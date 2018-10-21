   						/* DECLARACION DE FUNCIONES */

void inicio_simulacion(); // FUNCION PRINCIPAL DONDE EMPEZAMOS LA SIMULACION
void inicializar(CABECERA *p_cabecera, CLIENTES* &ultm_cliente, SERV1* &ultm_serv1, SERV2* &ultm_serv2, SERV3* &ultm_serv3, GARAJE *p_autos);  // Inicializamos Las Listas, El Garaje.. Y La Estructura Cabecera
bool aleatorio ();     		   // Generamos Valores Aleatorios. Verdad= "1", Falso ="0"
void nuevo_cliente (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, int *cont, int *tcarro);     // Verificamos Sí Llego Un Cliente o No.. Si Llego Un Cliente Enlazamos Nuestra Estructura Cabecera Con Nuestro Primer Cliente En La Cola
void insertar_cliente (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, int *tcarro);	   // Inserta Un Cliente A La Cola De Espera
void distribucion (CABECERA *p_cabecera, SERV1* &ultm_serv1, SERV2* &ultm_serv2, SERV3* &ultm_serv3, GARAJE *p_autos, int *serv);   // Distribuye Cada Cliente A La Cola Del Servicio Correspondiente
void cola_serv1 (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, SERV1* &ultm_serv1 );     // Cola Del Servicio "Lavado Y Aspirado" (serv1)
void cola_serv2 (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, SERV2* &ultm_serv2);      // Cola Del Servicio "Cambio De Aceite"  (serv2)
void cola_serv3 (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, SERV3* &ultm_serv3);      // Cola Del Servicio "Lavado De Motor"   (serv3)

						/* ATENCION POR SERVICIO */
void atencion_serv1 (CABECERA *p_cabecera);		   // Se Verifica Si El Primer Cliente En La Cola Del Servicio1 Tiene El Vehículo Listo
void atencion_serv2 (CABECERA *p_cabecera);		   // Se Verifica Si El Primer Cliente En La Cola Del Servicio2 Tiene El Vehículo Listo
void atencion_serv3 (CABECERA *p_cabecera);		   // Se Verifica Si El Primer Cliente En La Cola Del Servicio3 Tiene El Vehículo Listo


							 /* FUNCIONES */

void inicio_simulacion(){

	int Eserv1= 0;           // Estado Del Serv
	int Eserv2= 0;           // Estado Del Serv2
	int Eserv3= 0; 	         // Estado Del Serv3
	int Tcarro=0;			 // Tipo De Carro
	int serv=0;				 // Servicio
	int a=0, b=0, c=0;       // Variables Que Manejan Las Colas De Los Servicios
	int min=0, seg=0; // Minutos Y Segundos
	int cont=0;

	// Estructura Cabecera
	CABECERA X, *p_cabecera;

	// Listas
	CLIENTES *ultm_cliente;  	  // Clientes
	SERV1 *ultm_serv1;	          // Lavado y Aspirado
	SERV2 *ultm_serv2;        	  // Cambio De Aceite
	SERV3 *ultm_serv3; 	      	  // Lavado De Motor

	// Estructura
	GARAJE Y, *p_autos;	 // Estacionamiento

	/* Apuntamos A La Variable Para Acceder Con El Puntero A Las Estructuras */
	p_cabecera= &X;
	p_autos= &Y;

	system ("color 3F");
	/* Llamado A las Funciones */
	inicializar (p_cabecera, ultm_cliente, ultm_serv1, ultm_serv2, ultm_serv3, p_autos);
	solicitar_time(&min,&seg);  // Solicita El Tiempo

	while (min>=0 && seg>=0){

		animacion();
		nuevo_cliente ( p_cabecera, ultm_cliente, &cont, &Tcarro);
		distribucion ( p_cabecera, ultm_serv1, ultm_serv2, ultm_serv3, p_autos, &serv);
		mov_carro (&Tcarro, &serv, min, seg, &Eserv1, &Eserv2, &Eserv3, &a, &b, &c);
		mostrar_tiempo (&min,&seg);

		fflush (stdout); // Para vaciar el bufer de escritura
		Sleep (1000); // Espera 1 seg
	}

	estadisticas(p_cabecera, cont);
	limpiar(p_cabecera);

}

void inicializar(CABECERA *p_cabecera, CLIENTES* &ultm_cliente, SERV1* &ultm_serv1, SERV2* &ultm_serv2, SERV3* &ultm_serv3, GARAJE *p_autos){

	int i;

	/* Incializamos La Funcion Aleatoria */
	srand (time (NULL));

	/*  Inicializamos Nuestro Tope Del Estacionamiento */
	p_autos->tope= -1;

	/* Inicializamos Los Puestos Totales Del Estacionamiento en Disponible= "0" */
	for (i=0; i<MAXP; i++){

		p_autos->puestos[i]= DISPONIBLE;

	}
		/* Inicializamos Los Punteros De Las Listas */

			/* Clientes */
	ultm_cliente= NULL;

			/* Servicio 1= "Lavado y Aspirado"  */
	ultm_serv1= NULL;

			/* Servicio 2= "Cambio De Aceite" */
	ultm_serv2= NULL;

			/* Servicio 3= "Lavado De Motor" */
	ultm_serv3= NULL;

	/* Inicializamos Los Punteros De La Estructura Cabecera */
	p_cabecera->primero= NULL;              // El Primer Cliente
	p_cabecera->primero_serv1= NULL;        // EL Servicio De Lavado y Aspirado
	p_cabecera->primero_serv2= NULL;        // EL Servicio De Cambio De Aceite
	p_cabecera->primero_serv3= NULL;        // EL Servicio De Lavado De Motor

	/* Inicializamos Los Contadores De La Cabecera  */
	p_cabecera->cant_autos= 0;				    // Cantidad Total De Vehículos Atendidos
	p_cabecera->cant_serv1= 0;					// Cantidad De Vehículos Atendidos En El Serv1= "Lavado Y Aspirado"
	p_cabecera->cant_serv2= 0;					// Cantidad De Vehículos Atendidos En El Serv2= "Cambio De Aceite"
	p_cabecera->cant_serv3= 0;					// Cantidad De Vehículos Atendidos En El Serv3= "Lavado De Motor"
	p_cabecera->cant_efectivo= 0;				// Cantidad De Clientes Que Cancelaron En Efectivo
	p_cabecera->cant_tarjd= 0;					// Cantidad De Clientes Que Cancelaron Con Tarjeta De Débito
	p_cabecera->cant_tarjc= 0;					// Cantidad De Clientes Que Cancelaron Con Tarjeta De Crédito

}


bool aleatorio(){

	int num;

	num= rand() % 2;       // Se Genera Un Número entre el 0 y el 1..

		if (num==VERDAD)
			return true;
		else
			return false;
}


void nuevo_cliente (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, int *cont, int *Tcarro){

	if (aleatorio()==VERDAD){                    	   		// LLego Un Cliente.. No= "0", Si= "1"
		*cont+=1;
		insertar_cliente (p_cabecera, ultm_cliente, Tcarro);        // Se Envia A La Cola De Clientes
	}

}


void insertar_cliente (CABECERA *p_cabecera, CLIENTES* &ultm_cliente, int *Tcarro){

	CLIENTES *nvo_cliente;
	int i;

    nvo_cliente=(CLIENTES*) malloc (sizeof(CLIENTES));

    if(!nvo_cliente){

    	system("cls");
        printf("\n \t \tNo hay memoria disponible para este nuevo nodo! \n");
        system ("pause");
    }
    else{

		nvo_cliente->sig=NULL;

    	 if(!p_cabecera->primero){                // Si No Existe Un Cliente En La Cola
    	 	p_cabecera->primero= nvo_cliente;     // Enlazamos Nuestra Estrutura Cabecera Con El Primer Cliente De La Cola
           	ultm_cliente= nvo_cliente;
        }
        else{
           	ultm_cliente->sig= nvo_cliente;
            ultm_cliente= nvo_cliente;
        }

    	/* Se Va Cargando Los Servicios Aleatoriamente Para Ese Cliente */
    	for (i=0; i<3; i++){

    	    ultm_cliente->servicio[i]=aleatorio(); //  Va A Querer El Servicio= "1"; No Quiere El Servicio= "0";

    	}

    	/* Se Determina Que Vehiculo Tiene */
    	ultm_cliente->vehiculo= rand () %3; 	   // Carro Pequeño= "0"; Carro Mediano= "1"; Camioneta= "2"
		*Tcarro= ultm_cliente->vehiculo;
		
    	/* Se Determina El Tiempo De Duracion De Acuerdo Al Tipo De Vehículo En Cualquier Servicio */

    	if (ultm_cliente->vehiculo==CARROP){ // Si Es Un Carro Pequeño
    		ultm_cliente->time_serv= 2; // Duracion 2seg
    	}else if (ultm_cliente->vehiculo==CARROM){ // Si Es Un Carro Mediano
    			ultm_cliente->time_serv= 4; // Duracion 4seg
    		}else{ 	// Es Una Camioneta
    				ultm_cliente->time_serv= 6; // Duracion 6seg
    			}

    	/* Se Determina La Forma De Pago */

		ultm_cliente->tpago= rand () %3; // Efectivo= "0"; Tarjeta De Débito= "1"; Tarjeta De Crédito= "2";

    }
}

void distribucion(CABECERA *p_cabecera, SERV1* &ultm_serv1, SERV2* &ultm_serv2, SERV3* &ultm_serv3, GARAJE *p_autos, int *serv){  	// Se Va Despachando EL Cliente A La Cola De Su Respectivo Servicio Solicitado //

	CLIENTES *actual, *aEliminar;
	int total_serv; // Variable Que Verifica. Si La Suma Es Igual A "0" Fue Atendido En Todos Los Servicios; Si Es Mayor De "0" Aún Falta Por Atender.
	int i;
	
	/* Inicializamos Los Punteros */
	actual= NULL;
	aEliminar= NULL;

	actual= p_cabecera->primero; // "actual" Apunta Al Primer Cliente De La Cola

	while(actual){	// Mientras Haya Clientes En La Cola.. Se Verifica:

		total_serv= 0; // Inicializamos El Total Servicio Para Ese Cliente

		for (i=0; i<3; i++){	// Verificamos Que Servicio Quiere Segun La Posicion Del Vector {Serv1, Serv2, Serv3, Estacionamiento}

			if (actual->servicio[i]==VERDAD && actual->cola==FALSO){ // Si Quiere El Servicio Y No Está En Otra Cola

				/* Se Verifica Que Servicio Quiere. Y Se Pasa A Su La Respectiva Cola En Orden*/
					if (i==0){
						cola_serv1(p_cabecera, actual, ultm_serv1);	      // Cola De Sev.1= "Lavado Y Aspirado"
						*serv= 0;
						}else if (i==1){
							cola_serv2(p_cabecera, actual, ultm_serv2);      // Cola De Sev.2= "Cambio De Aceite"
							*serv= 1;
							}else if (i==2){
								cola_serv3(p_cabecera, actual, ultm_serv3);  // Cola De Sev.3= "Lavado De Motor"
								*serv= 2;
								}/*else if (i==3){
									estacionar(actual, p_autos);			  // Estacionamiento
									}*/
			}

			total_serv+= actual->servicio[i]; // Acumulamos El Valor De Esa Posición
		}

		if (p_cabecera->primero==actual && total_serv==0){ // Verificamos Si Es El Primer Cliente En La Cola (Comparamos Direcciones De Memoria) Y No Quiere Ningun Servicio

			aEliminar= actual;
			actual= actual->sig;
			p_cabecera->primero= actual; // Enlazamos Nuestra Cabecera Con El Siguiente En La Cola
			free(aEliminar);

		}else if (total_serv==FALSO){ // Se Verifica Si El Cliente No Necesita Ningún Servicio. De Ser Así La Suma De La Variable Tiene Que Ser "0"

			aEliminar= actual;
            actual= actual->sig;
            free(aEliminar);     //Eliminamos El Cliente De La Cola

			}else{
				actual= actual->sig; // Nos Movemos Al Siguiente Cliente
			}
	}
}

void cola_serv1 (CABECERA *p_cabecera, CLIENTES* &actual, SERV1* &ultm_serv1 ){

	SERV1 *nvo_serv1;

    nvo_serv1=(SERV1*) malloc (sizeof(SERV1));

    if(!nvo_serv1){

    	system("cls");
        printf("\n \t \tNo hay memoria disponible para este nuevo nodo! \n");
        system ("pause");
    }
    else{

		nvo_serv1->sig=NULL;

    	 if(!p_cabecera->primero_serv1){                // Si No Existe Un Cliente En La Cola Del Servicio
    	 		p_cabecera->primero_serv1= nvo_serv1;   // Enlazamos Nuestra Estrutura Cabecera Con El Primero En Esta Cola
           		ultm_serv1= nvo_serv1;
        	}
        	else{
           		ultm_serv1->sig= nvo_serv1;
            	ultm_serv1= nvo_serv1;
        	}

        actual->servicio[0]= 0; 			   	    // Anulamos El Pedido A Este Servicio
        actual->cola= VERDAD; 						// Se Asegura Que El Cliente Ya Está En La Cola De Un Servicio Y No Aparecera En Otra
        ultm_serv1->vehiculo= actual->vehiculo;     // Guardamos El Tipo De Vehiculo
        ultm_serv1->time_serv1= actual->time_serv;  // Guardamos El Timpo De Duración Del Vehículo En Este Servicio
        atencion_serv1 (p_cabecera);
    }
}

void cola_serv2 (CABECERA *p_cabecera, CLIENTES* &actual, SERV2* &ultm_serv2){

	SERV2 *nvo_serv2;

    nvo_serv2=(SERV2*) malloc (sizeof(SERV2));

    if(!nvo_serv2){

    	system("cls");
        printf("\n \t \tNo hay memoria disponible para este nuevo nodo! \n");
        system ("pause");
    }
    else{

    	nvo_serv2->sig=NULL;

    	 if(!p_cabecera->primero_serv2){                // Si No Existe Un Cliente En La Cola Del Servicio
           		p_cabecera->primero_serv2= nvo_serv2;	// Enlazamos Nuestra Estrutura Cabecera Con El Primero En Esta Cola
           		ultm_serv2= nvo_serv2;
		}
        else{
           		ultm_serv2->sig= nvo_serv2;
            	ultm_serv2= nvo_serv2;
        }

     	actual->servicio[1]= 0; 	                // Anulamos El Pedido A Este Servicio
     	actual->cola= VERDAD; 					    // Se Asegura Que El Cliente Ya Está En La Cola De Un Servicio Y No Aparecera En Otra
        ultm_serv2->vehiculo= actual->vehiculo;     // Guardamos El Tipo De Vehiculo
        ultm_serv2->time_serv2= actual->time_serv;  // Guardamos El Timpo De Duración Del Vehículo En Este Servicio
        atencion_serv2 (p_cabecera);
    }
}

void cola_serv3 (CABECERA *p_cabecera,  CLIENTES* &actual, SERV3* &ultm_serv3){

	SERV3 *nvo_serv3;

    nvo_serv3=(SERV3*) malloc (sizeof(SERV3));

    if(!nvo_serv3){

    	system("cls");
        printf("\n \t \tNo hay memoria disponible para este nuevo nodo! \n");
        system ("pause");
    }
    else{

    	nvo_serv3->sig=NULL;

    	 if(!p_cabecera->primero_serv3){                // Si No Existe Un Cliente En La Cola Del Servicio
           	p_cabecera->primero_serv3= nvo_serv3;	    // Enlazamos Nuestra Estrutura Cabecera Con El Primero En Esta Cola
           	ultm_serv3= nvo_serv3;
        }
        else{
           	ultm_serv3->sig= nvo_serv3;
            ultm_serv3= nvo_serv3;
        }

		actual->servicio[2]= 0; 					 	// Anulamos El Pedido A Este Servicio
		actual->cola= VERDAD;                           // Se Asegura Que El Cliente Ya Está En La Cola De Un Servicio Y No Aparecera En Otra
        ultm_serv3->vehiculo= actual->vehiculo;    		// Guardamos El Tipo De Vehiculo
        ultm_serv3->time_serv3= actual->time_serv; 		// Guardamos El Timpo De Duración Del Vehículo En Este Servicio
        atencion_serv3 (p_cabecera);
    }
}

			/*ATENCION POR SERVICIO*/

void atencion_serv1 (CABECERA *p_cabecera){

	SERV1 *actual, *aEliminar;
	CLIENTES *p_cliente;
	
	/* Inicializamos Los Punteros */
	actual= NULL;
	aEliminar= NULL;
	p_cliente= NULL;

	actual= p_cabecera->primero_serv1;		// "actual" Apunta Al Primer Cliente En La Cola Del Serv1
	p_cliente= p_cabecera->primero;			// "p_cliente" Apunta Al Primer Cliente En La Cola

	if(actual){		// Si Existe Un Cliente En La Cola De Este Servicio, Se Atiende..

		while (p_cliente){

			if(p_cliente->cola==VERDAD && p_cliente->servicio[0]==0 && actual->time_serv1>0){  // Si El Cliente Esta En Una Cola Y Le Anulamos El Pedido A Este Servicio Y El Tiempo En EL Serv Es Mayor Que 0

    			actual->time_serv1-= 1;	// Le Decrementamos 1seg Al Tiempo Del Servicio De Ese Cliente

    			if (actual->time_serv1==0){		 // Preguntamos Si Ya Cumplió "El Tiempo De Servicio" Y Sí "El Vehiculo Está Listo"

    				p_cabecera->cant_serv1+= 1;				// Lo Contamos Como Un Vehículo Ya Atendido En El Servicio
    				p_cliente->cola= FALSO; 				// Se Asegura Que El Cliente Ya Fue Atendido En EL Servicio Y Puede Aparecer En Otra Cola

    				if (p_cliente->tpago==0){
    					p_cabecera->cant_efectivo+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Efectivo
   					}else if (p_cliente->tpago==1){
   							p_cabecera->cant_tarjd+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Tarjeta De Débito
   						}else if (p_cliente->tpago==2){
   								p_cabecera->cant_tarjc+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Tarjeta De Crédito
   							}

					if(p_cabecera->primero_serv1==actual){  // Verificamos Si Es EL Primer Cliente En La Cola De Este Servicio

						aEliminar= actual;
    					actual= actual->sig;
   						p_cabecera->primero_serv1= actual;			// Enlazamos Nuestra Cabecera Con El Proximo Cliente En Cola Del Serv, Que Va A Hacer Nuestro Primer Cliente De La Cola De Este Serv
   						free(actual);								// Eliminamos Al Cliente Ya Atendido De La Cola

					}else{

					    aEliminar= actual;							// Enlazamos La Cola Con El Proximo Cliente
    					actual= actual->sig;
   						free(actual);							// Eliminamos Al Cliente Ya Atendido De La Cola

					}

   				}
    		}

    		p_cliente= p_cliente->sig;
    	}
    }
}


void atencion_serv2 (CABECERA *p_cabecera){

	SERV2 *actual, *aEliminar;
	CLIENTES *p_cliente;
	
		/* Inicializamos Los Punteros */
	actual= NULL;
	aEliminar= NULL;
	p_cliente= NULL;

	actual= p_cabecera->primero_serv2;		// "actual" Apunta Al Primer Cliente En La Cola Del Serv1
	p_cliente= p_cabecera->primero;			// "p_cliente" Apunta Al Primer Cliente En La Cola

	if(actual){		// Si Existe Un Cliente En La Cola De Este Servicio, Se Atiende..

		while (p_cliente){

			if(p_cliente->cola==VERDAD && p_cliente->servicio[1]==0 && actual->time_serv2>0){ // Si El Cliente Esta En Una Cola Y Le Anulamos El Pedido A Este Servicio Y El Tiempo En EL Serv Es Mayor Que 0

    			actual->time_serv2-= 1;	// Le Decrementamos 1seg Al Tiempo Del Servicio De Ese Cliente

    			if (actual->time_serv2==0){		 // Preguntamos Si Ya Cumplió "El Tiempo De Servicio" Y Sí "El Vehiculo Está Listo"

    				p_cabecera->cant_serv2+= 1;				// Lo Contamos Como Un Vehículo Ya Atendido En El Servicio
    				p_cliente->cola= FALSO; 				// Se Asegura Que El Cliente Ya Fue Atendido En EL Servicio Y Puede Aparecer En Otra Cola

    				if (p_cliente->tpago==0){
    					p_cabecera->cant_efectivo+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Efectivo
    				}else if (p_cliente->tpago==1){
    						p_cabecera->cant_tarjd+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Tarjeta De Débito
    					}else if (p_cliente->tpago==2){
    							p_cabecera->cant_tarjc+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Tarjeta De Crédito
    						}

					if(p_cabecera->primero_serv2==actual){  // Verificamos Si Es EL Primer Cliente En La Cola De Este Servicio

						aEliminar= actual;
    					actual= actual->sig;
   						p_cabecera->primero_serv2= actual;			// Enlazamos Nuestra Cabecera Con El Proximo Cliente En Cola Del Serv, Que Va A Hacer Nuestro Primer Cliente De La Cola De Este Serv
   						free(actual);								// Eliminamos Al Cliente Ya Atendido De La Cola

					}else{

					    aEliminar= actual;
    					actual= actual->sig;
   						free(actual);								// Eliminamos Al Cliente Ya Atendido De La Cola

					}
    			}
    		}

    		p_cliente= p_cliente->sig;

		}
    }
}

void atencion_serv3 (CABECERA *p_cabecera){

	SERV3 *actual, *aEliminar;
	CLIENTES *p_cliente;
	
		/* Inicializamos Los Punteros */
	actual= NULL;
	aEliminar= NULL;
	p_cliente= NULL;

	actual= p_cabecera->primero_serv3;		// "actual" Apunta Al Primer Cliente En La Cola Del Serv1
	p_cliente= p_cabecera->primero;			// "p_cliente" Apunta Al Primer Cliente En La Cola

	if(actual){		// Si Existe Un Cliente En La Cola De Este Servicio, Se Atiende..

		while (p_cliente){

			if(p_cliente->cola==VERDAD && p_cliente->servicio[2]==0 && actual->time_serv3>0){ // Si El Cliente Esta En Una Cola Y Le Anulamos El Pedido A Este Servicio Y El Tiempo En EL Serv Es Mayor Que 0

    			actual->time_serv3-= 1;	// Le Decrementamos 1seg Al Tiempo Del Servicio De Ese Cliente

    			if (actual->time_serv3==0){		 // Preguntamos Si Ya Cumplió "El Tiempo De Servicio" Y Sí "El Vehiculo Está Listo"

    				p_cabecera->cant_serv3+= 1;				// Lo Contamos Como Un Vehículo Ya Atendido En El Servicio
    				p_cliente->cola= FALSO; 				// Se Asegura Que El Cliente Ya Fue Atendido En EL Servicio Y Puede Aparecer En Otra Cola

    				if (p_cliente->tpago==0){
    					p_cabecera->cant_efectivo+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Efectivo
    					}else if (p_cliente->tpago==1){
    						p_cabecera->cant_tarjd+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Tarjeta De Débito
    						}else if (p_cliente->tpago==2){
    							p_cabecera->cant_tarjc+= 1;					// Lo Contamos Como Un CLiente Que Cancelo Con Tarjeta De Crédito
    							}

					if(p_cabecera->primero_serv3==actual){  // Verificamos Si Es EL Primer Cliente En La Cola De Este Servicio

						aEliminar= actual;
    					actual= actual->sig;
   						p_cabecera->primero_serv3= actual;			// Enlazamos Nuestra Cabecera Con El Proximo Cliente En Cola Del Serv, Que Va A Hacer Nuestro Primer Cliente De La Cola De Este Serv
   						free(actual);								// Eliminamos Al Cliente Ya Atendido De La Cola

					}else{

					    aEliminar= actual;
    					actual= actual->sig;					// Enlazamos Con El Proximo Cliente De La Cola
   						free(actual);							// Eliminamos Al Cliente Ya Atendido De La Cola

					}
    			}
    		}

    		p_cliente= p_cliente->sig;
    	}
    }
}

