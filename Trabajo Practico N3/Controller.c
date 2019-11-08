#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = parser_EmployeeFromText(pFile,pArrayListEmployee);

        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if(pFile == NULL)
    {
        printf("\nNo existe el archivo\n");
        printf("Para crear un archivo .bin,Lea el archivo en modo texto\nLuego guarde en modo binario\nDespues de hacer eso puede leer en modo binario\n");

    }
    else
    {
        retorno = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        fclose(pFile);
        return retorno;
    }
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int auxIdAuto;
    int retorno = 0;
    if(pArrayListEmployee != NULL)
    {
        auxIdAuto = idA(pArrayListEmployee,1);
        aux = (Employee*)altaEmpleado(auxIdAuto);
    }
    if(aux != NULL)
    {
        ll_add(pArrayListEmployee, aux);
        retorno = 1;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 modificacion existosa 0 no se modifico
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int auxId, opcion, retorno;
    char auxModif;
    mostrarLista(pArrayListEmployee);
    getValidInt("Ingrese id del Empleado a Modificar: ","\nIngerse un Numero valido",0,1000,&auxId);
    aux = (Employee*)ll_get(pArrayListEmployee,(auxId-1));
    mostrarEmpleado(aux);
    auxModif = getChar("Esta seguro que desea Modificar este empleado? (s/n)\n");
    if(auxModif == 's')
    {
        getValidInt("Eliga que desea Modificar(1.Nombre-2.HorasTrabajadas-3.Sueldo): ","Elija 1 2 o 3",0,3,&opcion);
        retorno = modifEmpleado(aux,opcion);

    }
    if(retorno == 1)
    {
        printf("\nmodificacion Exitosa\n");
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int auxId;
    char auxRemove;
    Employee* auxGet;
    mostrarLista(pArrayListEmployee);
    getValidInt("Ingrese id del Empleado a Eliminar: ","\nIngerse un Numero valido",0,1000,&auxId);
    auxGet = (Employee*)ll_get(pArrayListEmployee,(auxId-1));
    mostrarEmpleado(auxGet);
    auxRemove = getChar("Esta seguro que desea Eliminar este empleado? (s/n)");
    if(auxRemove == 's')
    {
        ll_remove(pArrayListEmployee,(auxId-1));
        printf("Empleado Eliminado");
        retorno = 1;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    if(pArrayListEmployee != NULL)
    {
         mostrarLista(pArrayListEmployee);
         retorno = 0;
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcionAux;
    getValidInt("Ingrese 0 para ordenar por ID Decreciente\nIngrese 1 para ordenar por ID Creciente: ","Ingrese un numero",0,2,&opcionAux);
    if(opcionAux == 0)
    {
    printf("Ordenano Espere\n");
    }
    ll_sort(pArrayListEmployee,sortEmpleadoId,opcionAux);///lista, funcion SOLO nombre sin parentesis, orden 1 --- 0
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* aux;
    int len, i;
    len = ll_len(pArrayListEmployee);
    pFile = fopen(path,"w");
    for(i = 0; i < len; i++)
    {
        aux = ll_get(pArrayListEmployee,i);
        fprintf(pFile,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* aux;
    int len, i;
    len = ll_len(pArrayListEmployee);
    pFile = fopen(path,"wb");
    for(i = 0; i < len; i++)
    {
        aux = ll_get(pArrayListEmployee,i);
        fwrite(aux,sizeof(Employee),1,pFile);
    }

    return 1;
}

