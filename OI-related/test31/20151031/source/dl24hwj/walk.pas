var
//v:array[0..10000,0..10000] of boolean;
n,c,x,y,i,j,ans:integer; 
f:array[1..2] of integer =(1,0);
f2:array[1..2] of integer =(0,1);
a:array[0..10000,0..10000] of 0..1;
procedure dfs(x,y:longint);
var i,j:integer;
begin
if (x=n)and(y=n) then begin 
	inc(ans);exit;end else 
	for i:=1 to 2 do 
if(x+f[i]>=y+f2[i])and(a[x+f[i],y+f2[i]]=0)and (y+f2[i] in [0..n])and (x+f[i] in[0..n])then 
	begin 
	a[x+f[i],y+f2[i]]:=1;
dfs(x+f[i],y+f2[i]);	
a[x+f[i],y+f2[i]]:=0;
	end;
end;


begin 
assign(input,'walk.in');reset(input);
assign(output,'walk.out');reset(output);
readln(n,c);
for i:=0 to n do  for j:=0 to n do a[i,j]:=0;
ans:=0;
for i:=1 to c do 
	begin  
readln(x,y);a[x,y]:=1;
end;
dfs(0,0);
writeln(ans);
close(input);close(output);
end.
