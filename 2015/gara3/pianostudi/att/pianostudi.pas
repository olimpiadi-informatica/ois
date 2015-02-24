function pianifica(N: longint; var da, a, crediti: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    pianifica := 42;
end;


const
    MAXN = 100000;
var
    N, i           : longint;
    da, a, crediti : array[0..MAXN-1] of longint;
    fr, fw         : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, da[i], a[i], crediti[i]);

    writeln(fw, pianifica(N, da, a, crediti));
    close(fr);
    close(fw);
end.
