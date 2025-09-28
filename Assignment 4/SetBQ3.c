c) Write a program that adds two single variable polynomials. Each polynomial should be
represented as a list with linked list implementation.


#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
};

void appendPoly(struct PolyNode **head, int coeff, int exp) {
    struct PolyNode *newNode = malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*head == NULL) *head = newNode;
    else {
        struct PolyNode *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayPoly(struct PolyNode *head) {
    while (head) {
        printf("%dx^%d \n", head->coeff, head->exp);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

void addPolynomials(struct PolyNode *p1, struct PolyNode *p2, struct PolyNode **res) {
    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            appendPoly(res, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            appendPoly(res, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            appendPoly(res, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) { appendPoly(res, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { appendPoly(res, p2->coeff, p2->exp); p2 = p2->next; }
}


#include "polynomial.h"
int main() {
    struct PolyNode *poly1 = NULL;
    struct PolyNode *poly2 = NULL;
    struct PolyNode *sum = NULL;

    int choice, coeff, exp;

    while (1) {
      
        printf("ENTER YOUR CHOICE : \n1. Add Term to Poly 1\n");
        printf("2. Add Term to Poly 2\n");
        printf("3. Display Poly 1\n");
        printf("4. Display Poly 2\n");
        printf("5. Add Polys and Display Result\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and exponent (e.g., 5 2 for 5x^2): ");
                scanf("%d %d", &coeff, &exp);
                appendPoly(&poly1, coeff, exp);
                printf("\n");
                break;
            case 2:
                printf("Enter coefficient and exponent (e.g., 3 1 for 3x^1): ");
                scanf("%d %d", &coeff, &exp);
                appendPoly(&poly2, coeff, exp);
                printf("\n");
                break;
            case 3:
                printf("\nPolynomial 1: ");
                displayPoly(poly1);
                break;
            case 4:
                printf("\nPolynomial 2: ");
                displayPoly(poly2);
                break;
            case 5:
                addPolynomials(poly1, poly2, &sum);
                printf("Sum of Polynomials is  : ");
                displayPoly(sum);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!!!.\n");
        }
    }

    return 0;
}
