				/* DECLARACION DE FUNCIONES */
void animacion();							// Muestra La Animacion Del Establecimiento En general
void mov_carro (int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c); // Funcion que distribuye que tipo de carro y movimiento debe mostrar		
void mover_autop(int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c); // Funcion Que imprime el movimiento del carro pequeño hacia un servicio
void mover_autom(int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c); // Funcion Que imprime el movimiento del carro mediano hacia un servicio
void mover_autoc(int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c); // Funcion Que imprime el movimiento de la camioneta hacia un servicio



void animacion(){

	system ("cls");
	fflush (stdout); // Para vaciar el bufer de escritura

	/*  Servicio 1: "Lavado Y Aspirado"  */
	gotoxy(1,1); printf ("      SERV.1 ");
	gotoxy(2,1); printf (" *--------------* ");
	gotoxy(3,1); printf (" |              | ");
	gotoxy(4,1); printf (" |  DISPONIBLE  | ");
	gotoxy(5,1); printf (" |              | ");
	gotoxy(6,1); printf (" *-|          |-* ");


	/*  Servicio 2: "Cambio De Aceite"  */
	gotoxy(1,21); printf ("      SERV.2 ");
	gotoxy(2,21); printf (" *--------------* ");
	gotoxy(3,21); printf (" |              | ");
	gotoxy(4,21); printf (" |  DISPONIBLE  | ");
	gotoxy(5,21); printf (" |              | ");
	gotoxy(6,21); printf (" *-|          |-* ");

	/*  Servicio 3: "Lavado De Motor"  */
	gotoxy(1,41); printf ("      SERV.3 ");
	gotoxy(2,41); printf (" *--------------* ");
	gotoxy(3,41); printf (" |              | ");
	gotoxy(4,41); printf (" |  DISPONIBLE  | ");
	gotoxy(5,41); printf (" |              | ");
	gotoxy(6,41); printf (" *-|          |-* ");

			/* "Estacionamiento"  */
	gotoxy(1,61); printf ("  Estacionamiento ");
	gotoxy(2,61); printf (" *--------------* ");
	gotoxy(3,61); printf (" |              | ");
	gotoxy(4,61); printf (" |   5 PUESTOS  | ");
	gotoxy(5,61); printf (" |  DISPONIBLES | ");
	gotoxy(6,61); printf (" |              | ");
	gotoxy(7,61); printf (" *-|          |-* ");

			/* Entrada */
	gotoxy(45,41); printf (" *-|     ^    |-* ");
	gotoxy(46,41); printf (" |       ^      | ");
	gotoxy(47,41); printf (" |    ENTRADA   | ");
	gotoxy(48,41); printf (" |       ^      | ");
	gotoxy(49,41); printf (" *-|     ^    |-* ");

	/* Salida */

	gotoxy(45,61); printf (" *-|     v    |-* ");
	gotoxy(46,61); printf (" |              | ");
	gotoxy(47,61); printf (" |     SALIDA   | ");
	gotoxy(48,61); printf (" |              | ");
	gotoxy(49,61); printf (" *-|     v    |-* ");

}

void mov_carro (int *Tcarro, int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c){

	if (*Tcarro==0)
		mover_autop(serv, min, seg, Eserv1, Eserv2, Eserv3, a, b, c);
	else if(*Tcarro==1)
		mover_autom(serv, min, seg, Eserv1, Eserv2, Eserv3, a, b, c);
		else
			mover_autoc(serv, min, seg, Eserv1, Eserv2, Eserv3, a, b, c);
	
}

void mover_autop(int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c){  // Movimiento Del Carro Pequeño
	
	int fil=41, col=41;  	// Fila Y Columna "Inicial"
	int filf=6, colf=0;  	// Fila Y Columna "Final" (Inicializadas)
	bool finalc= false;  	 // Verifica Si Llego Al Final De La Columna  
	
	if (*serv==0){    // Si El Servicio Es El Primero
	
		if (*Eserv1==0){
	
			*Eserv1= 1;
	
		}else{
			
			*a+= 8;
			filf= *a;
		}		
		
	}else if (*serv==1){ // Si El Servicio Es El Segundo
		
			colf= 20;
	
			if (*Eserv2==0){
		
				*Eserv2= 1;
	
			}else{
			
				*b+= 8;
				filf= *b;
			}
			
		}else if (*serv==2){ // Si El Servicio Es El Tercero
		
				colf= 40;
				
				if (*Eserv3==0){
		
					*Eserv3= 1;
	
				}else{
			
					*c+= 8;
					filf= *c;
				}
			}
		
		while (fil>filf){   // Después Lo Movemos Verticalmente Hacia Arriba Hasta LLegar Al Respectivo Servicio
		
			if (finalc==false){
				
				while (col>colf){     // Primero lo Movemos Horizontalmente Hacia Izquierda 
		
					system("cls");
					animacion();
						
					gotoxy(fil,col);   printf ("      _______     ");
					gotoxy(fil+1,col); printf ("    _/___|___|_   ");
					gotoxy(fil+2,col); printf ("   |_.-._|_.-._|- ");
					gotoxy(fil+3,col); printf ("     (@)   (@)    ");	
		
					col-=1;
					Sleep(0001);
				}
				
				finalc= true;
			}
		
			system("cls");
			animacion();

			gotoxy(fil,col);   printf ("      _______     ");
			gotoxy(fil+1,col); printf ("    _/___|___|_   ");
			gotoxy(fil+2,col); printf ("   |_.-._|_.-._|- ");
			gotoxy(fil+3,col); printf ("     (@)   (@)    ");	
		
			fil-=1;
			Sleep(0001);
		}	
		
}

void mover_autom(int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c){  // Movimiento Del Carro Mediano

	int fil=41, col=41; 	// Fila Y Columna "Inicial"
	int filf=6, colf=0; 	// Fila Y Columna "Final" (Inicializadas)
	bool finalc= false;   	// Verifica Si Llego Al Final De La Columna  
	
	if (*serv==0){    // Si El Servicio Es El Primero
	
		if (*Eserv1==0){
	
			*Eserv1= 1;
	
		}else{
			
			*a+= 8;
			filf= *a;
		}		
		
	}else if (*serv==1){ // Si El Servicio Es El Segundo
		
			colf= 20;
	
			if (*Eserv2==0){
		
				*Eserv2= 1;
	
			}else{
			
				*b+= 8;
				filf= *b;
			}
			
		}else if (*serv==2){ // Si El Servicio Es El Tercero
		
				colf= 40;
				
				if (*Eserv3==0){
		
					*Eserv3= 1;
	
				}else{
			
					*c+= 8;
					filf= *c;
				}
			}
		
		while (fil>filf){   // Después Lo Movemos Verticalmente Hacia Arriba Hasta LLegar Al Respectivo Servicio
		
			if (finalc==false){
				
				while (col>colf){     // Primero lo Movemos Horizontalmente Hacia Izquierda 
		
					system("cls");
					animacion();		
			
					gotoxy(fil,col);   printf ("       _________    ");  
					gotoxy(fil+1,col); printf ("    __/____|____|__ ");  
					gotoxy(fil+2,col); printf ("   |__.-.__|_.-.___|- ");
					gotoxy(fil+3,col); printf ("      (@)    (@)      ");	
		
					col-=1;
					Sleep(0001);
				}
				
				finalc= true;
			}
		
			system("cls");
			animacion();
		
			gotoxy(fil,col);   printf ("       _________    ");  
			gotoxy(fil+1,col); printf ("    __/____|____|__ ");  
			gotoxy(fil+2,col); printf ("   |__.-.__|_.-.___|- ");
			gotoxy(fil+3,col); printf ("      (@)    (@)      ");	
		
			fil-=1;
			Sleep(0001);
		}		
}

void mover_autoc(int *serv, int min, int seg, int *Eserv1, int *Eserv2, int *Eserv3, int *a, int *b, int *c){    // Movimiento De La Camioneta
	
	int fil=41, col=41;        // Fila Y Columna "Inicial"
	int filf=6, colf=0;        // Fila Y Columna "Final" (Inicializadas)
	bool finalc= false;   	   // Verifica Si Llego Al Final De La Columna 
	
	if (*serv==0){    // Si El Servicio Es El Primero
	
		if (*Eserv1==0){
	
			*Eserv1= 1;
	
		}else{
			
			*a+= 8;
			filf= *a;
		}		
		
	}else if (*serv==1){ // Si El Servicio Es El Segundo
		
			colf= 20;
	
			if (*Eserv2==0){
		
				*Eserv2= 1;
	
			}else{
			
				*b+= 8;
				filf= *b;
			}
			
		}else if (*serv==2){ // Si El Servicio Es El Tercero
		
				colf= 40;
				
				if (*Eserv3==0){
		
					*Eserv3= 1;
	
				}else{
			
					*c+= 8;
					filf= *c;
				}
			}
				
		while (fil>filf){   // Después Lo Movemos Verticalmente Hacia Arriba Hasta LLegar Al Respectivo Servicio
		
			if (finalc==false){
				
				while (col>colf){     // Primero lo Movemos Horizontalmente Hacia Izquierda 
		
					system("cls");
					animacion();
		
					gotoxy(fil,col);   printf ("       _________         ");
					gotoxy(fil+1,col); printf ("    __/_____|___|_____   ");
					gotoxy(fil+2,col); printf ("   |__.--.__|_.--.____|- ");
					gotoxy(fil+3,col); printf ("      (@)     (@)        ");	
		
					col-=1;
					Sleep(0001);
				}
				
				finalc= true;
			}
		
			system("cls");
			animacion();
		
			gotoxy(fil,col);   printf ("       _________         ");
			gotoxy(fil+1,col); printf ("    __/_____|___|_____   ");
			gotoxy(fil+2,col); printf ("   |__.--.__|_.--.____|- ");
			gotoxy(fil+3,col); printf ("      (@)     (@)        ");	
		
			fil-=1;
			Sleep(0001);
		}	
}


