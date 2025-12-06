#include <stdio.h>
#include <stdbool.h>
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

bool isPalindrome(struct ListNode* head) {
    struct ListNode* fast = head, *slow = head;
    if (head == NULL || head->next == NULL) return true;
    while (fast && fast->next)
    {
        // printf("go\n");
        slow = slow->next;
        // printf("slow %p\n", slow);
        fast = fast->next->next;
        // printf("fast %p\n", fast);
    }
    
    if (fast != NULL) slow = slow->next;
    // printf("slow %p\n", slow);
    slow = reverseList(slow);

    while (slow)
    {
        // printf("%d %d\n", head->val, slow->val);
        if (head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }

    return true;
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
    struct ListNode node_3 = {
        .val = 0,
    };

    node_0.next = &node_1;
    node_1.next = &node_2;
    node_2.next = &node_3;

    // printf("nodes: %p\n", &node_0);
    // printf("nodes: %p\n", &node_1);
    // printf("nodes: %p\n", &node_2);

    printf("is %d\n", isPalindrome(&node_0));

    return 0;
}

