/*
student�ඨ��
�����Ա�����Ķ���
*/

#define FILE_NAME "liu.txt"
class student{
	public:
		void scan();			//���ѧ���б�
		void add();				//���ѧ��
		void deleteStu();		//ɾ��ѧ��
		void find();			//����ѧ��
		bool find(student &stu);//����ѧ����������ѧ����Ϣ
		void change();			//����ѧ����Ϣ
		int getNum();			//���ѧ��
		string getName();		//�������
		string getEnglish();	//���Ӣ��ɼ�
	private:
		int Num;		//ѧ��
		string Name;	//����
		string English;	//Ӣ��ɼ�
};

//���ѧ��
int student::getNum(){
	return this->Num;
}

//�������
string student::getName(){
	return this->Name;
}

//���Ӣ��ɼ�
string student::getEnglish(){
	return this->English;
}

//���ѧ���ɼ��б�
void student::scan(){
	string file = FILE_NAME;

	ifstream is(file.c_str(),ofstream::in);//ֻ����ʽ���ļ����Ի�ȡ����
	checkFile(is,file);

	string s;
	while(!is.eof()){//��ȡ�ļ����ݣ��������ʾ��
		getline(is,s);
		cout<<s<<endl;;
	}

	is.close();
}

//���ѧ��
void student::add(){
	student stu;					//���ѧ������Ϣ
	vector<string> file;			//����ļ�����
	string temp,fileName=FILE_NAME;	//����ȡ�����ļ����ݵ�һ�У���ʱ�����temp
									//fileName���ļ���
	//��ȡ���ѧ����Ϣ
	cout<<"������ѧ�ţ� ";
	string num;//temp����string��ʽ��ȡѧ�ţ����ں���������string��ʽѹ����������ˢ��ѧ���б�
	cin>>num;
	stu.Num = atoi(num.c_str());
	cout<<"������������ ";
	cin>>stu.Name;
	cout<<"������Ӣ��ɼ��� ";
	cin>>stu.English;

	ifstream is( fileName.c_str(),ifstream::in);//ֻ����ʽ���ļ�����ȡ�ļ�����
	checkFile(is,fileName);

	int mark = 1;//ȷ�����ѧ����ѧ�Ŵ�С �Ƿ�����ĩβ��0�����ǣ�1������
	while(!is.eof()){//��ȡ�ļ�����
		getline(is,temp);
		if(stu.Num == atoi(temp.c_str())){//���ѧ���� �����б����ظ��������ѧ������
			cerr<<"��ѧ���Ѿ����ڣ���"<<endl;
			return;
		}
		if(stu.Num < atoi(temp.c_str()) && (!mark) ){
			file.push_back( num + " " + stu.Name + " " + stu.English );//����ӵ�ѧ����Ϣ��ѹ��file����
			mark = 0;
		}
		if(temp != ""){
			file.push_back(temp);//�����ȡ�����ݲ��գ��ͽ���һ��ѹ��file����
		}
	}
	is.close();
	
	ofstream os( fileName.c_str(),ofstream::out);//������д�ķ�ʽ���ļ�
	checkFile(os,fileName);//ȷ���ļ�������

	for(vector<string>::iterator iter = file.begin();//�����ļ����ݣ�ˢ��ѧ���б�
		iter != file.end();iter++){
			os<<*(iter)<<endl;
	}
	if(mark == 1){
		os<<stu.Num<<" "<<stu.Name<<" "<<stu.English<<endl;//��������
	}
	os.close();
}

//ɾ��ѧ��
void student::deleteStu(){
	student stu;				//Ҫɾ����ѧ����Ϣ
	string fileName = FILE_NAME;//�ļ���
	string temp;				//����ȡ�����ļ����ݵ�һ�У���ʱ�����temp
	vector<string> file;		//����ļ��е�����

	cout<<"��������Ҫɾ����ѧ����ѧ��: ";
	cin>>stu.Num;

	ifstream is(fileName.c_str(),ifstream::in);//ֻ����ʽ���ļ�����ȡ�ļ�����
	checkFile(is,fileName);

	while(!is.eof()){
		getline(is,temp);
		if(temp == ""){continue;}
		if(stu.Num == atoi(temp.c_str())){//�����ǰ��ǡ����Ҫɾ�����У�ֱ�������˴�ѭ��
										  //������ ���temp����䣬�ﵽɾ��Ч��
			continue;
		}
		file.push_back(temp);
	}

	is.close();

	ofstream os(fileName.c_str() ,ofstream::out);//������д�ķ�ʽ���ļ�
	checkFile(os,fileName);

	for(vector<string>::iterator iter = file.begin();
		iter != file.end();iter++){
			os<<*(iter)<<endl;
	}

	os.close();
}

//����ѧ��
void student::find(){
	student stu;				//�����Ҫ���ҵ�ѧ����Ϣ
	string Num;					//��string��ʽ���ѧ�ţ����ں�����string���͵�ѧ����Ϣ��ѹ��file����
	string fileName = FILE_NAME;//�ļ���
	string temp;				//�����ļ��л�ȡ��һ�У���ʱ�����temp��

	cout<<"��������Ҫ���ҵ�ѧ��ѧ�ţ� ";
	cin>>stu.Num;				//��ȡҪɾ��ѧ����ѧ��
	
	ifstream is(fileName.c_str(),ifstream::in);
	checkFile(is,fileName);

	while(!is.eof()){
		getline(is,temp);

		if(stu.Num == atoi(temp.c_str()) ){//������ҵ��������ѧ����Ϣ��
			cout<<"Find it !!"<<endl;
			cout<<temp<<endl;
			is.close();
			return ;						//�ҵ������֮�󣬴ﵽĿ�ļ��˳�����
		}
	}
	cout<<"Not found!!!"<<endl;//����ѭ����û���˳�������֤��û���ҵ�����������Ϣ
	is.close();
}

//����ѧ����������ѧ����Ϣ
bool student::find(student &stu){
	string fileName = FILE_NAME;
	string temp;
	
	
	ifstream is(fileName.c_str(),ifstream::in);
	checkFile(is,fileName);

	while(!is.eof()){
		getline(is,temp);
		if(stu.getNum() == atoi(temp.c_str()) ){
			//����string�еõ����ҵ�����Ϣ��������Ҫ����ֽ��3���֣��ֱ渳ֵ��ѧ����Ϣ���ԣ��Կո�Ϊ�ָ�����
			stu.Num = atoi(temp.substr(0,temp.find(' ')).c_str());//�õ��ӵ�0��λ�ã�����һ�����ֿո��λ��
																  //ȡ�������ַ�������ת����C�ַ������ͣ���ת����int���ͣ���ֵ�� ѧ������
			temp.erase(0,temp.find(' ')+1);//������һ���ո�֮ǰ���ַ�
			stu.Name = temp.substr(0,temp.find(' '));//ͬ�ϲ�ȡ�ַ�������
			temp.erase(0,temp.find(' ')+1);
			stu.English = temp;
			is.close();
			return 1;
		}
	}
	is.close();
	return 0;
}

//����ѧ����Ϣ
void student::change(){
	student stu;				//�����Ҫ�޸ĵ�ѧ����Ϣ
	string fileName = FILE_NAME;//�ļ���
	vector<string> file;		//����ļ� ������

	cout<<"��������Ҫ�޸ĵ�ѧ��ѧ��: ";
	string temp;
	string Num;
	
	int i=0;
	cin>>Num;
	stu.Num = atoi(Num.c_str()); //���ѧ�ŵ�int������ʽ
	if(!find(stu)){				 //ȷ���޸Ķ����Ƿ����
		cout<<"û�ҵ���λͬѧ"<<endl;
		return ;
	}
	
	//�޸�ѡ���б�
	while(1){
		cout<<"��������Ҫ�޸ĵ�ѡ�1��ѧ�� 2������ 3��Ӣ��ɼ� 4������: ";
		cin>>i;
		switch(i){
		case 1: cout<<"��Ҫ�޸�ѧ�ţ���������ѧ��: ";cin>>Num;break;
		case 2: cout<<"��Ҫ�޸�������������������: ";cin>>stu.Name;break;
		case 3: cout<<"��Ҫ�޸�Ӣ��ɼ����������µ�Ӣ��ɼ�: ";cin>>stu.English;break;
		case 4: break;
		default:cout<<"û�����ѡ��������������룡"<<endl;break;
		}
		if(i == 4) {cout<<"Bye"<<endl;break;}
	}

	ifstream is(fileName,ifstream::in);//���ļ����Ի���ļ�����
	checkFile(is,fileName);

	//����ļ�����
	while(!is.eof()){
		getline(is,temp);

		if(stu.Num == atoi(temp.c_str())){
			file.push_back(Num + " " + stu.Name + " " + stu.English);
			continue;
		}

		file.push_back(temp);
	}
	is.close();

	ofstream os(fileName,ofstream::out);//���ļ��������ļ������������ݣ�ˢ��ѧ���б�
	checkFile(os,fileName);

	for(vector<string>::iterator iter = file.begin();//�������������뵽�ļ���
		iter != file.end();iter++){
			os<<*(iter)<<endl;
	}
	os.close();
}