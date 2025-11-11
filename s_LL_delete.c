#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* createList() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, data, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted from first %d\n", temp->data);
    free(temp);

    return head;
}
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        printf("Deleted from last %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted from last %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}
struct Node* delete_specific(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        printf("Deleted data %d\n", temp->data);
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in list.\n", key);
        return head;
    }
    prev->next = temp->next;
    printf("Deleted data %d\n", temp->data);
    free(temp);
    return head;
}int main() {
    struct Node* head = NULL;
    int choice, key;
    while (1) {
        printf("\n---- Singly Linked List Menu ----\n");
        printf("1. Create Linked List\n");
        printf("2. Display List\n");
        printf("3. Delete First Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Delete Specific Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = deleteFirst(head);
                break;
            case 4:
                head = deleteLast(head);
                break;
            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                head = delete_specific(head, key);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}




