#include<bits/stdc++.h>
#define maxn 200005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
//c[]������ÿ���ڵ����ɫ
int c[maxn],head[maxn],len,sum[maxn],size[maxn],vis[maxn];
LL d;
//�߱�
//�ڽӱ�
struct node{
    int v,next;
}p[maxn<<1];

void addedge(int u,int v){
    //�����ָ���ı��
    p[len].v=v;
    //ÿ���ߵ���һ��������һ�μ�¼�ıߵĺ���
    p[len].next=head[u];
    //�ڽӱ�ķ���
    //lenΪ��ǰ�ߵı��

    //ֻ��¼��ǰ�ڵ�����һ���ߵ�λ��
    head[u]=len++;
}
//��������dfs
void dfs(int x,int fa){
    //�������Ϊ�������и���ɫ�ĵ�
    LL pre=sum[c[x]];
    //size�����ǵ�ǰ�ڵ���ӽڵ�����Ŀ
    size[x]=1;
    int add=0;
    //ͨ���ڽӱ�Ե�ǰ�ڵ�x����dfs
    //����0���˳�
    for(int i=head[x];~i;i=p[i].next){
        //��������������,����,��������������
        if(p[i].v==fa)
            continue;
        dfs(p[i].v,x);
        size[x] += size[p[i].v];
        //���㵱ǰ�ڵ��������к͵�ǰ�ڵ���ɫ��ͬ�ĵ�ĸ���
        LL count = size[p[i].v] - sum[c[x]] + pre;
        pre = sum[c[x]];
        //��ǰ�����Ĳ�ͬ��ɫ��ĸ���
        add += count;
        //����������ɫ���ǰ�ɫ,d�����ڲ�ͬ��ɫ����ɵıߵ��ܸ���
        d += count*(count-1)>>1;
    }
    //������xΪ���ڵ�������������x��ͬ��ɫ�ĵ�ĸ���
    sum[c[x]] += add + 1;
}

int main(){
    int n,tcase=1;
    while(~scanf("%d",&n)){
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        d=len=0;
        LL number = 0;
        for(int i=1;i<=n;++i){
            scanf("%d",&c[i]);
            //��¼��ɫ,��ɫ��Χ��[1,n]
            if(!vis[c[i]]){
                vis[c[i]]=1;
                number++;
            }
        }
        for(int i=1;i<n;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1,0);
        //ans��ʼ����(��ɫ����)*(���бߵĸ���)-d(dΪÿ����ɫ��ÿ�������ϱ���ȥ�Ĳ��ᾭ���Ǹ���ɫ��·���ĸ���)
        LL ans=(number*(n-1)*n>>1)-d;
        for(int i=1;i<=n;++i){
            //�����ڵ���ɫ����Ҫ����,���Ѵ��ڵ���ɫ����һ��
            if(vis[i]&&i!=c[1]){
                //�ڸ��ڵ�������ɫi��ͬ����ɫ�ĸ���
                LL count=n-sum[i];
                //ÿ����ɫ��·����=(n*(n-1)>>1)-(count*(count-1)>>1)
                //�Ը��ڵ�Ϊ���ļ�ȥ��ͬ�ڵ�ǰ��ɫ��·���ĸ���
                //���յõ���ans��Ϊ ÿ����ɫ·������ �ĺ�
                ans-=count*(count-1)>>1;
            }
        }
        printf("Case #%d: %lld\n",tcase++,ans);
    }
    return 0;
}
