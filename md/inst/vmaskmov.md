----------------------------
title : VMASKMOV (Intel x86/64 assembly instruction)
cat_title : VMASKMOV
ref_title : VMASKMOV
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VMASKMOV

**Conditional SIMD Packed Loads and Stores**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.128.66.0F38.W0 2C /r`\newline{}VMASKMOVPS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} |RVM|V/V|AVX|Conditionally load packed single-precision values from m128 using mask in xmm2 and store in xmm1.|
|`VEX.NDS.256.66.0F38.W0 2C /r`\newline{}VMASKMOVPS \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} |RVM|V/V|AVX|Conditionally load packed single-precision values from m256 using mask in ymm2 and store in ymm1.|
|`VEX.NDS.128.66.0F38.W0 2D /r`\newline{}VMASKMOVPD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} |RVM|V/V|AVX|Conditionally load packed double-precision values from m128 using mask in xmm2 and store in xmm1.|
|`VEX.NDS.256.66.0F38.W0 2D /r`\newline{}VMASKMOVPD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} |RVM|V/V|AVX|Conditionally load packed double-precision values from m256 using mask in ymm2 and store in ymm1.|
|`VEX.NDS.128.66.0F38.W0 2E /r`\newline{}VMASKMOVPS \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MVR|V/V|AVX|Conditionally store packed single-precision values from xmm2 using mask in xmm1.|
|`VEX.NDS.256.66.0F38.W0 2E /r`\newline{}VMASKMOVPS \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |MVR|V/V|AVX|Conditionally store packed single-precision values from ymm2 using mask in ymm1.|
|`VEX.NDS.128.66.0F38.W0 2F /r`\newline{}VMASKMOVPD \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MVR|V/V|AVX|Conditionally store packed double-precision values from xmm2 using mask in xmm1.|
|`VEX.NDS.256.66.0F38.W0 2F /r`\newline{}VMASKMOVPD \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |MVR|V/V|AVX|Conditionally store packed double-precision values from ymm2 using mask in ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|MVR|ModRM:r/m (w)|VEX.vvvv (r)|ModRM:reg (r)|NA|
### Description


Conditionally moves packed data elements from the second source operand into the corresponding data element of the destination operand, depending on the mask bits associated with each data element. The mask bits are speci-fied in the first source operand. 

The mask bit for each data element is the most significant bit of that element in the first source operand. If a mask is 1, the corresponding data element is copied from the second source operand to the destination operand. If the mask is 0, the corresponding data element is set to zero in the load form of these instructions, and unmodified in the store form. 

The second source operand is a memory address for the load form of these instruction. The destination operand is a memory address for the store form of these instructions. The other operands are both XMM registers (for VEX.128 version) or YMM registers (for VEX.256 version).

Faults occur only due to mask-bit required memory accesses that caused the faults. Faults will not occur due to referencing any memory location if the corresponding mask bit for that memory location is 0. For example, no faults will be detected if the mask bits are all zero.

Unlike previous MASKMOV instructions (MASKMOVQ and MASKMOVDQU), a nontemporal hint is not applied to these instructions.

Instruction behavior on alignment check reporting with mask bits of less than all 1s are the same as with mask bits of all 1s.

VMASKMOV should not be used to access memory mapped I/O and un-cached memory as the access and the ordering of the individual loads or stores it does is implementation specific. 



In cases where mask bits indicate data should not be loaded or stored paging A and D bits will be set in an imple-mentation dependent way. However, A and D bits are always set for pages where data is actually loaded/stored.

Note: for load forms, the first source (the mask) is encoded in VEX.vvvv; the second source is encoded in rm\esc{_}field, and the destination register is encoded in reg\esc{_}field.

Note: for store forms, the first source (the mask) is encoded in VEX.vvvv; the second source register is encoded in reg\esc{_}field, and the destination memory location is encoded in rm\esc{_}field.


### Operation
#### VMASKMOVPS -128-bit load 
```info-verb
DEST[31:0] <-  IF (SRC1[31]) Load_32(mem) ELSE 0 
DEST[63:32] <-  IF (SRC1[63]) Load_32(mem + 4) ELSE 0 
DEST[95:64] <-  IF (SRC1[95]) Load_32(mem + 8) ELSE 0 
DEST[127:97] <-  IF (SRC1[127]) Load_32(mem + 12) ELSE 0 
DEST[VLMAX-1:128] <-  0
```
#### VMASKMOVPS - 256-bit load
```info-verb
DEST[31:0] <-  IF (SRC1[31]) Load_32(mem) ELSE 0 
DEST[63:32] <-  IF (SRC1[63]) Load_32(mem + 4) ELSE 0 
DEST[95:64] <-  IF (SRC1[95]) Load_32(mem + 8) ELSE 0 
DEST[127:96] <-  IF (SRC1[127]) Load_32(mem + 12) ELSE 0 
DEST[159:128] <-  IF (SRC1[159]) Load_32(mem + 16) ELSE 0 
DEST[191:160] <-  IF (SRC1[191]) Load_32(mem + 20) ELSE 0 
DEST[223:192] <-  IF (SRC1[223]) Load_32(mem + 24) ELSE 0 
DEST[255:224] <-  IF (SRC1[255]) Load_32(mem + 28) ELSE 0 
```
#### VMASKMOVPD - 128-bit load 
```info-verb
DEST[63:0] <-  IF (SRC1[63]) Load_64(mem) ELSE 0 
DEST[127:64] <-  IF (SRC1[127]) Load_64(mem + 16) ELSE 0
DEST[VLMAX-1:128] <-  0
```
#### VMASKMOVPD - 256-bit load
```info-verb
DEST[63:0] <-  IF (SRC1[63]) Load_64(mem) ELSE 0 
DEST[127:64] <-  IF (SRC1[127]) Load_64(mem + 8) ELSE 0 
DEST[195:128] <-  IF (SRC1[191]) Load_64(mem + 16) ELSE 0 
DEST[255:196] <-  IF (SRC1[255]) Load_64(mem + 24) ELSE 0 
```
#### VMASKMOVPS - 128-bit store
```info-verb
IF (SRC1[31]) DEST[31:0] <-  SRC2[31:0] 
IF (SRC1[63]) DEST[63:32] <-  SRC2[63:32] 
IF (SRC1[95]) DEST[95:64] <-  SRC2[95:64] 
IF (SRC1[127]) DEST[127:96] <-  SRC2[127:96] 
```
#### VMASKMOVPS - 256-bit store
```info-verb
IF (SRC1[31]) DEST[31:0] <-  SRC2[31:0] 
IF (SRC1[63]) DEST[63:32] <-  SRC2[63:32] 
IF (SRC1[95]) DEST[95:64] <-  SRC2[95:64] 
IF (SRC1[127]) DEST[127:96] <-  SRC2[127:96] 
IF (SRC1[159]) DEST[159:128] <- SRC2[159:128] 
IF (SRC1[191]) DEST[191:160] <-  SRC2[191:160] 
IF (SRC1[223]) DEST[223:192] <-  SRC2[223:192] 
IF (SRC1[255]) DEST[255:224] <-  SRC2[255:224] 
```
#### VMASKMOVPD - 128-bit store
```info-verb
IF (SRC1[63]) DEST[63:0] <-  SRC2[63:0] 
IF (SRC1[127]) DEST[127:64] <- SRC2[127:64] 
```
#### VMASKMOVPD - 256-bit store
```info-verb
IF (SRC1[63]) DEST[63:0] <-  SRC2[63:0] 
IF (SRC1[127]) DEST[127:64] <- SRC2[127:64] 
IF (SRC1[191]) DEST[191:128] <-  SRC2[191:128] 
IF (SRC1[255]) DEST[255:192] <-  SRC2[255:192] 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
__m256  _mm256_maskload_ps(float const *a, __m256i mask)
void    _mm256_maskstore_ps(float *a, __m256i mask, __m256 b)
__m256d _mm256_maskload_pd(double *a, __m256i mask);
void    _mm256_maskstore_pd(double *a, __m256i mask, __m256d b);
__m128 _mm128_maskload_ps(float const *a, __m128i mask)
void    _mm128_maskstore_ps(float *a, __m128i mask, __m128 b)
__m128d _mm128_maskload_pd(double *a, __m128i mask);
void    _mm128_maskstore_pd(double *a, __m128i mask, __m128d b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 6 (No AC# reported for any mask bit combinations);

additionally

#UD  If VEX.W = 1.

