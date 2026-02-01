
SumArray.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fc010113          	addi	sp,sp,-64
 1000004:	02112e23          	sw	ra,60(sp)
 1000008:	02012623          	sw	zero,44(sp)
 100000c:	02012423          	sw	zero,40(sp)
 1000010:	02012623          	sw	zero,44(sp)
 1000014:	0280006f          	j	100003c <main+0x3c>
 1000018:	02c12783          	lw	a5,44(sp)
 100001c:	00279793          	slli	a5,a5,0x2
 1000020:	03010713          	addi	a4,sp,48
 1000024:	00f707b3          	add	a5,a4,a5
 1000028:	02c12703          	lw	a4,44(sp)
 100002c:	fce7a823          	sw	a4,-48(a5)
 1000030:	02c12783          	lw	a5,44(sp)
 1000034:	00178793          	addi	a5,a5,1
 1000038:	02f12623          	sw	a5,44(sp)
 100003c:	02c12703          	lw	a4,44(sp)
 1000040:	00900793          	li	a5,9
 1000044:	fce7dae3          	bge	a5,a4,1000018 <main+0x18>
 1000048:	02012623          	sw	zero,44(sp)
 100004c:	0300006f          	j	100007c <main+0x7c>
 1000050:	02c12783          	lw	a5,44(sp)
 1000054:	00279793          	slli	a5,a5,0x2
 1000058:	03010713          	addi	a4,sp,48
 100005c:	00f707b3          	add	a5,a4,a5
 1000060:	fd07a783          	lw	a5,-48(a5)
 1000064:	02812703          	lw	a4,40(sp)
 1000068:	00f707b3          	add	a5,a4,a5
 100006c:	02f12423          	sw	a5,40(sp)
 1000070:	02c12783          	lw	a5,44(sp)
 1000074:	00178793          	addi	a5,a5,1
 1000078:	02f12623          	sw	a5,44(sp)
 100007c:	02c12703          	lw	a4,44(sp)
 1000080:	00900793          	li	a5,9
 1000084:	fce7d6e3          	bge	a5,a4,1000050 <main+0x50>
 1000088:	02812503          	lw	a0,40(sp)
 100008c:	018000ef          	jal	ra,10000a4 <test>
 1000090:	00050793          	mv	a5,a0
 1000094:	00078513          	mv	a0,a5
 1000098:	03c12083          	lw	ra,60(sp)
 100009c:	04010113          	addi	sp,sp,64
 10000a0:	00008067          	ret

010000a4 <test>:
 10000a4:	fe010113          	addi	sp,sp,-32
 10000a8:	00112e23          	sw	ra,28(sp)
 10000ac:	00a12623          	sw	a0,12(sp)
 10000b0:	00c12703          	lw	a4,12(sp)
 10000b4:	02d00793          	li	a5,45
 10000b8:	00f71863          	bne	a4,a5,10000c8 <test+0x24>
 10000bc:	024000ef          	jal	ra,10000e0 <pass>
 10000c0:	00050793          	mv	a5,a0
 10000c4:	00c0006f          	j	10000d0 <test+0x2c>
 10000c8:	024000ef          	jal	ra,10000ec <fail>
 10000cc:	00050793          	mv	a5,a0
 10000d0:	00078513          	mv	a0,a5
 10000d4:	01c12083          	lw	ra,28(sp)
 10000d8:	02010113          	addi	sp,sp,32
 10000dc:	00008067          	ret

010000e0 <pass>:
 10000e0:	00100793          	li	a5,1
 10000e4:	00078513          	mv	a0,a5
 10000e8:	00008067          	ret

010000ec <fail>:
 10000ec:	00000793          	li	a5,0
 10000f0:	00078513          	mv	a0,a5
 10000f4:	00008067          	ret

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
