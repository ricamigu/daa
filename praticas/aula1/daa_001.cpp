#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;

	int count=0;
	int num;

	for(int i=0; i<n; i++){

		cin >> num;

		if( num == 42)
			count++;
	}

	cout << count << endl;

	return 0;
}