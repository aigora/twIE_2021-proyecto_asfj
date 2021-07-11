#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
//#include <windows.h>
//#include <conio.h>

#define N 51              //constante para la dimension del mapa del gps

#define INICIO "\x1b[30A"


#define AZUL "\x1b[34m"                  //colores de las letras
#define BLANCO "\x1b[37m"
#define CIAN "\x1b[36m"
#define AZUL31 "\x1b[38;5;31m"
#define NEGRO   "\x1b[30m"
#define ROJO "\x1b[38;5;160m"
#define AZUL24 "\x1b[38;5;24m"
#define AZUL69 "\x1b[38;5;69m"
#define AZUL20 "\x1b[38;5;26m"
#define AZUL45 "\x1b[38;5;45m"

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

#define FIN 'F' // constantes para detectar si el usuario desea salir del programa
#define ERRORES 'E' //constante para saber si el usuario escribió datos mal varias veces seguidas

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

//FUNCIONES VARIAS
void menus (int menu);
void delay(float numero_segundos);
int random();
//FUNCION CALCULADORA
float potencia(float base, int exponente);
//FUNCIONES CALENDARIO
int imprimir_fichero(int numeracion);
void copio_fichero();
void editar_fichero(int nu, int ed, char edit);
char coincide (char a[]);
void imprimir_tipo_rec (char c, int nu);
int escribir_recordatorio (char modo);
void printEvento(evento x);
int compFecha(fecha f1, fecha f2);
void print_fyh();
//FUNCIONES TEMPORIZADORES
void cuenta_atras (int se, int mi, int ho, int aa);
void modo_cuenta_atras (int aa);
//COMPROBACIÓN DE DATOS
int cuenta_caracteres (char mmm[]);
float numero (int minimo, int maximo);  // PIDE AL USUARIO UN NUMERO ACOTADO, LO COMPRUEBA Y LO DEVUELVE
int salir(char fin[N]);
// ANIMACIONES
void animacion_reloj_inteligente();
void animacion_temporizadores();
void animacion_calendario();
void animacion_GPS();
void animacion_calculadora();
void animacion_hasta_luego();

int main(){



    int n,v,metodo;
    char modo;                  // variables para calendario
    int menu,p=0,a=0,b=0;     //variables para controlar la posición en el menú
    int tempo,calen,calc,gp,srt;
    int se=0,mi=0,ho=0;

    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%H:%M \t\t %d/%m/%Y", tm);


//    animacion_reloj_inteligente ();

    do{

        if((a==0)&&(b==1))
            p=1;
        else{


            print_fyh();
            printf(CIAN INVERSO "%cHola de nuevo, Usuario!" RESET "\n",173);
            printf(CIAN SUBRAYADO "%cEn qu%c te puedo ayudar?\n" RESET AZUL24 "1-.Temporizadores\n" RESET AZUL31 "2-.Calendario\n" RESET AZUL69 "3-.GPS\n" RESET AZUL20"4-.Calculadora\n"RESET AZUL20"5-.Suerte\n"RESET BLANCO"6-.Cerrar sesi%cn\n" RESET "\n",168,130,162);
            a=0;
            b=0;


            do {
                if(a==1)
                    menu=6;
                else{

                    scanf("%i",&menu);
                    switch (menu)
                    {
                        case 1: //TEMPORIZADORES

                            LIMP;
//                            animacion_temporizadores();
                            menus (menu);
                            do {
                            printf(RESET);
                            scanf ("%i",&tempo);
                            switch (tempo)
                            {
                                case 1: //CRONOMETRO
                                    LIMP;

                                    printf (AZUL24 INVERSO"Cron%cmetro\n"RESET,162);
                                    printf(AZUL24 "Pulse una vez el espacio para iniciar, otra vez para pausar si es necesario y dos veces para continuar us%cndolo.\nPulse t dos veces para terminar de usar el cron%cmetro:\n[%.2i:%.2i:%.2i]\n",160,162,ho,mi,se);

                                   while (getch()!='t'){
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
                                           LIMP;
                                           printf (AZUL24 INVERSO"Cron%cmetro\n"RESET,162);
                                           printf(AZUL24 "Pulse una vez el espacio para pausar si es necesario y dos veces para continuar us%cndolo.\nPulse t dos veces para terminar de usar el cron%cmetro:\n[%.2i:%.2i:%.2i]\n",160,162,ho,mi,se);

                                           //printf(AZUL24"[%.2i:%.2i:%.2i]"RESET,ho, mi, se);
                                           delay(1); //Un segundo de refresco
                                       }
                                       char pausa=getch();
                                       if(pausa==32){ //pausa si pulsa el espacio
                                           getch();
                                       }
                                   }

                                LIMP;
                                printf(SUBRAYADO ITALIC "\n\nPuede continuar usando los "RESET);
                                menus (menu);

                                break;

                                case 2: //CUENTA ATRAS
                                        LIMP;

                                        int i = 0,aa=2;
                                        int total;

                                        printf (AZUL24 INVERSO "Cuenta atr%cs\n" RESET,160);
                                        printf(AZUL24 "Dime los segundos, minutos y horas que desee\n");//Hay que escribir los segundos, minutos y horas seguidos separados por un espacio
                                        scanf("%i %i %i",&se,&mi,&ho);
                                        total=se + 60*mi + 3600*ho;

                                        if(se<0||mi<0||ho<0) {LIMP;
                                            printf("No debe incluir tiempo negativo.");
                                        }else{

                                        printf("El programa terminara %i en segundos.\n", total);

                                        cuenta_atras(se, mi, ho, aa);  //saca por pantalla la cuenta atras hasta llegar al 00:00:00

                                        }

                                printf(AZUL24"\n\nFinaliz%c la cuenta atr%cs!",162,160);
                                printf(AZUL24 SUBRAYADO ITALIC "\n\nPuede continuar usando los " RESET);
                                menus (menu);


                                break;
                                case 3://CICLOS DE TIEMPO
                                    printf("Seleccione el m%ctodo que desee utilizar:\n1-.M%ctodo Pomodoro\n2-.M%ctodo T%cbata\n",130,130,130,160);
                                    scanf("%i",&metodo);
                                    if (metodo==1){
                                        LIMP;
                                        printf (AZUL24 INVERSO "M%ctodo pomodoro\n" RESET,130 );

                                        int ciclos;
                                        printf(AZUL24"%cCu%cntos ciclos de estudio desea hacer?\n"RESET ,168,160);
                                        scanf("% i",&ciclos);

                                        printf(AZUL24"Va a empezar el M%ctodo Pomodoro\n", 130);
                                        printf("Comienzan los %i ciclos de estudio\n" RESET, ciclos);

                                        delay(2);
                                        for(i=0;i<ciclos;i++)
                                        {
                                            mi=25;
                                            se=0;
                                            ho=0;
                                            aa=3;

                                            cuenta_atras(se, mi, ho, aa);

                                            printf("Va a empezar el tiempo de descanso\n");
                                            mi=5;
                                            se=0;
                                            ho=0;
                                            aa=4;

                                            cuenta_atras(se, mi, ho, aa);
                                        }



                                        printf(AZUL24 SUBRAYADO ITALIC "\n\nPuede continuar usando los ");
                                        menus (menu);
                                    }
                                    else if(metodo==2){
                                        LIMP;
                                        printf (AZUL24 INVERSO "M%ctodo T%cbata\n" RESET,130,160 );

                                        int series;
                                        series=8;

                                        printf(AZUL24"Va a empezar el tiempo de ejercicio\n");
                                        printf("Son %i series de ejrcicio\n" RESET,series);

                                        delay(2);
                                        for(i=0;i<series;i++)
                                        {
                                            mi=0;
                                            se=25;
                                            ho=0;
                                            aa=5;

                                            cuenta_atras(se, mi, ho, aa);

                                            printf("Va a empezar el tiempo de descanso\n");
                                            mi=0;
                                            se=5;
                                            ho=0;
                                            aa=6;

                                            cuenta_atras(se, mi, ho, aa);
                                        }
                                    }
                                    else //Presiona cualquier otro numero
                                        printf("Introduzca un n%cmero v%clido\n",163,160);
                                    printf(AZUL24 SUBRAYADO ITALIC "\n\nPuede continuar usando los ");
                                    menus (menu);

                                case 4: //atras
                                    a=1;
                                    LIMP;
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;

                            }
                            }
                            while (tempo!=4);
                            //menu=6;

                        break;


                        case 2: // CALENDARIO
                            LIMP;
//                            animacion_calendario();
                            menus (menu);
                            do{

                            scanf ("%i",&calen);
                            switch (calen)
                            {

                                case 1:
                                    LIMP;
                                    printf (AZUL31 INVERSO"Ver recordatorios\n"RESET);

                                    int j,iComp,Nu=0,ev=0;  // Nu será el numero de lineas (recordatorios) del fichero; ev contará el numero de eventos/recordatorios para hoy
                                    int noNumerado=0;
                                    char coinc,c,opcion, re[15]; //coinc para comprobar si coincide el tipo de record que busco o no; c para recorrer el fichero por caracteres y contar lineas; opcion para mostrar o no todos los recordatorios en pantalla; compA y compB para comparar el tipo de rec que busco y los que existen
                                    FILE *pf;
                                    evento eventos[3];             // Vector que almacena los eventos

                                    eventos[0].fechaRec.d=tm->tm_mday;     //asigo en la primera posicion del vector de eventos la fecha actual
                                    eventos[0].fechaRec.m=1+tm->tm_mon;
                                    eventos[0].fechaRec.a=1900+tm->tm_year;

                                    pf=fopen("Recordatorios_calendario.txt","r");

                                    if(pf==NULL)                          //compruebo que se abre bien
                                        {
                                        printf(AZUL31 "Error al abrir el fichero."RESET);
                                        return -1;
                                    }else
                                    {

                                        while (fscanf(pf,"%c",&c)!=EOF)  //cuento numero de lineas (cada linea un recordatorio)
                                            if(c=='\n') Nu++;

                                        printf(AZUL31 "\nHay %d registrados.\n\n",Nu);

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
                                                    printf(AZUL31"Recordatorio de hoy "RESET);
                                                    printEvento(eventos[1]);
                                                    ev++;       //contador de los recordarorios de hoy
                                                    break;
                                                case 1:         //no coincide la fecha
                                                    break;
                                            }
                                        }
                                        if(ev==0) printf(AZUL31"No hay recordatorios para hoy.\n"RESET);

                                        fclose(pf);


                                        printf(AZUL31 "\nPulse:\n'c' para ver las fechas en las que hay cumplea%cos\n'e' para ver las fechas de examenes\n'f' para ver los festivos\n'r' para ver todos los recordatorios\nCualquier otra letra para volver atr%cs.\n\n"RESET,164,160);
                                        scanf(" %c",&opcion);

                                        if(opcion=='r'||opcion=='R')
                                        {
                                            imprimir_fichero(noNumerado);
                                        }
                                        else imprimir_tipo_rec (opcion, Nu);

                                    }


                                    //LIMP;
                                    printf(SUBRAYADO ITALIC AZUL31"Puede continuar usando el "RESET);
                                    menus (menu);

                                break;


                                case 2:
                                    LIMP;
                                    printf (AZUL31 INVERSO"A%cadir recordatorio\n"RESET,164);

                                    modo='a';
                                    v=escribir_recordatorio(modo);            // funcion para a�adir recordatorios al fichero existente
  //A�ADO FICH/
                                    if(v==-1) break;
                                    else{

                                    LIMP;
                                    printf("Ya se han a%cadido!\n" SUBRAYADO ITALIC "Puede continuar usando el " RESET,164);
                                    menus (menu);

                                   // return v;    //v ser� -1 o 0 segun lo que devuelva la funcion (-1 cuando no se abre el fichero)


                                    break;
                                    }

                                case 3:
                                    LIMP;
                                    printf (INVERSO AZUL31 "Editar recordatorio existente\n"RESET);

                                    char editar;  //variable para saber si editar la fecha o el recordatorio
                                    int numerado=1,ed,nu;  //ed es el numero de linea que se editara; nu es el numero de lineas totales del fichero

                                    nu=imprimir_fichero(numerado);  //imprime todos los recordatorios numerados y devuelve el numero de lineas/recordatorios

                                    while(1){
                                        printf(AZUL31"%cQue n%cmero de recordatorio desea editar?\n"RESET,168,163);
                                        scanf("%d",&ed);
                                        if(ed>nu) printf(AZUL31"Ese n%cmero de recordatorio no existe.\n"RESET,163);
                                        else break;
                                    }

                                    while(1){
                                        printf(AZUL31"Pulse f si desea cambiar la fecha o r si desea cambiar el nombre del recordatorio.\n"RESET);
                                        scanf(" %c",&editar);
                                        if(editar!='r'&&editar!='f') printf(AZUL31"Esa letra no es v%clida.\n"RESET,160);
                                        else break;
                                    }

                                    copio_fichero();  //copio los recordatorios en un fichero temporal

                                    editar_fichero(nu, ed, editar);  //vuelvo a copiar en mi fichero de recordatorios pero haciendo las modificaciones

                                    LIMP;
                                    printf(AZUL31"Ya se ha editado!\n" SUBRAYADO ITALIC "Puede continuar usando el "RESET);
                                    menus (menu);


                                break;

                                case 4:
                                    LIMP;
                                    printf (AZUL31 INVERSO"Eliminar recordatorios existentes y empezar a crear de nuevo\n"RESET);

                                    int i;
  //CREO FICH/
                                        modo='e';

                                        if(escribir_recordatorio(modo)==-1) break;
                                        else{
                                        LIMP;
                                        printf(AZUL31"Ya se han creado!\n" SUBRAYADO ITALIC "Puede continuar usando el " RESET);
                                        menus (menu);
                                        break;
                                        }

                                case 5:
                                    a=1;
                                    LIMP;
                                break;
                                default:
                                     printf( AZUL31 "Introduzca un n%cmero v%clido\n"RESET,163,160);
                                break;
                            }
                            }
                            while(calen!=5);
                        break;


                        case 3: // GPS
                            LIMP;
//                            animacion_GPS();
                            menus (menu);
                            int punto;
                            int x1;
                            int y1;
                            int i=0,j=0, x=25,y=25;     //Define la posición del usuario en el centro del mapa.
                            int c1 = random() ;
                            int c2 = random() ;
                            int u1 = random() ;     //Define las posiciones aleatorias de la universidad, la casa y los pacientes de covid.
                            int u2 = random() ;
                            int px = random() ;
                            int py = random() ;
                            int p1x = random() ;
                            int p1y = random() ;
                            int p2x = random() ;
                            int p2y = random() ;
                            int p3x = random() ;
                            int p3y = random() ;
                            while(c1==u1||c2==u2){      //Comprueba que la universidad y la casa no están en el mismo sitio.
                            int c1 = random() ;
                            int c2 = random() ;
                            }
                            do {
                            scanf ("%i",&gp);
                            switch (gp)
                            {
                                case 1:
                                    LIMP;
                                    printf (AZUL69 INVERSO "Radar covid\n"RESET);

                                        srand(time(NULL));
                                        for(i=0;i<N;i++){
                                            printf("\n");        //Representa gráficamente.
                                                for(j=0;j<N;j++)
                                                    if(j==x&&i==y)
                                                        printf(NEGRITA AZUL69 "X " RESET);
                                                    else if (i==px&&j==py)
                                                        printf(ROJO INVERSO"P "RESET);
                                                    else if (i==p1x&&j==p1y)
                                                        printf(ROJO INVERSO"P "RESET);
                                                    else if (i==p2x&&j==p2y)
                                                        printf(ROJO INVERSO"P "RESET);
                                                    else if (i==p3x&&j==p3y)
                                                        printf(ROJO INVERSO"P "RESET);
                                                    else
                                                        printf(". ");
                                            }
                                             printf("\n");
                                             if((22<px&&22<py)||(22<p1x&&22<p1y)||(22<p2x&&22<p2y)||(22<p3x&&22<p3y)) //Avisa al usuario de peligro en caso de encontrarse cerca de un paciente.
                                             {
                                               if((px<27&&py<27)||(p1x<27&&p1y<27)||(p2x<27&&p2y<27)||(p3x<27&&p3y<27)) //Avisa al usuario de peligro en caso de encontrarse cerca de un paciente.
                                             {
                                                printf(AZUL69"Tiene un paciente de covid peligrosamente cerca, al%cjese de ahí.\n",130);
                                             }
                                             else{printf(AZUL69"Est%c en zona segura\n",160);}
                                             }

                                             printf(SUBRAYADO ITALIC "\n\nPuede continuar usando el "RESET );
                                             menus (menu);
                                break;
                                case 2:

                                    LIMP;
                                    printf (AZUL69 INVERSO "Direcci%cn\n"RESET,162);
                                    printf(AZUL69 "1 para casa, 2 para universidad, 3 para punto concreto, 4 para ir atr%cs\n"RESET,160);
                                    scanf("%i",&punto);
                                    switch (punto)
                                    {
                                    case 1:
                                        printf(AZUL69);
                                        if(c1<x && c2<y)
                                            printf("Arriba izquierda");
                                        else if(c1>x && c2>y)
                                            printf("Abajo derecha");
                                        else if(c1>x && c2<y)
                                            printf("Arriba derecha");
                                        else if(c1<x && c2>y)
                                            printf("Abajo izquierda");
                                        else if(c1<x && c2==y)
                                            printf("Izquierda");
                                        else if(c1==x && c2>y)
                                            printf("Abajo");
                                        else if(c1==x && c2<y)
                                            printf("Arriba");
                                        else if(c1>x && c2==y)
                                            printf("Derecha");
                                        else
                                            printf(".");
                                        printf(SUBRAYADO ITALIC "\n\nPuede continuar usando el "RESET);
                                        menus (menu);
                                    break;

                                    case 2:
                                        printf(AZUL69);
                                        if(u1<x && u2<y)
                                            printf("Arriba izquierda");
                                        else if(u1>x && u2>y)
                                            printf("Abajo derecha");
                                        else if(u1>x && u2<y)
                                            printf("Arriba derecha");
                                        else if(u1<x && u2>y)
                                            printf("Abajo izquierda");
                                        else if(u1<x && y1==y)
                                            printf("Izquierda");
                                        else if(u1==x && y1>y)
                                            printf("Abajo");
                                        else if(x1==x && y1<y)
                                            printf("Arriba");
                                        else if(u1>x && y1==y)
                                            printf("Derecha");
                                        else
                                            printf(".");
                                        printf(SUBRAYADO ITALIC "\n\nPuede continuar usando el ");
                                        menus (menu);
                                    break;

                                    case 3:
                                        printf (AZUL69"Escriba las coordenadas x e y de punto que quiera.\n");
                                        printf("x:\n"RESET);
                                        scanf("%i",&x1);
                                        printf(AZUL69"\ny:\n"RESET);
                                        scanf("%i",&y1);
                                        printf("\n");

                                        printf(AZUL69);
                                        if(x1<x && y1<y)
                                            printf("Arriba izquierda");
                                        else if(x1>x && y1>y)
                                            printf("Abajo derecha");
                                        else if(x1>x && y1<y)
                                            printf("Arriba derecha");
                                        else if(x1<x && y1>y)
                                            printf("Abajo izquierda");
                                        else if(x1<x && y1==y)
                                            printf("Izquierda");
                                        else if(x1==x && y1>y)
                                            printf("Abajo");
                                        else if(x1==x && y1<y)
                                            printf("Arriba");
                                        else if(x1>x && y1==y)
                                            printf("Derecha");
                                        else
                                            printf(".");
                                        printf(SUBRAYADO ITALIC "\n\nPuede continuar usando el "RESET);
                                        menus (menu);
                                    break;

                                    case 4:
                                        printf(SUBRAYADO ITALIC "\n\nPuede continuar usando el "RESET);
                                        menus (menu);
                                    break;

                                    default:
                                        printf("Introduzca un n%cmero v%clido\n",163,160);
                                        break;
                                    printf(SUBRAYADO ITALIC "\n\nPuede continuar usando el "RESET);
                                    menus (menu);
                                    }
                                break;
                                case 3:
                                    printf (AZUL69 INVERSO "Localizaci%cn\n"RESET,162);


                                        srand(time(NULL));
                                        for(i=0;i<N;i++){
                                            printf("\n");        //Representa gráficamente.
                                                for(j=0;j<N;j++)
                                                    if(j==x&&i==y)
                                                        printf(NEGRITA"X "RESET);
                                                    else if (i==c1&&j==c2)
                                                        printf(AZUL69 NEGRITA"C "RESET);
                                                    else if (i==u1&&j==u2)
                                                        printf(AZUL69 NEGRITA"U "RESET);
                                                    else
                                                        printf(". ");
                                            }

                                        printf(AZUL69 "\nCoordenadas x: %i y: %i.\nCoordenadas Casa: %i y: %i.\nCoordenadas Universidad: %i y: %i." RESET,x-25,y-25,-(c1-25),c2-25,-(u1-25),u2-25); //Imprime coordenadas

                                        if(x==c1&&y==c2)
                                            printf(AZUL69"\nHa llegado a casa.");                     //Comprueba si el usuario está en una de las coordenadas.
                                        else if(x==u1&&y==u2)
                                            printf(AZUL69"\nHa llegado a su universidad.");


                                    printf(AZUL69 SUBRAYADO ITALIC "\n\nPuede continuar usando el "RESET);
                                    menus (menu);
                                break;

                                case 4:
                                    a=1;
                                    LIMP;
                                break;
                                default:
                                     printf(AZUL69"Introduzca un n%cmero v%clido\n"RESET,163,160);
                                break;

                            }
                            }
                            while (gp!=4);
                        break;


                        case 4: // CALCULADORA
                            LIMP;
//                            animacion_calculadora();
                            menus (menu);
                            do{

                            scanf (" %i",&calc);

                            float x, y, resultado;
                            int valido = 1;

                            switch (calc)
                            {
                                case 1: // SUMA
                                    LIMP;
                                    printf (AZUL20 INVERSO"Sumar\n"RESET);

                                    printf( AZUL20"Ingrese x: " );
                                    scanf("%f", &x);
                                    printf("Ingrese y: " );
                                    scanf("%f", &y);

                                    resultado = x + y;
                                    printf("El resultado es %f\n"  , resultado);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);

                                break;
                                case 2: // RESTA
                                    LIMP;
                                    printf (AZUL20 INVERSO"Restar\n"RESET);

                                    printf(AZUL20"Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x - y;
                                    printf("El resultado es %f\n", resultado);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);

                                break;
                                case 3: // MULTIPLICACION
                                    LIMP;
                                    printf (AZUL20 INVERSO"Multiplicar\n"RESET);

                                    printf(AZUL20"Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x * y;
                                    printf("El resultado es %f\n", resultado);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);

                                break;
                                case 4: //DIVISION
                                    LIMP;
                                    printf (AZUL20 INVERSO"Dividir\n"RESET);

                                    printf(AZUL20"Ingrese x: ");
                                    scanf("%f", &x);
                                    printf("Ingrese y: ");
                                    scanf("%f", &y);

                                    resultado = x / y;
                                    printf("El resultado es %f\n", resultado);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);

                                break;
                                case 5: // POTENCIA
                                    LIMP;
                                    printf (AZUL20 INVERSO"Potencia\n"RESET);

                                    printf(AZUL20"Ingrese base: ");
                                    scanf("%f", &x);
                                    printf("Ingrese exponente: " );
                                    scanf("%f", &y);

                                    resultado = potencia(x, (int) y);
                                    printf("El resultado es %f\n" , resultado);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);

                                break;
                                case 6: // MEDIA ARITMETICA
                                    LIMP;
                                    printf (AZUL20 INVERSO"Media aritm%ctica\n"RESET,130);
                                    int s,t; //s=i n=t
                                    float suma, aux;
                                    printf("Ingrese el n%cmero total de datos: ",163);
                                    scanf ("%d",&t);
                                    for(s=0;s<t;s++){
                                        printf("Ingrese el dato %d : ",(s+1));
                                        scanf("%f",&aux);
                                        suma+=aux;
                                    }
                                    printf("La media aritm%ctica es: %g \n",130, suma/t);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);
                                break;

                                case 7: // MEDIA PONDERADA
                                    LIMP;
                                    printf (AZUL20 INVERSO"Media ponderada\n"RESET);
                                    int w,v; // w=i v=n
                                    float sum, u, peso, producto;
                                    printf("Ingrese el numero total de datos: ");
                                    scanf ("%d",&v);
                                    for(w=0;w<b;w++){
                                        printf("Ingrese el dato %d : ",(w+1));
                                        scanf("%f",&u);
                                        printf("Ingrese el peso %d ; ", (w+1));
                                        scanf ("%f",&peso);
                                        sum+=peso;
                                        producto+=u*peso;

                                    }

                                    printf("La media ponderada es: %g \n", producto/sum);

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);
                                break;
                                case 8: // ECUACION DE SEGUNDO GRADO
                                    LIMP;
                                    printf (AZUL20 INVERSO"Ecuaci%cn de segundo grado\n"RESET,162);
                                     float m, n, o, DET;

                                        printf ("La ecuaci%cn es de la forma ax^2 + bx + c = 0\n",162);
                                        printf ("Intoduce el valor de a:");
                                        scanf ("%f",&m);
                                        printf ("Intoduce el valor de b:");
                                        scanf ("%f",&n);
                                        printf ("Intoduce el valor de c:");
                                        scanf ("%f",&o);

                                        DET=(n*n)-(4*m*o);

                                        if (DET==0)
                                            printf("La soluci%cn de la ecuacion es: %.2f\n",162, -n/(2*m));
                                        else if (DET>0){
                                            printf("Una soluci%cn es: %.2f\n",162, (-n+sqrt(DET))/(2*m));
                                            printf("Otra soluci%cn es: %.2f\n",162, (-n-sqrt(DET))/(2*m));
                                        }
                                        else { // Si D<0
                                             printf("Una soluci%cn es: %.2f+%.2f i\n",162, -n/(2*m),(sqrt(-DET))/(2*m));
                                             printf("Otra soluci%cn es: %.2f-%.2f i\n",162, -n/(2*m),(sqrt(-DET))/(2*m));
                                        }

                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);
                                break;
                                case 9: // SISTEMA DE ECUACIONES DE DOS INCOGNITAS
                                    LIMP;
                                    printf (AZUL20 INVERSO"Sistema de ecuaciones de dos inc%cgnitas\n"RESET,162);
                                    float A, B, C, D, E, F, Det, X, Y;

                                    printf("El sistema de ecuaciones es de la forma: \n");
                                    printf("ax + by = c \n");
                                    printf("dx + ey = f \n");

                                    printf("Ingrese el valor de a: ");
                                    scanf("%f",&A);
                                    printf("Ingrese el valor de b: ");
                                    scanf("%f",&B);
                                    printf("Ingrese el valor de c: ");
                                    scanf("%f",&C);
                                    printf("Ingrese el valor de d: ");
                                    scanf("%f",&D);
                                    printf("Ingrese el valor de e: ");
                                    scanf("%f",&E);
                                    printf("Ingrese el valor de f: ");
                                    scanf("%f",&F);

                                    printf("Su sistema de ecuaciones queda as%c: \n",161);
                                    printf("%.2f x + %.2f y = %.2f \n",A,B,C);
                                    printf("%.2f x + %.2f y = %.2f \n",D,E,F);
                                    printf("En forma de matriz ampliada queda as%c: \n",161);
                                    printf("%.2f  %.2f | %.2f \n",A,B,C);
                                    printf("%.2f  %.2f | %.2f \n",D,E,F);

                                    Det= A*E - B*D;

                                    if(Det!=0){
                                        X= (C*E - B*F) / Det;
                                        Y= (A*F - C*D) / Det;
                                        printf("La soluci%cn del sistema de ecuaciones es: \n",162);
                                        printf("x= %.2f  y= %.2f", X,Y);
                                        }
                                        else { // det=0
                                            printf ("Se trata de un sistema de ecuaciones indeterminado \n");
                                        }


                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);
                                break;
                                case 10: // SISTEMA DE ECUACIONES DE TRES INCOGNITAS
                                    LIMP;
                                    float a_, b, c, d, e, f, g, h, i, j, k, l, det, x, y, z;

                                    printf("El sistema de ecuaciones es de la forma: \n");
                                    printf("ax + by + cz = d \n");
                                    printf("ex + fy + gz = h \n");
                                    printf("ix + jy + kz = l \n");

                                    printf("Ingrese el valor de a: ");
                                    scanf("%f",&a_);
                                    printf("Ingrese el valor de b: ");
                                    scanf("%f",&b);
                                    printf("Ingrese el valor de c: ");
                                    scanf("%f",&c);
                                    printf("Ingrese el valor de d: ");
                                    scanf("%f",&d);
                                    printf("Ingrese el valor de e: ");
                                    scanf("%f",&e);
                                    printf("Ingrese el valor de f: ");
                                    scanf("%f",&f);
                                    printf("Ingrese el valor de g: ");
                                    scanf("%f",&g);
                                    printf("Ingrese el valor de h: ");
                                    scanf("%f",&h);
                                    printf("Ingrese el valor de i: ");
                                    scanf("%f",&i);
                                    printf("Ingrese el valor de j: ");
                                    scanf("%f",&j);
                                    printf("Ingrese el valor de k: ");
                                    scanf("%f",&k);
                                    printf("Ingrese el valor de l: ");
                                    scanf("%f",&l);

                                    printf("Su sistema de ecuaciones queda asi: \n");
                                    printf("%.2f x + %.2f y + %.2f z = %.2f \n",a_,b,c,d);
                                    printf("%.2f x + %.2f y + %.2f z = %.2f \n",e,f,g,h);
                                    printf("%.2f x + %.2f y + %.2f z = %.2f \n",i,j,k,l);

                                    printf("En forma de matriz ampliada queda asi: \n");
                                    printf("%.2f %.2f %.2f |%.2f \n",a_,b,c,d);
                                    printf("%.2f %.2f %.2f |%.2f \n",e,f,g,h);
                                    printf("%.2f %.2f %.2f |%.2f \n",i,j,k,l);

                                    det= (a_*f*k + i*b*g + c*j*e)-(c*f*i + a_*j*g + k*b*e);

                                    if(det!=0){
                                        x= ((d*f*k + l*b*g + c*j*h)-(c*f*l + d*j*g + k*b*h)) / det;
                                        y= ((a_*h*k + i*d*g + c*l*e)-(c*h*i + a*l*g + k*d*e)) / det;
                                        z= ((a_*f*l + i*b*h + d*j*e)-(d*f*i + a_*j*h + l*b*e)) / det;
                                        printf("La solucion del sistema de ecuaciones es: \n");
                                        printf("x= %.2f  y= %.2f  z=%.2f " , x,y,z);
                                        }
                                        else { // det=0
                                            printf ("Se trata de un sistema de ecuaciones indeterminado \n");
                                            }
                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);
                                break;
                                case 11: // CALCULAR EL IVA
                                    LIMP;
                                    int iva;
                                    float IVA,precio, PRECIO; //precio=sin IVA PRECIO=con IVA iva=tipo IVA=dinero
                                    FILE *pfIVA;
                                    int nLineas;
                                    char caracterr,duda;
                                    printf (AZUL20 INVERSO"IVA\n"RESET);
                                    printf ("Hay tres tipos de IVA seg%cn el producto:\n",163);
                                    printf ("1-.General:es el que se aplica por defecto a cualquier bien o servicio que se comercialice en Espa%ca\n",164);
                                    printf ("2-.Reducido:afecta mayormente a los alimentos (a excepci%cn de los considerados de primera necesidad), y grava tanto los servicios de hosteler%ca y transporte de viajeros como la venta de inmuebles\n",162,161);
                                    printf ("3-.Superreducido:se aplica los bienes considerados de primera necesidad\n");
                                    printf ("%cLe ha quedado claro a qu%c tipo pertenece su producto?\nPresione *el n%cmero 1* si le ha quedado claro, en caso contrario presione cualquier otra tecla.\n",168,130,163);

                                    scanf (" %c",&duda);
                                    if (duda!= 49){
                                        printf("Se va a abrir una lista a%cadiendo una mejor explicaci%cn de los productos que pertenecen a cada tipo\n",164,162);
                                             pfIVA=fopen("Tipos_de_IVA.txt","r");

                                    if(pfIVA==NULL)                          //compruebo que se abre bien
                                    {
                                        printf(AZUL31 "Error al abrir el fichero."RESET);
                                        return -1;
                                    }else
                                    {

                                        while (fscanf(pfIVA,"%c",&caracterr)!=EOF){  //cuento numero de lineas
                                            if(caracterr=='\n') ++nLineas;
                                        }
                                            //printf("Hay %i lineas.\n",nLineas);

                                        fseek(pfIVA,0,SEEK_SET);            //vuelvo al principio del fichero

                                        for(caracterr=0; caracterr != EOF;){ // IMPRIMIR FICHERO IVA
                                            caracterr = fgetc (pfIVA);
                                            printf ("%c", caracterr);
                                            //delay(0.015);
                                        }
                                    }
                                    }
                                    printf ("%cA qu%c tipo pertenece su producto?\n",168,130);
                                    scanf(" %i", &iva);
                                    if (iva==1) {
                                        printf("A este producto se le aplica un IVA del 21%c\n",37);
                                        printf("%cCu%cnto le ha costado su producto(en euros)?\n",168,160);
                                        scanf(" %f",&PRECIO);
                                        IVA=PRECIO*0.21;
                                        precio= PRECIO - IVA;
                                        printf("El precio sin IVA es de %.2f Euros\n",precio);
                                        printf("El IVA es de %.2f Euros\n",IVA);
                                    }
                                    else if (iva==2){
                                        printf("A este producto se le aplica un IVA del 10%c\n",37);
                                        printf("%c Cu%cnto le ha costado su producto(en euros)?\n",168,160);
                                        scanf("%f",&PRECIO);
                                        IVA=PRECIO*0.1;
                                        precio= PRECIO - IVA;
                                        printf("El precio sin IVA es de %.2f Euros\n",precio);
                                        printf("El IVA es de %.2f Euros\n",IVA);
                                    }
                                    else if (iva==3){
                                        printf("A este producto se le aplica un IVA del 4%c\n",37);
                                        printf("%c Cu%cnto le ha costado su producto(en euros)?\n",168,160);
                                        scanf("%f",&PRECIO);
                                        IVA=PRECIO*0.04;
                                        precio= PRECIO - IVA;
                                        printf("El precio sin IVA es de %.2f Euros\n",precio);
                                        printf("El IVA es de %.2f Euros\n",IVA);
                                    }
                                    else //Cualquier otra tecla presionada
                                        printf("El n%cmero introducido no es v%clido\n",163,160);


                                    printf(AZUL20 SUBRAYADO ITALIC"\n\nPuede continuar usando la "RESET);
                                    menus (menu);
                                break;

                                case 12: //ATRAS
                                    a=1;
                                    LIMP;
                                break;
                                default:
                                     printf(AZUL20"Introduzca un n%cmero v%clido\n" RESET,163,160);
                                break;

                            }
                                }
                            while(calc!=12);

                        break;
                        case 5: //suerte
                            LIMP;
                            menus (menu);
                            do {
                            printf(RESET);
                            scanf ("%i",&srt);
                            switch (srt)
                            {
                                case 1: //cara o cruz

                                    LIMP;
                                    printf (AZUL24 INVERSO"Lanza una moneda y dice si sale cara o cruz\n"RESET);

                                        int lanz;
                                        srand(time(NULL));
                                        lanz = rand() % 2; //Coge un numero aleatorio y calcula su modulo
                                        if(lanz==0) // Si el numero es par
                                            printf (AZUL24"Ha salido cara\n");
                                        else // Si el numero es impar
                                            printf (AZUL24"Ha salido cruz\n");

                                    printf(SUBRAYADO ITALIC "\nPuede continuar usando los "RESET);
                                    menus (menu);

                                break;

                                case 2: //lanza un dado

                                     LIMP;
                                     printf (AZUL24 INVERSO"Lanza un dado de seis lados\n"RESET);

                                        int lanz1;
                                        srand(time(NULL));
                                        lanz1 = rand() % 6; //Coge un numero aleatorio entre 0 y 5
                                        if(lanz1==0)
                                            printf ("Ha salido el 1\n");
                                        else if (lanz1==1)
                                            printf ("Ha salido el 2\n");
                                        else if (lanz1==2)
                                            printf ("Ha salido el 3\n");
                                        else if (lanz1==3)
                                            printf ("Ha salido el 4\n");
                                        else if (lanz1==4)
                                            printf ("Ha salido el 5\n");
                                        else
                                            printf ("Ha salido el 6\n");

                                     printf(SUBRAYADO ITALIC "\nPuede continuar usando los "RESET);
                                     menus (menu);
                                break;
                                case 3: //carta

                                     LIMP;
                                     printf (AZUL24 INVERSO"Elige una carta aleatoria de la baraja espa%cola\n"RESET,168);

                                     int lanz2;
                                     srand(time(NULL));
                                        lanz2 = rand() % 39; //Coge un numero aleatorio entre 0 y 39
                                        if(lanz2==0)
                                            printf ("Ha salido el 1 de copas\n");
                                        else if (lanz2==1)
                                            printf ("Ha salido el 2 de copas\n");
                                        else if (lanz2==2)
                                            printf ("Ha salido el 3 de copas\n");
                                        else if (lanz2==3)
                                            printf ("Ha salido el 4 de copas\n");
                                        else if (lanz2==4)
                                            printf ("Ha salido el 5 de copas\n");
                                        else if (lanz2==5)
                                            printf ("Ha salido el 6 de copas\n");
                                        else if (lanz2==6)
                                            printf ("Ha salido el 7 de copas\n");
                                        else if (lanz2==7)
                                            printf ("Ha salido la sota de copas\n");
                                        else if (lanz2==8)
                                            printf ("Ha salido el caballo de copas\n");
                                        else if (lanz2==9)
                                            printf ("Ha salido el rey de copas\n");
                                        else if (lanz2==10)
                                            printf ("Ha salido el 1 de espadas\n");
                                        else if (lanz2==11)
                                            printf ("Ha salido el 2 de espadas\n");
                                        else if (lanz2==12)
                                            printf ("Ha salido el 3 de espadas\n");
                                        else if (lanz2==13)
                                            printf ("Ha salido el 4 de espadas\n");
                                        else if (lanz2==14)
                                            printf ("Ha salido el 5 de espadas\n");
                                        else if (lanz2==15)
                                            printf ("Ha salido el 6 de espadas\n");
                                        else if (lanz2==16)
                                            printf ("Ha salido el 7 de espadas\n");
                                        else if (lanz2==17)
                                            printf ("Ha salido la sota de espadas\n");
                                        else if (lanz2==18)
                                            printf ("Ha salido el caballo de espadas 3\n");
                                        else if (lanz2==19)
                                            printf ("Ha salido el rey de espadas 4\n");
                                        else if (lanz2==20)
                                            printf ("Ha salido el 1 de bastos\n");
                                        else if (lanz2==21)
                                            printf ("Ha salido el 2 de bastos\n");
                                        else if (lanz2==22)
                                            printf ("Ha salido el 3 de bastos\n");
                                        else if (lanz2==23)
                                            printf ("Ha salido el 4 de bastos\n");
                                        else if (lanz2==24)
                                            printf ("Ha salido el 5 de bastos\n");
                                        else if (lanz2==25)
                                            printf ("Ha salido el 6 de bastos\n");
                                        else if (lanz2==26)
                                            printf ("Ha salido el 7 de bastos\n");
                                        else if (lanz2==27)
                                            printf ("Ha salido la sota de bastos\n");
                                        else if (lanz2==28)
                                            printf ("Ha salido el caballo de bastos\n");
                                        else if (lanz2==29)
                                            printf ("Ha salido el rey de bastos\n");
                                        else if (lanz2==30)
                                            printf ("Ha salido el 1 de oros\n");
                                        else if (lanz2==31)
                                            printf ("Ha salido el 2 de oros\n");
                                        else if (lanz2==32)
                                            printf ("Ha salido el 3 de oros\n");
                                        else if (lanz2==33)
                                            printf ("Ha salido el 4 de oros\n");
                                        else if (lanz2==34)
                                            printf ("Ha salido el 5 de oros\n");
                                        else if (lanz2==35)
                                            printf ("Ha salido el 6 de oros\n");
                                        else if (lanz2==36)
                                            printf ("Ha salido el 7 de oros\n");
                                        else if (lanz2==37)
                                            printf ("Ha salido la sota de oros\n");
                                        else if (lanz2==38)
                                            printf ("Ha salido el caballo de oros\n");
                                        else
                                            printf ("Ha salido el rey de oros\n");

                                     printf(SUBRAYADO ITALIC "\nPuede continuar usando los "RESET);
                                     menus (menu);
                                break;
                                case 4: //elegir uno

                                    LIMP;
                                    printf (AZUL24 INVERSO"Elige un n%cmero aleatorio entre los deseados\n"RESET,163);

                                    int lanz3,veces;
                                    srand(time(NULL));

                                    printf ("%cEntre cu%cntos n%cmeros quiere hacer la elecci%cn?\n",168,160,163,162);
                                    scanf ("%i",&veces);
                                    lanz3 = rand() % veces ; //Coge un numero aleatorio y calcula su modulo
                                    printf ("Ha salido el n%cmero: %i\n",163,lanz3);

                                    printf(SUBRAYADO ITALIC "\nPuede continuar usando los "RESET);
                                    menus (menu);
                                break;
                                case 5: //atras
                                    a=1;
                                //LIMP;
                                break;
                                default:
                                     printf("Introduzca un n%cmero v%clido\n",163,160);
                                break;

                            }
                            }
                            while (srt!=5);

                        break;

                        case 6:
                            LIMP;
                            b=1;
                            printf (CIAN "Hasta luego!\n"RESET);
//                            animacion_hasta_luego();
                        break;


                        default:
                            printf(CIAN "Introduzca un n%cmero v%clido\n"RESET,163,160);
                        break;
                    }
                    }

                }

                while (menu!=6);

        }
    }
    while (p!=1);

return 0;

}


// FUNCIONES VARIAS
void menus (int menu)
{
    if(menu==1) printf (AZUL24 INVERSO "TEMPORIZADORES:\n\n" RESET AZUL24 "1-.Cron%cmetro\n2-.Cuenta atr%cs\n3-.Ciclos de tiempo\n4-.Atr%cs\n",162,160,160);
    else if(menu==2) printf (AZUL31 INVERSO "CALENDARIO:\n\n"RESET AZUL31"1-.Ver recordatorios\n2-.A%cadir recordatorio\n3-.Editar recordatorio existente\n4-.Eliminar recordatorios existentes y empezar a crear de nuevo\n5-.Atr%cs\n" ,164,160);
    else if(menu==3) printf (AZUL69 INVERSO " GPS \n\n"RESET AZUL69"1-.Radar covid\n2-.Direcci%cn\n3-.Localizaci%cn\n4-.Atr%cs\n" RESET ,162,162,160);
    else if(menu==4) printf (AZUL20 INVERSO "CALCULADORA:\n\n"RESET AZUL20"1-.Sumar\n2-.Restar\n3-.Multiplicar\n4-.Dividir\n5-.Potencia\n6-.Media aritm%ctica\n7-.Media ponderada\n8-.Ecuaci%cn de segundo grado\n9-.Sistema de ecuaciones de dos inc%cgnitas\n10-.Sistema de ecuaciones de tres ingc%cngitas\n11-.IVA\n12-.Atr%cs\n" RESET,130,162,162,162,160);
    else if(menu==5) printf (AZUL20 INVERSO "SUERTE:\n\n"RESET AZUL20"1-.Cara o cruz\n2-.Dado\n3-.Baraja\n4-.Elegir uno\n5-.Atr%cs\n" RESET,160);
    }

void delay(float numero_segundos)
{
    float milli_seconds = 1000 * numero_segundos;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int random()
{
    int nrandom;
    nrandom=rand()%N+1;
    return nrandom;
}


// FUNCION CALCULADORA
float potencia(float base, int exponente)
{
    float resultado = 1;
    int i;
    for (i = 0; i < exponente; ++i) {
        resultado *= base;
    }
    return resultado;
}


// FUNCIONES DEL CALENDARIO
int imprimir_fichero(int numeracion)
{

    int j,Nuu=0;  //Nu será el numero de lineas (recordatorios) del fichero; ev contará el numero de eventos/recordatorios para hoy
    char c; // c para recorrer el fichero por caracteres y contar lineas; opcion para mostrar o no todos los recordatorios en pantalla
    FILE *pf;
    evento eventos[2];             // Vector que almacena los eventos


    pf=fopen("Recordatorios_calendario.txt","r");

    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf("Error al abrir el fichero.");
    }else
    {

        while (fscanf(pf,"%c",&c)!=EOF)  //cuento numero de lineas (cada linea un recordatorio)
            if(c=='\n') Nuu++;

        printf(AZUL31 "Hay %d registrados.\n\n",Nuu);

    fseek(pf,0,SEEK_SET);            //vuelvo al principio del fichero


    if(numeracion==1){
        printf("RECORDATORIOS:\n"RESET);
        for(j=0;j<Nuu;j++)                   //escribo todas las lineas del fichero CON NUMERACION
    {
    fscanf(pf,"%d;%d;%d;%[^;];%s\n",
           &eventos[1].fechaRec.d, &eventos[1].fechaRec.m, &eventos[1].fechaRec.a, &eventos[1].tipo, &eventos[1].recordatorio);
      printf(AZUL31"%.2d %c"RESET" %.2d/%.2d/%d  %s %s\n",
             j+1,16, eventos[1].fechaRec.d, eventos[1].fechaRec.m, eventos[1].fechaRec.a, eventos[1].tipo, eventos[1].recordatorio);
    }
    printf("\n");
    }else{
        LIMP;
        printf("RECORDATORIOS:\n"RESET);
        for(j=0;j<Nuu;j++)                   //escribo todas las lineas del fichero SIN NUMERACION
        {
        fscanf(pf,"%d;%d;%d;%[^;];%s\n",
               &eventos[1].fechaRec.d, &eventos[1].fechaRec.m, &eventos[1].fechaRec.a, &eventos[1].tipo, &eventos[1].recordatorio);
          printf(AZUL31" %c "RESET"%.2d/%.2d/%d  %s %s\n",
                 16, eventos[1].fechaRec.d, eventos[1].fechaRec.m, eventos[1].fechaRec.a, eventos[1].tipo, eventos[1].recordatorio);
        }
        printf("\n");
    }

    }
    return Nuu; //devuelvo el numero de lineas
}
void copio_fichero()                                              //copio el fichero de recordatorios en uno temporal
{
    char ce;
    FILE *orig, *copia;
    orig = fopen("Recordatorios_calendario.txt", "r");
    if (orig == NULL) {
        printf("Error al abrir el archivo origen.\n");

    } else {
        copia = fopen("Recordatorios_copia.txt", "w");
        if (copia == NULL) {
          printf("Error al abrir el archivo copia.\n");

        } else {
            while (fscanf(orig, "%c", &ce) != EOF)
            {
              fprintf(copia, "%c", ce); // Escribo el caracter en la copia
            }

              fclose(orig);  // Cierro ficheros
              fclose(copia);
              //printf("Copia finalizada con exito.\n");
        }
    }
}
void editar_fichero(int nu, int ed, char edit)   // nu es el numero de liteas totales; ed es el numero de linea que quiero modificar; edit decide si edito fecha o recordatorio
{

    int j,nd,nm,na;
    char nuevoRec[20], nuevoTip[20];
    FILE *orig, *co;
    int d,m,a;
    char rec[20], tip[20];
    orig = fopen("Recordatorios_copia.txt", "r");
    co = fopen("Recordatorios_calendario.txt", "w");


    for(j=1;j<=nu;j++)                   //escribo todas las lineas del fichero
    {
        if(j==ed){
                if(edit=='r'){
                    printf(AZUL31"Escriba el nuvo nombre de recordatorio (tipo_de_recordatorio y recordatorio, separados por un espacio):\n"RESET);
                    scanf("%s %s",&nuevoTip, &nuevoRec);
                    fscanf(orig, "%i;%i;%i;%s;%s\n",
                        &d, &m, &a, &tip, &rec);
                    fprintf(co,"%i;%i;%i;%s;%s\n",
                         d, m, a, nuevoTip, nuevoRec);
                }else{
                    printf(AZUL31"Escriba la nueva fecha (d%ca mes a%co, en forma num%crica y separadas por un espacio):\n"RESET,161,164,130);
                    scanf("%i %i %i",&nd, &nm, &na);
                    fscanf(orig, "%d;%d;%d;%s;%s\n",
                        &d, &m, &a, &tip, &rec);
                    fprintf(co,"%d;%d;%d;%s;%s\n",
                         nd, nm, na, tip, rec);
                }
        }
        else{
            fscanf(orig, "%d;%d;%d;%[^;];%s\n",
                &d, &m, &a, &tip, &rec);
            fprintf(co,"%d;%d;%d;%s;%s\n",
                d, m, a, tip, rec);
        }

    }

    fclose(orig); // Cierro ficheros
    fclose(co);

}
char coincide (char a[])
{
    char x;

    if((a[0]=='c'||a[0]=='C')&&(a[1]=='u'||a[1]=='U')&&(a[2]=='m'||a[2]=='M')&&(a[3]=='p'||a[3]=='P')&&(a[4]=='l'||a[4]=='L')&&(a[5]=='e'||a[5]=='E')) x='c';
    else if((a[0]=='e'||a[0]=='E')&&(a[1]=='x'||a[1]=='X')&&(a[2]=='a'||a[2]=='A')&&(a[3]=='m'||a[3]=='M')) x='e';
    else if((a[0]=='f'||a[0]=='F')&&(a[1]=='e'||a[1]=='E')&&(a[2]=='s'||a[2]=='S')&&(a[3]=='t'||a[3]=='T')&&(a[4]=='i'||a[4]=='I')&&(a[5]=='v'||a[5]=='V')&&(a[6]=='o'||a[6]=='O')) x='f';

    else x='q';
    return x;
}
void imprimir_tipo_rec (char c, int Nu)
{
    LIMP;
    int j=0,d,m,a;
    char tip[20],rec[20];
    char coinc;
    FILE *pf;
    pf=fopen("Recordatorios_calendario.txt","r");

    if(c=='c'||c=='C')
    {
        printf(AZUL31 "CUMPLEA%cOS:\n",165);
        for(j=0;j<Nu;j++)
        {
            fscanf(pf,"%d;%d;%d;%[^;];%s\n",
                   &d, &m, &a, &tip, &rec);

            coinc=coincide (tip);
            if(coinc=='c')
            {
                printf(AZUL31" %c "RESET"%s: %.2d/%.2d/%d \n",
                     16, rec, d, m, a);
                j++;
            }
        }
    }else if(c=='e'||c=='E')
    {
        printf("EXAMENES:\n");
        for(j=0;j<Nu;j++)
        {
            fscanf(pf,"%d;%d;%d;%[^;];%s\n",
                   &d, &m, &a, &tip, &rec);

            coinc=coincide (tip);
            if(coinc=='e')
            {
                printf(AZUL31" %c "RESET"%s: %.2d/%.2d/%d \n",
                     16, rec, d, m, a);
                j++;
            }
        }
    }else if(c=='f'||c=='F')
    {
        printf("FESTIVOS:\n");
        for(j=0;j<Nu;j++)
        {
            fscanf(pf,"%d;%d;%d;%[^;];%s\n",
                   &d, &m, &a, &tip, &rec);

            coinc=coincide (tip);
            if(coinc=='f')
            {
                printf(AZUL31" %c "RESET"%s: %.2d/%.2d/%d \n",
                     16, rec, d, m, a);
                j++;
            }
        }
    }else j++;
    printf("\n");
    if(j==0) printf(AZUL31"No hay recordatorios de ese tipo.\n"RESET); // En caso de que se haya pedido mostrar las fechas de uno de los tipos pero no haya ninguna de ese.
}
int escribir_recordatorio ( char modo)
{
    int i,nn;
    int dia, mes, anio, numTip;
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
        do{
            printf("Día: ");
            dia=numero(1,31);
            printf("Mes (en forma numerica, del 1 al 12): ");
            mes=numero(1,12);
            printf("Anio: ");
            anio=numero(1000,9999);
            printf("Tipo de recordatorio:\n1-Examen\n2-Cumpleaños\n3-Festivo\n4-Crear nuevo tipo\n5-(Sin tipo específico)\n");
            scanf(" %i",&numTip);
            if(numTip==1) {
                tip[0]='E';
                tip[1]='x';
                tip[2]='a';
                tip[3]='m';
                tip[4]='e';
                tip[5]='n';
            }
            else if(numTip==2) {
                tip[0]='C';
                tip[1]='u';
                tip[2]='m';
                tip[3]='p';
                tip[4]='l';
                tip[5]='e';
                //tip[6]='a';
                //tip[7]='n';
                //tip[8]='o';
                //tip[9]='s';
            }
            else if(numTip==3) {
                tip[0]='F';
                tip[1]='e';
                tip[2]='s';
                tip[3]='t';
                tip[4]='i';
                tip[5]='v';
                tip[6]='o';
            }
            else if(numTip==4) {
                printf("Nuevo tipo: ");
                scanf(" %s",&tip);
            }
            else if(numTip==5) tip[0]=' ';
            else printf("Esa no es una opcion\n");

            printf("Recordatorio: ");
            scanf(" %s",&rec);

            fprintf(pf,"%d;%d;%d;%s;%s\n",                 //escribo en el fichero
                    dia,mes,anio,tip,rec);

            printf("¿Quiere escribir otro recordatorio?\n1-Si\n2-No\n");
            scanf(" %i",&nn);

        }while (nn-1==0);

    }
    fclose(pf);                           //cierro fichero
    return 0;


}
void printEvento(evento x)
{
  printf("(%i/%i/%i):\t"RESET,
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
void print_fyh()    //dar la hora y dia en pantalla
{
    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
    LIMP;
    strftime(fechayhora, 100, "%H:%M \t\t %d/%m/%Y", tm);
    printf (FAZUL INVISIBLE "\n\t %s \n" RESET,fechayhora);
    printf (FAZUL "\t %s \n",fechayhora);
    printf (INVISIBLE "\t %s \n\n" RESET ,fechayhora);
}


// FUNCIONES TEMPORIZADORES
void cuenta_atras(int se, int mi, int ho, int aa)
{
    int total,i;
    total=se + 60*mi + 3600*ho;
    for(i=0; i<=total; i++)
    {
        delay(1);
        LIMP;
        modo_cuenta_atras (aa);
        printf(AZUL24 "\n\t\t\t[ "RESET"%.2d:%.2d:%.2d "AZUL24"]", ho, mi, se);


        if(ho==0){
            if(mi==0){
                if(se==0){
                }
                else se--;
            }else{
                if(se==0){
                    se=59;
                    mi--;
                }else se--;
            }
        }else{
            if(mi==0){
                if(se==0){
                    se=59;
                    mi=59;
                    ho--;
                }else se--;
            }else{
                if(se==0){
                    se=59;
                    mi--;
                    ho--;
                }else se--;
            }
            }

    }


}
void modo_cuenta_atras (int aa)
{
    if(aa==2) printf (AZUL24 INVERSO "Cuenta atr%cs\n" RESET,160);
    else if (aa==3) printf (AZUL24 INVERSO "Ciclos de tiempo"RESET AZUL24 SUBRAYADO NEGRITA "  M%ctodo Pomodoro \n" RESET AZUL24 "\nToca estudiar\n",130);
    else if (aa==4) printf (AZUL24 INVERSO "Ciclos de tiempo"RESET AZUL24 SUBRAYADO NEGRITA "  M%ctodo Pomodoro \n" RESET AZUL24 "\nToca descanso\n",130);
    else if (aa==5) printf (AZUL24 INVERSO "Ciclos de tiempo"RESET AZUL24 SUBRAYADO NEGRITA "  M%ctodo T%cbata \n" RESET AZUL24 "\nToca hacer ejercicio\n",130,160);
    else if (aa==6) printf (AZUL24 INVERSO "Ciclos de tiempo"RESET AZUL24 SUBRAYADO NEGRITA "  M%ctodo T%cbata \n" RESET AZUL24 "\nToca descanso\n",130,160);

}


// COMPROBACIÓN DE DATOS
int cuenta_caracteres (char mmm[])  // CUENTA LOS CARACTERES INTRODUCIDOS
{
    int i=0;
    while(mmm[i]!='\0'){
        i++;
    }
    return i;
}
int salir(char salir[10]){   //DETECTA SI EL USUARIO ESCIBE 'FIN'.

     if (((salir[0]) == 'F') && ((salir[1]) == 'I') && ((salir[2]) == 'N') && (salir[3] == '\0')){
        animacion_hasta_luego;
        return -1;
     }
    return 1;
}


float numero (int minimo, int maximo)  // PIDE AL USUARIO UN NUMERO ACOTADO, LO COMPRUEBA Y LO DEVUELVE
{
    int iiii,contador_errores=0,Ncontador=0,Pcontador=0,PP=0,tttt=0,acotacion=0, signo=0;
    char mmm[10]; // cadena que el usuario escribirá por teclado
    float nummm=0; // numero que devolverá la función

    do{
        do{
            do{
                do{
                    if(contador_errores>0){  // ESCRIBE POR PANTALLA LOS ERRORES DETECTADOS
                        printf("Dato incorrecto.\n");
                        if(tttt>0) printf("Debe introducir solo datos numericos.\n");
                        if(Pcontador>1) printf("Debe introducir un punto como maximo.\n");
                        if(cuenta_caracteres(mmm)>10) printf("Se escribieron %i caracteres. Como maximo debe escribir 10 caracteres.\n",cuenta_caracteres(mmm));
                        if(acotacion>0) printf("La cifra debe estar entre %i y %i.\n",minimo,maximo);
                        if(contador_errores>3){
                            printf("Demasiados intentos, vuelva a probar mas tarde.\n");
                            return ERRORES; // el usuario escribió datos incorrectos varias veces seguidas
                        }
                    }
                    // vuelvo a poner todo a 0 (menos el contador de errores)
                    tttt=0;
                    Ncontador=0;
                    Pcontador=0;
                    PP=0;
                    acotacion=0;
                    nummm=0;
                    signo=0;
                    for(iiii=0;iiii<10;iiii++){
                        mmm[iiii]=0;
                    }

                    //introduzco cadena a evaluar
                    scanf(" %[^\n]",mmm);

                    if (salir(mmm)==-1) return FIN; // el usuario escribió "FIN", el programa se cerrará

                    if(mmm[0]=='-'){  // DETECTAR SI ES NEGATIVO
                        signo=1;
                        Ncontador++;

                        for(iiii=1;iiii<10;iiii++){  //DETECTAR SI HAY CARACTERES NO NUMERICOS
                            if (mmm[iiii]!=0){ //desprecia los espacios de m[] no rellenados
                                if((mmm[iiii]>47)&&(mmm[iiii]<58)){ //entre estos valores se encuentran los numeros del 0 al 9
                                }else if(mmm[iiii]=='.'){
                                    PP=iiii;      // ASIGNAR POSICIÓN DEL PUNTO
                                    Pcontador++;  // DETECTOR DE SI SE ESCRIBE MAS DE UN PUNTO
                                }
                                else {  // DETECTOR DE CARACTER DISTINTO DE NUMERO, PUNTO O HUECO SIN ESCRIBIR

                                    if(mmm[iiii]==8) Ncontador--;
                                    else tttt++;

                                }
                                Ncontador++; //CUENTA CASILLAS RELLENADAS
                            }
                        }
                    }
                    else{
                        for(iiii=0;iiii<10;iiii++){  //DETECTAR SI HAY CARACTERES NO NUMERICOS
                            if (mmm[iiii]!=0){ //desprecia los espacios de m[] no rellenados
                                if((mmm[iiii]>47)&&(mmm[iiii]<58)){ //entre estos valores se encuentran los numeros del 0 al 9
                                }else if(mmm[iiii]=='.'){
                                    PP=iiii;      // ASIGNAR POSICIÓN DEL PUNTO
                                    Pcontador++;  // DETECTOR DE SI SE ESCRIBE MAS DE UN PUNTO
                                }
                                else {  // DETECTOR DE CARACTER DISTINTO DE NUMERO, PUNTO O HUECO SIN ESCRIBIR

                                    if(mmm[iiii]==8) Ncontador--;
                                    else tttt++;

                                }
                                Ncontador++; //CUENTA CASILLAS RELLENADAS
                            }
                        }
                    }

                    contador_errores++; //en caso de repetir algún bucle, se cuentan los errores

                }while(cuenta_caracteres(mmm)>10);  // LONGITUD MAYOR DE LA PERMITIDA POR LA CADENA
            }while(tttt>0); // HAY CARACTERES NO NUMÉRICOS
        }while(Pcontador>1); // HAY MÁS DE UN PUNTO


        if (Pcontador==0){   // CUANDO NO HAY CIFRAS DECIMALES
            for(iiii=signo;iiii<Ncontador;iiii++){
                //printf("%d\n",Ncontador);
                if(mmm[iiii]!=8){
                    nummm=nummm+((mmm[iiii]-48)*pow(10,Ncontador-iiii-1));

                }
            }
        }else{ //Pcontador==1    CUANDO SI PUEDE HABER CIFRAS DECIMALES
            for(iiii=signo;iiii<PP;iiii++){ // cifras enteras, antes del punto
                nummm=nummm+((mmm[iiii]-48)*pow(10,PP-iiii-1));
            }
            for(iiii=PP+1;iiii<Ncontador;iiii++){ // cifras decimales, despues del punto
                nummm=nummm+(mmm[iiii]-48)*pow(10,PP-iiii);
            }
        }

        if((nummm<minimo)||(nummm>maximo)) acotacion++;

    }while ((nummm<minimo)||(nummm>maximo)); // COMPROBACIÓN DE LA ACOTACIÓN DESEADA


    if(signo==1) nummm=-nummm;
    return nummm; // resultado en tipo float, preparado para operar con él

}



// ANIMACIONES
void animacion_reloj_inteligente()
{

    FILE *pf;
    char c,color;
    int i;

    pf=fopen("reloj_inteligente.txt","r");
    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf(AZUL31 "Error al abrir el fichero."RESET);
    }else
    {

        LIMP;fseek(pf,0,SEEK_SET);

        LIMP;
        fseek(pf,0,SEEK_SET);

        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (CIAN "%c", c);
            delay(0.004);
        }

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL24 "%c", c);
        }
        delay(0.1);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL31 "%c", c);
        }
        delay(0.1);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL69 "%c", c);
        }
        delay(0.1);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL20 "%c", c);
        }
        delay(0.1);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (CIAN "%c", c);
        }
        delay(0.07);


    }
    delay(2);
    fclose(pf);
}
void animacion_temporizadores()
{

    FILE *pf;
    char c;

    pf=fopen("animacion_temporizadores.txt","r");
    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf(AZUL24 "Error al abrir la animacion de los temporizadores."RESET);
    }else
    {
        LIMP;
        fseek(pf,0,SEEK_SET);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (RESET AZUL24 "%c", c);
            delay(0.010);
        }
    }
    delay(0.5);
    fclose(pf);
}
void animacion_calendario()
{

    FILE *pf;
    char c;

    pf=fopen("animacion_calendario.txt","r");
    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf(AZUL31 "Error al abrir la animacion del calendario."RESET);
    }else
    {
        LIMP;
        fseek(pf,0,SEEK_SET);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (RESET AZUL31 "%c", c);
            delay(0.010);
        }
    }
    delay(0.5);
    fclose(pf);
}
void animacion_GPS()
{

    FILE *pf;
    char c;

    pf=fopen("animacion_gps.txt","r");
    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf(AZUL69 "Error al abrir la animacion del GPS."RESET);
    }else
    {
        LIMP;
        fseek(pf,0,SEEK_SET);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (RESET AZUL69 "%c", c);
            delay(0.010);
        }
    }
    delay(0.5);
    fclose(pf);
}
void animacion_calculadora()
{

    FILE *pf;
    char c;

    pf=fopen("animacion_calculadora.txt","r");
    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf(AZUL20 "Error al abrir la animacion de la calculadora."RESET);
    }else
    {
        LIMP;
        fseek(pf,0,SEEK_SET);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (RESET AZUL20 "%c", c);
            delay(0.010);
        }
    }
    delay(0.5);
    fclose(pf);
}
void animacion_hasta_luego()
{

    FILE *pf;
    char c,color;
    int i;

    pf=fopen("hasta_luego.txt","r");
    if(pf==NULL)                          //compruebo que se abre bien
    {
        printf(AZUL31 "Error al abrir el fichero."RESET);
    }else
    {

        LIMP;fseek(pf,0,SEEK_SET);

        LIMP;
        fseek(pf,0,SEEK_SET);

        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (CIAN "%c", c);
            delay(0.004);
        }

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL24 "%c", c);
        }
        delay(0.17);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL31 "%c", c);
        }
        delay(0.17);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL69 "%c", c);
        }
        delay(0.17);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (AZUL20 "%c", c);
        }
        delay(0.17);

        fseek(pf,0,SEEK_SET);
        printf(INICIO);
        for(c=0; c != EOF;){ // IMPRIMIR FICHERO
            c = fgetc (pf);
            printf (CIAN "%c", c);
        }


    }
    delay(1.5);
    fclose(pf);
}
