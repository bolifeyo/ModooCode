----------------------------
title : VINSERTF128, VINSERTF32x4, VINSERTF64x2, VINSERTF32x8, VINSERTF64x4s (Intel x86/64 assembly instruction)
cat_title : VINSERTF128, VINSERTF32x4, VINSERTF64x2, VINSERTF32x8, VINSERTF64x4
ref_title : VINSERTF128, VINSERTF32x4, VINSERTF64x2, VINSERTF32x8, VINSERTF64x4
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VINSERTF128, VINSERTF32x4, VINSERTF64x2, VINSERTF32x8, VINSERTF64x4

**Insert Packed Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.256.66.0F3A.W0 18 /r ib\newline{}VINSERTF128 ymm1, ymm2, xmm3/m128, imm8|RVMI|V/V|AVX|Insert 128 bits of packed floating-point values from xmm3/m128 and the remaining values from ymm2 into ymm1.|
|EVEX.NDS.256.66.0F3A.W0 18 /r ibVINSERTF32X4 ymm1 {k1}{z}, ymm2, xmm3/m128, imm8|T4|V/V|AVX512VL\newline{}AVX512F|Insert 128 bits of packed single-precision floating-point values from xmm3/m128 and the remaining values from ymm2 into ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F3A.W0 18 /r ibVINSERTF32X4 zmm1 {k1}{z}, zmm2, xmm3/m128, imm8|T4|V/V|AVX512F|Insert 128 bits of packed single-precision floating-point values from xmm3/m128 and the remaining values from zmm2 into zmm1 under writemask k1.|
|EVEX.NDS.256.66.0F3A.W1 18 /r ibVINSERTF64X2 ymm1 {k1}{z}, ymm2, xmm3/m128, imm8|T2|V/V|AVX512VL\newline{}AVX512DQ|Insert 128 bits of packed double-precision floating-point values from xmm3/m128 and the remaining values from ymm2 into ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F3A.W1 18 /r ibVINSERTF64X2 zmm1 {k1}{z}, zmm2, xmm3/m128, imm8|T2|V/V|AVX512DQ|Insert 128 bits of packed double-precision floating-point values from xmm3/m128 and the remaining values from zmm2 into zmm1 under writemask k1.|
|EVEX.NDS.512.66.0F3A.W0 1A /r ibVINSERTF32X8 zmm1 {k1}{z}, zmm2, ymm3/m256, imm8|T8|V/V|AVX512DQ|Insert 256 bits of packed single-precision floating-point values from ymm3/m256 and the remaining values from zmm2 into zmm1 under writemask k1.|
|EVEX.NDS.512.66.0F3A.W1 1A /r ibVINSERTF64X4 zmm1 {k1}{z}, zmm2, ymm3/m256, imm8|T4|V/V|AVX512F|Insert 256 bits of packed double-precision floating-point values from ymm3/m256 and the remaining values from zmm2 into zmm1 under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
|T2, T4, T8|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


VINSERTF128/VINSERTF32x4 and `VINSERTF64x2` insert 128-bits of packed floating-point values from the second source operand (the third operand) into the destination operand (the first operand) at an 128-bit granularity offset multiplied by imm8[0] (256-bit) or imm8[1:0]. The remaining portions of the destination operand are copied from the corresponding fields of the first source operand (the second operand). The second source operand can be either an XMM register or a 128-bit memory location. The destination and first source operands are vector registers.

VINSERTF32x4: The destination operand is a ZMM/YMM register and updated at 32-bit granularity according to the writemask. The high 6/7 bits of the immediate are ignored. 

VINSERTF64x2: The destination operand is a ZMM/YMM register and updated at 64-bit granularity according to the writemask. The high 6/7 bits of the immediate are ignored. 

VINSERTF32x8 and `VINSERTF64x4` inserts 256-bits of packed floating-point values from the second source operand (the third operand) into the destination operand (the first operand) at a 256-bit granular offset multiplied by imm8[0]. The remaining portions of the destination are copied from the corresponding fields of the first source operand (the second operand). The second source operand can be either an YMM register or a 256-bit memory location. The high 7 bits of the immediate are ignored. The destination operand is a ZMM register and updated at 32/64-bit granularity according to the writemask.


### Operation
#### VINSERTF32x4 (EVEX encoded versions) 
```info-verb
(KL, VL) = (8, 256), (16, 512)
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
IF VL = 256
    CASE (imm8[0]) OF
          0:  TMP_DEST[127:0] <-  SRC2[127:0]
          1:  TMP_DEST[255:128] <-  SRC2[127:0]
    ESAC.
FI;
IF VL = 512
    CASE (imm8[1:0]) OF
          00:  TMP_DEST[127:0] <-  SRC2[127:0]
          01:  TMP_DEST[255:128] <-  SRC2[127:0]
          10:  TMP_DEST[383:256] <-  SRC2[127:0]
          11:  TMP_DEST[511:384] <-  SRC2[127:0]
    ESAC.
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTF64x2 (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 256), (8, 512)
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
IF VL = 256
    CASE (imm8[0]) OF
          0:  TMP_DEST[127:0] <-  SRC2[127:0]
          1:  TMP_DEST[255:128] <-  SRC2[127:0]
    ESAC.
FI;
IF VL = 512
    CASE (imm8[1:0]) OF
          00:  TMP_DEST[127:0] <-  SRC2[127:0]
          01:  TMP_DEST[255:128] <-  SRC2[127:0]
          10:  TMP_DEST[383:256] <-  SRC2[127:0]
          11:  TMP_DEST[511:384] <-  SRC2[127:0]
    ESAC.
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTF32x8 (EVEX.U1.512 encoded version)
```info-verb
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC2[255:0]
    1: TMP_DEST[511:256] <-  SRC2[255:0]
ESAC.
FOR j <-  0 TO 15
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTF64x4 (EVEX.512 encoded version) 
```info-verb
VL = 512
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC2[255:0]
    1: TMP_DEST[511:256] <-  SRC2[255:0]
ESAC.
FOR j <-  0 TO 7
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTF128 (VEX encoded version)
```info-verb
TEMP[255:0] <- SRC1[255:0]
CASE (imm8[0]) OF
    0: TEMP[127:0] <- SRC2[127:0]
    1: TEMP[255:128] <- SRC2[127:0]
ESAC
DEST <- TEMP
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VINSERTF32x4 __m512 _mm512_insertf32x4( __m512 a, __m128 b, int imm);
VINSERTF32x4 __m512 _mm512_mask_insertf32x4(__m512 s, __mmask16 k, __m512 a, __m128 b, int imm);
VINSERTF32x4 __m512 _mm512_maskz_insertf32x4( __mmask16 k, __m512 a, __m128 b, int imm);
VINSERTF32x4 __m256 _mm256_insertf32x4( __m256 a, __m128 b, int imm);
VINSERTF32x4 __m256 _mm256_mask_insertf32x4(__m256 s, __mmask8 k, __m256 a, __m128 b, int imm);
VINSERTF32x4 __m256 _mm256_maskz_insertf32x4( __mmask8 k, __m256 a, __m128 b, int imm);
VINSERTF32x8 __m512 _mm512_insertf32x8( __m512 a, __m256 b, int imm);
VINSERTF32x8 __m512 _mm512_mask_insertf32x8(__m512 s, __mmask16 k, __m512 a, __m256 b, int imm);
VINSERTF32x8 __m512 _mm512_maskz_insertf32x8( __mmask16 k, __m512 a, __m256 b, int imm);
VINSERTF64x2 __m512d _mm512_insertf64x2( __m512d a, __m128d b, int imm);
VINSERTF64x2 __m512d _mm512_mask_insertf64x2(__m512d s, __mmask8 k, __m512d a, __m128d b, int imm);
VINSERTF64x2 __m512d _mm512_maskz_insertf64x2( __mmask8 k, __m512d a, __m128d b, int imm);
VINSERTF64x2 __m256d _mm256_insertf64x2( __m256d a, __m128d b, int imm);
VINSERTF64x2 __m256d _mm256_mask_insertf64x2(__m256d s, __mmask8 k, __m256d a, __m128d b, int imm);
VINSERTF64x2 __m256d _mm256_maskz_insertf64x2( __mmask8 k, __m256d a, __m128d b, int imm);
VINSERTF64x4 __m512d _mm512_insertf64x4( __m512d a, __m256d b, int imm);
VINSERTF64x4 __m512d _mm512_mask_insertf64x4(__m512d s, __mmask8 k, __m512d a, __m256d b, int imm);
VINSERTF64x4 __m512d _mm512_maskz_insertf64x4( __mmask8 k, __m512d a, __m256d b, int imm);
VINSERTF128 __m256 _mm256_insertf128_ps (__m256 a, __m128 b, int offset);
VINSERTF128 __m256d _mm256_insertf128_pd (__m256d a, __m128d b, int offset);
VINSERTF128 __m256i _mm256_insertf128_si256 (__m256i a, __m128i b, int offset);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


VEX-encoded instruction, see Exceptions Type 6; additionally

#UD If VEX.L = 0.

EVEX-encoded instruction, see Exceptions Type E6NF.
