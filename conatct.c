#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

void initializeContactList(ContactList *list) {
    list->count = 0;
}

void addContact(ContactList *list) {
    if (list->count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    Contact newContact;

    printf("\n--- Add New Contact ---\n");
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(newContact.phone, MAX_PHONE, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    printf("Enter address: ");
    fgets(newContact.address, MAX_ADDRESS, stdin);
    newContact.address[strcspn(newContact.address, "\n")] = '\0';

    list->contacts[list->count] = newContact;
    list->count++;

    printf("Contact added successfully!\n");
}

void displayAllContacts(ContactList *list) {
    if (list->count == 0) {
        printf("\nNo contacts found!\n");
        return;
    }

    printf("\n========== ALL CONTACTS ==========\n");
    printf("%-5s %-15s %-15s %-25s %-30s\n", "No.", "Name", "Phone", "Email", "Address");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < list->count; i++) {
        printf("%-5d %-15s %-15s %-25s %-30s\n", i + 1,
               list->contacts[i].name,
               list->contacts[i].phone,
               list->contacts[i].email,
               list->contacts[i].address);
    }
    printf("=====================================\n");
}

void searchContact(ContactList *list) {
    if (list->count == 0) {
        printf("\nNo contacts to search!\n");
        return;
    }

    char searchName[MAX_NAME];
    printf("\n--- Search Contact ---\n");
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int found = 0;
    printf("\n========== SEARCH RESULTS ==========\n");

    for (int i = 0; i < list->count; i++) {
        if (strstr(list->contacts[i].name, searchName) != NULL) {
            printf("\nNo. %d\n", i + 1);
            printf("Name: %s\n", list->contacts[i].name);
            printf("Phone: %s\n", list->contacts[i].phone);
            printf("Email: %s\n", list->contacts[i].email);
            printf("Address: %s\n", list->contacts[i].address);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found with that name!\n");
    }
}

void deleteContact(ContactList *list) {
    if (list->count == 0) {
        printf("\nNo contacts to delete!\n");
        return;
    }

    int index;
    printf("\n--- Delete Contact ---\n");
    displayAllContacts(list);
    printf("Enter contact number to delete (0 to cancel): ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > list->count) {
        printf("Invalid choice!\n");
        return;
    }

    for (int i = index - 1; i < list->count - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }
    list->count--;

    printf("Contact deleted successfully!\n");
}

void saveContactsToFile(ContactList *list) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error: Could not save contacts!\n");
        return;
    }

    fwrite(&list->count, sizeof(int), 1, file);
    fwrite(list->contacts, sizeof(Contact), list->count, file);
    fclose(file);
}

void loadContactsFromFile(ContactList *list) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        return;
    }

    fread(&list->count, sizeof(int), 1, file);
    fread(list->contacts, sizeof(Contact), list->count, file);
    fclose(file);

    printf("Contacts loaded from file.\n");
}