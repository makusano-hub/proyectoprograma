#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_audio.h>


#include "movimiento.h"
#include "pantalla.h"
#include "enemigo.h"
#include "jugador.h"
#include "colision.h"
#include "mapa.h"
#include "hud.h"
#include "camino.h"
#include "torre.h"
#include "obstaculo.h"
#include "bala.h"
#include "menu.h"
#include "ranking.h"

typedef enum{
	EstadoMenu,
	EstadoJugando,
	EstadoRanking,
	EstadoIngresarNombre,
	EstadoDerrota,
	EstadoVictoria
}EstadoJuego;

int main() {

	teclado teclado;
	//Jugador Jugador;// convertir en arreglo de jugadores para multiple entidades de jugadores Jugador jugadore[Maxjugadores]
	Jugador jugadores[MaxJugadores];
	DatosJugador datosjugador;
	Enemigo enemigos[MAxEnemigos];
	Portal spawn[MaxPortales];
	Recursos recursos[MaxRecursos] = {0};
	Menu menu;
	EstadoJuego estado = EstadoMenu;
	ConfigMap configuracion ={0};
	/*Arbol arboles[MaxArboles];
	Oro oros[MaxOro];*/

	HUD hud;
	Camino caminoEnemigos[MaxPortales];
	Torre castillo;
	Torre torres[MaxTorres];

	Bala balas[MaxBalas];
	DatoRanking datosranking;


	char nombreTemporal[10] ="";
	int cantidadLetras =0;

	int cantidadTorres =0;
	//int cantidadEnemigos =0;
	int cantidadPortales = 0;
	int cantRecursos =0;
	
	int framePortal =0;
	int contadorPortal=0;

	char *niveles[]={"matriz.txt","matriz2.txt","matriz3.txt","matriz4.txt"};
	int nivelActual =0;
	int cantidadNiveles = 4;

	int jugadorActivo = lenador;
	TipoTorre torreSeleccionada = torreNormal;


	srand(time(NULL));
	
	al_init(); 
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	//al_install_audio();

	al_install_keyboard();	
	iniciarteclado(&teclado);
	
	
	
	ALLEGRO_DISPLAY *display = crear_pantalla();	
	ALLEGRO_TIMER *timer = al_create_timer(1.0/ 60.0);
	ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();

	ALLEGRO_BITMAP *fondo = al_load_bitmap("../imagenes/fondodepantallam.png");	
	ALLEGRO_BITMAP *terreno = al_load_bitmap("../imagenes/terreno.png");
	ALLEGRO_BITMAP *pasto = al_load_bitmap("../imagenes/GrassCenter.png");
	ALLEGRO_BITMAP *camino = al_load_bitmap("../imagenes/muro.png");
	ALLEGRO_BITMAP *agua = al_load_bitmap("../imagenes/agua.png");
	ALLEGRO_BITMAP *oro = al_load_bitmap("../imagenes/sheetoro.png");//("../imagenes/oro.png");
	ALLEGRO_BITMAP *arbol = al_load_bitmap("../imagenes/sheetarbol.png");//("../imagenes/arbol.png");
	//ALLEGRO_BITMAP *portal = al_load_bitmap("../imagenes/portal.png");
	ALLEGRO_BITMAP *torre = al_load_bitmap("../imagenes/sheettorre.png");
	ALLEGRO_BITMAP *castelo = al_load_bitmap("../imagenes/castillo.png");
	ALLEGRO_BITMAP *bala = al_load_bitmap("../imagenes/bala.png");
	ALLEGRO_BITMAP *aldea = al_load_bitmap("../imagenes/aldea.png");
	ALLEGRO_BITMAP *casa = al_load_bitmap("../imagenes/casa.png");

	ALLEGRO_BITMAP *torreOro = al_load_bitmap("../imagenes/toreOro.png");


	ALLEGRO_BITMAP *spriteEnemigos[3];
	spriteEnemigos[0] = al_load_bitmap("../imagenes/enemigofuerte.png");	//fuerte en nombre
	spriteEnemigos[1] = al_load_bitmap("../imagenes/enemigorapido.png");
	spriteEnemigos[2] = al_load_bitmap("../imagenes/enemigotanque.png");
	//ALLEGRO_BITMAP *shettTorre = al_load_bitmap("../imagenes/sheettorre.png");
	//ALLEGRO_BITMAP *sheetJug = al_load_bitmap("../imagenes/sheetjugador.png");
	ALLEGRO_BITMAP *sheetPortal = al_load_bitmap("../imagenes/sheetportal.png");

	//ALLEGRO_BITMAP *spriteJugador = al_load_bitmap("../imagenes/sheetlenador.png");

	ALLEGRO_BITMAP *spritesJugador[MaxJugadores];
	spritesJugador[lenador] = al_load_bitmap("../imagenes/sheetlenador.png");
	spritesJugador[minero] = al_load_bitmap("../imagenes/sheetminero.png");
	
	
	
	/*
	ALLEGRO_BITMAP *sheetoro = al_load_bitmap(../imagenes/sheetoro.png);
	ALLEGRO_BITMAP *sheetmadera = al_load_bitmap(../imagenes/sheetarbol.png);

	al_draw_scaled_bitmap(enemigobasico,)
	*/

	

	bool redraw = true;
	bool running = true;

	//objeto objeto1;
	
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	//cargarMapa(recursos,arbol,oro,&cantRecursos);
	cargarMapa(niveles[nivelActual],&configuracion,recursos,arbol,oro,&cantRecursos);
	initMenu(&hud);

	inicMenuP(&menu);
	inicRanking(&datosranking);
	

	//contarRecursos(arboles,&cantidadArboles,oros,&cantidadOros);
	
	cantidadPortales = inicSpawn(&configuracion,spawn,MaxPortales);
	/*
	if(!calcularCamino(mapa,'e','f',&caminoEnemigos)){
		printf("no se calculo camino de enemigo");
		return 1;
	}*/
	for(int i = 0; i< cantidadPortales;i++){
		int filaPortal = (int)(spawn[i].ejey / cuadrado);
		int columnaPortal = (int)(spawn[i].ejex / cuadrado);

		if(!calcularCamino(&configuracion,filaPortal,columnaPortal,&caminoEnemigos[i])){
			printf("no se calculca el camino del portal %d\n",i);
			return 1;
		}
		printf("portal %d calculado con %d casilla\n",i,caminoEnemigos[i].longitud);
		
	}


	inicDatosJugador(&datosjugador);
	inicJugadores(jugadores,&configuracion,spritesJugador,&datosjugador);
	inicTorres(torres,MaxTorres);
	inicBala(balas,MaxBalas,bala);
	inicTorreInicial(&castillo,&configuracion,castelo);
	
	inicioEnemigos(enemigos, MAxEnemigos,spriteEnemigos);
	//inicSpawn(spawn, cantidadPortales);

	while (running){
		
		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){						
			running = false;
		}
		if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			if(estado == EstadoMenu)
			{
				if(event.keyboard.keycode == ALLEGRO_KEY_UP){
					seleccionMenu(&menu,-1);
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
					seleccionMenu(&menu,1);
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){

					Opciones opcion = obtenerOpcionMenu(&menu);

					if(opcion == Jugar){
						nombreTemporal[0]='\0';
						cantidadLetras = 0;
						estado = EstadoIngresarNombre;
						//estado = EstadoJugando;
					}
					else if(opcion == Ranking){
						cargarRanking(&datosranking);
						estado = EstadoRanking;
					}
					else if(opcion == salir){
						running = false;
					}
				}
			}
			else if(estado == EstadoJugando){
				
				if (event.keyboard.keycode == ALLEGRO_KEY_TAB)
				{
					cambiarJugador(jugadores,&jugadorActivo);
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_1){
					torreSeleccionada = torreNormal;
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_2){
					torreSeleccionada = torreRapida;
				}
				else{
					teclapresionada(&teclado,event.keyboard.keycode);

					if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
						ALLEGRO_BITMAP *spriteTorreElegido;
						if(torreSeleccionada == torreRapida){
							spriteTorreElegido = torreOro;
						}
						else{
							spriteTorreElegido = torre;
						}

					crearTorreJugador(torres,&cantidadTorres,&jugadores[jugadorActivo],&datosjugador,&configuracion,spriteTorreElegido,
						torreSeleccionada);

					}
				}
				

				
			}
			else if(estado == EstadoRanking){
				//cargarRanking(&datosranking);
				
				if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					estado = EstadoMenu;
				}
			}
			else if(estado == EstadoVictoria || estado == EstadoDerrota){
				if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
					estado = EstadoMenu;
				}
			}

			
		}
		if(event.type == ALLEGRO_EVENT_KEY_CHAR){
			if(estado==EstadoIngresarNombre){
				int tecla = event.keyboard.keycode;
				int caracter = event.keyboard.unichar;

				if(tecla == ALLEGRO_KEY_BACKSPACE){
					if(cantidadLetras>0){
						cantidadLetras--;
						nombreTemporal[cantidadLetras] = '\0';
					}
				}
				else if(tecla == ALLEGRO_KEY_ESCAPE){
					nombreTemporal[0]= '\0';
					cantidadLetras =0;
					estado = EstadoMenu;
				}
				else if (tecla == ALLEGRO_KEY_ENTER){
					if(cantidadLetras == 3){
						strcpy(datosjugador.nombre,nombreTemporal);
						estado = EstadoJugando;

						//esto esta de momento. debe actualizarse

						//Jugador.puntajeRank = 1000;

						/*if(registrarPuntaje(Jugador.nombre,Jugador.puntajeRank)){
							estado = EstadoJugando;
						}*/
					}					
				}
				else if(cantidadLetras<3){
						if(caracter>= 'a' && caracter <= 'z'){
							caracter = caracter - 'a' + 'A';
						}
						if(caracter>= 'A' && caracter <= 'Z'){
							nombreTemporal[cantidadLetras] = (char)caracter;
							cantidadLetras++;
							nombreTemporal[cantidadLetras] = '\0';
						}
					}
			}
		}

		if(event.type == ALLEGRO_EVENT_KEY_UP)
		{
			teclasoltada(&teclado, event.keyboard.keycode);
		}
		if(event.type == ALLEGRO_EVENT_TIMER)
		{	

			if(estado == EstadoJugando)//estado juego
			{
				for (int i = 0; i < cantidadPortales; i++) {
   					 spawn[i].tiempo++;
					}

					spawnEnemigos(&configuracion,spawn,cantidadPortales,enemigos,MAxEnemigos,spriteEnemigos);

				for(int i =0; i< MAxEnemigos; i++){	
					if(!enemigos[i].vivo){
					continue;
				     }							
				
					moverEnemigoCamino(&enemigos[i],&caminoEnemigos[enemigos[i].portalOrigen]);//cambiar que cada enemigo calcule su camino
					animacion(&enemigos[i]);
					colisionMetaEnemigo(&configuracion,&enemigos[i], &jugadores[jugadorActivo],&datosjugador);
				/*if(rango(&castillo,&enemigos[i])){
				printf("enemigo%d en rango\n",i);
				}*/
				}	 
				actDisparoTorre(&castillo,balas,MaxBalas,enemigos,MAxEnemigos);

				for(int i =0;i<cantidadTorres;i++){
					actDisparoTorre(&torres[i],balas,MaxBalas,enemigos,MAxEnemigos);
				}
				actBala(balas,MaxBalas,enemigos,MAxEnemigos);
				contadorPortal++;
				if(contadorPortal>= framTickPortal){
					contadorPortal=0;					
					framePortal++;
					if(framePortal>=cantFramePortal){
						framePortal = 0;
					}
				}
				

				construirTorres(torres,cantidadTorres);
				//moverEnemigo(&enemigo,&teclado);
				movJugador(&jugadores[jugadorActivo],&teclado);
				animacionJugador(&jugadores[jugadorActivo]);
				actJugador(&jugadores[jugadorActivo]);				
				colisionRecursos(&jugadores[jugadorActivo], recursos, cantRecursos,&datosjugador);
				if(datosjugador.vida <=0){

					registrarPuntaje(datosjugador.nombre,datosjugador.puntajeRank);
					//crear pantalla de derrota o fin de juego
					
					estado = EstadoDerrota;

					//running = false;

				}	
				else if(nivelTerminado(&configuracion,enemigos,MAxEnemigos)){

					if(nivelActual+1<cantidadNiveles){
						nivelActual++;

						cargarMapa(niveles[nivelActual],&configuracion,recursos,arbol,oro,&cantRecursos);

						reiniciarConteo(&configuracion);

						inicioEnemigos(enemigos,MAxEnemigos,spriteEnemigos);

						cantidadPortales=inicSpawn(&configuracion,spawn,MaxPortales);

						for(int i =0; i<cantidadPortales;i++){
							int filaPortal = (int)(spawn[i].ejey /cuadrado);
							int columnaPortal = (int)(spawn[i].ejex / cuadrado);
							calcularCamino(&configuracion,filaPortal,columnaPortal,&caminoEnemigos[i]);
						}
						inicBala(balas,MaxBalas,bala);
						inicTorres(torres,MaxTorres);
						cantidadTorres =0;

						buscarPosicion(&configuracion,'j',&jugadores[jugadorActivo].ejex,&jugadores[jugadorActivo].ejey);
						inicTorreInicial(&castillo,&configuracion,castelo);
						datosjugador.puntajeRank += 500;
					}
					else{
						registrarPuntaje(datosjugador.nombre,datosjugador.puntajeRank);
						estado = EstadoVictoria;
						//running = false;
					}
				}
			}						
					
			redraw = true;
		}
		if(redraw && al_is_event_queue_empty(queue)){
			al_clear_to_color(al_map_rgb(255,255,255));

			if(estado == EstadoMenu){
				al_draw_scaled_bitmap(fondo,0,0,al_get_bitmap_width(fondo),al_get_bitmap_height(fondo),0,0,anchoMap+anchoP,altoMap,0);
				dibuMenuP(&menu);
				
			}
			else if(estado == EstadoIngresarNombre){
				al_draw_scaled_bitmap(fondo,0,0,al_get_bitmap_width(fondo),al_get_bitmap_height(fondo),0,0,anchoMap+anchoP,altoMap,0);
				dibuMenuRanking(&menu,nombreTemporal);
				
			}
			else if(estado == EstadoJugando){

				dibujarMapa(&configuracion,terreno,pasto,camino,agua,oro,arbol,sheetPortal,casa,aldea,framePortal);

				for(int i =0; i<cantRecursos; i++){
					dibRecursos(&recursos[i]);
				}

				/*for(int i=0; i<cantidadArboles;i++){
					diArbol(&arboles[i]);
				}
				for(int i=0; i<cantidadOros;i++){
					diOro(&oros[i]);	
				}		*/				

				//dibuJugador(&jugadores[jugadorActivo]);
				dibuJugadores(jugadores,MaxJugadores,jugadorActivo);
				dibuTorre(&castillo);
				dibuTorreS(torres,cantidadTorres);
				dibuBala(balas,MaxBalas);

				for(int i =0; i<MAxEnemigos;i++)
				{
				dibujoEnemigo(&enemigos[i],pasto,camino);
				}		
				dibuMenu(&hud,&jugadores[jugadorActivo],&datosjugador);
			}
			else if(estado == EstadoRanking){
				al_draw_scaled_bitmap(fondo,0,0,al_get_bitmap_width(fondo),al_get_bitmap_height(fondo),0,0,anchoMap+anchoP,altoMap,0);				
				dibuRanking(&datosranking);
				
			}
			else if(estado == EstadoVictoria){
				dibuPantallaFinal(&menu,true,datosjugador.puntajeRank);
			}
			else if(estado == EstadoDerrota){
				dibuPantallaFinal(&menu,true,datosjugador.puntajeRank);
			}	

			
			al_flip_display();			
			
			redraw = false;
		}
	} 
	al_destroy_bitmap(terreno);
	al_destroy_bitmap(pasto);	
	al_destroy_bitmap(oro);
	al_destroy_bitmap(arbol);
	al_destroy_bitmap(fondo);
	//al_destroy_bitmap(enemigobasico);
	al_destroy_bitmap(camino);
	al_destroy_bitmap(agua);
	al_destroy_bitmap(castelo);
	al_destroy_bitmap(sheetPortal);
	al_destroy_bitmap(torre);
	al_destroy_bitmap(torreOro);
	//al_destroy_bitmap(sheetJug);
	/*for(int i =0;i<MaxJugadores;i++){
		al_destroy_bitmap(spritesJugador[MaxJugadores]);
	}*/
	
	
	destruRanking(&datosranking);
	destruMenu(&hud);
	destruMenuP(&menu);
	destruir_pantalla(display);
	al_destroy_timer(timer);   
	al_destroy_event_queue(queue);
    return 0;
}
