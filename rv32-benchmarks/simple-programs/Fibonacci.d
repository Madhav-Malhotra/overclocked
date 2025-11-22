
Fibonacci.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fe010113          	addi	sp,sp,-32
 1000004:	00112e23          	sw	ra,28(sp)
 1000008:	00a00513          	li	a0,10
 100000c:	024000ef          	jal	ra,1000030 <fib>
 1000010:	00a12623          	sw	a0,12(sp)
 1000014:	00c12503          	lw	a0,12(sp)
 1000018:	07c000ef          	jal	ra,1000094 <test>
 100001c:	00050793          	mv	a5,a0
 1000020:	00078513          	mv	a0,a5
 1000024:	01c12083          	lw	ra,28(sp)
 1000028:	02010113          	addi	sp,sp,32
 100002c:	00008067          	ret

01000030 <fib>:
 1000030:	fe010113          	addi	sp,sp,-32
 1000034:	00112e23          	sw	ra,28(sp)
 1000038:	00812c23          	sw	s0,24(sp)
 100003c:	00a12623          	sw	a0,12(sp)
 1000040:	00c12703          	lw	a4,12(sp)
 1000044:	00100793          	li	a5,1
 1000048:	00e7c663          	blt	a5,a4,1000054 <fib+0x24>
 100004c:	00c12783          	lw	a5,12(sp)
 1000050:	0300006f          	j	1000080 <fib+0x50>
 1000054:	00c12783          	lw	a5,12(sp)
 1000058:	fff78793          	addi	a5,a5,-1
 100005c:	00078513          	mv	a0,a5
 1000060:	fd1ff0ef          	jal	ra,1000030 <fib>
 1000064:	00050413          	mv	s0,a0
 1000068:	00c12783          	lw	a5,12(sp)
 100006c:	ffe78793          	addi	a5,a5,-2
 1000070:	00078513          	mv	a0,a5
 1000074:	fbdff0ef          	jal	ra,1000030 <fib>
 1000078:	00050793          	mv	a5,a0
 100007c:	00f407b3          	add	a5,s0,a5
 1000080:	00078513          	mv	a0,a5
 1000084:	01c12083          	lw	ra,28(sp)
 1000088:	01812403          	lw	s0,24(sp)
 100008c:	02010113          	addi	sp,sp,32
 1000090:	00008067          	ret

01000094 <test>:
 1000094:	fe010113          	addi	sp,sp,-32
 1000098:	00112e23          	sw	ra,28(sp)
 100009c:	00a12623          	sw	a0,12(sp)
 10000a0:	00c12703          	lw	a4,12(sp)
 10000a4:	03700793          	li	a5,55
 10000a8:	00f71863          	bne	a4,a5,10000b8 <test+0x24>
 10000ac:	024000ef          	jal	ra,10000d0 <pass>
 10000b0:	00050793          	mv	a5,a0
 10000b4:	00c0006f          	j	10000c0 <test+0x2c>
 10000b8:	024000ef          	jal	ra,10000dc <fail>
 10000bc:	00050793          	mv	a5,a0
 10000c0:	00078513          	mv	a0,a5
 10000c4:	01c12083          	lw	ra,28(sp)
 10000c8:	02010113          	addi	sp,sp,32
 10000cc:	00008067          	ret

010000d0 <pass>:
 10000d0:	00100793          	li	a5,1
 10000d4:	00078513          	mv	a0,a5
 10000d8:	00008067          	ret

010000dc <fail>:
 10000dc:	00000793          	li	a5,0
 10000e0:	00078513          	mv	a0,a5
 10000e4:	00008067          	ret

Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347          	fmsub.d	ft6,ft6,ft4,ft7,rmm
   4:	2820                	fld	fs0,80(s0)
   6:	29554e47          	fmsub.s	ft8,fa0,fs5,ft5,rmm
   a:	3820                	fld	fs0,112(s0)
   c:	332e                	fld	ft6,232(sp)
   e:	302e                	fld	ft0,232(sp)
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <main-0xffffec>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8
