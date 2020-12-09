#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

// Classe que representa um no
class Node {
public:
  list<pair<int, int>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  int distance;              // Distancia ao no origem da pesquisa
  int pred;

};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) {
    this->n = n;
    nodes = new Node[n+1];  // +1 se os nos comecam em 1 ao inves de 0
  }

  void addLink(int a, int b, int c) {
    nodes[a].adj.push_back({b,c});
  }

  // Algoritmo de Dijkstra
  void dijkstra(int s) {
    
    //Inicializar nos como nao visitados e com distancia infinita
    for (int i=1; i<=n; i++) {
      nodes[i].distance = -1;
      nodes[i].visited  = false;
    }
    
    // Inicializar "fila" com no origem
    nodes[s].distance = INT_MAX;
    nodes[s].pred = s;
    set<pair<int, int>> q; // By "default" um par e comparado pelo primeiro elemento 
    q.insert({0, s});      // Criar um par (dist=0, no=s)

    // Ciclo principal do Dijkstra
    while (!q.empty()) {
      // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
      int u = q.begin()->second;
      q.erase(q.begin());
      //q.insert({0,1});
      nodes[u].visited = true;
      cout << u << " [dist=" << nodes[u].distance << "]" << endl;
      
      // Relaxar arestas do no retirado
      for (auto edge : nodes[u].adj) {
      	int v = edge.first;
      	int cost = edge.second;
      	if (!nodes[v].visited && min(nodes[u].distance,cost) > nodes[v].distance) {
      	  q.erase({nodes[v].distance, v});  // Apagar do set
      	  nodes[v].distance = min(nodes[u].distance, cost);
      	  q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
          nodes[v].pred = u;
      	}
      }
    }
  }
};

int main() {
  int n, e, a, b, c;
  
  cin >> n;
  Graph *g = new Graph(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b >> c;
    g->addLink(a, b, c);
  }

  g->dijkstra(1);

  g->nodes[0].distance = 0;

  cout << endl;

  return 0;
}