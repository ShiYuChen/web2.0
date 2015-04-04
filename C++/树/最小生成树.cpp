#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

struct Edge
{
	int no;        //边的序号
	int x;         //端点1序号
	int y;         // 端点2序号
	int weight;    //权值
	bool selected; //是否被选择
};

Edge edge[MAX];       //边集和

int rank[MAX];        //已找到的最小生成树其中一部分的秩

int parent[MAX];//已找到的最小生成树其中一部分的头结点//用来判断一条边的2个端点是否在一个集合中，即加上这条边是否会形成回路

bool cmp(Edge a, Edge b)
{
	return a.weight <= b.weight;
} 

int find_set(int x)    //找出每一集合的头结点
{
	if(x != parent[x])
		parent[x] = find_set(parent[x]);
 	return parent[x];
}

void union_set(int x,int y,int w,int &sum)      //合并集合
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
 cout<<"请输入案例的个数：";
 cin>>cases;
 while(cases--)
 {
  int n;
  //最小生成树的权值总和
  int sum = 0;
  cout<<"请输入边的个数：";
  cin>>n;
  int i;
  //初始化
  char chx,chy;
  int weight;
  for(i=1;i<=n;i++)
  {
   edge[i].no = i;
   cout<<"请输入第"<<i<<"条边的二个端点的名称(小写字符)：";
   cin>>chx>>chy;
   edge[i].x = chx-'a'+1;
   edge[i].y = chy-'a'+1;
   cout<<"这条边的权值为：";
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
   //判断即加上这条边是否会形成回路
   if(x != y)
   {
    //选择这条边
    edge[i].selected = true;
    //合并不会形成回路的二个集合
    union_set(x,y,edge[i].weight,sum);
   }
  }

  cout<<"最小生成树的边集为："<<endl;
  for(i=1;i<=n;i++)
  {
   if(edge[i].selected)
   {
    cout<<"序号："<<edge[i].no<<"  " <<"端点1："<<(char)(edge[i].x+'a'-1)<<",端点2："<<(char)(edge[i].y+'a'-1)<<endl;
   }
  }
  cout<<"最小生成树的权值为："<<sum<<endl;
 }
 return 0;
}
