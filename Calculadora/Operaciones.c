
float suma(float operando1,float operando2)
{
    return operando1 + operando2;
}

float resta(float operando1, float operando2)
{
    return operando1 - operando2;
}

float division(float operando1, float operando2)
{

    return operando1 / operando2;
}
float multiplicacion(float operando1,float operando2)
{
    return operando1 * operando2;
}
long long int factorial(int operando1)
{
    int resultado;
    if(operando1 == 0 || operando1 == 1)
    {
        resultado = 1;
    }
    else
    {
        resultado = operando1 * factorial(operando1 - 1);
    }
    return resultado;
}

