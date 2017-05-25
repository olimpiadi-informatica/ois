procedure permuta(N: longint; var G, Gtilde: array of longint);
begin
    (* Mettete qui il codice della soluzione *)
end;


const
    MAXN = 100000;
var
    N, i        : longint;
    G, Gtilde   : array[0..MAXN-1] of longint;
    fr, fw      : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, G[i]);

    permuta(N, G, Gtilde);
    for i:=0 to N-1 do
        write(fw, Gtilde[i], ' ');
    writeln(fw);
    close(fr);
    close(fw);
end.
