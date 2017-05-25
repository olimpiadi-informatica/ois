function scosse(N: longint): double;
begin
    (* Mettete qui il codice della soluzione *)
    scosse := 42;
end;


var
    N, i  : longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);

    writeln(fw, scosse(N));
    close(fr);
    close(fw);
end.