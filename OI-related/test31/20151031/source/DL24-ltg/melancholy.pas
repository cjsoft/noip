const maxn = 4294967296;

var a :array[1..120000, 1..2] of longint;
b :array[1..120000] of longint;
ans :qword;
n,q,i,j,now,l,r,k,min,minn :longint;

begin
assign(input,'melancholy.in');
assign(output,'melancholy.out');
reset(input);
rewrite(output);
read(n,q);
for i := 1 to n do read(a[i,1]);
for i := 1 to n do read(a[i,2]);
for i := 1 to q do begin
read(l,r,k);
now := 0;
for j := 1 to n do
if (a[j,1] >= l) and (a[j,1] <= r) then begin inc(now); b[now] := j; end;
min := maxlongint;
minn := 0;
for j := 1 to now do
if a[b[j],2] < min then begin min := a[b[j],2]; minn := j; end;
b[minn] := 0;
ans := 0;
for j := 1 to now do
if b[j] <> 0 then ans := (ans + a[b[j],2]) mod maxn;
writeln(ans);
end;
close(input);
close(output);
end.
