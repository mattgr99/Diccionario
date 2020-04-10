#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <ctime> 
#include <sstream>
#include <windows.h> 
#include <conio.h> 
using namespace std; 
int menu(){
int op;	
printf("\n==============DICCIONARIO KICHWA================\n\n");
            printf("\t1. Cargar Datos de Disco\n");
            printf("\t2. Ingresar Datos por Teclado\n");
            printf("\t3. Imprimir Diccionario \n");
            printf("\t4. Buscar Palabra\n");
            printf("\t5. Traducir Frase\n");
            printf("\t6. SALIR\n");
            printf("\tUsuario ingresa una opcion (1-6):\t");
            scanf("%d", &op);
   return op;         
} 
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 int primoSgt(int num) {
    float m1, n1;
    float facdis;
    int cont;
    m1 = num;
    do {
        while (true) {
            num++;
            cont = 0;
            for (int i = 1; i < (num + 1); i++) {
                if (num % i == 0) {
                    cont++;
                }
            }
            if (cont == 2) {
                break;
            }
        }

        n1 = num;
        facdis = m1 / n1;
    } while (facdis >= 0.75);
    return num;
}
int dispersion1(char nombre[], int tamanoTabla) {
    int i, suma = 0, clave = 0;

    for (i = 0; i < strlen(nombre); i++)
        suma += nombre[i];
    clave = suma % tamanoTabla;
    return clave;
}



