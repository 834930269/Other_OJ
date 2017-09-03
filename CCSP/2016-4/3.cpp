//70»•¡Àif80
#include<bits/stdc++.h>
using namespace std;
int N;
int main(){
    scanf("%d",&N);
    string now;
    cin>>now;
    now+='/';
    getchar();
    for(int i=0;i<N;++i){
        string in;
        getline(cin,in);
        if(in[0]=='/'){
            char ans[10000]="";
            int ct=0;
            for(int j=0;j<in.length();++j){
                if(in[j]=='/'&&ct>=1&&ans[ct-1]=='/'){
                    continue;
                }else if(in[j]=='.'){
                    if(in[j-1]!='/'){
                        while(in[j]!='/'){
                            ans[ct++]=in[j];
                            j++;
                        }
                        j--;
                        continue;
                    }
                    if(in[++j]=='.'&&ct>1){
                        ct--;
                        while(ans[ct-1]!='/'){
                            ct--;
                        }
                    }
                }else{
                    ans[ct++]=in[j];
                }
            }
            ans[ct]='\0';
            if(ct>1&&ans[ct-1]=='/') ans[ct-1]='\0';
            puts(ans);
        }else{
            string q;
            q+=now;
            q=q+in;
            char ans[10000]="";
            int ct=0;
            for(int j=0;j<now.length();++j){
                ans[ct++]=now[j];
            }
            for(int j=0;j<in.length();++j){
                if(in[j]=='/'&&ct>1&&ans[ct-1]=='/'){
                    continue;
                }else if(in[j]=='.'){
                    if(in[j-1]!='/'){
                        while(in[j]!='/'){
                            ans[ct++]=in[j];
                            j++;
                        }
                        j--;
                        continue;
                    }
                    if(in[++j]=='.'&&ct>1){
                        ct--;
                        while(ans[ct-1]!='/'){
                            ct--;
                        }
                    }
                }else{
                    ans[ct++]=in[j];
                }
            }
            ans[ct]='\0';
            if(ct>1&&ans[ct-1]=='/') ans[ct-1]='\0';
            puts(ans);
        }
    }
    return 0;
}
