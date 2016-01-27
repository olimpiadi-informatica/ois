const
    MAXN = 10000;
    MAXQ = 1000;
type
    matrix = array[0..MAXN-1] of array[0..MAXQ-1] of longint;


function compra(N, Q: longint; var V: matrix): longint;
begin
    (* Mettete qui il codice della soluzione *)
    compra := 42;
end;


var
    N, Q, i, j  : longint;
    G           : matrix;
    fr, fw      : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, Q);
    for i:=0 to N-1 do begin
        for j:=0 to Q-1 do
            read(fr, G[i][j]);
        readln(fr);
    end;

    writeln(fw, compra(N, Q, G));
    close(fr);
    close(fw);
end.
