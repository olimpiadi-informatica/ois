uses math;

type
    table = array [0..2,0..2] of char;

function vincente(var griglia: table): longint;
var count, i, j : longint;
begin
    vincente := 2;
    for i:=0 to 2 do begin
        if (griglia[i][0] = griglia[i][1]) and (griglia[i][1] = griglia[i][2]) then begin
            if griglia[i][0] = 'X' then vincente := 1
            else if griglia[i][0] = 'O' then vincente := 0;
        end;
        if (griglia[0][i] = griglia[1][i]) and (griglia[1][i] = griglia[2][i]) then begin
            if griglia[0][i] = 'X' then vincente := 1
            else if griglia[0][i] = 'O' then vincente := 0;
        end;
    end;
    if (griglia[0][0] = griglia[1][1]) and (griglia[1][1] = griglia[2][2]) then begin
        if griglia[0][0] = 'X' then vincente := 1
        else if griglia[0][0] = 'O' then vincente := 0;
    end;
    if (griglia[0][2] = griglia[1][1]) and (griglia[1][1] = griglia[2][0]) then begin
        if griglia[0][2] = 'X' then vincente := 1
        else if griglia[0][2] = 'O' then vincente := 0;
    end;
    count := 0;
    for i:=0 to 2 do for j:=0 to 2 do if (griglia[i][j] <> '.') then inc(count);
    if (count = 9) and (vincente = 2) then vincente := 0;
    if vincente = 2 then begin
	count := count mod 2;
        if count = 0 then vincente := 0 else vincente := 1;
        for i:=0 to 2 do for j:=0 to 2 do if (griglia[i][j] = '.') then begin
            if count = 0 then begin
                griglia[i][j] := 'X';
                vincente := max(vincente, vincente(griglia));
                griglia[i][j] := '.';
                if vincente = 1 then break;
            end else begin
                griglia[i][j] := 'O';
                vincente := min(vincente, vincente(griglia));
                griglia[i][j] := '.';
                if vincente = 0 then break;
            end;
        end;
    end;
end;


var
    griglia : table;
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
    readln(fr, griglia[0,0], griglia[0,1], griglia[0,2]);
    readln(fr, griglia[1,0], griglia[1,1], griglia[1,2]);
    readln(fr, griglia[2,0], griglia[2,1], griglia[2,2]);

    writeln(fw, vincente(griglia));
    close(fr);
    close(fw);
end.
