#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int data;
    struct node * next;

}node;

node * createNode(int data) {

    node * temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void printList(node *head) {

    node * ptr = head;

    printf("The List is: \n");

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

node * addNode(node *head, int data) {

    node *ptr = head;

    node * newNode = createNode(data);

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;

    return head;
}
// ADDING AN ELEMENT TO THE LIST, OR INSERTION AT THE END

node * insertatFirst(node *head, int data) {

    node * newNode = createNode(data);

    newNode->next = head;

    return newNode;
}
node * insertatIndex(node *head, int data, int index) {

    node *newNode = createNode(data);

    node *ptr = head;
    int i = 0;

    while(i != index - 1) {
        ptr = ptr->next;
        i++;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;

    return head;
}

node * deleteAtEnd(node *head) {

    node *p = head;
    node *q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;

    printf("Element with value %d is deleted. \n", q->data);

    free(q);

    return head;
}

node * deleteAtStart(node *head) {

    node *temp = head;
    head = head->next;

    printf("Element with value %d is deleted. \n", temp->data);

    free(temp);

    return head;
}

node * deleteAtIndex(node *head, int index) {

    node *ptr = head;
    int i = 0;

    while(i != index - 1) {
        ptr = ptr->next;
        i++;
    }

    node *temp = ptr->next;
    ptr->next = temp->next;

    printf("Element with value %d is deleted. \n", temp->data);

    free(temp);

    return head;
}

void splitAlternatively(node *head) {

    if(head == NULL || head->next == NULL) {
        printf("Must have at least 2 nodes to split. \n");
        return;
    }

    node *A = NULL;
    node *B = NULL;
    int toggle = 0;

    node *current = head;

    while(current != NULL) {

        if(toggle == 0) {
            if(A == NULL) {
                A = createNode(current->data);
            } else {
                A = addNode(A, current->data);
            }
            toggle = 1;
        } else {
            if(B == NULL) {
                B = createNode(current->data);
            } else {
                B = addNode(B, current->data);
            }
            toggle = 0;
        }

        current = current->next;
    }

    printList(A);
    printList(B);
}

int main() {

    int len = 1, loop = 1, data, choice, index;

    node * head = createNode(-1);

    printf("Enter the value of the head of the List: \n");
    scanf("%d", &data);

    head->data = data;

    while(loop) {
        printf("\n");
        printf("1. Add an element/insert at the end. \n");
        printf("2. Add an element at the start of the list. \n");
        printf("3. Add an element at an index. \n");
        printf("4. Delete an element from the end of the List. \n");
        printf("5. Delete an element from the start of the List. \n");
        printf("6. Delete an element at an index. \n");
        printf("7. Split the List into two Lists with alternate data. \n");
        printf("8. Display the List. \n");
        printf("9. Exit. \n");

        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter the value: \n");
            scanf("%d", &data);

            head = addNode(head, data);
            printf("The element is added. \n");
            len++;
            break;

        case 2:
            printf("Enter the value: \n");
            scanf("%d", &data);

            head = insertatFirst(head, data);
            printf("The element is added. \n");
            len++;
            break;

        case 3:
            printf("Enter the value: \n");
            scanf("%d", &data);

            printf("Enter your index: \n");
            scanf("%d", &index);

            if(index == 0) {
                head = insertatFirst(head, data);
                printf("The element is added. \n");

            } else if(index >= len) {
                printf("This index does not exist in the List. \n");

            } else {
                head = insertatIndex(head, data, index);
                printf("The element is added. \n");
            }

            len++;
            break;

        case 4:

            if(len == 1) {
                printf("There is only node in the List, deletion cannot occur. \n");
            } else{

                head = deleteAtEnd(head);
                len--;
            }

            break;

        case 5:

            if(len == 1) {
                printf("There is only node in the List, deletion cannot occur. \n");
            } else{

                head = deleteAtStart(head);
                len--;
            }

            break;

        case 6:

            if(len == 1){
                printf("There is only node in the List, deletion cannot occur. \n");

            } else {
                printf("Enter your index: \n");
                scanf("%d", &index);

                if(index == 0) {
                    head = deleteAtStart(head);
                    len--;

                } else if(index >= len) {
                    printf("This index does not exist in the List. \n");

                } else {
                    head = deleteAtIndex(head, index);
                    len--;
                }
            }

            break;

        case 7:
            splitAlternatively(head);
            break;

        case 8:
            printList(head);
            break;

        case 9:
            loop = 0;
            break;

        default:
            printf("Enter only any one of the above options. \n");
            break;

        }
    }

    return 0;
}



/*
C PROGRAM FOR SIMGLY LINKED LIST WHERE USER CAN ADD, OR DELETE PERTAINING TO THE START, END OR BETWEEN THE LIST.

FOR STACK USING SLL -> INSERT AT START, DELETE AT START.
FOR QUEUE USING SLL -> INSERT AT END, DELETE AT START.
*/
