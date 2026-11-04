#include <stdio.h>
#include <stdlib.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

// Edge representation
struct Edge {
    int src, dest, weight;
};

// Graph representation
struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Subset for Disjoint Set Union (DSU)
struct Subset {
    int parent;
    int rank;
};

// Find set of an element i (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union of two sets by rank
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

// Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // Stores the resultant MST
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    // Step 1: Sort all edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("--- Edges Sorted by Weight (Greedy Selection) ---\n");
    for (int k = 0; k < graph->E; k++) {
        printf("  Edge (%d - %d) with Weight = %d\n",
               graph->edge[k].src, graph->edge[k].dest, graph->edge[k].weight);
    }
    printf("\n");

    // Number of edges to be taken is equal to V - 1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause cycle, include it in result
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard next_edge
    }

    // Print MST
    printf("============================================================\n");
    printf("          MINIMUM SPANNING TREE (MST) RESULT                \n");
    printf("============================================================\n");
    printf(" Edge       Weight\n");
    printf("--------------------\n");
    int minimumCost = 0;
    for (i = 0; i < e; i++) {
        printf(" %d -- %d      %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("--------------------\n");
    printf(" Total Minimum Spanning Tree Cost: %d\n", minimumCost);
    printf("============================================================\n");

    free(subsets);
}

int main() {
    printHeader();

    /*
            Example Graph with 4 vertices and 5 edges:
                 0
               / | \
             10  6   5
             /   |    \
            1 -- 15 -- 2
             \        /
               4    3
                 \ /
                  3
    */
    int V = 4;
    int E = 5;
    struct Graph* graph = createGraph(V, E);

    // Edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // Edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // Edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // Edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // Edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    free(graph->edge);
    free(graph);
    return 0;
}
