#include <stdio.h>
#include <stdlib.h>
/*Deseamos realizar un programa que gestione las notas de una clase de 10 alumnos de los
cuales sabemos el DNI y la nota. El programa debe mostrar un menú con las siguientes
opciones a resolver:
1. Cargar Alumnos
2. Buscar un alumno
3. Modificar la nota de un alumno
4. Mostrar un listado de los 10 alumnos
5. Salir
Donde, la opción 1 permite cargar los 10 alumnos ingresando para cada uno: DNI y nota.
Validar que el DNI no sea menor que 1000000 ni mayor que 99999999. Validar que la nota sea
mayor a 0 y menor o igual que 10.
La opción 2 debe pedir el DNI de un alumno y mostrar en consola DNI y nota. Si el DNI
ingresado no existe, informar la situación con un mensaje “DNI inexistente”.
La opción 3 debe pedir el DNI del alumno al cual se desea cambiar la nota y la nueva nota. Si el
DNI ingresado no existe, informar la situación con un mensaje “DNI inexistente”, si el DNI si se
encuentra modificar la nota del alumno por la ingresada.
La opción 4 debe mostrar en la consola el listado de alumnos.
SÓLO se saldrá de la aplicación si se selecciona la opción 5 */

void main()
{
    float lista[10][2];
    int opcion;
    int cantDeAlumnos = 2;
    float dniIngresado;
    float notaIngrasada;
    int numeroDeAlumno;
    int bandera = 0;
    int validacion = 0;
    do
    {
        do
        {
            printf("MENU DE OPCIONES:\n");
            printf("1.cargar alumnos\n");
            printf("2.buscar un alumno\n");
            printf("3.modificar la nota de un alumno\n");
            printf("4.mostrar un listado de 10 alumnos\n");
            printf("5.salir\n");

            scanf("%i", &opcion);

            if (opcion < 1 || opcion > 5)
            {
                printf("ERROR, vueva a intentarlo\n");
            }

        } while (opcion < 1 || opcion > 5);

        printf("opcion elegida: %i\n", opcion);

        switch (opcion)
        {
        case 1:
            printf("ingrese datos de los alumnos\n");
            for (int i = 0; i < cantDeAlumnos; i++)
            {
                printf("Alumno %i \n", i);
                for (int j = 0; i < 2; i++)
                {
                    do
                    {
                        printf("DNI:\n");
                        scanf("%f", &lista[i][0]);
                        if (lista[i][0] < 1000000 || lista[i][0] > 99999999)
                        {
                            printf("ERROR: no ingreso un DNI valido\n");
                        }
                    } while (lista[i][0] < 1000000 || lista[i][0] > 99999999);

                    do
                    {
                        printf("Nota:\n");
                        scanf("%f", &lista[i][1]);
                        if (lista[i][1] < 0 || lista[i][1] > 10)
                        {
                            printf("ERROR: no ingreso una nota valida\n");
                        }
                    } while (lista[i][1] < 0 || lista[i][1] > 10);
                }
            }

            for (int i = 0; i < cantDeAlumnos; i++)
            {
                printf("DNI: %.0f \tnota: %.1f \n", lista[i][0], lista[i][1]);
            }

            printf("desea volver al menu? (0 para Si y 1 para no)");
            scanf("%i", &validacion);
            if (validacion == 1)
            {
                printf("se ha finalizado la operacion");
                exit(-1);
            }
            else
            {
                printf(" ");
            }

            break;

        case 2:
            printf("ingrese DNI del alumno que desea buscar\n");
            scanf("%f", &dniIngresado);

            for (int i = 0; i < cantDeAlumnos; i++)
            {
                if (dniIngresado == lista[i][0])
                {
                    bandera = 1;
                    numeroDeAlumno = i;
                }
            }

            if (bandera == 1)
            {
                printf("DNI: %.0f \tnota: %.1f \n", lista[numeroDeAlumno][0], lista[numeroDeAlumno][1]);
            }
            else
            {
                printf("no se encontro a un alumno con ese DNI\n");
            }
            bandera = 0;

            printf("desea volver al menu? (0 para Si y 1 para no)");
            scanf("%i", &validacion);
            if (validacion == 1)
            {
                printf("se ha finalizado la operacion");
                exit(-1);
            }
            else
            {
                printf(" ");
            }

            break;
        case 3:

            break;
        case 4:

            for (int i = 0; i < cantDeAlumnos; i++)
            {
                printf("DNI: %.0f \tnota: %.1f \n", lista[i][0], lista[i][1]);
            }
            break;
        case 5:

            break;
        default:
            break;
        }
    } while (opcion != 5);

    system("pause");
}