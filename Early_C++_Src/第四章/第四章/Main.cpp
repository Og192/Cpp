#include<iostream>
#include<string>
using namespace std;
int shuzu1[10];
int main()
{
	const char *cp1="I like C++";
	const char *cp2="I like C++ too";//�ֵ����򷨣�cp2��cp1���棬cp2>cp1
	int i=strcmp(cp1,cp2);
	cout<<i<<endl;
	i=strcmp(cp1,cp2);//�����ǰ���ظ���
	cout<<i<<endl;
	i=strcmp(cp1,cp1);
	cout<<i<<endl;//��ͬ����0
	i=strcmp(cp2,cp1);
	cout<<i<<endl;//cp2>cp1��ǰ���ں󷵻�����
	char ca[]={'C','+','+','\0'};
	cout<<strlen(ca)<<endl;
	char largeStr[16+18+2];
	strcpy(largeStr,cp1);
	strcat(largeStr," ");
	strcat(largeStr,cp2);
	cout<<largeStr<<endl;
	strncpy(largeStr,cp1,17);
	strncat(largeStr," ",2);
	strncat(largeStr,cp2,18);//���֣�����NULL�ַ��� ���� cp2 ���ӵĸ������������������ȫй¶
	cout<<largeStr<<endl;
	return 0;
}