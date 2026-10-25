#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

//Прототипи
void fill_int_array(unsigned int * A, unsigned int Size);
void fill_float_array(float * B, unsigned int Size);
void print_int_array(const unsigned int * A, unsigned int Size);
void print_float_array(const float * B, unsigned int Size);

unsigned int sum(const unsigned int * A, unsigned int Size);
double product(const float * B, unsigned int Size);

//Опис функції main()
int main()
{
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    setlocale(LC_ALL, "Ukrainian");

    unsigned int * A;
    float * B;

    unsigned int Size;
    unsigned int amount;
    double mult;

    printf("Введіть розмір масиву: ");
    if (scanf("%u", &Size) != 1 || Size == 0) {
        printf("Некоректний розмір масиву.\n");
        return 1;
    }

    A = (unsigned int *) calloc(Size, sizeof(unsigned int));
    B = (float *) malloc(Size * sizeof(float));

    if (A == NULL || B == NULL) {
        printf("Пам'ять не було виділено!\n");
        exit(0);
    }

    fill_int_array(A, Size);
    fill_float_array(B, Size);

    print_int_array(A, Size);
    print_float_array(B, Size);

    amount = sum(A, Size);
    mult = product(B, Size);

    printf("\n\nСума елементів масиву A = %u", amount);
    printf("\nДобуток елементів масиву B = %.3lf\n", mult);

    free(A);
    free(B);

    return 0;
}

//Опис Функцій
void fill_int_array(unsigned int * A, unsigned int Size)
{
    unsigned int j, temp;
    printf("\n\nВведіть значення елементів масиву цілих чисел:\n");
    for (j = 0; j < Size; j++) {
        printf("A[%u] = ", j);
        scanf("%u", &temp);
        A[j] = temp;
    }
}

void fill_float_array(float * B, unsigned int Size)
{
    unsigned int j;
    float temp;
    printf("\n\nВведіть значення елементів масиву дійсних чисел:\n");
    for (j = 0; j < Size; j++) {
        printf("B[%u] = ", j);
        scanf("%f", &temp);
        B[j] = temp;
    }
}

void print_int_array(const unsigned int * A, unsigned int Size)
{
    unsigned int j;
    printf("\n\nМасив цілих чисел без знака (A):\n");
    for (j = 0; j < Size; j++) printf("%5u", A[j]);
}

void print_float_array(const float * B, unsigned int Size)
{
    unsigned int j;
    printf("\n\nМасив дійсних чисел (B):\n");
    for (j = 0; j < Size; j++) printf("%7.2f", B[j]);
}

unsigned int sum(const unsigned int * A, unsigned int Size)
{
    unsigned int j, S = 0;
    for (j = 0; j < Size; j++) S += A[j];
    return S;
}

double product(const float * B, unsigned int Size)
{
    unsigned int j;
    double M = 1.0;
    for (j = 0; j < Size; j++) M *= B[j];
    return M;
}
