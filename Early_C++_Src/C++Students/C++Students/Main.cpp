#include"head.h"
#include"student.h"

int main(void){
	student stu;//�½�һ��student����
	cout<<"��ӭ����ѧ���ɼ�����ϵͳ"<<endl;
	int n=0;
	//����ѡ���б�
	while(1){
		cout<<"1����� 2����� 3��ɾ�� 4����ѯ 5���޸� 6���˳� "<<endl;
		cout<<"��ѡ����Ҫ�ķ���: ";
		cin>>n;
		switch(n){
		case 1:stu.scan();break;		//���
		case 2:stu.add();break;			//���
		case 3:stu.deleteStu();break;	//ɾ��
		case 4:stu.find();break;		//��ѯ
		case 5:stu.change();break;		//�޸�
		case 6:break;					//�˳�
		default: cout<<"�ⲻ�ǿ��÷���!!!"<<endl;break;
		}
		if(n == 6) {cout<<"Bye!"<<endl;break;}
	}
	return 0;
}

