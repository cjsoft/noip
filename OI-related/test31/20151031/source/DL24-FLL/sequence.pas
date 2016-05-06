var a:array [1..100000] of longint;
n,i,m,p,t,aa,bb,cc:longint;
b,c:array [1..1000] of longint;

procedure min(a,b,c:longint);
var t:longint;
begin
aa:=a;
bb:=b;
cc:=c;
if aa>bb then begin t:=aa;aa:=bb;bb:=t;end;
if bb>cc then begin t:=bb;bb:=cc;cc:=t;end;
if aa>bb then begin t:=aa;aa:=bb;bb:=t;end;
end;

procedure fff;
var k,i,j:longint;
begin
for k:=3 to n do
	for j:=2 to k-1 do 
		for i:=1 to j-1 do begin
			min(a[i],a[j],a[k]);
			if aa+bb>cc then begin 
				writeln(aa,' ',bb,' ',cc);
				exit;
				end;
			end;
		writeln(-1,' ',-1,' ',-1);
end;

begin
assign(input,'sequence.in');
reset(input);
assign(output,'sequence.out');
rewrite(output);

read(n);
for i:=1 to n do read(a[i]);
read(m);
for i:=1 to m do begin
	read(t);
	if t=1 then begin read(b[i]);read(c[i]);end;
	end;
for p:=1 to m do
	if b[p]=0 then fff
	else a[b[p]]:=c[p];
	
close(input);close(output);	

end.
	