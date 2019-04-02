#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
int main()
{
    int option;
    char continuar = 's';
    float operando1 = 0;
    float operando2 = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    long long factorialOp1;
    long long factorialOp2;
    int flagDivision =  0;
    int flagFactorial = 0;
    int flagFactorial2 = 0;
    do
    {
        printf("1.Ingresar el primer operando(A=%0.2f)\n", operando1);
        printf("2.Ingresar el segundo operando(B=%0.2f)\n", operando2);
        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            //ingreso del primer operando
            printf("Ingrese el primer operando: ");
            scanf("%f", &operando1);
            break;
        case 2:
            //ingreso del segundo operando

            printf("Ingrese el segundo operando: ");
            scanf("%f", &operando2);
            break;
        case 3:
            //Calcula todas las Operaciones
            resultadoSuma = suma(operando1, operando2);
            resultadoResta = resta(operando1, operando2);
            resultadoMultiplicacion = multiplicacion(operando1, operando2);
            if(operando2 == 0.0)
            {
                flagDivision = 1;
            }
            else
            {
                flagDivision = 0;//reset de booleanos a 0
                resultadoDivision = division(operando1, operando2);
            }
            if (operando1 - (int)operando1 > 0 || operando1 < 0)
            {
                flagFactorial = 1;
            }
            else
            {
                flagFactorial = 0;//reset de booleanos a 0
                factorialOp1 = factorial(operando1);

            }
            if (operando2 - (int)operando2 > 0 || operando2 < 0)
            {
                flagFactorial2 = 1;
            }
            else
            {
                flagFactorial2 = 0;
                factorialOp2 = factorial(operando2);
            }
            break;
        case 4:
           //Muestra resultados
            printf("El resultado de la Suma es: %0.2f\n", resultadoSuma);
            printf("El resultado de la Resta es: %0.2f\n",resultadoResta);
            printf("El resultado de la Multiplicacion es: %0.2f\n",resultadoMultiplicacion);
            if(flagDivision == 1)
            {
                printf("Error no se puede dividir por 0\n");

            }
            else
            {
                printf("El resultado de la Division es: %0.2f\n",resultadoDivision);
            }
            if(flagFactorial == 1)
            {
                printf("No es posible realizar el factorial de un numero no natural\n");

            }
            else
            {
                printf("El factorial del primer operando es: %I64d\n", factorialOp1);
            }
            if(flagFactorial2 == 1)
            {
                printf("No es posible realizar el factorial de un numero no natural\n");

            }
            else
            {
                printf("El factorial del segundo operando es: %I64d\n", factorialOp2);
            }
            break;
        case 5:
            //cambia el valor de Continuar para salir del programa.
            continuar = 'n';
            break;
        default:
            //Opciones invalidas
            printf("Ingrese una opcion valida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(continuar == 's');
    return 0;
}
