#include <stdio.h>
#include <math.h>

// Definición de la función a integrar: x^2
double fx(double x) {
  return (x*x);
}

// Obtener el límite inferior de integración
double obtener_limite_inferior() {
  double limite_inferior;
  printf("Ingrese el límite inferior de integración: ");
  scanf("%lf", &limite_inferior);
  return limite_inferior;
}

// Obtener el límite superior de integración
double obtener_limite_superior() {
  double limite_superior;
  printf("Ingrese el límite superior de integración: ");
  scanf("%lf", &limite_superior);
  return limite_superior;
}

// Obtener el número de intervalos
int obtener_numero_intervalos() {
  int numero_intervalos;
  printf("Ingrese el número de intervalos: ");
  scanf("%d", &numero_intervalos);

  // Verificar que el número de intervalos sea positivo
  if (numero_intervalos <= 0) {
    printf("Error: El número de intervalos debe ser mayor que cero.\n");
    return -1;
  }

  return numero_intervalos;
}

// Método de integración por trapecios con interpolación
double integracion_trapecios(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n;  // Ancho del subintervalo
  double integral_acumulada = 0.5 * (f(a) + f(b));  // Inicializa la integral con los extremos

  // Calcula la integral utilizando la regla de los trapecios con interpolación
  for (int i = 1; i < n; i++) {
    integral_acumulada += f(a + i * h);  // Suma la altura de cada subintervalo
  }

  integral_acumulada *= h;  // Multiplica por el ancho del subintervalo

  return integral_acumulada;
}

int main() {
  // Obtener los límites de integración y el número de intervalos del usuario
  double limite_inferior = obtener_limite_inferior();
  double limite_superior = obtener_limite_superior();
  int numero_intervalos = obtener_numero_intervalos();

  // Validar que los límites de integración sean válidos
  if (limite_inferior >= limite_superior) {
    printf("Error: El límite inferior debe ser menor que el límite superior.\n");
    return 1;
  }

  // Calcular la aproximación de la integral
  double integral_aproximada = integracion_trapecios(fx, limite_inferior, limite_superior, numero_intervalos);

  // Mostrar el resultado
  printf("Aproximación de la integral de f(x) = x^2 en el intervalo [%.2lf, %.2lf] usando %d intervalos: %.16lf\n",
         limite_inferior, limite_superior, numero_intervalos, integral_aproximada);

  return 0;
}
