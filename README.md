<p align="center">
  <img src="https://user-images.githubusercontent.com/44834632/117828738-c709e200-b27a-11eb-985b-2ef7076bff49.png">
</p>

<h1>Monty</h1>

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project was to create an interpreter for Monty ByteCodes files.

<h2>Monty byte code files</h2>
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```monty

push 0
push 1
push 2
  push 3
                   pall    
push 4
    push 5    
      push    6        
pall

```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```monty

push 0 Push 0 onto the stack
push 1 Push 1 onto the stack

push 2
  push 3
                   pall    


                          
push 4

    push 5    
      push    6        

pall This is the end of our program. Monty is awesome!

```
<h2>Compilation & Output</h2>
The code is compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

Output is printed on `stdout`. 
Any error message are printed on `stderr`

<h2>Usage</h2>
After compiling run:-

`monty file`

where `file` is the path to the file containing Monty byte code

<h2>Files</h2>
Below are files used and their descriptions

| File name                                                                      | Description |
| ---------------------------------------------------------------------------    | ----------- |
|     [monty.c](..//main/monty.c)                                      | Entry point to the program      |
|     [file_handling.c](../mmain/file_handling.c)                      | Contain functions that are involved in reading instructions from the file     |
|     [interpret.c](../main/interpret.c)                              | Contain functions ressponsible for stepping through each instruction and interprating |
|     [instructions.c](../main/instructions.c)                        | Functions responsible for operations perfomed from opcodes instructions |
|     [instructions2.c](../main/instructions2.c)                      | An extension of [instructions.c](../monty/blob/main/instructions.c) |
|     [stack_handling.c](../main/stack_handling.c)                    | Contains functions involved in manipulating elements in a stack, ie pushing, popping ... |
|     [stack_handling2.c](../main/stack_handling2.c)                  | An extension of [stack_handling2.c](../monty/blob/main/stack_handling2.c) functions |
|     [string_functions.c](../main/string_functions.c)                | Contains functions responsible for string handling and validations |
|     [error_handling.c](../main/error_handling.c)                    | Functions responsible for error handling including handling safe exitting on errors |
|     [monty.h](../main/monty.h)                                      | Contains all function prototypes, data structures and header files |
|     [bytecodes](../main/bytecodes)                                  | Folder that contains monty bytecodes test files |

<h1>opcodes</h1>

| File name                                | Description |
| -------------------------------------    | ----------- |
|              push                        |  pushes an element to the stack. Usage: `push <int>` |
|              pall                        |  prints all the values on the stack, starting from the top of the stack. Usage: `pall` |
|              pint                        |  prints the value at the top of the stack, followed by a new line. Usage: `pint` |
|              pop                         |  removes the top element of the stack. Usage: `pop` |
|              swap                        |  swaps the top two elements of the stack. Usage: `swap` |
|              add                         |  adds the top two elements of the stack. Usage: `add`. Result is stored in the second top element of the stack, and the top element is removed |
|              nop                         |  doesn’t do anything. Does absolutely nothing. Usage: `nop` |


<h1>Authors</h1>

Alex Steve [mutheeal.am@gmail.com]

[@candiepih](https://github.com/candiepih)

