// Plfcfg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "detection_of_pcb.h"
#include "Plfcfg.h"
#include "afxdialogex.h"

//*******************************************************************************//

//debug ����
void PrintError(int e_code){
	char ErrorMsg[256]="ʧ�ܣ� ������룺";
	char buff[256]	;
	itoa(e_code,buff,10); 
	strcat(ErrorMsg,buff);

	CString s_ErrorMsg = CString(ErrorMsg);  
	USES_CONVERSION;  
	LPCWSTR wszEMsg = A2CW(W2A(s_ErrorMsg)); 

	AfxMessageBox(wszEMsg);
}

//*******************************************************************************//


// CPlfcfg �Ի���

IMPLEMENT_DYNAMIC(CPlfcfg, CDialogEx)

CPlfcfg::CPlfcfg(CWnd* pParent /* = NULL */)
	: CDialogEx(CPlfcfg::IDD, pParent)
{
}

CPlfcfg::~CPlfcfg()
{
}

void CPlfcfg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPlfcfg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPlfcfg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CPlfcfg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON6, &CPlfcfg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &CPlfcfg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BTN_APPLY, &CPlfcfg::OnBnClickedBtnApply)
END_MESSAGE_MAP()


// CPlfcfg ��Ϣ�������


void CPlfcfg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CPlfcfg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CDialogEx::OnTimer(nIDEvent);

	int ecode = 0;
	static F64 pos[2] = {0,0};

	switch(nIDEvent){

	case 1:		//��1��ʱ��
		ecode=Moto.update_pos();
		if(ecode!=0){
			KillTimer(1);
			PrintError(ecode);			
		}else{
			SetDlgItemInt(IDC_DSTPOS0,Moto.get_dstpos(0));
			SetDlgItemInt(IDC_DSTPOS1,Moto.get_dstpos(3));

			SetDlgItemInt(IDC_POS0,Moto.get_pos(0));
			SetDlgItemInt(IDC_POS1,Moto.get_pos(1));
		}
		break;
	default:
		break;	
	}
}


BOOL CPlfcfg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	//��ʾ�̼��汾����Ϣ
	if (Moto.firmware_ver != 0){
		SetDlgItemInt(IDC_FIRMVER,Moto.firmware_ver);
		SetDlgItemInt(IDC_DIRVER,Moto.driver_ver);
		SetDlgItemInt(IDC_DLLVER,Moto.dll_ver);
	}

	//����Ӧ�ù�ѡ��ѡ��
	// T��/S���˶�ģʽ
	CButton* pBtn = nullptr;

	if(Moto.get_sport_mode() == S_type){
		pBtn = (CButton*)GetDlgItem(IDC_RADIO1);
		pBtn->SetCheck(1);
	}else{
		pBtn = (CButton*)GetDlgItem(IDC_RADIO2);
		pBtn->SetCheck(1);
	}

	//�����ٶȺ�ʱ��
	SetDlgItemInt(IDC_START_SPEED,Moto.get_speed(0));
	SetDlgItemInt(IDC_MAX_SPEED,Moto.get_speed(1));
	SetDlgItemInt(IDC_TACC,Moto.get_speed(2)*1000);
	SetDlgItemInt(IDC_TDEC,Moto.get_speed(3)*1000);

	//����Ŀ��λ��
	SetDlgItemInt(IDC_DSTPOS0,Moto.get_dstpos(0));
	SetDlgItemInt(IDC_DSTPOS1,Moto.get_dstpos(1));


	SetDlgItemInt(IDC_POS0,Moto.get_pos(0));
	SetDlgItemInt(IDC_POS1,Moto.get_pos(1));


	//������
	pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	pBtn->SetCheck(1);

	//��ת����
	pBtn = (CButton*)GetDlgItem(IDC_RADIO3);
	pBtn->SetCheck(1);

	//Ĭ���ֶ����Ծ��� ��10000
	SetDlgItemText(IDC_EDIT13,_T("10000"));

	Moto.return_to_org();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPlfcfg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

//��ʼת������
void CPlfcfg::OnBnClickedButton6()
{
	//��ȡҪ������
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	int Axis0 = pBtn->GetCheck();
	pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
	int Axis1 = pBtn->GetCheck();
	
	//��ȡ����
	CString distance;
	GetDlgItemText(IDC_EDIT13,distance);
	float dst = _ttof(distance);
	
	//�򿪵��
	int ecode = 0;
	if(Axis0 == 1){
		ecode = Moto.move(0,dst);
		if( ecode != 0){
			PrintError(ecode);		
		}else{
			SetTimer(1,50,NULL);
		}
	}
	if(Axis1 == 1){
		ecode = Moto.move(3,dst);
		if(ecode !=0){
			PrintError(ecode);
		}else{
			SetTimer(1,50,NULL);
		}
	}
}


//������ֹͣ�����ť
void CPlfcfg::OnBnClickedButton4()
{
	int ecode  = 0;
	ecode = c154_emg_stop(0);
	if( ecode !=0){
		PrintError(ecode);
	}	
}

// Ӧ�ð�ť
void CPlfcfg::OnBnClickedBtnApply()
{
	//����˶�ģʽ
	CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO1);
	int SportMode = pBtn->GetCheck();
	if(SportMode == 1){
		Moto.set_sport_mode(T_type);
	}else{
		Moto.set_sport_mode(S_type);
	}

	//�����ٶ�
	CString buff;
	F64 speed[4]={0,0,0,0};

	
	GetDlgItemText(IDC_START_SPEED,buff);
	speed[0] = _ttof(buff);

	GetDlgItemText(IDC_MAX_SPEED,buff);
	speed[1] = _ttof(buff);

	GetDlgItemText(IDC_TACC,buff);
	speed[2] = _ttof(buff) / 1000;

	GetDlgItemText(IDC_TDEC,buff);
	speed[3] = _ttof(buff) / 1000;

	Moto.set_speed(speed);
}

