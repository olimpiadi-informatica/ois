function afaikdiyrotfl(N: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    afaikdiyrotfl := 42;
end;


var
    N     : longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);

    writeln(fw, afaikdiyrotfl(N));
    close(fr);
    close(fw);
end.
