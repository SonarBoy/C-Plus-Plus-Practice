#include <iostream>
#include "node.cpp"

using namespace std;

void push(Node** head_ref, int new_data){


    Node* new_node = new Node();

    new_node -> data = new_data;

    new_node -> next  = (*head_ref);

    (*head_ref) = new_node;
}



void insertAfter(struct Node* prev_node, int new_Data){
    
    if(prev_node == NULL){
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));


    new_node -> data = new_Data;

    new_node -> next = prev_node -> next;

    prev_node -> next = new_node;

}

void append(struct Node** head_ref, int new_data){

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node -> data = new_data;

    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last -> next != NULL){
        last = last -> next;
    }

    last -> next = new_node;
    return;

}



void appendWithMarker(struct Node** head_ref, int new_data,int number){

    int runner = 0;

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *tester_node = (struct Node*) malloc(sizeof(struct Node));


    struct Node *last = *head_ref;

    new_node -> data = new_data;

    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last -> next != NULL){
        last = last -> next;

        runner++;

        if(runner % number == 0){
            tester_node -> data = runner;
            tester_node -> next = NULL;

            last -> data = 111;
        }
    }

    last -> next = new_node;
    tester_node -> next = new_node;
    return;

}

void changeAtMarker(struct Node** head_ref, int new_data,int number){

    int runner = 0;

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *tester_node = (struct Node*) malloc(sizeof(struct Node));


    struct Node *last = *head_ref;

    new_node -> data = new_data;

    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return ;
    }

    while(last -> next != NULL){
        last = last -> next;
        runner++;

        if(runner == number){
            last -> data = 100;
            return ;
        }
        
    }
    
    return ;

}


int getAtMarker(struct Node** head_ref, int new_data,int number){

    int runner = 0;

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *tester_node = (struct Node*) malloc(sizeof(struct Node));


    struct Node *last = *head_ref;

    new_node -> data = new_data;

    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return 0;
    }

    while(last -> next != NULL){
        last = last -> next;
        runner++;

        if(runner == (number - 2)){
            tester_node -> data = 100;
            //tester_node -> next = last -> next -> next;
            return last -> data;
        }
        
    }
    
    return 0;

}


//Insert at a particular node.
int insertAtMarker(struct Node** head_ref, int new_data,int number){

    int runner = 0;

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *tester_node = (struct Node*) malloc(sizeof(struct Node));


    struct Node *last = *head_ref;

    new_node -> data = new_data;

    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return 0;
    }

    while(last -> next != NULL){

        last = last -> next;
        runner++;

        if(runner == number){
            
            tester_node -> next = last -> next;
            tester_node -> data = 111;
            last -> next = tester_node;
            return 0;
        }

    }
    
    return 0;
}





void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}  
  


int main(){

    Node* head = NULL;

    int number = 0;
    int marker = 0;
    
    while(true){

    int runner = 0;


    cout << endl << "Enter a number of elements to insert: " << endl;
    cin >> number;
    cout << endl;
    cout << endl << "Enter the mod of elements you want to mark: " << endl;
    cin >> marker;
    cout << endl;
    




    for(int runner = 0; runner < number; runner++){

        //appendWithMarker(&head,rand() % 100,marker);
        append(&head,rand() % 100);

    }

    cout << "Print: ";
    printList(head);

    cout << endl;
    cout << endl;

    //cout << "Testing with the insert " << 
    //changeAtMarker(&head,100,marker);
    insertAtMarker(&head,100,marker);
    cout << "The value at " << marker << " "<<  " is " <<getAtMarker(&head,100,marker);

    cout << endl;
    cout << endl;    

    cout << "Print: ";
    printList(head);

    runner = 0;
    number = 0;
    marker = 0;
    }

}