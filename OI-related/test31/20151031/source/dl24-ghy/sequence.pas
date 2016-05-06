var
	a:array[1..100001] of Longint;
	m,n,j,l,r,num,o:Longint;
procedure updata(x,y:Longint);
	begin
		a[x]:=y;
	end;
procedure print(x,y,z,w:Longint);
	var
		d,e,f:Longint;
begin
	if w=1 then writeln;
	if (x>=y) and (y>=z) then 
	begin
	d:=x;
	e:=y;
	f:=z;
	end;
	if (z>=y) and (y>=x) then 
	begin
	d:=z;
	e:=y;
	f:=x;
	end;
	if (x>=z) and (z>=y) then 
	begin
	d:=x;
	e:=z;
	f:=y;
	end;
	if (z>=x) and (x>=y) then 
	begin
	d:=z;
	e:=x;
	f:=y;
	end;
	if (y>=x) and (x>=z) then 
	begin
	d:=y;
	e:=x;
	f:=z;
	end;
	if (y>=z) and (z>=x) then 
	begin
	d:=y;
	e:=z;
	f:=x;
	end;
	write(f,' ',e,' ',d);
end;
procedure find(x:Longint);
	var
		i,t,h:Longint;
	begin
		for i:=3 to n do
			for t:=2 to i-1 do 
				for h:=1 to i-2 do 
					begin
						if (a[t]+a[h]>a[i])  and (a[t]+a[i]>a[h]) and (a[h]+a[i]>a[t]) then 
							begin
							print(a[t],a[h],a[i],x);
							exit;
							end;
					end;
		print(-1,-1,-1,x);
	end;

begin
	assign(input,'sequence.in');
	assign(output,'sequence.out');
	reset(input);
	rewrite(output);
	read(n);
	for j:=1 to n do read(a[j]);
	o:=0;
	num:=1;
	read(m);
	for j:=1 to m do 
		begin
			read(l);
			if l=2 then 
				begin
				if num>1 then o:=1;
				find(o);
				inc(num);
				end
			else begin
				read(l,r);
				updata(l,r);
			end; 
		end;
	close(input);
	close(output);
end.