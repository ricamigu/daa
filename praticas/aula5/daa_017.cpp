#include <iostream>

using namespace std;

int main(){
	
	int n; cin >> n;
	int matriz[n+1][n+1] = {0};
	int d; cin >> d;
	int cam, pos;

	// colocar 1s na posicao da piramide
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			matriz[i][j] = 1;
		}
	}

	// colocar pedras mas nas posicoes certas
	for(int i=0; i<d; i++){
		cin >> cam;
		cin >> pos;
		matriz[n+1-cam][pos] = -1;
	}

	long long count[n+1][n+1] = {0};
	for(int i=n; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(matriz[i][j]!=-1) count[i][j] = 1;
		}
	}

	for(int i=n-1; i>=1; i--){
		for(int j=n-1; j>=1; j--){
			if(matriz[i][j]==1) count[i][j] += count[i+1][j] + count[i+1][j+1];
		}
	}
	cout << count[1][1] << endl;
	return 0;
}