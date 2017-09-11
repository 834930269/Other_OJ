#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

const int maxn=200000;
struct node {
    int v,next;
} edge[maxn];

int DFN[maxn],LOW[maxn];
int stack[maxn],heads[maxn],visit[maxn],cnt,tot,index;
int ans;

void add(int x,int y)
{
    edge[++cnt].next=heads[x];
    edge[cnt].v = y;
    heads[x]=cnt;
    return ;
}

void tarjan(int x)
{ //����ڼ������ڴ����ݹ���ǵ㡣
    DFN[x]=LOW[x]=++tot;// �½���ĳ�ʼ����
    stack[++index]=x;//��վ
    visit[x]=1;//��ʾ��ջ��
    for(int i=heads[x];~i;i=edge[i].next)
    {
        int vv=edge[i].v;
        if(!DFN[edge[i].v])
        {//���û���ʹ�
            tarjan(edge[i].v);//���½������죬��ʼ�ݹ�
            LOW[x]=min(LOW[x],LOW[edge[i].v]);//�ݹ�������Ƚ�˭��˭�Ķ��ӣ����ף��������Ķ�Ӧ��ϵ���漰��ǿ��ͨ����������С�������顣
        }
        else if(visit[edge[i].v])
        { //������ʹ������һ���ջ�
            LOW[x]=min(LOW[x],DFN[edge[i].v]);//�Ƚ�˭��˭�Ķ��ӣ����ס��������Ӷ�Ӧ��ϵ
        }
    }
    if(LOW[x]==DFN[x])
    { //����������ǿ��ͨ�������������С����
        int now=0;
        do
        {
            visit[stack[index]]=0;
            index--;
            now++;
        } while(x!=stack[index+1]);//��ջ�����������
        ans+=(now*(now-1)>>1);
    }
}

int main(){
    memset(heads,-1,sizeof(heads));
    ans=0;
    int n,m;
    scanf("%d%d",&n,&m);
    int xx,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&xx,&y);
        add(xx,y);
    }
    for(int i=1;i<=n;i++)
        if(!DFN[i])
            tarjan(i);//�������û�з��ʹ����ʹӴ˵㿪ʼ����ֹͼû����
    printf("%d\n",ans);
    return 0;
}
