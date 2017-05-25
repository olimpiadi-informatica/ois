uses math;

const
    MAXN = 100000;
var
    N, i                            : longint;
    direzione, dimensione, Dir, Dim : array[0..MAXN-1] of longint;
    fr, fw                          : text;




function mangia(N: longint; var direzione, dimensione: array of longint): longint;
var i, j: longint;
begin
    mangia := 0;
    for i:=0 to N-1 do begin
        if direzione[i] = 1 then begin
            while (mangia > 0) and (Dir[mangia-1] = 0) and (Dim[mangia-1] < dimensione[i]) do
                dec(mangia);
            if (mangia = 0) or (Dir[mangia-1] = 1) then begin
                Dir[mangia] := direzione[i];
                Dim[mangia] := dimensione[i];
                inc(mangia);
            end;
        end else begin
            Dir[mangia] := direzione[i];
            Dim[mangia] := dimensione[i];
            inc(mangia);
        end;
    end;
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
        readln(fr, direzione[i], dimensione[i]);

    writeln(fw, mangia(N, direzione, dimensione));
    close(fr);
    close(fw);
end.
