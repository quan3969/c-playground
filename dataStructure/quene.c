
#include <stdio.h>
#include <malloc.h>

struct Quene {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Quene* createQuene(unsigned capacity)
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
    quene->size = quene->size + 1;
    printf("%d enquened to quene\n", item);
}

int dequene(struct Quene* quene)
{
    if (isEmpty(quene))
        return INT_MIN;
    int item = quene->array[quene->front];
    quene->front = (quene->front + 1) % quene->capacity;
    quene->size--;
    return item;
}

int front(struct Quene* quene)
{
    if (isEmpty(quene))
        return INT_MIN;
    return quene->array[quene->front];
}

int rear(struct Quene* quene)
{
    if (isEmpty(quene))
        return INT_MIN;
    return quene->array[quene->rear];
}

int main()
{
    struct Quene* quene = createQuene(20);
    enquene(quene, 20);
    enquene(quene, 30);
    enquene(quene, 40);

    printf("%d dequened from quene\n", dequene(quene));
    printf("Front item is %d\n", front(quene));
    printf("Rear item is %d\n", rear(quene));
    return 0;
}
