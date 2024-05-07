#include <stdio.h>

/*int main()
{
    int a = 0, b = 1, c = 2;
    int *ptr;

    ptr = &a;
    printf("Enter an integer: ");
    scanf("%d", &*ptr); // input: 26
    printf("\na = %d", a);
    printf("\nb = %d", b);
    printf("\nc = %d", c);
    printf("\n*ptr = %d", *ptr);

    ptr = &b;
    printf("\n\nEnter an integer: ");
    scanf("%d", &*ptr); // input: -9
    printf("\na = %d", a);
    printf("\nb = %d", b);
    printf("\nc = %d", c);
    printf("\n*ptr = %d", *ptr);

    ptr = &c;
    printf("\n\nEnter an integer: ");
    scanf("%d", &*ptr); // input: -3
    printf("\na = %d", a);
    printf("\nb = %d", b);
    printf("\nc = %d", c);
    printf("\n*ptr = %d", *ptr);
    return 0;
}*/

/*int main()
{   
    int a = 3,
        b;

    int *aPtr = &a,
        *bPtr = &b;

    *bPtr = *aPtr + 900;
    printf("\nValue of b is %d", b);
    printf("\nValue of *bPtr is %d \n\n", *bPtr);
    *bPtr = (*aPtr)++;

    printf("\nValue of b is %d", b);
    printf("\nValue of *bPtr is %d \n\n", *bPtr);
    *bPtr = ++*aPtr;

    printf("\nValue of b is %d", b);
    printf("\nValue of *bPtr is %d \n\n", *bPtr);
    return 0;
}*/

// This program shows the effect of pass-by-address in function calls.

/*int main()
{
    int Shirts = 100;
    int Pants = 200;
    void Deposit(int , int );
    void Pickup(int * , int*);
    printf("When starting, within main():\n");
    printf("\tShirts = %d \n", Shirts);
    printf("\tPants = %d \n", Pants);
    Deposit(Shirts, Pants);
    printf("\n\nAfter calling Deposit(), within main():\n");
    printf("\tShirts = %d \n", Shirts);
    printf("\tPants = %d \n", Pants);
    Pickup(&Shirts, &Pants);
    printf("\n\nAfter calling Pickup(), within main():\n");
    printf("\tShirts = %d \n", Shirts);
    printf("\tPants = %d \n", Pants);
    return 0;
}
void Deposit(int s, int p)
{
    s = 8; p = 23;
    printf("\nWithin Deposit()");
    printf("\n\tShirts = %d", s);
    printf("\n\tPants = %d", p);
}
void Pickup(int *sht, int *pt)
{
    *sht = 8; *pt = 23;
    printf("\nWithin Pickup()");
    printf("\n\tShirts = %d", *sht);
    printf("\n\tPants = %d", *pt);
}*/


#include <math.h>

void frac(float num, int *intPart, float *fractionPart) {
    *intPart = num;
    *fractionPart = num - *intPart;
}

int main() {
    float num = 65.82018;
    int intPart;
    float fractionPart;
    frac(num, &intPart, &fractionPart);
    printf("Integer part: %d\n", intPart);
    printf("Fraction part: %f\n", fractionPart);
    return 0;
}

