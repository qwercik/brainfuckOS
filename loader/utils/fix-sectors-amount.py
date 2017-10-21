#!/usr/bin/env python3

import sys

flag = b'\xEE\xFF\xC0\x00'
image_file = ''

if len(sys.argv) != 2:
    raise SystemExit('Incorrect usage. Use ' + sys.argv[0] + 'file.img')

image_file = sys.argv[1]

content = ''

with open(image_file, 'rb') as f:
    content = f.read()

    sectors_to_read = int(len(content) / 512) - 1

    if sectors_to_read < 1 or sectors_to_read > 255:
        raise SystemExit('Incorrect image file. It\'s too big or too small')

    opcode = b'\xB0' + bytearray([sectors_to_read]) + b'\x90\x90'
    
    if flag in content:
        content = content.replace(flag, opcode)
        print('Successfully fixed sectors to read amount')
    else:
        raise SystemExit('Incorrect image file. Does it include', str(flag), 'flag?')

with open(image_file, 'wb') as f:
    f.write(content)
