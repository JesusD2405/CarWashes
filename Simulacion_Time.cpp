						/*DECLARACION DE FUNCIONES*/
void gotoxy(int fila,int col);	
void solicitar_time(int *min, int *seg); 		// Solicita el tiempo de la simulacion
void mostrar_marco ();							// Muestra el marco del tiempo
void mostrar_time(int *min, int *seg);			// Muestra el tiempo en pantalla
void mostrar_date ();							// Muestra la fecha y hora del fin de la simulación

				/* FUNCIONES */

void gotoxy(int fila,int col){
	HANDLE hConsoleOutput;
	COORD d;
	hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	d.X=col; d.Y=fila;
		SetConsoleCursorPosition (hConsoleOutput, d);
}
						

void solicitar_time(int *min, int *seg){

	int resp=0;

	do{
		system("cls");
		printf ("\t ---Ingrese El Tiempo De La Simulacion---\n \n \t");
		printf ("Ingrese Los Minutos: ");
		scanf ("%i",&resp);
		*min=resp;

	}while(resp<=-1 || resp>60);   // Verificamos Que El Minuto Ingresado No Sea Negativo Ni Mayor A 60min

	resp=0; // Inicializamos De Nuevo La Resp Para Guardar El Valor De Segundos

	do{
		system("cls");
		printf("\n \t Ingrese Los Segundos: ");
		scanf ("%i",&resp);
		*seg=resp;

	}while(resp<=-1 || resp>60);   // Verificamos Que El Segundo Ingresado No Sea Negativo Ni Mayor A 60seg

}

void mostrar_marco (){

	gotoxy(45,3);printf("\xc9");
    gotoxy(45,26);printf("\xbb");
	gotoxy(49,3);printf("\xc8");
	gotoxy(49,26);printf("\xbc");
	for(int f=4;f<26;f+=1){
        gotoxy(45,f);printf("\xcd");//linea horizontal arriba
        gotoxy(49,f);printf("\xcd");//linea horizontal abajo
    }
    for(int f=46;f<49;f+=1){
        gotoxy(f,3);printf("\xba");//linea vertical izquierda
        gotoxy(f,26);printf("\xba");//linea vertical derecha
    }
}

void mostrar_tiempo(int *min, int *seg){

	mostrar_marco();		// Muestra El Marco

	if (*seg==0 && *min>0){
		*min-=1;
		*seg= 60;
	}

	fflush (stdout); // Para vaciar el bufer de escritura
	gotoxy(47,6);printf("TIEMPO: %imin %iseg", *min, *seg);
	*seg-=1;

}

void mostrar_date (){

	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
	char putout[88];
	char output[68];

	fflush (stdout); // Para vaciar el bufer de escritura
	system("cls");

	printf ("\n\n\n\n\t..Fin De La Simulacion..\n \n \t");
    strftime(putout,88,"Hora: %I:%M:%S %p",tlocal);
	printf("%s \n \t",putout);

	strftime(output,68,"Fecha: %d/%m/%y",tlocal);
	printf("%s\n \t",output);

	fflush(stdin);
	getch();

}


