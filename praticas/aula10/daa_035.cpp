// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao nao tem "garbage collection", ou seja, nao limpa no final a memoria)

#include <iostream>
#include <list>
#include <climits>
#include <set>
#define MAX 26

using namespace std;

int n;
int matriz[MAX][MAX];

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) {
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
  }
  
  void bfs(int v) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v);
    nodes[v].visited = true;
    matriz[v][v] = 1;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front();
      //cout << u << endl;
      matriz[v][u] = 1;
      for (auto w : nodes[u].adj)
        if (!nodes[w].visited) {
          matriz[w][u] = 1;
          q.push_back(w);
          nodes[w].visited  = true;
        }
    }
  }
};

void print_matriz(){
  char c = 'A';
  cout << " ";
  for(int i=0; i<n; i++) {
    cout << " " << c;
    c++;
  }
  cout << endl;

  c = 'A';
  for(int i=0; i<n; i++){
    cout << c; 
    for(int j=0; j<n; j++){
      cout << " " << matriz[i][j];
    }
    c++; cout << endl;
  }
}


int main() {
  int in;
  char a, b;
  cin >> n;
  Graph *g = new Graph(n);
  //cin >> e;

  for (int i=0; i<n; i++) {
    cin >> a;
    cin >> in;
    matriz[a-'A'][a-'A'] = 1;
    for(int i=0; i<in; i++){
      cin >> b;
      g->addLink(a-'A', b-'A');
      matriz[a-'A'][b-'A'] = 1;
    }
  }

  // Pesquisa em largura a partir do no 1
  
  for(int i=0; i<n; i++)
    g->bfs(i);
  print_matriz(); 

  return 0;
}