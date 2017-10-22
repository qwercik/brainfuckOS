#!/usr/bin/env python3

import sys

if len(sys.argv) != 2:
    raise SystemExit('Incorrect usage. Use: ' + sys.argv[0] + ' <image.img>')

image_filename = sys.argv[1]
content = ''

with open(image_filename, 'rb') as f:
    content = bytearray(f.read())
    bytes_to_append = 512 - len(content) % 512
    for i in range(bytes_to_append):
        content.append(0)

with open(image_filename, 'wb') as f:
    f.write(content)
    print('Successfully aligned to sector')
