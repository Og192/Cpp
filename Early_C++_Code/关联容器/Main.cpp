#include<iostream>
#include<string>
#include<vector>
#include<map>
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
int main()
{
	/*
	< pair<string,int> > vecpair;
	pair<string,int> pai;
	while(cin>>pai.first>>pai.second)
		vecpair.push_back(pai);
	map<string,int> word_count;
	word_count["Liu"]=1;
	cout<<word_count["Liu"]<<endl;
	++word_count["Liu"];
	cout<<word_count["Liu"]<<endl;
	string word;
	while(cin>>word)
		++word_count[word];
	cout<<"��������Ҫ����"<<endl;
	for(map<string,int>::iterator iter=word_count.begin();iter!=word_count.end();++iter)
	cout<<iter->first<<" : "<<iter->second<<endl;
	*/
	map<string,int> msi;
	typedef map<string,int>::value_type  vaty;
	msi.insert(vaty("g",2));
	msi.insert(vaty("t",8));
	msi.insert(make_pair("d",78));
	map<string, int>::iterator mit;
	mit=msi.insert(msi.begin(),vaty("e",12));
	map<string,int> msi1;
	string word;
	while(cin>>word){
		pair<map<string,int>::iterator,bool> ret=//����һ��pair����������insert���ص�pair�ĵ�������һ��boolֵ
			msi1.insert(make_pair(word,1));
		if(!ret.second)
			++ret.first->second;
	}
	map<string,int> msi2;
	msi2.insert(map<string,int>::value_type("a",23));
	msi2.insert(map<string,int>::value_type("b",32));
	int occurs=0;
	if(msi2.count("a"))//���ؼ��ǡ�a���ĸ�������map�ǵ��������Ĺ�������
		occurs=msi2["a"];
	map<string,int>::iterator mit1;
	mit1=msi2.find("b");//find����������Ҫ����pair������
	if(mit1!=msi2.end())
		occurs=mit1->second;
	map<string,int>::iterator mit2=msi2.begin();
	while(mit2!=msi2.end()){//map�����
		cout<<mit2->first<<endl
			<<mit2->second<<endl;
		++mit2;
	}
	//msi2.erase(msi2.begin(),msi2.end());
	//msi2.erase("a");
	//msi2.erase(mit1);
	return 0;
}