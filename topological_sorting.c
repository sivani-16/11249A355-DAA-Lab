#include <stdio.h>

#define MAX_VERTICES 6

int adj[MAX_VERTICES][MAX_VERTICES] = {
   {0, 1, 1, 0, 0, 0},
   {0, 0, 0, 1, 1, 0},
   {0, 0, 0, 0, 1, 0},
   {0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 0}
};

int visited[MAX_VERTICES] = {0};
int topological_order[MAX_VERTICES];
int order_index = MAX_VERTICES - 1;

void DFS(int vertex) {
   visited[vertex] = 1;
   for (int v = 0; v < MAX_VERTICES; v++) {
      if (adj[vertex][v] && !visited[v]) {
         DFS(v);
      }
   }
   topological_order[order_index--] = vertex;
}

void topological_sort() {
   for (int v = 0; v < MAX_VERTICES; v++) {
      if (!visited[v]) {
         DFS(v);
      }
   }
}

void print_topological_order() {
   printf("Topological Order: ");
   for (int i = 0; i < MAX_VERTICES; i++) {
      printf("%d ", topological_order[i]);
   }
   printf("\n");
}

int main() {
   topological_sort();
   print_topological_order();
   return 0;
}
