const saffah=1000000007;
var a:array[0..5001,0..5001] of longint;
i,j,t1,t2,n,m,x,y,qaq,ans:longint;
function jc(x:longint):longint;
var i:longint;
	begin
	qaq:=1;
	for i:= 1 to x do 
	qaq:=qaq*i mod saffah;
	jc:=qaq;

	end;
begin
		assign(input,'walk.in');
assign(output,'walk.out');
reset(input);rewrite(output);
readln(n,m);
for i:= 0 to n do 
a[i,0]:=1;
if m=0 then
	 begin
	ans:=jc(2*n);
	ans :=ans  div (jc(n)*jc(n));
	ans :=ans div (n+1);
	writeln(ans);
	halt;
	end;

for i:= 1 to m do
begin 
	readln(x,y);
	a[x,y]:=-1;
end;
a[0,0]:=1;
for i:= 0 to n do 
	for j:= 0 to i do 
	begin
	if (a[i,j]<>-1) and (i>0) and (j>0) then 
		begin
		t1:=a[i-1,j];
		t2:=a[i,j-1];
		if t1=-1 then t1:=0;
		if t2=-1 then t2:=0;
		a[i,j]:=(t1+t2) mod saffah;
		end;
	end; 
writeln(a[n,n]);
close(input);
close(output);
end.