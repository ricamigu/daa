#include <iostream>
#include <set>     
#include <map>     
#include <string>  

using namespace std;

int main(){

	multiset<int> baks; 
	multiset<int>::iterator it;
	int a; int r; cin >> a; cin >> r;
	string opcao;
	int n;
	int size = a+r;

	for(int i=0; i<size; i++){
		cin >> opcao;
		if(opcao=="BAK"){
			cin >> n;
			it = baks.insert(n);
			//it++;
		}
		else if(opcao=="MIN") {
				it = baks.begin();
				cout << *baks.begin() << '\n';
				baks.erase(it);
			}
		else if(opcao=="MAX") {
				it = baks.end();
				it--;
				cout << *it << '\n';
				baks.erase(it);     		
		}
		/*
		printf("elementos: ");
		for (auto i : baks)
    		printf("%d ", i);
  		putchar('\n');
  		*/
	}
}