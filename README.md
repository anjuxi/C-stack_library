# C语言 栈库 (C Stack Library)

一个用C语言实现的通用栈（Stack）数据结构库，采用链表实现，支持多种常用操作。

## 功能特性

- **基础操作**：创建栈、销毁栈、入栈、出栈、获取栈顶元素
- **状态查询**：判断栈是否为空、获取栈大小
- **扩展功能**：
  - 清空栈（保留栈结构）
  - 打印栈中所有元素
  - 获取并出栈（组合操作）
  - 复制栈
  - 反转栈
  - 交换栈顶两个元素

## 数据结构

```c
typedef int Data;  // 数据类型，可自定义修改

struct Node {
    Data node_data;      // 节点数据
    struct Node* next;   // 指向下一个节点
};

struct Stack {
    Node* top;      // 栈顶指针
    int size;       // 栈中元素个数
};
```

## API 接口

### 生命周期管理

| 函数                              | 说明                 |
| --------------------------------- | -------------------- |
| `Stack* creatStack(void)`         | 创建一个空栈         |
| `void destroyStack(Stack* stack)` | 销毁栈，释放所有内存 |
| `void clear(Stack* stack)`        | 清空栈（保留栈结构） |

### 基本操作

| 函数                                | 说明                   |
| ----------------------------------- | ---------------------- |
| `void push(Stack* stack, Data val)` | 入栈：将元素压入栈顶   |
| `void pop(Stack* stack)`            | 出栈：移除栈顶元素     |
| `Data top(Stack* stack)`            | 获取栈顶元素（不出栈） |
| `bool isEmpty(Stack* stack)`        | 判断栈是否为空         |
| `int stackSize(Stack* stack)`       | 获取栈中元素个数       |

### 扩展操作

| 函数                                      | 说明                                    |
| ----------------------------------------- | --------------------------------------- |
| `void showStack(Stack* stack)`            | 从栈顶到栈底打印栈中所有元素            |
| `Data getAndPop(Stack* stack)`            | 获取栈顶元素并出栈                      |
| `void copyStack(Stack* src, Stack* dest)` | 复制栈（从src复制到dest，dest会被清空） |
| `void reverseStack(Stack* stack)`         | 反转栈                                  |
| `void swapTopTwo(Stack* stack)`           | 交换栈顶两个元素                        |

## 使用示例

```c
#include <stdio.h>

int main() {
    // 创建一个栈
    Stack* stack = creatStack();

    // 入栈
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // 打印栈
    showStack(stack);  // 输出: 3 2 1

    // 获取栈顶元素
    Data val = top(stack);  // val = 3

    // 出栈
    pop(stack);

    // 获取栈大小
    int size = stackSize(stack);  // size = 2

    // 销毁栈
    destroyStack(stack);

    return 0;
}
```

## 编译运行

```bash
# 使用 GCC 编译
gcc -o stack_demo 栈库.cpp

# 运行
./stack_demo
```

## 依赖

[![C](https://img.shields.io/badge/C-99%2F11-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![C++](https://img.shields.io/badge/C%2B%2B-Compatible-blue.svg)](https://isocpp.org/)

- 标准C库：
  - `<stdio.h>` - 标准输入输出
  - `<stdlib.h>` - 内存分配
  - `<stdbool.h>` - 布尔类型支持（C99）

## 自定义数据类型

默认栈存储的数据类型为 `int`，如需修改，请更改代码中的类型定义：

```c
typedef int Data;  // 将 int 改为所需类型，如 double、char* 等
```

## 许可证

本项目开源，可自由使用和修改。

---

## 作者信息

**谙弆悕博士（Ailan Anjuxi）**

- 📧 邮箱：[anjuxi.ME@outlook.com](mailto:anjuxi.ME@outlook.com)
- 📞 SIP电话：[sip:anjuxi@sip.linphone.org](sip:anjuxi@sip.linphone.org)
