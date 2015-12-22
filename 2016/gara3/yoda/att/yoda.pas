procedure yodizza(var S: string; var Y: array of char);
var lunghezza, i: longint;
begin
    (* Per calcolare la lunghezza si puo' fare cosi' *)
    lunghezza := length(S);

    (* Mettete qui il codice della soluzione *)
    for i:=0 to lunghezza - 1 do
        Y[i] := S[i + 1];  (* ATTENZIONE: le due stringhe sono indicizzate diversamente:  *)
                           (*             S parte da 1 mentre Y parte da 0. Viva Pascal!  *)
end;


const
    MAXS = 100000;
var
    N     : longint;
    S     : string;
    Y     : array[0..MAXS+10] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, S);

    yodizza(S, Y);

    writeln(fw, Y);
    close(fr);
    close(fw);
end.
