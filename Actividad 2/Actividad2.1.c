#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<ctype.h>
#include "kbhit.h"  // Incluir la librería kbhit.h

//El Prog debe ir tal cual se encuentra

#define DELAY 100000  // 100ms de delay

void manejarLineaComandos(char *comando, int *comandoIndex, FILE **archivo, int *leyendoArchivo);
void evaluarComando(char *comando, FILE **archivo, int *leyendoArchivo);
int leerLineaArchivo(FILE *archivo);

int main() {
    char comando[200] = "";  // Buffer para el comando
    int comandoIndex = 0;
    FILE *archivo = NULL;
    int leyendoArchivo = 0;

    printf("\n#>");  // Imprimir el prompt antes de entrar al bucle

    do {
        if (kbhit()) {
            manejarLineaComandos(comando, &comandoIndex, &archivo, &leyendoArchivo);
        }

        if (leyendoArchivo && archivo) {
            if (leerLineaArchivo(archivo)) {
                fclose(archivo);
                archivo = NULL;
                leyendoArchivo = 0;
            }
        }

        usleep(DELAY);  // Pequeño delay
    } while (1);  // Bucle infinito
}


void manejarLineaComandos(char *comando, int *comandoIndex, FILE **archivo, int *leyendoArchivo) {
    char tecla = getchar();
    
    if (tecla == '\n') {  
        comando[*comandoIndex] = '\0';  
        for (int i = 0; comando[i]; i++)
        {
            comando[i] = toupper((unsigned char )comando[i]);
        }
        
        printf("\nComando:%s\n", comando);
        evaluarComando(comando, archivo, leyendoArchivo);
        *comandoIndex = 0;  
        comando[0] = '\0';  
    } else if (tecla == 127 || tecla == 8) {  // Retroceso
        if (*comandoIndex > 0) {
            (*comandoIndex)--;
            comando[*comandoIndex] = '\0';
        }
    } else {  
        comando[(*comandoIndex)++] = tecla;
        comando[*comandoIndex] = '\0';
    }

    // Mostrar la salida progresiva sin saltos de línea
    printf("\n#>%s", comando);
    fflush(stdout);
}

void evaluarComando(char *comando, FILE **archivo, int *leyendoArchivo) {
    char operacion[20], parametro[180] = "";
    if (sscanf(comando, "%s %s", operacion, parametro) >= 1) {
        
        if (strcmp(operacion, "LOAD") == 0 || strcmp(operacion, "CARGAR") == 0) {
            if (strlen(parametro) == 0) {
                printf("Uso: LOAD <nombre_archivo>\n");
                return;
            }
            *archivo = fopen(parametro, "r");
            if (!*archivo) {
                printf("Error: no se pudo abrir el archivo: %s.\n", parametro);
                return;
            }
            *leyendoArchivo = 1;
        } else if (strcmp(operacion, "EXIT") == 0 || strcmp(operacion, "SALIR") == 0) {
            exit(0);
        } else {
            printf("Comando incorrecto...\n");
        }
    }
}

int leerLineaArchivo(FILE *archivo) {
    char linea[256];
    if (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
        return 1;
    }
    return 0;
}
