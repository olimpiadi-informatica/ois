procedure permuta(K: longint; var P: array of char);
begin
    (* Mettete qui il codice della soluzione *)
    P[0] := 'A';
    P[1] := 'S';
    P[2] := 'D';
end;


var
    K: longint;
    P: array[0..25] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, K);

    permuta(K, P);

    writeln(fw, P);
    close(fr);
    close(fw);
end.
