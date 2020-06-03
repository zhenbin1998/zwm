#!/bin/bash
set -e
# 1. Build binary.
make zwm

# 2. Run.
#
# We need to specify the full path to Xephyr, as otherwise xinit will not
# interpret it as an argument specifying the X server to launch and will launch
# the default X server instead.
XEPHYR=$(whereis -b Xephyr | cut -f2 -d' ')
xinit ./xinitrc -- \
    "$XEPHYR" \
        :99 \
        -ac \
        -screen 800x600 \
        -host-cursor