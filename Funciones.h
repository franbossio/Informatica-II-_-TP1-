#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;
struct timestamp{
	int day;
	int month;
	int hh;
	int mm;
};

struct measurement{
	float temp;
	float hum;
	struct timestamp time;
};

struct city{
	struct city *next;
	struct measurement m;
	int cityID;
	int prov;
	char city_name[50];
};

void check(struct city **head){
	if(*head==NULL){
		cout<<"Lista vacia."<<endl;
		exit(1);
	}
}
void agregar(struct city **head, struct city **nuevo){
	struct city *aux=NULL;
	if(*head==NULL){
		*head=*nuevo;
	}else{
		aux=*head;
		while(aux->next!=NULL){
			aux=aux->next;
		}
		aux->next=*nuevo;
	}
}
	
void carga_archivo(struct city **head,struct city **head2,struct city **head3){
	struct city *nuevo=NULL;
	int ID, prov, hh, mm, day, month;
	char ciudad[50];
	float temp, hum;
	ifstream arch;
	arch.open("data_set.txt", ios::in);//abrimos el  archivo en modo lectura
	if(arch.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	while(!arch.eof()){//mientras no sea el final del archivo
		arch>>ID>>prov>>ciudad>>temp>>hum>>hh>>mm>>day>>month;
		if(!arch.eof()){
			nuevo=(struct city *)malloc(sizeof(struct city)+sizeof(struct measurement)+sizeof(struct timestamp));
			if(nuevo==NULL){
				cout<<"No hay memoria suficiente."<<endl;
				exit(1);
			}
			nuevo->cityID=ID;
			nuevo->prov=prov;
			strcpy(nuevo->city_name,ciudad);
			nuevo->m.temp=temp;
			nuevo->m.hum=hum;
			nuevo->m.time.hh=hh;
			nuevo->m.time.mm=mm;
			nuevo->m.time.day=day;
			nuevo->m.time.month=month;
			nuevo->next=NULL;
			if(prov==1){
				agregar(head,&nuevo);
			}
			if(prov==2){
				agregar(head2,&nuevo);
			}
			if(prov==3){
				agregar(head3,&nuevo);
			}
		}
	}
	arch.close();
}

	
void total_muestras(struct city **head,string state){
	struct city *aux=NULL;
	int total=0;
	check(head);
	aux=*head;
	while(aux!=NULL){
		total++;
		aux=aux->next;
	}
	cout<<"Total de "<<state<<": "<<total<<endl;
}

float calc_prom(struct city **head){
	struct city *aux=NULL;
	float prom=0, suma=0;
	int c=0;
	aux=*head;
	check(head);
	while(aux!=NULL){
		suma=suma+aux->m.temp;
		aux=aux->next;
		c++;
	}
	prom=suma/c;
	return prom;
}
	
void temp_prom_prov(struct city **head,string state){
	float prom=0;
	prom=calc_prom(head);
	cout<<"Temperatura promedio de "<<state<<": "<<prom<<endl;
}




void temp_prom_city(struct city **head){
	struct city *actual=NULL;
	struct city *sig=NULL;
	float prom=0, suma=0;
	int c=0;
	if(*head==NULL){
		cout<<"Lista vacia."<<endl;
		exit(1);
	}
	actual=*head;
	sig=(*head)->next;
	while(actual!=NULL){
		c++;
		suma=suma+actual->m.temp;
		if(sig==NULL || actual->cityID!=sig->cityID){
			prom=suma/c;
			cout<<"El promedio de la ciudad "<<actual->city_name<<"es: "<<prom<<endl;
			c=0;
			suma=0;
		}
		actual=actual->next;
		if(actual!=NULL){
			sig=sig->next;
		}
	}
}
void ciudad_calida(struct city **head, string state){
	struct city *actual=NULL;
	struct city *sig=NULL;
	float prom=0, suma=0, mayor=0;
	int c=0;
	string name_city;
	if(*head==NULL){
		cout<<"Lista vacia."<<endl;
		exit(1);
	}
	actual=*head;
	sig=(*head)->next;
	while(actual!=NULL){
		c++;
		suma=suma+actual->m.temp;
		if(sig==NULL || actual->cityID!=sig->cityID){
			prom=suma/c;
			if(mayor<prom){
				mayor=prom;
				name_city=actual->city_name;
			}
			c=0;
			suma=0;
		}
		actual=actual->next;
		if(actual!=NULL){
			sig=sig->next;
		}
	}
	cout<<"La ciudad mas calidad de la provincia de "<<state<<" es "<<name_city<<" con: "<<mayor<<"°"<<endl;
}
void ciudad_fria(struct city **head, string state){
	struct city *actual=NULL;
	struct city *sig=NULL;
	float prom=0, suma=0, menor=100;
	int c=0;
	string name_city;
	if(*head==NULL){
		cout<<"Lista vacia."<<endl;
		exit(1);
	}
	actual=*head;
	sig=(*head)->next;
	while(actual!=NULL){
		c++;
		suma=suma+actual->m.temp;
		if(sig==NULL || actual->cityID!=sig->cityID){
			prom=suma/c;
			if(menor>prom){
				menor=prom;
				name_city=actual->city_name;
			}
			c=0;
			suma=0;
		}
		actual=actual->next;
		if(actual!=NULL){
			sig=sig->next;
		}
	}
	cout<<"La ciudad mas fria de la provincia de "<<state<<" es "<<name_city<<" con: "<<menor<<"°"<<endl;
}
	
void dia_frio(struct city **head, string state){
	struct city *actual=NULL;
	float menor=100;
	int day_city=0, month_city=0;
	if(*head==NULL){
		cout<<"Lista vacia."<<endl;
		exit(1);
	}
	actual=*head;
	while(actual!=NULL){
		if(actual->m.temp<menor){
			menor=actual->m.temp;
			day_city=actual->m.time.day;
			month_city=actual->m.time.month;
		}
		actual=actual->next;
	}
	cout<<"La el dia mas frio de la provincia de "<<state<<" es "<<day_city<<"/"<<month_city<<" con: "<<menor<<"°"<<endl;
}

void dia_calido(struct city **head, string state){
	struct city *actual=NULL;
	struct city *sig=NULL;
	float mayor=0;
	int day_city=0, month_city=0;
	string name_city;
	if(*head==NULL){
		cout<<"Lista vacia."<<endl;
		exit(1);
	}
	actual=*head;
	sig=(*head)->next;
	while(actual!=NULL){
		if(sig==NULL || actual->cityID!=sig->cityID){
			if(actual->m.temp>mayor){
				mayor=actual->m.temp;
				day_city=actual->m.time.day;
				name_city=actual->city_name;
				month_city=actual->m.time.month;
			}
		}
		actual=actual->next;
		if(actual!=NULL){
			sig=sig->next;
		}
	}
	cout<<"El dia mas calido de la ciudad de "<<name_city<<" de la provincia de "<<state<<" es "<<day_city<<"/"<<month_city<<" con: "<<mayor<<"°"<<endl;
}
	
void best_prov(struct city **head,struct city **head2, struct city **head3){
	float prom_cordoba=0, prom_santaFe=0, prom_mendoza=0, cord=0, men=0, sant=0;
	prom_cordoba=calc_prom(head);
	prom_santaFe=calc_prom(head2);
	prom_mendoza=calc_prom(head3);
	cord=fabs(prom_cordoba-23.0);
	sant=fabs(prom_santaFe-23.0);
	men=fabs(prom_mendoza-23.0);
	if(cord<sant && cord<men){
		cout<<"Cordoba es la mejor provincia para el cultivos de pimientos"<<endl;
	}
	if(sant<cord && sant<men){
		cout<<"Santa Fe es la mejor provincia para el cultivos de pimientos"<<endl;
	}
	if(men<cord && men<sant){
		cout<<"Mendoza es la mejor provincia para el cultivos de pimientos"<<endl;
	}
	
}
