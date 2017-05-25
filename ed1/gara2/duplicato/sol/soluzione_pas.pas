uses math;

(* FUNZIONI PRESE DAL WEB *)

Procedure QSort(var numbers : Array of longint;
                left : longint; right : longint);
Var pivot, l_ptr, r_ptr : longint;
Begin
 l_ptr := left;
 r_ptr := right;
 pivot := numbers[left];
 While (left < right) do
  Begin
   While ((numbers[right] >= pivot) AND (left < right)) do
    right := right - 1;
   If (left <> right) then
    Begin
     numbers[left] := numbers[right];
     left := left + 1;
    End;
   While ((numbers[left] <= pivot) AND (left < right)) do
    left := left + 1;
   If (left <> right) then
    Begin
     numbers[right] := numbers[left];
     right := right - 1;
    End;
  End;
 numbers[left] := pivot;
 pivot := left;
 left := l_ptr;
 right := r_ptr;
 If (left < pivot) then
  QSort(numbers, left, pivot-1);
 If (right > pivot) then
  QSort(numbers, pivot+1, right);
End;

Procedure QuickSort(var numbers : Array of longint; size : longint);
Begin
 QSort(numbers, 0, size-1);
End;

(* FINE FUNZIONI PRESE DAL WEB *)


function trova(N: longint; var P: array of longint): longint;
var i : longint;
begin
    QuickSort(P, 2*N-1);
    for i:=0 to N-1 do
        if (i = N-1) or (P[2*i] <> P[2*i+1]) then begin
            trova := P[2*i];
            break;
        end;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    P     : array[0..2*MAXN-2] of longint;
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
    for i:=0 to 2*N-2 do
        read(fr, P[i]);
    writeln(fw, trova(N, P));
    close(fr);
    close(fw);
end.
