#!/bin/bash

# Builds the App Binary
mkdir -p build
cmake -B build
cmake --build build
