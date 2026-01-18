
fact-short.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fe010113          	addi	sp,sp,-32
 1000004:	00112e23          	sw	ra,28(sp)
 1000008:	00012623          	sw	zero,12(sp)
 100000c:	00012423          	sw	zero,8(sp)
 1000010:	00012623          	sw	zero,12(sp)
 1000014:	0280006f          	j	100003c <main+0x3c>
 1000018:	00c12503          	lw	a0,12(sp)
 100001c:	048000ef          	jal	ra,1000064 <factorial>
 1000020:	00050713          	mv	a4,a0
 1000024:	00812783          	lw	a5,8(sp)
 1000028:	00e787b3          	add	a5,a5,a4
 100002c:	00f12423          	sw	a5,8(sp)
 1000030:	00c12783          	lw	a5,12(sp)
 1000034:	00178793          	addi	a5,a5,1
 1000038:	00f12623          	sw	a5,12(sp)
 100003c:	00c12703          	lw	a4,12(sp)
 1000040:	00300793          	li	a5,3
 1000044:	fce7dae3          	bge	a5,a4,1000018 <main+0x18>
 1000048:	00812503          	lw	a0,8(sp)
 100004c:	090000ef          	jal	ra,10000dc <test>
 1000050:	00050793          	mv	a5,a0
 1000054:	00078513          	mv	a0,a5
 1000058:	01c12083          	lw	ra,28(sp)
 100005c:	02010113          	addi	sp,sp,32
 1000060:	00008067          	ret

01000064 <factorial>:
 1000064:	fd010113          	addi	sp,sp,-48
 1000068:	02112623          	sw	ra,44(sp)
 100006c:	00a12623          	sw	a0,12(sp)
 1000070:	00012e23          	sw	zero,28(sp)
 1000074:	00012c23          	sw	zero,24(sp)
 1000078:	00c12783          	lw	a5,12(sp)
 100007c:	00079663          	bnez	a5,1000088 <factorial+0x24>
 1000080:	00100793          	li	a5,1
 1000084:	0480006f          	j	10000cc <factorial+0x68>
 1000088:	00012e23          	sw	zero,28(sp)
 100008c:	0300006f          	j	10000bc <factorial+0x58>
 1000090:	00c12783          	lw	a5,12(sp)
 1000094:	fff78793          	addi	a5,a5,-1
 1000098:	00078513          	mv	a0,a5
 100009c:	fc9ff0ef          	jal	ra,1000064 <factorial>
 10000a0:	00050713          	mv	a4,a0
 10000a4:	01812783          	lw	a5,24(sp)
 10000a8:	00e787b3          	add	a5,a5,a4
 10000ac:	00f12c23          	sw	a5,24(sp)
 10000b0:	01c12783          	lw	a5,28(sp)
 10000b4:	00178793          	addi	a5,a5,1
 10000b8:	00f12e23          	sw	a5,28(sp)
 10000bc:	01c12703          	lw	a4,28(sp)
 10000c0:	00c12783          	lw	a5,12(sp)
 10000c4:	fcf746e3          	blt	a4,a5,1000090 <factorial+0x2c>
 10000c8:	01812783          	lw	a5,24(sp)
 10000cc:	00078513          	mv	a0,a5
 10000d0:	02c12083          	lw	ra,44(sp)
 10000d4:	03010113          	addi	sp,sp,48
 10000d8:	00008067          	ret

010000dc <test>:
 10000dc:	fe010113          	addi	sp,sp,-32
 10000e0:	00112e23          	sw	ra,28(sp)
 10000e4:	00a12623          	sw	a0,12(sp)
 10000e8:	00c12703          	lw	a4,12(sp)
 10000ec:	00a00793          	li	a5,10
 10000f0:	00f71863          	bne	a4,a5,1000100 <test+0x24>
 10000f4:	024000ef          	jal	ra,1000118 <pass>
 10000f8:	00050793          	mv	a5,a0
 10000fc:	00c0006f          	j	1000108 <test+0x2c>
 1000100:	024000ef          	jal	ra,1000124 <fail>
 1000104:	00050793          	mv	a5,a0
 1000108:	00078513          	mv	a0,a5
 100010c:	01c12083          	lw	ra,28(sp)
 1000110:	02010113          	addi	sp,sp,32
 1000114:	00008067          	ret

01000118 <pass>:
 1000118:	00100793          	li	a5,1
 100011c:	00078513          	mv	a0,a5
 1000120:	00008067          	ret

01000124 <fail>:
 1000124:	00000793          	li	a5,0
 1000128:	00078513          	mv	a0,a5
 100012c:	00008067          	ret

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
