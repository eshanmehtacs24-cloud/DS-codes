#include<stdio.h>
#define max 5
int C_queue[max],front=-1,rear=-1;
void insert(int ele){
    if(rear==max-1){
        printf("Queue Overflow");
        return;
    }
    else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        C_queue[rear]=ele;
    }
    else{
        rear=(rear+1)%max;
        C_queue[rear]=ele;
    }
}
int delete(){
    if(front==-1){
        printf("Queue underflow");
        return -1;
    }
    else if(front==rear){
        int deleted=C_queue[front];
        front=-1;
        rear=-1;
        return deleted;
    }
    else{
        int deleted=C_queue[front];
        front=(front+1)%max;
        return deleted;
    }
}
void display(){
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d ",C_queue[i]);
        }
    }
    else{
        for(int i=front;i<max;i++){
            printf("%d ",C_queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",C_queue[i]);
        }
    }
}
int main(){
    int deleted,choice,element;
    while(1){
    printf("\nEnter choice:");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter element to be inserted:");
        scanf("%d",&element);
        insert(element);
        break;

    case 2:
         deleted=delete();
        printf("\n Removed element=%d",deleted);
        break;

    case 3:
        display();
        break;

    case 4:
        return 0;
    default:
        printf("Invalid choice.Try again");
    }
}

}