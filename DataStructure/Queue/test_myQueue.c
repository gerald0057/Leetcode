#include <stdio.h>
#include "MyQueue.h"

int main(void) {
    MyCircularQueue *obj = myCircularQueueCreate(5);

    printf("%s\n", myCircularQueueIsEmpty(obj) ? "true" : "false");

    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueDeQueue(obj);

    printf("%d %d\n", obj->head, obj->tail);
    printf("%d %d\n", myCircularQueueFront(obj), myCircularQueueRear(obj));
    printf("%s\n", myCircularQueueIsEmpty(obj) ? "true" : "false");

    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    // myCircularQueueEnQueue(obj, 3);

    myCircularQueuetraverse(obj);

    printf("%s\n", myCircularQueueIsFull(obj) ? "true" : "false");

    myCircularQueueFree(obj);

    return 0;
}