#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class login{
public :
	login(){
		username = "liu";
		pwd="123";
	}
	bool clogin(string cusername,string cpwd){
		if(cusername==username && cpwd == pwd){
			return 1;
		};
		return 0;
	}
private:
	string username;
	string pwd;
};

class bank{
public :
	bank(){
		Money=0;
	}
	bank(double money){
		Money=money;
	}
	void save();
	void get();
	void show();
private:
	double Money;
};

void bank::save(){
	cout<<"��������Ǯ:"<<endl;
	double money;
	cin>>money;
	Money+=money;
}

void bank::get(){
	cout<<"��Ҫȡ����Ǯ:"<<endl;
	double money;
	cin>>money;
	if((Money-money)<0){
		cout<<"��������!"<<endl;
		return ;
	}
	Money-=money;
}

void bank::show(){
	cout<<endl<<"���������Ϊ:"<<Money<<endl;
}
int main(){
	login in;
	int n=3;
	while(true){
		cout<<endl<<"�������û���������"<<endl;
		string username;
		cout<<endl<<"�û���:";
		cin>>username;
		string pwd;
		cout<<endl<<"����:";
		cin>>pwd;


		if(in.clogin(username,pwd)){
			n=3;
			bank user(12);
		
			while(true){
				cout<<endl<<"1����Ǯ"<<endl<<"2��ȡǮ"<<endl<<"3����ѯ"<<endl<<"4���˳�"<<endl;
				cout<<"��ѡ������Ҫ�ķ���:";
				int i;
				cin>>i;
				switch(i){
					case 1:user.save();break;
					case 2:user.get();break;
					case 3:user.show();break;
					case 4:cout<<"�ɹ��˳���ллʹ�ñ�ϵͳ!"<<endl;break;
					default:cout<<"û�д������"<<endl;break;
				}
				if(i==4) break;
			}
		}else{
			n--;
			if(n==0){cout<<"��Ȼ���㲻֪������!"<<endl;exit(0);}
			cout<<"���������������û�������ȷ!���������룡"<<endl;
			cout<<"��ʾ:������"<<n<<"�λ���"<<endl;
		}
	}
}