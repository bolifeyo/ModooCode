----------------------------
title : MOV (Intel x86/64 assembly instruction)
cat_title : MOV
ref_title : MOV
path : /X86-64 명령어 레퍼런스
----------------------------
#@ MOV

**Move to/from Control Registers**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 20/r\newline{}\newline{}MOV r32, CR0-CR7|MR|N.E.|Valid|Move control register to r32.|
|0F 20/r\newline{}\newline{}MOV r64, CR0-CR7|MR|Valid|N.E.|Move extended control register to r64. |
|REX.R + 0F 20 /0\newline{}\newline{}MOV r64, CR8|MR|Valid |N.E.|Move extended CR8 to r64.\footnote{1}|
|0F 22 /r\newline{}\newline{}MOV CR0-CR7, r32|RM|N.E.|Valid|Move r32 to control register.|
|0F 22 /r\newline{}\newline{}MOV CR0-CR7, r64|RM|Valid |N.E.|Move r64 to extended control register.|
|REX.R + 0F 22 /0\newline{}\newline{}MOV CR8, r64|RM|Valid|N.E.|Move r64 to extended CR8.\footnote{1}|
### NOTE:


1.  MOV CR\htmlonly{*} instructions, except for MOV CR8, are serializing instructions. MOV CR8 is not architecturally defined as a serializing instruction. For more information, see Chapter 8 in Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 3A.

### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Moves the contents of a control register (CR0, CR2, CR3, CR4, or CR8) to a general-purpose register or the contents of a general purpose register to a control register. The operand size for these instructions is always 32 bits in non-64-bit modes, regardless of the operand-size attribute. (See "Control Registers" in Chapter 2 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A, for a detailed description of the flags and fields in the control registers.) This instruction can be executed only when the current privilege level is 0.

At the opcode level, the reg field within the ModR/M byte specifies which of the control registers is loaded or read. The 2 bits in the mod field are ignored. The r/m field specifies the general-purpose register loaded or read. Attempts to reference CR1, CR5, CR6, CR7, and CR9-CR15 result in undefined opcode (#UD) exceptions.

When loading control registers, programs should not attempt to change the reserved bits; that is, always set reserved bits to the value previously read. An attempt to change CR4's reserved bits will cause a general protection fault. Reserved bits in CR0 and CR3 remain clear after any load of those registers; attempts to set them have no impact. On Pentium 4, Intel Xeon and P6 family processors, CR0.ET remains set after any load of CR0; attempts to clear this bit have no impact.

In certain cases, these instructions have the side effect of invalidating entries in the TLBs and the paging-structure caches. See Section 4.10.4.1, "Operations that Invalidate TLBs and Paging-Structure Caches," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A for details.

The following side effects are implementation-specific for the Pentium 4, Intel Xeon, and P6 processor family: when modifying PE or PG in register CR0, or PSE or PAE in register CR4, all TLB entries are flushed, including global entries. Software should not depend on this functionality in all Intel 64 or IA-32 processors.

In 64-bit mode, the instruction's default operation size is 64 bits. The REX.R prefix must be used to access CR8. Use of REX.B permits access to additional registers (R8-R15). Use of the REX.W prefix or 66H prefix is ignored. Use of 



the REX.R prefix to specify a register other than CR8 causes an invalid-opcode exception. See the summary chart at the beginning of this section for encoding data and limits.

If CR4.PCIDE = 1, bit 63 of the source operand to `MOV` to CR3 determines whether the instruction invalidates entries in the TLBs and the paging-structure caches (see Section 4.10.4.1, "Operations that Invalidate TLBs and Paging-Structure Caches," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A). The instruction does not modify bit 63 of CR3, which is reserved and always 0.

See "Changes to Instruction Behavior in VMX Non-Root Operation" in Chapter 25 of the Intel(R) 64 and IA-32 Archi-tectures Software Developer's Manual, Volume 3C, for more information about the behavior of this instruction in VMX non-root operation.


### Operation

```info-verb
DEST <- SRC;
```
### Flags Affected


The OF, SF, ZF, AF, PF, and CF flags are undefined.


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If an attempt is made to write invalid bit combinations in CR0 (such as setting the PG flag to 1 when the PE flag is set to 0, or setting the CD flag to 0 when the NW flag is set to 1).
* If an attempt is made to write a 1 to any reserved bit in CR4.
* If an attempt is made to write 1 to CR4.PCIDE.
* If any of the reserved bits are set in the page-directory pointers table (PDPT) and the loading of a control register causes the PDPT to be loaded into the processor.

#### #UD
* If the LOCK prefix is used.
* If an attempt is made to access CR1, CR5, CR6, or CR7.

### Real-Address Mode Exceptions

#### #GP
* If an attempt is made to write a 1 to any reserved bit in CR4.
* If an attempt is made to write 1 to CR4.PCIDE.
* If an attempt is made to write invalid bit combinations in CR0 (such as setting the PG flag to 1 when the PE flag is set to 0).

#### #UD
* If the LOCK prefix is used.
* If an attempt is made to access CR1, CR5, CR6, or CR7.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* These instructions cannot be executed in virtual-8086 mode.

### Compatibility Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If an attempt is made to write invalid bit combinations in CR0 (such as setting the PG flag to 1 when the PE flag is set to 0, or setting the CD flag to 0 when the NW flag is set to 1).
* If an attempt is made to change CR4.PCIDE from 0 to 1 while CR3[11:0] != 000H.
* If an attempt is made to clear CR0.PG[bit 31] while CR4.PCIDE = 1.
* If an attempt is made to write a 1 to any reserved bit in CR3.
* If an attempt is made to leave IA-32e mode by clearing CR4.PAE[bit 5].

#### #UD
* If the LOCK prefix is used.
* If an attempt is made to access CR1, CR5, CR6, or CR7.

### 64-Bit Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If an attempt is made to write invalid bit combinations in CR0 (such as setting the PG flag to 1 when the PE flag is set to 0, or setting the CD flag to 0 when the NW flag is set to 1).
* If an attempt is made to change CR4.PCIDE from 0 to 1 while CR3[11:0] != 000H.
* If an attempt is made to clear CR0.PG[bit 31].
* If an attempt is made to write a 1 to any reserved bit in CR4.
* If an attempt is made to write a 1 to any reserved bit in CR8.
* If an attempt is made to write a 1 to any reserved bit in CR3.
* If an attempt is made to leave IA-32e mode by clearing CR4.PAE[bit 5].

#### #UD
* If the LOCK prefix is used.
* If an attempt is made to access CR1, CR5, CR6, or CR7.
* If the REX.R prefix is used to specify a register other than CR8.
