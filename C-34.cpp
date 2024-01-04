#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 插入节点到二叉排序树
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        // 如果树为空，创建一个新节点
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // 否则，递归地插入到左子树或右子树
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// 计算树的高度
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// 计算节点的层级
int level(struct TreeNode* root, int key, int depth) {
    if (root == NULL) {
        return -1;
    }

    if (key == root->data) {
        return depth;
    } else if (key < root->data) {
        return level(root->left, key, depth + 1);
    } else {
        return level(root->right, key, depth + 1);
    }
}

// 计算搜索失败时的平均搜索长度（ASL）
float calculateASL(struct TreeNode* root, int* keys, int numKeys) {
    float totalASL = 0;

    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int nodeLevel = level(root, key, 1);

        if (nodeLevel == -1) {
            // 节点未找到，计算树的高度作为平均搜索长度
            totalASL += height(root);
        } else {
            totalASL += nodeLevel;
        }
    }

    return totalASL / numKeys;
}

int main() {
    // 测试用例1
    int keys1[] = {10, 5, 15, 3, 7, 12, 18};
    int numKeys1 = sizeof(keys1) / sizeof(keys1[0]);

    struct TreeNode* root1 = NULL;
    for (int i = 0; i < numKeys1; i++) {
        root1 = insert(root1, keys1[i]);
    }

    printf("Test Case 1: ASL = %.2f\n", calculateASL(root1, keys1, numKeys1));

    // 释放树的内存
    // (实际应用中，需要在程序结束时或树不再需要时进行内存释放)
    // 这里只是简单示例，不包含内存释放

    // 测试用例2
    int keys2[] = {20, 10, 30, 5, 15, 25, 35};
    int numKeys2 = sizeof(keys2) / sizeof(keys2[0]);

    struct TreeNode* root2 = NULL;
    for (int i = 0; i < numKeys2; i++) {
        root2 = insert(root2, keys2[i]);
    }

    printf("Test Case 2: ASL = %.2f\n", calculateASL(root2, keys2, numKeys2));

    return 0;
}

