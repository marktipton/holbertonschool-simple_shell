#!/bin/bash

# Check if the file contains a line that starts with '#include "'
if ! grep -q '^#include "' "$1"; then
    # Prompt the user to enter the name of the header file
    read -p "Enter the name of the header file: " header
    # Check if the entered header file name ends with '.h'
    if [[ $header != *.h ]]; then
        # If it doesn't, set it to 'main.h'
        header="main.h"
    fi
    # Add the new line to the top of the file
    sed -i "1i#include \"$header\"" "$1"
fi
