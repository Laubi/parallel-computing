
#include <limits.h>
#include <stdbool.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 200
#endif

int GRAPH[SIZE][SIZE];
int DIST[SIZE];
bool VISITED[SIZE];


void init_random_graph() {
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
            if (i - j == 0 || rand()%5 == 0) { // no loops to self or random no edge
                GRAPH[j][i] = GRAPH[i][j] = 0;
            }  else {
                GRAPH[j][i] = GRAPH[i][j] = rand() % 100; // 0 or 1
            }
        }
    }
}

int minDistance(int const dist[], bool const prev[]){
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < SIZE; v++){
        if (!prev[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
void dijkstra(){
    for (int i = 0; i < SIZE; i++){
        DIST[i] = INT_MAX;
        VISITED[i] = false;
    }

    DIST[0] = 0;

    for (int count = 0; count < SIZE - 1; count++) {

        int u = minDistance(DIST, VISITED);

        VISITED[u] = true;

#pragma omp parallel for schedule(static) default(none) shared(DIST, VISITED, GRAPH) firstprivate(u)
        for (int v = 0; v < SIZE; v++){
            if (!VISITED[v] && GRAPH[u][v] && DIST[u] != INT_MAX && DIST[u] + GRAPH[u][v] < DIST[v]){
                DIST[v] += GRAPH[u][v];
            }
        }
    }
}

int main() {
    init_random_graph();

    measure_and_print(dijkstra);

    return 0;
}