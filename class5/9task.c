#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

typedef struct stack {
    int value[maxsize];
    int top;
} stack;

void createStack(stack *p) {
    p->top = -1;
}

void push(stack *p, int n) {
    if (p->top == maxsize - 1) {
        printf("오버플로우\n");
        return;
    }
    p->top++;
    p->value[p->top] = n;
}

int pop(stack *p) {
    if (p->top == -1) {
        printf(" 언더플로우\n");
        return -1; // 임의의 오류 값을 반환
    }
    int value = p->value[p->top];
    p->top--;
    return value;
}

void enqueue(stack *p1) {
    int data;
    printf("숫자를 입력하세요: ");
    scanf("%d", &data);
    push(p1, data);
}

void dequeue(stack *p1, stack *p2) {
    if (p2->top == -1) {
        // 스택 2가 비어있는 경우, 스택 1의 모든 요소를 스택 2로 이동
        while (p1->top != -1) {
            push(p2, pop(p1));
        }
    }
    // 스택 2에서 요소를 꺼내서 출력
    printf("디큐된 요소: %d\n", pop(p2));
}

int main(void) {
    stack stk1, stk2;
    createStack(&stk1);
    createStack(&stk2);

    int choice;
    while (1) {
        printf("\n\n선택: 1. 인큐  2. 디큐      3. 종료\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&stk1);
                break;
            case 2:
                dequeue(&stk1, &stk2);
                break;
            case 3:
                exit(0);
            default:
                printf("잘못된 선택\n");
        }
    }

    return 0;
}
