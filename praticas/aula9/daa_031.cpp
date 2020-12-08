// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao nao tem "garbage collection", ou seja, nao limpa no final a memoria)

#include <iostream>
#include <list>

#define MAX 251
using namespace std;

typedef struct {
  int x, y;
} Point;


class Pair {
public:
  int x, y;

  Pair(int x, int y){
    this->x = x;
    this->y = y;
  };
};

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

char matriz[MAX][MAX];
Node grafo[MAX][MAX];
bool adj[MAX][MAX];
int l, c;
int incr=0;


// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) {
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
  }

  void addLink(int v, int i, int j) {
    int pushc = v-c; int pushb = v+c; int pushe = v-1; int pushd = v+1;
    if(pushc < 0 || pushc>=(l*c)) {
      nodes[v].adj.push_back(pushc);
      //if(matriz[i-1][j] != '#') 
      nodes[pushc].distance = nodes[v].distance + 1;
      //else nodes[pushc].distance = 0;
    }

    if(pushb < 0 || pushb>=(l*c)) {
      nodes[v].adj.push_back(pushb);
      //if(matriz[i+1][j] != '#') 
      //nodes[pushb].distance = nodes[v].distance + 1;
      //else nodes[pushb].distance = 0;
    }
    if(pushe < 0 || pushe>=(l*c)) {
      nodes[v].adj.push_back(pushe);
      //if(matriz[i][j-1] != '#') 
      //nodes[pushe].distance = nodes[v].distance + 1;
      //else nodes[pushe].distance = 0;
    }
    if(pushd < 0 || pushd>=(l*c)) {
      nodes[v].adj.push_back(pushd);
      //if(matriz[i][j+1] != '#') 
      //nodes[pushd].distance = nodes[v].distance + 1;
      //else nodes[pushd].distance = 0;
    }

    //nodes[a].adj.push_back(b);
    //nodes[b].adj.push_back(a);
    /*
    if(x < 0 || x>=l || y<0 || y>=c) return;
    if(a < 0 || a>=l || b<0 || b>=c) return;
    adj[a][b] = adj[x][y] = true;
    if(matriz[a][b] == '#') grafo[a][b].distance = 0;
    if(matriz[x][y] == '#') grafo[x][y].distance = 0; 
    Pair *x1 = new Pair(a,b);
    Pair *y1 = new Pair(x,y);
    Point a1; a1.x = x; a1.y = y;
    //cout << a1.x << " " << a1.y;
    putchar('\n');
    nodes[z].adj.push_back(a1);
    nodes[z].adj.push_back(b1);
    //nodes[y1].adj.push_back(x1);
    */
  }
  
  
  void bfs(int v, int i, int j) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v);
    nodes[v].visited = true;
    if(matriz[i][j] == '#') nodes[v].distance = 0;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front();
      cout << u << ": " << nodes[u].distance << " ";
      for (auto w : nodes[u].adj)
      	if (!nodes[w].visited) {
      	  //q.push_back(w);
      	  nodes[w].visited  = true;
      	  nodes[w].distance = nodes[u].distance + 1; 	  
      	}
        cout << endl;
    }
  }
};

/*
void dfs1(int y, int x){

  if(y < 0 || y>=l || x<0 || x>=c) return;
  if(matriz[y][x] == 'A'){ 
    grafo[y][x].distance = incr; 
    grafo[y][x].visited = true; 
    return;
  }
  if(matriz[y][x] == '.') grafo[y][x].distance = incr;
  if(grafo[y][x].visited) return;
  dfs1(y-1,x); dfs1(y+1,x); dfs1(y,x-1); dfs1(y,x+1);
  incr++;
  return;
}*/


int main() {

  cin >> l; cin >> c;

  Graph *g = new Graph(l*c);

  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      cin >> matriz[i][j];
    }
  }
    
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      if(matriz[i][j] == '#') {
        g->nodes[incr].distance = 0;

        /*
        grafo[i][j].distance = 0;
        grafo[i+1][j].distance = grafo[i][j].distance+1;
        grafo[i-1][j].distance = grafo[i][j].distance+1;
        grafo[i][j-1].distance = grafo[i][j].distance+1;
        grafo[i][j+1].distance = grafo[i][j].distance+1;
        grafo[i+1][j].distance = true;
        grafo[i-1][j].distance = true;
        grafo[i][j-1].distance = true;
        grafo[i][j+1].visited = true;
        g->addLink(i,j,i+1,j);
        g->addLink(i,j,i-1,j);
        g->addLink(i,j,i,j+1);
        g->addLink(i,j,i,j-1);
        //matriz[i+1][j] == '#';
        //matriz[i-1][j] == '#';
        //matriz[i][j+1] == '#';
        //matriz[i][j-1] == '#';
        */
      }
       g->addLink(incr, i, j);
        incr++;
      /*
      else if(matriz[i][j] == '.'){
        g->addLink(i,j,i+1,j);
        g->addLink(i,j,i-1,j);
        g->addLink(i,j,i,j+1);
        g->addLink(i,j,i,j-1);
        grafo[i+1][j].distance = grafo[i][j].distance+1;
        grafo[i-1][j].distance = grafo[i][j].distance+1;
        grafo[i][j-1].distance = grafo[i][j].distance+1;
        grafo[i][j+1].distance = grafo[i][j].distance+1;
      }*/
    }
  }

    for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      cout << matriz[i][j] << " ";
    }
    putchar('\n');
  }

  int incr = 0;
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      g->bfs(incr, i, j);
      incr++;
    }
  }
  /*
  int incr = 0;
  for(int i=0;i<l; i++){
    for(int j=0; j<c; j++){
      cout << g->nodes[incr].distance << " ";
      incr++;
    }
  cout << '\n';
  }*/



  /*
  Graph *g = new Graph(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g->addLink(a, b);
  }

  // Pesquisa em largura a partir do no 1
  g->bfs(1);*/

  return 0;
}
