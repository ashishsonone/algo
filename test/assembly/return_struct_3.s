	.file	"return_struct_3.c"
# GNU C (Ubuntu/Linaro 4.6.4-1ubuntu1) version 4.6.4 (i686-linux-gnu)
#	compiled by GNU C version 4.6.4, GMP version 5.0.5, MPFR version 3.1.1-p2, MPC version 0.9
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultilib . -imultiarch i386-linux-gnu
# return_struct_3.c -mtune=generic -march=i686 -fverbose-asm
# -fstack-protector
# options enabled:  -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcommon -fdelete-null-pointer-checks -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -ffunction-cse -fgcse-lm
# -fident -finline-functions-called-once -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -fmath-errno -fmerge-debug-strings
# -fmove-loop-invariants -fpcc-struct-return -fpeephole
# -fprefetch-loop-arrays -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fshow-column
# -fsigned-zeros -fsplit-ivs-in-unroller -fstack-protector
# -fstrict-volatile-bitfields -ftrapping-math -ftree-cselim -ftree-forwprop
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-slp-vectorize
# -ftree-vect-loop-version -funit-at-a-time -funwind-tables
# -fvect-cost-model -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
# -m96bit-long-double -maccumulate-outgoing-args -malign-stringops
# -mfancy-math-387 -mfp-ret-in-387 -mglibc -mieee-fp -mno-red-zone
# -mno-sse4 -mpush-args -msahf -mtls-direct-seg-refs

# Compiler executable checksum: 1cff4e5e7ee708e4b090de2d6a1996f2

	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	pushl	%ebp	#
	movl	%esp, %ebp	#,
	subl	$16, %esp	#,
	movl	$21, -4(%ebp)	#, x
	movl	-4(%ebp), %eax	# x, D.1238
	leave
	ret
.LFE0:
	.size	f, .-f
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushl	%ebp	#
	movl	%esp, %ebp	#,
	subl	$16, %esp	#,
	call	f	#
	movl	%eax, -4(%ebp)	# tmp60, a
	leave
	ret
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.4-1ubuntu1) 4.6.4"
	.section	.note.GNU-stack,"",@progbits
