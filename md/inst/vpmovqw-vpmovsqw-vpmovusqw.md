----------------------------
title : VPMOVQW, VPMOVSQW, VPMOVUSQWs (Intel x86/64 assembly instruction)
cat_title : VPMOVQW, VPMOVSQW, VPMOVUSQW
ref_title : VPMOVQW, VPMOVSQW, VPMOVUSQW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPMOVQW, VPMOVSQW, VPMOVUSQW

**Down Convert QWord to Word**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.128.F3.0F38.W0 34 /r`\newline{}`VPMOVQW` \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |QVM|V/V|AVX512VL\newline{}AVX512F|Converts 2 packed quad-word integers from xmm2 into 2 packed word integers in xmm1/m32 with truncation under writemask k1.|
|`EVEX.128.F3.0F38.W0 24 /r`\newline{}`VPMOVSQW` \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |QVM|V/V|AVX512VL\newline{}AVX512F|Converts 8 packed signed quad-word integers from zmm2 into 8 packed signed word integers in xmm1/m32 using signed saturation under writemask k1.|
|`EVEX.128.F3.0F38.W0 14 /r`\newline{}`VPMOVUSQW` \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |QVM|V/V|AVX512VL\newline{}AVX512F|Converts 2 packed unsigned quad-word integers from xmm2 into 2 packed unsigned word integers in xmm1/m32 using unsigned saturation under writemask k1.|
|`EVEX.256.F3.0F38.W0 34 /r`\newline{}`VPMOVQW` \tooltip{xmm1/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |QVM|V/V|AVX512VL\newline{}AVX512F|Converts 4 packed quad-word integers from ymm2 into 4 packed word integers in xmm1/m64 with truncation under writemask k1.|
|`EVEX.256.F3.0F38.W0 24 /r`\newline{}`VPMOVSQW` \tooltip{xmm1/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |QVM|V/V|AVX512VL\newline{}AVX512F|Converts 4 packed signed quad-word integers from ymm2 into 4 packed signed word integers in xmm1/m64 using signed saturation under writemask k1.|
|`EVEX.256.F3.0F38.W0 14 /r`\newline{}`VPMOVUSQW` \tooltip{xmm1/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |QVM|V/V|AVX512VL\newline{}AVX512F|Converts 4 packed unsigned quad-word integers from ymm2 into 4 packed unsigned word integers in xmm1/m64 using unsigned saturation under writemask k1.|
|`EVEX.512.F3.0F38.W0 34 /r`\newline{}`VPMOVQW` \tooltip{xmm1/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 |QVM|V/V|AVX512F|Converts 8 packed quad-word integers from zmm2 into 8 packed word integers in xmm1/m128 with truncation under writemask k1.|
|`EVEX.512.F3.0F38.W0 24 /r`\newline{}`VPMOVSQW` \tooltip{xmm1/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 |QVM|V/V|AVX512F|Converts 8 packed signed quad-word integers from zmm2 into 8 packed signed word integers in xmm1/m128 using signed saturation under writemask k1.|
|`EVEX.512.F3.0F38.W0 14 /r`\newline{}`VPMOVUSQW` \tooltip{xmm1/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 |QVM|V/V|AVX512F|Converts 8 packed unsigned quad-word integers from zmm2 into 8 packed unsigned word integers in xmm1/m128 using unsigned saturation under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|QVM|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description 


VPMOVQW down converts 64-bit integer elements in the source operand (the second operand) into packed words using truncation. VPMOVSQW converts signed 64-bit integers into packed signed words using signed saturation. VPMOVUSQW convert unsigned quad-word values into unsigned word values using unsigned saturation. 

The source operand is a ZMM/YMM/XMM register. The destination operand is a XMM register or a 128/64/32-bit memory location.

Down-converted word elements are written to the destination operand (the first operand) from the least-significant word. Word elements of the destination operand are updated according to the writemask. Bits (MAX_VL-1:128/64/32) of the register destination are zeroed.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPMOVQW instruction (EVEX encoded versions) when dest is a register
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 16
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+15:i] <-  TruncateQuadWordToWord (SRC[m+63:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+15:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+15:i] <-  0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/4] <-  0;
```
#### VPMOVQW instruction (EVEX encoded versions) when dest is memory
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 16
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+15:i] <-  TruncateQuadWordToWord (SRC[m+63:m])
                ELSE 
                      *DEST[i+15:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```
#### VPMOVSQW instruction (EVEX encoded versions) when dest is a register
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 16
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+15:i] <-  SaturateSignedQuadWordToWord (SRC[m+63:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+15:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+15:i] <-  0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/4] <-  0;
```
#### VPMOVSQW instruction (EVEX encoded versions) when dest is memory
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 16
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+15:i] <-  SaturateSignedQuadWordToWord (SRC[m+63:m])
                ELSE 
                      *DEST[i+15:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```
#### VPMOVUSQW instruction (EVEX encoded versions) when dest is a register
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 16
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+15:i] <-  SaturateUnsignedQuadWordToWord (SRC[m+63:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+15:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+15:i] <-  0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/4] <-  0;
```
#### VPMOVUSQW instruction (EVEX encoded versions) when dest is memory
```info-verb
    (KL, VL) = (2, 128), (4, 256), (8, 512)
    FOR j <-  0 TO KL-1
          i <-  j * 16
          m <-  j * 64
          IF k1[j] OR *no writemask*
                THEN DEST[i+15:i] <-  SaturateUnsignedQuadWordToWord (SRC[m+63:m])
                ELSE 
                      *DEST[i+15:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPMOVQW __m128i _mm512_cvtepi64_epi16( __m512i a);
VPMOVQW __m128i _mm512_mask_cvtepi64_epi16(__m128i s, __mmask8 k, __m512i a);
VPMOVQW __m128i _mm512_maskz_cvtepi64_epi16( __mmask8 k, __m512i a);
VPMOVQW void _mm512_mask_cvtepi64_storeu_epi16(void * d, __mmask8 k, __m512i a);
VPMOVSQW __m128i _mm512_cvtsepi64_epi16( __m512i a);
VPMOVSQW __m128i _mm512_mask_cvtsepi64_epi16(__m128i s, __mmask8 k, __m512i a);
VPMOVSQW __m128i _mm512_maskz_cvtsepi64_epi16( __mmask8 k, __m512i a);
VPMOVSQW void _mm512_mask_cvtsepi64_storeu_epi16(void * d, __mmask8 k, __m512i a);
VPMOVUSQW __m128i _mm512_cvtusepi64_epi16( __m512i a);
VPMOVUSQW __m128i _mm512_mask_cvtusepi64_epi16(__m128i s, __mmask8 k, __m512i a);
VPMOVUSQW __m128i _mm512_maskz_cvtusepi64_epi16( __mmask8 k, __m512i a);
VPMOVUSQW void _mm512_mask_cvtusepi64_storeu_epi16(void * d, __mmask8 k, __m512i a);
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

