#include<iostream>//���������
#include<string>//����string
#include<cctype>//����string������
#include<vector>//����vector������
#include<bitset>//����bitset������
#include<cstddef>//����size_t��������
#include"con1.h"
using std::vector;
using namespace std;
int main()
{
	bitset<32> b;
	for(int i=0;i<32;++i)
		cout<<b[i];
	cout<<endl;
	bitset<32> c(10000);
	for(int i=0;i<32;++i)
		cout<<c[i];
	cout<<endl;
	bitset<9> d(10000);
	for(int i=0;i<9;++i)
		cout<<d[i];
	cout<<endl;
	bitset<16> e(0xffff);
	for(int i=0;i<16;++i)
		cout<<e[i];
	cout<<endl;
	
	long a=9;
	bitset<32> f(a);
	for(int i=0;i<32;++i)
		cout<<f[i];
	cout<<endl;
	string str("1111111000000011001101");
	bitset<32> bitvec2(str);
	bitset<32> bitvec3(str,str.size()-4);
	for(string::size_type i=0;i<bitvec2.size();++i)
		cout<<bitvec2[i];
	cout<<endl;
	cout<<bitvec3<<endl;
	string strval("1100");
	bitset<32> bitvec(strval);
	//for(int i=0;i<32;++i)
		cout<<bitvec;
	cout<<endl;
	bitset<32> s(1);
	cout<<s<<endl;
	bool is_set=bitvec.any();
	cout<<is_set<<endl;//���1��Ϊbitvec�д�����1λ
	bool is_not_set=bitvec.none();
	cout<<is_not_set<<endl;//���0����Ϊbitvec.none()���ж�bitvec���Ƿ�����1λ�����򷵻�0��û���򷵻�1
	size_t bits_set=bitvec.count();
	cout<<bits_set<<endl;//���2��Ϊbitvec.count()��Ѱ��bitvec�д��ڶ�����1λ
	bitset<32> bits1;
	for(int i=0;i<32;++i)
	{
		bits1.set(i);
	}
	cout<<bits1<<endl;
	bitset<32> bits2;
	bits2.set();
	cout<<bits2<<endl;
	size_t bits1_test=9;
	bits1_test=bits1.test(bits1_test);
	cout<<bits1_test<<endl;
	bits1_test=31;
	bits1.reset(bits1_test);
	bits1_test=bits1.test(31);
	cout<<bits1_test<<endl;
	bits2.flip();
	bits1.flip();
	bits1[30].flip();
	cout<<bits2<<endl;
	cout<<bits1<<endl;
	return 0;
}