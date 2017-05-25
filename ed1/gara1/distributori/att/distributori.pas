function rifornisci(N, M, K: longint; var D: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    rifornisci := 42;
end;


const
    MAXN = 100000;
var
    N, M, K, i : longint;
    D          : array[0..MAXN-1] of longint;
    fr, fw     : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M, K);
    for i:=0 to N-1 do
        read(fr, D[i]);

    writeln(fw, rifornisci(N, M, K, D));
    close(fr);
    close(fw);
end.
