uses math;

procedure append(var C, Gtilde: array of longint; var N: longint; x: longint);
begin
    dec(N);
    Gtilde[N] := x;
    dec(C[Gtilde[N]]);
end;

procedure permuta(N: longint; var G, Gtilde: array of longint);
var C   : array[0..10] of longint;
    LAST: array[0..24] of longint = (00,20,12,32,40,04,44,24,52,60,16,36,64,56,72,76,80,08,28,84,48,68,88,92,96);
    i   : longint;
begin
    for i:=0 to 10 do C[i] := 0;
    for i:=0 to N-1 do inc(C[G[i]]);
    append(C, Gtilde, N, 0);
    for i:=0 to 24 do if (C[LAST[i] mod 10] > 0) and (C[LAST[i] div 10] > 0) then
        if (((LAST[i] mod 10) <> (LAST[i] div 10)) or (C[LAST[i] mod 10] > 1)) then begin
        append(C, Gtilde, N, LAST[i] mod 10);
        append(C, Gtilde, N, LAST[i] div 10);
        break;
    end;
    i := 0;
    while i < 10 do
        if C[i] = 0 then inc(i) else append(C, Gtilde, N, i);
end;


const
    MAXN = 100000;
var
    N, i        : longint;
    G, Gtilde   : array[0..MAXN-1] of longint;
    fr, fw      : text;

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
        read(fr, G[i]);

    permuta(N, G, Gtilde);
    for i:=0 to N-1 do
        write(fw, Gtilde[i], ' ');
    writeln(fw);
    close(fr);
    close(fw);
end.
