#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 51

int main(){
    time_t hora;
    time(&hora);
    int menu,y=0;
    int a=0,b=0;
    int tempo,calen,calc,gp;


    do{

        if((a==0)&&(b==1))
            y=1;
        else{

            printf("%s\n%cHola de nuevo, Usuario!\n",ctime(&hora),173);
            printf("%cEn qu%c te puedo ayudar?\n1-.Temporizadores\n2-.Calend%crio\n3-.GPS\n4-.Calculadora\n5-.Cerrar sesi%cn\n",168,130,160,162);
            a=0;
            b=0;


            do {
                if(a==1)
                    menu=5;
                else{

                    scanf("%i",&menu);
                    switch (menu)
                            {
                        case 1:
                            system("cls");
                            printf ("TEMPORIZADORES:\n1-.Cron%cmetro\n2-.Cuenta atr%cs\n3-.Ciclos de tiempo\n4-.Atr%cs\n",162,160,160);
                            do {
                            scanf ("%i",&tempo);
                            switch (tempo)
                            {
                                case 1:
                                    printf ("Cron%cmetro\n",162);
                                break;
                                case 2:
                                    printf ("Cuenta atr%cs\n",160);
                                break;
                                case 3:
                                    printf ("Ciclos de tiempo\n");
                                break;
                                case 4:
                                    a=1;
                                    system("cls");
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;

                            }
                            }
                            while (tempo!=4);
                            menu=6;

                        break;


                        case 2:
                            system("cls");
                            printf ("CALENDARIO:\n1-.Recordatorios\n2-.Crear recordatorio\n3-.Editar recordatorio existente\n4-.Atr%cs\n",160);
                            do{
                            scanf ("%i",&calen);
                            switch (calen)
                            {
                                case 1:
                                    printf ("Recordatorios\n");
                                break;
                                case 2:
                                    printf ("Crear recordatorio\n");
                                break;
                                case 3:
                                    printf ("Editar recordatorio existente\n");
                                break;
                                case 4:
                                    a=1;
                                    system("cls");
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;
                            }
                            }
                            while(calen!=4);
                        break;


                        case 3:
                            system("cls");
                            printf ("GPS\n1-.Radar covid\n2-.Ruta mas corta\n3-.Localizaci%cn\n4-.Atr%cs\n",162,160);
                            do {
                            scanf ("%i",&gp);
                            switch (gp)
                            {
                                case 1:
                                    printf ("Radar covid\n");
                                break;
                                case 2:
                                    printf ("Ruta mas corta\n");
                                break;
                                case 3:
                                    printf ("Localizaci%cn\n",162);
                                    int i=0,j=0, x=25,y=25;     //Define la posición del usuario en el centro del mapa.
                                    srand(time(NULL));
                                    int x1 = (rand()%N+1) ;
                                    int y1 = (rand()%N+1) ;
                                    int x2 = (rand()%N+1) ;     //Define las posiciones aleatorias de la universidad y la casa.
                                    int y2 = (rand()%N+1) ;
                                    while(x1==x2||y1==y2){      //Comprueba que la universidad y la casa no están en el mismo sitio.
                                    int x1 = (rand()%N+1) ;
                                    int y1 = (rand()%N+1) ;
                                    }

                                    for(i=0;i<N;i++){
                                        printf("\n");        //Representa gráficamente.
                                        for(j=0;j<N;j++)
                                            if(j==x&&i==y)
                                                printf("X ");
                                    else if (i==x1&&j==y1)
                                            printf("C ");
                                    else if (i==x2&&j==y2)
                                            printf("U ");
                                    else
                                    printf(". ");
                                    }

                                    printf("\nCoordenadas x: %i y: %i.\nCoordenadas Casa: %i y: %i.\nCoordenadas Universidad: %i y: %i.",x,y,x1,y1,x2,y2); //Imprime coordenadas

                                if(x==x1&&y==y1)
                                    printf("\nHa llegado a casa.");                     //Comprueba si el usuario está en una de las coordenadas.
                                else if(x==x2&&y==y2)
                                        printf("\nHa llegado a su universidad.");
                                return 0;


                                break;
                                case 4:
                                    a=1;
                                    system("cls");
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;

                            }
                            }
                            while (gp!=4);
                        break;


                        case 4:
                            system("cls");
                            printf ("CALCULADORA:\n1-.Sumar\n2-.Restar\n3-.Multiplicar\n4-.Dividir\n5-.Atr%cs\n",160);
                            do{
                            scanf ("%i",&calc);
                            switch (calc)
                            {
                                case 1:
                                    printf ("Sumar\n");
                                break;
                                case 2:
                                    printf ("Restar\n");
                                break;
                                case 3:
                                    printf ("Multiplicar\n");
                                break;
                                case 4:
                                    printf ("Dividir\n");
                                break;
                                case 5:
                                    a=1;
                                    system("cls");
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;

                            }
                            }
                            while(calc!=5);

                        break;


                        case 5:
                            system("cls");
                            b=1;
                            printf ("Hasta luego!\n");
                        break;


                        default:
                            printf("Introduzca un n%cmero v%clido\n",163,160);
                        break;
                            }
                        }



                }
                while (menu!=5);

        }
    }
    while (y!=1);

return 0;

}
