# COT4400 PROJECT3

Author: Xiaohu Sun，U#：23340031
This is a program to solve Tarzan Maze in COT4400 project 3

## Compile

Use the MakeFile to create maze.exe.

```bash
make
```
For testing large graph please make sure you apply the command to increase stack size in complier!!
I've add that command 
```bash
"-Wl,--stack,0x20000000"
```
into Makefile, but it only works in Windows based g++
if you are running it in a Linux Lab machines. Please please make sure you are using the command ulimit -s unlimited BEFORE complie it.
```bash
ulimit -s unlimited
```
Everything works fine in my device and I've tested it in USF lab server, even large graph it only takes 1-2 seconds to get answers, please leave me a comment if it doesn't really work well.

## Usage


Put inputs into input.txt
```bash
ifstream file("input.txt");
```

Then run it 
```bash
./maze.exe
```

Get results from output.txt
```bash
outputFile.open("output.txt");
```

## If Makefile doesn't work well on your devices
Program tested well in Windows based VSC and Ubuntu based VSC and USF lab machine.
If Makefile doesn't really work well, please use command complie it manually, it's a simple command shoudn't take too much time, Thank you!!
```bash
g++ -o maze ./project3.cpp
``` 

