
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#ifndef MATRIX_SIZE
#   define MATRIX_SIZE 20000
#endif

#define TRUE 1
#define FALSE 0

int cost[MATRIX_SIZE][MATRIX_SIZE];

int par[MATRIX_SIZE];
int dist[MATRIX_SIZE] = {[0 ... MATRIX_SIZE-1 ]=INT_MAX};
int visited[MATRIX_SIZE] ={0} ;

void initializeWithRandoms() {
    srand(time(0));

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if(rand() % 5  == 0) {
                cost[i][j] = rand() % 100; // 0 or 1
            } else {
                cost[i][j] = 9999;
            }
        }
    }
}


int getMin(int dist[] , int visited[]){
    int key = 0 ;
    int min = INT_MAX ;
    for(int i=0;i < MATRIX_SIZE ; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ;
            key = i ;
        }
    }
    return key ;
}

void dijkstra(){

    dist[0] =0 ;
    par[0] =0 ;

    for(int g = 0 ;g<MATRIX_SIZE-1 ; g++){
        int u = getMin( dist ,  visited )  ;
        visited[u] = TRUE ;

        for(int v =0 ; v< MATRIX_SIZE ;v++){
            if(!visited[v] && (dist[u]+cost[u][v]) <  dist[v] && cost[u][v]!=9999)
            {
                par[v] = u ;
                dist[v] = dist[u] + cost[u][v] ;
            }
        }
    }
}

int main() {
    initializeWithRandoms();

    dijkstra();

    return 0;
}