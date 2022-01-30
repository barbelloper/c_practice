#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DEGREE 50
#define MAX(a,b) ((a>b)?a:b)

typedef struct polynomial
{
    int degree;
    float coef[MAX_DEGREE];
}polynomial;

static polynomial multPoly(polynomial A, polynomial B);
static void printPoly(polynomial A);
static polynomial addPoly(polynomial A, polynomial B);

void printPoly(polynomial A)
{
    int i = 0; 
    int degree = 0;
    degree = A.degree;
    for (i = 0; i <= A.degree; i++)
    {
        printf("%0.2fx^%d", A.coef[i], degree--);
        if (i < A.degree)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

polynomial addPoly(polynomial A, polynomial B)
{
    polynomial C;
    memset(&C, 0x00, sizeof(polynomial));
    int A_index = 0, B_index = 0, C_index = 0;
    int A_degree = A.degree, B_degree = B.degree;

    C.degree = MAX(A.degree, B.degree);

    while((A_index <= A.degree) && (B_index <= B.degree))
    {
        if (A_degree > B_degree)
        {
            C.coef[C_index++] = A.coef[A_index++];
            A_degree --;
        }
        else if (A_degree == B_degree)
        {
            C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
            A_degree --;
            B_degree --;
        }
        else
        {
            C.coef[C_index++] = B.coef[B_index++];
            B_degree--;
        }
    }
    return C;
}

polynomial multTerm(polynomial A, float coef, int degree)
{
    int i = 0;
    polynomial dest;
    memset(&dest, 0x00, sizeof(polynomial));
    dest.degree = A.degree + degree;

    for(i = 0; i <= A.degree; i ++)
    {
        dest.coef[i] = A.coef[i] * coef;
    }
    for(i = A.degree + 1; i <= dest.degree; i++)
    {
        dest.coef[i] = 0;
    }
    return dest;
}

polynomial multPoly(polynomial A, polynomial B)
{
}

int main(void)
{
    polynomial A;
    polynomial B;
    polynomial C;
    polynomial D;
    int i;
    printf("input A degree: ");
    scanf("%d", &A.degree);
    getchar();
    printf("\n");
    for(i = 0; i <= A.degree; i++)
    {
        printf("input the coefficient of the %d-order term of A: ", (A.degree)-i);
        scanf("%f",&A.coef[i]);
        getchar();
    }
    printf("input B degree: ");
    scanf("%d", &B.degree);
    getchar();
    printf("\n");
    for(i = 0; i <= B.degree; i++)
    {
        printf("input the coefficient of the %d-order term of B: ", (B.degree)-i);
        scanf("%f",&B.coef[i]);
        getchar();
    }
    fflush(stdin);
    C = addPoly(A,B);
    //D = multPoly(A,B);
    printf("\n A(x) = "); printPoly(A);
    printf("\n B(x) = "); printPoly(B);
    printf("\n C(x) = "); printPoly(C);
    //printf("\n D(x) = "); printPoly(D);
    getchar();
    return 0;
}