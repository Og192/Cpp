
// ODBCView.cpp : CODBCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ODBC.h"
#endif

#include "ODBCSet.h"
#include "ODBCDoc.h"
#include "ODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCView

IMPLEMENT_DYNCREATE(CODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CODBCView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CODBCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CODBCView ����/����

CODBCView::CODBCView()
	: CRecordView(CODBCView::IDD)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CODBCView::~CODBCView()
{
}

void CODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
}

BOOL CODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCSet;
	CRecordView::OnInitialUpdate();

}


// CODBCView ��ӡ


void CODBCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CODBCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CODBCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CODBCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CODBCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CODBCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CODBCView ���

#ifdef _DEBUG
void CODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDoc* CODBCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDoc)));
	return (CODBCDoc*)m_pDocument;
}
#endif //_DEBUG


// CODBCView ���ݿ�֧��
CRecordset* CODBCView::OnGetRecordset()
{
	return m_pSet;
}



// CODBCView ��Ϣ�������
