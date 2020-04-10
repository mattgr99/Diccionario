#include <conio.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <sstream>
#include <windows.h> 
#include "hash.h"
using namespace std;

/* Función para convertir cualquier tipo
de datos a string.
*/
/*template <class T>
inline string ToString(const T& t) {
stringstream ss;
ss << t;
return ss.str();
}

/* Función para emular al gotoxy en la consola de
Linux.
*/
/*inline string gotoxy(const int& x,const int& y) {
return "\33[" + ToString(x) + ";" + ToString(y) + "H";
}*/
/*#define MAX_SCREEN_AREA 100
int gotoxy(int x, int y){
char essq[MAX_SCREEN_AREA]={0}; // String variable to hold the escape sequence
sprintf(essq, "\033[%d;%df", y,x);
printf("%s", essq);
return 0;
}*/
//using namespace std;

/*
 * 
 */
struct NODO {
    char nombre[30];
    char significado[30];
    NODO *sig;
};


//funcion para calcular el numero primo siguiente
/*void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }*/
 
/*void gotoxy(int x, int y) 
{ 
printf("33[%d;%df", y, x); 
fflush(stdout); 
} */

/*void gotoxy(int x, int y)
{
  printf("\033[%d;%df", y, x);
  //fflush(stdout);
}*/




//funcion que inicializara las posiciones del VECTOR EN NULL

NODO* iniTabla(NODO* tabla[], int tamanoTabla) {
    for (int i = 0; i < tamanoTabla; i++)
        tabla[i] = NULL;
    return *tabla;
}

NODO *ingresarDatos(NODO *tabla[], int tamanoTabla, int elementos, char pe[], char pk[]) {
    //int rep;
    //  for (int i = 1; i <= elementos; i++) {
    //do {
    //rep = 0;
    int clave = 0, valor = 0, res, res1 = 0;
    bool bandera = true;

    NODO *nuevo = new NODO;
    //fflush(stdin);
    strcpy(nuevo->nombre, pe);
    strcpy(nuevo->significado, pk);
    //fflush(stdin);
    nuevo->sig = NULL;
    clave = dispersion1(nuevo->nombre, tamanoTabla);
    if (tabla[clave] == NULL)
        tabla[clave] = nuevo;
    else {
        NODO *aux = tabla[clave];
        do {
            valor = strcmp(aux->nombre, nuevo->nombre);
            if (valor == 0) {
                // printf("\nEste nombre ya se encuentra ingresado\n");
                bandera = false;
                // rep = 1;
                free(nuevo);
                break;
            }
            aux = aux->sig;
        } while (aux != NULL);

        if (bandera) {
            aux = nuevo;
            aux->sig = tabla[clave];
            tabla[clave] = aux;
        }


    }


    // } while (rep == 1);
    // }
    return *tabla;
}

void mostrarDatosTabla(NODO *tabla[], int tamanoTabla) {
   	system("cls");
    printf("\nNo      Palabra\t\t    Significado\n\n");
   int j=2;
    for (int i = 0; i < tamanoTabla; i++) {

        if (tabla[i] != NULL) {
            NODO *aux = tabla[i];
            
            do {
                if (aux == NULL)
                    break;
                
				gotoxy(1,++j);   
                printf("%d.", i + 1);
                gotoxy(9,j);   
                printf("%s:",aux->significado);
                gotoxy(32,j);   
                printf("%s",aux->nombre);
                aux = aux->sig;

            } while (aux != NULL);
        }
    }
    //
     //gotoxy(15,10); 
//%s:\t\t%s\n, aux->significado, aux->nombre

getch();
}

void buscarenTabla(NODO *tabla[], int tamanoTabla) {
    unsigned t0, t1;

    t0 = clock();
    int i, valor = 0;
    char textoBsq[30];
    bool bandera = true;
    printf("\nUsuario ingresa la palabra que desea buscar:\t");
    fflush(stdin);
    scanf("%s", &textoBsq);
    for (i = 0; i < tamanoTabla; i++) {
        if (tabla[i] != NULL) {
            NODO *aux = tabla[i];
            do {
                valor = strcmp(textoBsq, aux->nombre);
                if (valor == 0) {
                    printf("\nSignificado: %s\n", aux->significado);
                    bandera = false;
                    break;
                }
                aux = aux->sig;
            } while (aux != NULL);
        }
    }
    if (bandera)
        printf("\nElemento no encontrado\n");
    // Code to execute
    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Tiempo de busqueda: " << time << endl;
}
void traducirfrase(NODO *tabla[], int tamanoTabla,char textbusqueda[]) {
    
    int i, valor = 0;
    
    bool bandera = true;
    
    for (i = 0; i < tamanoTabla; i++) {
        if (tabla[i] != NULL) {
            NODO *aux = tabla[i];
            do {
                valor = strcmp(textbusqueda, aux->nombre);
                if (valor == 0) {
                    printf("%s ", aux->significado);
                    bandera = false;
                    break;
                }
                aux = aux->sig;
            } while (aux != NULL);
        }
    }
    if (bandera)
        printf("[%s] ", textbusqueda);
    // Code to execute
    
}

main() {
    int opc = 0, M = 0, N = 0, el, val=0, numero, M1;
    float fac, c1, c2;
    FILE *f;
    char palabras1[30], palabrae[30], palabrak[30], pales[30], palkc[30], frase[100],palabrasep[30];
    char *p;
    //do {

    /*printf("\nUsuario ingresa la cantidad de elementos a dispersar:\t");
    scanf("%d", &M);
    if (M <= 1)
        printf("\n********ERROR, Usuario ingresa un valor positivo mayor que 1\n");
} while (M <= 1);*/
    f = fopen("palabras.dat", "r");
    if (f == NULL) {
        printf("No hay fichero");
    } else {
        do {
            fscanf(f, "%s", &palabras1);
            //*tabla = ingresarDatos(tabla, N, M,ciud);*/
            fflush(stdin);
            M++;
        } while (!feof(f));
    }
 M1 = M;
    fclose(f);
    N = primoSgt(M);
    NODO * tabla[N];
    *tabla = iniTabla(tabla, N);


//system("clear"); // Importante para no sobreescribir la pantalla.
// Emular goto(x, y);
//cout << gotoxy(30,40) << "Hola" << endl;
    do {
        do {
        	opc=menu();
            if (opc < 1 || opc > 6)
                printf("\n***Error,Ingresa un valor dentro del rango\n");
        } while (opc < 1 || opc > 6);
        switch (opc) {
            case 1:

                f = fopen("palabras.dat", "r");
                if (f == NULL) {
                    printf("No hay fichero");
                } else {
                    do {
                    	val++;
                        fscanf(f, "%s", palabras1);
                        //fgets(ciud, 30, f);
                        
                        //scanf("%*c%[^\n]",variable);
                        if (val == 1)
                            strcpy(palkc, palabras1);
                        else {
                            strcpy(pales, palabras1);
                            *tabla = ingresarDatos(tabla, N, M, pales, palkc);
                            val = 0;
                        }

                    } while (!feof(f));
                    printf("\n\nDATOS CARGADOS\n");
                }

                fclose(f);
                break;
            case 2:
                c1 = M1;
                c2 = N;
                fac = c1 / c2;
                if (fac > 0.75)
                    printf("No puede ingresar mas elementos\n");
                else {

                    val = 0;

                    do {
                        M1++;
                        printf("Palabra en espaniol: ");
                        scanf("%s", &palabrae);
                        printf("Palabra en kichwa: ");
                        scanf("%s", &palabrak);
                        *tabla = ingresarDatos(tabla, N, M, palabrae, palabrak);

                        printf("Desea ingresar otro elemento (1.si/2.no)\n");
                        scanf("%d", &el);
                        c1 = M1;
                        c2 = N;
                        fac = c1 / c2;
                        if (fac > 0.75) {
                            printf("No puede ingresar mas elementos\n");
                            break;
                        }
                    } while ((el > 0)&&(el < 2));
                }



                break;
            case 3: mostrarDatosTabla(tabla, N);
                break;
            case 4:
                do {
                    buscarenTabla(tabla, N);
                    printf("Desea buscar otra palabra (1.si/2.no)\n");
                    scanf("%d", &el);
                } while ((el > 0)&&(el < 2));
                break;
            case 5: printf("\nIngrese la frase que desea traducir\n");
                //fflush(stdin);
                fgets(frase, 100, stdin);
                cin.getline(frase, 100);
                fflush(stdin);
               printf("\n");
                char *p=strtok(frase," ");
                //strcpy(palabrasep,frase);
               // traducirfrase(tabla, N,palabrasep);
                while(p!=NULL){
                strcpy(palabrasep,p);
                //printf("\n%s\n",palabrasep);
                traducirfrase(tabla, N,palabrasep);
                 p=strtok(NULL," ");
                }
                printf("\n");
                break;
        }
    } while (opc != 6);
}
