#include <iostream>
#include <set>     
#include <map>     
#include <string>  

#define MAX 105

using namespace std;

int n;
bool adj[MAX][MAX];
bool visited[MAX];

void dfs(int v){

	visited[v] = true;
	for(int i=1; i<=n; i++)
		if(adj[v][i] && !visited[i])
			dfs(i);
		
}

int main(){

	int e, a, b;
	cin >> n; cin >> e;

	for(int i=0; i<e; i++){
		cin >> a; cin >> b;
		adj[a][b] = adj[b][a] = true;
	}

	int count=0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			count++;
			dfs(i);
		}
	}

	cout << count << '\n';
	return 0;

}