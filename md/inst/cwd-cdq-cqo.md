----------------------------
title : CWD, CDQ, CQOs (Intel x86/64 assembly instruction)
cat_title : CWD, CDQ, CQO
ref_title : CWD, CDQ, CQO
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CWD, CDQ, CQO

**Convert Word to Doubleword/Convert Doubleword to Quadword**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|99|`CWD` |NP|Valid|Valid|DX:AX <- sign-extend of AX.|
|99|`CDQ` |NP|Valid|Valid|EDX:EAX <- sign-extend of EAX.|
|REX.W + 99|`CQO` |NP|Valid|N.E.|RDX:RAX<- sign-extend of RAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Doubles the size of the operand in register AX, EAX, or RAX (depending on the operand size) by means of sign extension and stores the result in registers DX:AX, EDX:EAX, or RDX:RAX, respectively. The `CWD` instruction copies the sign (bit 15) of the value in the AX register into every bit position in the DX register. The `CDQ` instruction copies the sign (bit 31) of the value in the EAX register into every bit position in the EDX register. The `CQO` instruc-tion (available in 64-bit mode only) copies the sign (bit 63) of the value in the RAX register into every bit position in the RDX register.

The `CWD` instruction can be used to produce a doubleword dividend from a word before word division. The `CDQ` instruction can be used to produce a quadword dividend from a doubleword before doubleword division. The `CQO` instruction can be used to produce a double quadword dividend from a quadword before a quadword division.

The `CWD` and `CDQ` mnemonics reference the same opcode. The `CWD` instruction is intended for use when the operand-size attribute is 16 and the `CDQ` instruction for when the operand-size attribute is 32. Some assemblers may force the operand size to 16 when `CWD` is used and to 32 when `CDQ` is used. Others may treat these mnemonics as synonyms (CWD/CDQ) and use the current setting of the operand-size attribute to determine the size of values to be converted, regardless of the mnemonic used.

In 64-bit mode, use of the REX.W prefix promotes operation to 64 bits. The `CQO` mnemonics reference the same opcode as CWD/CDQ. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
IF OperandSize = 16 (* CWD instruction *)
    THEN 
          DX <- SignExtend(AX);
    ELSE IF OperandSize = 32 (* CDQ instruction *)
          EDX <- SignExtend(EAX); FI;
    ELSE IF 64-Bit Mode and OperandSize = 64 (* CQO instruction*)
          RDX <- SignExtend(RAX); FI;
FI;
```
### Flags Affected


None

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

