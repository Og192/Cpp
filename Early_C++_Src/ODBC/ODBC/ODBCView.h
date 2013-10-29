
// ODBCView.h : CODBCView ��Ľӿ�
//

#pragma once

class CODBCSet;

class CODBCView : public CRecordView
{
protected: // �������л�����
	CODBCView();
	DECLARE_DYNCREATE(CODBCView)

public:
	enum{ IDD = IDD_ODBC_FORM };
	CODBCSet* m_pSet;

// ����
public:
	CODBCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CODBCView();
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

#ifndef _DEBUG  // ODBCView.cpp �еĵ��԰汾
inline CODBCDoc* CODBCView::GetDocument() const
   { return reinterpret_cast<CODBCDoc*>(m_pDocument); }
#endif

