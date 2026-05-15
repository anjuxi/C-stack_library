#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// ——————————————————————————————————————————————#
typedef int Data;//为了方便修改数据类型。

// 栈节点结构体。
struct Node {
    Data node_data;      // 节点存放的数据。
    struct Node* next;   // 指向下一个节点的指针。
};
typedef struct Node Node;   // 为 struct Node 取别名为 Node。

// 栈结构体（包含栈顶指针和节点数量）
struct Stack {
    Node* top;      // 栈顶指针
    int size;       // 栈中元素个数
};
typedef struct Stack Stack; // 为 struct Stack 取别名为 Stack。
// ——————————————————————————————————————————————#


// ——————————————————————————————————————————————#
Stack* creatStack(void);            // 创建一个空栈
void destroyStack(Stack* stack);    // 销毁栈，释放所有内存

// 基本操作
void push(Stack* stack, Data val);  // 入栈：将元素压入栈顶
void pop(Stack* stack);             // 出栈：移除栈顶元素
Data top(Stack* stack);             // 获取栈顶元素（不出栈）
bool isEmpty(Stack* stack);         // 判断栈是否为空
int stackSize(Stack* stack);        // 获取栈中元素个数
void clear(Stack* stack);           // 清空栈（保留栈结构）

// 扩展操作
void showStack(Stack* stack);       // 从栈顶到栈底打印栈中所有元素
Data getAndPop(Stack* stack);       // 获取栈顶元素并出栈
void copyStack(Stack* src, Stack* dest); // 复制栈（从src复制到dest，dest会被清空）
void reverseStack(Stack* stack);    // 反转栈
void swapTopTwo(Stack* stack);      // 交换栈顶两个元素
// ——————————————————————————————————————————————#


int main() {
    // 创建一个栈
    Stack* stack = creatStack();

    // 入栈测试
    printf("入栈：1, 2, 3, 4, 5\n");
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("当前栈（从栈顶到栈底）：");
    showStack(stack);
    printf("\n栈大小：%d\n", stackSize(stack));

    // 查看栈顶元素
    printf("\n栈顶元素：%d\n", top(stack));
    printf("栈大小：%d\n", stackSize(stack));

    // 出栈测试
    printf("\n出栈一次\n");
    pop(stack);
    printf("当前栈（从栈顶到栈底）：");
    showStack(stack);
    printf("\n栈大小：%d\n", stackSize(stack));

    // 获取并出栈测试
    printf("\n获取并出栈：%d\n", getAndPop(stack));
    printf("当前栈（从栈顶到栈底）：");
    showStack(stack);
    printf("\n栈大小：%d\n", stackSize(stack));

    // 交换栈顶两个元素
    printf("\n交换栈顶两个元素\n");
    swapTopTwo(stack);
    printf("当前栈（从栈顶到栈底）：");
    showStack(stack);
    printf("\n栈大小：%d\n", stackSize(stack));

    // 复制栈测试
    printf("\n复制栈到stack2\n");
    Stack* stack2 = creatStack();
    copyStack(stack, stack2);
    printf("stack2（从栈顶到栈底）：");
    showStack(stack2);
    printf("\nstack2大小：%d\n", stackSize(stack2));

    // 反转栈测试
    printf("\n反转stack2\n");
    reverseStack(stack2);
    printf("stack2反转后（从栈顶到栈底）：");
    showStack(stack2);
    printf("\nstack2大小：%d\n", stackSize(stack2));

    // 清空栈测试
    printf("\n清空stack\n");
    clear(stack);
    printf("stack是否为空：%s\n", isEmpty(stack) ? "是" : "否");
    printf("stack大小：%d\n", stackSize(stack));

    // 销毁栈
    destroyStack(stack);
    destroyStack(stack2);
    printf("\n栈已销毁\n");

    return 0;
}

// ========== 函数实现 ==========

// 创建一个空栈
Stack* creatStack(void) {
    Stack* stack = (Stack*)calloc(1, sizeof(Stack));
    if (!stack) {
        return NULL;   // 内存分配失败，返回 NULL
    }
    stack->top = NULL;  // 栈顶初始为空
    stack->size = 0;    // 元素个数初始为0
    return stack;
}

// 销毁栈，释放所有内存
void destroyStack(Stack* stack) {
    if (!stack) {
        return;
    }
    clear(stack);       // 先清空所有节点
    free(stack);        // 释放栈结构本身
}

// 入栈：将元素压入栈顶
void push(Stack* stack, Data val) {
    if (!stack) {
        return;
    }
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (!newNode) {
        return;    // 分配失败，直接返回
    }
    newNode->node_data = val;       // 设置节点数据
    newNode->next = stack->top;     // 新节点指向原来的栈顶
    stack->top = newNode;           // 更新栈顶指针
    stack->size++;                  // 元素个数加1
}

// 出栈：移除栈顶元素
void pop(Stack* stack) {
    if (!stack || !stack->top) {
        return;    // 栈为空，直接返回
    }
    Node* temp = stack->top;        // 保存当前栈顶
    stack->top = stack->top->next;  // 栈顶指向下一个节点
    free(temp);                     // 释放原栈顶节点
    stack->size--;                  // 元素个数减1
}

// 获取栈顶元素（不出栈）
Data top(Stack* stack) {
    if (!stack || !stack->top) {
        return 0;   // 栈为空，返回0（可以根据需要修改）
    }
    return stack->top->node_data;
}

// 判断栈是否为空
bool isEmpty(Stack* stack) {
    if (!stack) {
        return true;
    }
    return stack->size == 0;
}

// 获取栈中元素个数
int stackSize(Stack* stack) {
    if (!stack) {
        return 0;
    }
    return stack->size;
}

// 清空栈（保留栈结构）
void clear(Stack* stack) {
    if (!stack) {
        return;
    }
    while (stack->top) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->size = 0;
}

// 从栈顶到栈底打印栈中所有元素
void showStack(Stack* stack) {
    if (!stack || !stack->top) {
        return;
    }
    Node* curNode = stack->top;
    while (curNode) {
        printf("%d ", curNode->node_data);
        curNode = curNode->next;
    }
}

// 获取栈顶元素并出栈
Data getAndPop(Stack* stack) {
    if (!stack || !stack->top) {
        return 0;   // 栈为空，返回0
    }
    Data val = stack->top->node_data;
    pop(stack);
    return val;
}

// 复制栈（从src复制到dest，dest会被清空）
void copyStack(Stack* src, Stack* dest) {
    if (!src || !dest) {
        return;
    }
    clear(dest);    // 先清空目标栈

    // 使用临时栈来保持顺序
    Stack* tempStack = creatStack();
    if (!tempStack) {
        return;
    }

    // 将src的元素压入临时栈（顺序反转）
    Node* curNode = src->top;
    while (curNode) {
        push(tempStack, curNode->node_data);
        curNode = curNode->next;
    }

    // 将临时栈的元素压入dest（恢复顺序）
    while (!isEmpty(tempStack)) {
        push(dest, getAndPop(tempStack));
    }

    destroyStack(tempStack);
}

// 反转栈
void reverseStack(Stack* stack) {
    if (!stack || !stack->top || !stack->top->next) {
        return;    // 空栈或只有一个元素，无需反转
    }

    // 使用临时栈来反转
    Stack* tempStack = creatStack();
    if (!tempStack) {
        return;
    }

    // 将所有元素移到临时栈（顺序反转）
    while (!isEmpty(stack)) {
        push(tempStack, getAndPop(stack));
    }

    // 将临时栈的元素移回原栈
    while (!isEmpty(tempStack)) {
        push(stack, getAndPop(tempStack));
    }

    destroyStack(tempStack);
}

// 交换栈顶两个元素
void swapTopTwo(Stack* stack) {
    if (!stack || stack->size < 2) {
        return;    // 栈中元素不足2个，无法交换
    }

    // 获取栈顶两个元素
    Data first = getAndPop(stack);
    Data second = getAndPop(stack);

    // 交换顺序后压回栈
    push(stack, first);
    push(stack, second);
}
