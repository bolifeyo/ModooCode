----------------------------
title : INC (Intel x86/64 assembly instruction)
cat_title : INC
ref_title : INC
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/I
publish_date: 2020-09-01
----------------------------


#@ INC

**Increment by 1**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FE /0|INC r/m8|M|Valid|Valid|Increment r/m byte by 1.|
|REX + FE /0|INC r/m8\footnote{*}|M|Valid|N.E.|Increment r/m byte by 1.|
|FF /0|INC r/m16|M|Valid|Valid|Increment r/m word by 1.|
|FF /0|INC r/m32|M|Valid|Valid|Increment r/m doubleword by 1.|
|REX.W + FF /0|INC r/m64|M|Valid|N.E.|Increment r/m quadword by 1.|
|40+ rw\footnote{**}|INC r16|O|N.E.|Valid|Increment word register by 1.|
|40+ rd|INC r32|O|N.E.|Valid|Increment doubleword register by 1.|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.

\htmlonly{*}\htmlonly{*}40H through 47H are REX prefixes in 64-bit mode
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r, w)|NA|NA|NA|
|O|opcode + rd (r, w)|NA|NA|NA|
### Description


Adds 1 to the destination operand, while preserving the state of the CF flag. The destination operand can be a register or a memory location. This instruction allows a loop counter to be updated without disturbing the CF flag. (Use a `ADD` instruction with an immediate operand of 1 to perform an increment operation that does updates the CF flag.)

This instruction can be used with a `LOCK` prefix to allow the instruction to be executed atomically.

In 64-bit mode, `INC` r16 and `INC` r32 are not encodable (because opcodes 40H through 47H are REX prefixes). Otherwise, the instruction's 64-bit mode default operation size is 32 bits. Use of the REX.R prefix permits access to additional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits.


### Operation

```info-verb
DEST <- DEST + 1;
```
### AFlags Affected


The CF flag is not affected. The OF, SF, ZF, AF, and PF flags are set according to the result.


### Protected Mode Exceptions

#### #GP(0)
* If the destination operand is located in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULLsegment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.

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
* If the LOCK prefix is used but the destination is not a memory operand.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.