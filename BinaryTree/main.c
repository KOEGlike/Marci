#include <stdio.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, &n1, &n2};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, &n3, &n4};
    inorder(&n5);
    return 0;
}