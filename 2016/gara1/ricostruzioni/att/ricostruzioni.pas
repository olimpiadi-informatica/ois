function spiana(N, K: longint; var A: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    spiana := 42;
end;


const
    MAXN = 100000;
var
    N, K, i : longint;
    A       : array[0..MAXN-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, A[i]);

    writeln(fw, spiana(N, K, A));
    close(fr);
    close(fw);
end.
