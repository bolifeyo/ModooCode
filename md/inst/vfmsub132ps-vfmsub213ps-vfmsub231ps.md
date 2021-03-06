----------------------------
title : VFMSUB132PS, VFMSUB213PS, VFMSUB231PSs (Intel x86/64 assembly instruction)
cat_title : VFMSUB132PS, VFMSUB213PS, VFMSUB231PS
ref_title : VFMSUB132PS, VFMSUB213PS, VFMSUB231PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFMSUB132PS, VFMSUB213PS, VFMSUB231PS

**Fused Multiply-Subtract of Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/E**\newline{}**n**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.128.66.0F38.W0 9A /r `\newline{}`VFMSUB132PS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|FMA|Multiply packed single-precision floating-point values from xmm1 and xmm3/mem, subtract xmm2 and put result in xmm1.|
|`VEX.NDS.128.66.0F38.W0 AA /r `\newline{}`VFMSUB213PS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|FMA|Multiply packed single-precision floating-point values from xmm1 and xmm2, subtract xmm3/mem and put result in xmm1.|
|`VEX.NDS.128.66.0F38.W0 BA /r `\newline{}`VFMSUB231PS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|FMA|Multiply packed single-precision floating-point values from xmm2 and xmm3/mem, subtract xmm1 and put result in xmm1.|
|`VEX.NDS.256.66.0F38.W0 9A /r `\newline{}`VFMSUB132PS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|FMA|Multiply packed single-precision floating-point values from ymm1 and ymm3/mem, subtract ymm2 and put result in ymm1.|
|`VEX.NDS.256.66.0F38.W0 AA /r `\newline{}`VFMSUB213PS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|FMA|Multiply packed single-precision floating-point values from ymm1 and ymm2, subtract ymm3/mem and put result in ymm1.|
|`VEX.NDS.256.66.0F38.0 BA /r `\newline{}`VFMSUB231PS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|FMA|Multiply packed single-precision floating-point values from ymm2 and ymm3/mem, subtract ymm1 and put result in ymm1.|
|`EVEX.NDS.128.66.0F38.W0 9A /r `\newline{}`VFMSUB132PS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from xmm1 and xmm3/m128/m32bcst, subtract   xmm2 and put result in xmm1.|
|`EVEX.NDS.128.66.0F38.W0 AA /r `\newline{}`VFMSUB213PS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from xmm1 and xmm2, subtract   xmm3/m128/m32bcst and put result in xmm1.|
|`EVEX.NDS.128.66.0F38.W0 BA /r`\newline{}`VFMSUB231PS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from xmm2 and xmm3/m128/m32bcst, subtract   xmm1 and put result in xmm1.|
|`EVEX.NDS.256.66.0F38.W0 9A /r`\newline{}`VFMSUB132PS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from ymm1 and ymm3/m256/m32bcst, subtract   ymm2 and put result in ymm1.|
|`EVEX.NDS.256.66.0F38.W0 AA /r `\newline{}`VFMSUB213PS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from ymm1 and ymm2, subtract   ymm3/m256/m32bcst and put result in ymm1.|
|`EVEX.NDS.256.66.0F38.W0 BA /r`\newline{}`VFMSUB231PS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from ymm2 and ymm3/m256/m32bcst, subtract   ymm1 and put result in ymm1.|
|`EVEX.NDS.512.66.0F38.W0 9A /r `\newline{}`VFMSUB132PS` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 zmm3/m512/m32bcst{er} |FV|V/V|AVX512F|Multiply packed single-precision floating-point values from zmm1 and zmm3/m512/m32bcst, subtract zmm2 and put result in zmm1.|
|`EVEX.NDS.512.66.0F38.W0 AA /r `\newline{}`VFMSUB213PS` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 zmm3/m512/m32bcst{er} |FV|V/V|AVX512F|Multiply packed single-precision floating-point values from zmm1 and zmm2, subtract zmm3/m512/m32bcst and put result in zmm1.|
|`EVEX.NDS.512.66.0F38.W0 BA /r `\newline{}`VFMSUB231PS` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 zmm3/m512/m32bcst{er} |FV|V/V|AVX512F|Multiply packed single-precision floating-point values from zmm2 and zmm3/m512/m32bcst, subtract zmm1 and put result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (r, w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (r, w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a set of SIMD multiply-subtract computation on packed single-precision floating-point values using three source operands and writes the multiply-subtract results in the destination operand. The destination operand is also the first source operand. The second operand must be a SIMD register. The third source operand can be a SIMD register or a memory location. 

VFMSUB132PS: Multiplies the four, eight or sixteen packed single-precision floating-point values from the first source operand to the four, eight or sixteen packed single-precision floating-point values in the third source operand. From the infinite precision intermediate result, subtracts the four, eight or sixteen packed single-precision floating-point values in the second source operand, performs rounding and stores the resulting four, eight or sixteen packed single-precision floating-point values to the destination operand (first source operand).

VFMSUB213PS: Multiplies the four, eight or sixteen packed single-precision floating-point values from the second source operand to the four, eight or sixteen packed single-precision floating-point values in the first source operand. From the infinite precision intermediate result, subtracts the four, eight or sixteen packed single-precision floating-point values in the third source operand, performs rounding and stores the resulting four, eight or sixteen packed single-precision floating-point values to the destination operand (first source operand).

VFMSUB231PS: Multiplies the four, eight or sixteen packed single-precision floating-point values from the second source to the four, eight or sixteen packed single-precision floating-point values in the third source operand. From the infinite precision intermediate result, subtracts the four, eight or sixteen packed single-precision floating-point values in the first source operand, performs rounding and stores the resulting four, eight or sixteen packed single-precision floating-point values to the destination operand (first source operand).

EVEX encoded versions: The destination operand (also first source operand) and the second source operand are ZMM/YMM/XMM register. The third source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory loca-tion or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is condition-ally updated with write mask k1.

VEX.256 encoded version: The destination operand (also first source operand) is a YMM register and encoded in reg\esc{_}field. The second source operand is a YMM register and encoded in VEX.vvvv. The third source operand is a YMM register or a 256-bit memory location and encoded in rm\esc{_}field. 

VEX.128 encoded version: The destination operand (also first source operand) is a XMM register and encoded in reg\esc{_}field. The second source operand is a XMM register and encoded in VEX.vvvv. The third source operand is a XMM register or a 128-bit memory location and encoded in rm\esc{_}field. The upper 128 bits of the YMM destination register are zeroed.


### Operation
#### VFMSUB132PS DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
IF (VEX.128) THEN 
    MAXNUM <- 2
ELSEIF (VEX.256)
    MAXNUM <-  4
FI
For i = 0 to MAXNUM-1 {
    n <-  32*i;
    DEST[n+31:n] <-  RoundFPControl_MXCSR(DEST[n+31:n]*SRC3[n+31:n] - SRC2[n+31:n])
}
IF (VEX.128) THEN
    DEST[MAX_VL-1:128] <-  0
ELSEIF (VEX.256)
    DEST[MAX_VL-1:256] <-  0
FI
```
#### VFMSUB213PS DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
IF (VEX.128) THEN 
    MAXNUM <- 2
ELSEIF (VEX.256)
    MAXNUM <-  4
FI
For i = 0 to MAXNUM-1 {
    n <-  32*i;
    DEST[n+31:n] <-  RoundFPControl_MXCSR(SRC2[n+31:n]*DEST[n+31:n] - SRC3[n+31:n])
}
IF (VEX.128) THEN
    DEST[MAX_VL-1:128] <-  0
ELSEIF (VEX.256)
    DEST[MAX_VL-1:256] <-  0
FI
```
#### VFMSUB231PS DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
IF (VEX.128) THEN 
    MAXNUM <- 2
ELSEIF (VEX.256)
    MAXNUM <-  4
FI
For i = 0 to MAXNUM-1 {
    n <-  32*i;
    DEST[n+31:n] <-  RoundFPControl_MXCSR(SRC2[n+31:n]*SRC3[n+31:n] - DEST[n+31:n])
}
IF (VEX.128) THEN
    DEST[MAX_VL-1:128] <-  0
ELSEIF (VEX.256)
    DEST[MAX_VL-1:256] <-  0
FI
```
#### VFMSUB132PS DEST, SRC2, SRC3 (EVEX encoded version, when src3 operand is a register)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1)
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  
                RoundFPControl(DEST[i+31:i]*SRC3[i+31:i] - SRC2[i+31:i])
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
#### VFMSUB132PS DEST, SRC2, SRC3 (EVEX encoded version, when src3 operand is a memory source)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) 
                      THEN
                            DEST[i+31:i] <-  
                RoundFPControl_MXCSR(DEST[i+31:i]*SRC3[31:0] - SRC2[i+31:i])
                      ELSE 
                            DEST[i+31:i] <-  
                RoundFPControl_MXCSR(DEST[i+31:i]*SRC3[i+31:i] - SRC2[i+31:i])
                FI;
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
#### VFMSUB213PS DEST, SRC2, SRC3 (EVEX encoded version, when src3 operand is a register)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1)
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  
                RoundFPControl_MXCSR(SRC2[i+31:i]*DEST[i+31:i] - SRC3[i+31:i])
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
#### VFMSUB213PS DEST, SRC2, SRC3 (EVEX encoded version, when src3 operand is a memory source)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) 
                      THEN
                            DEST[i+31:i] <-  
                RoundFPControl_MXCSR(SRC2[i+31:i]*DEST[i+31:i] - SRC3[31:0])
                      ELSE 
                            DEST[i+31:i] <-  
                RoundFPControl_MXCSR(SRC2[i+31:i]*DEST[i+31:i] - SRC3[i+31:i])
                FI;
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
#### VFMSUB231PS DEST, SRC2, SRC3 (EVEX encoded version, when src3 operand is a register)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1)
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  
                RoundFPControl_MXCSR(SRC2[i+31:i]*SRC3[i+31:i] - DEST[i+31:i])
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
#### VFMSUB231PS DEST, SRC2, SRC3 (EVEX encoded version, when src3 operand is a memory source)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) 
                      THEN
                            DEST[i+31:i] <-  
                RoundFPControl_MXCSR(SRC2[i+31:i]*SRC3[31:0] - DEST[i+31:i])
                      ELSE 
                            DEST[i+31:i] <-  
                RoundFPControl_MXCSR(SRC2[i+31:i]*SRC3[i+31:i] - DEST[i+31:i])
                FI;
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

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFMSUBxxxPS __m512 _mm512_fmsub_ps(__m512 a, __m512 b, __m512 c);
VFMSUBxxxPS __m512 _mm512_fmsub_round_ps(__m512 a, __m512 b, __m512 c, int r);
VFMSUBxxxPS __m512 _mm512_mask_fmsub_ps(__m512 a, __mmask16 k, __m512 b, __m512 c);
VFMSUBxxxPS __m512 _mm512_maskz_fmsub_ps(__mmask16 k, __m512 a, __m512 b, __m512 c);
VFMSUBxxxPS __m512 _mm512_mask3_fmsub_ps(__m512 a, __m512 b, __m512 c, __mmask16 k);
VFMSUBxxxPS __m512 _mm512_mask_fmsub_round_ps(__m512 a, __mmask16 k, __m512 b, __m512 c, int r);
VFMSUBxxxPS __m512 _mm512_maskz_fmsub_round_ps(__mmask16 k, __m512 a, __m512 b, __m512 c, int r);
VFMSUBxxxPS __m512 _mm512_mask3_fmsub_round_ps(__m512 a, __m512 b, __m512 c, __mmask16 k, int r);
VFMSUBxxxPS __m256 _mm256_mask_fmsub_ps(__m256 a, __mmask8 k, __m256 b, __m256 c);
VFMSUBxxxPS __m256 _mm256_maskz_fmsub_ps(__mmask8 k, __m256 a, __m256 b, __m256 c);
VFMSUBxxxPS __m256 _mm256_mask3_fmsub_ps(__m256 a, __m256 b, __m256 c, __mmask8 k);
VFMSUBxxxPS __m128 _mm_mask_fmsub_ps(__m128 a, __mmask8 k, __m128 b, __m128 c);
VFMSUBxxxPS __m128 _mm_maskz_fmsub_ps(__mmask8 k, __m128 a, __m128 b, __m128 c);
VFMSUBxxxPS __m128 _mm_mask3_fmsub_ps(__m128 a, __m128 b, __m128 c, __mmask8 k);
VFMSUBxxxPS __m128 _mm_fmsub_ps (__m128 a, __m128 b, __m128 c);
VFMSUBxxxPS __m256 _mm256_fmsub_ps (__m256 a, __m256 b, __m256 c);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2.

EVEX-encoded instructions, see Exceptions Type E2.

