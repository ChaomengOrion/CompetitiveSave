	.file	"test.cpp"
	.text
	.globl	_Z4testv
	.def	_Z4testv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4testv
_Z4testv:
.LFB10616:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3foov
	.def	_Z3foov;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3foov
_Z3foov:
.LFB10617:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10618:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	call	_Z4testv
	call	_Z4testv
	call	_Z4testv
	call	_Z4testv
	call	_Z4testv
	call	_Z4testv
	leaq	_Z3foov(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	call	*%rax
	movq	-8(%rbp), %rax
	call	*%rax
	movq	-8(%rbp), %rax
	call	*%rax
	movq	-8(%rbp), %rax
	call	*%rax
	movq	-8(%rbp), %rax
	call	*%rax
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
_ZSt12__is_ratio_vISt5ratioILx1ELx1000000000EEE:
	.byte	1
_ZSt12__is_ratio_vISt5ratioILx1ELx1EEE:
	.byte	1
_ZSt12__is_ratio_vISt5ratioILx1000000000ELx1EEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIoEE:
	.byte	1
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0"
