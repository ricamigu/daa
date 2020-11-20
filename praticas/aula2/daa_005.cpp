#include <iostream>
#include <string>

using namespace std;

int * soma_total(int v[], int size){

	int* vec = new int[size+1];
	int soma=0;
	vec[0]=soma;

	for(int i=1;i<=size+1;i++){
		soma += v[i]; 
		vec[i] = soma;
	}

	return vec;
}

int main(){

	int n;
	cin >> n;
	int vecN[n+1]; vecN[0]=0;

	for(int i=1;i<=n;i++){
		cin >> vecN[i];
	}


	int m;
	cin >> m;
	int a[m+1], b[m+1]; a[0]=0;b[0]=0;
	int *s = soma_total(vecN,n);

	for(int i=1;i<=m;i++){
		cin >> a[i];
		cin >> b[i];
	}

	for(int i=1;i<=m;i++){
		int soma = s[b[i]] - s[a[i]-1];
		cout << soma << endl;
	}

	return 0;

}