const ca=1000000007;
type node=record
	x:longint;
	y:longint;
	end;
var n,c,i,j,x,y,len,le,k,kk:longint;ans:int64;
a:array [0..10000,0..10000] of boolean;
b:array [1..5000000] of node;
begin
assign(input,'walk.in');
reset(input);
assign(output,'walk.out');
rewrite(output);

fillchar(a,sizeof(a),false);
read(n,c);
for i:=0 to n do
for j:=i to n do a[j][i]:=true;

for i:=1 to c do begin
	read(x,y);
	a[x][y]:=false;
	end;
b[1].x:=0;b[1].y:=0;
k:=1;
kk:=1;
le:=1;
repeat
	for i:=k-le+1 to k do begin
		if a[b[i].x+1,b[i].y] then begin
			inc(kk);
			inc(len);
			b[kk].x:=b[i].x+1;
			b[kk].y:=b[i].y;
			end;
		if a[b[i].x,b[i].y+1] then begin
			inc(kk);
			inc(len);
			b[kk].x:=b[i].x;
			b[kk].y:=b[i].y+1;
			end;
		end;
		for j:=kk-len+1 to kk do 
			if (b[j].x=n)and(b[j].y=n) then begin
				inc(ans);ans:=ans mod ca;end;
		k:=kk;
		le:=len;
		len:=0;
until le=0;

writeln(ans);

close(input);close(output);	
end.