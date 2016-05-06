const PLP = 2 shl 32;
var 
n,i,j,k,top,l,r:longint;
qst,min:longint;  
pq:array[1..6] of longint;
d,v,a:array[1..100000] of longint;
ta:integer;

procedure prique(x:longint;size:integer);
begin 
inc(top);
pq[top]:=x;
if top=1 then min:=x else if x<min then min:=x;
end;

function fct(x:longint):int64;
var i,k:longint;
begin 
k:=1;for i:=1 to x do k:=k*i;exit(k);
end;

function  ok(s:string;wanted:integer):boolean;
var k,kk:integer;
begin 
kk:=0;
for k:=1 to l do 	if(s[k]='1')then inc(kk);
if(kk=wanted)then exit(true) else exit(false);
end;

procedure main(p,wanted:longint);
var 
s,ss:string;
ans,kk:int64;
num,son,i,j,q:longint;
m:integer;
begin 
ans:=0;
num:=1 shl p;
kk:=fct(wanted);
for i:=1 to num-1  do  begin 
j:=i; 	s:=''; 
while(j<>0) do begin
		m:=j and 1;str(m,ss);s:=s+ss;j:=j shr 1;
	end;//writeln(s);
l:=length(s);
if(ok(s,k))then 	begin //if  there are exactly k*1   in s then!!!!!!!
	son:=1;
	 for q:=1 to l do if(s[q]='1')then  begin
		 son:=son*v[q] mod PLP;//write(v[q],' *');//son:=son*v[k];
	 end;//writeln;
	 inc(ans,son);
		end; end;
writeln(ans*kk mod PLP);
		end;

	begin 
	 assign(input,'melancholy.in');reset(input);
	 assign(output,'melancholy.out');rewrite(output);
readln(n,qst);
for  i:=1 to n do read(d[i]);
for  i:=1 to n do read(a[i]);
for j:=1 to qst do 
	begin
	readln(l,r,k);ta:=0;
	top:=0;fillchar(pq,sizeof(pq),0);
{choose+sort}for i:=1 to n do if(d[i] in[l..r])then prique(a[i],k);	
for i:=1 to top do if pq[i]<>min then begin 
	inc(ta);v[ta]:=pq[i]end;
//for i:=1 to ta do write(v[i]);writeln;
if(ta<k)then writeln (0) else  main(ta,k);
end;
close(input);close(output);
		end.
		