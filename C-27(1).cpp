#include <stdio.h>

#define MAX_SIZE 100

struct TreeNode {
    int data;
};

struct TreeNode tree[MAX_SIZE];

// ����������
void buildTree(int index, int data) {
    tree[index].data = data;
}

// Ѱ�������ڵ�������������
int findLowestCommonAncestor(int i, int j) {
    while (i != j) {
        if (i > j)
            i = i / 2;
        else
            j = j / 2;
    }
    return i;
}

int main() {
    // ʾ����������
    buildTree(1, 1);
    buildTree(2, 2);
    buildTree(3, 3);
    buildTree(4, 4);
    buildTree(5, 5);
    buildTree(6, 6);
    buildTree(7, 7);

    int i = 3;
    int j = 6;

    int ancestor = findLowestCommonAncestor(i, j);

    printf("����������ȵı�ţ�%d��ֵ��%d\n", ancestor, tree[ancestor].data);

    return 0;
}

