#include <iostream>
#include <time.h>
#include <string>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>



ALLEGRO_DISPLAY* Ventana = NULL;
ALLEGRO_BITMAP* Map = NULL;
ALLEGRO_FONT* TEMP = NULL;
ALLEGRO_BITMAP* Pacman = NULL;
ALLEGRO_BITMAP* Pac_Up = NULL;
ALLEGRO_BITMAP* Pac_Rig = NULL;
ALLEGRO_BITMAP* Pac_Lef = NULL;
ALLEGRO_BITMAP* Pac_Dow = NULL;

ALLEGRO_COLOR Negro = al_map_rgb(0, 0, 0);
ALLEGRO_COLOR Blanco = al_map_rgb(255, 255, 255);

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
//1 muros  0 camino


char MAPA[24][24] =
{
	"XXXXXXXXXXXXXXXXXXXXXXX",
	"X          X          X",
	"X XXX XXXX X XXXX XXX X",
	"X XXX XXXX X XXXX XXX X",
	"X                     X",
	"X XXX X XXXXXXX X XXX X",
	"X     X    X    X     X",
	"XXXXX XXXX X XXXX XXXXX",
	"XXXXX X         X XXXXX",
	"XXXXX X XXX XXX X XXXXX",
	"        XXX XXX        ",
	"XXXXX X XXX XXX X XXXXX",
	"XXXXX X XXXXXXX X XXXXX",
	"XXXXX X         X XXXXX",
	"XXXXX X XXXXXXX X XXXXX",
	"X          X          X",
	"X XXX XXXX X XXXX XXX X",
	"X   X             X   X",
	"XXX X X XXXXXXX X X XXX",
	"X     X    X    X     X",
	"X XXXXXXXX X XXXXXXXX X",
	"X                     X",
	"XXXXXXXXXXXXXXXXXXXXXXX",
};


void Createmap() {
	
	al_draw_bitmap(Map, 0, 0, 0);
}



class Pac_MAN {
private:
	 int vel;
	 float posinx;
	 float posiny;

public:

	Pac_MAN(float, float, int);
	float pos_inx();
	float pos_iny();
	void dir(int i);
	int velmax(); 

};
void Pac_MAN::dir(int i) {
	if (i == 0) { Pacman = Pac_Up; }
	if (i == 1) { Pacman = Pac_Dow; }
	if (i == 2) { Pacman = Pac_Rig; }
	if (i == 3) { Pacman = Pac_Lef; }
}

Pac_MAN:: Pac_MAN(float px, float py, int Vl) {
	posinx = px;
	posiny = py;
	vel = Vl;
}

int Pac_MAN::velmax(){
	return vel;
} 

float Pac_MAN::pos_inx() {
	return posinx;
}

float Pac_MAN::pos_iny()
{
	return posiny;
}


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



void Alasitas(){
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

void PaC_Man(){

al_init();

	

	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	Ventana= al_create_display(460,460);

	//TEMP = al_load_font("Fuentes/VCR_OSD_MONO_1.001.ttf",25,0);
	Map = al_load_bitmap("Maps/map.bmp");


	Pacman = al_load_bitmap("Ar/Characters/Pacman/Pac_Up.png");
	Pac_Up  = al_load_bitmap("Ar/Characters/Pacman/Pac_Up.png");
	Pac_Rig = al_load_bitmap("Ar/Characters/Pacman/Pac_Right.png");
	Pac_Lef = al_load_bitmap("Ar/Characters/Pacman/Pac_Left.png");
	Pac_Dow = al_load_bitmap("Ar/Characters/Pacman/Pac_Down.png");


	ALLEGRO_TIMER* TIME = al_create_timer(1.0);
    ALLEGRO_TIMER* FPS = al_create_timer(1.0 / 20);

	ALLEGRO_EVENT_QUEUE* qvuve = al_create_event_queue();



	
	al_register_event_source(qvuve,al_get_timer_event_source(TIME));
	al_register_event_source(qvuve, al_get_timer_event_source(FPS));
	al_register_event_source(qvuve, al_get_keyboard_event_source());


	al_start_timer(TIME);
	al_start_timer(FPS);



	al_set_window_title(Ventana,"Pac Man.exe");


	Createmap();

	Pacman = Pac_Rig;
	Pac_MAN p1(200, 320, 5);


	int D_i=-1;
	float P_x= p1.pos_inx();
	float P_y= p1.pos_iny();

	al_draw_bitmap(Pacman, p1.pos_inx(), p1.pos_iny(), 0);
	string D = "Right";
	while (true) {
		ALLEGRO_EVENT Ev;
		
		
		al_wait_for_event(qvuve, &Ev);
		if (Ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (Ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				D = "UP";
				D_i = 0;
				p1.dir(D_i);
				break;
			case ALLEGRO_KEY_DOWN:
				D = "Down";
				D_i = 1;

				p1.dir(D_i);
			
				break;
			case ALLEGRO_KEY_RIGHT:
				D = "Right";
				D_i =2;
				p1.dir(D_i);
			
				break;
			case ALLEGRO_KEY_LEFT:
				D = "Left";
				D_i = 3;
				p1.dir(D_i);
				break;
				
			case ALLEGRO_KEY_ESCAPE:
				return -1;
				break;
			
			}
		
		}
		al_clear_to_color(Negro);
		Createmap();
		if (P_x <= 0 && P_y ==200) { 
		
			P_x = 455;
			al_draw_bitmap(Pacman, P_x,  P_y, 0); 
		}
		if (P_x >= 460 && P_y == 200) {
		
			P_x = 5;
			al_draw_bitmap(Pacman, P_x, P_y, 0);
		}
		int P_mx = (int(P_x))/ 20;
		int P_mx2 = (int(P_x)) / 20;

		int P_my = (int(P_y)-5) / 20;
		int P_my2 = (int(P_y)+20) / 20;

		int P_my3 = (int(P_y)) / 20;
		int P_mx3 = (int(P_x)-5) / 20;

		int P_my4 = (int(P_y)) / 20;
		int P_mx4 = (int(P_x) + 20) / 20;
		

		if (D_i == 0) { 
			if (MAPA[P_my][P_mx] != 'X') { P_y -= p1.velmax(); }				
		}
		if (D_i == 1) { 
			if (MAPA[P_my2][P_mx2] != 'X' ) { P_y += p1.velmax(); }				 
		}

		if (D_i == 2) { 
			if(MAPA[P_my4][P_mx4] != 'X') { P_x += p1.velmax(); } 
		}
		if (D_i == 3) {
			if (MAPA[P_my3][P_mx3] != 'X') { P_x -= p1.velmax(); }	
		}

		if (D_i == -1) { al_draw_bitmap(Pacman, p1.pos_inx(), p1.pos_iny(), 0); }

		float x =  P_x;
		float y =  P_y;

		cout <<"Posx =  " << x << "  Posy=  " << y << "  PMx= " << P_mx3<<"  Pmy3= "<< P_my3 << "  Dir = " << D << endl;

		al_draw_bitmap(Pacman, x, y, 0);

		al_flip_display();
	}
}

void JdH(){
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

}
void Doojump(){
	 srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(30);

    Texture t1,t2,t3;
    t1.loadFromFile("/home/benja/Documentos/cpp/background.png");
    t2.loadFromFile("/home/benja/Documentos/cpp/platform.png");
    t3.loadFromFile("/home/benja/Documentos/cpp/doodle.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    point plat[20];

    for (int i=0;i<10;i++){
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

    int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen()){
        Event e;
        while (app.pollEvent(e)){
            if (e.type == Event::Closed)
                app.close();
        	}

  		 if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
   		 if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    	dy+=0.2;
    	y+=dy;
    		if (y>500)  dy=-10;

    		if (y<h)
    			for (int i=0;i<10;i++){
    				 y=h;
     				 plat[i].y=plat[i].y-dy;
    			  if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    			}

   			 for (int i=0;i<10;i++)
   				  if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
    					  && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

  					sPers.setPosition(x,y);
   					//esto deberia cerrar la ventana
					sf::Vector2f pop=sPers.getPosition();
   					if (pop.y <= 150){
						app.close();
						}
					app.draw(sBackground);
    					app.draw(sPers);
    					for (int i=0;i<10;i++){
    						sPlat.setPosition(plat[i].x,plat[i].y);
    						app.draw(sPlat);
  						  }

   				 app.display();
				}
}

int main (){
	cout << "Ingrese el juego:"<<endl;
	cout << "1 Alasitas"<<endl;
	cout << "2 Pacman" <<endl;
	cout << "Juegos del hambre"<<endl;
	cout << "Doodle jump"<<endl;
	int n_1 ;
	cin >> n_1;
	cout << "Ingresar: ";
	if(n_1 == 1){
	while(true){Alasitas();}
	}
	if(n_1== 2){
	while(true){PaC_Man();}
	}
	if(n_1 ==3 ){
	while(true){JdH();}
	}
	if(n_1 == 4){
	while(true){DooJump();}
	}
	return 0;
}

