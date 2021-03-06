----------------------------
title : LGDT, LIDTs (Intel x86/64 assembly instruction)
cat_title : LGDT, LIDT
ref_title : LGDT, LIDT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LGDT, LIDT

**Load Global/Interrupt Descriptor Table Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 01 /2|`LGDT` \tooltip{m16&32}{메모리 데이터 쌍을 나타내며, & 왼쪽과 오른쪽에 메모리 데이터의 크기를 나타낸다. 예를 들어서 m16&32 는 16 비트 와 32비트 메모리 데이터 쌍을 의미한다. m16&16 과 m32&32 의 경우 BOUND 명령어에서 사용되는데, 배열 인덱스의 상한과 하한을 나타내기 위해서 사용된다. m16&32 와 m16&64 의 경우 LIDT 와 LGDT 명령어에서 사용되는데, 등록할 GDTR 과 IDTR 레지스터의 주소와 limit 필드 값을 로드하기 위해 사용된다.} |M|N.E.|Valid|Load m into GDTR.|
|0F 01 /3|`LIDT` \tooltip{m16&32}{메모리 데이터 쌍을 나타내며, & 왼쪽과 오른쪽에 메모리 데이터의 크기를 나타낸다. 예를 들어서 m16&32 는 16 비트 와 32비트 메모리 데이터 쌍을 의미한다. m16&16 과 m32&32 의 경우 BOUND 명령어에서 사용되는데, 배열 인덱스의 상한과 하한을 나타내기 위해서 사용된다. m16&32 와 m16&64 의 경우 LIDT 와 LGDT 명령어에서 사용되는데, 등록할 GDTR 과 IDTR 레지스터의 주소와 limit 필드 값을 로드하기 위해 사용된다.} |M|N.E.|Valid|Load m into IDTR.|
|0F 01 /2|`LGDT` \tooltip{m16&64}{To-m16&32} |M|Valid|N.E.|Load m into GDTR.|
|0F 01 /3|`LIDT` \tooltip{m16&64}{To-m16&32} |M|Valid|N.E.|Load m into IDTR.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Loads the values in the source operand into the global descriptor table register (GDTR) or the interrupt descriptor table register (IDTR). The source operand specifies a 6-byte memory location that contains the base address (a linear address) and the limit (size of table in bytes) of the global descriptor table (GDT) or the interrupt descriptor table (IDT). If operand-size attribute is 32 bits, a 16-bit limit (lower 2 bytes of the 6-byte data operand) and a 32-bit base address (upper 4 bytes of the data operand) are loaded into the register. If the operand-size attribute is 16 bits, a 16-bit limit (lower 2 bytes) and a 24-bit base address (third, fourth, and fifth byte) are loaded. Here, the high-order byte of the operand is not used and the high-order byte of the base address in the GDTR or IDTR is filled with zeros.

The `LGDT` and `LIDT` instructions are used only in operating-system software; they are not used in application programs. They are the only instructions that directly load a linear address (that is, not a segment-relative address) and a limit in protected mode. They are commonly executed in real-address mode to allow processor initialization prior to switching to protected mode.

In 64-bit mode, the instruction's operand size is fixed at 8+2 bytes (an 8-byte base and a 2-byte limit). See the summary chart at the beginning of this section for encoding data and limits.

See "SGDT--Store Global Descriptor Table Register" in Chapter 4, Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2B, for information on storing the contents of the GDTR and IDTR.


### Operation

```info-verb
IF Instruction is LIDT
    THEN
          IF OperandSize = 16
                THEN 
                      IDTR(Limit) <- SRC[0:15];
                      IDTR(Base) <- SRC[16:47] AND 00FFFFFFH; 
                ELSE IF 32-bit Operand Size
                      THEN
                            IDTR(Limit) <- SRC[0:15];
                            IDTR(Base) <- SRC[16:47]; 
                      FI;
                ELSE IF 64-bit Operand Size (* In 64-Bit Mode *)
                      THEN
                            IDTR(Limit) <- SRC[0:15];
                            IDTR(Base) <- SRC[16:79]; 
                      FI;
          FI;
    ELSE (* Instruction is LGDT *)
          IF OperandSize = 16
                THEN 
                      GDTR(Limit) <- SRC[0:15];
                      GDTR(Base) <- SRC[16:47] AND 00FFFFFFH; 
                ELSE IF 32-bit Operand Size
                      THEN
                            GDTR(Limit) <- SRC[0:15];
                            GDTR(Base) <- SRC[16:47]; 
                      FI;
                ELSE IF 64-bit Operand Size (* In 64-Bit Mode *)
                      THEN
                            GDTR(Limit) <- SRC[0:15];
                            GDTR(Base) <- SRC[16:79]; 
                      FI;
          FI; 
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #UD
* If source operand is not a memory location.
* If the LOCK prefix is used.

#### #GP(0)
* If the current privilege level is not 0.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

### Real-Address Mode Exceptions

#### #UD
* If source operand is not a memory location.
* If the LOCK prefix is used.

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

### Virtual-8086 Mode Exceptions

#### #UD
* If source operand is not a memory location.
* If the LOCK prefix is used.

#### #GP(0)
* The LGDT and LIDT instructions are not recognized in virtual-8086 mode.

#### #GP
* If the current privilege level is not 0.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the current privilege level is not 0.
* If the memory address is in a non-canonical form.

#### #UD
* If source operand is not a memory location.
* If the LOCK prefix is used.

#### #PF(fault-code)
* If a page fault occurs.
