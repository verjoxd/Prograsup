#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<cstdlib>
#include <iomanip>

using namespace std;
class alasitas{
public:
void almacenar(string personajes[],string mf[][6]){
	int aux=0;
	int i=0;
	int f=0;
	while(aux<=5){
				for(int j=0;j<=5;j++){
					mf[i][j]=personajes[f];
					f++;
				}
				f=f;
				i++;
				aux++;
	}
}
void imprimir(string mf[][6],string filas[]){
	cout << setw( 120 ) << setfill( '-' ) << '\n' << setfill( ' ' );
	for (int x=0;x<6;x++){
		cout<<"| "
      	<< left << setw( 15 ) << filas[x];
		for(int y=0;y<6;y++){
			cout<< "| "
      		<< left << setw( 15 ) << mf[x][y];
		}
		cout<<"| ";
		cout << setw( 120 ) << setfill( '-' ) << '\n' << setfill( ' ' ) << '\n';
	}
}


int val(string x,string y[],string z[]){
	int aux=0;
	for(int i=0;i<36;i++){
		if(x==y[i]){
			aux=1;
			break;
		}
	}
	if(aux==0){
		for(int j=0;j<6;j++){
		if(x==z[j]){
			aux=1;
			break;
		}
	}
	}
	return aux;
}
int randcasa(int n, int jug){
	int y;
	if(n<=8){
		y=rand()%(100-0)+0;
	}
	if(n>15 && n<20 || jug>5 && jug<10){
		y=rand()%(100-25)+25;
	}
	if(n >= 20 || jug>=10){
		y=y=rand()%(100-50)+50;
	}
	return y;
}
int randcart(){
	int x=rand()%(36-1)+1;
	return x;
}
int filas(string mf[][6],string auxc,string auxd, string fil[]){
	int aux=0,auxa=0; 
	for (int i=0;i<6;i++){
		for (int j=0;j<6;j++){
			if(auxc==mf[i][j]){
				aux=i;
				break;
			}
		}
	}
	if(fil[aux]==auxd){
		return auxa=1;
	}	
}
void choice(int n,string personajes[],string filas[], string choices[]){
	cout<<endl<<"Escriba correctamente su eleccion \n";
	string ch;
	int x;
	for(int i=1;i<=n;i++){
		do{
		cout<<"Jugador "<<i<<" elija su personaje o su fila: "<<endl;
		cin>>ch;
		x=val(ch,personajes,filas);
		if(x==0){
			cout<<"Error!!\n";
		}
		}while(x==0);
		choices[i-1]=ch;
	}
}
void cartas(string per[],string fil[], string ch[],string mf[][6],int n){
	int x,y,jug=0,auxa=0,auxb=0;
	string auxc,auxd;
	srand(time(NULL));
	int casa=0;
	do{
		x=randcasa(n,jug);
		if(x>90){
			cout<<"!!!!!!!!!!!!!!!!!EL DIABLO!!!!!!!!!!!!!!!!!!"<<endl;
			break;
		}else{
			y=randcart();
			cout << setw( 19 ) << setfill( '-' ) << '\n' << setfill( ' ' );
			cout<<endl;
			cout<<"| "
      		<< left << setw( 15 ) <<per[y-1];
      		cout<<"|";
			cout << setw( 19 ) << setfill( '-' ) << '\n' << setfill( ' ' )<<endl;
			auxc=per[y-1];
			for(int i=0;i<n;i++){
				if(per[y-1]==ch[i]){
					cout<<"El jugador "<<i+1<<" gano 30Bs!"<<endl;
				}else{
					auxd=ch[i];
					auxb=filas(mf,auxc,auxd,fil);
					if(auxb==1){
						cout<<"El jugador "<<i+1<<" gano 5Bs!"<<endl;
					}
				}
			}
		}
		jug++;
		int h;
		do {
			h=0;
			cout << "Pulse 1 y enter para continuar...";
			cin>>h;
		}while(h==0);
		
		
	}while(casa==0);
	
}
};
int main(){
	cout<<"PASE CASERO!!! \n"<<"Bienvenido al juego de apuestas donde puedes duplicar tu inversion :D \n"<<"Estas listo? \n"<<"1.- SI \n2.- NO \n";
	int x,n;
	string b;
	cin>>x;
	if (x==1){
	//system("cls");
	string mf[6][6];
	string filas[] = {"Fila_1","Fila_2","Fila_3","Fila_4","Fila_5","Fila_6"};
	string personajes[] = {"Bolivar","Tigre","San_Jose","Universitario","Real_Potosi","Wilsterman",
						"Chavo","Bruja_71","Dn_Florinda","Chilindrina","Don_Ramon","Quico",
						"Bob_Patino","Krusty","Lisa","Bart","Homero","Marge",
						"Batman","Superman","Spiderman","Hulk","Viuda Negra","Flash",
						"Roman","Batista","Jhon_Cena","Undertaker","Triple_H","Miz",
						"Luna","Sol","Corazon","Estrella","Diamante","Copo"};
	cout<<"Instrucciones del juego: \nCada jugador podra apostar tanto a su personaje favorito, como a su fila de la suerte. En este juego usted tiene muchas posibilidades de ganar! \nCada fila cuesta 10Bs y podra ganar 5Bs por personaje y cada personaje cuesta 5Bs y si le llega a tocar ganara 30Bs!! \nSi sale Diablo, la casa gana! >:)\n";
	cout<<"Cuantos jugadores van a jugar?\n";
	cin>>n;
	cout<<"Presione 'S' para continuar....\n";
	cin>>b;
	string choices[n];
	if(b=="s"||b=="S"){
		//system("cls");
		alasitas juego;
		juego.almacenar(personajes,mf);
		juego.imprimir(mf,filas);
		juego.choice(n,personajes,filas,choices);
		juego.cartas(personajes,filas,choices,mf,n);
	}
	}
}



