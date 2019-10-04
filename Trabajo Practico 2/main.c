#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#define LEMPLEADOS 5


int main()
{
    Employee unEmpleado;
    Employee listaDeEmpleados[LEMPLEADOS];
    initEmployees(listaDeEmpleados,LEMPLEADOS);
    Employee otro_array[LEMPLEADOS];
    int opcion,auxId,opcionOrdenar;
    int flagCarga = 0;
    int contadorEmpleados = 0;
    do
    {
        getValidInt("1. Dar de alta nuevo Empleado\n2. Modificar Empleado\n3. Dar de baja Empleado\n4. Informar Empleados\n5. Informar Promedio Salarios\n6.Salir\n","Error Por favor Ingrese numeros Validos",0,7,&opcion);

        switch(opcion)
        {
        case 1:
            if(addEmployee(listaDeEmpleados,LEMPLEADOS)!= -1)
            {
                printf("\nEmpleado Cargado\n");
                flagCarga = 1;
            }
            else
            {
                printf("\nError en la Carga de Empleado\n");
            }
            break;
        case 2:
            if (flagCarga != 0)
            {
                printEmployees(listaDeEmpleados,LEMPLEADOS);
                auxId = getInt("\nIngrese el id del Empleado a Modificar: ");
                findEmployeeById(listaDeEmpleados,LEMPLEADOS,auxId);
            }
            else
            {
                printf("\nPrimero Debe cargar al menos un Empleado\n");
            }
            break;
        case 3:
            if (flagCarga != 0)
            {
                auxId = 0;
                printEmployees(listaDeEmpleados,LEMPLEADOS);
                auxId = getInt("\nIngrese el id del Empleado a Modificar: ");
                if(removeEmployee(listaDeEmpleados,LEMPLEADOS, auxId) == 1)
                {
                    printf("\nEmpleado dado de baja\n");
                }
                else
                {
                    printf("\n No existe Empleado con ese ID, vuelva a Intentar \n");
                }
            }
            else
            {
                printf("\nPrimero Debe cargar al menos un Empleado\n");
            }
            break;
        case 4:
            memcpy(otro_array,listaDeEmpleados,sizeof(otro_array));
            if(flagCarga !=0)
            {
                getValidInt("1) Ordenar de A-Z\n2) Ordenar de Z-A\n","Ingrese una Opcion Valida",1,2,&opcionOrdenar);
                sortEmployees(otro_array,LEMPLEADOS,opcionOrdenar);
                printEmployees(otro_array, LEMPLEADOS);
            }
            else
            {
                printf("\nPrimero Debe cargar al menos un Empleado\n");
            }
            break;
        case 5:
            if(flagCarga != 0)
            {
                promedioSalarios(listaDeEmpleados, LEMPLEADOS);
            }
            else
            {
                printf("\nPrimero Debe cargar al menos un Empleado\n");
            }
            break;
        case 6:
            opcion = 7;
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion != 7);


    return 0;
}
