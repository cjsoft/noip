var a:array[1..100000] of longint;
n,m,i,j,k,ovo,sf,x,y:longint;
function sjx(x,y,z:longint):boolean;
	begin
	if (x+y>z) and (x+z>y) and (z+y>x) then exit(true)
			else exit(false);
	end;
procedure print(x,y,z:longint);
	begin
	if (x<=y) and (y<=z) then begin writeln(x,' ',y,' ',z);exit;end;
	if (x<=z) and (z<=y) then begin writeln(x,' ',z,' ',y);exit; end ;
	if (y<=x) and (x<=z) then begin writeln(y,' ',x,' ',z);exit;end;
	if (y<=z) and (z<=x) then begin writeln(y,' ',z,' ',x);exit; end ;
	if (z<=y) and (y<=x) then begin writeln(z,' ',y,' ',x);exit;end;
	if (z<=x) and (x<=y) then begin writeln(z,' ',x,' ',y);exit; end ;
	end;
procedure orz;
	begin
		for k:= 3 to n do 
			for i:= 2 to k-1 do 
				for j:= 1 to i-1 do 
				if sjx(a[k],a[i],a[j]) then begin print(a[k],a[i],a[j]);exit;end;
		writeln('-1 -1 -1');
	end;
begin
			assign(input,'sequence.in');
assign(output,'sequence.out');
reset(input);rewrite(output);
readln(n);
for i:= 1 to n do 
	read(a[i]);
readln(m);
for ovo:= 1 to m do 
	begin
	read(sf);
	if sf=1 then 
		begin
		readln(x,y);
		a[x]:=y;
		end;
	if sf=2 then orz;
	end;
	close(input);close(output);
end.