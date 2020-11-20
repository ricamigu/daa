#include <iostream>
#include <algorithm>

using namespace std;

int sum(int n){
  return (n == 1 || n == 0) ? 1 : sum(n - 1) + n;
}

int bsearch(int v[], int low, int high, int x){

  while(low < high){
    int middle = low + (high - low)/2;

    if(v[middle]>=x) high = middle;
    else low = middle+1;

  }

  if( (v[low]!=x) ) return -1;

  return low;
}

int main() {
  
  int n;
  cin >> n;
  int v[n];
  int m = sum(n-1);
  int somas[m];

  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v, v+n);


  int k=0;
  int p=0;
  for (int i=0; i<n; i++){
    for(int j=1+p; j<n; j++){
      somas[k] = v[i] + v[j];
      k++;
    }
    p++;
  }
  sort(somas, somas+m);


  int q;
  cin >> q;
  int qt[q];

  
  for(int i=0; i<q; i++){
    cin >> qt[i];
  }



  int abso[q];
  for(int i=0; i<q; i++)
    abso[i]=qt[i];


  int val;
  int val2;
  for(int i=0; i<q; i++){
    val = bsearch(somas, 0, m-1, qt[i]);
    val2 = bsearch(somas, 0, m-1, abso[i]);
    while( val == -1 && val2 == -1){
      
      val = bsearch(somas, 0, m-1, qt[i]++);
      val2 = bsearch(somas, 0, m-1, abso[i]--);

    }

    if(val == -1 && val2 != -1) {cout << somas[val2]  << endl;}
    else if(val2 == -1 && val != -1) {cout << somas[val]<< endl;}
    else if(val!=-1 && val2 != -1){
      if(val==val2) cout << somas[val] << endl;
      else {
        cout << somas[val2]<< " ";
        cout << somas[val]  << endl;
      }
    }

  }


  return 0;
}