----------------------------
title : VPMOVQD, VPMOVSQD, VPMOVUSQDs (Intel x86/64 assembly instruction)
cat_title : VPMOVQD, VPMOVSQD, VPMOVUSQD
ref_title : VPMOVQD, VPMOVSQD, VPMOVUSQD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPMOVQD, VPMOVSQD, VPMOVUSQD

**Down Convert QWord to DWord**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.F3.0F38.W0 35 /r\newline{}VPMOVQD xmm1/m128 {k1}{z}, xmm2|A|V/V|AVX512VL\newline{}AVX512F|Converts 2 packed quad-word integers from xmm2 into 2 packed double-word integers in xmm1/m128 with truncation subject to writemask k1.|
|EVEX.128.F3.0F38.W0 25 /r\newline{}VPMOVSQD xmm1/m64 {k1}{z}, xmm2|A|V/V|AVX512VL\newline{}AVX512F|Converts 2 packed signed quad-word integers from xmm2 into 2 packed signed double-word integers in xmm1/m64 using signed saturation subject to writemask k1.|
|EVEX.128.F3.0F38.W0 15 /r\newline{}VPMOVUSQD xmm1/m64 {k1}{z}, xmm2|A|V/V|AVX512VL\newline{}AVX512F|Converts 2 packed unsigned quad-word integers from xmm2 into 2 packed unsigned double-word integers in xmm1/m64 using unsigned saturation subject to writemask k1.|
|EVEX.256.F3.0F38.W0 35 /r\newline{}VPMOVQD xmm1/m128 {k1}{z}, ymm2|A|V/V|AVX512VL\newline{}AVX512F|Converts 4 packed quad-word integers from ymm2 into 4 packed double-word integers in xmm1/m128 with truncation subject to writemask k1.|
|EVEX.256.F3.0F38.W0 25 /r\newline{}VPMOVSQD xmm1/m128 {k1}{z}, ymm2|A|V/V|AVX512VL\newline{}AVX512F|Converts 4 packed signed quad-word integers from ymm2 into 4 packed signed double-word integers in xmm1/m128 using signed saturation subject to writemask k1.|
|EVEX.256.F3.0F38.W0 15 /r\newline{}VPMOVUSQD xmm1/m128 {k1}{z}, ymm2|A|V/V|AVX512VL\newline{}AVX512F|Converts 4 packed unsigned quad-word integers from ymm2 into 4 packed unsigned double-word integers in xmm1/m128 using unsigned saturation subject to writemask k1.|
|EVEX.512.F3.0F38.W0 35 /r\newline{}VPMOVQD ymm1/m256 {k1}{z}, zmm2|HVM|V/V|AVX512F|Converts 8 packed quad-word integers from zmm2 into 8 packed double-word integers in ymm1/m256 with truncation subject to writemask k1.|
|EVEX.512.F3.0F38.W0 25 /r\newline{}VPMOVSQD ymm1/m256 {k1}{z}, zmm2|HVM|V/V|AVX512F|Converts 8 packed signed quad-word integers from zmm2 into 8 packed signed double-word integers in ymm1/m256 using signed saturation subject to writemask k1.|
|EVEX.512.F3.0F38.W0 15 /r\newline{}VPMOVUSQD ymm1/m256 {k1}{z}, zmm2|HVM|V/V|AVX512F|Converts 8 packed unsigned quad-word integers from zmm2 into 8 packed unsigned double-word integers in ymm1/m256 using unsigned saturation subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|HVM|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description 


VPMOVQW down converts 64-bit integer elements in the source operand (the second operand) into packed double-words using truncation. VPMOVSQW converts signed 64-bit integers into packed signed doublewords using signed saturation. VPMOVUSQW convert unsigned quad-word values into unsigned double-word values using unsigned saturation. 

The source operand is a ZMM/YMM/XMM register. The destination operand is a YMM/XMM/XMM register or a 256/128/64-bit memory location.

Down-converted doubleword elements are written to the destination operand (the first operand) from the least-significant doubleword. Doubleword elements of the destination operand are updated according to the writemask. Bits (MAX_VL-1:256/128/64) of the register destination are zeroed.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPMOVQD instruction (EVEX encoded version) reg-reg form
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 32
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+31:i] <-  TruncateQuadWordToDWord (SRC[m+63:m])
                ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+31:i] <-  0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/2] <-  0;
```
#### VPMOVQD instruction (EVEX encoded version) memory form
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 32
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+31:i] <-  TruncateQuadWordToDWord (SRC[m+63:m])
                ELSE *DEST[i+31:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```
#### VPMOVSQD instruction (EVEX encoded version) reg-reg form
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 32
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+31:i] <-  SaturateSignedQuadWordToDWord (SRC[m+63:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+31:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+31:i] <-  0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/2] <-  0;
```
#### VPMOVSQD instruction (EVEX encoded version) memory form
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 32
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+31:i] <-  SaturateSignedQuadWordToDWord (SRC[m+63:m])
                ELSE *DEST[i+31:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```
#### VPMOVUSQD instruction (EVEX encoded version) reg-reg form
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 32
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+31:i] <-  SaturateUnsignedQuadWordToDWord (SRC[m+63:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+31:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+31:i] <-  0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/2] <-  0;
```
#### VPMOVUSQD instruction (EVEX encoded version) memory form
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 32
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+31:i] <-  SaturateUnsignedQuadWordToDWord (SRC[m+63:m])
                ELSE *DEST[i+31:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPMOVQD __m256i _mm512_cvtepi64_epi32( __m512i a);
VPMOVQD __m256i _mm512_mask_cvtepi64_epi32(__m256i s, __mmask8 k, __m512i a);
VPMOVQD __m256i _mm512_maskz_cvtepi64_epi32( __mmask8 k, __m512i a);
VPMOVQD void _mm512_mask_cvtepi64_storeu_epi32(void * d, __mmask8 k, __m512i a);
VPMOVSQD __m256i _mm512_cvtsepi64_epi32( __m512i a);
VPMOVSQD __m256i _mm512_mask_cvtsepi64_epi32(__m256i s, __mmask8 k, __m512i a);
VPMOVSQD __m256i _mm512_maskz_cvtsepi64_epi32( __mmask8 k, __m512i a);
VPMOVSQD void _mm512_mask_cvtsepi64_storeu_epi32(void * d, __mmask8 k, __m512i a);
VPMOVUSQD __m256i _mm512_cvtusepi64_epi32( __m512i a);
VPMOVUSQD __m256i _mm512_mask_cvtusepi64_epi32(__m256i s, __mmask8 k, __m512i a);
VPMOVUSQD __m256i _mm512_maskz_cvtusepi64_epi32( __mmask8 k, __m512i a);
VPMOVUSQD void _mm512_mask_cvtusepi64_storeu_epi32(void * d, __mmask8 k, __m512i a);
VPMOVUSQD __m128i _mm256_cvtusepi64_epi32(__m256i a);
VPMOVUSQD __m128i _mm256_mask_cvtusepi64_epi32(__m128i a, __mmask8 k, __m256i b);
VPMOVUSQD __m128i _mm256_maskz_cvtusepi64_epi32( __mmask8 k, __m256i b);
VPMOVUSQD void _mm256_mask_cvtusepi64_storeu_epi32(void * , __mmask8 k, __m256i b);
VPMOVUSQD __m128i _mm_cvtusepi64_epi32(__m128i a);
VPMOVUSQD __m128i _mm_mask_cvtusepi64_epi32(__m128i a, __mmask8 k, __m128i b);
VPMOVUSQD __m128i _mm_maskz_cvtusepi64_epi32( __mmask8 k, __m128i b);
VPMOVUSQD void _mm_mask_cvtusepi64_storeu_epi32(void * , __mmask8 k, __m128i b);
VPMOVSQD __m128i _mm256_cvtsepi64_epi32(__m256i a);
VPMOVSQD __m128i _mm256_mask_cvtsepi64_epi32(__m128i a, __mmask8 k, __m256i b);
VPMOVSQD __m128i _mm256_maskz_cvtsepi64_epi32( __mmask8 k, __m256i b);
VPMOVSQD void _mm256_mask_cvtsepi64_storeu_epi32(void * , __mmask8 k, __m256i b);
VPMOVSQD __m128i _mm_cvtsepi64_epi32(__m128i a);
VPMOVSQD __m128i _mm_mask_cvtsepi64_epi32(__m128i a, __mmask8 k, __m128i b);
VPMOVSQD __m128i _mm_maskz_cvtsepi64_epi32( __mmask8 k, __m128i b);
VPMOVSQD void _mm_mask_cvtsepi64_storeu_epi32(void * , __mmask8 k, __m128i b);
VPMOVQD __m128i _mm256_cvtepi64_epi32(__m256i a);
VPMOVQD __m128i _mm256_mask_cvtepi64_epi32(__m128i a, __mmask8 k, __m256i b);
VPMOVQD __m128i _mm256_maskz_cvtepi64_epi32( __mmask8 k, __m256i b);
VPMOVQD void _mm256_mask_cvtepi64_storeu_epi32(void * , __mmask8 k, __m256i b);
VPMOVQD __m128i _mm_cvtepi64_epi32(__m128i a);
VPMOVQD __m128i _mm_mask_cvtepi64_epi32(__m128i a, __mmask8 k, __m128i b);
VPMOVQD __m128i _mm_maskz_cvtepi64_epi32( __mmask8 k, __m128i b);
VPMOVQD void _mm_mask_cvtepi64_storeu_epi32(void * , __mmask8 k, __m128i b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E6.

#UD  If EVEX.vvvv != 1111B.
