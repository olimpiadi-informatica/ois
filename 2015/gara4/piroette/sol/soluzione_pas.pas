uses math;

procedure append(var C, Gtilde: array of longint; var N: longint; x: longint);
begin
    dec(N);
    Gtilde[N] := x;
    dec(C[Gtilde[N]]);
end;

procedure permuta(N: longint; var G, Gtilde: array of longint);
var C   : array[0..10] of longint;
    i   : longint;
begin
    for i:=0 to 10 do C[i] := 0;
    for i:=0 to N-1 do inc(C[G[i]]);
    append(C, Gtilde, N, 0);
    for i:=0 to 4 do if (C[2*i] > 0) then begin
        append(C, Gtilde, N, 2*i);
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
