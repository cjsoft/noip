program dy1;
var n,m,i,j,k,b,z,x1,y1,cz,ans1,ans2,ans3:longint;
var a:array[1..100001]of longint;
var bol:boolean;

	procedure sort(q,w,e:longint);
	var c,q1,w1,e1:longint;
		begin
		q1:=q;
		w1:=w;
		e1:=e;
		if w1<q1 then 
			begin
			c:=q1;
			q1:=w1;
			w1:=c;
			end;
		if e1<w1 then 
			begin
			c:=e1;
			e1:=w1;
			w1:=c;
			end;
		if w1<q1 then 
			begin
			c:=q1;
			q1:=w1;
			w1:=c;
			end;
		ans1:=q1;
		ans2:=w1;
		ans3:=e1;
		end;

	procedure get3(x:longint);
		begin
		for i:=3 to x do
			for j:=2 to i-1 do
				for k:=1 to j-1 do
					begin
					if (a[i]-a[j]<a[k]) and (a[i]+a[j]>a[k]) then
						begin
						sort(a[i],a[j],a[k]);
						b:=i;
						exit;
						end;
					end;
		ans1:=-1;
		ans2:=-1;
		ans3:=-1;
		end;

begin
assign(input,'sequence.in');
assign(output,'sequence.out');
reset(input);
rewrite(output);

	readln(n);
	for i:=1 to n do
		read(a[i]);
	readln;
	b:=n;
	readln(m);
	for z:=1 to m do
		begin
		read(cz);
		if cz=2 then begin
			if bol=true then 
			writeln(ans1,' ',ans2,' ',ans3)
			else 
				begin
				get3(b);
				writeln(ans1,' ',ans2,' ',ans3);
				bol:=true;
				end;
			readln;
			end else 
			begin
				readln(x1,y1);
				if x1<=b then 
					begin
					a[x1]:=y1;
					bol:=false;
					end;
			end;
		end;

close(input);
close(output);
end.