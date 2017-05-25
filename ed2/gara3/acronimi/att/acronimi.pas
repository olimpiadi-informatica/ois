function acronimi(var A, S: string): longint;
var lunghezza: longint;
begin
    (* Per calcolare la lunghezza si puo' fare cosi' *)
    lunghezza := length(A);

    (* Mettete qui il codice della soluzione *)
    acronimi := 42;
end;


const
    MAXA = 100;
    MAXS = 100000;
var
    A : string;
    S : string;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, A);
    readln(fr, S);

    writeln(fw, acronimi(A, S));
    close(fr);
    close(fw);
end.
