//Windows�����£�Visual C++ 6.0����SQLServer 2005���ݿ��ADO����,��VS2008�б�д�������£�

#pragma once


#define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>

//ʹ��# import�Ѷ�̬���ӿ�msado15.dll����Visual C++Ӧ�ó��򣬲����ɶ���ADO�������C++ͷ�ļ���msado15.tlh��ado15.tli������
#import "c:\Program Files\Common Files\System\ADO\msado15.dll"     no_namespace rename("EOF", "EndOfFile")

typedef struct {
	int id;
	char *name;
	bool sex;
	int age;
	int empid;
}student;

class DAO{
public :
	void doConnection(char *sqlCommand);
	void Dodelete();
	void save(student stu);
	void Update(student stu);
	student find(student stu);
private:
	student stu;
};

void DAO::doConnection(char *sqlCommand){
	printf("�����������ݿ⡭��\n");
	_bstr_t strConnect="DSN=sql2008test;Database=test;uid=LIU-PC;pwd=;";//����Ĳ���������������ODBC����Դʱ��һЩ����,uid���û�����pwd������
	::CoInitialize(NULL);//��ʼ��COM��

	//���һ��ָ��Connection�����ָ��m_pConnection
	 _ConnectionPtr m_pConnection(__uuidof(Connection));

	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ){ //����Connection����
		printf("����Connection����ʱ����\n");
	}

	try{
		m_pConnection->Open (strConnect,"","", adModeUnknown); //�������ݿ�
	}catch(_com_error e){
	  printf("�������ݿ�ʱ����\n");
	}

	m_pConnection->Execute(sqlCommand, NULL, 1);//ִ��SQL���
	m_pConnection->Close();

	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ


}

void DAO::Dodelete(){


	char *sqlCommand = " delete  from user where name='liu' ";//ע������ʹ����ɾ����������ѡ����ң���Ϊѡ����ҷ��ص���һ�����ϣ�Ҫ�õ��α�ȣ��Ƚ��鷳��

     doConnection(sqlCommand);                                                              //��������ֻ����һ���򵥵Ĳ���,���Ƿ���������
	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ

}

void DAO::save(student stu){
	char *sqlCommand = "INSERT INTO users(name, sex, age, empid) VALUES ('pae', 0, 23, 45)";
	doConnection(sqlCommand);

}

void DAO::Update(student stu){
	char *sqlCommand = " update users set name = 'zhuang' , age = 0 , empid =56 where id = 6";
	doConnection(sqlCommand);

}

student DAO::find(student stu){
	char *sqlCommand = "";
	doConnection(sqlCommand);


//	m_pConnection->Execute(sqlCommand, NULL, 1);//ִ��SQL���
//	m_pConnection->Close();
//
//	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ
	return stu;
}

int main(void){
	student stu={0,"",0,23,34};
	DAO ope;
	ope.Dodelete();
	return 0;
}
