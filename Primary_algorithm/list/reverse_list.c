#include <stdio.h>
#include "list.h"

struct ListNode* reverseList(struct ListNode* head)
{
    // printf("val: %d\n", head->val);
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *tail = head->next;
    struct ListNode *list = reverseList(head->next);
    tail->next = head;
    head->next = NULL;

    return list;
}

int main(void)
{
    struct ListNode node_0 = {
        .val = 0,
    };
    struct ListNode node_1 = {
        .val = 1,
    };
    struct ListNode node_2 = {
        .val = 2,
    };

    node_0.next = &node_1;
    node_1.next = &node_2;

    printf("nodes: %p\n", &node_0);
    printf("nodes: %p\n", &node_1);
    printf("nodes: %p\n", &node_2);

    struct ListNode *p = reverseList(&node_0);

    while (p)
    {
        printf("p: %p\n", p);
        printf("val: %d\n", p->val);
        p = p->next;
    }

    return 0;
}
