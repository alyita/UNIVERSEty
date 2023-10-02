#include "queue.h"
#include <stdio.h>

#define FULL -1
#define EMPTY -2


void init(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

int isEmpty(struct Queue *queue){
    return (queue->front == -1);
}

int isFull(struct Queue *queue){
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

int enqueue(struct Queue *queue, int who){
    if(isFull(queue)){
        return FULL;
    }

    if(isEmpty(queue)){
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->array[queue->rear] = who;

    return 0;
}

int dequeue(struct Queue *queue){

    if(isEmpty(queue)){
        return EMPTY;
    }

    int who = queue->array[queue->front];
        
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return who;
}



