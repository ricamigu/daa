#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
  int inicio;
  int fim;
} Segmento;

struct compareSegm {
  bool operator()(const Segmento r1, const Segmento r2) {
  	 if (r1.fim > r2.fim) return true;
    if (r1.fim <= r2.fim) return false;

    if (r1.inicio <= r2.inicio) return true;
    if (r1.inicio >	 r2.inicio) return false;
    return false;
  }
};

int cobertura_minima(Segmento v[], int max){

	int end=0;
	int k=0; int i=0;

	while(end < max){

		if(v[i].inicio <= end && v[i].fim > end){
			end = v[i].fim;
			k++;
			i=0;
		}
		else i++;
	}

	return k;
}

int main(){

	int m;
	cin >> m;
	int n;
	cin >> n;
	Segmento retas[n];

	for(int i=0; i<n; i++){
		cin >> retas[i].inicio;
		cin >> retas[i].fim;
	}

	sort(retas, retas+n, compareSegm());

	cout << cobertura_minima(retas, m) <<endl;

	return 0;
}