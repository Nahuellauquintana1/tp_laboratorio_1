
struct
    {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; // OCUPADO = 1 --- LIBRE = 0
    }typedef Employee;

/** \brief Muestra un solo Empleado
 *
 * \param Estructura Employee
 * \param Un empleado dentro de la Estructura
 * \return 0 si no hay error
 *
 */
int mostrarEmployee (Employee unEmployee);
/** \brief Sub menu modificaciones
 *
 * \param Estructura Employee
 * \param Un empleado de la estructura
 * \return
 *
 */
int subMenu (Employee* unEmployee);
/** \brief Inicializa Empleados
 *
 * \param listaEmpleados[] Employee lista de Empleados
 * \param len int tamaño de la lista de Empleados
 * \return
 *
 */
int initEmployees(Employee listaEmpleados[] , int len);
/** \brief Menu de Opciones generico
 *
 * \param mensaje[] char Mensaje para mostrar en el menu
 * \return int
 *
 */
int menuDeOpciones(char mensaje[]);
/** \brief Crea un Nuevo empleado con datos ingresados por el usuario
 *
 * \param listaEmpleados[] Employee lista de Empleados
 * \param len int tamaño de la lista de Empleados
 * \return 1 si es correcto -1 si hay error
 *
 */
int addEmployee(Employee listaEmpleados[] , int len);
/** \brief Baja logica de empleados Cambia estado (isEmpty) a LIBRE buscando el empleado por id
 *
 * \param listaEmpleados[] Employee array de empleados
 * \param len int tamaño del array
 * \param id int  id ingresado por el usuario
 * \return int 1 si se pudo
 *
 */
int removeEmployee(Employee listaEmpleados[] , int len, int id);
/** \brief Ordena por Apellido en orden ascendente o descendente
 *
 * \param listaEmpleados[] Employee array de empleados
 * \param len int tamaño del array de empleados
 * \param order int 1 para A-Z 0 para Z-A
 * \return void
 *
 */
void sortEmployees(Employee listaEmpleados[] , int len, int order);
/** \brief Muestra todos los empleados llamando a mostrarEmployee
 *
 * \param listaEmpleados[] Employee Array de Empleados
 * \param len int Tamaño del Array de Empleados
 * \return int
 *
 */
int printEmployees(Employee listaEmpleados[] , int len);
/** \brief Modifica El apellido del Empleado solicitado
 *
 * \param unEmployee Employee* Puntero a un Empleado
 * \return void
 *
 */
void modificarApellido(Employee* unEmployee);
/** \brief Modifica El Nombre del Empleado solicitado
 *
 * \param unEmployee Employee* Puntero a un Empleado
 * \return void
 *
 */
void modificarNombre(Employee* unEmployee);
/** \brief Modifica El Salario del Empleado solicitado
 *
 * \param unEmployee Employee* Puntero a un Empleado
 * \return void
 *
 */
void modificarSalario(Employee* unEmployee);
/** \brief Modifica El Sector del Empleado solicitado
 *
 * \param unEmployee Employee* Puntero a un Empleado
 * \return void
 *
 */
void modificarSector(Employee* unEmployee);
/** \brief Pide el primer indice libre del array
 *
 * \param listaEmpleados[] Employee array de Employee
 * \param len int   tamaño del array de employee
 * \return int devuelve el indice
 *
 */
int pedirIndiceLibre(Employee listaEmpleados[], int len);
/** \brief Busca un Empleado por el id ingresado por el usuario
 *
 * \param Employee* puntero a Employee
 * \param len int tamaño del array de Employee
 * \param id int id a buscar en el array
 * \return int
 *
 */
int findEmployeeById(Employee* , int len,int id);
/** \brief Calcula el Promedio de Los salarios E informa Aquellos que lo superan
 *
 * \param Employee* puntero a la Lista de Empleados
 * \param len int   tamaño de la lista
 * \return int
 *
 */
int promedioSalarios(Employee* , int len);
