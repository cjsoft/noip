var	n,c,i,j,x,y:Longint;
	a:array[0..10001,0..10001] of Longint;
const g=1000000007;
begin
	assign(input,'walk.in');
	assign(output,'walk.out');
	reset(input);
	rewrite(output);
	read(n,c);
	fillchar(a,sizeof(A),0);
	if c>0 then begin
		for i:=1 to c Do
			begin
			 	read(x,y);
			 	a[x,y]:=-1;
			 end; 
	end;
	a[0,0]:=1;
	i:=1;
	while (a[i,0]=0) and (i<=n) do 
	begin
		inc(a[i,0]);
		inc(i);
	end;
	while i<=n do 
		begin
			a[i,0]:=0;
			inc(i);
		end;
	for i:=1 to n do 
		for j:=1 to i do 
			begin
			 	if a[i,j]=0 then
			 		a[i,j]:=((a[i-1,j] mod g)+(a[i,j-1] mod g))mod g
				else a[i,j]:=0;
			 end; 
	write(a[n,n]);
	close(input);
	close(output);
end.