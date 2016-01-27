function pausa(N: longint; var A, B: array of longint): longint;
var i, j: longint;
begin
    pausa := 0;
    for i := 0 to N - 1 do
    begin
        inc(pausa);
        for j := i + 1 to N - 1 do
            if (B[i] > A[j]) and (A[i] < B[j]) then
                inc(pausa);
    end;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    A, B  : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, A[i], B[i]);

    writeln(fw, pausa(N, A, B));
    close(fr);
    close(fw);
end.
