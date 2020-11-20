// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>
#include <limits>

using namespace std;

// Estrutura para representar um no da arvore
typedef struct node {
  bool isBlack; // No preto?
  bool isNull;  // No nulo?
  int value;    // Valor
  struct node *left, *right; // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v) {
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull  = (v==0);
  aux->isBlack = (v>=0);
  aux->value   = abs(v);
  return aux;
}

// Ler input em preorder
Node readPreOrder() {
  int v;
  cin >> v;
  Node aux = mkNode(v);
  if (v!=0) {
    aux->left  = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}

// Menor valor da arvore
int minimum(Node t) {
  if (t->isNull) return INT_MAX;
  int minLeft  = minimum(t->left);
  int minRight = minimum(t->right);
  return min(t->value, min(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t) {
  if (t->isNull) return INT_MIN;
  int maxLeft  = maximum(t->left);
  int maxRight = maximum(t->right);
  return max(t->value, max(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t) {
  if (t->isNull) return 0;
  return 1 + size(t->left) + size(t->right);
}

// ---------------------------------------------------
// funcoes de verificação

// verificar se é binária
bool binary_tree(Node t, int min, int max){
  if(t->isNull) return true;
  if(t->value < min || t->value > max) return false;
  return binary_tree(t->left,min,t->value-1) && binary_tree(t->right,t->value+1,max);
}

//verificar se root é preta
bool root_property(Node t){
  return(t->isBlack);
}

// verificar se filhos de nós vermelhos são pretos
bool red_property(Node t){
  if(t->isNull) return true;
  if(!t->isBlack && !(t->left->isBlack && t->right->isBlack)) return false; 
  return red_property(t->left) && red_property(t->right);
}

int black_height(Node t){

  int count=0;

  while(!t->isNull){
    t = t->left;
    if(t->isBlack) count++;
  }
  return count;
}

bool black_property(Node t, int bh, int count){

  if(t->isNull) return count==bh;
  if(t->isBlack) count++;
  return black_property(t->left, bh, count) && black_property(t->right, bh, count);

}

int main() {
  int i, n;
  Node root;
  cin >> n;
  int min = std::numeric_limits<int>::min();
  int max = std::numeric_limits<int>::max();
  for (i=0; i<n; i++) {
    root = readPreOrder();
    int bh = black_height(root);
    if(binary_tree(root,min,max) && root_property(root) && red_property(root) && black_property(root,bh,0) ) {
      cout << "SIM" << '\n';
    }
    else cout << "NAO" << '\n';
  }

  return 0;
}