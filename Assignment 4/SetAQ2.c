
**Implement a list library (singlylist.h) for a singly linked list with Append, Insert, Search and Delete
operations.**

b) Write a menu driven program for the following operations.
i. Reverse a linked list and display it.
ii. Accept an element from user and Concatenate it with a created link list.
iii. Merge two linked list and display it.


<Signlylist_b.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Reverse linked list (but return copy so original remains unchanged)
struct Node* reverseCopy(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* copy = NULL;

    // First copy list
    while (current != NULL) {
        insertEnd(&copy, current->data);
        current = current->next;
    }

    // Now reverse the copied list
    current = copy;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; // head of reversed copy
}

// Concatenate single element
void concatenateElement(struct Node** head, int data) {
    insertEnd(head, data);
}

// Merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }
    return result;
}


<main_b.c>

#include "Singlylist_b.h"
int main() {
    struct Node* firstList = NULL;
    struct Node* secondList = NULL;
    int choice, n, val;

    while (1) {
        printf("\n1. Reverse First Linked List (Display Only)\n");
        printf("2. Concatenate Element with First Linked List\n");
        printf("3. Merge First and Second Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                firstList = NULL;
                printf("Enter number of elements in first list: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    insertEnd(&firstList, val);
                }
                printf("Original First List: ");
                displayList(firstList);

                printf("Reversed First List: ");
                struct Node* reversed = reverseCopy(firstList);
                displayList(reversed);
                break;

            case 2:
                if (firstList == NULL) {
                    printf("First list is empty! Create it first (Option 1).\n");
                } else {
                    printf("Enter element to concatenate: ");
                    scanf("%d", &val);
                    concatenateElement(&firstList, val);
                    printf("After Concatenation: ");
                    displayList(firstList);
                }
                break;

            case 3:
                if (firstList == NULL) {
                    printf("First list is empty! Create it first (Option 1).\n");
                } else {
                    secondList = NULL;
                    printf("Enter number of elements in second list: ");
                    scanf("%d", &n);
                    printf("Enter elements: ");
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &val);
                        insertEnd(&secondList, val);
                    }
                    printf("Second List: ");
                    displayList(secondList);

                    firstList = mergeLists(firstList, secondList);
                    printf("After Merging: ");
                    displayList(firstList);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
