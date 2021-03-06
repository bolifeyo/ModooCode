----------------------------
title : MOVNTDQ (Intel x86/64 assembly instruction)
cat_title : MOVNTDQ
ref_title : MOVNTDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVNTDQ

**Store Packed Integers Using Non-Temporal Hint**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|------------------------------------|---------------|
|`66 0F E7 /r`\newline{}`MOVNTDQ` \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|SSE2|Move packed integer values in xmm1 to m128 using non-temporal hint.|
|`VEX.128.66.0F.WIG E7 /r`\newline{}VMOVNTDQ \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move packed integer values in xmm1 to m128 using non-temporal hint.|
|`VEX.256.66.0F.WIG E7 /r`\newline{}VMOVNTDQ \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move packed integer values in ymm1 to m256 using non-temporal hint.|
|`EVEX.128.66.0F.W0 E7 /r`\newline{}VMOVNTDQ \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move packed integer values in xmm1 to m128 using non-temporal hint.|
|`EVEX.256.66.0F.W0 E7 /r`\newline{}VMOVNTDQ \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move packed integer values in zmm1 to m256 using non-temporal hint.|
|`EVEX.512.66.0F.W0 E7 /r`\newline{}VMOVNTDQ \tooltip{m512}{64 바이트 메모리 데이터} zmm1 |FVM|V/V|AVX512F|Move packed integer values in zmm1 to m512 using non-temporal hint.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|FVM|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Moves the packed integers in the source operand (second operand) to the destination operand (first operand) using a non-temporal hint to prevent caching of the data during the write to memory. The source operand is an XMM register, YMM register or ZMM register, which is assumed to contain integer data (packed bytes, words, double-words, or quadwords). The destination operand is a 128-bit, 256-bit or 512-bit memory location. The memory operand must be aligned on a 16-byte (128-bit version), 32-byte (VEX.256 encoded version) or 64-byte (512-bit version) boundary otherwise a general-protection exception (#GP) will be generated. 

The non-temporal hint is implemented by using a write combining (WC) memory type protocol when writing the data to memory. Using this protocol, the processor does not write the data into the cache hierarchy, nor does it fetch the corresponding cache line from memory into the cache hierarchy. The memory type of the region being written to can override the non-temporal hint, if the memory address specified for the non-temporal store is in an uncacheable (UC) or write protected (WP) memory region. For more information on non-temporal stores, see "Caching of Temporal vs. Non-Temporal Data" in Chapter 10 in the IA-32 Intel Architecture Software Developer's Manual, Volume 1.

Because the WC protocol uses a weakly-ordered memory consistency model, a fencing operation implemented with the `SFENCE` or `MFENCE` instruction should be used in conjunction with VMOVNTDQ instructions if multiple proces-sors might use different memory types to read/write the destination memory locations.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, VEX.L must be 0; otherwise instructions will #UD.


### Operation
#### VMOVNTDQ(EVEX encoded versions) 
```info-verb
VL = 128, 256, 512
DEST[VL-1:0] <-  SRC[VL-1:0]
DEST[MAX_VL-1:VL] <-  0
```
```sidenote


1. ModRM.MOD = 011B required
```

**MOVNTDQ (Legacy and VEX versions)**

DEST <-  SRC


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVNTDQ void _mm512_stream_si512(void * p, __m512i a);
VMOVNTDQ void _mm256_stream_si256 (__m256i * p, __m256i a);
MOVNTDQ void _mm_stream_si128 (__m128i * p, __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type1.SSE2; 

EVEX-encoded instruction, see Exceptions Type E1NF.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

