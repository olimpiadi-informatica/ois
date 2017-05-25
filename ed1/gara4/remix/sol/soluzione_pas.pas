uses math;

function pah(var S: array of char; i: longint): boolean;
begin
    pah := (S[i] = 'P') and (S[i+1] = 'a') and (S[i+2] = 'H');
end;


function tunz(var S: array of char; i: longint): boolean;
begin
    tunz := (S[i] = 'T') and (S[i+1] = 'u') and (S[i+2] = 'N') and (S[i+3] = 'Z');
end;


procedure ripulisci(N: longint; var remix, testo: array of char);
var ir, it, lasti: longint;
begin
    ir := 0;
    lasti := 0;
    it := 0;
    while ir <= N do begin
        if pah(remix, ir) or tunz(remix, ir) then begin
            if (lasti < ir) then begin
                while lasti < ir do begin
                    testo[it] := remix[lasti];
                    inc(lasti);
                    inc(it);
                end;
                testo[it] := ' ';
                inc(it);
            end;
            if pah(remix, ir) then ir := ir + 3;
            if tunz(remix, ir) then ir := ir + 4;
            lasti := ir;
        end else inc(ir);
    end;
    if (lasti < ir) then begin
        while lasti < ir do begin
            testo[it] := remix[lasti];
            inc(lasti);
            inc(it);
        end;
        testo[it] := ' ';
        inc(it);
    end;
    testo[it-1] := remix[N];
end;


const
    MAXN = 100000;
var
    N               : longint;
    remix, testo    : array[0..MAXN] of char;
    fr, fw          : text;

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
    readln(fr, remix);
    ripulisci(N, remix, testo);
    writeln(fw, testo);
    close(fr);
    close(fw);
end.
