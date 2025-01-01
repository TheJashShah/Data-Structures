#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int data;
    struct node *next;

}node;

typedef struct{

    node *topNode;

}Stack;

node * CreateNode(int data) {

    node * newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

node * AddNode(node *topNode, int data) {

    // PUSH

    node *temp = topNode;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    node *newNode = CreateNode(data);

    temp->next = newNode;

    return topNode;
}

node * DeleteNode(node *topNode) {

    // POP

    if(topNode == NULL) {
        printf("Stack is already empty. \n");
        return NULL;
    }

    if(topNode->next == NULL) {
        printf("%d is popped from Stack. \n", topNode->data);
        free(topNode);
        return NULL;
    }

    node *temp = topNode;

    topNode = topNode->next;

    printf("%d is popped from Stack. \n", temp->data);

    free(temp);

    return topNode;
}

int peek(node *topNode) {

    if(topNode == NULL) {
        printf("Stack is Empty. \n");
        return -1;
    }

    return topNode->data;
}

void printList(Stack * s) {

    printf("The Stack from Top is: \n");

    node *temp = s->topNode;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->topNode = NULL;

    int loop = 1, choice, data, peeked;

    while(loop) {
        printf("\n");
        printf("1. Push to Stack. \n");
        printf("2. Pop from Stack. \n");
        printf("3. Peek. \n");
        printf("4. Display Stack. \n");
        printf("5. Exit. \n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {

        case 1:

            printf("Enter your data: \n");
            scanf("%d", &data);

            if(s->topNode == NULL) {
                s->topNode = CreateNode(data);

            } else {
                s->topNode = AddNode(s->topNode, data);
            }

            printf("%d is pushed to Stack. \n", data);

            break;

        case 2:

            s->topNode = DeleteNode(s->topNode);

            break;

        case 3:

            peeked = peek(s->topNode);

            printf("The Topmost data is %d. \n", peeked);

            break;

        case 4:

            printList(s);

            break;

        case 5:
            loop = 0;
            break;

        default:
            printf("Enter only one of the above options. \n");
            break;

        }
    }

    free(s);
    return 0;
}


/*
IMPLEMENTATION OF STACK AS LINKED LIST.
*/
