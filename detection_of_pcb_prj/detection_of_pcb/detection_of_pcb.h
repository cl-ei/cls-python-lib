
// detection_of_pcb.h : detection_of_pcb Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

#include "Plfcfg.h"
#include "platform.h"

// Cdetection_of_pcbApp:
// �йش����ʵ�֣������ detection_of_pcb.cpp
//

class Cdetection_of_pcbApp : public CWinAppEx
{
public:
	Cdetection_of_pcbApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPlfCfg();
	afx_msg void OnCfgPlatform();
};

void ErrMsgBox(char *msg,int error_code);

extern Cdetection_of_pcbApp theApp;
