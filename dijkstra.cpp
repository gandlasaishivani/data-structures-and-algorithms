#include<iostream>
using namespace std;
#define v 5
int mindist(int dist[],bool set[]) {
    int min = 1e9,minindex;
    for(int i = 0;i<v;i++) {
      if(set[i] == false && dist[i] <= min) {
        min = dist[i];
        minindex = i;
      }
    }
    return minindex;
}
void print(int dist[]) {
    for(int i =0;i<v;i++) {
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}
void dijkstra(int graph[v][v],int source) {
     bool set[v];
     int dist[v];
     for(int i = 0;i<v;i++) {
        set[i] = false;
        dist[i] = 1e9;
     }
     dist[source] = 0;
     for(int i = 0;i<v-1;i++) {
          int u = mindist(dist,set);
          set[u] = true;
          for(int j = 0;j<v;j++) {
            if(set[j] == false && graph[u][j] && dist[u] != 1e9 &&   dist[u]+graph[u][j] < dist[j]){
                dist[j] = dist[u]+graph[u][j];
            }
          }

     }
     print(dist);
}
int main() {
     int graph[v][v] = { { 0, 6, 0, 1, 0 },
                        { 6, 0, 5, 2, 2 },
                        { 0, 5, 0, 0, 5 },
                        { 1, 2, 0, 0, 1 },
                        { 0, 2, 5, 1, 0 } };

    // Perform Dijkstra's algorithm starting from vertex 0
    dijkstra(graph, 0);
    return 0;
}
