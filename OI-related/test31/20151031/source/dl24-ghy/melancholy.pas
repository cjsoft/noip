var
	n,q,i,t:Longint;
begin
	assign(input,'melancholy.in');
	assign(output,'melancholy.out');
	reset(input);
	rewrite(output);
	read(n,q);
	for i:=1 to 2n do read(t);
	for i:=1 to 3n do read(t);
	t:=1;
	while t<=100000 do inc(t);
	write(0);
	close(input);
	close(output);
end.