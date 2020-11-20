#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin >> n;
	int baloes[n];
	int max=0;

	for(int i=0; i<n; i++){
		cin >> baloes[i];
		if(max<baloes[i]) max = baloes[i];
	}

	int counting[max+1] = {0};

	for(int i=0; i<n; i++){
		counting[baloes[i]]++;
	}

	int height;
	int i=0;
	int k=0;
	bool encontrou=false;
	
	/*for(int a=0; a<=max; a++ ){
		cout << "counting[" << a << "]: " << counting[a] << endl;
	}*/
	
	while( i < n ){

		encontrou = false;
		height = baloes[i];

		while(counting[height]>0){
			//cout << "counting[" << height << "]: " << counting[height] << endl; 
			counting[height]--;
			height--;
			if(!encontrou) {
				k++;
				encontrou = true;
			}
		}
		i++;
	}

	cout << k << endl;

	return 0;
}

