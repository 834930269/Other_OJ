///HDU 6045
#include<bits/stdc++.h>
using namespace std;
const int maxn=80000+10;
int N,X,Y,T,ans;
char str1[maxn],str2[maxn];
bool judge1(int same,int dif,int m,int l){
    ///�����Բ�ͬ,��������ͬ
    int mxs=min(same,m);///����ͬ������󻯹���
    int mxd=m-mxs;
    if(mxs+dif-mxd>=l) return true;
    return false;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%*c",&N,&X,&Y);ans=0;
        int res=min(X,Y),lar=max(X,Y);///��С�÷ֵ�
        ///������ͬ���ǲ�ͬ,A,B�������ǶԵ�
        ///����ͬ���׸�A,B.��ֻͬ���׸�A|B
        gets(str1);gets(str2);
        for(int i=0;i<N;++i) if(str1[i]==str2[i]) ans++;
        int same=ans,dif=N-ans;
        ///��С�÷ֵķֿ���������ͬ,Ҳ�������Բ�ͬ,��������
        if(judge1(same,dif,res,lar)) puts("Not lying");
        else puts("Lying");
    }
    return 0;
}
