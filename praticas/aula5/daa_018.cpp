#include <iostream>
#include <algorithm>

using namespace std;

void moedas(int array[], int n, int p){

	cout << p;
	int coins[p] = {0};
	int use[p] = {0};

	for(int i=1; i<=p; i++){
		coins[i] = 100000001;
		for(int j=0; j<n; j++){
			if(array[j]<=i && 1+coins[i-array[j]] < coins[i]){
				coins[i] = 1 + coins[i- array[j]];
				use[i] = array[j];
			}
		}
	}

	cout << ": [" << coins[p] << "]";

	int print = use[p];
	int p1= p;

	while(print > 0){
		cout << " "<< print;
		print = p1 - print;
		p1 = print;
		print = use[p1];
	}
	
	cout << endl;
}

int main(){

	int n; cin >> n;
	int s[n];
	int qn;

	for(int i=0; i<n; i++){
		cin >> s[i];
	}

	cin >> qn;
	int perg[qn];

	for(int i=0; i<qn; i++){
		cin >> perg[i];
		
	}

	for(int i=0; i<qn; i++){
		moedas(s, n, perg[i]);
	}

	return 0;
}