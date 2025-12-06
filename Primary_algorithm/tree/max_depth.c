#include <stdio.h>
#include "tree.h"

int maxDepth(struct TreeNode* root) {
    if (NULL == root) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return l > r ? l + 1 : r + 1;
}

int main(void)
{
    struct TreeNode n6 = {.val = 6};
    struct TreeNode n5 = {.val = 5};
    struct TreeNode n4 = {.val = 4};
    struct TreeNode n3 = {.val = 3};
    struct TreeNode n2 = {.val = 2, .left = &n3, .right = &n4};
    struct TreeNode n1 = {.val = 1, .left = &n5, .right = &n6};
    struct TreeNode n0 = {.val = 0, .left = &n1, .right = &n2};

    printf("depth: %d\n", maxDepth(&n0));

    return 0;
}
