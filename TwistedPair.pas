(*******************************************************
* 作者：伍耀晖              Author: YaoHui.Wu          *
* 开源日期：2022年6月7日    Open Source Date: 2022-6-7 *
* 国家：中国                Country: China             *
*******************************************************)
(* Compiled by free pascal. free pascal website: www.freepascal.org *)

Program TwistedPair;

Type
   TrinaryArray = Array[0..5] Of Byte;

Procedure Usage();
Begin
    Writeln('Usage'#10#9'Encryption: TwistedPair -e/-E Plaintext.file Ciphertext.file Password'#10#9'Decryption: TwistedPair -d/-D Ciphertext.file Plaintext.file Password');
End;

Procedure Ternary(wNumeric : Word;
                  Var baTrinary : TrinaryArray);
Var
    i : Byte;

Begin
    baTrinary[0] := 0;

    baTrinary[1] := 0;

    baTrinary[2] := 0;

    baTrinary[3] := 0;

    baTrinary[4] := 0;

    baTrinary[5] := 0;

    If wNumeric <> 0 Then
    Begin
        For i := 5 DownTo 0 Do
        Begin
            baTrinary[i] := wNumeric Mod 3;

            wNumeric := wNumeric Div 3;
        End;
    End;
End;

(*
 0 0 2
 1 1 1
 2 2 0
*)

Procedure TernaryXor0(Var baCiphertextOrPlaintext : TrinaryArray;
                      Var baPassword : TrinaryArray);
Var
    j : Byte;

Begin
    For j := 0 To 5 Do
    Begin
        If (baCiphertextOrPlaintext[j] = 0) And (baPassword[j] = 0) Then
        Begin
            baCiphertextOrPlaintext[j] := 0;
        End
        Else If (baCiphertextOrPlaintext[j] = 0) And (baPassword[j] = 1) Then
        Begin
            baCiphertextOrPlaintext[j] := 0;
        End
        Else If (baCiphertextOrPlaintext[j] = 0) And (baPassword[j] = 2) Then
        Begin
            baCiphertextOrPlaintext[j] := 2;
        End
        Else If (baCiphertextOrPlaintext[j] = 1) And (baPassword[j] = 0) Then
        Begin
            baCiphertextOrPlaintext[j] := 1;
        End
        Else If (baCiphertextOrPlaintext[j] = 1) And (baPassword[j] = 1) Then
        Begin
            baCiphertextOrPlaintext[j] := 1;
        End
        Else If (baCiphertextOrPlaintext[j] = 1) And (baPassword[j] = 2) Then
        Begin
            baCiphertextOrPlaintext[j] := 1;
        End
        Else If (baCiphertextOrPlaintext[j] = 2) And (baPassword[j] = 0) Then
        Begin
            baCiphertextOrPlaintext[j] := 2;
        End
        Else If (baCiphertextOrPlaintext[j] = 2) And (baPassword[j] = 1) Then
        Begin
            baCiphertextOrPlaintext[j] := 2;
        End
        Else If (baCiphertextOrPlaintext[j] = 2) And (baPassword[j] = 2) Then
        Begin
            baCiphertextOrPlaintext[j] := 0;
        End
    End;
End;

(*
 0 2 2
 1 1 1
 2 0 0
*)

Procedure TernaryXor2(Var baCiphertextOrPlaintext : TrinaryArray;
                      Var baPassword : TrinaryArray);
Var
    j : Byte;

Begin
    For j := 0 To 5 Do
    Begin
        If (baCiphertextOrPlaintext[j] = 0) And (baPassword[j] = 0) Then
        Begin
            baCiphertextOrPlaintext[j] := 0;
        End
        Else If (baCiphertextOrPlaintext[j] = 0) And (baPassword[j] = 1) Then
        Begin
            baCiphertextOrPlaintext[j] := 2;
        End
        Else If (baCiphertextOrPlaintext[j] = 0) And (baPassword[j] = 2) Then
        Begin
            baCiphertextOrPlaintext[j] := 2;
        End
        Else If (baCiphertextOrPlaintext[j] = 1) And (baPassword[j] = 0) Then
        Begin
            baCiphertextOrPlaintext[j] := 1;
        End
        Else If (baCiphertextOrPlaintext[j] = 1) And (baPassword[j] = 1) Then
        Begin
            baCiphertextOrPlaintext[j] := 1;
        End
        Else If (baCiphertextOrPlaintext[j] = 1) And (baPassword[j] = 2) Then
        Begin
            baCiphertextOrPlaintext[j] := 1;
        End
        Else If (baCiphertextOrPlaintext[j] = 2) And (baPassword[j] = 0) Then
        Begin
            baCiphertextOrPlaintext[j] := 2;
        End
        Else If (baCiphertextOrPlaintext[j] = 2) And (baPassword[j] = 1) Then
        Begin
            baCiphertextOrPlaintext[j] := 0;
        End
        Else If (baCiphertextOrPlaintext[j] = 2) And (baPassword[j] = 2) Then
        Begin
            baCiphertextOrPlaintext[j] := 0;
        End
    End;
End;

(*
 2 0 0
 1 1 1
 0 2 2
*)

Procedure TernaryXand0(Var baCiphertextOrPlaintext : TrinaryArray;
                       Var baPassword : TrinaryArray);
Var
    k : Byte;

Begin
    For k := 0 To 5 Do
    Begin
        If (baCiphertextOrPlaintext[k] = 0) And (baPassword[k] = 0) Then
        Begin
            baCiphertextOrPlaintext[k] := 2;
        End
        Else If (baCiphertextOrPlaintext[k] = 0) And (baPassword[k] = 1) Then
        Begin
            baCiphertextOrPlaintext[k] := 0;
        End
        Else If (baCiphertextOrPlaintext[k] = 0) And (baPassword[k] = 2) Then
        Begin
            baCiphertextOrPlaintext[k] := 0;
        End
        Else If (baCiphertextOrPlaintext[k] = 1) And (baPassword[k] = 0) Then
        Begin
            baCiphertextOrPlaintext[k] := 1;
        End
        Else If (baCiphertextOrPlaintext[k] = 1) And (baPassword[k] = 1) Then
        Begin
            baCiphertextOrPlaintext[k] := 1;
        End
        Else If (baCiphertextOrPlaintext[k] = 1) And (baPassword[k] = 2) Then
        Begin
            baCiphertextOrPlaintext[k] := 1;
        End
        Else If (baCiphertextOrPlaintext[k] = 2) And (baPassword[k] = 0) Then
        Begin
            baCiphertextOrPlaintext[k] := 0;
        End
        Else If (baCiphertextOrPlaintext[k] = 2) And (baPassword[k] = 1) Then
        Begin
            baCiphertextOrPlaintext[k] := 2;
        End
        Else If (baCiphertextOrPlaintext[k] = 2) And (baPassword[k] = 2) Then
        Begin
            baCiphertextOrPlaintext[k] := 2;
        End
    End;
End;

(*
 2 2 0
 1 1 1
 0 0 2
*)

Procedure TernaryXand2(Var baCiphertextOrPlaintext : TrinaryArray;
                       Var baPassword : TrinaryArray);
Var
    k : Byte;

Begin
    For k := 0 To 5 Do
    Begin
        If (baCiphertextOrPlaintext[k] = 0) And (baPassword[k] = 0) Then
        Begin
            baCiphertextOrPlaintext[k] := 2;
        End
        Else If (baCiphertextOrPlaintext[k] = 0) And (baPassword[k] = 1) Then
        Begin
            baCiphertextOrPlaintext[k] := 2;
        End
        Else If (baCiphertextOrPlaintext[k] = 0) And (baPassword[k] = 2) Then
        Begin
            baCiphertextOrPlaintext[k] := 0;
        End
        Else If (baCiphertextOrPlaintext[k] = 1) And (baPassword[k] = 0) Then
        Begin
            baCiphertextOrPlaintext[k] := 1;
        End
        Else If (baCiphertextOrPlaintext[k] = 1) And (baPassword[k] = 1) Then
        Begin
            baCiphertextOrPlaintext[k] := 1;
        End
        Else If (baCiphertextOrPlaintext[k] = 1) And (baPassword[k] = 2) Then
        Begin
            baCiphertextOrPlaintext[k] := 1;
        End
        Else If (baCiphertextOrPlaintext[k] = 2) And (baPassword[k] = 0) Then
        Begin
            baCiphertextOrPlaintext[k] := 0;
        End
        Else If (baCiphertextOrPlaintext[k] = 2) And (baPassword[k] = 1) Then
        Begin
            baCiphertextOrPlaintext[k] := 0;
        End
        Else If (baCiphertextOrPlaintext[k] = 2) And (baPassword[k] = 2) Then
        Begin
            baCiphertextOrPlaintext[k] := 2;
        End
    End;
End;

Var
    i, k, bPasswordLength : Byte;

    j, ulFileSize : QWord;

    baPassword : Array Of TrinaryArray;

    baPlaintextOrCiphertext : TrinaryArray;

    fdPlaintextOrCiphertext : File;

    bpPlaintext : PByte;

    wpCiphertext : PWord;

Begin
    If(ParamCount <> 4) Then
    Begin
        Usage();
    End
    Else If (ParamStr(1) = '-e') Or (ParamStr(1) = '-E') Then
    Begin
        Assign(fdPlaintextOrCiphertext, ParamStr(2));

        Reset(fdPlaintextOrCiphertext, 1);

        ulFileSize := FileSize(fdPlaintextOrCiphertext);

        If ulFileSize = 0 Then
        Begin
            WriteLn('There is no data in file [', ParamStr(2), '], 0 byte.');

            Halt(-1);
        End;

        bpPlaintext := GetMem(ulFileSize);

        BlockRead(fdPlaintextOrCiphertext, bpPlaintext^, ulFileSize);

        Close(fdPlaintextOrCiphertext);

        wpCiphertext := GetMem(2 * ulFileSize);

        bPasswordLength := Length(ParamStr(4));

        SetLength(baPassword, bPasswordLength);

        For i := 1 To bPasswordLength Do
        Begin
            Ternary(Ord(ParamStr(4)[i]), baPassword[i - 1]);
        End;

        k := 0;

        For j := 0 To ulFileSize - 1 Do
        Begin
            Ternary(bpPlaintext[j], baPlaintextOrCiphertext);

            TernaryXor0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor2(baPlaintextOrCiphertext, baPassword[k]);

            (*TernaryXor0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand2(baPlaintextOrCiphertext, baPassword[k]);*)

            wpCiphertext[j] := 243 * baPlaintextOrCiphertext[0] + 81 * baPlaintextOrCiphertext[1] + 27 * baPlaintextOrCiphertext[2] + 9 * baPlaintextOrCiphertext[3] + 3 * baPlaintextOrCiphertext[4] + baPlaintextOrCiphertext[5];

            k := (k + 1) Mod bPasswordLength;
        End;

        Assign(fdPlaintextOrCiphertext, Paramstr(3));

        Rewrite(fdPlaintextOrCiphertext, 1);

        BlockWrite(fdPlaintextOrCiphertext, wpCiphertext^, 2 * ulFileSize);

        Close(fdPlaintextOrCiphertext);

        FreeMem(wpCiphertext);

        FreeMem(bpPlaintext);
    End
    Else If (paramstr(1) = '-d') Or (paramstr(1) = '-D') Then
    Begin
        Assign(fdPlaintextOrCiphertext, ParamStr(2));

        Reset(fdPlaintextOrCiphertext, 1);

        ulFileSize := FileSize(fdPlaintextOrCiphertext);

        If ulFileSize = 0 Then
        Begin
            WriteLn('There is no data in file [', ParamStr(2), '], 0 byte.');

            Halt(-1);
        End;

        wpCiphertext := GetMem(ulFileSize);

        BlockRead(fdPlaintextOrCiphertext, wpCiphertext^, ulFileSize);

        Close(fdPlaintextOrCiphertext);

        ulFileSize := ulFileSize Div 2;

        bpPlaintext := GetMem(ulFileSize);

        bPasswordLength := Length(ParamStr(4));

        SetLength(baPassword, bPasswordLength);

        For i := 1 To bPasswordLength Do
        Begin
            Ternary(Ord(ParamStr(4)[i]), baPassword[i - 1]);
        End;

        k := 0;

        For j := 0 To ulFileSize - 1 Do
        Begin
            Ternary(wpCiphertext[j], baPlaintextOrCiphertext);

            TernaryXor2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor0(baPlaintextOrCiphertext, baPassword[k]);

            (*TernaryXand0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand0(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXor2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand2(baPlaintextOrCiphertext, baPassword[k]);

            TernaryXand0(baPlaintextOrCiphertext, baPassword[k]);*)

            bpPlaintext[j] := 243 * baPlaintextOrCiphertext[0] + 81 * baPlaintextOrCiphertext[1] + 27 * baPlaintextOrCiphertext[2] + 9 * baPlaintextOrCiphertext[3] + 3 * baPlaintextOrCiphertext[4] + baPlaintextOrCiphertext[5];

            k := (k + 1) Mod bPasswordLength;
        End;

        Assign(fdPlaintextOrCiphertext, Paramstr(3));

        Rewrite(fdPlaintextOrCiphertext, 1);

        BlockWrite(fdPlaintextOrCiphertext, bpPlaintext^, ulFileSize);

        Close(fdPlaintextOrCiphertext);

        FreeMem(bpPlaintext);

        FreeMem(wpCiphertext);
    End
    Else
    Begin
        Usage();
    End
End.
