// Exemplo de ordenacao customizada de pessoas
// Primeiro por ordem crescente da idade, e em caso de empate por
// ordem crescente alfabetica do nome
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 11/10/2020
// ----------------------------------

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


typedef struct {
  int cont;
  char c;
  int pos;
} Frequencia;

struct compareLetter {
  bool operator()(const Frequencia n1, const Frequencia n2) {
    if (n1.cont > n2.cont) return true;
    if (n1.cont < n2.cont) return false;
    return (n1.pos< n2.pos);
  }
};

int main() {

  string input;
  Frequencia v[26] = { 0 };

  getline(cin, input);
  int size = input.length();

  for(int i=0;i<size; i++){
    if(v[input[i]-65].cont==0) v[input[i]-65].pos = i;
    v[input[i]-65].cont++;
    v[input[i]-65].c = input[i];
  }

  sort(v, v+26, compareLetter());
  
  for (int i=0; i<26; i++)
    if(v[i].cont != 0)
      cout << v[i].c << " " << v[i].cont << endl;
  
  return 0;
}