#include<sys/time.h>
#include<iostream>
#include"bank.h"
#include"bank.cpp"

using std::string;
using std::cout;
using std::endl;
int main()
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	Bank Liu("Og", "12345", 100);
	gettimeofday(&end, NULL);
//	Liu.Print_info();
//	Liu.Save_mon(10);
//	Liu.Print_info();
//	Liu.Get_mon(100);
//	Liu.Print_info();

	cout << "\"string(no def)\"" << (end.tv_sec - start.tv_sec) << "s " 
		<< (end.tv_usec - start.tv_usec) << "us" << endl;

	return 0;
}
