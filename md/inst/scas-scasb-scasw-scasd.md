----------------------------
title : SCAS, SCASB, SCASW, SCASDs (Intel x86/64 assembly instruction)
cat_title : SCAS, SCASB, SCASW, SCASD
ref_title : SCAS, SCASB, SCASW, SCASD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SCAS, SCASB, SCASW, SCASD

**Scan String **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|AE|`SCAS` \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |NP|Valid |Valid|Compare AL with byte at ES:(E)DI or RDI, then set status flags.\htmlonly{*}|
|AF|`SCAS` \tooltip{m16}{DS:(E)SI, ES:(E)DI 로 표현되는 2 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |NP|Valid |Valid|Compare AX with word at ES:(E)DI or RDI, then set status flags.\htmlonly{*}|
|AF|`SCAS` \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} |NP|Valid |Valid|Compare EAX with doubleword at ES(E)DI or RDI then set status flags.\htmlonly{*}|
|REX.W + AF|`SCAS` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} |NP|Valid|N.E.|Compare RAX with quadword at RDI or EDI then set status flags.|
|AE|`SCASB` |NP|Valid |Valid|Compare AL with byte at ES:(E)DI or RDI then set status flags.\htmlonly{*}|
|AF|`SCASW` |NP|Valid |Valid|Compare AX with word at ES:(E)DI or RDI then set status flags.\htmlonly{*}|
|AF|`SCASD` |NP|Valid |Valid|Compare EAX with doubleword at ES:(E)DI or RDI then set status flags.\htmlonly{*}|
|REX.W + AF|SCASQ |NP|Valid |N.E.|Compare RAX with quadword at RDI or EDI then set status flags.|

```note
\htmlonly{*} In 64-bit mode, only 64-bit (RDI) and 32-bit (EDI) address sizes are supported. In non-64-bit mode, only 32-bit (EDI) and 16-bit (DI) address sizes are supported
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


In non-64-bit modes and in default 64-bit mode: this instruction compares a byte, word, doubleword or quadword specified using a memory operand with the value in AL, AX, or EAX. It then sets status flags in EFLAGS recording the results. The memory operand address is read from ES:(E)DI register (depending on the address-size attribute of the instruction and the current operational mode). Note that ES cannot be overridden with a segment override prefix.

At the assembly-code level, two forms of this instruction are allowed. The explicit-operand form and the no-oper-ands form. The explicit-operand form (specified using the `SCAS` mnemonic) allows a memory operand to be speci-fied explicitly. The memory operand must be a symbol that indicates the size and location of the operand value. The register operand is then automatically selected to match the size of the memory operand (AL register for byte comparisons, AX for word comparisons, EAX for doubleword comparisons). The explicit-operand form is provided to allow documentation. Note that the documentation provided by this form can be misleading. That is, the memory operand symbol must specify the correct type (size) of the operand (byte, word, or doubleword) but it does not have to specify the correct location. The location is always specified by ES:(E)DI.

The no-operands form of the instruction uses a short form of `SCAS`. Again, ES:(E)DI is assumed to be the memory operand and AL, AX, or EAX is assumed to be the register operand. The size of operands is selected by the mnemonic: `SCASB` (byte comparison), `SCASW` (word comparison), or `SCASD` (doubleword comparison).

After the comparison, the (E)DI register is incremented or decremented automatically according to the setting of the DF flag in the EFLAGS register. If the DF flag is 0, the (E)DI register is incremented; if the DF flag is 1, the (E)DI register is decremented. The register is incremented or decremented by 1 for byte operations, by 2 for word oper-ations, and by 4 for doubleword operations.

SCAS, `SCASB`, `SCASW`, `SCASD`, and SCASQ can be preceded by the `REP` prefix for block comparisons of ECX bytes, words, doublewords, or quadwords. Often, however, these instructions will be used in a `LOOP` construct that takes 



some action based on the setting of status flags. See "REP/REPE/REPZ /REPNE/REPNZ--Repeat String Operation Prefix" in this chapter for a description of the `REP` prefix.

In 64-bit mode, the instruction's default address size is 64-bits, 32-bit address size is supported using the prefix 67H. Using a REX prefix in the form of REX.W promotes operation on doubleword operand to 64 bits. The 64-bit no-operand mnemonic is SCASQ. Address of the memory operand is specified in either RDI or EDI, and AL/AX/EAX/RAX may be used as the register operand. After a comparison, the destination register is incremented or decremented by the current operand size (depending on the value of the DF flag). See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
Non-64-bit Mode:
IF (Byte comparison)
    THEN
          temp <- AL - SRC;
          SetStatusFlags(temp);
                THEN IF DF = 0 
                      THEN (E)DI <- (E)DI + 1; 
                      ELSE (E)DI <- (E)DI - 1; FI;
    ELSE IF (Word comparison)
          THEN
                temp <- AX - SRC;
                SetStatusFlags(temp);
                IF DF = 0
                      THEN (E)DI <- (E)DI + 2; 
                      ELSE (E)DI <- (E)DI - 2; FI;
          FI;
    ELSE IF (Doubleword comparison)
          THEN
                temp <- EAX - SRC;
                SetStatusFlags(temp);
                IF DF = 0
                      THEN (E)DI <- (E)DI + 4; 
                      ELSE (E)DI <- (E)DI - 4; FI;
          FI;
FI;
64-bit Mode:
IF (Byte cmparison)
    THEN
          temp <- AL - SRC;
          SetStatusFlags(temp);
                THEN IF DF = 0 
                      THEN (R|E)DI <- (R|E)DI + 1; 
                      ELSE (R|E)DI <- (R|E)DI - 1; FI;
    ELSE IF (Word comparison)
          THEN
                temp <- AX - SRC;
                SetStatusFlags(temp);
                IF DF = 0
                      THEN (R|E)DI <- (R|E)DI + 2; 
                      ELSE (R|E)DI <- (R|E)DI - 2; FI;
          FI;
ELSE IF (Doubleword comparison)
          THEN
                temp <- EAX - SRC;
                SetStatusFlags(temp);
                IF DF = 0
                      THEN (R|E)DI <- (R|E)DI + 4; 
                      ELSE (R|E)DI <- (R|E)DI - 4; FI;
          FI;
    ELSE IF (Quadword comparison using REX.W )
          THEN
                temp <- RAX - SRC;
                SetStatusFlags(temp);
                IF DF = 0
                      THEN (R|E)DI <- (R|E)DI + 8; 
                      ELSE (R|E)DI <- (R|E)DI - 8; 
                FI;
    FI;
F
```
### Flags Affected


The OF, SF, ZF, AF, PF, and CF flags are set according to the temporary result of the comparison.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the limit of the ES segment.
* If the ES register contains a NULL segment selector.
* If an illegal memory operand effective address in the ES segment is given.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
