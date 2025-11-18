#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert(struct Node *head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* sortList(struct Node *head) {
    struct Node *i = head, *j;
    int temp;

    while (i && i->next) {
        j = i->next;
        while (j) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* concatenate(struct Node *h1, struct Node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct Node *temp = h1;
    while (temp->next)
        temp = temp->next;

    temp->next = h2;
    return h1;
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 into List 1\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list1 = insert(list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list2 = insert(list2, value);
                break;

            case 3:
                display(list1);
                break;

            case 4:
                display(list2);
                break;

            case 5:
                list1 = sortList(list1);
                break;

            case 6:
                list1 = reverseList(list1);
                break;

            case 7:
                list1 = concatenate(list1, list2);
                break;

            case 8:
                exit(0);
        }
    }
}
