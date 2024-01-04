#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
int index=1;
// ����������
struct TreeNode* buildTree(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ѱ�������ڵ�������������
struct TreeNode* findLowestCommonAncestor(struct TreeNode* root, int node1, int node2) {
    if (root == NULL)
        return NULL;
    
    if (root->data == node1 || root->data == node2)
        return root;

    struct TreeNode* left = findLowestCommonAncestor(root->left, node1, node2);
    struct TreeNode* right = findLowestCommonAncestor(root->right, node1, node2);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    // ʾ����������
    struct TreeNode* root = buildTree(1);
    root->left = buildTree(2);
    root->right = buildTree(3);
    root->left->left = buildTree(4);
    root->left->right = buildTree(5);
    root->right->left = buildTree(6);
    root->right->right = buildTree(7);

    int node1 = 3;
    int node2 = 6;

    struct TreeNode* ancestor = findLowestCommonAncestor(root, node1, node2);

    if (ancestor != NULL)
        printf("����������ȵ�ֵ��%d\n", ancestor->data);
    else
        printf("δ�ҵ������������\n");

    return 0;
}

