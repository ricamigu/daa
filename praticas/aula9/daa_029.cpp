#include <iostream>
#include <list>
#include <string>

#define MAX 26      // Maximo numero de nos 

using namespace std;

int n;              // Numero de nos do grafo
string a[100];
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?
bool exists[MAX];
list<char> lista;

void dfs(int v) {
  //cout << v << " ";
  visited[v] = true;
  for(int i=0; i<MAX; i++)
    if(adj[v][i] && !visited[i])
      dfs(i);
  lista.push_front(v);
}

void compare(){

  for(int i=0; i<n-1; i++){

    int s1 = (int)a[i].length();
    int s2 = (int)a[i+1].length();


    for(int x=0; x<s1 && x<s2; x++){
      if(a[i].at(x) != a[i+1].at(x)){
        adj[a[i].at(x)-'A'][a[i+1].at(x)-'A'] = true;
        exists[a[i].at(x)-'A'] = true;
        exists[a[i+1].at(x)-'A'] = true;
        break;
      }
    }
  }
}

int main() {

  cin >> n;

  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  compare();

  for(int i=0; i<26; i++){
    if(exists[i] && !visited[i]) {
      dfs(i); // Pesquisa em profundidade a partir do no 1
    }
  }

  for(int i: lista)
    cout << char(i+'A');
  putchar('\n');

  return 0;
}