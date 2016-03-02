function apri(N, F: longint; var K: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    apri := 42;
end;


const
    MAXN = 1000000;
var
    N, F, i : longint;
    K       : array[0..MAXN-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, F);
    for i:=0 to N-1 do
        read(fr, K[i]);

    writeln(fw, apri(N, F, K));
    close(fr);
    close(fw);
end.
