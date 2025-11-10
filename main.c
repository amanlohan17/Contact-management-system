#include <stdio.h>
#include "contact.h"

int main() {
    ContactList contactList;
    int choice;

    initializeContactList(&contactList);
    loadContactsFromFile(&contactList);

    while (1) {
        printf("\n========== CONTACT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addContact(&contactList);
                break;
            case 2:
                displayAllContacts(&contactList);
                break;
            case 3:
                searchContact(&contactList);
                break;
            case 4:
                deleteContact(&contactList);
                break;
            case 5:
                saveContactsToFile(&contactList);
                printf("Contacts saved. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}