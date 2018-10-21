/*
	Name: Jesus David Pérez
	Date: 09/12/14 
	Description: Simulador De Auto-lavado
*/

			/* LIBRERIAS */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

			/* Archivos */
			
#include "Simulacion_Const.cpp"
#include "Simulacion_Estruct.cpp"
#include "Simulacion_Time.cpp"
#include "Simulacion_Animacion.cpp"
#include "Simulacion_FuncF.cpp"
#include "Simulacion_FuncP.cpp"
                       
                           
int main(){
	
	inicio_simulacion();
	mostrar_date();
	creditos();
	
	return 0;
}
