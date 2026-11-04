#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

// Graph Node for Adjacency List
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct Graph {
    int V;
    struct AdjListNode** adjLists;
};

struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = vertices;
    graph->adjLists = (struct AdjListNode**)malloc(vertices * sizeof(struct AdjListNode*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add undirected edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Edge from src to dest
    struct AdjListNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS using queue
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Breadth First Search Traversal starting from vertex %d:\n  -> ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct AdjListNode* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

void printComplexityAnalysis() {
    printf("\n================ COMPLEXITY ANALYSIS ================\n");
    printf(" 1. Time Complexity:\n");
    printf("    - Adjacency List: O(V + E)\n");
    printf("      Where V is the number of vertices and E is the number of edges.\n");
    printf("      Each vertex is enqueued once, and each edge is examined once.\n");
    printf(" 2. Space Complexity:\n");
    printf("    - O(V) for the visited boolean array and BFS queue.\n");
    printf("=====================================================\n");
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct AdjListNode* curr = graph->adjLists[i];
        while (curr != NULL) {
            struct AdjListNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    printHeader();

    int V = 6;
    struct Graph* graph = createGraph(V);

    /*
          Graph Structure:
             0 --- 1
             |   / |
             |  /  |
             2 --- 3
             \    /
              4  5
    */
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("Graph with %d vertices constructed:\n", V);
    printf("Edges: (0-1), (0-2), (1-2), (1-3), (2-3), (2-4), (3-5)\n\n");

    BFS(graph, 0);

    printComplexityAnalysis();

    freeGraph(graph);
    return 0;
}
