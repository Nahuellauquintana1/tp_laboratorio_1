#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Genera Espacio en memoria para el Empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief Crea Empleado con los Parametros pasados a la funcion
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief Elimina un Empleado
 *
 * \return void
 *
 */
void employee_delete();

/** \brief Setter de id
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Getter de id
 *
 * \param this Employee*
 * \param id int*
 * \return int devuleve id
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Settea el nombre al parametro pasado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Devuelve el nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setea las horas del empleado pasado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Devuleve las horas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Establece el sueldo al parametro
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Devuelve el sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra un empleado en consola
 *
 * \param emp Employee*
 * \return void
 *
 */
void mostrarEmpleado(Employee* emp);

/** \brief Ordena empleados por id
 *
 * \param void*
 * \param void*
 * \return int
 *
 */
int sortEmpleadoId(void*,void*);
/** \brief Crea un empleado pidiendo al usuario los datos
 *
 * \param int id Id generada automaticamente
 * \param
 * \return Devuelve el empleado creado
 *
 */
Employee* altaEmpleado (int id);

/** \brief Funcion que permite modificar los 3 Campos del empleado
 *
 * \param unEmpleado Employee*
 * \param opcion int
 * \return int
 *
 */
int modifEmpleado(Employee* unEmpleado, int opcion);


#endif // employee_H_INCLUDED
