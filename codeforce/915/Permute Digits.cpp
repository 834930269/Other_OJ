#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

long long str_2_num(string str){
    long long reg=0;
    int len=str.size();
    for(int i=0;i<len;++i){
        reg*=10;
        reg+=(str[i]-'0');
    }
    return reg;
}

int main(){
    string a,b;
    while(cin>>a>>b){
        int len=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<len;++i){
            for(int j=i;j<len;++j){
                string tmp=a;
                swap(tmp[i],tmp[j]);
                sort(tmp.begin()+i+1,tmp.end());
                if(str_2_num(tmp)<=str_2_num(b)&&str_2_num(tmp)>=str_2_num(a))swap(a[i],a[j]);
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
