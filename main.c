
#include <stdio.h>
#include <stdlib.h>

struct Quene {
    int front, rear, size;
    int capacity;
    int* array;
};

struct Quene* createQuene(int capacity)
{
    struct Quene* quene = (struct Quene*)malloc(sizeof(struct Quene));
    quene->capacity = capacity;
    quene->front = quene->size = 0;
    quene->rear = capacity - 1;
    quene->array = (int*)malloc(sizeof(int) * capacity);
    return quene;
}

int isFull(struct Quene* quene)
{
    return quene->size == quene->capacity;
}

int isEmpty(struct Quene* quene)
{
    return quene->size == 0;
}

void enquene(struct Quene* quene, int item)
{
    if (isFull(quene))
        return;
    quene->rear = (quene->rear + 1) % quene->capacity;
    quene->array[quene->rear] = item;
    quene->size++;
}

int dequene(struct Quene* quene)
{
    if (isEmpty(quene))
        return INT32_MIN;
    int item = quene->array[quene->front];
    quene->front = (quene->front + 1) % quene->capacity;
    quene->size--;
    return item;
}

int front(struct Quene* quene)
{
    if (isEmpty(quene))
        return INT32_MIN;
    return quene->array[quene->front];
}

int rear(struct Quene* quene)
{
    if (isEmpty(quene))
        return INT32_MIN;
    return quene->array[quene->rear];
}

int main()
{
    struct Quene* quene = createQuene(2);
    enquene(quene, 10);
    enquene(quene, 20);
    int temp = front(quene);
    temp = rear(quene);
    temp = dequene(quene);
    return 0;
}
