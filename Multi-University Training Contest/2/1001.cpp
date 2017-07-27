///HDU 6045
#include<bits/stdc++.h>
using namespace std;
const int maxn=80000+10;
int N,X,Y,T,ans;
char str1[maxn],str2[maxn];
bool judge1(int same,int dif,int m,int l){
    ///即来自不同,又来自相同
    int mxs=min(same,m);///把相同部分最大化贡献
    int mxd=m-mxs;
    if(mxs+dif-mxd>=l) return true;
    return false;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%*c",&N,&X,&Y);ans=0;
        int res=min(X,Y),lar=max(X,Y);///最小得分的
        ///无论相同还是不同,A,B都可以是对的
        ///但相同贡献给A,B.不同只贡献给A|B
        gets(str1);gets(str2);
        for(int i=0;i<N;++i) if(str1[i]==str2[i]) ans++;
        int same=ans,dif=N-ans;
        ///最小得分的分可以来自相同,也可以来自不同,或者两者
        if(judge1(same,dif,res,lar)) puts("Not lying");
        else puts("Lying");
    }
    return 0;
}
