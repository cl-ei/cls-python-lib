#pragma once


// CRunDlg �Ի���

class CRunDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRunDlg)

public:
	CRunDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRunDlg();

// �Ի�������
	enum { IDD = IDD_RUNDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRun();
	afx_msg void OnBnClickedButtonMove();
	afx_msg void OnBnClickedShapeSel();
};
