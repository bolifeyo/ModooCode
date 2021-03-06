----------------------------
title : RDFSBASE, RDGSBASEs (Intel x86/64 assembly instruction)
cat_title : RDFSBASE, RDGSBASE
ref_title : RDFSBASE, RDGSBASE
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RDFSBASE, RDGSBASE

**Read FS/GS Segment Base**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**||**Op/ **\newline{}**En**|**64/32-**\newline{}**bit **\newline{}**Mode**|**CPUID Fea-**\newline{}**ture Flag**|**Description**|
|------------------------------------||------------------------|----------------------------------------------|-------------------------------------|---------------|
|`F3 0F AE /0`\newline{}`RDFSBASE` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} ||M|V/I|FSGSBASE|Load the 32-bit destination register with the FS base address.|
|`F3 REX.W 0F AE /0`\newline{}`RDFSBASE` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} ||M|V/I|FSGSBASE|Load the 64-bit destination register with the FS base address.|
|`F3 0F AE /1`\newline{}`RDGSBASE` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} ||M|V/I|FSGSBASE|Load the 32-bit destination register with the GS base address.|
|`F3 REX.W 0F AE /1`\newline{}`RDGSBASE` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} ||M|V/I|FSGSBASE|Load the 64-bit destination register with the GS base address.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Loads the general-purpose register indicated by the modR/M:r/m field with the FS or GS segment base address.

The destination operand may be either a 32-bit or a 64-bit general-purpose register. The REX.W prefix indicates the operand size is 64 bits. If no REX.W prefix is used, the operand size is 32 bits; the upper 32 bits of the source base address (for FS or GS) are ignored and upper 32 bits of the destination register are cleared. 

This instruction is supported only in 64-bit mode.


### Operation

```info-verb
DEST <- FS/GS segment base address;
```
### Flags Affected


None

### C/C++ Compiler Intrinsic Equivalent


RDFSBASE: unsigned int _readfsbase_u32(void );

RDFSBASE:  unsigned __int64 _readfsbase_u64(void );

RDGSBASE:  unsigned int _readgsbase_u32(void );

RDGSBASE: unsigned __int64 _readgsbase_u64(void );


### Protected Mode Exceptions

#### #UD
* The RDFSBASE and RDGSBASE instructions are not recognized in protected mode.

### Real-Address Mode Exceptions

#### #UD
* The RDFSBASE and RDGSBASE instructions are not recognized in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The RDFSBASE and RDGSBASE instructions are not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions

#### #UD
* The RDFSBASE and RDGSBASE instructions are not recognized in compatibility mode.

### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If CR4.FSGSBASE[bit 16] = 0.
* If CPUID.07H.0H:EBX.FSGSBASE[bit 0] = 0.
