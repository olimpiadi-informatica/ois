const
    MAXN = 100000;

function test(N: longint; var H: array of longint): longint;
var R, mH : array[0..MAXN-1] of longint; { R = 0: sali (>=) 1: scendi (<) 2: rampa; mH = max height allowed }
    i : longint;
begin
    for i:=0 to N-2 do
        if (H[i+1] < H[i]) then R[i] := 1
        else R[i] := 0;
    for i:=0 to N-3 do
        if (H[i+1] > H[i]) and (H[i+1]-H[i] = H[i+2]-H[i+1]) then begin
            R[i] := 2;
            R[i+1] := 2;
        end;
    mH[0] := H[0];
    mH[1] := mH[0];
    for i:=1 to N-2 do begin
        mH[i+1] := mH[i];
        if (i<(N-1)) and (R[i-1] <> 1) and (R[i] <> R[i-1]) then mH[i+1] := H[i];
    end;
    test := N-1;
    for i:=0 to N-2 do
        if (R[i] = 0) and (H[i+1] >= mH[i+1]) then begin
            test := i;
            break;
        end;
end;


var
    N, i  : longint;
    H     : array[0..MAXN-1] of longint;
    fr, fw: text;

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
        read(fr, H[i]);

    writeln(fw, test(N, H));
    close(fr);
    close(fw);
end.
