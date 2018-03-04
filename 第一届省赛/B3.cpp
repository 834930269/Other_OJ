    #include <iostream>
    #include <stdio.h>
    #include <algorithm>
    #include <set>
    #include <string>
    using namespace std;

    int main()
    {
        pair<int,int>p;
        int n;char str[10];
        int c=1;
        while(cin>>n&&n)
        {
            cout<<"Case "<<c++<<":"<<endl;
            set< pair<int,int> >s;
            while(n--)
            {
                scanf("%s",str);
                scanf("%d%d",&p.first,&p.second);
                if(str[0]=='a')
                    s.insert(p);
                else if(str[0]=='r')
                    s.erase(p);
                else if(str[0]=='f')
                {
                    set< pair<int,int> >::iterator it;
                    it=s.lower_bound(p);//找到set中第一个比p大的元素的位置，找不到则为s.end()
                    for(;it!=s.end();it++)
                    {
                        if(it->first>p.first&&it->second>p.second)//都大于才符合题意
                        {
                            cout<<it->first<<" "<<it->second<<endl;
                            break;
                        }
                    }
                    if(it==s.end())//找不到
                        cout<<-1<<endl;
                }
            }
            cout<<endl;
        }
        return 0;
    }
