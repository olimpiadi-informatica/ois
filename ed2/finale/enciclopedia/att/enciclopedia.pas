var
  fr, fw: text;

procedure volume(var S: ansistring);
begin
    writeln(fw, S);
end;

procedure rilega(N, K: longint; var parole: array of ansistring);
var a, b : ansistring;
begin
    (* Mettete qui il codice della soluzione *)
    a := 'QUA-RAN';
    b := 'TA-DUE';
    volume(a);
    volume(b);
end;


const
    MAXN = 10000;
var
    N, K, i : longint;
    parole  : array[0..MAXN-1] of ansistring;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, parole[i]);

    rilega(N, K, parole);

    close(fr);
    close(fw);
end.
