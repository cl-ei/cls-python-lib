
// detection_of_pcbDoc.cpp : Cdetection_of_pcbDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "detection_of_pcb.h"
#endif

#include "detection_of_pcbDoc.h"

#include <propkey.h>


#include "RunDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cdetection_of_pcbDoc

IMPLEMENT_DYNCREATE(Cdetection_of_pcbDoc, CDocument)

BEGIN_MESSAGE_MAP(Cdetection_of_pcbDoc, CDocument)
	ON_COMMAND(ID_32775, &Cdetection_of_pcbDoc::OnRun)
END_MESSAGE_MAP()


// Cdetection_of_pcbDoc ����/����

Cdetection_of_pcbDoc::Cdetection_of_pcbDoc()
{
	// TODO: �ڴ����һ���Թ������

}

Cdetection_of_pcbDoc::~Cdetection_of_pcbDoc()
{
}

BOOL Cdetection_of_pcbDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Cdetection_of_pcbDoc ���л�

void Cdetection_of_pcbDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void Cdetection_of_pcbDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void Cdetection_of_pcbDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void Cdetection_of_pcbDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cdetection_of_pcbDoc ���

#ifdef _DEBUG
void Cdetection_of_pcbDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cdetection_of_pcbDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cdetection_of_pcbDoc ����


void Cdetection_of_pcbDoc::OnRun()
{
	// TODO: �ڴ���������������
	CRunDlg RunDlg;
	RunDlg.DoModal();

}
