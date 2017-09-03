#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

struct Node{
	int health,attack;
	Node(){

	}
	Node(int h,int a){
		health = h;
		attack = a;
	}
};
struct Role{
	Node card[10];
	int health;
	int num;
	Role(){}

};
void add(Role &x,Node b,int p){
	x.num++;
	for(int i = x.num; i > p; i--)
		x.card[i] = x.card[i-1];
	x.card[p] = b;
}

void del(Role &x,int p,int d){
	x.card[p].health -= d;
	if(x.card[p].health <= 0){
		for(int i = p;i < x.num; i++)
			x.card[i] = x.card[i+1];
		x.num--;
	}
}
int main(){
	Role role[2];
	string ope;
	int p,a,h,d;
	role[0].health = role[1].health = 30;
	role[0].num = role[1].num = 0;

	int n,now=0;
	cin>>n;
	while(n--){
		cin>>ope;
		if(ope == "summon"){
			cin>>p>>a>>h;
			add(role[now],Node(h,a),p);
		}
		else if(ope == "attack"){
			cin>>a>>d;
			if(d == 0){
				role[now^1].health -= role[now].card[a].attack;
			}
			else{
				int x1 = role[now].card[a].attack;
				int x2 = role[now^1].card[d].attack;
				del(role[now],a,x2);
				del(role[now^1],d,x1);
			}
		}
		else if(ope == "end"){
			now ^= 1;///ÆæÊý-1,Å¼Êý+1
		}

	}
	if(role[0].health <= 0) cout<<-1<<endl;
	else if(role[1].health <= 0)cout<<1<<endl;
	else cout<<0<<endl;

	cout<<role[0].health<<endl;
	cout<<role[0].num;
	for(int i = 1;i <= role[0].num; i++)
		cout<<" "<<role[0].card[i].health;
	cout<<endl;

	cout<<role[1].health<<endl;
	cout<<role[1].num;
	for(int i = 1;i <= role[1].num; i++)
		cout<<" "<<role[1].card[i].health;
	cout<<endl;

	return 0;

}

