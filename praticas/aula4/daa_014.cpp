#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
  float dias;
  float multa;
  float racio;
  int pos;
} Sapateiro;

struct compareSapatos {
  bool operator()(const Sapateiro s1, const Sapateiro s2) {
  	if (s1.racio > s2.racio) return true;
  	if ( s1.racio < s2.racio) return false;
  	if ( s1.pos < s2.pos  ) return true;
    return false;
  }
};


int main(){

	int n;
	cin >> n;
	Sapateiro encomendas[n];

	for(int i=0; i<n; i++){
		cin >> encomendas[i].dias;
		cin >> encomendas[i].multa;
		encomendas[i].racio = encomendas[i].multa/encomendas[i].dias;
		encomendas[i].pos = i+1;
	}

	sort(encomendas, encomendas+n, compareSapatos());
	
	for(int i=0; i<n; i++){
		if(i<n-1)cout << encomendas[i].pos << " ";
		else cout << encomendas[i].pos << endl;
	}

	return 0;
}