#include <stdio.h>
#include <time.h>
int main(){
    time_t hora;
    time(&hora);
    int menu,x,y;
    int tempo,calen,calc,gp;


    printf("%s\n¡Hola de nuevo, Usuario!\n",ctime(&hora));
    printf("¿En qué te puedo ayudar?\n1-.Temporizadores\n2-.Calendario\n3-.GPS\n4-.Calculadora\n5-.Cerrar sesión\n");
    do {
    scanf("%i",&menu);
    switch (menu)
            {
        case 1:
            printf ("Temporizadores:\n1-.Cronómetro\n2-.Cuenta atras\n3-.Ciclos de tiempo\n4-.Atras\n");
            do {
            scanf ("%i",&tempo);
            switch (tempo)
            {
                case 1:
                    printf ("Cronómetro\n");
                break;
                case 2:
                    printf ("Cuenta atrás\n");
                break;
                case 3:
                    printf ("Ciclos de tiempo\n");
                break;
                case 4:
                    printf ("*menu principal*\n");
                break;
                default:
                     printf("Introduce un número válido\n");
                break;

            }
            }
            while (tempo!=4);


        break;


        case 2:
            printf ("Calendario:\n1-.Recordatorios\n2-.Crear recordatorio\n3-.Editar recordatorio existente\n4-.Atras\n");
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
                    x=1;
                    printf ("*menu principal*\n");
                break;
                default:
                     printf("Introduce un número válido\n");
                break;
            }
            }
            while(calen!=4);
        break;


        case 3:
            printf ("GPS\n1-.Radar covid\n2-.Ruta mas corta\n3-.Localizacion\n4-.Atras\n");
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
                    printf ("Localizacion\n");
                break;
                case 4:
                    x=1;
                    printf ("*menu principal*\n");
                break;
                default:
                     printf("Introduce un número válido\n");
                break;

            }
            }
            while (gp!=4);
        break;


        case 4:
            printf ("Calculadora\n1-.Sumar\n2-.Restar\n3-.Multiplicar\n4-.Dividir\n5-.Atras\n");
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
                    x=1;
                    printf ("*menu principal*\n");
                break;
                default:
                     printf("Introduce un número válido\n");
                break;

            }
            }
            while(calc!=5);

        break;


        case 5:
            printf ("Nos vemos\n\n");
        break;


        default:
            printf("Introduzca un número válido\n");
        break;
            }
        }

    while (menu!=5);




return 0;

}
