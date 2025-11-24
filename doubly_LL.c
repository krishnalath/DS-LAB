#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// (a) CREATE DOUBLY LINKED LIST
void createList() {
    int n, value, i;
    struct Node *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = NULL; // reset list

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL)
            head = newNode;
        else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }
}

// (b) INSERT TO THE LEFT OF A NODE HAVING A SPECIFIC VALUE
void insertLeft(int key, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }

    struct Node* newNode = createNode(value);

    // Insert before head
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        printf("Inserted %d to the left of %d\n", value, key);
        return;
    }

    // Insert before middle node
    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;

    printf("Inserted %d to the left of %d\n", value, key);
}

// (c) DELETE NODE BASED ON A SPECIFIC VALUE
void deleteValue(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    // deleting head
    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        printf("Deleted %d\n", temp->data);
        free(temp);
        return;
    }

    // deleting last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        printf("Deleted %d\n", temp->data);
        free(temp);
        return;
    }

    // deleting middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted %d\n", temp->data);
    free(temp);
}

// (d) DISPLAY LIST
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, key, value;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left of a Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;

            case 2:
                printf("Enter node value to insert left of: ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertLeft(key, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteValue(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
