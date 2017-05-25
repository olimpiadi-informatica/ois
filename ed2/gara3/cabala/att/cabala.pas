function occulta(N, M: longint): int64;
begin
    (* Mettete qui il codice della soluzione *)
    occulta := 42;
end;


var
    T, N, M, i : longint;
    fr, fw     : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, T);
    for i:=0 to T-1 do begin
        readln(fr, N, M);
        write(fw, occulta(N, M), ' ');
    end;

    writeln(fw);
    close(fr);
    close(fw);
end.
