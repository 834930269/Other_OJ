#include<bits/stdc++.h>
using namespace std;
int N,M;
string str[200];
map<string,string> mp;
int main(){
    cin>>N>>M;getchar();
    for(int i=0;i<N;++i){
        getline(cin,str[i]);
    }
    for(int i=0;i<M;++i){
        string a,b;
        cin>>a;getchar();
        getline(cin,b);
        mp[a]=b.substr(1,b.length()-2);
    }
    for(int i=0;i<N;++i){
        int le=str[i].length();
        string &tp=str[i],ans;
        for(int j=0;j<le;++j){
            if(tp[j]=='{'&&j+1<le&&tp[j+1]=='{'){
                string qb,sp;
                j++;
                qb+="{{ ";
                for(j+=2;j<le;++j){
                    if(tp[j]==' '&&j+2<le&&tp[j+1]=='}'&&tp[j+2]=='}'){
                        qb+=" }}";
                        j+=2;
                        break;
                    }
                    qb+=tp[j];
                    sp+=tp[j];
                }
                if(mp.count(sp)>0){
                    ans+=mp[sp];
                }
                continue;
            }
            if(j<le)
                ans+=tp[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
