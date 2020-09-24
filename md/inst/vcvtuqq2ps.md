----------------------------
title : VCVTUQQ2PS (Intel x86/64 assembly instruction)
cat_title : VCVTUQQ2PS
ref_title : VCVTUQQ2PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCVTUQQ2PS

**Convert Packed Unsigned Quadword Integers to Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.F2.0F.W1 7A /r\newline{}VCVTUQQ2PS xmm1 {k1}{z}, xmm2/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512DQ|Convert two packed unsigned quadword integers from xmm2/m128/m64bcst to packed single-precision floating-point values in zmm1 with writemask k1.|
|EVEX.256.F2.0F.W1 7A /r\newline{}VCVTUQQ2PS xmm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512DQ|Convert four packed unsigned quadword integers from ymm2/m256/m64bcst to packed single-precision floating-point values in xmm1 with writemask k1.|
|EVEX.512.F2.0F.W1 7A /r\newline{}VCVTUQQ2PS ymm1 {k1}{z}, zmm2/m512/m64bcst{er}|FV|V/V|AVX512DQ|Convert eight packed unsigned quadword integers from zmm2/m512/m64bcst to eight packed single-precision floating-point values in zmm1 with writemask k1.|
###                                                        Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

  FV ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts packed unsigned quadword integers in the source operand (second operand) to single-precision floating-point values in the destination operand (first operand). 

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operand is a YMM/XMM/XMM (low 64 bits) register conditionally updated with writemask k1. 

Note: EVEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### VCVTUQQ2PS (EVEX encoded version) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    k <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-
                Convert_UQuadInteger_To_Single_Precision_Floating_Point(SRC[k+63:k])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```
#### VCVTUQQ2PS (EVEX encoded version) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    k <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) 
                      THEN
                            DEST[i+31:i] <-
                Convert_UQuadInteger_To_Single_Precision_Floating_Point(SRC[63:0])
                      ELSE 
                            DEST[i+31:i] <-
                Convert_UQuadInteger_To_Single_Precision_Floating_Point(SRC[k+63:k])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTUQQ2PS __m256 _mm512_cvtepu64_ps( __m512i a);
VCVTUQQ2PS __m256 _mm512_mask_cvtepu64_ps( __m256 s, __mmask8 k, __m512i a);
VCVTUQQ2PS __m256 _mm512_maskz_cvtepu64_ps( __mmask8 k, __m512i a);
VCVTUQQ2PS __m256 _mm512_cvt_roundepu64_ps( __m512i a, int r);
VCVTUQQ2PS __m256 _mm512_mask_cvt_roundepu64_ps( __m256 s, __mmask8 k, __m512i a, int r);
VCVTUQQ2PS __m256 _mm512_maskz_cvt_roundepu64_ps( __mmask8 k, __m512i a, int r);
VCVTUQQ2PS __m128 _mm256_cvtepu64_ps( __m256i a);
VCVTUQQ2PS __m128 _mm256_mask_cvtepu64_ps( __m128 s, __mmask8 k, __m256i a);
VCVTUQQ2PS __m128 _mm256_maskz_cvtepu64_ps( __mmask8 k, __m256i a);
VCVTUQQ2PS __m128 _mm_cvtepu64_ps( __m128i a);
VCVTUQQ2PS __m128 _mm_mask_cvtepu64_ps( __m128 s, __mmask8 k, __m128i a);
VCVTUQQ2PS __m128 _mm_maskz_cvtepu64_ps( __mmask8 k, __m128i a);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E2.

#UD If EVEX.vvvv != 1111B.
