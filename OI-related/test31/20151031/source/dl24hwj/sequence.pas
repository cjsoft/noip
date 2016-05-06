const MAX = 9999999;
var 
x,y,mini,minj,mink:longint;
po:1..2;
n,i,j,k,m:longint;
a:array[1..100000] of longint;
function ok(a,b,c:longint):boolean;
begin 
if(a+b>c)and(a+c>b)and(b+c>a)then 
	exit(true) else exit(false);
end;
	function f(a,b,c,k:longint):longint;
	var 
	w:array[1..3] of longint ;
	i,j,t:integer;
	begin 
	w[1]:=a;w[2]:=b;w[3]:=c;
	for i:=1 to 3 do for j:=1 to 3 do 
		if(w[i]<w[j])then begin t:=w[i];w[i]:=w[j];w[j]:=t;end; 
			exit(w[k]);
	end;
	procedure print;
	var i,j,k:longint;
	begin 
	mini:=MAX;minj:=MAX;mink:=MAX;
for i:=1 to n do 
	for j:=i+1 to n do 
		for k:=j+1 to n  do	
	if ok(a[i],a[j],a[k])then begin 
	if(k<mink)then begin 
		mini:=i;minj:=j;mink:=k;end else
	if(j<minj)and(k=mink)then begin 
		mini:=i;minj:=j;mink:=k;end  else
	if(i<mini)and(j=minj)and(k=mink)then begin 
		mini:=i;minj:=j;mink:=k;end;
	end;
	writeln(f(a[mini],a[minj],a[mink],1),' ',f(a[mini],a[minj],a[mink],2),' ',f(a[mini],a[minj],a[mink],3));
	end;
	
begin 
	assign(input,'sequence.in');reset(input);
	assign(output,'sequence.out' );rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);
readln(m);
for i:=1 to m do 
	begin 
read(po);
if(po=2)then print
	else begin  
		read(x,y);a[x]:=y;
	end;
end;
close(input);close(output);
	end.
