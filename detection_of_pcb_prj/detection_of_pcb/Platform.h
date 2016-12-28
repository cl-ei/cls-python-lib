#pragma once
#include "./Library/Include/C154.h"

enum SportModeType{S_type,T_type};

#define AXIS_0  0
#define AXIS_1  3

class CPlatform
{
public:
	CPlatform(void);
	~CPlatform(void);

	I16 firmware_ver;
	I32 driver_ver;
	I32 dll_ver;	
protected:
	U16 CardID_InBit;
	I16 CardId;
	
	int m_Status;
	//�˶�ģʽѡ��
	//T: Ϊ�㶨���ٶ�����ģʽ�����ٹ�������
	//S: ���ٶ�Ϊ�����ٶ����ߣ����Լ�С����𶯣������ýϷ���
	SportModeType m_SportMode;

	F64 m_StartVel;		//��ʼ�ٶ�
	F64 m_MaxVel;		//����ٶ�
	F64 m_Tacc;		//����ʱ��
	F64 m_Tdec;		//����ʱ��

	//������������һΪ0ʱ���˶�����Ϊ��S����
	F64 m_Sacc;		//S���߼��ٽ׶��ٶȲ�ֵ������С�� (0.5 * m_MaxVel)					
	F64 m_Sdec;		//S���߼��ٽ׶��ٶȲ�ֵ������С�� (0.5 * m_MaxVel)

	F64 m_Pos[2];		//��ǰλ�ã���λpoint
	F64 m_DstPos[2];		//Ŀ��λ��
	F64 m_Border[2];	//�����
	F64 m_PosCam[2];	//�����λ��
	F64 m_SizeCam[2];	//�����λ��

	F64 m_PPCm;		//ÿ���׵�������������ƽ̨��С

	


	HANDLE ChildThread;

public:
	int InitPlatform(void);

	int set_sport_mode(SportModeType);
	SportModeType get_sport_mode(void);

	int set_speed(F64 spd[]);
	F64 get_speed(int Arg_No);

	F64 get_dstpos(int Arg_No,bool update = true);

	int set_border(F64 b0,F64 b1);
	int move(I16 Axis , F64 distance);
	int move_absolute_xy(F64 pos_x,F64 pos_y);
	int update_pos();
	F64 get_pos(int Arg_No,bool update = true);

	int return_to_org(void);
};

//extern CPlatform Moto;