#include <stdio.h>
#include <stdlib.h>

// 定义图的结构体
typedef struct {
    int numVertices;  // 图的顶点数
    int** matrix;     // 邻接矩阵
    struct Node** list; // 邻接表
} Graph;

// 定义邻接表中的节点
struct Node {
    int vertex;
    struct Node* next;
};

// 函数声明
Graph* createGraph(int numVertices);
void addEdgeMatrix(Graph* graph, int src, int dest);

void printAdjList(Graph* graph);
void addEdgeList(Graph* graph, int src, int dest);
void listToAdjMatrix(Graph* graph);
void printAdjMatrix(Graph* graph);

// 创建图的函数
Graph* createGraph(int numVertices) {
    int i, j;
    
    // 分配内存给图结构体
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // 分配内存给邻接矩阵
    graph->matrix = (int**)malloc(numVertices * sizeof(int*));
    for (i = 0; i < numVertices; i++) {
        graph->matrix[i] = (int*)malloc(numVertices * sizeof(int));
    }

    // 初始化邻接矩阵为0
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }

    // 分配内存给邻接表
    graph->list = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    for (i = 0; i < numVertices; i++) {
        graph->list[i] = NULL;
    }

    return graph;
}
// 添加边到邻接矩阵
void addEdgeMatrix(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
// 添加边到邻接表
void addEdgeList(Graph* graph, int src, int dest) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->list[src];
    graph->list[src] = newNode;
}

// 将邻接矩阵转换为邻接表
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

// 将邻接表转换为邻接矩阵
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





// 打印邻接表
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

// 打印邻接矩阵
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
    // 创建一个图并初始化邻接矩阵

 	Graph* graph2 = createGraph(4);
    addEdgeList(graph2, 0, 1);
    addEdgeList(graph2, 0, 2);
    addEdgeList(graph2, 1, 3);

    // 将邻接表转换为邻接矩阵并打印
    listToAdjMatrix(graph2);
    printf("\nAdjacency Matrix:\n");
    printAdjMatrix(graph2);
    
    printf("\n");
    // 创建一个新图并初始化邻接表
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

