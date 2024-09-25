#!/bin/bash

set -euo pipefail

#################
# BUILD
if [ "$#" -lt 2 ]; then
  echo "Usage: ./build.sh [source1.c source2.c ...] [executable_name]"
  exit 1
fi

# Extract the executable name (last argument)
exeName="${@: -1}"

# Get all the C files (all arguments except the last one)
cFiles=("${@:1:$#-1}")

# Compile C files
gcc "${cFiles[@]}" -o "bin/$exeName"

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful! Executable created: ./bin/$exeName"
else
  echo "Compilation failed!"
  exit 1
fi


#################
# RUN
#################

# Set default executable name if none is provided
# exeName=${1:-program}

# Check if the executable exists
if [ ! -f "bin/$exeName" ]; then
  echo "Executable ./bin/$exeName does not exist."
  exit 1
fi

# Run the executable
echo "Running $exeName..."
./bin/"$exeName"
