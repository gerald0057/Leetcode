#include <stdio.h>

 struct ListNode
 {
    int val;
    struct ListNode *next;
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(void)
{
    struct ListNode node_0 = {.val = 0,};
    struct ListNode node_1 = {.val = 1,};
    struct ListNode node_2 = {.val = 2,};

    node_0.next = &node_1;
    node_1.next = &node_2;

    deleteNode(&node_1);

    struct ListNode *p = &node_0;
    do
    {
        printf("val: %d\r\n", p->val);
        p = p->next;
    }
    while (p);

    return 0;
}
