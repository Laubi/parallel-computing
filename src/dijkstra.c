
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 20000
#endif

#define TRUE 1
#define FALSE 0

int cost[SIZE][SIZE];

int par[SIZE];
int dist[SIZE] = {[0 ... SIZE - 1 ]=INT_MAX};
int visited[SIZE] ={0} ;

void initializeWithRandoms() {
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
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
    for(int i=0; i < SIZE ; i++){
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

    for(int g = 0 ; g < SIZE - 1 ; g++){
        int u = getMin( dist ,  visited )  ;
        visited[u] = TRUE ;

        for(int v =0 ; v < SIZE ; v++){
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

    measure_and_print(dijkstra);

    return 0;
}