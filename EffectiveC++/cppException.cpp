#include <iostream>
#include <string>
using std::string;

class DivisorCanNotBeZeroException
{
public :
	DivisorCanNotBeZeroException(string errorMessage)
		:mErrorMessage(errorMessage)
	{
	}
	string ToString()
	{
		return mErrorMessage;
	}
private:
	string mErrorMessage;
};

int dev(int a, int b)
{
	if(!b)
		throw new DivisorCanNotBeZeroException("Divisor can not be zero");
}

void main()  
{
	try{
		dev(1, 0);
	}
	catch(DivisorCanNotBeZeroException *d){
		std::cout << d->ToString() << std::endl;
		delete d;
	}
	//catch all exception.
	catch(...)
	{
		std::cout << "bala bala" << std::endl;
	}
}
/*
release �汾ʱ��complier����try���ݿ����Ƿ���throw�����û�У��ᱻ��Ϊ�������쳣������catch�ᱻ�Ż�����
���Ǳ������������ַ�����

1��
	__try
	{
	BYTE* pch ;
	pch = ( BYTE* )00001234 ;   //����һ���Ƿ���ַ
	*pch = 6 ; //�ԷǷ���ַ��ֵ�������Access Violation �쳣
	}
	__except( EXCEPTION_EXECUTE_HANDLER )
	{
	AfxMessageBox( "catched" ) ;
	}

	������__try, __except�黹�����⣬ �����������C++��׼�� ����Windowsƽ̨���е���չ�� ���������ʹ�ù������漰�ֲ��������������ĵ��ã�������C2712 �ı������ ��ô����û�б�İ취�أ�

2����Ȼ�У� ������Ȼʹ��C++��׼��try{}catch(..){}�� ���ڱ����������м��� /EHa �Ĳ���������VC�����������try catchģ����Ż����ˡ�
*/