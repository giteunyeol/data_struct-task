#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define maxqueue 100

typedef char element;
typedef struct
{
    element data[maxqueue];
    int front, rear;
} QueueType;

void error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear + 1) * maxqueue == q->front);
}

void add_rear(QueueType *q, element item)
{
    if (is_full(q))
    {
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % maxqueue;
    q->data[q->rear] = item;
}

element delete_front(QueueType *q)
{
    if (is_empty(q))
    {
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % maxqueue;
    return q->data[q->front];
}

int pal(QueueType *q)
{
    int size = (q->rear - q->front + maxqueue) % maxqueue;
    for (int i = 0; i < size / 2; i++)
    {
        if (q->data[(q->front + 1 + i) % maxqueue] != q->data[(q->rear - i + maxqueue) % maxqueue])
        {
            return 0; // 펠린드롬이 아님
        }
    }
    return 1; // 펠린드롬임
}

int main(void)
{
    QueueType q;
    char a[100];
    fgets(a, sizeof(a), stdin);

    init_queue(&q);

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (isalpha(a[i]))
        {                                // 알파벳인 경우만 큐에 추가
            add_rear(&q, tolower(a[i])); // 대문자를 소문자로 변환하여 큐에 추가
        }
    }

    if (pal(&q))
    {
        printf("펠린드롬입니다.");
    }
    else
    {
        printf("펠린드롬이 아닙니다.");
    }

    return 0;
}
