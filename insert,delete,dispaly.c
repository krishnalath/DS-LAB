#include <stdio.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX - 1)
        {
        printf("QUEUE FULL!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d inserted into the queue.\n", element);
    }
}

int dequeue() {
    int element;
    if (front == -1 || front > rear) {
        printf("QUEUE IS EMPTY!\n");
        return -1;
    } else {
        element = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return element;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("QUEUE IS EMPTY!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                element = dequeue();
                if (element != -1)
                    printf("The element deleted is: %d\n", element);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

