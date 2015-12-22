function risolvi(N: longint; var V: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    risolvi := 42;
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    V     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
{$ifdef EVAL}
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
{$else}
    fr := input;
    fw := output;
{$endif}
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, V[i]);

    writeln(fw, risolvi(N, V));
    close(fr);
    close(fw);
end.
