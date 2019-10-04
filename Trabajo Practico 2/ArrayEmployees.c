#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#include "ArrayEmployees.h"
#include "inputs.h"

int initEmployees(Employee list[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        list[i].isEmpty = LIBRE;
    }
    return 0;
}
int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    return opcion;
}

int addEmployee(Employee list[], int len)
{
    int i;
    i = pedirIndiceLibre(list, len);
    if(i!=-1)
    {
        list[i].id = i+1;
        getValidString("Ingrese Nombre: ","Ingrese un Nombre Valido\n",1,50,list[i].name);
        list[i].name[0]=toupper(list[i].name[0]);
        getValidString("Ingrese Apellido: ","Ingrese un Apellido Valido\n",1,50,list[i].lastName);
        list[i].lastName[0]=toupper(list[i].lastName[0]);
        pedirFloatValidado("Ingrese Salario del Empleado: ","Ingrese un Salario Valido\n",1,1000000,&list[i].salary);
        getValidInt("Ingrese Sector del Empleado: ","Ingrese un Sector Valido\n",1,100,&list[i].sector);
        list[i].isEmpty = OCUPADO;
        return 1;
    }
    else
    {
        return -1;
    }
}
int removeEmployee(Employee list[], int len, int id)
{
    int i;
    int retorno = 0; /// Si existe Legajo 1 ---- Si no Existe Legajo 0
    for(i = 0; i  < len ; i++)
    {
        if(list[i].id == id)
        {
            list[i].isEmpty = 0;
            retorno = 1;
        }
    }
    return retorno;
}
void sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    Employee auxEmployee;

    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].isEmpty == OCUPADO)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)>0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else
                    {
                        if(strcmp(list[i].lastName,list[j].lastName)==0)
                        {
                            if(list[i].sector>list[j].sector)
                            {
                                auxEmployee = list[i];
                                list[i] = list[j];
                                list[j] = auxEmployee;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].isEmpty == OCUPADO)
                {

                    if(strcmp(list[i].lastName,list[j].lastName)<0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else
                    {
                        if(strcmp(list[i].lastName,list[j].lastName)==0)
                        {
                            if(list[i].sector<list[j].sector)
                            {
                                auxEmployee = list[i];
                                list[i] = list[j];
                                list[j] = auxEmployee;
                            }
                        }
                    }
                }
            }
        }
    }
}

int printEmployees (Employee list[], int len)
{
    int i;
    int flagEstado = 1;
    printf("Apellido\t\tNombre\t\tSalario\t\tSector\t\tID\n");
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            flagEstado = 0;
            mostrarEmployee(list[i]);
        }

    }
    if(flagEstado == 1)
    {
        printf("\nNo hay Empleados Cargados\n");
    }
    return 0;
}
int mostrarEmployee (Employee unEmployee)
{
    printf("%-10s\t", unEmployee.lastName);
    printf("%-10s\t", unEmployee.name);
    printf("%15.2f\t", unEmployee.salary);
    printf("%15d\t", unEmployee.sector);
    printf("%15d\n", unEmployee.id);
    return 0;
}

int subMenu (Employee* unEmployee)
{
    int opcion,retorno;
    system("cls");
    do
    {
        getValidInt("1. Apellido\n2. Nombre\n3. Salario\n4. Sector\n5. Volver al Menu Anterior\n","Por favor Ingrese una Opcion Valida",1,5,&opcion);

        switch(opcion)
        {
        case 1:
            modificarApellido(unEmployee);
            retorno = 1;
            break;
        case 2:
            modificarNombre(unEmployee);
            retorno = 1;
            break;
        case 3:
            modificarSalario(unEmployee);
            retorno = 1;
            break;
        case 4:
            modificarSector(unEmployee);
            retorno = 1;
            break;
        case 5:
            opcion = 5;
            break;
        }
        system("cls");
    }
    while(opcion != 5);
    return retorno;

}

void modificarApellido(Employee* unEmployee)
{
    Employee auxEmployee;
    getValidString("Ingrese el Nuevo Apellido: ","Ingrese un Nombre Valido",1,49,auxEmployee.lastName);
    fflush(stdin);
    strcpy(unEmployee->lastName,auxEmployee.lastName);
}

void modificarNombre(Employee* unEmployee)
{
    char auxNombre[50];
    getValidString("Ingrese el Nuevo Nombre: ","Ingrese un Nombre Valido",1,49,auxNombre);
    fflush(stdin);
    strcpy(unEmployee->name,auxNombre);
}
void modificarSalario(Employee* unEmployee)
{
    float auxSalario;
    pedirFloatValidado("Ingrese el Nuevo Salario: ","Ingrese un Salario Valido",1,1000000,&auxSalario);
    fflush(stdin);
    unEmployee->salary = auxSalario;
}

void modificarSector(Employee* unEmployee)
{
    int auxSector;
    getValidInt("Ingrese el Nuevo Sector: ","Ingrese un Sector Valido",1,10,&auxSector);
    fflush(stdin);
    unEmployee->sector = auxSector;
}

int pedirIndiceLibre(Employee list[], int len)
{
    int i;
    for ( i = 0; i < len ; i++)
    {
        if(list[i].isEmpty == LIBRE)
        {
            return i;
        }
    }
    return -1;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    int flag = 0;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            if(list[i].id == id)
            {
                subMenu(&list[i]);
                flag = 1;
            }
        }
    }
    if(flag != 1)
    {
        printf("No existe empleado con ese ID");
    }
    return id;
}

int promedioSalarios(Employee* list, int len)
{
    int i,promedio,j;
    int contador = 0;
    int acumulador = 0;

    for(i = 0; i < len ; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            contador++;
            acumulador = acumulador + list[i].salary;
        }

    }
    promedio = acumulador / contador;
    printf("El promedio del Salario es: %d\n", promedio);

    for(j = 0; j < len ; j++)
    {
        if(list[j].isEmpty == OCUPADO)
        {
            if(list[j].salary > promedio)
            {
                printf("\n\tEmpleados que superan al Promedio\n");
                printf("Apellido\t\tNombre\t\tSalario\t\tSector\t\tID\n");
                mostrarEmployee(list[j]);
            }
        }
    }
return 0;
}
