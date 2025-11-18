#include <stdio.h>
#define n 5
int arr[n];
int front=-1;
int rear=-1;

int isFull(){
    return (rear+1)%n==front;
}
int isEmpty(){
    return (front==-1 && rear==-1);
}

void insert(int x){
    if(isFull()){
        printf("Queue is full , overflow");
    }
    else{
        front=0;
        rear=(rear+1)%n;
        arr[rear]=x;
        printf("%d is inserted",x);
    }
}

void delete(){
    if(isEmpty()){
        printf("Queue is empty , underflow");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=front+1;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty");
    }
    else{

        for(int i=front;i<=rear;i++){
            printf("%d ",arr[i]);
        }
    }
}

int main(){
    int choice;
    int value;
    int flag=1;
    while(flag!=0){
    printf("\n1 for insert\n2 for delete\n3 for display\n4 for exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("enter value: ");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:delete();
        break;
        case 3:display();
        break;
        case 4: flag=0;
    }
}
}

