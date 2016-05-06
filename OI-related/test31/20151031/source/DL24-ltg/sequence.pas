var a :array[1..120000] of longint;
i,n,m,x,p,q,r :longint;
papapa :boolean;

procedure check(x,y,z :longint);
begin
    if (x>y) and (y>z) then begin writeln(z,' ',y,' ',x); exit; end;
    if (x>z) and (z>y) then begin writeln(y,' ',z,' ',x); exit; end;
    if (y>z) and (z>x) then begin writeln(x,' ',z,' ',y); exit; end;
    if (y>x) and (x>z) then begin writeln(z,' ',x,' ',y); exit; end;
    if (z>x) and (x>y) then begin writeln(y,' ',x,' ',z); exit; end;
    if (z>y) and (y>x) then begin writeln(x,' ',y,' ',z); exit; end;
end;

begin
        assign(input,'sequence.in');
        assign(output,'sequence.out');
        reset(input);
        rewrite(output);
        read(n);
	for i := 1 to n do read(a[i]);
	read(m);
	for i := 1 to m do begin
		read(x);
		if x=1 then begin
			read(p,q);
			a[p] := q;
		end
		else begin
			papapa := false;
			for r := 3 to n do begin
				for q := 2 to r-1 do begin
					for p := 1 to q-1 do
						if (a[r]+a[q]>a[p]) and (a[r]+a[p]>a[q]) and (a[p]+a[q]>a[r]) then begin
							papapa := true;
							break;
						end;
					if papapa then break;
				end;
				if papapa then break;
			end;
			if papapa then check(a[p],a[q],a[r])
                        else writeln('-1 -1 -1');
		end;
        end;
        close(input);
        close(output);
end.
