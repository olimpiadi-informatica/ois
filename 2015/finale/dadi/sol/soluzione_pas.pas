uses math;

procedure simula(N: longint; var C: array of char; var R: array of longint);
var top, bottom, front, back, left, right, t, ic, ir : longint;
begin
    top     := 1;
    bottom  := 6;
    front   := 2;
    back    := 5;
    left    := 4;
    right   := 3;
    ir := 0;
    for ic := 0 to N-1 do begin
        if C[ic] = 'T' then begin
            R[ir] := top;
            inc(ir);
        end;
        if C[ic] = 'F' then begin
            R[ir] := front;
            inc(ir);
        end;
        if C[ic] = 'R' then begin
            R[ir] := right;
            inc(ir);
        end;
        if C[ic] = 'X' then begin
            t := top;
            top := back;
            back := bottom;
            bottom := front;
            front := t;
        end;
        if C[ic] = 'Y' then begin
            t := top;
            top := right;
            right := bottom;
            bottom := left;
            left := t;
        end;
        if C[ic] = 'Z' then begin
            t := front;
            front := left;
            left := back;
            back := right;
            right := t;
        end;
    end;
end;


const
    MAXN = 100000;
var
    N, i, j : longint;
    C       : array[0..MAXN] of char;
    R       : array[0..MAXN-1] of longint;
    fr, fw  : text;

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
    readln(fr, C);

    simula(N, C, R);
    j := 0;
    for i:=0 to N-1 do if (C[i] = 'T') or (C[i] = 'F') or (C[i] = 'R') then begin
        write(fw, R[j], ' ');
        inc(j);
    end;
    writeln(fw);
    close(fr);
    close(fw);
end.
