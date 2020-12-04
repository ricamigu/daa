#include <iostream>
#include <set>     
#include <map>     
#include <string>  

#define FILL '#'
#define MAX 105
#define NDIRS 8

using namespace std;

//int incx[NDIRS] = { -1, 1, 0, 0, -1, -1, 1 , 1 };
//int incy[NDIRS] = {  0, 0,-1, 1, -1,  1,-1,  1 };

int rows, cols;
char m[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int y, int x){

	if(y < 0 || y >= rows || x <0 || x>=cols) return 0;
	if(visited[y][x] || m[y][x]!=FILL) return 0;

	visited[y][x] = true;
	
	return 1 + dfs(y-1,x) + dfs(y+1,x) + dfs(y,x-1) + dfs(y,x+1) + dfs(y-1,x-1) + dfs(y-1,x+1) + dfs(y+1,x-1) + dfs(y+1,x+1) ;

}

void reset_matriz(){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			visited[i][j] = false;
		}
	}
}


int main(){

	int casos;
	cin >> casos;

	for(int i=0; i<casos; i++){

		cin >> rows; cin >> cols;
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				cin >> m[i][j];
			}
		}

		int count = 0; int check = 0; int max=0;
		for(int i=0; i<rows; i++)
			for(int j=0; j<cols; j++)
				if(m[i][j]==FILL && !visited[i][j]){
					count++;
					check = dfs(i,j);
					if(check>=max) max = check;
				}
		cout << max << '\n';
		reset_matriz();
	}

	return 0;
}