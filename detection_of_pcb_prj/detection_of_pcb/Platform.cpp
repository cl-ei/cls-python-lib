#include "StdAfx.h"
#include "Platform.h"
#include "detection_of_pcb.h"

/* ���ײ�����쳣 */ 
DWORD WINAPI ThreadProc(LPVOID Axis)
{
	int ecode = c154_wait_error_interrupt( (I16)Axis, -1 );
	
	ErrMsgBox("�жϷ�����",ecode);
	
	return 0;
}


//ƽ̨��Ա������ʼ��
CPlatform::CPlatform(void)
	: m_SportMode(T_type)
{
	this->CardId = 0;
	this->m_Status = 0;

	this->m_Sacc = 0;
	this->m_Sdec = 0;
	this->m_Tacc = 0.05;
	this->m_Tdec = 0.05;

	this->m_StartVel = 1000;
	this->m_MaxVel = 8000;

	this->m_Border[0] = 32000;
	this->m_Border[1] = 94000;
}


CPlatform::~CPlatform(void)
{
}


//Ӳ��ƽ̨��ʼ��
int CPlatform::InitPlatform(void){
	int i = 0;
	int ecode = 0;
	ecode = c154_initial(&CardID_InBit, 0);

	if (ecode!=0){
		return ecode;
	}

	ecode = c154_get_version( CardId, &firmware_ver, &driver_ver, &dll_ver);	
	if (ecode!=0){
		return ecode;
	}
		
	for (i = 0; i < 2; i++)
	{	
		//����������� ģʽ
		c154_set_pls_outmode( i, 4);

		//�������������ź�ģʽ
		c154_set_pls_iptmode( i, 2, 0);

		//����Դѡ��0 �ⲿ����Դ��1�ڲ��������Դ
		c154_set_feedback_src( i, 1);		
	}
	ecode = c154_config_from_file();
	if (ecode!=0){
		return ecode;
	}

	/* �����ж� */
	ecode = c154_set_motion_int_factor(0, 0X01 );
	if (ecode!=0){
		return ecode;
	}
	ecode = c154_set_motion_int_factor(1, 0X01 );
	if (ecode!=0){
		return ecode;
	}
	/* ���ù���ģʽ */

	/* �����ж� */
	ecode = c154_int_control(0, 1);
	if (ecode!=0){
		return ecode;
	}
	return 0;
}

int CPlatform::set_sport_mode(SportModeType a){
	this->m_SportMode = a;
	return 1;
}

SportModeType CPlatform::get_sport_mode(void){
	return m_SportMode;
}

int CPlatform::set_speed(F64 spd[]){
	this->m_StartVel = spd[0];
	this->m_MaxVel = spd[1];
	this->m_Tacc = spd[2];
	this->m_Tdec = spd[3];
	return 0;
}

F64 CPlatform::get_speed(int Arg_No){
	switch (Arg_No) {
	case 0:
		return this->m_StartVel;
		break;
	case 1:
		return this->m_MaxVel;
		break;
	case 2:
		return this->m_Tacc;
		break;
	case 3:
		return this->m_Tdec;
		break;
	default:
		return -1;
	}
}

int CPlatform::move(I16 Axis,F64 distance){
	int ecode = 0;

	if (this->m_SportMode == T_type){
		 ecode=c154_start_tr_move(Axis, 
								distance, 
								this->m_StartVel,
								this->m_MaxVel,
								this->m_Tacc,
								this->m_Tdec);	
	}else{
		 ecode=c154_start_sr_move(Axis, 
								distance, 
								this->m_StartVel,
								this->m_MaxVel,
								this->m_Tacc,
								this->m_Tdec,
								this->m_Sacc,
								this->m_Sdec);
	
	}
	return  ecode;
}

int CPlatform::move_absolute_xy(F64 pos_x,F64 pos_y){
	//Card_id, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec
	I16 AxisArray[2] = {AXIS_0, AXIS_1};
	F64 PosArray[2] = {pos_x, pos_y};
	int ecode = 0;
	
	ecode = c154_start_ta_line2(AxisArray,PosArray,
		this->m_StartVel,this->m_MaxVel*1.4142,	this->m_Tacc,this->m_Tdec);
	return ecode;
}

int CPlatform::update_pos(){
	int ecode =0;
	ecode = c154_get_position(0,&this->m_Pos[0]);
	if (ecode != 0 ){
		return ecode;
	}
	ecode = c154_get_position(AXIS_1,&this->m_Pos[1]);
	if (ecode != 0 ){
		return ecode;
	}
	return 0;
}

F64 CPlatform::get_pos(int Arg_No,bool update){
	if (update == true){
		this->update_pos();
	}
	return this->m_Pos[Arg_No];
}

F64 CPlatform::get_dstpos(int Arg_No,bool update){
	I32 pos = 0;
	if (update == true){
		c154_get_command(Arg_No,&pos);
		this->m_DstPos[Arg_No] = pos;
	}
	return this->m_DstPos[Arg_No];
}

int CPlatform::return_to_org(void){
	c154_home_move(0,this->m_StartVel,this->m_MaxVel*(-1),this->m_Tacc);
	c154_home_move(3,this->m_StartVel,this->m_MaxVel*(-1),this->m_Tacc);
	//CreateThread(0,0,ThreadProc,(LPVOID)0,0,0);
	return 0;
}

// ʵ����Ӳ��ƽ̨
CPlatform Moto;