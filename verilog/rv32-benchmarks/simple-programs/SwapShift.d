
SwapShift.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fe010113          	addi	sp,sp,-32
 1000004:	00112e23          	sw	ra,28(sp)
 1000008:	00500793          	li	a5,5
 100000c:	00f12223          	sw	a5,4(sp)
 1000010:	00900793          	li	a5,9
 1000014:	00f12023          	sw	a5,0(sp)
 1000018:	00012783          	lw	a5,0(sp)
 100001c:	00279793          	slli	a5,a5,0x2
 1000020:	00f12023          	sw	a5,0(sp)
 1000024:	00412783          	lw	a5,4(sp)
 1000028:	4017d793          	srai	a5,a5,0x1
 100002c:	00f12223          	sw	a5,4(sp)
 1000030:	00410793          	addi	a5,sp,4
 1000034:	00f12623          	sw	a5,12(sp)
 1000038:	00010793          	mv	a5,sp
 100003c:	00f12423          	sw	a5,8(sp)
 1000040:	00812583          	lw	a1,8(sp)
 1000044:	00c12503          	lw	a0,12(sp)
 1000048:	044000ef          	jal	ra,100008c <swap>
 100004c:	00c12783          	lw	a5,12(sp)
 1000050:	0007a783          	lw	a5,0(a5)
 1000054:	00f12223          	sw	a5,4(sp)
 1000058:	00812783          	lw	a5,8(sp)
 100005c:	0007a783          	lw	a5,0(a5)
 1000060:	00f12023          	sw	a5,0(sp)
 1000064:	00412703          	lw	a4,4(sp)
 1000068:	00012783          	lw	a5,0(sp)
 100006c:	00f707b3          	add	a5,a4,a5
 1000070:	00078513          	mv	a0,a5
 1000074:	058000ef          	jal	ra,10000cc <test>
 1000078:	00050793          	mv	a5,a0
 100007c:	00078513          	mv	a0,a5
 1000080:	01c12083          	lw	ra,28(sp)
 1000084:	02010113          	addi	sp,sp,32
 1000088:	00008067          	ret

0100008c <swap>:
 100008c:	fe010113          	addi	sp,sp,-32
 1000090:	00a12623          	sw	a0,12(sp)
 1000094:	00b12423          	sw	a1,8(sp)
 1000098:	00c12783          	lw	a5,12(sp)
 100009c:	0007a783          	lw	a5,0(a5)
 10000a0:	00f12e23          	sw	a5,28(sp)
 10000a4:	00812783          	lw	a5,8(sp)
 10000a8:	0007a703          	lw	a4,0(a5)
 10000ac:	00c12783          	lw	a5,12(sp)
 10000b0:	00e7a023          	sw	a4,0(a5)
 10000b4:	00812783          	lw	a5,8(sp)
 10000b8:	01c12703          	lw	a4,28(sp)
 10000bc:	00e7a023          	sw	a4,0(a5)
 10000c0:	00000013          	nop
 10000c4:	02010113          	addi	sp,sp,32
 10000c8:	00008067          	ret

010000cc <test>:
 10000cc:	fe010113          	addi	sp,sp,-32
 10000d0:	00112e23          	sw	ra,28(sp)
 10000d4:	00a12623          	sw	a0,12(sp)
 10000d8:	00c12703          	lw	a4,12(sp)
 10000dc:	02600793          	li	a5,38
 10000e0:	00f71863          	bne	a4,a5,10000f0 <test+0x24>
 10000e4:	024000ef          	jal	ra,1000108 <pass>
 10000e8:	00050793          	mv	a5,a0
 10000ec:	00c0006f          	j	10000f8 <test+0x2c>
 10000f0:	024000ef          	jal	ra,1000114 <fail>
 10000f4:	00050793          	mv	a5,a0
 10000f8:	00078513          	mv	a0,a5
 10000fc:	01c12083          	lw	ra,28(sp)
 1000100:	02010113          	addi	sp,sp,32
 1000104:	00008067          	ret

01000108 <pass>:
 1000108:	00100793          	li	a5,1
 100010c:	00078513          	mv	a0,a5
 1000110:	00008067          	ret

01000114 <fail>:
 1000114:	00000793          	li	a5,0
 1000118:	00078513          	mv	a0,a5
 100011c:	00008067          	ret

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
