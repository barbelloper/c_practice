#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct 
{
   int degree;
   float coef[MAX_DEGREE];
} polynomial;

static polynomial addPoly(polynomial A, polynomial B);
static polynomial multTerm(polynomial A, float coef, int degree);
static polynomial multPoly(polynomial A, polynomial B);
static void printPoly(polynomial);

polynomial addPoly(polynomial A, polynomial B) 
{
   polynomial C;
   int A_index = 0, B_index = 0, C_index = 0;
   int A_degree = A.degree, B_degree = B.degree;
   C.degree = MAX(A.degree,B.degree);
   while((A_index <= A.degree) && (B_index <= B.degree)) 
   {
	  if(A_degree > B_degree) 
	  {
		 C.coef[C_index++] = A.coef[A_index++];
		 A_degree--;
	  }
	  else if (A_degree == B_degree) 
	  {
		 C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
		 A_degree--;
		 B_degree--;
	  }
	  else 
	  {
		 C.coef[C_index++] = B.coef[B_index++];
		 B_degree--;
	  }
   }
   return C;
}

void printPoly(polynomial P) 
 {
   int i, degree;
   degree = P.degree;
   for (i = 0; i <= P.degree; i++) 
   {
	  printf("%0.3fx^%d", P.coef[i], degree--);
	  if(i<P.degree) printf(" +");
   }
   printf("\n");
}

polynomial multTerm(polynomial A, float coef, int degree)
{
   int i;
   polynomial Des;
   Des.degree = A.degree + degree;

   for(i = 0; i <= A.degree; i ++) 
   {
	  Des.coef[i] = A.coef[i] * coef;
   }
   for(i = A.degree+1; i <= Des.degree; i++) 
   {
	  Des.coef[i] = 0;
   }
   return Des;
}

polynomial multPoly(polynomial A, polynomial B) 
{
   int i;
   polynomial *mult = (polynomial *)malloc(sizeof(polynomial)*(B.degree+1));
   polynomial LastMult = {0,0};
   for(i = 0; i <= B.degree; i++) 
   {
	  mult[i] = multTerm(A, B.coef[i], (B.degree)-i);
	  LastMult = addPoly(LastMult, mult[i]);
   }
   return LastMult;
   free(mult);
}

int main (void) 
{
   polynomial A;
   polynomial B;
   polynomial C;
   polynomial D;
   int i;
   printf("input A degree : ");
   scanf("%d", &A.degree);
   getchar();
   printf("\n");
   for(i = 0; i <= A.degree; i++) 
   {
	  printf("input the coefficient of the %d-order term of A: ", (A.degree)-i);
	  scanf("%f",&A.coef[i]);
	  getchar();
   }
   printf("input B degree : ");
   scanf("%d",&B.degree);
   printf("\n");
   for(i = 0; i <= B.degree; i++) 
   {
	  printf("input the coefficient of the %d-order term of B: ", (B.degree)-i);
	  scanf("%f",&B.coef[i]);
	  getchar();
   }
   fflush(stdin);
   C = addPoly(A,B);
   D = multPoly(A,B);
   printf("\n A(x) ="); printPoly(A);
   printf("\n B(x) ="); printPoly(B);
   printf("\n C(x) ="); printPoly(C);
   printf("\n D(x) ="); printPoly(D);
   getchar();
   return 0;
}



 