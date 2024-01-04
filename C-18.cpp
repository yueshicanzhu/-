#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// �����ͷ����˫��ѭ������
typedef struct {
    Node* head;
} LinkedList;

// ��ʼ������
void initList(LinkedList* list) {
    list->head = NULL;
}

// ����ڵ㵽����β��
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

// ��ӡ����Ԫ��
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

// ���������ϵĽ���
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

// ��������Ƿ����ָ��Ԫ��
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

// ���������ϵĲ���
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



// �ͷ������ڴ�
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
    // ��������1
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

    printf("���� A: ");
    printList(&A);
    printf("���� B: ");
    printList(&B);

    intersectionResult = intersection(&A, &B);
    unionResult = unionSet(&A, &B);

    printf("����: ");
    printList(&intersectionResult);
    printf("����: ");
    printList(&unionResult);

    freeList(&A);
    freeList(&B);
    freeList(&intersectionResult);
    freeList(&unionResult);

    // ��������2
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

    printf("\n���� A: ");
    printList(&A);
    printf("���� B: ");
    printList(&B);

    intersectionResult = intersection(&A, &B);
    unionResult = unionSet(&A, &B);

    printf("����: ");
    printList(&intersectionResult);
    printf("����: ");
    printList(&unionResult);

    freeList(&A);
    freeList(&B);
    freeList(&intersectionResult);
    freeList(&unionResult);

    return 0;
}

