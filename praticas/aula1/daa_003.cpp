#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>

using namespace std;

//XX-NN-NN
int matricula_1(string s){

	int num=0;
	//int divisor = 100000;

	if(s[0] >= 'K' && s[0] < 'W') s[0]=s[0]-1;
	if(s[0] >= 'W' && s[0] < 'Y') s[0]=s[0]-2;
	if(s[0] >= 'Y') s[0]=s[0]-3;

	if(s[1] >= 'K' && s[1] < 'W') s[1]=s[1]-1;
	if(s[1] >= 'W' && s[1] < 'Y') s[1]=s[1]-2;
	if(s[1] >= 'Y') s[1]=s[1]-3;

	num = (23 * (s[0] - 65)) * 10000 + ( (s[1] - 65)) * 10000 + ((s[3] - '0')) * 1000 + ((s[4] - '0')) * 100 + ((s[6] - '0')) * 10 + ((s[7] - '0')*1);

	return num;

}

//NN-NN-XX
int matricula_2(string s){

	int num=5290000;
	//int divisor = 100000;

	if(s[6] >= 'K' && s[6] < 'W') s[6]= s[6]-1;
	if(s[6] >= 'W' && s[6] < 'Y') s[6]= s[6]-2;
	if(s[6] >= 'Y') s[6]=s[6]-3;

	if(s[7] >= 'K' && s[7] < 'W') s[7]=s[7]-1;
	if(s[7] >= 'W' && s[7] < 'Y') s[7]=s[7]-2;
	if(s[7] >= 'Y') s[7]=s[7]-3;

	num += (23 * (s[6] - 65)) * 10000 + ( (s[7] - 65)) * 10000 + ((s[0] - '0')) * 1000 + ((s[1] - '0')) * 100 + ((s[3] - '0')) * 10 + ((s[4] - '0')*1);

	return num;

}

//NN-XX-NN
int matricula_3(string s){

	int num=5290000*2;
	//int divisor = 100000;

	if(s[3] >= 'K' && s[3] < 'W') s[3] = s[3]-1;
	if(s[3] >= 'W' && s[3] < 'Y') s[3] = s[3]-2;
	if(s[3] >= 'Y') s[3] = s[3]-3;

	if(s[4] >= 'K' && s[4] < 'W') s[4] = s[4]-1;
	if(s[4] >= 'W' && s[4] < 'Y') s[4] = s[4]-2;
	if(s[4] >= 'Y') s[4] = s[4]-3;

	num += (23 * (s[3] - 65)) * 10000 + ( (s[4] - 65)) * 10000 + ((s[0] - '0')) * 1000 + ((s[1] - '0')) * 100 + ((s[6] - '0')) * 10 + ((s[7] - '0')*1);

	return num;

}

// XX-NN-XX
// 01 34 67
int matricula_4(string s){

	int num=5290000*3;
	//int divisor = 100000;

	if(s[0] >= 'K' && s[0] < 'W') s[0] = s[0]-1;
	if(s[0] >= 'W' && s[0] < 'Y') s[0] = s[0]-2;
	if(s[0] >= 'Y') s[0] = s[0]-3;

	if(s[1] >= 'K' && s[1] < 'W') s[1] = s[1]-1;
	if(s[1] >= 'W' && s[1] < 'Y') s[1] = s[1]-2;
	if(s[1] >= 'Y') s[1] = s[1]-3;

	if(s[6] >= 'K' && s[6] < 'W') s[6]= s[6]-1;
	if(s[6] >= 'W' && s[6] < 'Y') s[6]= s[6]-2;
	if(s[6] >= 'Y') s[6]=s[6]-3;

	if(s[7] >= 'K' && s[7] < 'W') s[7]=s[7]-1;
	if(s[7] >= 'W' && s[7] < 'Y') s[7]=s[7]-2;
	if(s[7] >= 'Y') s[7]=s[7]-3;

	num += ((s[3] - '0') *10) + ((s[4] - '0') * 1) + ( 23 * (s[6] - 65) * 100) + ((s[7] - 65) * 100) + ( 23*(s[0] - 65) * 52900) + (23*(s[1] - 65) * 2300);
	return num;

}

int tipo_matricula(string s){

	//XX-NN-NN
	if( (isalpha(s[0]) && isalpha(s[1])) && !( isalpha(s[6]) && isalpha(s[7])) ) return 1;

	//NN-NN-XX
	else if ( (isalpha(s[6]) && isalpha(s[7])) && !( isalpha(s[0]) && isalpha(s[1])) ) return 2;

	//NN-XX-NN
	else if ( isalpha(s[3]) && isalpha(s[4])) return 3;

	//XX-NN-XX
	else if( (isalpha(s[0]) && isalpha(s[1])) && ( isalpha(s[6]) && isalpha(s[7])) ) return 4;

	return 0;
}

int main(){
	
	//string s1, s2;
	int n;
	int tipo1,tipo2;
	int val1=-1, val2=-1;
	int dif=-1;


	cin >> n;
	string s1[n], s2[n];

	for(int i=0; i<n; i++){

		//getline(cin, s1[i], ' ');
		//getline(cin, s2[i], ' ');

		cin >> s1[i];
		cin >> s2[i];
	}



	for(int i=0; i<n; i++){

		tipo1 = tipo_matricula(s1[i]);
		tipo2 = tipo_matricula(s2[i]);

		switch(tipo1){
			case 1: val1 = matricula_1(s1[i]);
					break;

			case 2: val1 = matricula_2(s1[i]);
					break;

			case 3: val1 = matricula_3(s1[i]);
					break;

			case 4: val1 = matricula_4(s1[i]);
					break;
		}

		switch(tipo2){
			case 1: val2 = matricula_1(s2[i]);
					break;

			case 2: val2 = matricula_2(s2[i]);
					break;

			case 3: val2 = matricula_3(s2[i]);
					break;

			case 4: val2 = matricula_4(s2[i]);
					break;
		}

		dif = abs(val2 - val1);
		
		cout << dif << endl;

	}
	
	return 0;
}