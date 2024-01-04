#include <stdio.h>

#define MAX_SIZE 100

struct TreeNode {
    int data;
};

struct TreeNode tree[MAX_SIZE];

// 构建二叉树
void buildTree(int index, int data) {
    tree[index].data = data;
}

// 寻找两个节点的最近公共祖先
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
    // 示例测试用例
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

    printf("最近公共祖先的编号：%d，值：%d\n", ancestor, tree[ancestor].data);

    return 0;
}

