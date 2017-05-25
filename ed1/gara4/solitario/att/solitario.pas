function gioca(N, M: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    gioca := 42;
end;


var
    N, M  : longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);

    writeln(fw, gioca(N, M));
    close(fr);
    close(fw);
end.
