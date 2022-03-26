#include <iostream>
#include <stdlib.h>
#include <time.h> //para numero random
#include <string.h>
#include <stdio.h>


using namespace std;

class juego{
    public: 
    
    void imprimir(int n,int jugador[]){
		for(int i=0;i<n;i++){
			cout<<jugador[i]<<", ";
		}
	}

    void jugadores(int n, string jugador[]){
        cout<<"Ingrese los nombres de los jugadores "<<endl;
        for (int i=0;i<n;i++){
            cout<<"Jugador "<<i+1<<endl;
            cin>>jugador[i];
            cout<<endl;
        }
    }

    int randomp(int n){
        int x;
        x=rand()%((n)-0)+0;
        return x;
    }
    
 
   

    void etapa_1(int pos1,int n,int auxp1,int auxp2, string jugador[]){
        int rando;
        rando = rand()%(6-1)+1;
        
        //opciones de la historia 
        if(rando==1){
            cout<<" Sucedio un accidente, un lobo se comio al jugador "<<jugador[auxp1]<<" y queda descalificado "<<endl;
            
            //n=n-1;

        }
        if(rando==2){
            cout<<"Oh no, "<<jugador[auxp2]<<" Rompio la pierna de "<<jugador[auxp1]<<"; "<<jugador[auxp1]<<" queda descalificado "<<endl;
            

        }
        if(rando==3){
            cout<<"Mientras el jugador "<<jugador[auxp1]<<" comía a medio dia, se atraganta y queda descalificado "<<endl;
            

		}
        if(rando==4){
            cout<<"Los jugadores "<<jugador[auxp2]<<" y "<<jugador[auxp1]<<" se encuentran en una cabaña, tras batallar con palitos el jugador "<<jugador[auxp1]<<" pierde y es descalificado"<<endl;
        	

		}
        if(rando==5){
            cout<<"Una flecha perdida impacta a "<<jugador[auxp1]<<" , queda descalificado "<<endl;
			

		}
        if(rando==6){	//descalifico 2 jugadores
            cout<<"Los jugadores "<<jugador[auxp2]<<" y "<<jugador[auxp1]<<" iban juntos y "<<jugador[auxp2]<<" lanza al barranco a "<<jugador[auxp1]<<" y lo descalifica "<<endl;
        
		}
    }
    
    void etapa_2(int pos1,int n,int auxp1,int auxp2, string jugador[]){
		int rando;
        rando = rand()%(6-1)+1;
        //opciones de la historia 
        if(rando==1){
            cout<<"Empieza la limpieza y el "<<jugador[auxp1]<<" estaba fuera del area del juego, queda descalificado "<<endl;
            
        }
        if(rando==2){
            cout<<"El jugador "<<jugador[auxp2]<<" roba las pertenencias del jugador "<<jugador[auxp1]<<" y queda sin proviciones para sobrevivir una noche helada, "<<jugador[auxp1]<<" queda descalificado "<<endl;
        	
		}
        if(rando==3){
            cout<<"El jugador "<<jugador[auxp1]<<" se encuentra con una banda de aliados y se les une;\n pero luego los traiciona, por lo que lo ahogan y queda descalificado"<<endl;
        
		}
        if(rando==4){
            cout<<"La noche se aproxima y "<<jugador[auxp1]<<" decide dormir debajo de un molle, baja una araña venenosa, lo pica y es descalificado"<<endl;
        	
		}
        if(rando==5){
            cout<<jugador[auxp1]<<" estas creando un veneno en forma de spray, al hacer la prueba disparas mal y te lo hechas encima por lo que quedas descalificado "<<endl;
        
		}
        if(rando==6){	//descalifico 2 jugadores
            cout<<"Cuando salio el sol "<<jugador[auxp2]<<" y "<<jugador[auxp1]<<" decidieron buscar moras de desayuno que resultan ser venenosas, "<<jugador[auxp2]<<" sobrevive pero "<<jugador[auxp1]<<" no, queda descalificados"<<endl;
        
		}
    }

    void etapa_3(int pos1,int n,int auxp1,int auxp2, string jugador[]){
		int rando;
        rando = rand()%(6-1)+1;
        //opciones de la historia 
        if(rando==1){
            cout<<"La zona de juego se reduce cada vez mas y "<<jugador[auxp1]<<" se queda dormido fuera de ella, el gas venenoso lo descalifica"<<endl;
        
		}
        if(rando==2){
            cout<<"Oh no, "<<jugador[auxp2]<<" disparo a "<<jugador[auxp1]<<" en el corazon usando un arma secreta, "<<jugador[auxp1]<<" queda descalificado"<<endl;
        
		}
        if(rando==3){
            cout<<"En la cima de una montaña "<<jugador[auxp1]<<" vigilaba el perímetro, pero por estar en puesto de campero queda descalificado "<<endl;
       
		}
        if(rando==4){
            cout<<"Los organizadores entregan un botiquin a "<<jugador[auxp2]<<" pero "<<jugador[auxp1]<<" esta herido, lucha para obtener el botiquin per falla; "<<jugador[auxp1]<<" descalificado"<<endl;
       
		}
        if(rando==5){
            cout<<"Una vivora muerde a "<<jugador[auxp1]<<" por su toxicidad, queda descalificado "<<endl;
      
		}
        if(rando==6){
            cout<<"El jugador "<<jugador[auxp2]<<" trata de salvar al jugador "<<jugador[auxp1]<<" de la muerte, no lo logra y "<<jugador[auxp1]<<" es descalificado"<<endl;
        
		}
    }

    void etapa_fin(int pos1,int n,int auxp1,int auxp2, string jugador[]){
		int rando;
        rando = rand()%(3-1)+1;
        //opciones de la historia 
        if(rando==1){ //good ending
            cout<<"Hora del gran duelo, la zona resstringida es de a penas unos metros, "<<jugador[auxp1]<<" posee una lanza hecha de piedra\n ; "<<jugador[auxp2]<<" sólo tiene un mazo de madera\n tras mucho esfuerzo físico y pruebras de aptitud física\n el jugador "<<jugador[auxp1]<<" clava su lanza en el corazon del contrincante\n el jugador"<<jugador[auxp1]<<" es el ganador"<<endl;

		}
        if(rando==2){ //normal ending
            cout<<"Exactamente cuando la hora marca las 6 de la mañana "<<jugador[auxp2]<<" y "<<jugador[auxp1]<<" se preparan para la pelea final\n Luego de horas de analisis y tacticas el jugador "<<jugador[auxp1]<<" se prepara para el ataque sorpresa\n pero los calculos fallan y termina suicidandose\n El jugador "<<jugador[auxp1]<<" GANA"<<endl;
  
		}
        if(rando==3){ //bad ending
            cout<<"El momento de la verdad, así como un duelo de ninjas los jugadores "<<jugador[auxp1]<<" y "<<jugador[auxp2]<<" buscan salvar sus vidas, pero el cielo se vuelve gris\n, una figura brillante y rosada aparece en medio y los mata a los dos\n Nadie gana"<<endl;
    
		}
    }


    void dias(int i,int pos1,int n,int auxp1,int auxp2, string jugador[]){
      // int ndias=10;
        //for(int i=1;i<=n;i++){
        	
			
            if(n>7 && n<=10){//7 a 10
            
            	cout<<endl;
                cout<<"\t \t \t ETAPA 1 \n\tDia "<<i+1<<endl<<endl;
                etapa_1(pos1,n,auxp1,auxp2,jugador);
                cout<<endl;
            }

            if(n>5 && n<=7){//5 a 7
            
            	cout<<endl;
                cout<<"\t \t \t ETAPA 2 \n\tDia "<<i+1<<endl<<endl;
                etapa_2(pos1,n,auxp1,auxp2,jugador);
                cout<<endl;
            }

            if(n>2 && n<=5){//3 a 4
            	
            	cout<<endl;
                cout<<"\t \t \t ETAPA 3 \n\tDia "<<i+1<<endl<<endl;
                etapa_3(pos1,n,auxp1,auxp2,jugador);
                cout<<endl;
            }

            if(n==2){
            	cout<<endl;
                cout<<"\t \t \t ETAPA FINAL \n\tDia "<<i+1<<endl<<endl;
                etapa_fin(pos1,n,auxp1,auxp2,jugador);
                cout<<endl;
                
            }
           
        //}
    }
};


int main(){
    int n;  
    do{
    	cout<<"Ingrese el numero de jugadores: "<<endl;
    	cin>>n;
	}while(n<2 || n>10);
    
    
    cout<<"Sean bienvenidos jugadores, el juego consta de 4 etapas"<<endl;
    cout<<"\¿Listos para probar su suerte?"<<endl<<endl;
    cout<<"Solo puede sobrevivir uno, ese sera el ganador"<<endl;
    cout<<"¿Llegaras a la etapa final?"<<endl<<endl;
    cout<<"JUEGO DE 2 a 10 JUGADORES"<<endl;
    cout<<"Segun el numero de jugadores se iran saltando el numero de etapas"<<endl;
    cout<<endl;
    cout<<endl;
    
    //string elim[n]={};
    int pos1,i=0,rando;
    int auxp1,auxp2;
    int num = n;
    string jugador[n]={};   //vector que admite varios valores
    int muertes[n-1]={};
    
    juego game;
    game.jugadores(n,jugador);
    
    srand(time(NULL));
    
   while(n>=2){	
    	rando=game.randomp(n);					
    	do{	
    		auxp1=game.randomp(num);
    	    auxp2=game.randomp(num);
    	    	for(int k=0;k<i;k++){    //limite del array
    				if(auxp1==muertes[k]){
    					auxp1=auxp2;
					}
				}
    	}while(auxp1==auxp2);
    	
    	muertes[i]=auxp1;
    	game.dias(i,pos1,n,auxp1,auxp2,jugador);
		n--;
		i++;
    }
    game.imprimir(i,muertes);
    return 0;
}

