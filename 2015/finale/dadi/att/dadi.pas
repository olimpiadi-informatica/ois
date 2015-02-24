procedure simula(N: longint; var C: array of char; var R: array of longint);
begin
    (* Mettete qui il codice della soluzione *)
end;


const
    MAXN = 100000;
var
    N, i, j : longint;
    C       : array[0..MAXN] of char;
    R       : array[0..MAXN-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, C);

    simula(N, C, R);
    j := 0;
    for i:=0 to N-1 do if (C[i] = 'T') or (C[i] = 'F') or (C[i] = 'R') then begin
        write(fw, R[j], ' ');
        inc(j);
    end;
    writeln(fw);
    close(fr);
    close(fw);
end.
