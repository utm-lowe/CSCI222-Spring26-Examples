
binding:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 e1 2f 00 00 	mov    0x2fe1(%rip),%rax        # 3ff0 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	push   0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 9c 2f 00 00    	jmp    *0x2f9c(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)
    1030:	f3 0f 1e fa          	endbr64
    1034:	68 00 00 00 00       	push   $0x0
    1039:	e9 e2 ff ff ff       	jmp    1020 <_init+0x20>
    103e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64
    1044:	ff 25 8e 2f 00 00    	jmp    *0x2f8e(%rip)        # 3fd8 <__cxa_finalize@GLIBC_2.2.5>
    104a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001050 <__stack_chk_fail@plt>:
    1050:	f3 0f 1e fa          	endbr64
    1054:	ff 25 76 2f 00 00    	jmp    *0x2f76(%rip)        # 3fd0 <__stack_chk_fail@GLIBC_2.4>
    105a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	45 31 c0             	xor    %r8d,%r8d
    1076:	31 c9                	xor    %ecx,%ecx
    1078:	48 8d 3d d9 00 00 00 	lea    0xd9(%rip),%rdi        # 1158 <main>
    107f:	ff 15 5b 2f 00 00    	call   *0x2f5b(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.34>
    1085:	f4                   	hlt
    1086:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    108d:	00 00 00 

0000000000001090 <deregister_tm_clones>:
    1090:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4010 <__TMC_END__>
    1097:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4010 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 3e 2f 00 00 	mov    0x2f3e(%rip),%rax        # 3fe8 <_ITM_deregisterTMCloneTable@Base>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmp    *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	ret
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
    10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
    10c7:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4010 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    $1,%rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 0d 2f 00 00 	mov    0x2f0d(%rip),%rax        # 3ff8 <_ITM_registerTMCloneTable@Base>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmp    *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	ret
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
    1100:	f3 0f 1e fa          	endbr64
    1104:	80 3d 05 2f 00 00 00 	cmpb   $0x0,0x2f05(%rip)        # 4010 <__TMC_END__>
    110b:	75 2b                	jne    1138 <__do_global_dtors_aux+0x38>
    110d:	55                   	push   %rbp
    110e:	48 83 3d c2 2e 00 00 	cmpq   $0x0,0x2ec2(%rip)        # 3fd8 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00 
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0c                	je     1127 <__do_global_dtors_aux+0x27>
    111b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4008 <__dso_handle>
    1122:	e8 19 ff ff ff       	call   1040 <__cxa_finalize@plt>
    1127:	e8 64 ff ff ff       	call   1090 <deregister_tm_clones>
    112c:	c6 05 dd 2e 00 00 01 	movb   $0x1,0x2edd(%rip)        # 4010 <__TMC_END__>
    1133:	5d                   	pop    %rbp
    1134:	c3                   	ret
    1135:	0f 1f 00             	nopl   (%rax)
    1138:	c3                   	ret
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <frame_dummy>:
    1140:	f3 0f 1e fa          	endbr64
    1144:	e9 77 ff ff ff       	jmp    10c0 <register_tm_clones>

0000000000001149 <_Z1fv>:
        return 8;
    }
};


int f() {
    1149:	f3 0f 1e fa          	endbr64
    114d:	55                   	push   %rbp
    114e:	48 89 e5             	mov    %rsp,%rbp
    return 42;
    1151:	b8 2a 00 00 00       	mov    $0x2a,%eax
}
    1156:	5d                   	pop    %rbp
    1157:	c3                   	ret

0000000000001158 <main>:

int main() {
    1158:	f3 0f 1e fa          	endbr64
    115c:	55                   	push   %rbp
    115d:	48 89 e5             	mov    %rsp,%rbp
    1160:	48 83 ec 20          	sub    $0x20,%rsp
    1164:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    116b:	00 00 
    116d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1171:	31 c0                	xor    %eax,%eax
    f();
    1173:	e8 d1 ff ff ff       	call   1149 <_Z1fv>

    A a;
    1178:	48 8d 05 09 2c 00 00 	lea    0x2c09(%rip),%rax        # 3d88 <_ZTV1A+0x10>
    117f:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    a.f();
    1183:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    1187:	48 89 c7             	mov    %rax,%rdi
    118a:	e8 99 00 00 00       	call   1228 <_ZN1A1fEv>
    a.g();
    118f:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    1193:	48 89 c7             	mov    %rax,%rdi
    1196:	e8 a1 00 00 00       	call   123c <_ZN1A1gEv>

    B b;
    119b:	48 8d 05 ce 2b 00 00 	lea    0x2bce(%rip),%rax        # 3d70 <_ZTV1B+0x10>
    11a2:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    b.f();
    11a6:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    11aa:	48 89 c7             	mov    %rax,%rdi
    11ad:	e8 9e 00 00 00       	call   1250 <_ZN1B1fEv>
    b.g();
    11b2:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    11b6:	48 89 c7             	mov    %rax,%rdi
    11b9:	e8 a6 00 00 00       	call   1264 <_ZN1B1gEv>

    A *p;
    p = &a;
    11be:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    11c2:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    p->f();
    11c6:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    11ca:	48 8b 00             	mov    (%rax),%rax
    11cd:	48 8b 10             	mov    (%rax),%rdx
    11d0:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    11d4:	48 89 c7             	mov    %rax,%rdi
    11d7:	ff d2                	call   *%rdx
    p->g();
    11d9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    11dd:	48 89 c7             	mov    %rax,%rdi
    11e0:	e8 57 00 00 00       	call   123c <_ZN1A1gEv>
    p = &b;
    11e5:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    11e9:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    p->f();
    11ed:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    11f1:	48 8b 00             	mov    (%rax),%rax
    11f4:	48 8b 10             	mov    (%rax),%rdx
    11f7:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    11fb:	48 89 c7             	mov    %rax,%rdi
    11fe:	ff d2                	call   *%rdx
    p->g();
    1200:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1204:	48 89 c7             	mov    %rax,%rdi
    1207:	e8 30 00 00 00       	call   123c <_ZN1A1gEv>
    120c:	b8 00 00 00 00       	mov    $0x0,%eax
    1211:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    1215:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    121c:	00 00 
    121e:	74 05                	je     1225 <main+0xcd>
    1220:	e8 2b fe ff ff       	call   1050 <__stack_chk_fail@plt>
    1225:	c9                   	leave
    1226:	c3                   	ret
    1227:	90                   	nop

0000000000001228 <_ZN1A1fEv>:
    virtual int f() {
    1228:	f3 0f 1e fa          	endbr64
    122c:	55                   	push   %rbp
    122d:	48 89 e5             	mov    %rsp,%rbp
    1230:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
        return 0;
    1234:	b8 00 00 00 00       	mov    $0x0,%eax
    }
    1239:	5d                   	pop    %rbp
    123a:	c3                   	ret
    123b:	90                   	nop

000000000000123c <_ZN1A1gEv>:
    int g() {
    123c:	f3 0f 1e fa          	endbr64
    1240:	55                   	push   %rbp
    1241:	48 89 e5             	mov    %rsp,%rbp
    1244:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
        return 7;
    1248:	b8 07 00 00 00       	mov    $0x7,%eax
    }
    124d:	5d                   	pop    %rbp
    124e:	c3                   	ret
    124f:	90                   	nop

0000000000001250 <_ZN1B1fEv>:
    int f() override {
    1250:	f3 0f 1e fa          	endbr64
    1254:	55                   	push   %rbp
    1255:	48 89 e5             	mov    %rsp,%rbp
    1258:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
        return 42;
    125c:	b8 2a 00 00 00       	mov    $0x2a,%eax
    }
    1261:	5d                   	pop    %rbp
    1262:	c3                   	ret
    1263:	90                   	nop

0000000000001264 <_ZN1B1gEv>:
    int g() {
    1264:	f3 0f 1e fa          	endbr64
    1268:	55                   	push   %rbp
    1269:	48 89 e5             	mov    %rsp,%rbp
    126c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
        return 8;
    1270:	b8 08 00 00 00       	mov    $0x8,%eax
    }
    1275:	5d                   	pop    %rbp
    1276:	c3                   	ret

Disassembly of section .fini:

0000000000001278 <_fini>:
    1278:	f3 0f 1e fa          	endbr64
    127c:	48 83 ec 08          	sub    $0x8,%rsp
    1280:	48 83 c4 08          	add    $0x8,%rsp
    1284:	c3                   	ret
