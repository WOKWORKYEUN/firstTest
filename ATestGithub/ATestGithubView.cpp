
// ATestGithubView.cpp : CATestGithubView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ATestGithub.h"
#endif

#include "ATestGithubDoc.h"
#include "ATestGithubView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CATestGithubView

IMPLEMENT_DYNCREATE(CATestGithubView, CView)

BEGIN_MESSAGE_MAP(CATestGithubView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CATestGithubView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CATestGithubView ����/����

CATestGithubView::CATestGithubView()
{
	// TODO: �ڴ˴���ӹ������

}

CATestGithubView::~CATestGithubView()
{
}

BOOL CATestGithubView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CATestGithubView ����

void CATestGithubView::OnDraw(CDC* /*pDC*/)
{
	CATestGithubDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CATestGithubView ��ӡ


void CATestGithubView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CATestGithubView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CATestGithubView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CATestGithubView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CATestGithubView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CATestGithubView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CATestGithubView ���

#ifdef _DEBUG
void CATestGithubView::AssertValid() const
{
	CView::AssertValid();
}

void CATestGithubView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CATestGithubDoc* CATestGithubView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CATestGithubDoc)));
	return (CATestGithubDoc*)m_pDocument;
}
#endif //_DEBUG


// CATestGithubView ��Ϣ�������
