var     n,i,m,x:longint;
begin
        assign(input,'sequence8.in');
        reset(input);
        assign(output,'test.out');
        rewrite(output);
        readln(n);
        for i:=1 to n do begin
           read(x);
        end;
        readln(m);
        if i=n then writeln('OK');
        close(input);
        close(output);
end.
