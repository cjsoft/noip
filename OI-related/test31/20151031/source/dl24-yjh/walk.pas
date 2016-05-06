program dy2;
var n,c,i,j,x,y:longint;
var a:array[0..8001,0..8001]of longint;

begin
assign(input,'walk.in');
assign(output,'walk.out');
reset(input);
rewrite(output);

	readln(n,c);
	for i:=1 to n do
		for j:=1 to n do
			a[i,j]:=0;
	
	for i:=1 to c do
		begin
		readln(x,y);
		a[x,y]:=-1;
		end;
	
	for i:=0 to n do
		begin
		for j:=0 to i do
			begin
			if a[i,j]=-1 then a[i,j]:=0
				else if j=0 then a[i,j]:=1 else a[i,j]:=((a[i-1,j] mod 1000000007)+(a[i,j-1] mod 1000000007)) mod 1000000007;
			end;
		end;
	
	writeln(a[n,n]);

close(input);
close(output);
end.