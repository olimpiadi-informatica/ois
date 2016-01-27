procedure inizia(N: longint; var M: array of longint);
begin
    (* Mettete qui il codice della soluzione *)
end;

function abbatti(X, D: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    abbatti := D;
end;


const
    MAXN = 100000;
var
    N, T, X, D, i   : longint;
    M               : array[0..MAXN-1] of longint;
    fr, fw          : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, T);
    for i:=0 to N-1 do
        read(fr, M[i]);
    readln(fr);

    inizia(N, M);
    for i:=0 to T-1 do begin
        if i > 0 then write(fw, ' ');
        readln(fr, X, D);
        write(fw, abbatti(X, D));
    end;
    writeln(fw);
    close(fr);
    close(fw);
end.
