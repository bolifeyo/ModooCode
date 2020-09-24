----------------------------
title : LAR (Intel x86/64 assembly instruction)
cat_title : LAR
ref_title : LAR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LAR

**Load Access Rights Byte**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 02 /r|LAR r16, r16/m16|RM|Valid|Valid|r16 <- access rights referenced by r16/m16|
|0F 02 /r|LAR reg, r32/m16\footnote{1}|RM|Valid|Valid|reg <- access rights referenced by r32/m16|

```note
1. For all loads (regardless of source or destination sizing) only bits 16-0 are used. Other bits are ignored
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Loads the access rights from the segment descriptor specified by the second operand (source operand) into the first operand (destination operand) and sets the ZF flag in the flag register. The source operand (which can be a register or a memory location) contains the segment selector for the segment descriptor being accessed. If the source operand is a memory address, only 16 bits of data are accessed. The destination operand is a general-purpose register.

The processor performs access checks as part of the loading process. Once loaded in the destination register, soft-ware can perform additional checks on the access rights information. 

The access rights for a segment descriptor include fields located in the second doubleword (bytes 4-7) of the segment descriptor. The following fields are loaded by the `LAR` instruction:

*  Bits 7:0 are returned as 0

*  Bits 11:8 return the segment type.

*  Bit 12 returns the S flag.

*  Bits 14:13 return the DPL.

*  Bit 15 returns the P flag.

*  The following fields are returned only if the operand size is greater than 16 bits:

     -- Bits 19:16 are undefined.

     -- Bit 20 returns the software-available bit in the descriptor.

     -- Bit 21 returns the L flag.

     -- Bit 22 returns the D/B flag.

     -- Bit 23 returns the G flag.

     -- Bits 31:24 are returned as 0.

This instruction performs the following checks before it loads the access rights in the destination register: 

*  Checks that the segment selector is not NULL.

*  Checks that the segment selector points to a descriptor that is within the limits of the GDT or LDT being accessed

*  Checks that the descriptor type is valid for this instruction. All code and data segment descriptors are valid for (can be accessed with) the `LAR` instruction. The valid system segment and gate descriptor types are given in Table 3-52. 

*  If the segment is not a conforming code segment, it checks that the specified segment descriptor is visible at the CPL (that is, if the CPL and the RPL of the segment selector are less than or equal to the DPL of the segment selector).

If the segment descriptor cannot be accessed or is an invalid type for the instruction, the ZF flag is cleared and no access rights are loaded in the destination operand.



The `LAR` instruction can only be executed in protected mode and IA-32e mode.

### Table 3-52.  Segment and Gate Types


|**Type**|**Protected Mode**||**IA-32e Mode**||
|--------|------------------||---------------||
||**Name**|**Valid**|**Name**|**Valid**|
|0\newline{}1\newline{}2\newline{}3\newline{}4\newline{}5\newline{}6\newline{}7\newline{}8\newline{}9\newline{}A\newline{}B\newline{}C\newline{}D\newline{}E\newline{}F|Reserved\newline{}Available 16-bit TSS\newline{}LDT\newline{}Busy 16-bit TSS\newline{}16-bit call gate\newline{}16-bit/32-bit task gate\newline{}16-bit interrupt gate\newline{}16-bit trap gate\newline{}Reserved\newline{}Available 32-bit TSS\newline{}Reserved\newline{}Busy 32-bit TSS\newline{}32-bit call gate\newline{}Reserved\newline{}32-bit interrupt gate\newline{}32-bit trap gate|No\newline{}Yes\newline{}Yes\newline{}Yes\newline{}Yes\newline{}Yes\newline{}No\newline{}No\newline{}No\newline{}Yes\newline{}No\newline{}Yes\newline{}Yes\newline{}No\newline{}No\newline{}No|Reserved\newline{}Reserved\newline{}LDT\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Available 64-bit TSS\newline{}Reserved\newline{}Busy 64-bit TSS\newline{}64-bit call gate\newline{}Reserved\newline{}64-bit interrupt gate\newline{}64-bit trap gate|No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}Yes\newline{}No\newline{}Yes\newline{}Yes\newline{}No\newline{}No\newline{}No|

### Operation

```info-verb
IF Offset(SRC) > descriptor table limit
    THEN 
          ZF <- 0; 
    ELSE
          SegmentDescriptor <- descriptor referenced by SRC;
          IF SegmentDescriptor(Type) != conforming code segment
          and (CPL > DPL) or (RPL > DPL)
          or SegmentDescriptor(Type) is not valid for instruction
                THEN
                      ZF <- 0;
                ELSE
                      DEST <- access rights from SegmentDescriptor as given in Description section;
                      ZF <- 1;
          FI;
FI;
```
### Flags Affected


The ZF flag is set to 1 if the access rights are loaded successfully; otherwise, it is cleared to 0.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and the memory operand effective address is unaligned while the current privilege level is 3. 

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* The LAR instruction is not recognized in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The LAR instruction cannot be executed in virtual-8086 mode.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If the memory operand effective address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory operand effective address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and the memory operand effective address is unaligned while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.