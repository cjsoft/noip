#include <cstdio>
#include <cstring>
#include <algorithm>
#define for1(i,a,n) for(i=a;i<=(n);++i)
#define for2(i,a,n) for(i=a;i<(n);++i)
#define for3(i,a,n) for(i=a;i>=(n);--i)
#define for4(i,a,n) for(i=a;i>(n);--i)
#define CC(i,a) memset(i, a, sizeof(i))
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;

const int N=1000000;
char s[N];
int sa[N], t1[N], t2[N], c[N], r[N], height[N], rank[N];

void hz(int* r, int n, int m) {
    int i, j, p, *x=t1, *y=t2, *t;
    for2(i, 0, m) c[i]=0;
    for2(i, 0, n) c[ x[i]=r[i] ]++; //给排名为x[i]的计数
    for2(i, 1, m) c[i]+=c[i-1];     //将计数数组c累加，目的是给sa提供下标
    for3(i, n-1, 0) sa[ --c[x[i]] ]=i;  //sa数组用c提供的名次下标更新原数组下标
    for(j=1, p=0; j<=n   && p<n; j<<=1, m=p) { //p<n时退出，因为此时排名已经不同，此优化很重要，并且每一次将m更新为最大值p
        p=0;
        for2(i, n-j, n) y[p++]=i;   //y数组充当第二关键字的sa数组，这里是初始化那些没有第二关键字的，即第二关键字为0的，所以他们最小放在前面
        for2(i, 0, n) if(sa[i]>=j) y[p++]=sa[i]-j;   //因为是第二关键字，所以要标到第一关键字的下标来
        for2(i, 0, m) c[i]=0;   //同之前的基数排序一样
        for2(i, 0, n) c[ x[y[i]] ]++;   //用第二关键字的下标引导rank，找到对应第一关键字的rank累计
        for2(i, 1, m) c[i]+=c[i-1];     //同上
        for3(i, n-1, 0) sa[ --c[x[y[i]]] ]=y[i];    //sa数组用c提供的 第二关键字尽量大中的 第一关键字下标 的名次更新到这个这个 第二关键字尽量大中的 第一关键字下标
        for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; ++i) //y数组可以不要了，将它赋值为这一次的rank，x数组作为下一个rank数组，所以更新
            x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]?p-1:p++;    //当第一关键字的rank相等并且第二关键字的rank相等说明这个下标的rank和其中一个相等，所以名次还是为上一个
    }
}

void getheight(int n) {
    int i, j, k;
    for1(i, 1, n) rank[sa[i]]=i;    //因为sa下标从1开始，rank下标从0开始，值域从1开始
    for(k=i=0; i<n; height[rank[i++]]=k) //根据h[i]>=h[i-1]-1，我们循环的是h[i]，所以h[i-1]不需保存，其中h[i]我们用k来代替了
        for(k?k--:0, j=sa[rank[i]-1]; s[i+k]==s[j+k]; k++);     //因为h[i-1]-1是.............（自己看论文或白书去）。我们只需要根据前一个后缀来更新最大前缀。
}

// int main() {
    // scanf("%s", s);
    // int i, n=strlen(s);
    // for2(i, 0, n) r[i]=s[i]-'a'+1; //这里的r随便，如果知道范围的话，c数组可以相应的开小一些，我这里直接27了。。
    // hz(r, n+1, 27); //为了让sa的下标从1开始，我们插入了一个比所有字符还要小的字符到末尾，所以sa的下标就从1开始了，方便计算height而不会导致越界～
    // //...
    // getheight(n);
    // for2(i, 1, n + 1) printf("%d ", sa[i] + 1); puts("");
    // for1(i, 2, n) printf("%d ", height[i]); puts("");
    // //...
    // return
int sequence[N];
int main() {
  scanf("%s", s);
  int l1 = strlen(s);
  s[l1] ='\0';
  scanf("%s", s + l1 + 1);
  int l2 = strlen(s + l1 + 1);
  for (int i = 0; i < l1 + l2 + 1; ++i) {
    sequence[i] = s[i] + 1;
  }
  sequence[l1] = 0;
  hz(sequence, l1 + l2 + 2, 257);
  getheight(l1 + l2 + 1);
  // getsa(sequence, sa, l1 + l2 + 2, 257);
  // getheight(sequence, sa, h, l1 + l2 + 1);
  int resu = 0;
  // printf("%d %d\n", l1, l2);
  // for (int i = 0; i <= l1 + l2 + 2; ++i) printf(" - %d %d\n", sa[i], h[i]);
  for (int i = 2; i <= l1 + l2 + 1; ++i) {
    if ((sa[i] - l1) * (sa[i - 1] - l1) < 0) resu = std::max(resu, height[i]);
  }
  printf("%d\n", resu);
  return 0;
}
