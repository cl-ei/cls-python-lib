// RunDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "detection_of_pcb.h"
#include "RunDlg.h"
#include "afxdialogex.h"


// CRunDlg �Ի���

IMPLEMENT_DYNAMIC(CRunDlg, CDialogEx)

CRunDlg::CRunDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRunDlg::IDD, pParent)
{	
}

CRunDlg::~CRunDlg()
{
}

void CRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CRunDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	/* ����ĳ�ʼ�� */

	CButton* pBtn = nullptr;
	pBtn = (CButton*)GetDlgItem(IDC_SHAPE_SEL);
	pBtn->SetCheck(1);

	return true;
}


BEGIN_MESSAGE_MAP(CRunDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CRunDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RUN, &CRunDlg::OnBnClickedRun)
	ON_BN_CLICKED(IDC_BUTTON_MOVE, &CRunDlg::OnBnClickedButtonMove)
	ON_BN_CLICKED(IDC_SHAPE_SEL, &CRunDlg::OnBnClickedShapeSel)
END_MESSAGE_MAP()


// CRunDlg ��Ϣ�������


void CRunDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CRunDlg::OnBnClickedRun()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	I16 AxisArray[2] = {0, 3};
	F64 PosArray[2] = {1000, 2000};
	int 
	ecode = c154_start_tr_line2(AxisArray,PosArray,
		1000,5000,	0.05,0.05);

	ErrMsgBox("???��",ecode);
}


void CRunDlg::OnBnClickedButtonMove()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Moto.move_absolute_xy(20000,60000);
}


void CRunDlg::OnBnClickedShapeSel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
