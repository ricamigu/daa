#include <iostream>
#include <string>

using namespace std;

int somar(int n){

	int soma = 0;
	int r;

	while( n>0){
		r = n % 10;
		n = n / 10;
		cout << n << endl;
		soma += r;
	}

	return soma;
}


int main(){
	
	int n;
	cin >> n;
	int vecN[n], vecV[n];

	//int count=0;
	int num, soma=0, valor;
	
	for(int i=0; i<n; i++){

		cin >> num;
		cin >> valor;

		vecN[i] = num;
		vecV[i] = valor;

	}

	for(int i=0; i<n; i++){

		num = vecN[i];
		valor = vecV[i];
		soma = 0;
		//soma = somar(num+1);
		
		while(soma != valor){
			//cout << "soma:" << soma << " != " << valor << endl;
			num++;
			soma = somar(num);
		}

		cout << num << endl;
	}

	return 0;
}