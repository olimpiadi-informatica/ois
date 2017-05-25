procedure risolvi(N, Q: longint; var t, a, b, d: array of longint);
var i: longint;
begin
    (* Mettete qui il codice della soluzione *)
    for i:=0 to Q-1 do
        d[i] := 42;
end;


const
    MAXN = 100000;
    MAXQ = 100000;
var
    N, Q, i  : longint;
    t        : array[0..MAXN-1] of longint;
    a, b, d  : array[0..MAXQ-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, Q);
    for i:=0 to N-1 do
        read(fr, t[i]);
    readln;
    for i:=0 to Q-1 do
        readln(fr, a[i], b[i]);

    risolvi(N, Q, t, a, b, d);

    for i:=0 to Q-1 do
        writeln(fw, d[i]);
    close(fr);
    close(fw);
end.
