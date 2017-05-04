#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int main(){
	int ruleta[15]={50,0,125,25,-1,75,500,0,100,25,50,150,200,-1,50};
	string jugadores[3]={"ALBERTO","GONZALO","MARIO"};
	char frase[]="LA RULETA DE LA SUERTE";
	char panel[]="## ###### ## ## ######";
	char pista[]="Este programa es...";
	char letra;
	int i = 0;
	srand(time(NULL));
	int jugador=rand()%3;
	int dinero[3] = {0,0,0};
	bool solucionado = false;
	int posicionruleta;
	while(solucionado==false){
		cout << endl;
		cout << "+----------------------------------------------+" << endl;
		cout << "| Siguiente turno" << endl;
		cout << "| Panel: " << panel << endl;
		cout << "| Pista: " << pista << endl;
		cout << "| Turno de: " << jugadores[jugador] << endl;
		cout << "+----------------------------------------------+" << endl;
		cout << "Pulse ENTER para continuar" << endl;
		cin.ignore();
		srand(time(NULL));
		posicionruleta=rand()%15;
		if(ruleta[posicionruleta]==0){
			cout << "Posicion de la ruleta: Bancarrota" << endl;
			dinero[jugador] = 0;
			jugador = (jugador+1)%3;
		}
		else if(ruleta[posicionruleta]==-1){
			cout << "Posicion de la ruleta: Cambio de turno" << endl;
			jugador = (jugador+1)%3;
		}
		else{
			cout << "Posicion de la ruleta: " << ruleta[posicionruleta] << "€" << endl;
			cout << "Elija una consonante: " << flush;
			cin >> letra;
			i=0;
			while(frase[i]!='\0'){
				if(frase[i]==letra){
					dinero[jugador] = dinero[jugador]+ruleta[posicionruleta];
					panel[i] = letra;
				}
				i++;
			}
			cout << endl;
			cout << panel << endl;
			cout << "Pista: " << pista << endl;
			cout << endl;
			solucionado=true;
			i=0;
			while(frase[i]!='\0'){
				if(frase[i]!=panel[i]) solucionado = false;
				i++;
			}
			if(dinero[jugador]>=100 && solucionado==false){
				cout << "¿Quiere comprar una vocal por 100€? Tiene " << dinero[jugador] << "€" << " (S/N)"<< endl;
				cin >> letra;
				if(letra=='S'){
					dinero[jugador] = dinero[jugador] - 100;
					cout << "Vocal: " << flush;
					cin >> letra;
					cin.ignore();
					i = 0;
					while(frase[i]!='\0'){
						if(frase[i]==letra){
							panel[i] = letra;
						}
						i++;
					}
				}
			}
			solucionado=true;
			i=0;
			while(frase[i]!='\0'){
				if(frase[i]!=panel[i]) solucionado = false;
				i++;
			}
			jugador = (jugador+1)%3;
		}
		cout << endl;
		cout << "Pulse ENTER para continuar" << endl;
		cin.ignore();
	}
	if(jugador!=0){
		jugador = jugador-1;
	}
	else jugador = 2;
	cout << "El ganador es " << jugadores[jugador] << " y se lleva " << dinero[jugador] << " €" << endl;
	return 0;
}
