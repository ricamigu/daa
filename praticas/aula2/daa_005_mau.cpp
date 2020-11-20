#include <iostream>

using namespace std;

int calcular(int a, int b, int v[]){

	int soma=0;

	for(int i=a; i<=b;i++){
		soma += v[i];
	}

	return soma;
}

int main(){

	int n;
	cin >> n;
	int vecN[n];

	for(int i=1;i<=n;i++){
		cin >> vecN[i];
	}

	int m;
	cin >> m;
	int a[m], b[m];

	for(int i=1;i<=m;i++){
		cin >> a[i];
		cin >> b[i];
	}

	for(int i=1;i<=m;i++){
		cout << calcular(a[i],b[i],vecN) << endl;
	}

}