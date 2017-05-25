function falsifica(N: longint; var Q: array of char; var A: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    falsifica := 42;
end;


const
    MAXN = 1000000;
var
    N, i  : longint;
    Q     : array[0..MAXN-1] of char;
    A     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    Q[0] := 'X';
    A[0] := -1;
    for i:=1 to N-1 do
        readln(fr, Q[i], A[i]);

    writeln(fw, falsifica(N, Q, A));
    close(fr);
    close(fw);
end.
