#include <iostream>
#include <string>
#include <math.h>

using namespace std;

float cx, cy, raio;

bool checkOverlap(float cx, float cy, float x1, float y1, float x2, float y2,float lado) 
{ 
  
    float Xn = max(x1, min(cx, x2)); 
    float Yn = max(y1, min(cy, y2)); 
      
    float Dx = Xn - cx; 
    float Dy = Yn - cy;

    return (Dx * Dx + Dy * Dy) <= lado * lado; 
}


float area_circulo(int r){
	return M_PI * pow(r,2); 
}

float area_rect(float l){
	return l*l;
}

float intersecao(float x1, float y1, float x2, float y2, float lado){
	
	
	if (cx+raio < x1 && cx-raio > x1+lado && cy + raio < y1 && cy - raio > y1+lado) return 0;
	//if( !checkOverlap(cx,cy,x1,y1,x2,y2,lado) ) return 0;
	if( (x1 <= cx-raio) && (y1 <= cy-raio) && (x2 >= cx+raio) && (y2 >= cy+raio) ) return area_circulo(raio); // circulo totalmente dentro
	if ( (x1 >= cx-raio) && (y1 >= cy-raio) && (x2 <= cx+raio) && (y2 <= cy+raio) ) return area_rect(lado);
	float area = 0;

	if( lado >= 0.0005){
		area = area + intersecao(x1, y1+(lado/2), x2-(lado/2), y2, lado/2); //subquadrado superior esquerdo
		area = area + intersecao(x1+(lado/2),y1+(lado/2),x2,y2,lado/2); //subquadrado superior direito
		area = area + intersecao(x1,y1,x2-(lado/2),y2-(lado/2),lado/2); //subquadrado inferior esquerdo
		area = area + intersecao(x1+(lado/2),y1,x2,y2-(lado/2),lado/2); //subquadrado inferior direito
	}

	return area;
}

int main(){

	int n;
	int qx, qy, ql, cx1, cy1, cr;

	//cin >> n;
	cin >> qx; cin >> qy; cin >> ql; cin >> cx1; cin >> cy1; cin >> cr;
	cx = cx1;
	cy = cy1;
	raio = cr;

	int x2=qx+ql;
	int y2=qx+ql;

	cout << intersecao(qx,qy,x2,y2,ql) << endl;

	return 0;

}