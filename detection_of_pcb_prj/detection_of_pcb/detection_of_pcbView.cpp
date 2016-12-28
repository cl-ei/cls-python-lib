
// detection_of_pcbView.cpp : Cdetection_of_pcbView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "detection_of_pcb.h"
#endif

#include "detection_of_pcbDoc.h"
#include "detection_of_pcbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cdetection_of_pcbView

IMPLEMENT_DYNCREATE(Cdetection_of_pcbView, CView)

BEGIN_MESSAGE_MAP(Cdetection_of_pcbView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cdetection_of_pcbView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cdetection_of_pcbView ����/����

Cdetection_of_pcbView::Cdetection_of_pcbView()
{
	// TODO: �ڴ˴���ӹ������

}

Cdetection_of_pcbView::~Cdetection_of_pcbView()
{
}

BOOL Cdetection_of_pcbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cdetection_of_pcbView ����

void Cdetection_of_pcbView::OnDraw(CDC* /*pDC*/)
{
	Cdetection_of_pcbDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cdetection_of_pcbView ��ӡ


void Cdetection_of_pcbView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cdetection_of_pcbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cdetection_of_pcbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cdetection_of_pcbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Cdetection_of_pcbView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cdetection_of_pcbView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cdetection_of_pcbView ���

#ifdef _DEBUG
void Cdetection_of_pcbView::AssertValid() const
{
	CView::AssertValid();
}

void Cdetection_of_pcbView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdetection_of_pcbDoc* Cdetection_of_pcbView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdetection_of_pcbDoc)));
	return (Cdetection_of_pcbDoc*)m_pDocument;
}
#endif //_DEBUG


// Cdetection_of_pcbView ��Ϣ�������
