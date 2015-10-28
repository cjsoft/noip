#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <memory.h>
char arr[1007];
using namespace std;
void calc(stack<bool> &nums,stack<char> &ops){
	char to=ops.top();ops.pop();
	if(to=='!'){
		bool tn=nums.top();nums.pop();
		nums.push(!tn);
	}else{
		bool tn1,tn2;
		tn2=nums.top();nums.pop();
		tn1=nums.top();nums.pop();
		if(to=='|')
			nums.push(tn1||tn2);
		else if(to=='&')
			nums.push(tn1&&tn2);
	}
}
bool solve(char se[]){
	stack<bool> nums;
	stack<char> ops;
	int lse=strlen(se);
	for(int i=0;i<lse;++i){
		if(se[i]==' ' || se[i]=='\0')
			continue;
		if(se[i]==')'){
			while(ops.top()!='('){
				calc(nums,ops);
				if(ops.empty())
					break;
			}
			if(!ops.empty())
				ops.pop();
		}else if(se[i]=='V'){
			nums.push(true);
		}else if(se[i]=='F'){
			nums.push(false);
		}else{
			if(ops.empty()){
				ops.push(se[i]);
				continue;
			}
			if((se[i]=='|' || se[i]=='&' )&& !ops.empty()){
				while(ops.top()=='!'){
					calc(nums,ops);
					if(ops.empty())
						break;
				}
				if(!ops.empty())
					while(se[i]=='|' && ops.top()=='&'){
						calc(nums,ops);
						if(ops.empty())
							break;
					}
				ops.push(se[i]);
			}else if(se[i]=='!' || se[i]=='('){
				ops.push(se[i]);
			}
		}
	}
	while(!ops.empty()){
		calc(nums,ops);
	}
	return nums.top();
}
int main(){
	while(!cin.fail() && cin.peek()!=-1){
		memset(arr,0,sizeof(arr));
		cin.getline(arr,1007);
		printf(solve(arr)?"V\n":"F\n");
	}
	
	return 0;
}