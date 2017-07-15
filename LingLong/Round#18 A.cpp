#include<bits/stdc++.h>
#define cle(x) memset(x,0,sizeof(x))
#define INF 0x3f3f3f3f
using namespace std;

const int maxn=50000+10;
int T,n,q,d[1420];
char str[200];
long long vis[20][20][20];
bool vi[1420];

int main(){
    scanf("%d",&T);
    while(T--){
        cle(d),cle(vis),cle(vi);
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;++i){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            vis[x][y][z]++;
        }
        for(int i=0;i<=10;i++)
        {
            for(int j=0;j<=10;j++)
            {
                for(int k=0;k<=10;k++)
                {
                    for(int x=0;x<=10;x++)
                    {
                        for(int y=0;y<=10;y++)
                        {
                            for(int z=0;z<=10;z++)
                            {
                                int dis=abs(i-x)+abs(j-y)+abs(k-z);
                                if(i==x&&j==y&&k==z)
                                {
                                    if(vis[i][j][k]-1>=0){
                                        d[dis]+=(vis[i][j][k])*(vis[i][j][k]-1)/2;
                                        vi[dis]=true;
                                    }
                                }
                                else if(vis[i][j][k]*vis[x][y][z]>0)
                                {
                                    d[dis]+=vis[i][j][k]*vis[x][y][z];
                                    vi[dis]=true;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=30;++i)d[i]=d[i-1]+d[i]/2;
        for(int i=0;i<q;++i){
            int R;
            scanf("%d",&R);
            R=min(30,R);
            printf("%lld\n",d[R]);
        }
    }
    return 0;
}
