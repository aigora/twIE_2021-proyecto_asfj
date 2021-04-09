#include <stdio.h>
#include <time.h>
int main(){
    time_t hora;
    time(&hora);
    int menu;
    int tempo;
    int calen;
    printf("%s\n¡Hola de nuevo, Usuario!\n",ctime(&hora));
    printf("¿En qué te puedo ayudar?\n1-.Temporizadores\n2-.Calendario\n3-.GPS\n4-.Calculadora\n5-.Cerrar sesión\n");
    do {
    scanf("%i",&menu);
    switch (menu)
            {
        case 1:
            printf ("Temporizadores:\n");
            scanf ("%i",&tempo);
            switch (tempo)
            {
                case 1:
                    printf ("Cronómetro\n");
                break;
                case 2:
                    printf ("Cuenta atrás");
                break;
                case 3:
                    printf ("Ciclos de tiempo");
                break;
                case 4:
                    printf ()


            }

        break;
        case 2:
            printf ("Calendario\n");
        break;
        case 3:
            printf ("GPS\n");
        break;
        case 4:
            printf ("Calculadora\n");
        break;
        case 5:
            printf ("Nos vemos\n");
        break;
        default:
            printf("Introduce un número válido\n");
        break;
            }
        }
 while (menu!=5);

return 0;

}
