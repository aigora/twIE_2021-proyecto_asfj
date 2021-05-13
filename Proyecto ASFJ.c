#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <windows.h>

 float potencia(float base, int exponente);

int main(){

    time_t t;
    struct tm *tm;
    char fechayhora[100];
    int d,m,y;
    int menu,p=0,a=0,b=0; //variables para controlar la posición en el menú
    int tempo,calen,calc,gp;

    //dar la hora y dia en pantalla
    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%H:%M\t\t%d/%m/%Y", tm);
    printf ("\n\t %s \n",fechayhora);

    //asigno en variables la fecha para luego usarlas en el calendario
    d=tm->tm_mday;
    m=1+tm->tm_mon;
    y=1900+tm->tm_year;
    //printf("%d\n",d);
    //printf("%d\n",m);
    //printf("%d\n",y);



    do{

        if((a==0)&&(b==1))
            p=1;
        else{

            printf("\n%cHola de nuevo, Usuario!\n",173);
            printf("%cEn qu%c te puedo ayudar?\n\n1-.Temporizadores\n2-.Calendario\n3-.GPS\n4-.Calculadora\n5-.Cerrar sesi%cn\n",168,130,162);
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
                                    int segundos=0,minutos=0,horas=0;
                                    printf("¡Bienvenido al cronómetro!\n Pulsa espacio para iniciar:\n[%.2i:%.2i:%.2i]",horas,minutos,segundos);
                                    system("pause ->NULL");
                                    while (1){
                                    segundos++;
                                    if(segundos==60){
                                    segundos=0;
                                    minutos=minutos+1;
                                    if (minutos==60){
                                    minutos=0;
                                    horas++;
                                    }
                                    }

                                    system("cls");
                                    printf("[%.2d:%.2d:%.2d]",horas,minutos,segundos);
                                    Sleep(1000);
                                     }
                                     }

                                break;
                                case 2:
                                    printf ("Cuenta atr%cs\n",160);
                                        int i = 0;
                                        int segundos, minutos, horas, total;

                                        printf("Dime los segundos, minutos y horas que desee\n");//Hay que escribir los segundos, minutos y horas seguidos separados por un espacio
                                        scanf("%i %i %i",&segundos,&minutos,&horas);
                                        total=segundos + 60*minutos + 3600*horas;
                                        printf("El programa terminara %i en segundos.\n", total);




                                        for(i=0; i<total; i++){
                                            Sleep(1000);
                                            //printf("%i\n", i+1);

                                            system("cls");
                                                printf("\n\n\n\t\t\t[ %.2d:%.2d:%.2d ]", horas, minutos, segundos);


                                            segundos=segundos-1;
                                            if(segundos==0&&minutos>0) {
                                                    minutos=minutos-1;
                                                    segundos=59;
                                            }
                                            if (minutos==0&&horas>0) {
                                                    horas=horas-1;
                                                    minutos=59;
                                            }


                                            }

                                                return 0;
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
                            printf ("CALCULADORA:\n1-.Sumar\n2-.Restar\n3-.Multiplicar\n4-.Dividir\n5-.Potencia\n6-.Atr%cs\n",160);
                            do{
                            scanf ("%i",&calc);

                            float x, y, resultado;
                            int valido = 1;

                            switch (calc)
                            {
                                case 1:
                                    printf ("Sumar\n");

                                    printf("Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x + y;
                                    printf("El resultado es %f\n", resultado);
                                break;
                                case 2:
                                    printf ("Restar\n");

                                    printf("Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x - y;
                                    printf("El resultado es %f\n", resultado);
                                break;
                                case 3:
                                    printf ("Multiplicar\n");

                                    printf("Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x * y;
                                    printf("El resultado es %f\n", resultado);
                                break;
                                case 4:
                                    printf ("Dividir\n");

                                    printf("Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x / y;
                                    printf("El resultado es %f\n", resultado);
                                break;
                                case 5:
                                    printf ("Potencia\n");

                                    printf("Ingrese base: ");
                                    scanf("%f", &x);
                                    printf("Ingrese exponente: ");
                                    scanf("%f", &y);

                                    resultado = potencia(x, (int) y);
                                    printf("El resultado es %f\n", resultado);

                                break;
                                case 6:
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
    while (p!=1);

return 0;

}


//Función de potencia para la calculadora

float potencia(float base, int exponente)
{
    float resultado = 1;
    int i;
    for (i = 0; i < exponente; ++i) {
        resultado *= base;
    }
    return resultado;
}

//Funcion para ingresar x e y en la calculadora



