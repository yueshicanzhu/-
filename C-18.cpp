#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 定义带头结点的双向循环链表
typedef struct {
    Node* head;
} LinkedList;

// 初始化链表
void initList(LinkedList* list) {
    list->head = NULL;
}

// 插入节点到链表尾部
void insertNode(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    newNode->prev = (list->head) ? list->head->prev : newNode;
    
    if (list->head) {
        list->head->prev->next = newNode;
        list->head->prev = newNode;
    } else {
        list->head = newNode;
    }
}

// 打印链表元素
void printList(LinkedList* list) {
    if (list->head) {
        Node* current = list->head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != list->head);
        printf("\n");
    } else {
        printf("Empty list\n");
    }
}

// 求两个集合的交集
LinkedList intersection(LinkedList* A, LinkedList* B) {
    LinkedList result;
    initList(&result);

    if (A->head && B->head) {
        Node* currentA = A->head;
        do {
            Node* currentB = B->head;
            do {
                if (currentA->data == currentB->data) {
                    insertNode(&result, currentA->data);
                    break;
                }
                currentB = currentB->next;
            } while (currentB != B->head);
            currentA = currentA->next;
        } while (currentA != A->head);
    }

    return result;
}

// 检查链表是否包含指定元素
int contains(LinkedList* list, int value) {
    if (list->head) {
        Node* current = list->head;
        do {
            if (current->data == value) {
                return 1;
            }
            current = current->next;
        } while (current != list->head);
    }
    return 0;
}

// 求两个集合的并集
LinkedList unionSet(LinkedList* A, LinkedList* B) {
    LinkedList result;
    initList(&result);

    if (A->head) {
        Node* currentA = A->head;
        do {
            insertNode(&result, currentA->data);
            currentA = currentA->next;
        } while (currentA != A->head);
    }

    if (B->head) {
        Node* currentB = B->head;
        do {
            if (!contains(&result, currentB->data)) {
                insertNode(&result, currentB->data);
            }
            currentB = currentB->next;
        } while (currentB != B->head);
    }

    return result;
}



// 释放链表内存
void freeList(LinkedList* list) {
    if (list->head) {
        Node* current = list->head;
        do {
            Node* nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != list->head);
    }
    list->head = NULL;
}

int main() {
    // 测试用例1
    LinkedList A, B, intersectionResult, unionResult;
    initList(&A);
    initList(&B);

    insertNode(&A, 1);
    insertNode(&A, 2);
    insertNode(&A, 3);
    insertNode(&A, 4);
    insertNode(&A, 5);

    insertNode(&B, 3);
    insertNode(&B, 4);
    insertNode(&B, 5);
    insertNode(&B, 6);
    insertNode(&B, 7);

    printf("集合 A: ");
    printList(&A);
    printf("集合 B: ");
    printList(&B);

    intersectionResult = intersection(&A, &B);
    unionResult = unionSet(&A, &B);

    printf("交集: ");
    printList(&intersectionResult);
    printf("并集: ");
    printList(&unionResult);

    freeList(&A);
    freeList(&B);
    freeList(&intersectionResult);
    freeList(&unionResult);

    // 测试用例2
    initList(&A);
    initList(&B);

    insertNode(&A, 8);
    insertNode(&A, 9);
    insertNode(&A, 10);
    insertNode(&A, 11);
    insertNode(&A, 12);

    insertNode(&B, 10);
    insertNode(&B, 11);
    insertNode(&B, 12);
    insertNode(&B, 13);
    insertNode(&B, 14);

    printf("\n集合 A: ");
    printList(&A);
    printf("集合 B: ");
    printList(&B);

    intersectionResult = intersection(&A, &B);
    unionResult = unionSet(&A, &B);

    printf("交集: ");
    printList(&intersectionResult);
    printf("并集: ");
    printList(&unionResult);

    freeList(&A);
    freeList(&B);
    freeList(&intersectionResult);
    freeList(&unionResult);

    return 0;
}

