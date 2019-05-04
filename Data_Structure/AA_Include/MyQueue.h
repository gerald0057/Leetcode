#ifndef __MyQueue_h__
#define __MyQueue_h__

#include <stdbool.h>

typedef struct MyCircularQueue {
    int head;
    int tail;
    int max_size;
    int *pQueue;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k);
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj);
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj);
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj);
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj);
/** free the queue*/
void myCircularQueueFree(MyCircularQueue* obj);
/** traverse the queue*/
void myCircularQueuetraverse(MyCircularQueue *obj);

#endif