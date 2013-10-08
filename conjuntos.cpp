#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define n 10
int c[n];
int a[n],b[n];
void interseccion(){
	int i,j,f=0;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if(a[i] == b[j]){
				c[f] = a[i];
				f++;
			}
		}
	}
	//metodo burbuja para el arreglo menor a mayor
	int aux=0;
	for (i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(c[j]>c[j+1]){
			aux=c[j];
			c[j]=c[j+1];
			c[j+1]=aux;
			}
			
		}
		
		
	}
	
	//imprime 
	for (i=0;i<10;i++){
		if(c[i]!=0 ){
			if(c[i]!= c[i+1])
	printf("%d\n",c[i]);
			}
		}
	
}

void uniones(){
	int s,f=0;
	int v_aux [10];
	int v_final [10];
	int cont,num,i,j=0,k,z=0 ;
	for (i=0;i<10;i++){
		for (s=0;s<10;s++){
			if(a[i] == b[s]){
				c[f] = a[i];
				f++;
			}else{
				c[s] = a[i];
				f++;
				c[f+1] = b[i];
				f++;
			}
		}
	}
	for (i=0;i<10;i++) {
		cont=0;
		num=c[i];
		v_aux[j]=num;
		j++;
		for (k=0;k<10;k++)
			if ( v_aux[k] == num )
				cont++;
		
		if ( cont == 1 ) {
			v_final[z]=num;
			z++;
		}
	}
	
	for (i=0;i<f;i++){
		printf("%d\n",v_final[i]);
	}
}

//negacion de B (lo que hay en A y no aparece en B)
void negacion(){
	int i,j,f=0;
	int d[n];
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if(a[i] == b[j]){
				c[f] = a[i];
				f++;
			}
		}
	}
	//metodo burbuja para el arreglo menor a mayor
	int aux=0;
	for (i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(c[j]>c[j+1]){
				aux=c[j];
				c[j]=c[j+1];
				c[j+1]=aux;
			}
		}
		
		
	}
	
	//imprime 
	for (i=0;i<10;i++){
		if(c[i]!=0 ){
			if(c[i]!= c[i+1])
				c[i] = d[i];  //arreglo d es la interseccion
		}
	}
	
	for (i=0;i<10;i++){
		if(d[i] != a[i])
			printf("%d\n",d[i]);
		
	}
}


int main(){
	
	int opc;
	
	int i;
	
	srand(time(NULL));
	printf("Generando numeros aleatorios del conjunto A \n");
	getch();
	for (i=0;i<10;i++){
		a[i]=(rand()%20)+1;
		printf("%d\n",a[i]);
	}
	printf(" Generando numeros aleatorios del conjunto B \n");
	getch();
	for (i=0;i<10;i++){
		b[i]=(rand()%20)+1;
		printf("%d\n",b[i]);
	}
	do{
		printf("\\MENU n1)Intersección 2)Union 3)negacion n4)Salir n");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				interseccion();
				break;
		case 2:
			uniones();
			break;
		case 3:
			negacion();
			break;
		case 4: return 0;
			break;
			default:
				printf("opción No valida");
				getch();
				
		}
	}while(opc!=4);
	
}




