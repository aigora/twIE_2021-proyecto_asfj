#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define N 51

float potencia(float base, int exponente);
int aniado_recordatorio (int n);
int escribir_recordatorio (int n);

int main(){

    time_t t;
    struct tm *tm;
    char fechayhora[100];
    int d,m,y;
    int menu,p=0,a=0,b=0; //variables para controlar la posición en el menú
    int tempo,calen,calc,gp;
    int n, v;  // variables para calendario
    int se=0,mi=0,ho=0;


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

                                   printf("Pulsa espacio para iniciar y para pausar si es necesario:\n[%.2i:%.2i:%.2i]\n",ho,mi,se);
                                   system("pause ->NULL");
                                   while (1){
                                    while(!kbhit()){
                                     se++;
                                     if (se==60){
                                      se=0;
                                      mi++;
                                       if (mi==60){
                                        mi=0;
                                        ho++;
                                       }
                                      }
                                     system("cls");
                                     printf("[%.2i:%.2i:%.2i]",ho, mi, se);
                                     Sleep(1000);
                                     }
                                     char pausa=getch();
                                     if(pausa==32){
                                     getch();
                                    }
                                   }
                                 system("pause");

                                break;
                                case 2:
                                    printf ("Cuenta atr%cs\n",160);
                                        int i = 0;
                                        int total;

                                        printf("Dime los segundos, minutos y horas que desee\n");//Hay que escribir los segundos, minutos y horas seguidos separados por un espacio
                                        scanf("%i %i %i",&se,&mi,&ho);
                                        total=se + 60*mi + 3600*ho;
                                        printf("El programa terminara %i en segundos.\n", total);




                                        for(i=0; i<total; i++){
                                            Sleep(1000);
                                            //printf("%i\n", i+1);

                                            system("cls");
                                                printf("\n\n\n\t\t\t[ %.2d:%.2d:%.2d ]", ho, mi, se);


                                            se=se-1;
                                            if(se==0&&mi>0) {
                                                    mi=mi-1;
                                                    se=59;
                                            }
                                            if (mi==0&&ho>0) {
                                                    ho=ho-1;
                                                    mi=59;
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
                            printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A�adir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo.\n5-.Atr%cs\n",160);
                            do{
                            scanf ("%i",&calen);
                            switch (calen)
                            {
                                case 1:

                                break;

                                case 2:
                                    printf ("A�adir recordatorio\n");

                                    printf ("Cuantos recordatorios desea a�adir?\n");
                                    scanf("%d",&n);
                                    v=aniadir_recordatorio(n);            // funcion para a�adir recordatorios al fichero existente
  /*A�ADO FICH*/
                                    if(v==-1) break;
                                    else{

                                    system("cls");
                                    printf("Ya se han a�adido!\nPuede continuar usando el ");
                                    printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A�adir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo.\n5-.Atr%cs\n",160);


                                   // return v;    //v ser� -1 o 0 segun lo que devuelva la funcion (-1 cuando no se abre el fichero)


                                    break;
                                    }

                                case 3:

                                    printf ("Editar recordatorio existente:\n");
                                break;

                                case 4:
                                    system("cls");
                                    printf ("Eliminar recordatorios existentes y empezar a crear de nuevo:\n");

                                    int i,N;
                                    char *recordatorio,c;
  /*CREO FICH*/                         int n, v;
                                        printf ("Cuantos recordatorios desea crear?\n");
                                        scanf("%d",&n);
                                        v=escribir_recordatorio(n);

                                        if(v==-1) break;
                                        else{
                                        system("cls");
                                        printf("Ya se han creado!\nPuede continuar usando el ");
                                        printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A�adir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo.\n5-.Atr%cs\n",160);
                                        break;
                                        }

                                case 5:
                                    a=1;
                                    system("cls");
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;
                            }
                            }
                            while(calen!=5);
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



int aniadir_recordatorio (int n)              // NO FUNCIONA BIEN
{
    int i;
    int dia, mes, anio;
    char rec[30];
    FILE *pf;
    pf=fopen("Recordatorios_calendario","a"); //abro fichero en modo a�adir

    if(pf==NULL)                             //compruebo que se abre bien
    {
        printf("Error al abrir el fichero.");
        return -1;
    }else
    {
        printf("Escriba en el fichero, separadas por un espacio y los tres primeros datos en forma num�rica: dia mes a�o recordatorio\n");
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %s",                       //asigno valores a los vectores
                &dia,&mes,&anio,&rec);

            fprintf(pf,"%d;%d;%d;%s\n",                 //escribo en el fichero
                    dia,mes,anio,rec);
        }

        fclose(pf);                           //cierro fichero
        return 0;

        }

    }


int escribir_recordatorio (int n)
{
    int i;
    int dia, mes, anio;
    char rec[30];
    FILE *pf;
    pf=fopen("Recordatorios_calendario","w"); //creo fichero en modo escritura

    if(pf==NULL)                             //compruebo que se abre bien
    {
        printf("Error al abrir el fichero.");
        return -1;
    }else
    {
        printf("Escriba en el fichero, separadas por un espacio y los tres primeros datos en forma num�rica: dia mes a�o recordatorio\n");
        for(i=0;i<n;i++)                                                  // FUNCION PARA ESCRIBIR EN EL FICHEROOO
        {
            scanf("%d %d %d %s",                       //asigno valores a los vectores
                &dia,&mes,&anio,&rec);

            fprintf(pf,"%d;%d;%d;%s\n",                 //escribo en el fichero
                    dia,mes,anio,rec);

        }
    fclose(pf);                           //cierro fichero
    return 0;
    }

}


