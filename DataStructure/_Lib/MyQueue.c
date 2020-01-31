#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MyQueue.h"

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *CirQ = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    if (CirQ == NULL) {
        perror("base queue malloc error");
        exit(0);
        return NULL;
    }

    CirQ->pQueue = (int *)malloc(sizeof(int) * k);
    if (CirQ->pQueue == NULL) {
        perror("circular queue malloc error");
        exit(0);
        return NULL;
    }

    CirQ->max_size = k;
    CirQ->head = -1;
    CirQ->tail = -1;

    return CirQ;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    if (myCircularQueueIsEmpty(obj))
        obj->head = 0;

    obj->tail = (obj->tail + 1) % obj->max_size;
    obj->pQueue[obj->tail] = value;    
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    if (obj->head == obj->tail) {
        obj->head = -1;
        obj->tail = -1;
        return true;
    }
    
    obj->head = (obj->head + 1) % obj->max_size;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->pQueue[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->pQueue[obj->tail];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->head == -1);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->tail + 1) % obj->max_size == obj->head);
}

void myCircularQueuetraverse(MyCircularQueue *obj) {
    int i = obj->head;

    printf("Head->");
    while (i % (obj->max_size) != obj->tail) {
        printf("%d->", obj->pQueue[i % (obj->max_size)]);
        ++i;
    }
    printf("%d->Tail\n", obj->pQueue[i % (obj->max_size)]);
}

/** free my circular queue*/
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
    obj = NULL;
    return;
}