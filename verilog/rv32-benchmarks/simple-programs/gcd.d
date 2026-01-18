
gcd.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fe010113          	addi	sp,sp,-32
 1000004:	00112e23          	sw	ra,28(sp)
 1000008:	000017b7          	lui	a5,0x1
 100000c:	80078793          	addi	a5,a5,-2048 # 800 <main-0xfff800>
 1000010:	00f12623          	sw	a5,12(sp)
 1000014:	07c00793          	li	a5,124
 1000018:	00f12423          	sw	a5,8(sp)
 100001c:	00c12783          	lw	a5,12(sp)
 1000020:	41f7d793          	srai	a5,a5,0x1f
 1000024:	00c12703          	lw	a4,12(sp)
 1000028:	00f74733          	xor	a4,a4,a5
 100002c:	40f707b3          	sub	a5,a4,a5
 1000030:	00f12623          	sw	a5,12(sp)
 1000034:	00812783          	lw	a5,8(sp)
 1000038:	41f7d793          	srai	a5,a5,0x1f
 100003c:	00812703          	lw	a4,8(sp)
 1000040:	00f74733          	xor	a4,a4,a5
 1000044:	40f707b3          	sub	a5,a4,a5
 1000048:	00f12423          	sw	a5,8(sp)
 100004c:	0340006f          	j	1000080 <main+0x80>
 1000050:	00c12703          	lw	a4,12(sp)
 1000054:	00812783          	lw	a5,8(sp)
 1000058:	00e7dc63          	bge	a5,a4,1000070 <main+0x70>
 100005c:	00c12703          	lw	a4,12(sp)
 1000060:	00812783          	lw	a5,8(sp)
 1000064:	40f707b3          	sub	a5,a4,a5
 1000068:	00f12623          	sw	a5,12(sp)
 100006c:	0140006f          	j	1000080 <main+0x80>
 1000070:	00812703          	lw	a4,8(sp)
 1000074:	00c12783          	lw	a5,12(sp)
 1000078:	40f707b3          	sub	a5,a4,a5
 100007c:	00f12423          	sw	a5,8(sp)
 1000080:	00c12703          	lw	a4,12(sp)
 1000084:	00812783          	lw	a5,8(sp)
 1000088:	fcf714e3          	bne	a4,a5,1000050 <main+0x50>
 100008c:	00c12503          	lw	a0,12(sp)
 1000090:	018000ef          	jal	ra,10000a8 <test>
 1000094:	00050793          	mv	a5,a0
 1000098:	00078513          	mv	a0,a5
 100009c:	01c12083          	lw	ra,28(sp)
 10000a0:	02010113          	addi	sp,sp,32
 10000a4:	00008067          	ret

010000a8 <test>:
 10000a8:	ff010113          	addi	sp,sp,-16
 10000ac:	00a12623          	sw	a0,12(sp)
 10000b0:	00c12783          	lw	a5,12(sp)
 10000b4:	ffc78793          	addi	a5,a5,-4
 10000b8:	0017b793          	seqz	a5,a5
 10000bc:	0ff7f793          	andi	a5,a5,255
 10000c0:	00078513          	mv	a0,a5
 10000c4:	01010113          	addi	sp,sp,16
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
