type node = record
	l,r,lson,rson,min:longint;
	s:array[1..6]of qword;
	end;
const jiecheng:array[1..6]of longint=(1,2,6,24,120,720);
teachk=4294967295;

var tree:array[1..265000]of node;
now:longint;
d,v:array[1..110000]of longint;
i:longint;
n,q:longint;
t1,t2,t3,k:longint;

ans:node;

operator +(const a,b:node)c:node;
var i,t1,t2:longint;
begin
c.s[1]:=(a.s[1]+b.s[1]) and teachk;

c.s[2]:=(a.s[1]*b.s[1]) and teachk;
c.s[2]:=(c.s[2]+(a.s[2]+b.s[2])) and teachk;

c.s[3]:=(a.s[1]*b.s[2]) and teachk;
c.s[3]:=(c.s[3]+a.s[2]*b.s[1]) and teachk;
c.s[3]:=(c.s[3]+a.s[3]+b.s[3]) and teachk;

c.s[4]:=0;
for i:=1 to 3 do c.s[4]:=(c.s[4]+a.s[i]*b.s[4-i]) and teachk;
c.s[4]:=(c.s[4]+a.s[4]+b.s[4]) and teachk;

c.s[5]:=0;
for i:=1 to 4 do c.s[5]:=(c.s[5]+a.s[i]*b.s[5-i]) and teachk;
c.s[5]:=(c.s[5]+a.s[5]+b.s[5]) and teachk;

c.s[6]:=0;
for i:=1 to 5 do c.s[6]:=(c.s[6]+a.s[i]*b.s[6-i]) and teachk;
c.s[6]:=(c.s[6]+a.s[6]+b.s[6]) and teachk;


t1:=a.min;t2:=b.min;
if t1<t2 then c.min:=t1 else c.min:=t2;

end;


procedure sort(l,r: longint);
var
	i,j,x,y: longint;
begin
	i:=l;
	j:=r;
	x:=d[(l+r) div 2];
	repeat
	while d[i]<x do
		inc(i);
	while x<d[j] do
		dec(j);
	if not(i>j) then
		begin
			y:=d[i];
			d[i]:=d[j];
			d[j]:=y;
			y:=v[i];
			v[i]:=v[j];
			v[j]:=y;
			inc(i);
			j:=j-1;
		end;
	until i>j;
	if l<j then
	sort(l,j);
	if i<r then
	sort(i,r);
end;

procedure relax(a:longint);
var t1,t2:longint;
begin
tree[a].s[1]:=(tree[a<<1].s[1]+tree[a<<1+1].s[1]) and teachk;

tree[a].s[2]:=(tree[a<<1].s[1]*tree[a<<1+1].s[1]) and teachk;
tree[a].s[2]:=(tree[a].s[2]+(tree[a<<1].s[2]+tree[a<<1+1].s[2])) and teachk;

tree[a].s[3]:=(tree[a<<1].s[1]*tree[a<<1+1].s[2]) and teachk;
tree[a].s[3]:=(tree[a].s[3]+tree[a<<1].s[2]*tree[a<<1+1].s[1]) and teachk;
tree[a].s[3]:=(tree[a].s[3]+tree[a<<1].s[3]+tree[a<<1+1].s[3]) and teachk;

tree[a].s[4]:=0;
for i:=1 to 3 do tree[a].s[4]:=(tree[a].s[4]+tree[a<<1].s[i]*tree[a<<1+1].s[4-i]) and teachk;
tree[a].s[4]:=(tree[a].s[4]+tree[a<<1].s[4]+tree[a<<1+1].s[4]) and teachk;

tree[a].s[5]:=0;
for i:=1 to 4 do tree[a].s[5]:=(tree[a].s[5]+tree[a<<1].s[i]*tree[a<<1+1].s[5-i]) and teachk;
tree[a].s[5]:=(tree[a].s[5]+tree[a<<1].s[5]+tree[a<<1+1].s[5]) and teachk;

tree[a].s[6]:=0;
for i:=1 to 5 do tree[a].s[6]:=(tree[a].s[6]+tree[a<<1].s[i]*tree[a<<1+1].s[6-i]) and teachk;
tree[a].s[6]:=(tree[a].s[6]+tree[a<<1].s[6]+tree[a<<1+1].s[6]) and teachk;


t1:=tree[a<<1].min;t2:=tree[a<<1+1].min;
if t1<t2 then tree[a].min:=t1 else tree[a].min:=t2;
end;


procedure maketree(l,r,now:longint);
begin
tree[now].l:=l;
tree[now].r:=r;
if l=r then begin
	tree[now].min:=v[l];
	tree[now].s[1]:=v[l];
	tree[now].s[2]:=0;
	tree[now].s[3]:=0;
	exit;
	end
else begin
	tree[now].lson:=now<<1;
	tree[now].rson:=now<<1+1;
	maketree(l,(l+r)>>1,now<<1);
	maketree((l+r)>>1+1,r,now<<1+1);
	relax(now);
	end;
end;

function erfen(a,l,r:longint):longint;
var mid:longint;
begin
if l=r then exit(l) else begin
	mid:=(l+r)>>1;
	if a>d[mid] then exit(erfen(a,mid+1,r)) else exit(erfen(a,l,mid));
	end;
end;

procedure ask(l,r,now:longint);
begin
if (tree[now].l=l) and (tree[now].r=r) then begin
	ans:=ans+tree[now];
	exit;
	end
else if r<=tree[now<<1].r then begin
	ask(l,tree[now<<1].r,now<<1);
	exit;
	end
else if l>=tree[now<<1+1].l then begin
	ask(tree[now<<1+1].l,r,now<<1+1);
	exit;
	end
else begin
	ask(l,tree[now<<1].r,now<<1);
	ask(tree[now<<1+1].l,r,now<<1+1);
	exit;
	end;
end;


procedure query(l,r,k:longint);
var i:longint;
o:int64;
begin
ans.min:=maxlongint;
for i:=1 to 6 do ans.s[i]:=0;
ask(l,r,1);
o:=(ans.s[1]-ans.min) mod (teachk+1);
for i:=2 to k do o:=(ans.s[i]-o) mod (teachk+1);
if o<0 then o:=o+(teachk+1);
o:=o*jiecheng[k] mod (teachk+1);
writeln(o);
end;



begin
assign(input,'melancholy.in');
assign(output,'melancholy.out');
reset(input);
rewrite(output);

read(n,q);
for i:=1 to n do read(d[i]);
for i:=1 to n do read(v[i]);
sort(1,n);
maketree(1,n,1);
for i:=1 to q do begin
	read(t1,t2,k);
	t1:=erfen(t1,1,n);
	t3:=erfen(t2,1,n);
	if t2>=d[t3] then t2:=t3 else t2:=t3-1;
	query(t1,t2,k);
	end;
close(input);
close(output);

end.
