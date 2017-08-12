#include<bits/stdc++.h>

#define BUF_SS 101

using namespace std;

char buf[101];
int pre=-1;

int check_hl(int st){
    char hr[100];
    string tip;
    int ind=st+1,cs=0,hs=0;
    while(buf[ind]!=']'){
        if(buf[ind]=='_'){
            tip+="<em>";
            ind++;
            while(buf[ind]!='_'){
                tip+=buf[ind];
                ind++;
            }
            tip+="</em>";
            ind++;
        }else{
            tip+=buf[ind];
            ind++;
        }
    }
    ind+=2;
    while(buf[ind]!=')'){
        hr[hs++]=buf[ind];
        ind++;
    }
    hr[hs]='\0';
    printf("<a href=\"%s\">",hr);
    cout<<tip<<"</a>";
    return ind-st;
}

int check_em(int st){
    int ind=st+1;
    printf("<em>");
    while(buf[ind]!='_'){
        if(buf[ind]=='['){
            int ed=check_hl(ind);
            ind+=(ed+1);
        }else{
            putchar(buf[ind]);
            ind++;
        }
    }
    printf("</em>");
    return ind-st;
}

void check_h(int sz){
    int n,r=0;
    char sts[20],ste[20];
    while(buf[r]=='#'){
        r++;
    }
    int s=r,e=sz-1;
    sprintf(sts,"<h%d>",r);
    sprintf(ste,"</h%d>",r);
    for(;buf[s]==' ';s++){}
    printf("%s",sts);
    for(int i=s;buf[i]!='\n';++i){
        int ed=0;
        if(buf[i]=='_') ed=check_em(i);
        else if(buf[i]=='[') ed=check_hl(i);
        else putchar(buf[i]);
        i+=ed;
    }
    printf("%s\n",ste);
}

void check_u(int sz){
    if(pre!=2)printf("<ul>\n");
    int s=1,e=sz-1;
    for(;buf[s]==' ';s++){}
    printf("<li>");
    for(int i=s;buf[i]!='\n';++i){
        int ed=0;
        if(buf[i]=='_') ed=check_em(i);
        else if(buf[i]=='[') ed=check_hl(i);
        else putchar(buf[i]);
        i+=ed;
    }
    printf("</li>\n");
}

void check_p(int sz){
    if(pre!=3)printf("<p>");
    if(pre==3)putchar('\n');
    for(int i=0;buf[i]!='\n' && i<sz;++i){
        int ed=0;
        if(buf[i]=='_') ed=check_em(i);
        else if(buf[i]=='[') ed=check_hl(i);
        else putchar(buf[i]);
        i+=ed;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(fgets(buf,BUF_SS,stdin)){
        if(buf[0]=='\n'){
            if(pre==3){
                printf("</p>\n");
                pre=0;continue;
            }else if(pre==2){
                printf("</ul>\n");
                pre=0;continue;
            }
            continue;
        }
        int sz=strlen(buf);
        if(buf[0]=='#') check_h(sz),pre=1;
        else if(buf[0]=='*') check_u(sz),pre=2;
        else check_p(sz),pre=3;
    }
    if(pre==3)printf("</p>\n");
    if(pre==2)printf("</ul>\n");
    return 0;
}
