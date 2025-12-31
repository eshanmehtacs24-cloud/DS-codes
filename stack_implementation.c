#include<stdio.h>
#define Max 4
int top=-1,sta[Max];
void push(int ele){
    if(top==Max-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    sta[top]=ele;
}
int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    int pop_ele=sta[top];
    top--;
    return pop_ele;
}
void display(){
    printf("Stack:");
    for(int i=0;i<=top;i++){
        printf("%d ",sta[i]);
    }
    printf("\n");
}
int main(){
    int choice,element;
    while(1){
        printf("Enter choice: \n1 push \n 2 pop \n 3 return");
                              scanf("%d",&choice);
                              switch(choice)
                              {
                                case 1:printf("Enter element to be inserted:");
                                        scanf("%d",&element);
                                        push(element);
                                        display();
                                        break;
                                case 2: {
                                    int poped1=pop();
                                        if(poped1!=-1){
                                            printf("Pop element is =%d",poped1);
                                            display();
                                        }
                                }
                                        break;
                                case 3: return 0;

                              }
    }
}

