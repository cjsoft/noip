const teachk=1000000007;
var n,c:longint;
dp:array[0..5000,-1..5000]of longint;
map:array[0..5000,0..5000]of boolean;
i,j:longint;

procedure solve1;
var t1,t2:longint;
i,j:longint;
begin
for i:=1 to c do begin
	read(t1,t2);
	map[t1,t2]:=true;
	end;
dp[0,0]:=1;
for i:=1 to n do for j:=0 to i do if not map[i,j] then dp[i,j]:=(dp[i-1,j]+dp[i,j-1]) mod teachk;
writeln(dp[n,n]);
end;


begin
assign(input,'walk.in');
assign(output,'walk.out');
reset(input);
rewrite(output);
read(n,c);
if n<=5000 then begin
	fillchar(dp,sizeof(dp),0);
	fillchar(map,sizeof(map),false);
	solve1;
	end;
close(input);
close(output);
end.
