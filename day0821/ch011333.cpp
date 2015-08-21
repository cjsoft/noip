#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct bfloat
{
	int zhengshu[257],xiaoshu[257];
	bfloat(){
		memset(zhengshu,0,sizeof(zhengshu));
		memset(xiaoshu,0,sizeof(xiaoshu));
	}
	void erasezero(){
		for(int i=256;i>=0;--i){
			if(xiaoshu[i])
				return ;
			xiaoshu[i]=-'0';
		}
	}
}a,b;

bfloat operator+(bfloat a,bfloat b){
	bfloat rtn;
	for(int i=256;i>=0;--i){
		rtn.xiaoshu[i]=a.xiaoshu[i]+b.xiaoshu[i];
	}
	for(int i=256;i>0;--i){
		rtn.xiaoshu[i-1]+=rtn.xiaoshu[i]/10;
		rtn.xiaoshu[i]%=10;
	}
	rtn.zhengshu[0]+=rtn.xiaoshu[0]/10;
	rtn.xiaoshu[0]%=10;
	for(int i=0;i<257;++i){
		rtn.zhengshu[i]+=a.zhengshu[i]+b.zhengshu[i];
	}
	for(int i=0;i<256;++i){
		rtn.zhengshu[i+1]+=rtn.zhengshu[i]/10;
		rtn.zhengshu[i]%=10;
	}
	return rtn;
}
char sa[257*2-1],sb[257*2-1];
int main(){
	scanf("%s\n%s",sa,sb);
	int la=strlen(sa),lb=strlen(sb);
	int lp=-1,rp=-1;
	for(int i=0;i<la;++i){
		if(sa[i]=='.'){
			lp=i;
			break;
		}
	}
	for(int i=0;i<lb;++i){
		if(sb[i]=='.'){
			rp=i;
			break;
		}
	}
	for(int i=0;i<lp;++i){
		a.zhengshu[lp-1-i]=sa[i]-'0';
	}
	for(int i=0;i<rp;++i){
		b.zhengshu[rp-1-i]=sb[i]-'0';
	}
	for(int i=lp+1;i<la;++i){
		a.xiaoshu[i-lp-1]=sa[i]-'0';
	}
	for(int i=rp+1;i<lb;++i){
		b.xiaoshu[i-rp-1]=sb[i]-'0';
	}
	bfloat c=a+b;
	bool tag=true;
	for(int i=256;i>=0;--i){
		if(c.zhengshu[i])
			tag=false;
		if(!tag)
			putchar(c.zhengshu[i]+'0');
	}
	if(tag)
		putchar('0');
	putchar('.');
	c.erasezero();
	for(int i=0;i<257;++i){
		if(c.xiaoshu[i]==-'0')
			break;
		putchar(c.xiaoshu[i]+'0');
	}
	putchar('\n');
	return 0;
}