----------------------------
title : VBLENDMPD, VBLENDMPSs (Intel x86/64 assembly instruction)
cat_title : VBLENDMPD, VBLENDMPS
ref_title : VBLENDMPD, VBLENDMPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VBLENDMPD, VBLENDMPS

**Blend Float64/Float32 Vectors Using an OpMask Control**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F38.W1 65 /r\newline{}VBLENDMPD xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Blend double-precision vector xmm2 and double-precision vector xmm3/m128/m64bcst and store the result in xmm1, under control mask.|
|EVEX.NDS.256.66.0F38.W1 65 /r\newline{}VBLENDMPD ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Blend double-precision vector ymm2 and double-precision vector ymm3/m256/m64bcst and store the result in ymm1, under control mask.|
|EVEX.NDS.512.66.0F38.W1 65 /r\newline{}VBLENDMPD zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Blend double-precision vector zmm2 and double-precision vector zmm3/m512/m64bcst and store the result in zmm1, under control mask.|
|EVEX.NDS.128.66.0F38.W0 65 /r\newline{}VBLENDMPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Blend single-precision vector xmm2 and single-precision vector xmm3/m128/m32bcst and store the result in xmm1, under control mask.|
|EVEX.NDS.256.66.0F38.W0 65 /r\newline{}VBLENDMPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Blend single-precision vector ymm2 and single-precision vector ymm3/m256/m32bcst and store the result in ymm1, under control mask.|
|EVEX.NDS.512.66.0F38.W0 65 /r\newline{}VBLENDMPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Blend single-precision vector zmm2 and single-precision vector zmm3/m512/m32bcst using k1 as select control and store the result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Performs an element-by-element blending between float64/float32 elements in the first source operand (the second operand) with the elements in the second source operand (the third operand) using an opmask register as select control. The blended result is written to the destination register.

The destination and first source operands are ZMM/YMM/XMM registers. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location.

The opmask register is not used as a writemask for this instruction. Instead, the mask is used as an element selector: every element of the destination is conditionally selected between first source or second source using the value of the related mask bit (0 for first source operand, 1 for second source operand).

If EVEX.z is set, the elements with corresponding mask bit value of 0 in the destination operand are zeroed.


### Operation
#### VBLENDMPD (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no controlmask*
          THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+63:i] <-  SRC2[63:0]
                      ELSE 
                            DEST[i+63:i] <-  SRC2[i+63:i]
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN DEST[i+63:i] <-  SRC1[i+63:i]
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VBLENDMPS (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no controlmask*
          THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+31:i] <-  SRC2[31:0]
                      ELSE 
                            DEST[i+31:i] <-  SRC2[i+31:i]
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN DEST[i+31:i] <-  SRC1[i+31:i]
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VBLENDMPD __m512d _mm512_mask_blend_pd(__mmask8 k, __m512d a, __m512d b);
VBLENDMPD __m256d _mm256_mask_blend_pd(__mmask8 k, __m256d a, __m256d b);
VBLENDMPD __m128d _mm_mask_blend_pd(__mmask8 k, __m128d a, __m128d b);
VBLENDMPS __m512 _mm512_mask_blend_ps(__mmask16 k, __m512 a, __m512 b);
VBLENDMPS __m256 _mm256_mask_blend_ps(__mmask8 k, __m256 a, __m256 b);
VBLENDMPS __m128 _mm_mask_blend_ps(__mmask8 k, __m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4.
