----------------------------
title : MAXPS (Intel x86/64 assembly instruction)
cat_title : MAXPS
ref_title : MAXPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MAXPS

**Maximum of Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 5F /r\newline{}MAXPS xmm1, xmm2/m128|RM|V/V|SSE|Return the maximum single-precision floating-point values between xmm1 and xmm2/mem. |
|VEX.NDS.128.0F.WIG 5F /r\newline{}VMAXPS xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Return the maximum single-precision floating-point values between xmm2 and xmm3/mem. |
|VEX.NDS.256.0F.WIG 5F /r\newline{}VMAXPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Return the maximum single-precision floating-point values between ymm2 and ymm3/mem.|
|EVEX.NDS.128.0F.W0 5F /r\newline{}VMAXPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Return the maximum packed single-precision floating-point values between xmm2 and xmm3/m128/m32bcst and store result in xmm1 subject to writemask k1.|
|EVEX.NDS.256.0F.W0 5F /r\newline{}VMAXPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Return the maximum packed single-precision floating-point values between ymm2 and ymm3/m256/m32bcst and store result in ymm1 subject to writemask k1.|
|EVEX.NDS.512.0F.W0 5F /r\newline{}VMAXPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst{sae}|FV|V/V|AVX512F|Return the maximum packed single-precision floating-point values between zmm2 and zmm3/m512/m32bcst and store result in zmm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Performs a SIMD compare of the packed single-precision floating-point values in the first source operand and the second source operand and returns the maximum value for each pair of values to the destination operand. 

If the values being compared are both 0.0s (of either sign), the value in the second operand (source operand) is returned. If a value in the second operand is an SNaN, then SNaN is forwarded unchanged to the destination (that is, a QNaN version of the SNaN is not returned). 

If only one value is a NaN (SNaN or QNaN) for this instruction, the second operand (source operand), either a NaN or a valid floating-point value, is written to the result. If instead of this behavior, it is required that the NaN source operand (from either the first or second operand) be returned, the action of `MAXPS` can be emulated using a sequence of instructions, such as, a comparison followed by `AND`, `ANDN` and `OR`. 

EVEX encoded versions: The first source operand (the second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register destination are zeroed.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are unmodified.


### Operation
#### VMAXPS (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+31:i] <-  MAX(SRC1[i+31:i], SRC2[31:0])
                      ELSE 
                            DEST[i+31:i] <-  MAX(SRC1[i+31:i], SRC2[i+31:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  DEST[i+31:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMAXPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <- MAX(SRC1[31:0], SRC2[31:0])
DEST[63:32] <- MAX(SRC1[63:32], SRC2[63:32])
DEST[95:64] <- MAX(SRC1[95:64], SRC2[95:64])
DEST[127:96] <- MAX(SRC1[127:96], SRC2[127:96])
DEST[159:128] <- MAX(SRC1[159:128], SRC2[159:128])
DEST[191:160] <- MAX(SRC1[191:160], SRC2[191:160])
DEST[223:192] <- MAX(SRC1[223:192], SRC2[223:192])
DEST[255:224] <- MAX(SRC1[255:224], SRC2[255:224])
DEST[MAX_VL-1:256] <- 0
```
#### VMAXPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- MAX(SRC1[31:0], SRC2[31:0])
DEST[63:32] <- MAX(SRC1[63:32], SRC2[63:32])
DEST[95:64] <- MAX(SRC1[95:64], SRC2[95:64])
DEST[127:96] <- MAX(SRC1[127:96], SRC2[127:96])
DEST[MAX_VL-1:128] <- 0
```
#### MAXPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- MAX(DEST[31:0], SRC[31:0])
DEST[63:32] <- MAX(DEST[63:32], SRC[63:32])
DEST[95:64] <- MAX(DEST[95:64], SRC[95:64])
DEST[127:96] <- MAX(DEST[127:96], SRC[127:96])
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMAXPS __m512 _mm512_max_ps( __m512 a, __m512 b);
VMAXPS __m512 _mm512_mask_max_ps(__m512 s, __mmask16 k, __m512 a, __m512 b);
VMAXPS __m512 _mm512_maskz_max_ps( __mmask16 k, __m512 a, __m512 b);
VMAXPS __m512 _mm512_max_round_ps( __m512 a, __m512 b, int);
VMAXPS __m512 _mm512_mask_max_round_ps(__m512 s, __mmask16 k, __m512 a, __m512 b, int);
VMAXPS __m512 _mm512_maskz_max_round_ps( __mmask16 k, __m512 a, __m512 b, int);
VMAXPS __m256 _mm256_mask_max_ps(__m256 s, __mmask8 k, __m256 a, __m256 b);
VMAXPS __m256 _mm256_maskz_max_ps( __mmask8 k, __m256 a, __m256 b);
VMAXPS __m128 _mm_mask_max_ps(__m128 s, __mmask8 k, __m128 a, __m128 b);
VMAXPS __m128 _mm_maskz_max_ps( __mmask8 k, __m128 a, __m128 b);
VMAXPS __m256 _mm256_max_ps (__m256 a, __m256 b);
MAXPS __m128 _mm_max_ps (__m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


Invalid (including QNaN Source Operand), Denormal

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 2.

EVEX-encoded instruction, see Exceptions Type E2.
