function gioca(X, Y, MX, MY, N: longint; var RX, RY, PX, PY: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    gioca := 42;
end;

const
    MAXN = 10000;
var
    X, Y, MX, MY, N, i: longint;
    RX, RY, PX, PY    : array[0..MAXN-1] of longint;
    fr, fw            : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, X, Y, MX, MY, N);
    for i:=0 to N-1 do
        readln(fr, RX[i], RY[i], PX[i], PY[i]);

    writeln(fw, gioca(X, Y, MX, MY, N, RX, RY, PX, PY));
    close(fr);
    close(fw);
end.
