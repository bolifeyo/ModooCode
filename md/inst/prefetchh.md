----------------------------
title : PREFETCHh (Intel x86/64 assembly instruction)
cat_title : PREFETCHh
ref_title : PREFETCHh
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PREFETCHh

**Prefetch Data Into Caches**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 18 /1|PREFETCHT0 \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |M|Valid|Valid|Move data from m8 closer to the processor using T0 hint.|
|0F 18 /2|PREFETCHT1 \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |M|Valid|Valid|Move data from m8 closer to the processor using T1 hint.|
|0F 18 /3|PREFETCHT2 \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |M|Valid|Valid|Move data from m8 closer to the processor using T2 hint.|
|0F 18 /0|PREFETCHNTA \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |M|Valid|Valid|Move data from m8 closer to the processor using NTA hint.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Fetches the line of data from memory that contains the byte specified with the source operand to a location in the cache hierarchy specified by a locality hint:

*  T0 (temporal data)--prefetch data into all levels of the cache hierarchy.

*  T1 (temporal data with respect to first level cache misses)--prefetch data into level 2 cache and higher.

*  T2 (temporal data with respect to second level cache misses)--prefetch data into level 3 cache and higher, or an implementation-specific choice.

*  NTA (non-temporal data with respect to all cache levels)--prefetch data into non-temporal cache structure and into a location close to the processor, minimizing cache pollution.

The source operand is a byte memory location. (The locality hints are encoded into the machine level instruction using bits 3 through 5 of the ModR/M byte.)

If the line selected is already present in the cache hierarchy at a level closer to the processor, no data movement occurs. Prefetches from uncacheable or WC memory are ignored.

The `PREFETCHh` instruction is merely a hint and does not affect program behavior. If executed, this instruction moves data closer to the processor in anticipation of future use.

The implementation of prefetch locality hints is implementation-dependent, and can be overloaded or ignored by a processor implementation. The amount of data prefetched is also processor implementation-dependent. It will, however, be a minimum of 32 bytes. Additional details of the implementation-dependent locality hints are described in Section 7.4 of Intel(R) 64 and IA-32 Architectures Optimization Reference Manual.

It should be noted that processors are free to speculatively fetch and cache data from system memory regions that are assigned a memory-type that permits speculative reads (that is, the WB, WC, and WT memory types). A `PREFETCHh` instruction is considered a hint to this speculative behavior. Because this speculative fetching can occur at any time and is not tied to instruction execution, a `PREFETCHh` instruction is not ordered with respect to the fence instructions (MFENCE, `SFENCE`, and LFENCE) or locked memory references. A `PREFETCHh` instruction is also unordered with respect to `CLFLUSH` and `CLFLUSHOPT` instructions, other `PREFETCHh` instructions, or any other general instruction. It is ordered with respect to serializing instructions such as `CPUID`, `WRMSR`, `OUT`, and `MOV` CR.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
FETCH (m8);
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
void _mm_prefetch(char *p, int i)
The argument "*p" gives the address of the byte (and corresponding cache line) to be prefetched. The value "i" gives a constant (_MM_HINT_T0, _MM_HINT_T1, _MM_HINT_T2, or _MM_HINT_NTA) that specifies the type of prefetch operation to be performed.
```
### Numeric Exceptions


None.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

