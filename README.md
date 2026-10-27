# C Stack Library

A general-purpose stack library in C. It's linked-list based and covers the usual stack operations plus a few extras.

## Features

- Basic operations: create, destroy, push, pop, peek
- Status checks: isEmpty, size
- Extras:
  - Clear the stack (keep the stack object)
  - Print all elements
  - Pop and return in one call
  - Copy a stack
  - Reverse a stack
  - Swap the top two elements

## Data Structure

```c
typedef int Data;  // element type; change as needed

struct Node {
    Data node_data;      // node data
    struct Node* next;   // next node
};

struct Stack {
    Node* top;      // top pointer
    int size;       // element count
};
```

## API

### Lifecycle

| Function | Description |
| ------------------------------- | -------------------- |
| `Stack* creatStack(void)` | Create an empty stack |
| `void destroyStack(Stack* stack)` | Destroy the stack and free all memory |
| `void clear(Stack* stack)` | Clear the stack (keep the stack object) |

### Basic operations

| Function | Description |
| ----------------------------------- | ---------------------- |
| `void push(Stack* stack, Data val)` | Push onto the top |
| `void pop(Stack* stack)` | Remove the top element |
| `Data top(Stack* stack)` | Get the top element (without popping) |
| `bool isEmpty(Stack* stack)` | Check whether the stack is empty |
| `int stackSize(Stack* stack)` | Get the element count |

### Extra operations

| Function | Description |
| ----------------------------------------- | --------------------------------------- |
| `void showStack(Stack* stack)` | Print elements from top to bottom |
| `Data getAndPop(Stack* stack)` | Get the top element and pop it |
| `void copyStack(Stack* src, Stack* dest)` | Copy src into dest (dest is cleared first) |
| `void reverseStack(Stack* stack)` | Reverse the stack |
| `void swapTopTwo(Stack* stack)` | Swap the top two elements |

## Example

```c
#include <stdio.h>

int main() {
    // Create a stack
    Stack* stack = creatStack();

    // Push
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Print
    showStack(stack);  // prints: 3 2 1

    // Peek
    Data val = top(stack);  // val = 3

    // Pop
    pop(stack);

    // Size
    int size = stackSize(stack);  // size = 2

    // Destroy
    destroyStack(stack);

    return 0;
}
```

## Build and Run

```bash
# GCC
gcc -o stack_demo stack.c

# Run
./stack_demo
```

Use your actual source filename if it differs from `stack.c`.

## Dependencies

[![C](https://img.shields.io/badge/C-99%2F11-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![C++](https://img.shields.io/badge/C%2B%2B-Compatible-blue.svg)](https://isocpp.org/)

- Standard C library:
  - `<stdio.h>` — input/output
  - `<stdlib.h>` — memory allocation
  - `<stdbool.h>` — boolean type (C99)

## Custom Element Type

By default the stack stores `int`. To store something else, change the typedef:

```c
typedef int Data;  // change to double, char*, etc.
```

## License

Open source. Use and modify freely.

---

## Author

**Dr. Ailan Anjuxi (谙弆悕)**

- Email: [anjuxi.ME@outlook.com](mailto:anjuxi.ME@outlook.com)
- SIP: [sip:anjuxi@sip.linphone.org](sip:anjuxi@sip.linphone.org)
