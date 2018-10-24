/* MIT License

Copyright (c) 2018 Alexandru-Paul Copil

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <stdio.h>
#include <string.h>
#include "stack.h"


void print_stack(stack* s) {
    for(size_t index = 0; index < s -> SP; index++)
        printf("%08lu: %ld\n", index, s -> data[index]);
}


int main(int argc, char* argv[]) {

    // Create new stack
    stack* STACK; NEW(STACK, argc+10);

    // Reverse polish notation
    for(int index = 1; index < argc; index++) {
        switch(*argv[index]) {
            // Operations
            case '+':
                PUSH(STACK, POP(STACK) + POP(STACK)); break;
            case '-':
                PUSH(STACK, POP(STACK) - POP(STACK)); break;
            case 'x':
                PUSH(STACK, POP(STACK) * POP(STACK)); break;
            case '/':
                PUSH(STACK, POP(STACK) / POP(STACK)); break;
            // New value
            default:
                PUSH(STACK, strtol(argv[index], NULL, 10));

        } // switch
    } // for

    // Print stack
    print_stack(STACK);

    return 0;
}
