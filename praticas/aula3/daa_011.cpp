#include <iostream>
#include <algorithm>

using namespace std;

bool is_possible(int v[], int size, int x, int k){

  int soma=0;
  int part=0;
  int max=0;

  for(int i=0; i<size; i++){
    if(soma + v[i] <= x) soma += v[i];
    else { 
    //  if(soma==0) return false;
      if(soma>max) max=soma;
      soma=v[i]; part++; 
    }
  }
  
  if(max>x) return false;
  if(part+1>k) return false;

  return true;
}

int bsearch(int v[], int low, int high, int n, int pt){

  while(low < high){
    int middle = low + (high - low)/2;

    if( is_possible(v, n, middle, pt)) high = middle;
    else low = middle+1;

  }

  return low;
}


int main() {

  int n; cin >> n;
  int dist[n];
  int s=0;
  for(int i=0;i<n; i++){
    cin >> dist[i];
    s += dist[i];
  }

  int q; cin >> q;
  int p[q];
  for(int i=0; i<q;i++){
    cin >> p[i];
  }

  for(int i=0; i<q; i++){
    cout << bsearch(dist, 1, s, n, p[i]) << endl;
  }

  return 0;
}