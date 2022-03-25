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
int main() {

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
	return 0;
}
