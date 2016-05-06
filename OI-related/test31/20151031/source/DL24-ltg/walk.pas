const maxn = 1000000007;

var dp :array[0..5000, 0..5000] of longint;
a :array[0..5000, 0..5000] of boolean;
n,c,x,y,i,j :longint;

begin
        assign(input,'walk.in');
        assign(output,'walk.out');
        reset(input);
        rewrite(output);
        read(n,c);
	fillchar(a,sizeof(a),true);
	for i := 1 to c do
	begin
		read(x,y);
		a[x,y] := false;
	end;
        for i := 1 to n do
		dp[i,0] := 1;
	for i := 1 to n do
	for j := 1 to i do
	begin
		if a[i-1,j] then dp[i,j] := (dp[i,j] + dp[i-1,j]) mod maxn;
		if a[i,j-1] then dp[i,j] := (dp[i,j] + dp[i,j-1]) mod maxn;
	end;
        for i := 0 to n do begin
        for j := 0 to n do
        write(dp[i,j],'  ');
        writeln;
        end;
        //writeln(dp[n,n] mod maxn);
        close(input);
        close(output);
end.
