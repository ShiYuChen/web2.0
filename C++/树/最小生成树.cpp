#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

struct Edge
{
	int no;        //�ߵ����
	int x;         //�˵�1���
	int y;         // �˵�2���
	int weight;    //Ȩֵ
	bool selected; //�Ƿ�ѡ��
};

Edge edge[MAX];       //�߼���

int rank[MAX];        //���ҵ�����С����������һ���ֵ���

int parent[MAX];//���ҵ�����С����������һ���ֵ�ͷ���//�����ж�һ���ߵ�2���˵��Ƿ���һ�������У��������������Ƿ���γɻ�·

bool cmp(Edge a, Edge b)
{
	return a.weight <= b.weight;
} 

int find_set(int x)    //�ҳ�ÿһ���ϵ�ͷ���
{
	if(x != parent[x])
		parent[x] = find_set(parent[x]);
 	return parent[x];
}

void union_set(int x,int y,int w,int &sum)      //�ϲ�����
{
	if(rank[x]>rank[y])
		parent[y]=x;
 	else
 	{
  		if(rank[x]==rank[y])
   			rank[y]++;
  		parent[x]=y;
 	}
 	sum +=w;
}


int main()
{
 int cases;
 cout<<"�����밸���ĸ�����";
 cin>>cases;
 while(cases--)
 {
  int n;
  //��С��������Ȩֵ�ܺ�
  int sum = 0;
  cout<<"������ߵĸ�����";
  cin>>n;
  int i;
  //��ʼ��
  char chx,chy;
  int weight;
  for(i=1;i<=n;i++)
  {
   edge[i].no = i;
   cout<<"�������"<<i<<"���ߵĶ����˵������(Сд�ַ�)��";
   cin>>chx>>chy;
   edge[i].x = chx-'a'+1;
   edge[i].y = chy-'a'+1;
   cout<<"�����ߵ�ȨֵΪ��";
   cin>>weight;
   edge[i].weight = weight;
   edge[i].selected = false;
   parent[edge[i].x] = edge[i].x;
   parent[edge[i].y] = edge[i].y;
   rank[edge[i].x] = 0;
   rank[edge[i].y] = 0;
  }

  sort(edge + 1, edge + n, cmp);
  for(i=1;i<=n;i++)
  {
   int x,y;
   x = find_set(edge[i].x);
   y = find_set(edge[i].y);
   //�жϼ������������Ƿ���γɻ�·
   if(x != y)
   {
    //ѡ��������
    edge[i].selected = true;
    //�ϲ������γɻ�·�Ķ�������
    union_set(x,y,edge[i].weight,sum);
   }
  }

  cout<<"��С�������ı߼�Ϊ��"<<endl;
  for(i=1;i<=n;i++)
  {
   if(edge[i].selected)
   {
    cout<<"��ţ�"<<edge[i].no<<"  " <<"�˵�1��"<<(char)(edge[i].x+'a'-1)<<",�˵�2��"<<(char)(edge[i].y+'a'-1)<<endl;
   }
  }
  cout<<"��С��������ȨֵΪ��"<<sum<<endl;
 }
 return 0;
}
