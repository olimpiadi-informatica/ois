function mangia(N: longint; var direzione, dimensione: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    mangia := 42;
end;


const
    MAXN = 100000;
var
    N, i                  : longint;
    direzione, dimensione : array[0..MAXN-1] of longint;
    fr, fw                : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, direzione[i], dimensione[i]);

    writeln(fw, mangia(N, direzione, dimensione));
    close(fr);
    close(fw);
end.
