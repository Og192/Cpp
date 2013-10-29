
// ODBCSet.cpp : CODBCSet ���ʵ��
//

#include "stdafx.h"
#include "ODBC.h"
#include "ODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCSet ʵ��

// ���������� 2012��7��7�� ������, 20:48

IMPLEMENT_DYNAMIC(CODBCSet, CRecordset)

CODBCSet::CODBCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_name = L"";
	m_age = 0;
	m_empid = 0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CODBCSet::GetDefaultConnect()
{
	return _T("DSN=sql2008test;Description=test;UID=sa;PWD=aixiteluli16;APP=Microsoft\x00ae Visual Studio\x00ae 2010;WSID=LIU-PC;DATABASE=test;Network=DBMSSOCN;Address=liu-PC");
}

CString CODBCSet::GetDefaultSQL()
{
	return _T("[dbo].[student]");
}

void CODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Long(pFX, _T("[age]"), m_age);
	RFX_Long(pFX, _T("[empid]"), m_empid);

}
/////////////////////////////////////////////////////////////////////////////
// CODBCSet ���

#ifdef _DEBUG
void CODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

