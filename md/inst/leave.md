----------------------------
title : LEAVE (Intel x86/64 assembly instruction)
cat_title : LEAVE
ref_title : LEAVE
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LEAVE

**High Level Procedure Exit**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|C9|`LEAVE` |NP|Valid|Valid|Set SP to BP, then pop BP.|
|C9|`LEAVE` |NP|N.E.|Valid|Set ESP to EBP, then pop EBP.|
|C9|`LEAVE` |NP|Valid|N.E.|Set RSP to RBP, then pop RBP.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Releases the stack frame set up by an earlier `ENTER` instruction. The `LEAVE` instruction copies the frame pointer (in the EBP register) into the stack pointer register (ESP), which releases the stack space allocated to the stack frame. The old frame pointer (the frame pointer for the calling procedure that was saved by the `ENTER` instruction) is then popped from the stack into the EBP register, restoring the calling procedure's stack frame. 

A `RET` instruction is commonly executed following a `LEAVE` instruction to return program control to the calling procedure.

See "Procedure Calls for Block-Structured Languages" in Chapter 7 of the Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 1, for detailed information on the use of the `ENTER` and `LEAVE` instructions.

In 64-bit mode, the instruction's default operation size is 64 bits; 32-bit operation cannot be encoded. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
IF StackAddressSize = 32
    THEN
          ESP <- EBP;
    ELSE IF StackAddressSize = 64
          THEN RSP <- RBP; FI;
    ELSE IF StackAddressSize = 16
          THEN SP <- BP; FI;
FI;
IF OperandSize = 32
    THEN EBP <- Pop();
    ELSE IF OperandSize = 64
          THEN RBP <- Pop(); FI;
    ELSE IF OperandSize = 16
          THEN BP <- Pop(); FI;
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #SS(0)
* If the EBP register points to a location that is not within the limits of the current stack segment.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If the EBP register points to a location outside of the effective address space from 0 to FFFFH.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If the EBP register points to a location outside of the effective address space from 0 to FFFFH.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
