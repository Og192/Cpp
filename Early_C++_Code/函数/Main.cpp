#include <iostream>
using namespace std;
 int print(int a);
int main()
{
	typedef int (*camFun)(int);//����camFun��һ���������͵�ͬ��ʣ�����������һ��ָ��
							   //ָ�����һ����������������ķ���ֵ�β��綨����
	int f=7;
	camFun pf=print;//camFun����һ���������ͣ�����������͵ı���
	f=pf(f);
	f=(*pf)(f);//�˵ص�*pf��pfû������
	return 0;
}
 int print(int a)
{
	a=10;
	cout<<"�ɹ�����"<<endl;
	return a;
}