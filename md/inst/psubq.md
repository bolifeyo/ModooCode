----------------------------
title : PSUBQ (Intel x86/64 assembly instruction)
cat_title : PSUBQ
ref_title : PSUBQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSUBQ

**Subtract Packed Quadword Integers **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F FB /r\footnote{1}\newline{}\newline{}PSUBQ mm1, mm2/m64|RM|V/V|SSE2|Subtract quadword integer in mm1 from mm2 /m64.|
|66 0F FB /r\newline{}\newline{}PSUBQ xmm1, xmm2/m128|RM|V/V|SSE2|Subtract packed quadword integers in xmm1 from xmm2 /m128.|
|VEX.NDS.128.66.0F.WIG FB/r\newline{}\newline{}VPSUBQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Subtract packed quadword integers in xmm3/m128 from xmm2.|
|VEX.NDS.256.66.0F.WIG FB /r\newline{}\newline{}VPSUBQ ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Subtract packed quadword integers in ymm3/m256 from ymm2.|
|EVEX.NDS.128.66.0F.W1 FB /r\newline{}VPSUBQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed quadword integers in xmm3/m128/m64bcst from xmm2 and store in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F.W1 FB /r\newline{}VPSUBQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed quadword integers in ymm3/m256/m64bcst from ymm2 and store in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F.W1 FB/r\newline{}VPSUBQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Subtract packed quadword integers in zmm3/m512/m64bcst from zmm2 and store in zmm1 using writemask k1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Subtracts the second operand (source operand) from the first operand (destination operand) and stores the result in the destination operand. When packed quadword operands are used, a SIMD subtract is performed. When a quadword result is too large to be represented in 64 bits (overflow), the result is wrapped around and the low 64 bits are written to the destination element (that is, the carry is ignored).

Note that the (V)PSUBQ instruction can operate on either unsigned or signed (two's complement notation) inte-gers; however, it does not set bits in the EFLAGS register to indicate overflow and/or a carry. To prevent undetected overflow conditions, software must control the ranges of the values upon which it operates.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version 64-bit operand: The source operand can be a quadword integer stored in an MMX technology register or a 64-bit memory location. 

128-bit Legacy SSE version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM desti-nation register remain unchanged.



VEX.128 encoded version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded versions: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed.

EVEX encoded VPSUBQ: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory loca-tion or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is conditionally updated with writemask k1.


### Operation
#### PSUBQ (with 64-Bit operands)
```info-verb
    DEST[63:0] <- DEST[63:0] - SRC[63:0];
```
#### PSUBQ (with 128-Bit operands)
```info-verb
    DEST[63:0] <- DEST[63:0] - SRC[63:0];
    DEST[127:64] <- DEST[127:64] - SRC[127:64];
```
#### VPSUBQ (VEX.128 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0]-SRC2[63:0]
DEST[127:64] <-  SRC1[127:64]-SRC2[127:64]
DEST[VLMAX-1:128] <-  0
```
#### VPSUBQ (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0]-SRC2[63:0]
DEST[127:64] <-  SRC1[127:64]-SRC2[127:64]
DEST[191:128] <-  SRC1[191:128]-SRC2[191:128]
DEST[255:192] <-  SRC1[255:192]-SRC2[255:192]
DEST[VLMAX-1:256] <-  0
```
#### VPSUBQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  SRC1[i+63:i] - SRC2[63:0]
                      ELSE DEST[i+63:i] <-  SRC1[i+63:i] - SRC2[i+63:i]
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPSUBQ __m512i _mm512_sub_epi64(__m512i a, __m512i b);
VPSUBQ __m512i _mm512_mask_sub_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPSUBQ __m512i _mm512_maskz_sub_epi64( __mmask8 k, __m512i a, __m512i b);
VPSUBQ __m256i _mm256_mask_sub_epi64(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPSUBQ __m256i _mm256_maskz_sub_epi64( __mmask8 k, __m256i a, __m256i b);
VPSUBQ __m128i _mm_mask_sub_epi64(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPSUBQ __m128i _mm_maskz_sub_epi64( __mmask8 k, __m128i a, __m128i b);
PSUBQ:__m64 _mm_sub_si64(__m64 m1, __m64 m2)
(V)PSUBQ:__m128i _mm_sub_epi64(__m128i m1, __m128i m2)
VPSUBQ:__m256i _mm256_sub_epi64(__m256i m1, __m256i m2)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPSUBQ, see Exceptions Type E4.
