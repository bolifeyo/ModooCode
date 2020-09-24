----------------------------
title : VPBLENDD (Intel x86/64 assembly instruction)
cat_title : VPBLENDD
ref_title : VPBLENDD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPBLENDD

** Blend Packed Dwords**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.128.66.0F3A.W0 02 /r ib\newline{}VPBLENDD xmm1, xmm2, xmm3/m128, imm8|RVMI|V/V|AVX2|Select dwords from xmm2 and xmm3/m128 from mask specified in imm8 and store the values into xmm1.|
|VEX.NDS.256.66.0F3A.W0 02 /r ib\newline{}VPBLENDD ymm1, ymm2, ymm3/m256, imm8|RVMI|V/V|AVX2|Select dwords from ymm2 and ymm3/m256 from mask specified in imm8 and store the values into ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Dword elements from the source operand (second operand) are conditionally written to the destination operand (first operand) depending on bits in the immediate operand (third operand). The immediate bits (bits 7:0) form a mask that determines whether the corresponding word in the destination is copied from the source. If a bit in the mask, corresponding to a word, is "1", then the word is copied, else the word is unchanged.

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### VPBLENDD (VEX.256 encoded version)
```info-verb
IF (imm8[0] == 1) THEN DEST[31:0] <-  SRC2[31:0]
ELSE DEST[31:0] <-  SRC1[31:0]
IF (imm8[1] == 1) THEN DEST[63:32] <-  SRC2[63:32]
ELSE DEST[63:32] <-  SRC1[63:32]
IF (imm8[2] == 1) THEN DEST[95:64] <-  SRC2[95:64]
ELSE DEST[95:64] <-  SRC1[95:64]
IF (imm8[3] == 1) THEN DEST[127:96] <-  SRC2[127:96]
ELSE DEST[127:96] <-  SRC1[127:96]
IF (imm8[4] == 1) THEN DEST[159:128] <-  SRC2[159:128]
ELSE DEST[159:128] <-  SRC1[159:128]
IF (imm8[5] == 1) THEN DEST[191:160] <-  SRC2[191:160]
ELSE DEST[191:160] <-  SRC1[191:160]
IF (imm8[6] == 1) THEN DEST[223:192] <-  SRC2[223:192]
ELSE DEST[223:192] <-  SRC1[223:192]
IF (imm8[7] == 1) THEN DEST[255:224] <-  SRC2[255:224]
ELSE DEST[255:224] <-  SRC1[255:224]
```
#### VPBLENDD (VEX.128 encoded version)
```info-verb
IF (imm8[0] == 1) THEN DEST[31:0] <-  SRC2[31:0]
ELSE DEST[31:0] <-  SRC1[31:0]
IF (imm8[1] == 1) THEN DEST[63:32] <-  SRC2[63:32]
ELSE DEST[63:32] <-  SRC1[63:32]
IF (imm8[2] == 1) THEN DEST[95:64] <-  SRC2[95:64]
ELSE DEST[95:64] <-  SRC1[95:64]
IF (imm8[3] == 1) THEN DEST[127:96] <-  SRC2[127:96]
ELSE DEST[127:96] <-  SRC1[127:96]
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPBLENDD: __m128i _mm_blend_epi32 (__m128i v1, __m128i v2, const int mask)
VPBLENDD: __m256i _mm256_blend_epi32 (__m256i v1, __m256i v2, const int mask)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.W = 1.
