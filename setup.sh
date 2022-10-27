#!/bin/bash
cd src
gcc timernal.c -o timernal
cd ..
mv src/timernal /usr/local/bin
chmod a+x /usr/local/bin/timernal
