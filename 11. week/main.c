
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int adj[MAX][MAX];
bool visited[MAX];
int numNodes;

void DFS(int u) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < numNodes; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v);
        }
    }
}

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[u][v] = 1;
}

int main() {
    int i, j;


    numNodes = 7;

    for (i = 0; i < numNodes; i++) {
        visited[i] = false;
        for (j = 0; j < numNodes; j++) {
            adj[i][j] = 0;
        }
    }


    addEdge(0, 1);
    addEdge(1, 2);


    addEdge(3, 4);


    addEdge(5, 6);


    printf("Graph uzerindeki Cluster'lar (Kumeleme):\n");
    printf("----------------------------------------\n");


    int clusterCount = 0;

    for (i = 0; i < numNodes; i++) {

        if (visited[i] == false) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);

            DFS(i);

            printf("}\n");
        }
    }

    printf("----------------------------------------\n");
    printf("Toplam %d adet ayri kume bulundu.\n", clusterCount);

    return 0;
}
