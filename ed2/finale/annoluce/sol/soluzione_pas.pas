const
    MAXN = 100000;
var
    NN : longint;
    XX, YY, ZZ : array[0..MAXN-1] of int64;

procedure mappatura(N: longint; var X, Y, Z: array of longint);
var i : longint;
begin
    NN := N;
    for i:=0 to N-1 do
    begin
        XX[i] := X[i];
        YY[i] := Y[i];
        ZZ[i] := Z[i];
    end;
end;

function query(D: longint) : longint;
var i : longint;
    dist : int64;
begin
    query := 0;
    dist := D;
    for i:=0 to NN-1 do
    begin
        if XX[i] * XX[i] + YY[i] * YY[i] + ZZ[i] * ZZ[i] <= dist * dist then
            inc(query);
    end;
end;


var
    N, Q, D, i : longint;
    X, Y, Z    : array[0..MAXN-1] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);

    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, X[i], Y[i], Z[i]);

    mappatura(N, X, Y, Z);

    readln(fr, Q);
    for i:=0 to Q-1 do
    begin
        readln(fr, D);
        writeln(fw, query(D));
    end;

    close(fr);
    close(fw);
end.
