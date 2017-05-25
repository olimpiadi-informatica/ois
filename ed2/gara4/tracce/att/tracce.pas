function conteggio(K: longint; var S: ansistring): longint;
begin
    (* Se volete sapere la lunghezza di S, potete fare come al solito: *)
    (*   lunghezza := length(S)   *)

    (* Mettete qui il codice della soluzione *)
    conteggio := 42;
end;


var
    N : longint;
    S : ansistring;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, S);

    writeln(fw, conteggio(N, S));
    close(fr);
    close(fw);
end.
