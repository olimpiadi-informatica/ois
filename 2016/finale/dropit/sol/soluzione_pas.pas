function cadi(N: longint; var L, P: array of longint): longint;
var
    i: longint;
label
    continua_a_cadere;
begin
    cadi := 0;

    for i := 0 to N - 1 do
    begin
        continua_a_cadere:

        if cadi = 0 then
        begin
            P[cadi] := L[i];
            inc(cadi);
        end else if P[cadi - 1] > L[i] then
        begin
            P[cadi] := L[i];
            inc(cadi);
            P[cadi] := P[cadi - 2] - L[i];
            inc(cadi);
        end else if P[cadi - 1] = L[i] then
            dec(cadi)
        else
        begin
            dec(L[i], P[cadi - 1]);
            dec(cadi);
            goto continua_a_cadere;
        end;
    end;
end;


const
    MAXN = 100000;
    MAXM = 2*MAXN;
var
    N, M, i: longint;
    L      : array[0..MAXN-1] of longint;
    P      : array[0..MAXM-1] of longint;
    fr, fw : text;

begin
{$ifdef EVAL}
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
{$else}
    fr := input;
    fw := output;
{$endif}
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, L[i]);

    M := cadi(N, L, P);
    writeln(fw, M);
    for i:=0 to M-2 do
        write(fw, P[i], ' ');
    writeln(fw, P[M-1]);
    close(fr);
    close(fw);
end.
