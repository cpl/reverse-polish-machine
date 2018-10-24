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


#include <stdlib.h>


typedef struct stack {
    size_t SP;
    signed long* data;
    size_t cap;
} stack;



// NEW(stack*, size_t), allocate a stack of given size.
#define NEW(s, n) ((s = (stack*)malloc(sizeof(stack))),\
                   (s -> cap = n),                     \
                   (s -> SP = 0),                      \
                   (s -> data = (signed long*)calloc(n, sizeof(signed long))))

// CLEAR(stack*), reset the stack pointer.
#define CLEAR(s)   (s -> SP = 0)

// ISEMPTY(stack*), check if the stack pointer is 0.
#define ISEMPTY(s) (((s -> SP) == 0))

// PUSH(stack*, size_t), put a given value on the top of the stack
#define PUSH(s, v) (s -> data[(s -> SP)++] = (signed long)v)

// POP(s), return the value on top of the stack, or 0 if the stack is empty.
#define POP(s) (ISEMPTY(s) ? 0 : s -> data[--(s -> SP)])

// ISFULL(s), check if the stack is full
#define ISFULL(s) (((s -> SP) == (s -> cap)))
