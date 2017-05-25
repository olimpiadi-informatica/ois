const
    MAXN = 1000;
type
    matrix = array[0..MAXN-1] of array[0..MAXN-1] of longint;

(* Mettete qui le eventuali variabili globali *)

function cammina(N, M: longint; var V: matrix): longint;
begin
    (* Mettete qui il codice della soluzione *)
    cammina := 42;
end;


var
    N, M, i, j : longint;
    griglia    : array[0..MAXN-1] of array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        for j:=0 to M-1 do
            read(fr, griglia[i, j]);

    writeln(fw, cammina(N, M, griglia));
    close(fr);
    close(fw);
end.
