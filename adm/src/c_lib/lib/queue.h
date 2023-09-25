#ifndef QUEUE_H
#define QUEUE_H


#define MAX_SIZE 5000

struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

void init(struct Queue *queue);
int isEmpty(struct Queue *queue);
int isFull(struct Queue *queue);
int enqueue(struct Queue *queue, int who);
int dequeue(struct Queue *queue);

#endif // QUEUE_H
