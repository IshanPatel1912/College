#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

/* ============================================================
   PART 1: CYCLE DETECTION IN DIRECTED GRAPH
   ============================================================ */
#define MAX_V 20

struct DirectedGraph {
    int V;
    int adj[MAX_V][MAX_V];
};

struct DirectedGraph* createDirectedGraph(int V) {
    struct DirectedGraph* g = (struct DirectedGraph*)malloc(sizeof(struct DirectedGraph));
    g->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void addDirectedEdge(struct DirectedGraph* g, int u, int v) {
    g->adj[u][v] = 1;
}

bool isCyclicDirectedUtil(struct DirectedGraph* g, int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i]) {
            if (!visited[i] && isCyclicDirectedUtil(g, i, visited, recStack)) {
                return true;
            } else if (recStack[i]) {
                return true; // Back edge detected
            }
        }
    }

    recStack[v] = false; // Remove vertex from recursion stack
    return false;
}

bool isCyclicDirected(struct DirectedGraph* g) {
    bool visited[MAX_V] = {false};
    bool recStack[MAX_V] = {false};

    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {
            if (isCyclicDirectedUtil(g, i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

/* ============================================================
   PART 2: CYCLE DETECTION IN UNDIRECTED GRAPH
   ============================================================ */
struct UndirectedGraph {
    int V;
    int adj[MAX_V][MAX_V];
};

struct UndirectedGraph* createUndirectedGraph(int V) {
    struct UndirectedGraph* g = (struct UndirectedGraph*)malloc(sizeof(struct UndirectedGraph));
    g->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void addUndirectedEdge(struct UndirectedGraph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

bool isCyclicUndirectedUtil(struct UndirectedGraph* g, int v, bool visited[], int parent) {
    visited[v] = true;

    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i]) {
            if (!visited[i]) {
                if (isCyclicUndirectedUtil(g, i, visited, v)) {
                    return true;
                }
            } else if (i != parent) {
                // Adjacent visited node is NOT parent -> cycle detected
                return true;
            }
        }
    }
    return false;
}

bool isCyclicUndirected(struct UndirectedGraph* g) {
    bool visited[MAX_V] = {false};

    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {
            if (isCyclicUndirectedUtil(g, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    printHeader();

    // 1. Directed Graph Cycle Test
    printf("============================================================\n");
    printf("       1. TESTING DIRECTED GRAPH CYCLE DETECTION            \n");
    printf("============================================================\n");
    struct DirectedGraph* dg1 = createDirectedGraph(4);
    addDirectedEdge(dg1, 0, 1);
    addDirectedEdge(dg1, 1, 2);
    addDirectedEdge(dg1, 2, 0); // Creates cycle: 0 -> 1 -> 2 -> 0
    addDirectedEdge(dg1, 2, 3);

    printf("Directed Graph 1 Edges: (0->1), (1->2), (2->0), (2->3)\n");
    printf("  >> Contains Cycle: %s\n\n", isCyclicDirected(dg1) ? "TRUE (Cycle Detected)" : "FALSE (Acyclic)");

    struct DirectedGraph* dg2 = createDirectedGraph(3);
    addDirectedEdge(dg2, 0, 1);
    addDirectedEdge(dg2, 1, 2);
    printf("Directed Graph 2 (DAG) Edges: (0->1), (1->2)\n");
    printf("  >> Contains Cycle: %s\n", isCyclicDirected(dg2) ? "TRUE (Cycle Detected)" : "FALSE (Acyclic)");

    // 2. Undirected Graph Cycle Test
    printf("\n============================================================\n");
    printf("      2. TESTING UNDIRECTED GRAPH CYCLE DETECTION           \n");
    printf("============================================================\n");
    struct UndirectedGraph* ug1 = createUndirectedGraph(4);
    addUndirectedEdge(ug1, 0, 1);
    addUndirectedEdge(ug1, 1, 2);
    addUndirectedEdge(ug1, 2, 3);
    addUndirectedEdge(ug1, 3, 0); // Creates cycle: 0-1-2-3-0

    printf("Undirected Graph 1 Edges: (0-1), (1-2), (2-3), (3-0)\n");
    printf("  >> Contains Cycle: %s\n\n", isCyclicUndirected(ug1) ? "TRUE (Cycle Detected)" : "FALSE (Acyclic)");

    struct UndirectedGraph* ug2 = createUndirectedGraph(3);
    addUndirectedEdge(ug2, 0, 1);
    addUndirectedEdge(ug2, 1, 2);
    printf("Undirected Graph 2 (Tree) Edges: (0-1), (1-2)\n");
    printf("  >> Contains Cycle: %s\n", isCyclicUndirected(ug2) ? "TRUE (Cycle Detected)" : "FALSE (Acyclic)");

    printf("============================================================\n");
    free(dg1);
    free(dg2);
    free(ug1);
    free(ug2);
    return 0;
}
