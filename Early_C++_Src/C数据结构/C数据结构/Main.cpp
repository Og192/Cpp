 // main1-1.cpp �����������bo1-1.cpp��������
#include<iostream>
using std::cout;
using std::endl;
#include"c1.h" // Ҫ������������#include�������������ļ���������ǰĿ¼��
 // ����2�пɸ�����Ҫѡ��һ������ֻ��ѡ��һ������������ı��������bo1-1.cpp
 typedef int ElemType; // ���������������ElemType�ڱ�������Ϊ����
 //typedef double ElemType; // ���������������ElemType�ڱ�������Ϊ˫������
 #include"c1-1.h" // �ڴ�����֮ǰҪ����ElemType������
// �ڴ�����֮ǰҪ����c1-1.h�ļ�����Ϊ���ж�����Triplet��

   // bo1-1.cpp ������������Triplet��ElemType(��c1-1.h����)�Ļ�������(8��)
 Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
 { // �������:������Ԫ��T,������T������Ԫ�صĳ�ֵΪv1,v2��v3
   if(!(T=(ElemType *)malloc(3*sizeof(ElemType))))
     exit(OVERFLOW);
   T[0]=v1,T[1]=v2,T[2]=v3;
   return OK;
 }

 Status DestroyTriplet(Triplet &T)
 { // �����������Ԫ��T������
   free(T);
   T=NULL;
   return OK;
 }

 Status Get(Triplet T,int i, ElemType &e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڣ�1��i��3�������������e����T�ĵ�iԪ��ֵ
   if(i<1||i>3)
     return ERROR;
   e=T[i-1];
   return OK;
 }

 Status Put(Triplet T,int i,ElemType e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڣ�1��i��3������������ı�T�ĵ�iԪ��ֵΪe
   if(i<1||i>3)
     return ERROR;
   T[i-1]=e;
   return OK;
 }

 Status IsAscending(Triplet T)
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ�������������T������Ԫ�ذ��������У�����1�����򷵻�0
   return(T[0]<=T[1]&&T[1]<=T[2]);
 }

 Status IsDescending(Triplet T)
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ�������������T������Ԫ�ذ��������У�����1�����򷵻�0
   return(T[0]>=T[1]&&T[1]>=T[2]);
 }

 Status Max(Triplet T,ElemType &e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ������������e����T������Ԫ���е����ֵ
   e=T[0]>=T[1]?T[0]>=T[2]?T[0]:T[2]:T[1]>=T[2]?T[1]:T[2];
   return OK;
 }

 Status Min(Triplet T,ElemType &e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ������������e����T������Ԫ���е���Сֵ
   e=T[0]<=T[1]?T[0]<=T[2]?T[0]:T[2]:T[1]<=T[2]?T[1]:T[2];
   return OK;
 }

 void main()
 {
   Triplet T;//����ָ��
   ElemType m;//����
   Status i;//����
   i=InitTriplet(T,5,7,9);
 //i=InitTriplet(T,5.0,7.1,9.3); // ��ElemTypeΪ˫������ʱ,��ȡ���Ͼ�
   printf("���ó�ʼ��������i=%d(1:�ɹ�) T������ֵΪ��",i);
   cout<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
   // Ϊ����ElemType�����ͱ仯��Ӱ�죬��coutȡ��printf()��ע���βҪ��endl
   i=Get(T,2,m);
   if(i==OK)
     cout<<"T�ĵ�2��ֵΪ��"<<m<<endl;
   i=Put(T,2,6);
   if(i==OK)
     cout<<"��T�ĵ�2��ֵ��Ϊ6��T������ֵΪ��"<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
   i=IsAscending(T); // ���ຯ��ʵ����ElemType�������޹�,��ElemType�����ͱ仯ʱ,ʵ�β���ı�
   printf("���ò�������ĺ�����i=%d(0:�� 1:��)\n",i);
   i=IsDescending(T);
   printf("���ò��Խ���ĺ�����i=%d(0:�� 1:��)\n",i);
   if((i=Max(T,m))==OK) // �ȸ�ֵ�ٱȽ�
     cout<<"T�е����ֵΪ��"<<m<<endl;
   if((i=Min(T,m))==OK)
     cout<<"T�е���СֵΪ��"<<m<<endl;
   DestroyTriplet(T); // ����Ҳ���Բ����ط���ֵ
   cout<<"����T��T="<<T<<"(NULL)"<<endl;
 }

