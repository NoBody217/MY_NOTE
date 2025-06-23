#include <stdio.h>
#include <string.h> // 用于 strlen (如果需要) 和 strcspn (在main中移除换行符时)
#include <ctype.h>  // 用于 isalnum

#define MAX_SIZE 200 // 假设的最大表达式长度和栈大小

char s1[MAX_SIZE]; // 存储中缀表达式
char s2[MAX_SIZE]; // 存储后缀表达式
char stk[MAX_SIZE]; // 运算符栈
int top = -1;      // 栈顶指针
int s2_idx = 0;    // s2的当前索引

void push(char item) { stk[++top] = item; }
char pop() { return stk[top--];}

// 获取运算符优先级
int prec(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// 中缀转后缀核心函数
void infixToPostfix_simplified() {
    // 重置状态 (如果函数可能被多次调用)
    top = -1;
    s2_idx = 0;
    // s2[0] = '\0'; // 不需要清空，因为会覆盖
    char token;
    int i;

    for (i = 0; s1[i] != '\0'; ++i) {
        token = s1[i];

        if (isspace(token)) { // 简单忽略空格
            continue;
        }

        // 1. 操作数
        if (isalnum(token)) {
            s2[s2_idx++] = token;
        }
        // 2. 左括号
        else if (token == '(') {
            push(token);
        }
        // 3. 右括号
        else if (token == ')') {
            while (stk[top] != '(') { // 因为输入合法，所以pop前栈顶不会是空，且一定能找到'('
                s2[s2_idx++] = pop();
            }
            pop(); // 弹出左括号
        }
        // 4. 运算符
        else {
            // 处理右结合的 '^'
            if (token == '^') {
                while (top != -1 && stk[top] != '(' && prec(token) < prec(stk[top])) {
                    // 对于右结合操作符 '^'，只有当栈顶操作符优先级严格大于当前操作符才弹出
                    // 如果优先级相同 (另一个'^'), 则不弹出，以保持右结合性 (例如 a^b^c -> abc^^)
                    s2[s2_idx++] = pop();
                }
            } else {
                // 处理左结合操作符 (+, -, *, /, %)
                while (top != -1 && stk[top] != '(' && prec(token) <= prec(stk[top])) {
                    // 当栈顶操作符优先级大于或等于当前操作符时弹出
                    s2[s2_idx++] = pop();
                }
            }
            push(token); // 当前运算符入栈
        }
    }

    //弹出栈中所有剩余运算符
    while (top != -1) { // 因为输入合法，栈中剩余的不会是左括号
        s2[s2_idx++] = pop();
    }

    s2[s2_idx] = '\0';
}

int main() {
    printf("请输入合法的的中缀表达式 (例如 a+b*c-d/e): ");
    if (fgets(s1, MAX_SIZE, stdin) != NULL) {
        // 移除 fgets 可能读入的换行符
        s1[strcspn(s1, "\n")] = '\0';
    } else {
        printf("读取输入时发生错误。\n");
        return 1;
    }
    printf("中缀表达式: %s\n", s1);
    infixToPostfix_simplified();
    printf("后缀表达式: %s\n", s2);
    return 0;
}