----------------------------
title : OUT (Intel x86/64 assembly instruction)
cat_title : OUT
ref_title : OUT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/O
publish_date: 2020-09-01
----------------------------


#@ OUT

**Output to Port**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|E6 ib|`OUT` \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} AL |I|Valid|Valid|Output byte in AL to I/O port address imm8.|
|E7 ib|`OUT` \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} AX |I|Valid|Valid|Output word in AX to I/O port address imm8. |
|E7 ib|`OUT` \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} EAX |I|Valid|Valid|Output doubleword in EAX to I/O port address imm8.|
|EE|`OUT` DX AL |NP|Valid|Valid|Output byte in AL to I/O port address in DX.|
|EF|`OUT` DX AX |NP|Valid|Valid|Output word in AX to I/O port address in DX.|
|EF|`OUT` DX EAX |NP|Valid|Valid|Output doubleword in EAX to I/O port address in DX.|

```note
\htmlonly{*} See IA-32 Architecture Compatibility section below
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|I|imm8|NA|NA|NA|
|NP|NA|NA|NA|NA|
### Description


Copies the value from the second operand (source operand) to the I/O port specified with the destination operand (first operand). The source operand can be register AL, AX, or EAX, depending on the size of the port being accessed (8, 16, or 32 bits, respectively); the destination operand can be a byte-immediate or the DX register. Using a byte immediate allows I/O port addresses 0 to 255 to be accessed; using the DX register as a source operand allows I/O ports from 0 to 65,535 to be accessed.

The size of the I/O port being accessed is determined by the opcode for an 8-bit I/O port or by the operand-size attribute of the instruction for a 16- or 32-bit I/O port.

At the machine code level, I/O instructions are shorter when accessing 8-bit I/O ports. Here, the upper eight bits of the port address will be 0.

This instruction is only useful for accessing I/O ports located in the processor's I/O address space. See Chapter 18, "Input/Output," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for more infor-mation on accessing I/O ports in the I/O address space.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### IA-32 Architecture Compatibility


After executing an OUT instruction, the Pentium\footnote{(R)}  processor ensures that the EWBE# pin has been sampled active before it begins to execute the next instruction. (Note that the instruction can be prefetched if EWBE# is not active, but it will not be executed until the EWBE# pin is sampled active.) Only the Pentium processor family has the EWBE# pin.


### Operation

```info-verb
IF ((PE = 1) and ((CPL > IOPL) or (VM = 1)))
    THEN (* Protected mode with CPL > IOPL or virtual-8086 mode *)
          IF (Any I/O Permission Bit for I/O port being accessed = 1)
                THEN (* I/O operation is not allowed *)
                      #GP(0);
                ELSE ( * I/O operation is allowed *) 
                      DEST <- SRC; (* Writes to selected I/O port *)
          FI;
    ELSE (Real Mode or Protected Mode with CPL <= IOPL *)
          DEST <- SRC; (* Writes to selected I/O port *)
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #GP(0)
* If the CPL is greater than (has less privilege) the I/O privilege level (IOPL) and any of the corresponding I/O permission bits in TSS for the I/O port being accessed is 1.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If any of the I/O permission bits in the TSS for the I/O port being accessed is 1.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same as protected mode exceptions.


### 64-Bit Mode Exceptions



Same as protected mode exceptions.

