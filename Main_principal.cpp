#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include "Funciones.h"

using namespace std;

void menu(void);

int main(int argc, char *argv[]) {
	struct city *head=NULL; 
	struct city *head2=NULL;
	struct city *head3=NULL;
	char op=' ';
	carga_archivo(&head,&head2,&head3);
	do{
		menu();
		cin>>op;
		switch(op){
		case 'a': 
		case 'A':
			cout<<"-----------------------------------------------------------"<<endl;
			total_muestras(&head,"Cordoba");
			total_muestras(&head2,"Santa Fe");
			total_muestras(&head3,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'b': 
		case 'B':
			cout<<"-----------------------------------------------------------"<<endl;
			temp_prom_prov(&head,"Cordoba");
			temp_prom_prov(&head2,"Santa Fe");
			temp_prom_prov(&head3,"Mendoza");
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'c': 
		case 'C':
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"Cordoba:"<<endl;
			temp_prom_city(&head);
			cout<<"Santa Fe:"<<endl;
			temp_prom_city(&head2);
			cout<<"Mendoza:"<<endl;
			temp_prom_city(&head3);
			cout<<"-----------------------------------------------------------"<<endl;
			break;
		case 'd': 
		case 'D':
			ciudad_calida(&head,"Cordoba");
			ciudad_calida(&head2,"Santa Fe");
			ciudad_calida(&head3,"Mendoza");
			break;
		case 'e': 
		case 'E':
			ciudad_fria(&head,"Cordoba");
			ciudad_fria(&head2,"Santa Fe");
			ciudad_fria(&head3,"Mendoza");
			break;
		case 'f': 
		case 'F':
			dia_frio(&head,"Cordoba");
			dia_frio(&head2,"Santa Fe");
			dia_frio(&head3,"Mendoza");
			break;
		case 'g': 
		case 'G':
			dia_calido(&head,"Cordoba");
			dia_calido(&head2,"Santa Fe");
			dia_calido(&head3, "Mendoza");
			break;
		case 'h': 
		case 'H':
			best_prov(&head,&head2,&head3);
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




