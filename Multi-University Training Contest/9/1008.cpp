#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;

int c[maxn];
int m,n;
map<int,int> d;
vector<int> a;
int main(){
    while(~scanf("%d",&m)){
        d.clear();a.clear();
        n=sqrt(m<<1);
        for(int i=0;i<m;++i){
            scanf("%d",&c[i]);
            d[c[i]]++;
        }
        sort(c,c+m);
        a.push_back(c[0]);a.push_back(c[1]);
        d[c[1]]--;d[c[0]]--;
        for(int i=1;i<m && a.size()<n;++i){
            int si=a.size()-1;
            for(int j=0;j<si;++j){
                if(d.find(a[si]+a[j])!=d.end() && d[a[si]+a[j]]>0){
                    d[a[si]+a[j]]--;
         //           printf("IDone %d\n",a[si-1]+a[j]);
                }
            }
            while(d[c[i]]==0){
                int no=c[i];
                while(c[i]==no){
                    ++i;
                    if(i>=m)break;
                }
                if(i>=m)break;
    //            printf("Done %d\n",c[i]);
            }
            if(i<m){
                a.push_back(c[i]);
         //       printf("Push %d\n",c[i]);
                d[c[i]]--;
            }
            --i;
        }
        printf("%d\n",a.size());
        printf("%d",a[0]);
        for(int i=1;i<a.size();++i){
            printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
