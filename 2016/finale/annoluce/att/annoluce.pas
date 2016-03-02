const
    MAXN = 100000;

(* Dichiarate qui eventuali variabili globali *)

procedure mappatura(N: longint; var X, Y, Z: array of longint);
begin
    (* Mettete qui il codice della soluzione *)
end;

function query(D: longint) : longint;
begin
    (* Mettete qui il codice della soluzione *)
    query := 42;
end;


var
    N, Q, D, i : longint;
    X, Y, Z    : array[0..MAXN-1] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);

    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, X[i], Y[i], Z[i]);

    mappatura(N, X, Y, Z);

    readln(fr, Q);
    for i:=0 to Q-1 do
    begin
        readln(fr, D);
        writeln(fw, query(D));
    end;

    close(fr);
    close(fw);
end.
