type wxz=record
	d:longint;
	v:longint;
	end;
const saffah=4294967296;	
var a:array[1..10000] of wxz;
c:array[1..10000] of longint;
i,j,tot,k,t1,t2,l,r,ovo,ans,n,m:longint;
procedure sort(l,r: longint);
      var
         i,j,x: longint;
      y:wxz;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2].d;
         repeat
           while a[i].d<x do
            inc(i);
           while x<a[j].d do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
      procedure qsort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=c[(l+r) div 2];
         repeat
           while c[i]<x do
            inc(i);
           while x<c[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           qsort(l,j);
         if i<r then
           qsort(i,r);
      end;

begin
		assign(input,'melancholy.in');
assign(output,'melancholy.out');
reset(input);rewrite(output);
readln(n,m);
for i:= 1 to n do 
	read(a[i].d);
for i:= 1 to n do 
	read(a[i].v);
	sort(1,n);
for ovo:= 1 to m do 
	begin
	readln(l,r,k);
	if k>r-l+1 then begin writeln(0);continue;end;
	tot:=0;
	for i:= 1 to n do 
	begin
	if a[i].d>r then break;
	if (a[i].d>=l) and (a[i].d<=r) then 
		begin 
		inc(tot);
		c[tot]:=a[i].v;
		end;

	end;
	qsort(1,tot);
	if k=1 then 
		begin
		ans:=0;
		for i:= 2 to tot do 
			ans:=ans+(c[i] mod saffah);
		writeln(ans);
		end;
	if k=2 then 
		begin
		ans:=0;
		for i:= 2 to tot-1 do 
			for j:= i+1 to tot do 
			ans:=ans+((c[i] mod saffah)*(c[j] mod saffah)) mod saffah;
		writeln(2*ans);
		end;
	if k=3 then 
		begin
		ans:=0;
		for i:= 2 to tot-2 do 
			for j:= i+1 to tot-1 do 
				for k:= j+1 to tot do 
				ans:=ans+((c[i] mod saffah)*(c[j] mod saffah)*(c[k] mod saffah)) mod saffah;
		writeln(6*ans);
		end;
	end;
	close(input);close(output);
end.
