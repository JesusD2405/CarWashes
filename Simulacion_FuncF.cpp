						/*DECLARACION DE FUNCIONES*/

void estadisticas(); 					// Muestra las Estadisticas Generales De La Simulación
void creditos();    					// Muestra Informacion Acerca Del Programa
void limpiar (CABECERA *p_cabecera); 	// Aseguramos De Limpiar Las Listas Que Aún Permanecen En EL Programa

							/* FUNCIONES */

void estadisticas (CABECERA *p_cabecera, int cont){

	int f, c;
	int serv1, serv2, serv3;

	system("cls");

	/* MARCO */

	gotoxy(3,1);printf("\xc9");
    gotoxy(3,78);printf("\xbb");
	gotoxy(22,1);printf("\xc8"); 	// Esquinas Inferiores
	gotoxy(22,78);printf("\xbc"); 	// Esquinas Inferiores

	for(c=2;c<78;c+=1){
        gotoxy(3,c);printf("\xcd");//linea horizontal arriba
        gotoxy(5,c);printf("\xcd");//linea horizontal arriba
        gotoxy(11,c);printf("\xcd");//linea horizontal arriba
        gotoxy(17,c);printf("\xcd");//linea horizontal abajo
        gotoxy(22,c);printf("\xcd");//linea horizontal abajo
    }
    for(f=4;f<22;f+=1){
        gotoxy(f,20);printf("\xba");//linea vertical interna
    }

    for(f=18;f<22;f+=1){
    	gotoxy(f,41);printf("\xba");//linea vertical interna
	}

    for (f=4;f<22;f+=1){
    	gotoxy(f,1);printf("\xba");		// lineas verticales externas
    	gotoxy(f,78);printf("\xba");	// lineas verticales externas
    }

	/* Encabezado */
	gotoxy(1,27);printf("* ESTADISTICAS GENERALES *");

	/* Contenido Tabla */
	gotoxy(4,5);printf("DESCRIPCION");
	gotoxy(4,44);printf("TIPO");

	gotoxy(7,3);printf("Vehiculos");
	gotoxy(8,3);printf("Atendidos");
	gotoxy(9,3);printf("Por Servicio");

	gotoxy(6,26);printf("Serv.1");
	gotoxy(8,28);printf("%i", p_cabecera->cant_serv1);	// Cantidad De Vehículos Atendidos En El Serv1= "Lavado Y Aspirado"
	gotoxy(6,44);printf("Serv.2");
	gotoxy(8,46);printf("%i", p_cabecera->cant_serv2);	// Cantidad De Vehículos Atendidos En El Serv2= "Cambio De Aceite"
	gotoxy(6,61);printf("Serv.3");
	gotoxy(8,63);printf("%i", p_cabecera->cant_serv3);			// Cantidad De Vehículos Atendidos En El Serv3= "Lavado De Motor"

	gotoxy(13,3);printf("Cantidad De");
	gotoxy(14,3);printf("Clientes");
	gotoxy(15,3);printf("Por Tipo De Pago");

	gotoxy(12,25);printf("Efectivo");
	gotoxy(14,28);printf("%i", p_cabecera->cant_efectivo);
	gotoxy(12,39);printf("Tarj. De Debito");
	gotoxy(14,45);printf("%i", p_cabecera->cant_tarjd);
	gotoxy(12,60);printf("Tarj. De Credito");
	gotoxy(14,65);printf("%i", p_cabecera->cant_tarjc);


	serv1= p_cabecera->cant_serv1;
	serv2= p_cabecera->cant_serv2;
	serv3= p_cabecera->cant_serv3;

	p_cabecera->cant_autos= serv1+serv2+serv3;
	gotoxy(19,3);printf("Total De Autos ");
	gotoxy(20,3);printf("Atendidos: ");
	gotoxy(20,28);printf("%i", p_cabecera->cant_autos);
	gotoxy(19,43);printf("Total De Clientes");
	gotoxy(20,43);printf("Generados: ");
	gotoxy(20,65);printf("%i", cont);

	/* Documentacion De Tabla */
	gotoxy(26,3);printf("*Servicios:");
	gotoxy(27,3);printf("Serv.1= 'Lavado Y Aspirado' ");
	gotoxy(28,3);printf("Serv.2= 'Cambio De Aceite' ");
	gotoxy(29,3);printf("Serv.3= 'Lavado De Motor' ");

	/* Opciones */
	fflush (stdin);
	gotoxy(32,20); system("pause");
}

void creditos(){

	int i=1;
	int fila=16;

	system("cls");

	while (fila>0){

		system("cls");

		gotoxy(fila,3);	  printf("*-----------------------------------------------------------------------*");
		gotoxy(fila+1,3); printf("|                                                                       |");
		gotoxy(fila+2,3); printf("|               UNIVERSIDAD NACIONAL EXPERIMENTAL DE GUAYANA            |");
		gotoxy(fila+3,3); printf("|                                                                       |");
		gotoxy(fila+4,3); printf("|    Proyecto De Carrera: Ing. En Informatica                           |");
		gotoxy(fila+5,3); printf("|    Asignatura:          Tec. De Programacion II                       |");
		gotoxy(fila+6,3); printf("|    Profesor:             Andres Lillo                                 |");
		gotoxy(fila+7,3); printf("|                                                                       |");
		gotoxy(fila+8,3); printf("|              -> Estudiante: Jesus David Perez                         |");
		gotoxy(fila+9,3); printf("|                                                                       |");
		gotoxy(fila+10,3);printf("*-----------------------------------------------------------------------*");

		Sleep (500); // Esperar 1/2 seg
		fflush (stdout); // Para vaciar el bufer de escritura
		fila-=1;
	}

	fflush(stdin);
	getch();
}

void limpiar (CABECERA *p_cabecera){

	CLIENTES *actual_client, *aEliminar;
	SERV1 *actual_serv1, *aEliminar1;
	SERV2 *actual_serv2, *aEliminar2;
	SERV3 *actual_serv3, *aEliminar3;
	
		/* Inicializamos Los Punteros */
	actual_client= NULL;
	aEliminar= NULL;
	
	actual_serv1= NULL;
	aEliminar1= NULL;

	actual_serv2= NULL;
	aEliminar2= NULL;
	
	actual_serv3= NULL;
	aEliminar3= NULL;	

	/* Se Libera Los Clientes Que Quedaron En Cola */
	actual_client= p_cabecera->primero;

	if(actual_client==NULL){
    	printf("lista vacia\n");
    }
    else{

        while(actual_client){
        	aEliminar= actual_client;
            actual_client= actual_client->sig;
            free(aEliminar);

        }
    }

	/* Se Libera Los Clientes Que Quedaron En Cola Del Serv1 */
    actual_serv1= p_cabecera->primero_serv1;

	if(actual_serv1==NULL){
    	printf("lista vacia\n");
    }
    else{

        while(actual_serv1){
        	aEliminar1= actual_serv1;
            actual_serv1= actual_serv1->sig;
            free(aEliminar1);

        }
    }

	/* Se Libera Los Clientes Que Quedaron En Cola Del Serv2 */
    actual_serv2= p_cabecera->primero_serv2;

	if(actual_serv2==NULL){
    	printf("lista vacia\n");
    }
    else{

        while(actual_serv2){
        	aEliminar2= actual_serv2;
            actual_serv2= actual_serv2->sig;
            free(aEliminar2);

        }
    }

    /* Se Libera Los Clientes Que Quedaron En Cola Del Serv3 */
    actual_serv3= p_cabecera->primero_serv3;

	if(actual_serv3==NULL){
    	printf("lista vacia\n");
    }
    else{

        while(actual_serv3){
        	aEliminar3= actual_serv3;
            actual_serv3= actual_serv3->sig;
            free(aEliminar3);

        }
    }

}


