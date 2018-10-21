                            // Listas.. Comportamientos De Colas //

typedef struct clientes{

	int cola;				 // Esta En La Cola De Un Servcio= "1", No Esta En La Cola De Un Servicio= "0"
	int servicio[3];      	 // Vector Que Almacena La Cantidad De Servicios A Realizar. MAXS= "4"
	int vehiculo;		     // Variable Que Guarda El Tipo De Vehiculo (Carro Peque�o= "0", Carro Mediano= "1", Camioneta= "2")
	int time_serv;           // Tiempo De Duracion Del Veh�culo En Un Servicio (Carro Peque�o= "5seg", Carro Mediano= "8seg", Camioneta= "12seg")
	int tpago;				 // Tipo De Pago (Efectivo= "0", Tarjeta De D�bito= "1", Tarjeta De Cr�dito= "2")

	struct clientes *sig;

}CLIENTES;

typedef struct serv1{ 	    // Lavado Y Aspirado

	int vehiculo;			// Guarda El Vehiculo.. Carro= "0", Camioneta= "1"
	int time_serv1;         // Tiempo De Duracion Del Veh�culo En El Servicio 1
	struct serv1 *sig;

}SERV1;

typedef struct serv2{       // Cambio De Aceite

	int vehiculo;			// Guarda El Vehiculo.. Carro= "0", Camioneta= "1"
	int time_serv2;         // Tiempo De Duracion Del Veh�culo En El Servicio 2
	struct serv2 *sig;

}SERV2;

typedef struct serv3{		 // Lavado De Motor

	int vehiculo;			// Guarda El Vehiculo.. Carro= "0", Camioneta= "1"
	int time_serv3;         // Tiempo De Duracion Del Veh�culo En El Servicio 3
	struct serv3 *sig;

}SERV3;

                                // Estrutura.. Comportamiento De Pila  //

typedef struct estacionamiento{

	int puestos [MAXP];   		// N�mero De Puestos Del Estacionamiento... MAXP=5
	int tope;		 	 		 // Tope De La Pila

}GARAJE;

                                   // Estructura Principal: "Cabecera" //

typedef struct autolavado{

	int cant_autos;				    // Cantidad Total De Veh�culos Atendidos
	int cant_serv1;					// Cantidad De Veh�culos Atendidos En El Serv1= "Lavado Y Aspirado"
	int cant_serv2;					// Cantidad De Veh�culos Atendidos En El Serv2= "Cambio De Aceite"
	int cant_serv3;					// Cantidad De Veh�culos Atendidos En El Serv3= "Lavado De Motor"
	int cant_efectivo;				// Cantidad De Clientes Que Cancelaron En Efectivo
	int cant_tarjd;					// Cantidad De Clientes Que Cancelaron Con Tarjeta De D�bito
	int cant_tarjc;					// Cantidad De Clientes Que Cancelaron Con Tarjeta De Cr�dito

	struct clientes *primero;		    // Clientes
	struct serv1 *primero_serv1;        // Lavado y Aspirado
	struct serv2 *primero_serv2;        // Cambio De Aceite
	struct serv3 *primero_serv3;        // Lavado De Motor

}CABECERA;

