#include <iostream>
#include <set>     
#include <map>     
#include <string>  

#define MAX 105      // Maximo numero de nos 

using namespace std;

typedef struct {
  bool visited;
  string color;
} node;

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
node matriz[MAX];  // Que nos ja foram visitados?

bool dfs(int v, string cor) {
  //cout << v << " ";
  matriz[v].visited = true;
  matriz[v].color = cor;

  for (int i=1; i<=n; i++){
      if (adj[v][i] && !matriz[i].visited){
        if(cor=="blue") cor = "red"; else cor = "blue";
        return true && dfs(i,cor);
      }
      else if(adj[v][i] && matriz[i].visited){
        if(matriz[i].color == cor) return false;
    }
  }
  return true;
}

void clean_matriz(){
  for(int i=0; i<MAX; i++){
      matriz[i].color = "black";
      matriz[i].visited = false;
      for(int j=0; j<MAX;j++){
        adj[i][j] = false;
    }
  }
}

int main() {
  int casos; cin >> casos;
  for(int x=0; x<casos; x++){
     int edges, a, b;
     cin >> n; cin >> edges;
    for (int i=0; i<edges; i++) {
      cin >> a >> b;
      adj[a][b] = adj[b][a] = true;
    }
    // Pesquisa em profundidade a partir do no 1
    if(dfs(1,"blue")) cout << "sim" << endl; else cout << "nao" << endl; 
    clean_matriz();
  }
  return 0;
}