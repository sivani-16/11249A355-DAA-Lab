#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices

// Check if it's safe to assign color 'c' to vertex 'v'
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Recursive function to solve m-coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V) return true; // All vertices are assigned a color

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    bool graph[V][V] = { {0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0} };
    int m = 3; // Number of colors
    int color[V] = {0};

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution Exists. Vertex colors: ");
        for (int i = 0; i < V; i++) printf("%d ", color[i]);
    } else {
        printf("No solution possible with %d colors.", m);
    }
    return 0;
}
