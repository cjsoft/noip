program dy3;
var n:longint;
var b,a:array[1..100000]of longint;
var q,isr,isl,r,i,j,k,l:longint;

	procedure sort(x,y:longint);
	var mid,ll,rr,c,d:longint;
	begin
		ll:=x;
		rr:=y;
		mid:=a[(ll+rr) div 2];
		repeat
			while a[ll]<mid do inc(ll);
			while a[rr]>mid do dec(rr);
			if rr>=ll then 
				begin
					c:=a[ll];
					d:=b[ll];
					a[ll]:=a[rr];
					b[ll]:=b[rr];
					a[rr]:=c;
					b[rr]:=d;
					inc(ll);
					dec(rr);
				end;
		until ll>rr;
		if ll<y then sort(ll,y);
		if rr>x then sort(x,rr);
	end;

begin
assign(input,'melancholy.in');
assign(output,'melancholy.out');
reset(input);
rewrite(output);

	readln(n,q);
	for i:=1 to n do
		read(a[i]);
	readln;
	for i:=1 to n do
		read(b[i]);
		
	for i:=1 to q do
		begin
		readln(l,r,k);
		if l>a[n] then 
			begin
			writeln(0);
			continue;
			end;
		if r<a[1] then 
			begin
			writeln(0);
			continue;
			end;
		for j:=1 to n-1 do
			begin
			if l<a[1] then begin isl:=1; break; end
				else if l=a[j] then begin isl:=j; break; end
					else if (l>a[j]) and (l<a[j+1]) then begin isl:=j+1; break; end;
			end;
		
		for j:=1 to n-1 do
			begin
			if r>a[n] then begin isr:=n; break; end
				else if r=a[j] then begin isr:=j; break; end
					else if (r>a[j]) and (r<a[j+1]) then begin isr:=j+1; break; end;
			end;
		writeln('0');
		end;

close(input);
close(output);
end.

