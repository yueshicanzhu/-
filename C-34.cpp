#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ����ڵ㵽����������
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        // �����Ϊ�գ�����һ���½ڵ�
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // ���򣬵ݹ�ز��뵽��������������
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// �������ĸ߶�
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// ����ڵ�Ĳ㼶
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

// ��������ʧ��ʱ��ƽ���������ȣ�ASL��
float calculateASL(struct TreeNode* root, int* keys, int numKeys) {
    float totalASL = 0;

    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int nodeLevel = level(root, key, 1);

        if (nodeLevel == -1) {
            // �ڵ�δ�ҵ����������ĸ߶���Ϊƽ����������
            totalASL += height(root);
        } else {
            totalASL += nodeLevel;
        }
    }

    return totalASL / numKeys;
}

int main() {
    // ��������1
    int keys1[] = {10, 5, 15, 3, 7, 12, 18};
    int numKeys1 = sizeof(keys1) / sizeof(keys1[0]);

    struct TreeNode* root1 = NULL;
    for (int i = 0; i < numKeys1; i++) {
        root1 = insert(root1, keys1[i]);
    }

    printf("Test Case 1: ASL = %.2f\n", calculateASL(root1, keys1, numKeys1));

    // �ͷ������ڴ�
    // (ʵ��Ӧ���У���Ҫ�ڳ������ʱ����������Ҫʱ�����ڴ��ͷ�)
    // ����ֻ�Ǽ�ʾ�����������ڴ��ͷ�

    // ��������2
    int keys2[] = {20, 10, 30, 5, 15, 25, 35};
    int numKeys2 = sizeof(keys2) / sizeof(keys2[0]);

    struct TreeNode* root2 = NULL;
    for (int i = 0; i < numKeys2; i++) {
        root2 = insert(root2, keys2[i]);
    }

    printf("Test Case 2: ASL = %.2f\n", calculateASL(root2, keys2, numKeys2));

    return 0;
}

