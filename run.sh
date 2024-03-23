#!/bin/bash

# Check if the first parameter is "build"
if [ "$1" = "build" ]; then
    # Run build script
    ./build.sh
fi

# Check if executable exists
if [ -f ./build/app/app ]; then
    # Run the executable
    ./build/app/app
else
    echo "Executable 'app'  not found. Make sure your build was successful."
fi

