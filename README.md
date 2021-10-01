# Compiler for Kauta (CPy)
This repo contains a compiler for Kauta(CPy), an object oriented programming language similar to C++ and Python, created for the coursework of Compilers, Monsoon, 2019 under Prof. Suresh Purini at IIIT Hyderabad.

## Language Design
The details about the language design can be found in `Language-Design.pdf`.

## Pre-requisites
- flex
- bison
- llvm-6.0-dev

All of these can be installed using the command
```
sudo apt install <package-name>
```

## Files

- scanner.l - It contains scanner of the compiler which will recognize tokens using regular expressions.  
- parser.y - It contains parser of the compiler. It checks macro-syntax of language.  
- ast.h - It contains declarations of all classes used in construction of AST.
- ast.cpp - It contains all functions of classes, statements, methods required for AST.
- visitor.cpp - It contains visitor functions to print the AST and generate the code.
- codegen.cpp - It contains code generator functions for all classes, expression and statements.

## Compile and run

- Just change the input file in `test.sh` and run
```
bash test.sh
```
### Detailed steps
- To compile the code, use 'make' command.
- To run decaf compiler on `input.txt` file,  use command `./a.out < input.txt`
- redirect output of above file in an output file. 
- Run output file using `lli-6.0`.
- Example: 
    - `make`
    - `./a.out < input.txt > out`
    - `lli-6.0 out`

## Project description

### Scanner 

- `flex` scanner for scanning tokens.
- Detects tokens using regular expressions.

### Parser

- `bison` parser for generating AST
- Implemented using Context Free Grammar

### Code generation

- Implemented using `Visitor design pattern`

