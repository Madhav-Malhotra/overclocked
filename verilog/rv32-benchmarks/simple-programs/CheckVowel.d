
CheckVowel.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <main>:
 1000000:	fd010113          	addi	sp,sp,-48
 1000004:	02112623          	sw	ra,44(sp)
 1000008:	00012e23          	sw	zero,28(sp)
 100000c:	00012c23          	sw	zero,24(sp)
 1000010:	010007b7          	lui	a5,0x1000
 1000014:	1e87a603          	lw	a2,488(a5) # 10001e8 <fail+0xc>
 1000018:	1e878713          	addi	a4,a5,488
 100001c:	00472683          	lw	a3,4(a4)
 1000020:	1e878713          	addi	a4,a5,488
 1000024:	00872703          	lw	a4,8(a4)
 1000028:	00c12223          	sw	a2,4(sp)
 100002c:	00d12423          	sw	a3,8(sp)
 1000030:	00e12623          	sw	a4,12(sp)
 1000034:	1e878793          	addi	a5,a5,488
 1000038:	00c7c783          	lbu	a5,12(a5)
 100003c:	00f10823          	sb	a5,16(sp)
 1000040:	000108a3          	sb	zero,17(sp)
 1000044:	00010923          	sb	zero,18(sp)
 1000048:	000109a3          	sb	zero,19(sp)
 100004c:	00010a23          	sb	zero,20(sp)
 1000050:	00010aa3          	sb	zero,21(sp)
 1000054:	00010b23          	sb	zero,22(sp)
 1000058:	00010ba3          	sb	zero,23(sp)
 100005c:	00012e23          	sw	zero,28(sp)
 1000060:	10c0006f          	j	100016c <main+0x16c>
 1000064:	01c12783          	lw	a5,28(sp)
 1000068:	02010713          	addi	a4,sp,32
 100006c:	00f707b3          	add	a5,a4,a5
 1000070:	fe47c703          	lbu	a4,-28(a5)
 1000074:	06100793          	li	a5,97
 1000078:	0cf70e63          	beq	a4,a5,1000154 <main+0x154>
 100007c:	01c12783          	lw	a5,28(sp)
 1000080:	02010713          	addi	a4,sp,32
 1000084:	00f707b3          	add	a5,a4,a5
 1000088:	fe47c703          	lbu	a4,-28(a5)
 100008c:	04100793          	li	a5,65
 1000090:	0cf70263          	beq	a4,a5,1000154 <main+0x154>
 1000094:	01c12783          	lw	a5,28(sp)
 1000098:	02010713          	addi	a4,sp,32
 100009c:	00f707b3          	add	a5,a4,a5
 10000a0:	fe47c703          	lbu	a4,-28(a5)
 10000a4:	06500793          	li	a5,101
 10000a8:	0af70663          	beq	a4,a5,1000154 <main+0x154>
 10000ac:	01c12783          	lw	a5,28(sp)
 10000b0:	02010713          	addi	a4,sp,32
 10000b4:	00f707b3          	add	a5,a4,a5
 10000b8:	fe47c703          	lbu	a4,-28(a5)
 10000bc:	04500793          	li	a5,69
 10000c0:	08f70a63          	beq	a4,a5,1000154 <main+0x154>
 10000c4:	01c12783          	lw	a5,28(sp)
 10000c8:	02010713          	addi	a4,sp,32
 10000cc:	00f707b3          	add	a5,a4,a5
 10000d0:	fe47c703          	lbu	a4,-28(a5)
 10000d4:	06900793          	li	a5,105
 10000d8:	06f70e63          	beq	a4,a5,1000154 <main+0x154>
 10000dc:	01c12783          	lw	a5,28(sp)
 10000e0:	02010713          	addi	a4,sp,32
 10000e4:	00f707b3          	add	a5,a4,a5
 10000e8:	fe47c703          	lbu	a4,-28(a5)
 10000ec:	04900793          	li	a5,73
 10000f0:	06f70263          	beq	a4,a5,1000154 <main+0x154>
 10000f4:	01c12783          	lw	a5,28(sp)
 10000f8:	02010713          	addi	a4,sp,32
 10000fc:	00f707b3          	add	a5,a4,a5
 1000100:	fe47c703          	lbu	a4,-28(a5)
 1000104:	06f00793          	li	a5,111
 1000108:	04f70663          	beq	a4,a5,1000154 <main+0x154>
 100010c:	01c12783          	lw	a5,28(sp)
 1000110:	02010713          	addi	a4,sp,32
 1000114:	00f707b3          	add	a5,a4,a5
 1000118:	fe47c703          	lbu	a4,-28(a5)
 100011c:	04f00793          	li	a5,79
 1000120:	02f70a63          	beq	a4,a5,1000154 <main+0x154>
 1000124:	01c12783          	lw	a5,28(sp)
 1000128:	02010713          	addi	a4,sp,32
 100012c:	00f707b3          	add	a5,a4,a5
 1000130:	fe47c703          	lbu	a4,-28(a5)
 1000134:	07500793          	li	a5,117
 1000138:	00f70e63          	beq	a4,a5,1000154 <main+0x154>
 100013c:	01c12783          	lw	a5,28(sp)
 1000140:	02010713          	addi	a4,sp,32
 1000144:	00f707b3          	add	a5,a4,a5
 1000148:	fe47c703          	lbu	a4,-28(a5)
 100014c:	05500793          	li	a5,85
 1000150:	00f71863          	bne	a4,a5,1000160 <main+0x160>
 1000154:	01812783          	lw	a5,24(sp)
 1000158:	00178793          	addi	a5,a5,1
 100015c:	00f12c23          	sw	a5,24(sp)
 1000160:	01c12783          	lw	a5,28(sp)
 1000164:	00178793          	addi	a5,a5,1
 1000168:	00f12e23          	sw	a5,28(sp)
 100016c:	01c12703          	lw	a4,28(sp)
 1000170:	01300793          	li	a5,19
 1000174:	eee7d8e3          	bge	a5,a4,1000064 <main+0x64>
 1000178:	01812503          	lw	a0,24(sp)
 100017c:	018000ef          	jal	ra,1000194 <test>
 1000180:	00050793          	mv	a5,a0
 1000184:	00078513          	mv	a0,a5
 1000188:	02c12083          	lw	ra,44(sp)
 100018c:	03010113          	addi	sp,sp,48
 1000190:	00008067          	ret

01000194 <test>:
 1000194:	fe010113          	addi	sp,sp,-32
 1000198:	00112e23          	sw	ra,28(sp)
 100019c:	00a12623          	sw	a0,12(sp)
 10001a0:	00c12703          	lw	a4,12(sp)
 10001a4:	00300793          	li	a5,3
 10001a8:	00f71863          	bne	a4,a5,10001b8 <test+0x24>
 10001ac:	024000ef          	jal	ra,10001d0 <pass>
 10001b0:	00050793          	mv	a5,a0
 10001b4:	00c0006f          	j	10001c0 <test+0x2c>
 10001b8:	024000ef          	jal	ra,10001dc <fail>
 10001bc:	00050793          	mv	a5,a0
 10001c0:	00078513          	mv	a0,a5
 10001c4:	01c12083          	lw	ra,28(sp)
 10001c8:	02010113          	addi	sp,sp,32
 10001cc:	00008067          	ret

010001d0 <pass>:
 10001d0:	00100793          	li	a5,1
 10001d4:	00078513          	mv	a0,a5
 10001d8:	00008067          	ret

010001dc <fail>:
 10001dc:	00000793          	li	a5,0
 10001e0:	00078513          	mv	a0,a5
 10001e4:	00008067          	ret

Disassembly of section .rodata:

010001e8 <_end-0xe18>:
 10001e8:	63656843          	fmadd.d	fa6,fa0,fs6,fa2,unknown
 10001ec:	776f566b          	0x776f566b
 10001f0:	6c65                	lui	s8,0x19
 10001f2:	0a21                	addi	s4,s4,8
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
