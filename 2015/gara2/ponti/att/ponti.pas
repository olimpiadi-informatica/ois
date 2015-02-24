function costruisci(N, M: longint; var da, a: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    costruisci := 42;
end;


const
    MAXM = 100000;
var
    N, M, i: longint;
    da, a  : array[0..MAXM-1] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i]);

    writeln(fw, costruisci(N, M, da, a));
    close(fr);
    close(fw);
end.
