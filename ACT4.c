#include <stdio.h>
#include <stdlib.h>

void inicializar_tablero();
void mostrar_tablero(char gato[][3]);
void realizar_movimientos(char gato[][3]);
int resultados(char tablero[][3]);

int jugador1 = 1, jugador2;

int main(){
    inicializar_tablero();
    return 0;
}

void inicializar_tablero(){
    char gato[3][3];
    mostrar_tablero(gato);
}

void mostrar_tablero(char gato[][3]){
    system("cls");
    printf("Hola aqui tienes el tablero\n");

    printf("\t|\t|\n");
    printf("%c\t|%c\t|%c\n",gato[0][0],gato[0][1],gato[0][2]);
    printf("________|_______|________\n");
    printf("\t|\t|\n");
    printf("%c\t|%c\t|%c\n",gato[1][0],gato[1][1],gato[1][2]);
    printf("________|_______|________\n");
    printf("\t|\t|\n");
    printf("%c\t|%c\t|%c\n",gato[2][0],gato[2][1],gato[2][2]);
    printf("\t|\t|\n\n");
    if(resultados(gato) != 0){
        printf("El ganador es el jugador %i\n", resultados(gato));
    }else{
        realizar_movimientos(gato);
    }
}

void realizar_movimientos(char gato[][3]){
    int movx1, movy1, movx2, movy2;
    if(jugador1){
        printf("Jugador 1, ingrese su movimiento en x\n");
        scanf("%i", &movx1);
        printf("Jugador 1, ingrese su movimiento en y\n");
        scanf("%i", &movy1);
        if(gato[movx1][movy1] != 'x' && gato[movx1][movy1] != 'o'){
            gato[movx1][movy1] = 'x';
            jugador1 = 0;
            jugador2 = 1;
            mostrar_tablero(gato);
        }else{
            printf("Esa casilla esta ocupada, ingrese otra.\n");
            realizar_movimientos(gato);
        }
    }else if(jugador2){
        printf("Jugador 2, ingrese su movimiento en x\n");
        scanf("%i", &movx2);
        printf("Jugador 2, ingrese su movimiento en y\n");
        scanf("%i", &movy2);
        if(gato[movx2][movy2] != 'x' && gato[movx2][movy2] != 'o'){
           gato[movx2][movy2] = 'o';
            jugador1 = 1;
            jugador2 = 0;
            mostrar_tablero(gato);
        }else{
            printf("Esa casilla esta ocupada, ingrese otra.\n");
            realizar_movimientos(gato);
        }
    }
}

int resultados(char tablero[][3]){
    int ganador;
    if ((tablero[0][0] == 'x' && tablero[0][1] == 'x' && tablero[0][2] == 'x')||
        (tablero[1][0] == 'x' && tablero[1][1] == 'x' && tablero[1][2] == 'x')||
        (tablero[2][0] == 'x' && tablero[2][1] == 'x' && tablero[2][2] == 'x') ||
        (tablero[0][0] == 'x' && tablero[1][0] == 'x' && tablero[2][0] == 'x') ||
        (tablero[0][1] == 'x' && tablero[1][1] == 'x' && tablero[2][1] == 'x') ||
        (tablero[0][2] == 'x' && tablero[1][2] == 'x' && tablero[2][2] == 'x') ||
        (tablero[0][0] == 'x' && tablero[1][1] == 'x' && tablero[2][2] == 'x') ||
        (tablero[0][2] == 'x' && tablero[1][1] == 'x' && tablero[2][0] == 'x')){
            ganador = 1;

    }else{
        if((tablero[0][0] == 'o' && tablero[0][1] == 'o' && tablero[0][2] == 'o')||
            (tablero[1][0] == 'o' && tablero[1][1] == 'o' && tablero[1][2] == 'o')||
            (tablero[2][0] == 'o' && tablero[2][1] == 'o' && tablero[2][2] == 'o')||
            (tablero[0][0] == 'o' && tablero[1][0] == 'o' && tablero[2][0] == 'o')||
            (tablero[0][1] == 'o' && tablero[1][1] == 'o' && tablero[2][1] == 'o')||
            (tablero[0][2] == 'o' && tablero[1][2] == 'o' && tablero[2][2] == 'o')||
            (tablero[0][0] == 'o' && tablero[1][1] == 'o' && tablero[2][2] == 'o')||
            (tablero[0][2] == 'o' && tablero[1][1] == 'o' && tablero[2][0] == 'o')){
                ganador = 2;
        }
    }
    return ganador;
}
