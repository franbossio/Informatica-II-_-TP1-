#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include "Funciones.h"

using namespace std;

void menu(void);

int main(int argc, char *argv[]) {
	struct city *head_cordoba=NULL; 
	struct city *head_santaFe=NULL;
	struct city *head_mendoza=NULL;
	char op=' ';
	carga_archivo(&head_cordoba,&head_santaFe,&head_mendoza);
	do{
		menu();
		cin>>op;
		switch(op){
		case 'a': 
		case 'A':
			cout<<"-----------------------------------------------------------"<<endl;
			total_muestras(&head_cordoba,"Cordoba");
			total_muestras(&head_santaFe,"Santa Fe");
			total_muestras(&head_mendoza,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'b': 
		case 'B':
			cout<<"-----------------------------------------------------------"<<endl;
			temp_prom_prov(&head_cordoba,"Cordoba");
			temp_prom_prov(&head_santaFe,"Santa Fe");
			temp_prom_prov(&head_mendoza,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'c': 
		case 'C':
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"Cordoba:"<<endl;
			temp_prom_city(&head_cordoba);
			cout<<"Santa Fe:"<<endl;
			temp_prom_city(&head_santaFe);
			cout<<"Mendoza:"<<endl;
			temp_prom_city(&head_mendoza);
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'd': 
		case 'D':
			cout<<"-----------------------------------------------------------"<<endl;
			ciudad_calida(&head_cordoba,"Cordoba");
			ciudad_calida(&head_santaFe,"Santa Fe");
			ciudad_calida(&head_mendoza,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'e': 
		case 'E':
			cout<<"-----------------------------------------------------------"<<endl;
			ciudad_fria(&head_cordoba,"Cordoba");
			ciudad_fria(&head_santaFe,"Santa Fe");
			ciudad_fria(&head_mendoza,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'f': 
		case 'F':
			cout<<"-----------------------------------------------------------"<<endl;
			dia_frio(&head_cordoba,"Cordoba");
			dia_frio(&head_santaFe,"Santa Fe");
			dia_frio(&head_mendoza,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'g': 
		case 'G':
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"Cordoba:"<<endl;
			dia_calido(&head_cordoba);
			cout<<"Santa Fe:"<<endl;
			dia_calido(&head_santaFe);
			cout<<"Mendoza:"<<endl;
			dia_calido(&head_mendoza);
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'h': 
		case 'H':
			cout<<"-----------------------------------------------------------"<<endl;
			mejor_provincia_cultivos(&head_cordoba,&head_santaFe,&head_mendoza);
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		}
		cout<<"¿Deseas continuar(s/n)?:"<<endl;
		cin>>op;
	} while(op=='s'||op=='S');
	return 0;
}

void menu(void){
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"Elige una opcion:"<<endl;
	cout<<"a-Total de las muestras almacenadas en las listas pertenecientes a cada provincia."<<endl;
	cout<<"b-Temperatura promedio de cada provincia."<<endl;
	cout<<"c-Temperatura promedio de cada ciudad."<<endl;
	cout<<"d-Ciudad mas calida de cada provincia."<<endl;
	cout<<"e-Ciudad mas fria de cada provincia."<<endl;
	cout<<"f-Dia mas frio de cada provincia."<<endl;
	cout<<"g-Dia mas calido de cada ciudad."<<endl;
	cout<<"h-Mejor provincia para el cultivo de pimientos."<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
}




