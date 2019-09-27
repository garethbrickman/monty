# Monty ByteCode Interpreter

### Description

Monty ByteCode Interpreter is a program for interpreting Monty ByteCode files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## Examples:
```c
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
```c
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```
### Functionality

-   The program must be invoked with only two arguments: monty <path containing .m file>
-  The monty program runs the bytecodes line by line and stop if either:
   - it executed properly every line of the file
   - it finds an error in the file
   - an error occured

## Installation

All of the c files in this repository, as well as the header file, must be present in a directory and compiled with "monty" as the name of the executable.

Example:
```c
gcc *.c -o monty
```

## Usage Example

```c
$ monty <file.m>
```

## Contributing
Any pull requests for adding features or fixing bugs will be manually reviewed. Please see the AUTHORS file for contact information.

## License

This code is in the public domain (see [UNLICENSE](https://github.com/brenns10/lsh/blob/master/UNLICENSE) for more details). This means you can use, modify, and distribute it without any restriction. We appreciate, but don't require, acknowledgement in derivative works.