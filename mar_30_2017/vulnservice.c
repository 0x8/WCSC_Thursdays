#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Message {
    char   msg[100];
    struct Message* next;
    struct Message* prev;
} Message;

Message* createmsg(char *msg) {
    // Create the new message 'object'
    Message* new_msg = (Message*)malloc(sizeof(Message));
    if(new_msg == NULL){
        printf("Error creating new message node!\n");
        exit(1);
    } 
    
    // Copy the content into the message
    strcpy(new_msg->msg, msg);
    
    return new_msg;
}

// Allow creation of new messages
Message* new_message(Message* curr) {
    // Define the new msg
    char msg[100];
    
    printf("Enter your new message:\n");

    // Read the new message
    scanf("%s", msg);

    if (curr == NULL){
        curr = createmsg(msg);
        return curr;
    } 
    
    else if (curr->msg == "NULL") {
        curr = createmsg(msg);
        return curr;
    }

    else {
        Message* new_msg = createmsg(msg);       
        return new_msg;
    }
}

int main() {

    Message* messages = (Message*)malloc(sizeof(Message));
    strcpy(messages->msg,"NULL");
    messages->next = NULL;
    messages->prev = NULL;
    Message* messages_last = messages;
    Message* messages_head = messages;

    printf("[Welcome to WCSC VULNCHAT]\n");
    printf("We promise our system is vulnerable in some way,\n");
    printf("it's just up to you to find it.\n");
    
    char name[28];
    printf("\nPlease tell me your name: ");
    fflush(stdout);
    read(0, name, 0x1c);
    printf("Hello, %s !\n", name);
    
    // Main loop
    while(1) {

        // Print menu
        printf("\n");
        printf("The options are as follows: \n");
        printf("[1] Save a message\n");
        printf("[2] View Messages\n");
        printf("[3] Exit\n");

        // Get choice
        int choice;
        printf("\nPlease select one of the options: ");
        scanf("%d", &choice);

        // Create a temporary pointer for looping purposes
        Message* tmp = messages_head;

        // Handle choice
        if (choice == 1) { // Create Message
            
            //Message* newmsg = (Message*)malloc(sizeof(Message));
            Message* newmsg = new_message(messages_last);
            
            // Increment pointer down the list
            messages_last->next = newmsg;
            messages_last = newmsg;
        }

        else if (choice == 2) { // View messages
            tmp = messages_head->next;
            
            // Loop over the entire list and print the messages
            while(tmp != NULL) {
                printf("Message: %s", &tmp->msg[0]);
                printf("\n"); // Extra new line for prettyness
                tmp = tmp->next;
            }
        }

        else if (choice == 3) { // Exit
            exit(0);
        }

        else { // Invalid choice
            printf("Invalid option, please choose a valid one.\n");
        }

    }

    return 0;
}
