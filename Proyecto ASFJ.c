#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define N 51              //constante para la dimension del mapa del gps

#define AZUL "\x1b[34m"                  //colores de las letras
#define BLANCO "\x1b[37m"
#define CIAN "\x1b[36m"
#define AZUL31 "\x1b[38;5;31m"
#define NEGRO   "\x1b[30m"
#define AZUL24 "\x1b[38;5;24m"

#define  FAZUL "\x1b[44m"

#define NEGRITA "\x1b[1m"               //comandos para el estilo del texto
#define PARPADEO "\x1b[5m"
#define ITALIC "\x1b[3m"
#define SUBRAYADO "\x1b[4m"
#define DIM "\x1b[2m"
#define INVISIBLE "\x1b[8m"
#define INVERSO "\x1b[7m" // intercambia color de las letras y de su fondo (ahorramos comandos para color de fondo)
#define TACHADO "\x1b[9m"

#define RESET   "\x1b[0m"  //resetear comandos de colores y estilos

#define LIMP printf("\033[2J" "\033[H")   // "limpiar la pantalla" + empezar a escribir arriba

typedef struct
{
    int d, m, a;
}fecha;

typedef struct
{
    char tipo[50];
    char recordatorio[50];
    fecha fechaRec;
}evento;


float potencia(float base, int exponente);
int escribir_recordatorio (int n,char modo);
void printEvento(evento x);
int compFecha(fecha f1, fecha f2);


int main(){

    time_t t;
    struct tm *tm;
    char fechayhora[100];
    int n,v;
    char modo;                  // variables para calendario
    int menu,p=0,a=0,b=0;     //variables para controlar la posición en el menú
    int tempo,calen,calc,gp;
    int se=0,mi=0,ho=0;

    //dar la hora y dia en pantalla
    t=time(NULL);
    tm=localtime(&t);
    LIMP;
    strftime(fechayhora, 100, "%H:%M \t\t %d/%m/%Y", tm);
    printf (FAZUL INVISIBLE "\n\t %s \n" RESET,fechayhora);
    printf (FAZUL "\t %s \n",fechayhora);
    printf (INVISIBLE "\t %s \n\n" RESET ,fechayhora);


    do{

        if((a==0)&&(b==1))
            p=1;
        else{

            printf(CIAN INVERSO "%cHola de nuevo, Usuario!" RESET "\n",173);
            printf(CIAN SUBRAYADO "%cEn qu%c te puedo ayudar?\n" RESET CIAN "\n1-.Temporizadores\n2-.Calendario\n3-.GPS\n4-.Calculadora\n5-.Cerrar sesi%cn" RESET "\n",168,130,162);
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

                            LIMP;
                            printf (AZUL31 INVERSO "TEMPORIZADORES:\n" RESET AZUL31 "1-.Cron%cmetro\n2-.Cuenta atr%cs\n3-.Ciclos de tiempo\n4-.Atr%cs" RESET "\n",162,160,160);
                            do {
                            scanf ("%i",&tempo);
                            switch (tempo)
                            {
                                case 1:
                                    printf ("CRONOMETRO\n");
                                 //Función de cronómetro
                                   printf("Pulsa espacio para iniciar y para pausar si es necesario:\n[%.2i:%.2i:%.2i]\n",ho,mi,se);
                                   system("pause ->NULL");
                                   while (1){
                                    while(!kbhit()){ //la función espera a que se presione una tecla en específico
                                     se++; //paso del tiempo
                                     if (se==60){
                                      se=0;
                                      mi++; //pasa de 59 segundos a 1:00
                                       if (mi==60){
                                        mi=0;
                                        ho++;
                                       }
                                      }
                                     system("cls"); //ESTO DEBE CAMBIARSE, SÓLO FUNCIONA EN WINDOWS
                                     printf("[%.2i:%.2i:%.2i]",ho, mi, se);
                                     Sleep(1000); //Un segundo de refresco
                                     }
                                     char pausa=getch();
                                     if(pausa==32){ //pausa si pulsa el espacio
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
                                    LIMP;
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
                            LIMP;
                            printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A%cadir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo\n5-.Atr%cs\n",164,160);
                            do{

                            scanf ("%i",&calen);
                            switch (calen)
                            {

                                case 1:
                                    LIMP;
                                    printf ("Ver recordatorios:\n");

                                    int j,iComp,Nu=0,ev=0;  //Nu será el numero de lineas (recordatorios) del fichero; ev contará el numero de eventos/recordatorios para hoy
                                //    int dia, mes, anio;
                                    char c,opcion; // c para recorrer el fichero por caracteres y contar lineas; opcion para mostrar o no todos los recordatorios en pantalla
                                    FILE *pf;
                                    evento eventos[2];             // Vector que almacena los eventos

                                    eventos[0].fechaRec.d=tm->tm_mday;     //asigo en la primera posicion del vector de eventos la fecha actual
                                    eventos[0].fechaRec.m=1+tm->tm_mon;
                                    eventos[0].fechaRec.a=1900+tm->tm_year;

                                    pf=fopen("Recordatorios_calendario.txt","r");

                                    if(pf==NULL)                          //compruebo que se abre bien
                                    {
                                        printf("Error al abrir el fichero.");
                                        return -1;
                                    }else
                                    {

                                        while (fscanf(pf,"%c",&c)!=EOF)  //cuento numero de lineas (cada linea un recordatorio)
                                            if(c=='\n') Nu++;

                                        printf("Hay %d registrados.\n\n",Nu);

                                        fseek(pf,0,SEEK_SET);            //vuelvo al principio del fichero


                                        for(j=0;j<Nu;j++)                   //leo el fichero
                                        {
                                            fscanf(pf,"%d;%d;%d;%[^;];%s\n",
                                                   &eventos[1].fechaRec.d, &eventos[1].fechaRec.m, &eventos[1].fechaRec.a, &eventos[1].tipo, &eventos[1].recordatorio);


                                            iComp = compFecha(eventos[0].fechaRec,  //comparo fecha actual con la del recordatorio que estoy leyendo
                                            eventos[1].fechaRec);
                                            switch(iComp)
                                            {
                                                case -1:        //coincide la fecha
                                                    printf("Recordatorio de hoy ");
                                                    printEvento(eventos[1]);
                                                    ev++;       //contador de los recordarorios de hoy
                                                    break;
                                                case 1:         //no coincide la fecha
                                                    break;
                                            }
                                        }
                                        if(ev==0) printf("No hay recordatorios para hoy.\n");


                                        printf("\nPulse 'r' para ver todos los recordatorios o cualquier otra letra para volver atr%cs.\n\n",160);

                                        scanf(" %c",&opcion);
                                        if(opcion=='r'||opcion=='R')
                                        {
                                            fseek(pf,0,SEEK_SET);            //vuelvo al principio del fichero
                                            LIMP;
                                            printf("RECORDATORIOS:\n");
                                            for(j=0;j<Nu;j++)                   //escribo todas las lineas del fichero
                                            {
                                            fscanf(pf,"%d;%d;%d;%[^;];%s\n",
                                                   &eventos[1].fechaRec.d, &eventos[1].fechaRec.m, &eventos[1].fechaRec.a, &eventos[1].tipo, &eventos[1].recordatorio);
                                              printf("%c %.2d/%.2d/%.2d  %s %s\n",
                                                     16, eventos[1].fechaRec.d, eventos[1].fechaRec.m, eventos[1].fechaRec.a, eventos[1].tipo, eventos[1].recordatorio);
                                            }
                                            printf("\n");
                                        }else LIMP;



                                        fclose(pf);
                                    }
                                    printf("Puede continuar usando el ");
                                    printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A%cadir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo\n5-.Atr%cs\n",164,160);

                                break;


                                case 2:
                                    printf ("A%cadir recordatorio\n",164);

                                    printf ("Cuantos recordatorios desea a%cadir?\n",164);
                                    scanf("%d",&n);
                                    modo='a';
                                    v=escribir_recordatorio(n,modo);            // funcion para a�adir recordatorios al fichero existente
  /*A�ADO FICH*/
                                    if(v==-1) break;
                                    else{

                                    LIMP;
                                    printf("Ya se han a%cadido!\nPuede continuar usando el ",164);
                                    printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A%cadir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo.\n5-.Atr%cs\n",164,160);


                                   // return v;    //v ser� -1 o 0 segun lo que devuelva la funcion (-1 cuando no se abre el fichero)


                                    break;
                                    }

                                case 3:
                                    printf ("Editar recordatorio existente\n");
                                break;

                                case 4:
                                    LIMP;
                                    printf ("Eliminar recordatorios existentes y empezar a crear de nuevo:\n");

                                    int i;
  /*CREO FICH*/                         int n, v;
                                        printf ("Cuantos recordatorios desea crear?\n");
                                        scanf("%d",&n);
                                        modo='e';
                                        v=escribir_recordatorio(n,modo);            // funcion para crear fichero de recordatorios

                                        if(v==-1) break;
                                        else{
                                        LIMP;
                                        printf("Ya se han creado!\nPuede continuar usando el ");
                                        printf ("CALENDARIO:\n1-.Ver recordatorios\n2-.A%cadir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo.\n5-.Atr%cs\n",164,160);
                                        break;
                                        }

                                case 5:
                                    a=1;
                                    LIMP;
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



int escribir_recordatorio (int n, char modo)
{
    int i;
    int dia, mes, anio;
    char tip[30], rec[30];
    FILE *pf;

    if(modo=='e') pf=fopen("Recordatorios_calendario.txt","w"); //creo fichero en modo escritura
    else pf=fopen("Recordatorios_calendario.txt","a");          //abro fichero en modo a�adir

    if(pf==NULL)                             //compruebo que se abre bien
    {
        printf("Error al abrir el fichero.");
        return -1;
    }else
    {
        printf("Escriba en el fichero, separadas por un espacio y los tres primeros datos en forma num%crica: d%ca mes a%co tipo_de_evento recordatorio\n",130,161,164);
        for(i=0;i<n;i++)                                                  // FUNCION PARA ESCRIBIR EN EL FICHEROOO
        {
            scanf("%d %d %d %s %s",                       //asigno valores a los vectores
                &dia,&mes,&anio,&tip,&rec);

            fprintf(pf,"%d;%d;%d;%s;%s\n",                 //escribo en el fichero
                    dia,mes,anio,tip,rec);

        }
    fclose(pf);                           //cierro fichero
    return 0;
    }

}

void printEvento(evento x)
{
  printf("(%i/%i/%i):\t",
	 x.fechaRec.d,
	 x.fechaRec.m,
	 x.fechaRec.a);
	 printf("%s %s\n",
	 x.tipo,
	 x.recordatorio);
}

int compFecha(fecha f1, fecha f2)
{
  if (f1.a == f2.a && f1.m==f2.m && f1.d==f2.d)
        return -1;
  else
        return 1;
}
