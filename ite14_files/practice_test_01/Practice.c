#include <stdio.h>
#include <stdlib.h>

struct nodes
{
    int x;
    struct nodes *next;
};
//Passing the head by reference
void addNode_Reference(struct nodes ** head){

    //creates the node
    struct nodes * new_node;
    new_node = (struct nodes *) malloc (sizeof(struct nodes));

    printf("\nEnter value of X:");
    scanf("%d", &new_node->x);
    new_node->next = NULL;

    //if the list is empty, point the head to the created node
    //which is the default first node of the list
    if (*head == NULL){
        *head = new_node;
    }
    //if the list is not empty, loop the list and find the last node
    else {
        struct nodes * current;
        current = *head;

        //loop the entire list until NULL
        while(current != NULL){
            //condition to find the last node of the list
            if (current->next == NULL){
                //insert th new node at the end of the list then break the loop
                current->next = new_node;
                break;
            }
            current = current->next;
        }
    }

}

struct nodes * addNode_Return_Node(){
    //creates the node
    struct nodes * new_node;
    new_node = (struct nodes *) malloc (sizeof(struct nodes));

    printf("\nEnter value of X:");
    scanf("%d", &new_node->x);
    new_node->next = NULL;

    return new_node;
}

void display(struct nodes * head){
    //create a current pointer and initialize to head
    struct nodes * current;
    current = head;

    //if the list is empty
    if (head == NULL){
        printf("\nThe list is empty");
    }
    else {
        //loop the list until NULL
        while(current != NULL){
            printf("%d -> ", current->x);
            current = current->next;
        }
    }
}
void countNodes( struct nodes * curr )
{
    int count = 0;
    while( curr != NULL )
    {
        count++;
        curr = curr->next;
    }
    printf( "There are %d nodes in the list.\n", count );
}

// Searches if Node has x == to user input
void search( struct nodes * curr )
{
    if( curr == NULL )
    {
        printf( "There is nothing to search.\n " );
        return;
    }
    int target;
    printf( "Enter x: " );
    scanf( "%d", &target );
    
    while( curr != NULL )
    {
        if( curr->x == target )
        {
            printf( "x: %d exists.\n", target );
            return;
        }

        curr = curr->next;
    }

    printf( "x: %d does not exist.\n", target );
}

void displayEven( struct nodes * curr )
{
    if( curr == NULL )
    {
        printf( "No nodes to display.\n" );
        return;
    }

    int index = 1;
    while( curr != NULL )
    {
        if( ( index % 2 ) == 0 )
        {
            printf( "%d ->", curr->x );
        }
        index++;
        curr = curr->next;
    }
}

void deleteFirst( struct nodes ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }

    struct nodes * curr = *head;
    *head = curr->next;
    free( curr );
}

void deleteLast( struct nodes ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }
    struct nodes * curr = *head;

    if( curr->next == NULL )
    {
        free( *head );
        *head = NULL;
        return;
    }

    while( curr->next->next != NULL )
    {
        curr = curr->next;
    }
    free( curr->next );
    curr->next = NULL;
}

// Deletes the first instance of node with x == user input.
void deleteNode( struct nodes ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }
    int target;
    struct nodes * curr = *head;

    printf( "Enter x to delete: " );
    scanf( "%d", &target );

    if( ( *head )->x == target )
    {
        struct nodes * temp = *head;
        *head = temp->next;
        free( temp );
        return;
    }
    
    while( curr->next != NULL )
    {
        if( curr->next->x == target )
        {
            struct nodes * temp = curr->next;
            curr->next = curr->next->next;
            free( temp );
            return;
        }
        curr = curr->next;
    }

    printf( "x: %d does not exist.\n", target );
}

int main(){
    struct nodes *head = NULL;

    struct nodes * new_node;
    int ch;
    do{
        printf("\n1.......Add Node (Passing the Head - Pass By Reference)");
        printf("\n2.......Add Node (No Parameter - Returns the created node)");
        printf("\n3.......Display List");
        printf("\n4.......Count List – Count and display the total number of nodes in the current list.");
        printf("\n5.......Search in the List – Allow the user to input an integer value and determine whether it exists in the list.");
        printf("\n6.......Display by Even Position – Display only the nodes located at even positions in the list.");
        printf("\n7.......Delete the First Node – Delete the first node in the list without requiring user input.");
        printf("\n8.......Delete the Last Node – Delete the last node in the list without requiring user input.");
        printf("\n9......Delete a Node – Prompt the user to input a value X. If X exists in the list, delete the corresponding node.");
        printf("\n0.......Exit");
        printf("\nSelect: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: addNode_Reference(&head);
                    break;
            case 2: new_node = addNode_Return_Node();

                    //if the list is empty, point the head to the created node
                    //which is the default first node of the list
                    if (head == NULL){
                        head = new_node;
                    }
                    //if the list is not empty, loop the list and find the last node
                    else {
                        struct nodes * current;
                        current = head;

                        //loop the entire list until NULL
                        while(current != NULL){
                            //condition to find the last node of the list
                            if (current->next == NULL){
                                //insert th new node at the end of the list then break the loop
                                current->next = new_node;
                                break;
                            }
                            current = current->next;
                        }
                    }

                    break;
            case 3: display(head);
                    break;
            case 4: countNodes(head);
                    break;
            case 5: search(head);
                    break;
            case 6: displayEven(head);
                    break;
            case 7: deleteFirst(&head);
                    break;
            case 8: deleteLast(&head);
                    break;
            case 9: deleteNode(&head);
                    break;
            default:break;
        }
    }while(ch != 0);


    return 0;
}
