#include<cstdio>
#include<iostream>
using namespace std;

int n,q,t1,t2,t3,t4,t5,t6;

int all[1002];

void ask(){
	for (int j=2;j<n;j++){
		for (int i=1;i<j;i++){
			for (int k=j+1;k<=n;k++){
				t1=all[j];
				t2=all[i];
				t3=all[k];
				if (t1>t2){
					t4=t1;
					t1=t2;
					t2=t4;
				}
				if (t1>t3){
					t4=t1;
					t1=t3;
					t3=t4;
				}
				if (t2>t3){
					t4=t2;
					t2=t3;
					t3=t4;
				}
				
				if (t3-t2<t1&&t1+t2>t3){
					cout<<t1<<' '<<t2<<' '<<t3<<endl;
					return;
				}
			}
		}
	}
	
	cout<<"-1 -1 -1"<<endl;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n;
	
	for (int i=1;i<=n;i++){
		cin>>all[i];
	}
	
	cin>>q;
	
	for (int i=1;i<=q;i++){
		cin>>t4;
		if (t4==2) ask();
		else{
			cin>>t5>>t6;
			all[t5]=t6;
		}
	}
	
	return 0;
}
