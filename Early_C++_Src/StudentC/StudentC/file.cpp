#include<stdio.h>
//#include<
#include "func.h"
int main(int argc,char *argv[]){
	char n;
	while(1){
		printf("******ѧ����Ϣ����ϵͳ*****\n");
		printf("*1�����         2��ɾ��  *\n");
		printf("*3�����         4����ѯ  *\n");
		printf("*5���˳�                  *\n");
		printf("***************************\n");
		printf("��ѡ������Ҫ�ķ���:  ");
		n = getc(stdin) ;
		flush();
		if(n<'1' || n>'5'){
			printf("Please input the right comend!\n");
			continue;
		}
		switch(n){
			case '1':add();	break;
			case '2':Delete();break;
			case '3':print();	break;
			case '4':find();	break;
			default:break;
		}
		if(n=='5'){
			printf("Bye!\n");
			break;
		}
	}
	return 0;
}