#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int seq_total(int v[], int a, int b){

	int max_so_far = -2001, max_ending_here = 0;

    for (int i = a; i < b; i++)
    {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


float sms(int v[], int a, int b){

	if(a==b) return v[a];
	int meio = (a+b)/2;
	float best1, best2, best3;

	best1 = sms(v,a,meio);
	best2 = sms(v,meio+1,b);
	best3 = seq_total(v,a,b);

	return max( max(best1,best2), best3);

}

int main(){

	int n;
	cin >> n;
	int v[n];

	for(int i=0;i<n;i++){
		cin >> v[i];
	}

	cout << sms(v,0,n-1) << endl;

	return 0;

}