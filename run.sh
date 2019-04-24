#!/bin/bash

echo Start compiling
g++ -std=c++14 main.cpp -o proj1
echo Compiled successfully

echo Start running
./proj1
echo Completed successfully