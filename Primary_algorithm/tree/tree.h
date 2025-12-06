#ifndef __TREE_H
#define __TREE_H

#ifdef __cplusplus
extern "C" {
#endif

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#ifdef __cplusplus
}
#endif

#endif /* __TREE_H */
