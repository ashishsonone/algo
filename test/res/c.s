	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$buf+4, bufp1
	movl	bufp0, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	bufp0, %eax
	movl	bufp1, %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	movl	bufp1, %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	leave
	ret
