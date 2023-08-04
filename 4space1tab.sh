#!/bin/bash
# replaces each 4 spaces at the beginning of lines with a tab.

if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename.c>"
    exit 1
fi

sed -i 's/    /\t/g' "$1"
