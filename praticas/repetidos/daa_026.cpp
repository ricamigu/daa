#include <iostream>
#include <set>     
#include <map>     
#include <string>  

#define MAX 105      // Maximo numero de nos 
#define FILL '#'

using namespace std;

int linha, coluna;
char matriz[MAX][MAX];
bool visited[MAX][MAX];  // Que nos ja foram visitados?

int dfs(int y, int x) {
  //cout << v << " ";
  if( y < 0 || y >= linha || x < 0 || x >= coluna) return 0;
  if( matriz[y][x] != FILL ) return 0;
  if( visited[y][x] ) return 0;
  visited[y][x] = true;

  return 1 + dfs(y-1,x-1) + dfs(y-1,x) + dfs(y-1,x+1) + dfs(y,x+1) + dfs(y+1,x+1) + dfs(y+1,x) + dfs(y+1,x-1) + dfs(y,x-1);   
}

void clear_matriz(){

  for(int i=0; i<linha; i++)
    for(int j=0; j<coluna; j++)
      visited[i][j] = false;

}

int main() {

  int n;
  cin >> n;

  for(int casos=0; casos<n; casos++){
    cin >> linha; cin >> coluna;
    for (int i=0; i<linha; i++) {
    for(int j=0; j<coluna; j++){
      cin >> matriz[i][j];
    }
  }

  int max=0, check=0;
  for(int i=0; i<linha; i++){
    for(int j=0; j<coluna; j++){
          if(matriz[i][j] == FILL && !visited[i][j]) {
            check = dfs(i,j); // Pesquisa em profundidade a partir do no 1
            if(max<=check) max = check;
          }
    }
  }
  cout << max << endl;
  clear_matriz();
  }
  return 0;
}