#!/bin/bash
cd src
gcc timer.c -o timer
cd ..
mv src/timer /usr/local/bin
chmod a+x /usr/local/bin/timer
