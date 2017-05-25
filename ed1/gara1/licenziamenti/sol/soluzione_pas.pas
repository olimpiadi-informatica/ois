uses math;

const
    MAXN = 100000;
    MAXB = 1000000;
var
    N, i                  : longint;
    B, C, Dip, Idip, Ndip : array[0..MAXN-1] of longint;
    fr, fw                : text;


function controlla(x: longint; bmin: longint): longint;
var i: longint;
begin
    if B[x] > bmin then controlla := 1 else controlla := 0;
    bmin := min(bmin, B[x]);
    for i:=0 to Ndip[x]-1 do
        controlla := controlla + controlla(Dip[Idip[x]+i], bmin);
end;

function licenzia(N: longint; var B, C: array of longint): longint;
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
    licenzia := controlla(0, MAXB);
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

    writeln(fw, licenzia(N, B, C));
    close(fr);
    close(fw);
end.
