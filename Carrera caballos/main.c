#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

const int DISTANCIAPISTA=40;
const float MIN=1.0;
const float MAX=4.5;
void imprimirPista(char pista[][DISTANCIAPISTA], int validos);
int main()
{
    srand(time(NULL));
    int saldo;
    int caballoElegido;
    double multi1=MIN+(double)rand()/ RAND_MAX*(MAX-MIN);
    double multi2=MIN+(double)rand()/ RAND_MAX*(MAX-MIN);
    int filas=7;
    char pista[filas][DISTANCIAPISTA];
    //cargamos la pista
    for(int f=0;f<8;f++)
    {
        for(int i=0;i<DISTANCIAPISTA;i++)
        {
            if((i==0) || (i==DISTANCIAPISTA-1))
            {
                pista[f][i]='|';
            }
            else if((f==0) || (f==filas-1))
            {
                pista[f][i]='=';
            }
            else
            {
                pista[f][i]=' ';
            }
        }
    }

    //pedimos el ingreso de las apuestas
    printf("ingrese dinero a apostar: ");
    scanf("%i", &saldo);
    do{
        printf("por cual caballo va a apostar\ncaballo 1(el de arriba) %f \ncaballo 2(el de abajo) %f\n",multi1,multi2);
        scanf("%i", &caballoElegido);
        system("cls");
    }while((caballoElegido!=1)&&(caballoElegido!=2));

    printf("Cargando datos");
    for(int i=0;i<3;i++)
    {
        printf(".");
        Sleep(500);
    }
    printf("EMPIEZA LA CARRERA");
    int index1=1;//caballo 1
    int index2=1;//caballo 2
    while((index1!=DISTANCIAPISTA-2) && (index2!=DISTANCIAPISTA-2))
    {
        system("cls");
        int posibilidades1=rand()%2;
        int posibilidades2=rand()%2;
        if(posibilidades1==1)
        {
            index1++,
            pista[2][index1]='-';
            pista[2][index1-1]=' ';
        }
        if(posibilidades2==1)
        {
            index2++,
            pista[4][index2]='-';
            pista[4][index2-1]=' ';
        }
        imprimirPista(pista,filas);
        Sleep(100);
    }
    if(index1==DISTANCIAPISTA-2)
    {
        double win=saldo*multi1;
        printf("\n\nCABALLO 1 GANADOR\n\ntu apuesta :%i",saldo);
        if(caballoElegido==1)
        {
            printf("\ntotal:%f",win);
        }
        else
        {
            printf("\nPERDISTE ");
        }
    }
    if(index2==DISTANCIAPISTA-2)
    {
        double win=saldo*multi2;
        printf("\n\nCABALLO 2 GANADOR\n\ntu apuesta :%i",saldo);
        if(caballoElegido==2)
        {
            printf("\ntotal:%f",win);
        }
        else
        {
            printf("\nPERDISTE ");
        }
    }


    return 0;
}
void imprimirPista(char pista[][DISTANCIAPISTA], int validos)
{
    for(int f=0;f<validos;f++)
    {
        for(int i=0;i<DISTANCIAPISTA;i++)
        {
            printf("%c", pista[f][i]);
        }
        printf("\n");
    }
}
