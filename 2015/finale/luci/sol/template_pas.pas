function spegni(N, M, K: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    spegni := 42;
end;


var
    N, M, K : longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M, K);
    
    writeln(fw, spegni(N, M, K));
    close(fr);
    close(fw);
end.
