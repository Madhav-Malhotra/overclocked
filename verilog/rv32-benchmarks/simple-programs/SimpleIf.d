
SimpleIf.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fe010113          	addi	sp,sp,-32
 1000004:	00112e23          	sw	ra,28(sp)
 1000008:	00300793          	li	a5,3
 100000c:	00f12623          	sw	a5,12(sp)
 1000010:	00200793          	li	a5,2
 1000014:	00f12423          	sw	a5,8(sp)
 1000018:	00012223          	sw	zero,4(sp)
 100001c:	00c12703          	lw	a4,12(sp)
 1000020:	00400793          	li	a5,4
 1000024:	00e7cc63          	blt	a5,a4,100003c <main+0x3c>
 1000028:	00c12703          	lw	a4,12(sp)
 100002c:	00812783          	lw	a5,8(sp)
 1000030:	00f707b3          	add	a5,a4,a5
 1000034:	00f12623          	sw	a5,12(sp)
 1000038:	0140006f          	j	100004c <main+0x4c>
 100003c:	00c12703          	lw	a4,12(sp)
 1000040:	00812783          	lw	a5,8(sp)
 1000044:	40f707b3          	sub	a5,a4,a5
 1000048:	00f12623          	sw	a5,12(sp)
 100004c:	00c12703          	lw	a4,12(sp)
 1000050:	00812783          	lw	a5,8(sp)
 1000054:	00f707b3          	add	a5,a4,a5
 1000058:	00f12223          	sw	a5,4(sp)
 100005c:	00412503          	lw	a0,4(sp)
 1000060:	018000ef          	jal	ra,1000078 <test>
 1000064:	00050793          	mv	a5,a0
 1000068:	00078513          	mv	a0,a5
 100006c:	01c12083          	lw	ra,28(sp)
 1000070:	02010113          	addi	sp,sp,32
 1000074:	00008067          	ret

01000078 <test>:
 1000078:	fe010113          	addi	sp,sp,-32
 100007c:	00112e23          	sw	ra,28(sp)
 1000080:	00a12623          	sw	a0,12(sp)
 1000084:	00c12703          	lw	a4,12(sp)
 1000088:	00700793          	li	a5,7
 100008c:	00f71863          	bne	a4,a5,100009c <test+0x24>
 1000090:	024000ef          	jal	ra,10000b4 <pass>
 1000094:	00050793          	mv	a5,a0
 1000098:	00c0006f          	j	10000a4 <test+0x2c>
 100009c:	024000ef          	jal	ra,10000c0 <fail>
 10000a0:	00050793          	mv	a5,a0
 10000a4:	00078513          	mv	a0,a5
 10000a8:	01c12083          	lw	ra,28(sp)
 10000ac:	02010113          	addi	sp,sp,32
 10000b0:	00008067          	ret

010000b4 <pass>:
 10000b4:	00100793          	li	a5,1
 10000b8:	00078513          	mv	a0,a5
 10000bc:	00008067          	ret

010000c0 <fail>:
 10000c0:	00000793          	li	a5,0
 10000c4:	00078513          	mv	a0,a5
 10000c8:	00008067          	ret

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
