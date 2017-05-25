function interroga(N, K: longint; var D: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    interroga := 42;
end;


const
    MAXN = 10000;
var
    N, K, i : longint;
    D       : array[0..MAXN-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, D[i]);

    writeln(fw, interroga(N, K, D));
    close(fr);
    close(fw);
end.
