#include<bits/stdc++.h>
#define maxn 200005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
//c[]数组是每个节点的颜色
int c[maxn],head[maxn],len,sum[maxn],size[maxn],vis[maxn];
LL d;
//边表
//邻接表
struct node{
    int v,next;
}p[maxn<<1];

void addedge(int u,int v){
    //有向边指向点的编号
    p[len].v=v;
    //每条边的下一条边是上一次纪录的边的号码
    p[len].next=head[u];
    //邻接表的方法
    //len为当前边的编号

    //只记录当前节点的最后一个边的位置
    head[u]=len++;
}
//对树进行dfs
void dfs(int x,int fa){
    //非这个点为根的所有该颜色的点
    LL pre=sum[c[x]];
    //size数组是当前节点的子节点总数目
    size[x]=1;
    int add=0;
    //通过邻接表对当前节点x进行dfs
    //等于0则退出
    for(int i=head[x];~i;i=p[i].next){
        //如果遇到反向边了,跳过,继续往其他边走
        if(p[i].v==fa)
            continue;
        dfs(p[i].v,x);
        size[x] += size[p[i].v];
        //计算当前节点子树所有和当前节点颜色不同的点的个数
        LL count = size[p[i].v] - sum[c[x]] + pre;
        pre = sum[c[x]];
        //当前子树的不同颜色点的个数
        add += count;
        //假设其他颜色都是白色,d即等于不同颜色所组成的边的总个数
        d += count*(count-1)>>1;
    }
    //计算以x为根节点子树的所有与x不同颜色的点的个数
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
            //记录颜色,颜色范围是[1,n]
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
        //ans初始等于(颜色个数)*(所有边的个数)-d(d为每个颜色在每个子树上被减去的不会经过那个颜色的路径的个数)
        LL ans=(number*(n-1)*n>>1)-d;
        for(int i=1;i<=n;++i){
            //不存在的颜色不需要计算,把已存在的颜色计算一下
            if(vis[i]&&i!=c[1]){
                //在根节点中与颜色i不同的颜色的个数
                LL count=n-sum[i];
                //每个颜色的路径数=(n*(n-1)>>1)-(count*(count-1)>>1)
                //以根节点为中心减去不同于当前颜色的路径的个数
                //最终得到的ans即为 每个颜色路径个数 的和
                ans-=count*(count-1)>>1;
            }
        }
        printf("Case #%d: %lld\n",tcase++,ans);
    }
    return 0;
}
