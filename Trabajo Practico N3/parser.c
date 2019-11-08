#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
     char id [50];
     char nombre [50];
     char horasTrabajadas[50];
     char sueldo[50];
     int i=0;
     Employee* unEmpleado;
     fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
     while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        unEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee, unEmpleado);
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

     while(!feof(pFile))
    {
        Employee* aux = malloc(sizeof(Employee));
        fread(aux,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee, aux);
    }

    fclose(pFile);

    return 1;
}
