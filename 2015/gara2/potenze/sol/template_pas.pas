function alloca(N: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    alloca := 42;
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
    writeln(fw, alloca(N));
    close(fr);
    close(fw);
end.
