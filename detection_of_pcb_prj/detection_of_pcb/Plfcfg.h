#pragma once


// CPlfcfg �Ի���

#include "Platform.h"

extern CPlatform Moto;

class CPlfcfg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlfcfg)

public:
	CPlfcfg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlfcfg();

// �Ի�������
	enum { IDD = IDD_DLG_PLFCFG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedBtnApply();
	afx_msg void OnEnChangeStartSpeed();
};

