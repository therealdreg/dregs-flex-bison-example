# (Dreg's Fork) Flex & Bison example
A compiler and interpreter of a toy language. Using *C++*, *Flex* and *Bison*.

[![Makefile CI](https://github.com/therealdreg/dregs-flex-bison-example/actions/workflows/makefile.yml/badge.svg?branch=main)](https://github.com/therealdreg/dregs-flex-bison-example/actions/workflows/makefile.yml)

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
Use the following command to build the project:
```
make
```
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

## Using the interpreter
The following command executes a While program immediately:
```
./while -i path/to/your/while.program
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

## TO-DO

- More tests (especially for Kokan's work: elvis operator, multiple assignment and "for loop")

## License
This software is licensed under the MIT license. See the *LICENSE* file for details.

## Credits

- Original repo by Gergely Dévai ( @devaigergely81 ): https://github.com/devaigergely81/flex-bison-example
- Fork by Kókai Péter ( @Kokan ): https://github.com/Kokan/flex-bison-example
