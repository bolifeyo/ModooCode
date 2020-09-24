----------------------------
title : VRCP14SS (Intel x86/64 assembly instruction)
cat_title : VRCP14SS
ref_title : VRCP14SS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VRCP14SS

**Compute Approximate Reciprocal of Scalar Float32 Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F38.W0 4D /r\newline{}VRCP14SS xmm1 {k1}{z}, xmm2, xmm3/m32|T1S|V/V|AVX512F|Computes the approximate reciprocal of the scalar single-precision floating-point value in xmm3/m32 and stores the results in xmm1 using writemask k1. Also, upper double-precision floating-point value (bits[127:32]) from xmm2 is copied to xmm1[127:32]. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


This instruction performs a SIMD computation of the approximate reciprocal of the low single-precision floating-point value in the second source operand (the third operand) and stores the result in the low quadword element of the destination operand (the first operand) according to the writemask k1. Bits (127:32) of the XMM register desti-nation are copied from corresponding bits in the first source operand (the second operand). The maximum relative error for this approximation is less than 2\footnote{-14} . The source operand can be an XMM register or a 32-bit memory loca-tion. The destination operand is an XMM register.

The `VRCP14SS` instruction is not affected by the rounding control bits in the MXCSR register. When a source value is a 0.0, an $$\infty$$ with the sign of the source value is returned. A denormal source value will be treated as zero only in case of DAZ bit set in MXCSR. Otherwise it is treated correctly (i.e. not as a 0.0). Underflow results are flushed to zero only in case of FTZ bit set in MXCSR. Otherwise it will be treated correctly (i.e. correct underflow result is written) with the sign of the operand. When a source value is a SNaN or QNaN, the SNaN is converted to a QNaN or the source QNaN is returned. See Table 5-16 for special-case input values.

MXCSR exception flags are not affected by this instruction and floating-point exceptions are not reported.

A numerically exact implementation of VRCP14xx can be found at 

###                                                                                                    https://software.intel.com/en-us/articles/refer-ence-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VRCP14SS (EVEX version)
```info-verb
IF k1[0] OR *no writemask*
          THEN DEST[31:0] <-  APPROXIMATE(1.0/SRC2[31:0]);
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRCP14SS __m128 _mm_rcp14_ss( __m128 a, __m128 b);
VRCP14SS __m128 _mm_mask_rcp14_ss(__m128 s, __mmask8 k, __m128 a, __m128 b);
VRCP14SS __m128 _mm_maskz_rcp14_ss( __mmask8 k, __m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E5.
