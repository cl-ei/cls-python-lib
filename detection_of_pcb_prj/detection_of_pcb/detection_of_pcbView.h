
// detection_of_pcbView.h : Cdetection_of_pcbView ��Ľӿ�
//

#pragma once


class Cdetection_of_pcbView : public CView
{
protected: // �������л�����
	Cdetection_of_pcbView();
	DECLARE_DYNCREATE(Cdetection_of_pcbView)

// ����
public:
	Cdetection_of_pcbDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cdetection_of_pcbView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // detection_of_pcbView.cpp �еĵ��԰汾
inline Cdetection_of_pcbDoc* Cdetection_of_pcbView::GetDocument() const
   { return reinterpret_cast<Cdetection_of_pcbDoc*>(m_pDocument); }
#endif

