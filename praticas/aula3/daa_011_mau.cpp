#include <iostream>
#include <algorithm>

using namespace std;

int bsearch(bool v[], int low, int high){

  while(low < high){
    int middle = low + (high - low)/2;

    if(v[middle]) high = middle;
    else low = middle+1;

  }

  return low;
}

bool is_possible(int v[], int size, int x, int k){

  int soma=0;
  int part=0;
  int max=0;

  for(int i=0; i<size; i++){
    if(soma + v[i] <= x) soma += v[i];
    else { 
      if(soma==0) return false;
      if(soma>max) max=soma;
      soma=v[i]; part++; 
    }
  }
  
  if(max>x) return false;
  if(part+1>k) return false;

  return true;
}

int sum(int v[], int size){

  int soma=0;

  for(int i=0; i<size; i++){
    soma += v[i];
  }

  return soma;
}

int main() {

  int n; cin >> n;
  int dist[n];
  int s=0;
  for(int i=0;i<n; i++){
    cin >> dist[i];
    s += dist[i];
  }

  //int s = sum(dist,n);
  bool arr[s+1];
  int q; cin >> q;
  int p[q];
  for(int i=0; i<q;i++){
    cin >> p[i];
  }

  for(int i=0; i<q; i++){

    for(int j=1;j<=s; j++){
      arr[j] = is_possible(dist, n, j, p[i]);
    }

    cout << bsearch(arr, 1, s) << endl;

    //arr[s+1] = {false};

  }

  return 0;
}