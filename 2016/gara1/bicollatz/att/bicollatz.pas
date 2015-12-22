function bicollatz(A, B: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    bicollatz := 42;
end;


var
    A, B  : longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, A, B);

    writeln(fw, bicollatz(A, B));
    close(fr);
    close(fw);
end.
