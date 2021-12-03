# COT4400 PROJECT3

Author: Xiaohu Sun，U#：23340031
This is a program to solve Tarzan Maze in COT4400 project 3

## Compile

Use the MakeFile to create maze.exe.

```bash
make
```
For testing a large graph please make sure you apply the command to increase stack size in complier!!
I've added that command 
```bash
"-Wl,--stack,0x20000000"
```
into Makefile, but it only works in Windows-based g++
if you are running it in a Linux Lab machine. Please please make sure you are using the command ulimit -s unlimited BEFORE compile it.
```bash
ulimit -s unlimited
```
Everything works fine on my device and I've tested it on USF lab server (-std=c++11) , even large graph it only takes 1-2 seconds to get answers, please leave me a comment if it doesn't really work well.

## Usage


1. Put inputs into input.txt
```bash
ifstream file("input.txt");
```

2. Then run it 
```bash
./maze
```
Some useful information about current graph would be shown in stdout, and if there's a path founded successfully "found it" would be shown in stdout.
```bash
#Eg.
column = x = 981
rows = y = 981
starting x = 1
starting y = 1
found it
```


3. Get results from output.txt
```bash
outputFile.open("output.txt");
```

## If Makefile doesn't work well on your devices
Program tested well in Windows-based VSC and Ubuntu-based VSC and USF lab machines.
If Makefile doesn't really work well, please use the command to compile it manually, it's a simple command that shouldn't take too much time, Thank you!!
```bash
ulimit -s unlimited
g++ -std=c++11 -o maze ./project3.cpp
``` 

## License
[MIT](https://github.com/SohoSon/cot4400p3/blob/5a99a15aad4612ae58c3ca45323037bfdfb30f8f/LICENSE)
