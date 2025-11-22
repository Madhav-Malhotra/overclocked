
BubbleSort.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fd010113          	addi	sp,sp,-48
 1000004:	02112623          	sw	ra,44(sp)
 1000008:	010007b7          	lui	a5,0x1000
 100000c:	2487a883          	lw	a7,584(a5) # 1000248 <fail+0xc>
 1000010:	24878713          	addi	a4,a5,584
 1000014:	00472803          	lw	a6,4(a4)
 1000018:	24878713          	addi	a4,a5,584
 100001c:	00872503          	lw	a0,8(a4)
 1000020:	24878713          	addi	a4,a5,584
 1000024:	00c72583          	lw	a1,12(a4)
 1000028:	24878713          	addi	a4,a5,584
 100002c:	01072603          	lw	a2,16(a4)
 1000030:	24878713          	addi	a4,a5,584
 1000034:	01472683          	lw	a3,20(a4)
 1000038:	24878713          	addi	a4,a5,584
 100003c:	01872703          	lw	a4,24(a4)
 1000040:	24878793          	addi	a5,a5,584
 1000044:	01c7a783          	lw	a5,28(a5)
 1000048:	01112023          	sw	a7,0(sp)
 100004c:	01012223          	sw	a6,4(sp)
 1000050:	00a12423          	sw	a0,8(sp)
 1000054:	00b12623          	sw	a1,12(sp)
 1000058:	00c12823          	sw	a2,16(sp)
 100005c:	00d12a23          	sw	a3,20(sp)
 1000060:	00e12c23          	sw	a4,24(sp)
 1000064:	00f12e23          	sw	a5,28(sp)
 1000068:	00010793          	mv	a5,sp
 100006c:	00800593          	li	a1,8
 1000070:	00078513          	mv	a0,a5
 1000074:	024000ef          	jal	ra,1000098 <bubble_srt>
 1000078:	00010793          	mv	a5,sp
 100007c:	00078513          	mv	a0,a5
 1000080:	124000ef          	jal	ra,10001a4 <test>
 1000084:	00050793          	mv	a5,a0
 1000088:	00078513          	mv	a0,a5
 100008c:	02c12083          	lw	ra,44(sp)
 1000090:	03010113          	addi	sp,sp,48
 1000094:	00008067          	ret

01000098 <bubble_srt>:
 1000098:	fe010113          	addi	sp,sp,-32
 100009c:	00a12623          	sw	a0,12(sp)
 10000a0:	00b12423          	sw	a1,8(sp)
 10000a4:	00012e23          	sw	zero,28(sp)
 10000a8:	0e40006f          	j	100018c <bubble_srt+0xf4>
 10000ac:	00100793          	li	a5,1
 10000b0:	00f12c23          	sw	a5,24(sp)
 10000b4:	0b80006f          	j	100016c <bubble_srt+0xd4>
 10000b8:	01812703          	lw	a4,24(sp)
 10000bc:	400007b7          	lui	a5,0x40000
 10000c0:	fff78793          	addi	a5,a5,-1 # 3fffffff <_end+0x3effefff>
 10000c4:	00f707b3          	add	a5,a4,a5
 10000c8:	00279793          	slli	a5,a5,0x2
 10000cc:	00c12703          	lw	a4,12(sp)
 10000d0:	00f707b3          	add	a5,a4,a5
 10000d4:	0007a703          	lw	a4,0(a5)
 10000d8:	01812783          	lw	a5,24(sp)
 10000dc:	00279793          	slli	a5,a5,0x2
 10000e0:	00c12683          	lw	a3,12(sp)
 10000e4:	00f687b3          	add	a5,a3,a5
 10000e8:	0007a783          	lw	a5,0(a5)
 10000ec:	06e7da63          	bge	a5,a4,1000160 <bubble_srt+0xc8>
 10000f0:	01812703          	lw	a4,24(sp)
 10000f4:	400007b7          	lui	a5,0x40000
 10000f8:	fff78793          	addi	a5,a5,-1 # 3fffffff <_end+0x3effefff>
 10000fc:	00f707b3          	add	a5,a4,a5
 1000100:	00279793          	slli	a5,a5,0x2
 1000104:	00c12703          	lw	a4,12(sp)
 1000108:	00f707b3          	add	a5,a4,a5
 100010c:	0007a783          	lw	a5,0(a5)
 1000110:	00f12a23          	sw	a5,20(sp)
 1000114:	01812783          	lw	a5,24(sp)
 1000118:	00279793          	slli	a5,a5,0x2
 100011c:	00c12703          	lw	a4,12(sp)
 1000120:	00f70733          	add	a4,a4,a5
 1000124:	01812683          	lw	a3,24(sp)
 1000128:	400007b7          	lui	a5,0x40000
 100012c:	fff78793          	addi	a5,a5,-1 # 3fffffff <_end+0x3effefff>
 1000130:	00f687b3          	add	a5,a3,a5
 1000134:	00279793          	slli	a5,a5,0x2
 1000138:	00c12683          	lw	a3,12(sp)
 100013c:	00f687b3          	add	a5,a3,a5
 1000140:	00072703          	lw	a4,0(a4)
 1000144:	00e7a023          	sw	a4,0(a5)
 1000148:	01812783          	lw	a5,24(sp)
 100014c:	00279793          	slli	a5,a5,0x2
 1000150:	00c12703          	lw	a4,12(sp)
 1000154:	00f707b3          	add	a5,a4,a5
 1000158:	01412703          	lw	a4,20(sp)
 100015c:	00e7a023          	sw	a4,0(a5)
 1000160:	01812783          	lw	a5,24(sp)
 1000164:	00178793          	addi	a5,a5,1
 1000168:	00f12c23          	sw	a5,24(sp)
 100016c:	00812703          	lw	a4,8(sp)
 1000170:	01c12783          	lw	a5,28(sp)
 1000174:	40f707b3          	sub	a5,a4,a5
 1000178:	01812703          	lw	a4,24(sp)
 100017c:	f2f74ee3          	blt	a4,a5,10000b8 <bubble_srt+0x20>
 1000180:	01c12783          	lw	a5,28(sp)
 1000184:	00178793          	addi	a5,a5,1
 1000188:	00f12e23          	sw	a5,28(sp)
 100018c:	01c12703          	lw	a4,28(sp)
 1000190:	00812783          	lw	a5,8(sp)
 1000194:	f0f74ce3          	blt	a4,a5,10000ac <bubble_srt+0x14>
 1000198:	00000013          	nop
 100019c:	02010113          	addi	sp,sp,32
 10001a0:	00008067          	ret

010001a4 <test>:
 10001a4:	fd010113          	addi	sp,sp,-48
 10001a8:	02112623          	sw	ra,44(sp)
 10001ac:	00a12623          	sw	a0,12(sp)
 10001b0:	00100793          	li	a5,1
 10001b4:	00f12c23          	sw	a5,24(sp)
 10001b8:	00012e23          	sw	zero,28(sp)
 10001bc:	00012e23          	sw	zero,28(sp)
 10001c0:	04c0006f          	j	100020c <test+0x68>
 10001c4:	01c12783          	lw	a5,28(sp)
 10001c8:	00279793          	slli	a5,a5,0x2
 10001cc:	00c12703          	lw	a4,12(sp)
 10001d0:	00f707b3          	add	a5,a4,a5
 10001d4:	0007a703          	lw	a4,0(a5)
 10001d8:	01c12783          	lw	a5,28(sp)
 10001dc:	00178793          	addi	a5,a5,1
 10001e0:	00279793          	slli	a5,a5,0x2
 10001e4:	00c12683          	lw	a3,12(sp)
 10001e8:	00f687b3          	add	a5,a3,a5
 10001ec:	0007a783          	lw	a5,0(a5)
 10001f0:	00e7d863          	bge	a5,a4,1000200 <test+0x5c>
 10001f4:	048000ef          	jal	ra,100023c <fail>
 10001f8:	00050793          	mv	a5,a0
 10001fc:	0240006f          	j	1000220 <test+0x7c>
 1000200:	01c12783          	lw	a5,28(sp)
 1000204:	00178793          	addi	a5,a5,1
 1000208:	00f12e23          	sw	a5,28(sp)
 100020c:	01c12703          	lw	a4,28(sp)
 1000210:	00600793          	li	a5,6
 1000214:	fae7d8e3          	bge	a5,a4,10001c4 <test+0x20>
 1000218:	018000ef          	jal	ra,1000230 <pass>
 100021c:	00050793          	mv	a5,a0
 1000220:	00078513          	mv	a0,a5
 1000224:	02c12083          	lw	ra,44(sp)
 1000228:	03010113          	addi	sp,sp,48
 100022c:	00008067          	ret

01000230 <pass>:
 1000230:	00100793          	li	a5,1
 1000234:	00078513          	mv	a0,a5
 1000238:	00008067          	ret

0100023c <fail>:
 100023c:	00000793          	li	a5,0
 1000240:	00078513          	mv	a0,a5
 1000244:	00008067          	ret

Disassembly of section .rodata:

01000248 <_end-0xdb8>:
 1000248:	000c                	0xc
 100024a:	0000                	unimp
 100024c:	0009                	c.nop	2
 100024e:	0000                	unimp
 1000250:	0004                	0x4
 1000252:	0000                	unimp
 1000254:	00000063          	beqz	zero,1000254 <fail+0x18>
 1000258:	0078                	addi	a4,sp,12
 100025a:	0000                	unimp
 100025c:	0001                	nop
 100025e:	0000                	unimp
 1000260:	00000003          	lb	zero,0(zero) # 0 <main-0x1000000>
 1000264:	000a                	c.slli	zero,0x2
	...

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
