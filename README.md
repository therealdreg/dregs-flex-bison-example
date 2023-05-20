# (Dreg's Fork) Flex & Bison example
A compiler and interpreter of a toy language. Using *C++*, *Flex* and *Bison*.

[![Makefile CI](https://github.com/therealdreg/dregs-flex-bison-example/actions/workflows/makefile.yml/badge.svg?branch=main)](https://github.com/therealdreg/dregs-flex-bison-example/actions/workflows/makefile.yml)

**[while.exe](while.exe)** program is in this repo ready to use on Windows!

## The toy language "While language"
The language is called the *While language*. Its different variants often serve educational purposes. 

Features:

- two types (*boolean* and *natural*)
- expressions of these two types
- assignment instruction
- reading/writing from standard input/output
- branching
- looping

Example:
```
program test_write_natural
    natural n
    natural i
    natural f
    natural t
begin
    f := 0
    t := 3
    for i := f to t do
        write(69)
        write(i)
    done
    read(n)
    while not (n = 0) do
        i := n
        while i > 0 do
            write(n)
            i := i-1
        done
        read(n)
    done
end
```

See the *test/\*.ok* files to learn the syntax and semantics of the language.

## Building the project
Make sure you have *g++*, *flex*, *bison* and *nasm* installed. The project was tested with the following versions: g++ 8.3.0 (C++14), flex 2.6.4, bison 3.3.2, nasm 2.14. It might work with other versions as well.

Install deps (Debian based example):
```
sudo apt-get install g++ flex bison nasm build-essential gcc-multilib libfl-dev
```
Use these following commands to build the project (including flex+bison files):
```
make clean
make
```

**WARNING**: **make clean** must be executed **first** to cleanup all generated flex+bison files 

Use the following command to run tests:
```
make test
```
Use the following command to cleanup all generated files:
```
make clean
```

**WARNING**: if you are using a 32bit OS just update Makefile with the following commands:
```
sed -i 's/nasm -f elf32/nasm -felf/g' Makefile
sed -i 's/gcc -m32/gcc/g' Makefile
```

### Building the project without bison+flex installed

Modify Makefile:
```
sed -i 's/flex /# flex /g' Makefile
sed -i 's/bison /# bison /g' Makefile
```

Use the following command to build the project without bison+flex installed:
```
make
```

(For windows just use **mingw32-make.exe**)

Don't use **make clean**, use instead the following command to cleanup all generated files:
```
make no-flex-bison-clean
```

## Using the interpreter
The following command executes a While program immediately:
```
./while -i path/to/your/while.program
```

Example:
```
echo -e "program dregpoc\nbegin\nwrite(69)\nend" > poc.w
./while -i poc.w
```

Output (stdout):
```
69
```

---

powershell + windows example using stdin as input:
```
Write-Output "program dreg`nbegin`nwrite(69)`nend" | .\while.exe -i
```

Output (stdout):
```
69
```

## Using the compiler
The following command compiles a While language program to NASM assembly:
```
./while -c path/to/your/while.program > output.asm
```
To further compile the assembly program to an executable

64 bit OS:
```
nasm -f elf32 output.asm
gcc -m32 output.o io.c -o output
```

32 bit OS:
```
nasm -felf output.asm
gcc output.o io.c -o output
```

To run the executable output:
```
./output
```

Example:
```
echo -e "program dregpoc\nbegin\nwrite(69)\nend" > poc.w
./while -c poc.w
```

Output (stdout):
```
global main
extern write_natural
extern read_natural
extern write_boolean
extern read_boolean

section .bss

section .text
main:
mov eax,69
push eax
call write_natural
add esp,4
xor eax,eax
ret
```

## Changelog

### 2023 May

From @Kokan 's fork:
- add stdin as input when no file-arg
- add a basic CI github actions (makefile.yml...)
- add tests for elvis operator (?), FOR _ := _ TO _ DO _ DONE loop ...
- flex and bison as optional tools to build the project (uploaded pre-generated files)
- windows support + .exe compiled with mingw (deps static)
- by default->64bit OS compiles/assembles 32bit code (added instructions for 32bit OS)
- merged some PR's from original repo by @devaigergely81 
- master to main
- .gitignore, .gitattributes ...
- better README.md 
- add changelog, to-do, credits, new license header...
- ...

## TO-DO

- more tests (especially for Kokan's work: elvis operator, multiple assignment and "for loop")
- improve CI (more github actions, add more distros...)
- improve Makefile (current version sucks)
- clang-format + clang-tidy
- better doc
- docker
- flex+bison+windows instructions: https://github.com/lexxmark/winflexbison + https://osdn.net/projects/mingw/ 
- better support for windows Makefile (make clean etc...)

## License
This software is licensed under the MIT license. See the *LICENSE* file for details.

## Credits

- original repo by Gergely Dévai ( @devaigergely81 ): https://github.com/devaigergely81/flex-bison-example
- fork by Kókai Péter ( @Kokan ): https://github.com/Kokan/flex-bison-example
