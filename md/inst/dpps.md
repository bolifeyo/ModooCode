----------------------------
title : DPPS (Intel x86/64 assembly instruction)
cat_title : DPPS
ref_title : DPPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/D
publish_date: 2020-09-01
----------------------------


#@ DPPS

** Dot Product of Packed Single Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A 40 /r ib`\newline{}`DPPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE4_1|Selectively multiply packed SP floating-point values from xmm1 with packed SP floating-point values from xmm2, add and selectively store the packed SP floating-point values or zero values to xmm1.|
|`VEX.NDS.128.66.0F3A.WIG 40 /r ib`\newline{}VDPPS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Multiply packed SP floating point values from xmm1 with packed SP floating point values from xmm2/mem selectively add and store to xmm1.|
|`VEX.NDS.256.66.0F3A.WIG 40 /r ib`\newline{}VDPPS \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Multiply packed single-precision floating-point values from ymm2 with packed SP floating point values from ymm3/mem, selectively add pairs of elements and store to ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
### Description


Conditionally multiplies the packed single precision floating-point values in the destination operand (first operand) with the packed single-precision floats in the source (second operand) depending on a mask extracted from the high 4 bits of the immediate byte (third operand). If a condition mask bit in Imm8[7:4] is zero, the corresponding multiplication is replaced by a value of 0.0 in the manner described by Section 12.8.4 of Intel(R) 64 and IA-32 Archi-tectures Software Developer's Manual, Volume 1.

The four resulting single-precision values are summed into an intermediate result. The intermediate result is condi-tionally broadcasted to the destination using a broadcast mask specified by bits [3:0] of the immediate byte.

If a broadcast mask bit is "1", the intermediate result is copied to the corresponding dword element in the destina-tion operand. If a broadcast mask bit is zero, the corresponding element in the destination is set to zero.

DPPS follows the NaN forwarding rules stated in the Software Developer's Manual, vol. 1, table 4.7. These rules do not cover horizontal prioritization of NaNs. Horizontal propagation of NaNs to the destination and the positioning of those NaNs in the destination is implementation dependent. NaNs on the input sources or computationally gener-ated NaNs will have at least one NaN propagated to the destination.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register.


### Operation
#### DP_primitive (SRC1, SRC2)
```info-verb
IF (imm8[4] = 1) 
    THEN Temp1[31:0] <-  DEST[31:0] * SRC[31:0]; // update SIMD exception flags
    ELSE Temp1[31:0] <-  +0.0; FI;
IF (imm8[5] = 1) 
    THEN Temp1[63:32] <-  DEST[63:32] * SRC[63:32]; // update SIMD exception flags
    ELSE Temp1[63:32] <-  +0.0; FI;
IF (imm8[6] = 1) 
    THEN Temp1[95:64] <-  DEST[95:64] * SRC[95:64]; // update SIMD exception flags
    ELSE Temp1[95:64] <-  +0.0; FI;
IF (imm8[7] = 1) 
    THEN Temp1[127:96] <-  DEST[127:96] * SRC[127:96]; // update SIMD exception flags
    ELSE Temp1[127:96] <-  +0.0; FI;
Temp2[31:0] <-  Temp1[31:0] + Temp1[63:32]; // update SIMD exception flags
/* if unmasked exception reported, execute exception handler*/
Temp3[31:0] <-  Temp1[95:64] + Temp1[127:96]; // update SIMD exception flags
/* if unmasked exception reported, execute exception handler*/
Temp4[31:0] <-  Temp2[31:0] + Temp3[31:0]; // update SIMD exception flags
/* if unmasked exception reported, execute exception handler*/
IF (imm8[0] = 1) 
    THEN DEST[31:0] <-  Temp4[31:0];
    ELSE DEST[31:0] <-  +0.0; FI;
IF (imm8[1] = 1) 
    THEN DEST[63:32] <-  Temp4[31:0];
    ELSE DEST[63:32] <-  +0.0; FI;
IF (imm8[2] = 1) 
    THEN DEST[95:64] <-  Temp4[31:0];
    ELSE DEST[95:64] <-  +0.0; FI;
IF (imm8[3] = 1) 
    THEN DEST[127:96] <-  Temp4[31:0];
    ELSE DEST[127:96] <-  +0.0; FI;
```
#### DPPS (128-bit Legacy SSE version)
```info-verb
DEST[127:0]<- DP_Primitive(SRC1[127:0], SRC2[127:0]);
DEST[VLMAX-1:128] (Unmodified)
```
#### VDPPS (VEX.128 encoded version)
```info-verb
DEST[127:0]<- DP_Primitive(SRC1[127:0], SRC2[127:0]);
DEST[VLMAX-1:128] <-  0
```
#### VDPPS (VEX.256 encoded version)
```info-verb
DEST[127:0]<- DP_Primitive(SRC1[127:0], SRC2[127:0]);
DEST[255:128]<- DP_Primitive(SRC1[255:128], SRC2[255:128]);
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
(V)DPPS: __m128 _mm_dp_ps ( __m128 a, __m128 b, const int mask);
VDPPS: __m256 _mm256_dp_ps ( __m256 a, __m256 b, const int mask);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

Exceptions are determined separately for each add and multiply operation, in the order of their execution. Unmasked exceptions will leave the destination operands unchanged.

### Other Exceptions


See Exceptions Type 2.

