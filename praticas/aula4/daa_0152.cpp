#include <iostream>
#include <algorithm>

using namespace std;

int bsearch(int v[], int low, int high, int x){

  while(low < high){
    int middle = low + (high - low)/2;
    if(v[middle]>=x) high = middle;
    else low = middle+1;
  }

  if( (v[low]!=x) ) return -1;
  return low;
}

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
	bool encontrou;

	while( i <= n ){

		encontrou = false;
		height = baloes[i];

		for(int j=i+1; j<=max; j++){
			if(counting[height]>0){ 
				counting[j]--;
				height--;
				if(!encontrou) k++;
				encontrou=true;
			}
		}
		i++;
	}

	cout << k << endl;

	return 0;
}
