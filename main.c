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

double mean_value(const unsigned int * A, unsigned int Size);
unsigned int find_min(const unsigned int * A, unsigned Size);
float find_max(const float * B, unsigned int Size);

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

    double average_value;
    unsigned int min_value;
    float max_value;

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

    average_value = mean_value(A, Size);
    min_value = find_min(A, Size);
    max_value = find_max(B, Size);

    printf("\n\n--- Результати виконання ЛР 4 (Частина 1) ---");
    printf("\nСереднє значення елементів масиву A: %.2lf", average_value);
    printf("\nМінімальне значення елементів масиву A: %u", min_value);
    printf("\nМаксимальне значення елементів масиву B: %.2f\n", max_value);

    free(A);
    free(B);

    return 0;
}

//Опис Функцій
// Автоматичне заповнення за формулою: A[j] = Size - (j + 1)
void fill_int_array(unsigned int * A, unsigned int Size)
{
    unsigned int j;
    for (j = 0; j < Size; j++) {
        A[j] = Size - (j + 1);
    }
}

// Автоматичне заповнення за формулою: B[j] = 5.0 * j + 5.0
void fill_float_array(float * B, unsigned int Size)
{
    unsigned int j;
    for (j = 0; j < Size; j++) {
        B[j] = 5.0f * (float)j + 5.0f;
    }
}

void print_int_array(const unsigned int * A, unsigned int Size)
{
    unsigned int j;
    printf("\n\nМасив цілих чисел без знака (A):\n");
    for (j = 0; j < Size; j++) {
            printf("%5u", A[j]);
    }
}

void print_float_array(const float * B, unsigned int Size)
{
    unsigned int j;
    printf("\n\nМасив дійсних чисел (B):\n");
    for (j = 0; j < Size; j++) {
            printf("%7.2f", B[j]);
    }
}

unsigned int sum(const unsigned int * A, unsigned int Size)
{
    unsigned int j, S = 0;
    for (j = 0; j < Size; j++) {
            S += A[j];
    }
    return S;
}

double product(const float * B, unsigned int Size)
{
    unsigned int j;
    double M = 1.0;
    for (j = 0; j < Size; j++) {
            M *= B[j];
    }
    return M;
}

double mean_value(const unsigned int * A, unsigned int Size)
{
    if (Size == 0) return 0.0;
    unsigned int total_sum = sum(A, Size);
    return (double)total_sum / Size;
}

unsigned int find_min(const unsigned int * A, unsigned int Size)
{
    unsigned int j;
    unsigned int min = A[0];
    for (j = 1; j < Size; j++){
        if (A[j] < min){
            min = A[j];
        }
    }
    return min;
}

float find_max(const float * B, unsigned int Size)
{
    unsigned int j;
    float max = B[0];
    for (j = 1; j < Size; j++){
        if (B[j] > max){
            max = B[j];
        }
    }
    return max;
}
