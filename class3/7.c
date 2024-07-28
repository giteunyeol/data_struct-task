#include <stdio.h>

typedef struct complex
{
    float real;       
    float imaginary;  
} complex;

// 두 복소수를 더하는 함수
complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

int main(void)
{
    complex a, b;
    scanf("%f %f", &a.real, &a.imaginary); // complex a에 scanf
    scanf("%f %f", &b.real, &b.imaginary); // complex b에 scanf
    
    complex result = add(a, b);

    printf("%f %f", result.real, result.imaginary);

    
    return 0;
}
