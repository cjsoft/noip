label 23333;
var n,m:longint;
a:array[1..1000]of longint;
i,j,k:longint;
t1,t2:longint;

function pan(a,b,c:longint):boolean;
begin
if a+b<=c then exit(false);
if b+c<=a then exit(false);
if a+c<=b then exit(false);
exit(true);
end;

procedure print(a,b,c:longint);
var min,t1:longint;
begin
min:=a;
t1:=1;
if b<min then begin
	min:=b;
	t1:=2;
	end;
if c<min then begin
	min:=c;
	t1:=3;
	end;
write(min,' ');
if t1=1 then begin
	if b<c then write(b,' ',c) else write(c,' ',b);
	end
else if t1=2 then begin
	if a<c then write(a,' ',c) else write(c,' ',a);
	end
else begin
	if a<b then write(a,' ',b) else write(b,' ',a);
	end;
writeln;
end;

begin
assign(input,'sequence.in');
assign(output,'sequence.out');
reset(input);
rewrite(output);
read(n);
for i:=1 to n do read(a[i]);
read(m);
while m>0 do begin
	read(t1);
	if t1=2 then begin
		for i:=3 to n do for j:=2 to i-1 do for k:=1 to j-1 do if pan(a[i],a[j],a[k]) then begin
			print(a[i],a[j],a[k]);
			goto 23333;
			end;
		end
	else begin
		read(t1,t2);
		a[t1]:=t2;
		end;
	23333:m:=m-1;
	end;
close(input);
close(output);
end.
