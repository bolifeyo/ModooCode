----------------------------
title : VPCMPD, VPCMPUDs (Intel x86/64 assembly instruction)
cat_title : VPCMPD, VPCMPUD
ref_title : VPCMPD, VPCMPUD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPCMPD, VPCMPUD

**Compare Packed Integer Values into Mask**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F3A.W0 1F /r ib\newline{}VPCMPD k1 {k2}, xmm2, xmm3/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed doubleword integer values in xmm3/m128/m32bcst and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.256.66.0F3A.W0 1F /r ib\newline{}VPCMPD k1 {k2}, ymm2, ymm3/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed doubleword integer values in ymm3/m256/m32bcst and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.512.66.0F3A.W0 1F /r ib\newline{}VPCMPD k1 {k2}, zmm2, zmm3/m512/m32bcst, imm8|FV|V/V|AVX512F|Compare packed signed doubleword integer values in zmm2 and zmm3/m512/m32bcst using bits 2:0 of imm8 as a comparison predicate. The comparison results are written to the destination k1 under writemask k2.|
|EVEX.NDS.128.66.0F3A.W0 1E /r ib\newline{}VPCMPUD k1 {k2}, xmm2, xmm3/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed unsigned doubleword integer values in xmm3/m128/m32bcst and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.256.66.0F3A.W0 1E /r ib\newline{}VPCMPUD k1 {k2}, ymm2, ymm3/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed unsigned doubleword integer values in ymm3/m256/m32bcst and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.512.66.0F3A.W0 1E /r ib\newline{}VPCMPUD k1 {k2}, zmm2, zmm3/m512/m32bcst, imm8|FV|V/V|AVX512F|Compare packed unsigned doubleword integer values in zmm2 and zmm3/m512/m32bcst using bits 2:0 of imm8 as a comparison predicate. The comparison results are written to the destination k1 under writemask k2.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description


Performs a SIMD compare of the packed integer values in the second source operand and the first source operand and returns the results of the comparison to the mask destination operand. The comparison predicate operand (immediate byte) specifies the type of comparison performed on each pair of packed values in the two source oper-ands. The result of each comparison is a single mask bit result of 1 (comparison true) or 0 (comparison false).

VPCMPD/VPCMPUD performs a comparison between pairs of signed/unsigned doubleword integer values.

The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register or a 512/256/128-bit memory location or a 512-bit vector broadcasted from a 32-bit memory location. The destination operand (first operand) is a mask register k1. Up to 16/8/4 comparisons are performed with results written to the destination operand under the writemask k2.

The comparison predicate operand is an 8-bit immediate: bits 2:0 define the type of comparison to be performed. Bits 3 through 7 of the immediate are reserved. Compiler can implement the pseudo-op mnemonic listed in Table 5-10.


### Operation
#### VPCMPD (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k2[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN CMP <-  SRC1[i+31:i] OP SRC2[31:0];
                      ELSE CMP <-  SRC1[i+31:i] OP SRC2[i+31:i];
                FI;
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] <-  0 ; zeroing-masking onlyFI;
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### VPCMPUD (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k2[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN CMP <-  SRC1[i+31:i] OP SRC2[31:0];
                      ELSE CMP <-  SRC1[i+31:i] OP SRC2[i+31:i];
                FI;
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] <-  0 ; zeroing-masking onlyFI;
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPCMPD __mmask16 _mm512_cmp_epi32_mask( __m512i a, __m512i b, int imm);
VPCMPD __mmask16 _mm512_mask_cmp_epi32_mask(__mmask16 k, __m512i a, __m512i b, int imm);
VPCMPD __mmask16 _mm512_cmp[eq|ge|gt|le|lt|neq]_epi32_mask( __m512i a, __m512i b);
VPCMPD __mmask16 _mm512_mask_cmp[eq|ge|gt|le|lt|neq]_epi32_mask(__mmask16 k, __m512i a, __m512i b);
VPCMPUD __mmask16 _mm512_cmp_epu32_mask( __m512i a, __m512i b, int imm);
VPCMPUD __mmask16 _mm512_mask_cmp_epu32_mask(__mmask16 k, __m512i a, __m512i b, int imm);
VPCMPUD __mmask16 _mm512_cmp[eq|ge|gt|le|lt|neq]_epu32_mask( __m512i a, __m512i b);
VPCMPUD __mmask16 _mm512_mask_cmp[eq|ge|gt|le|lt|neq]_epu32_mask(__mmask16 k, __m512i a, __m512i b);
VPCMPD __mmask8 _mm256_cmp_epi32_mask( __m256i a, __m256i b, int imm);
VPCMPD __mmask8 _mm256_mask_cmp_epi32_mask(__mmask8 k, __m256i a, __m256i b, int imm);
VPCMPD __mmask8 _mm256_cmp[eq|ge|gt|le|lt|neq]_epi32_mask( __m256i a, __m256i b);
VPCMPD __mmask8 _mm256_mask_cmp[eq|ge|gt|le|lt|neq]_epi32_mask(__mmask8 k, __m256i a, __m256i b);
VPCMPUD __mmask8 _mm256_cmp_epu32_mask( __m256i a, __m256i b, int imm);
VPCMPUD __mmask8 _mm256_mask_cmp_epu32_mask(__mmask8 k, __m256i a, __m256i b, int imm);
VPCMPUD __mmask8 _mm256_cmp[eq|ge|gt|le|lt|neq]_epu32_mask( __m256i a, __m256i b);
VPCMPUD __mmask8 _mm256_mask_cmp[eq|ge|gt|le|lt|neq]_epu32_mask(__mmask8 k, __m256i a, __m256i b);
VPCMPD __mmask8 _mm_cmp_epi32_mask( __m128i a, __m128i b, int imm);
VPCMPD __mmask8 _mm_mask_cmp_epi32_mask(__mmask8 k, __m128i a, __m128i b, int imm);
VPCMPD __mmask8 _mm_cmp[eq|ge|gt|le|lt|neq]_epi32_mask( __m128i a, __m128i b);
VPCMPD __mmask8 _mm_mask_cmp[eq|ge|gt|le|lt|neq]_epi32_mask(__mmask8 k, __m128i a, __m128i b);
VPCMPUD __mmask8 _mm_cmp_epu32_mask( __m128i a, __m128i b, int imm);
VPCMPUD __mmask8 _mm_mask_cmp_epu32_mask(__mmask8 k, __m128i a, __m128i b, int imm);
VPCMPUD __mmask8 _mm_cmp[eq|ge|gt|le|lt|neq]_epu32_mask( __m128i a, __m128i b);
VPCMPUD __mmask8 _mm_mask_cmp[eq|ge|gt|le|lt|neq]_epu32_mask(__mmask8 k, __m128i a, __m128i b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E4.
