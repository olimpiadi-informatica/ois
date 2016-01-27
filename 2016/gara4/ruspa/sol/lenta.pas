const
    MAXN = 100000;
var
    N, T, X, D, i   : longint;
    M               : array[0..MAXN-1] of longint;
    fr, fw          : text;

procedure inizia(N: longint; var M: array of longint);
begin
end;

function abbatti(X, D: longint): longint;
var i: longint;
begin
    for i:=0 to N do
        if (i = N) or (M[i] > X) then
        begin
            if D = 0 then
            begin
                if N - i <= i then
                    abbatti := 0
                else
                    abbatti := 1
            end else begin
                if i <= N - i then
                    abbatti := 1
                else
                    abbatti := 0;
            end;
            exit;
        end;
end;


begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, T);
    for i:=0 to N-1 do
        read(fr, M[i]);
    readln(fr);

    inizia(N, M);
    for i:=0 to T-1 do begin
        if i > 0 then write(fw, ' ');
        readln(fr, X, D);
        write(fw, abbatti(X, D));
    end;
    writeln(fw);
    close(fr);
    close(fw);
end.
