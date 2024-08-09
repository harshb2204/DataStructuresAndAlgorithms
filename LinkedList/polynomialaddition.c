//polyaddition
#include <stdio.h>
#include <stdlib.h>

struct Poly
{
    int coeff;
    int exp;
    struct Poly *next;
};
void displayPoly(struct Poly *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d ", poly->coeff, poly->exp);
        if (poly->next != NULL)
            printf("+ ");
        poly = poly->next;
    }
    printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    struct Poly *poly3 = NULL, *p3 = NULL;

    while (p1 != NULL || p2 != NULL)
    {
        if (poly3 == NULL)
        {
            poly3 = p3 = (struct Poly *)malloc(sizeof(struct Poly));
        }
        else
        {
            p3->next = (struct Poly *)malloc(sizeof(struct Poly));
            p3 = p3->next;
        }

        if (p1 != NULL && p2 != NULL)
        {
            if (p1->exp > p2->exp)
            {
                p3->exp = p1->exp;
                p3->coeff = p1->coeff;
                p1 = p1->next;
            }
            else if (p1->exp < p2->exp)
            {
                p3->exp = p2->exp;
                p3->coeff = p2->coeff;
                p2 = p2->next;
            }
            else
            {
                p3->exp = p1->exp;
                p3->coeff = p1->coeff + p2->coeff;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        else if (p1 != NULL)
        {
            p3->exp = p1->exp;
            p3->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p2 != NULL)
        {
            p3->exp = p2->exp;
            p3->coeff = p2->coeff;
            p2 = p2->next;
        }

        p3->next = NULL;
    }

    // Remove zero coefficients and free memory

    return poly3;
}

int main()
{

    struct Poly *poly1 = (struct Poly *)malloc(sizeof(struct Poly));
    poly1->coeff = 7;
    poly1->exp = 5;
    poly1->next = (struct Poly *)malloc(sizeof(struct Poly));
    poly1->next->coeff = 6;
    poly1->next->exp = 1;
    poly1->next->next = (struct Poly *)malloc(sizeof(struct Poly));
    poly1->next->next->coeff = 5;
    poly1->next->next->exp = 0;
    poly1->next->next->next = NULL;

    struct Poly *poly2 = (struct Poly *)malloc(sizeof(struct Poly));
    poly2->coeff = 8;
    poly2->exp = 3;
    poly2->next = (struct Poly *)malloc(sizeof(struct Poly));
    poly2->next->coeff = 4;
    poly2->next->exp = 2;
    poly2->next->next = (struct Poly *)malloc(sizeof(struct Poly));
    poly2->next->next->coeff = 4;
    poly2->next->next->exp = 1;
    poly2->next->next->next = NULL;

    // Displaying polynomials
    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    // Adding polynomials
    struct Poly *result = add(poly1, poly2);

    // Displaying the result
    printf("Result: ");
    displayPoly(result);

    // Freeing memory
    free(poly1);
    free(poly2);
    free(result);

    return 0;
}