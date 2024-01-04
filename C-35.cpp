#include <stdio.h>
#include <stdlib.h>

// ����ͼ�Ľṹ��
typedef struct {
    int numVertices;  // ͼ�Ķ�����
    int** matrix;     // �ڽӾ���
    struct Node** list; // �ڽӱ�
} Graph;

// �����ڽӱ��еĽڵ�
struct Node {
    int vertex;
    struct Node* next;
};

// ��������
Graph* createGraph(int numVertices);
void addEdgeMatrix(Graph* graph, int src, int dest);

void printAdjList(Graph* graph);
void addEdgeList(Graph* graph, int src, int dest);
void listToAdjMatrix(Graph* graph);
void printAdjMatrix(Graph* graph);

// ����ͼ�ĺ���
Graph* createGraph(int numVertices) {
    int i, j;
    
    // �����ڴ��ͼ�ṹ��
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // �����ڴ���ڽӾ���
    graph->matrix = (int**)malloc(numVertices * sizeof(int*));
    for (i = 0; i < numVertices; i++) {
        graph->matrix[i] = (int*)malloc(numVertices * sizeof(int));
    }

    // ��ʼ���ڽӾ���Ϊ0
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }

    // �����ڴ���ڽӱ�
    graph->list = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    for (i = 0; i < numVertices; i++) {
        graph->list[i] = NULL;
    }

    return graph;
}
// ��ӱߵ��ڽӾ���
void addEdgeMatrix(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
// ��ӱߵ��ڽӱ�
void addEdgeList(Graph* graph, int src, int dest) {
    // �����½ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->list[src];
    graph->list[src] = newNode;
}

// ���ڽӾ���ת��Ϊ�ڽӱ�
Graph* MatrixToAdjList(int matrix[][5], int vertices) {
    Graph* graph = createGraph(vertices);

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (matrix[i][j] == 1) {
                addEdgeList(graph, i, j);
            }
        }
    }

    return graph;
}

// ���ڽӱ�ת��Ϊ�ڽӾ���
void listToAdjMatrix(Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->list[i];
        while (current != NULL) {
            graph->matrix[i][current->vertex] = 1;
            current = current->next;
        }
    }
}





// ��ӡ�ڽӱ�
void printAdjList(Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->list[i];
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// ��ӡ�ڽӾ���
void printAdjMatrix(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // ����һ��ͼ����ʼ���ڽӾ���

 	Graph* graph2 = createGraph(4);
    addEdgeList(graph2, 0, 1);
    addEdgeList(graph2, 0, 2);
    addEdgeList(graph2, 1, 3);

    // ���ڽӱ�ת��Ϊ�ڽӾ��󲢴�ӡ
    listToAdjMatrix(graph2);
    printf("\nAdjacency Matrix:\n");
    printAdjMatrix(graph2);
    
    printf("\n");
    // ����һ����ͼ����ʼ���ڽӱ�
    int n=5;
	int matrix[5][5] = {
	        {0, 1, 0, 1, 0},
	        {1, 0, 1, 1, 1},
	        {0, 1, 0, 0, 1},
	        {1, 1, 0, 0, 1},
	        {0, 1, 1, 1, 0}
	    };
	Graph* graphFromMatrix = MatrixToAdjList(matrix, n);
    printAdjList(graphFromMatrix);
	
    return 0;
}

