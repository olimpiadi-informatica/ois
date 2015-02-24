procedure bianchetta(N, K: longint; var U, C: array of longint);
var xc, bc, oc, nc, x : longint;
begin
    bc := 10;
    oc := 0;
    nc := 0;
    xc := -1;
    x := 0;
    while (nc < N-K) and (oc < 10) do begin
        if (x-nc > K) then begin
                C[nc] := bc;
                nc := nc + 1;
                if (U[x] < bc) then oc := 10
                else begin
                    oc := bc;
                    bc := 10;
                    x := xc;
                end;
            end
        else if (U[x] = oc) then begin
                C[nc] := oc;
                nc := nc + 1;
                if (U[nc+K] < oc) then oc := 10
                else bc := 10;
            end
        else if (U[x] < bc) then begin
                bc := U[x];
                xc := x;
            end;
        x := x + 1;
    end;
    for x := nc+K to N-1 do C[x-K] := U[x];
end;


const
    MAXN = 1000000;
var
    N, K, i: longint;
    U, C   : array[0..MAXN-1] of longint;
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
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, U[i]);

    bianchetta(N, K, U, C);
    for i:=0 to N-K-1 do
        write(fw, C[i], ' ');
    writeln(fw);
    close(fr);
    close(fw);
end.
