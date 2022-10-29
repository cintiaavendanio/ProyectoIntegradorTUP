#include <stdio.h>
#include <stdlib.h>

struct alumno
{
    int dni;
    int nota;
};

struct alumno lista_alumnos[10];

int cant_alumnos = 2;
float dni_ingresado;
float nota_ingresada;
int bandera = 0;
int validacion;
float nueva_nota;
int numero_alumno;

void cargarDatos();
void buscarAlumno();
void modificarAlumnos();
void mostrarAlumnos();

void main()
{
    int opcion;
    do
    {
        printf("Ingrese una opci%cn \n", 162);
        printf("1-Cargar alumnos \n");
        printf("2-Buscar un alumno \n");
        printf("3-Modificar la nota de un alumno \n");
        printf("4-Mostrar un listado de los 10 alumnos \n");
        printf("5-Salir \n");
        scanf("%i", &opcion);

        if (opcion != 5)
        {
            switch (opcion)
            {
            case 1: // carga de datos
                cargarDatos();
                break;

            case 2: // búsqueda

                buscarAlumno();

                break;

            case 3: // modificación de notas de alumnos

                modificarAlumnos();
                break;

            case 4: // listado de alumnos
                mostrarAlumnos();
                break;
            }
        }

    } while (opcion != 5);

    system("pause");
}

void cargarDatos()
{
    printf("Ingrese datos de los alumnos \n");
    for (int i = 0; i < cant_alumnos; i++)
    {
        do
        {
            printf("DNI: \n");
            scanf("%i", &lista_alumnos[i].dni);
            if (lista_alumnos[i].dni < 1000000 || lista_alumnos[i].dni > 99999999)
            {
                printf("ERROR: no ingreso un dni valido");
            }

        } while (lista_alumnos[i].dni < 1000000 || lista_alumnos[i].dni > 99999999);

        do
        {
            printf("Nota: \n");
            scanf("%i", &lista_alumnos[i].nota);
            if (lista_alumnos[i].nota < 1 || lista_alumnos[i].nota > 10)
            {
                printf("ERROR: no ingreso una nota valida");
            }

        } while (lista_alumnos[i].nota < 1 || lista_alumnos[i].nota > 10);
    }
}

void buscarAlumno()
{
    printf("ingrese DNI del alumno que desea buscar\n");
    scanf("%f", &dni_ingresado);

    for (int i = 0; i < cant_alumnos; i++)
    {
        if (dni_ingresado == lista_alumnos[i].dni)
        {
            bandera = 1;
            numero_alumno = i;
        }
    }

    if (bandera == 1)
    {
        printf("DNI: %i \t nota: %i \n", lista_alumnos[numero_alumno].dni, lista_alumnos[numero_alumno].nota);
    }
    else
    {
        printf("no se encontro un alumno con ese DNI \n");
    }

    bandera = 0;
}
void modificarAlumnos()
{
    printf("ingrese DNI del alumno del cual desea modificar la nota\n");
    scanf("%f", &dni_ingresado);

    for (int i = 0; i < cant_alumnos; i++)
    {
        if (dni_ingresado == lista_alumnos[i].dni)
        {
            bandera = 1;
            numero_alumno = i;
        }
    }

    if (bandera == 1)
    {
        printf("Ingrese la nueva nota \n");
        scanf("%f", &nueva_nota);
        lista_alumnos[numero_alumno].nota = nueva_nota;

        printf("DNI: %i \t nota: %i \n", lista_alumnos[numero_alumno].dni, lista_alumnos[numero_alumno].nota);
    }
    else
    {
        printf("no se encontro un alumno con ese DNI \n");
    }
}
void mostrarAlumnos()
{
    printf(" Lista de alumnos \n");
    for (int i = 0; i < cant_alumnos; i++)
    {
        printf("Alumno %i \t DNI: %i \t nota: %i \n", i + 1, lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
}