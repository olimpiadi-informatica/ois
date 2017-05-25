uses math;

const
    MAXN = 10000;
    MAXB = 100000;
var
    N, i                  : longint;
    B, C, Dip, Idip, Ndip : array[0..MAXN-1] of longint;
    fr, fw                : text;


function valore(x: longint): longint;
var i: longint;
begin
    valore := 0;
    for i:=0 to Ndip[x]-1 do
        valore := valore + valore(Dip[Idip[x]+i]);
    valore := max(valore, B[x]);
end;

function recluta(N: longint; var B, C: array of longint): longint;
var i: longint;
begin
    for i:=1 to N-1 do
        inc(Ndip[C[i]]);
    for i:=1 to N-1 do begin
        Idip[i] := Idip[i-1] + Ndip[i-1];
        Ndip[i-1] := 0;
    end;
    Ndip[N-1] := 0;
    for i:=1 to N-1 do begin
        Dip[Idip[C[i]]+Ndip[C[i]]] := i;
        inc(Ndip[C[i]]);
    end;
    recluta := valore(0);
end;


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
        readln(fr, B[i], C[i]);

    writeln(fw, recluta(N, B, C));
    close(fr);
    close(fw);
end.
