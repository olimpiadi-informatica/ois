uses math;

const
   MAXN = 100000;

function osserva(N: longint; var H: array of longint): longint;
var
   M, i, ic, r : longint;
   imax        : array[0..2] of longint;
begin
   M := H[0];
   for i:=1 to N-1 do
      M := max(M, H[i]);
   imax[0] := 0;
   imax[1] := 0;
   imax[2] := 0;
   ic := 1;
   r := 0;
   for i:=0 to N-1 do begin
      if (i = N-1) or (H[i] = M) then begin
         inc(ic);
         imax[ic mod 3] := i;
         r := max(r, imax[ic mod 3]-imax[(ic-2) mod 3]);
      end;
   end;
   osserva := r+1;
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

    writeln(fw, osserva(N, H));
    close(fr);
    close(fw);
end.
