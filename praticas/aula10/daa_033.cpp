// Exemplo de aplicacao do algoritmo de Dijkstra
// (assumindo um grafo pesado e dirigido, sem pesos negativos)

#include <iostream>
#include <climits>
#include <list>
#include <set>

#define MAX 1001

using namespace std;


string arr[MAX];
int size=0;

// Classe que representa um no
class Node {
public:
  list<pair<int, float>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  float distance;              // Distancia ao no origem da pesquisa
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

  void addLink(int a, int b, float c) {
    nodes[a].adj.push_back({b,c});
    nodes[b].adj.push_back({a,c});
  }

  // Algoritmo de Dijkstra
  void dijkstra(int s) {
    
    //Inicializar nos como nao visitados e com distancia infinita
    for (int i=1; i<=n; i++) {
      nodes[i].distance = INT_MAX;
      nodes[i].visited  = false;
    }
    
    // Inicializar "fila" com no origem
    nodes[s].distance = 0;
    nodes[s].pred = s;
    set<pair<int, float>> q; // By "default" um par e comparado pelo primeiro elemento 
    q.insert({0, s});      // Criar um par (dist=0, no=s)

    // Ciclo principal do Dijkstra
    while (!q.empty()) {
      
      // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
      int u = q.begin()->second;
      q.erase(q.begin());
      nodes[u].visited = true;
      //cout << u << " [dist=" << nodes[u].distance << "]" << endl;

      // Relaxar arestas do no retirado
      for (auto edge : nodes[u].adj) {
      	int v = edge.first;
      	float cost = edge.second;
      	if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
      	  q.erase({nodes[v].distance, v});  // Apagar do set
      	  nodes[v].distance = nodes[u].distance + cost;
      	  q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
      	  nodes[v].pred = u;
        }
      }
    }
  }
};


int insert_array(string s){
  size++;
  arr[size] = s;
  return size;
}

int find(string s){

  for(int i=1; i<=size; i++){
    if(arr[i]==s) return i;
  }
  return insert_array(s);
}

void print_array(){
  for(int i=1; i<=size; i++){
    cout << i << " " <<arr[i] << '\n';
  }
}

int main() {
  int n, e; float peso;
  string sa, sb;
  
  cin >> n;
  Graph *g = new Graph(n);
  cin >> e;

  string inicial, final;
  cin >> inicial >> final;

  int x = find(inicial);
  int y = find(final);

  int a,b;

  for (int i=0; i<e; i++) {
    cin >> sa >> sb;
    cin >> peso;
    a = find(sa); b = find(sb);
    //cout << a-1 << " -> " << b-1 << "  " << peso << endl;
    g->addLink(a, b, peso);
  }

  g->dijkstra(x);
  cout << g->nodes[y].distance << endl;

  return 0;
}