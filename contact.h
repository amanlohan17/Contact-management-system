#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50
#define MAX_ADDRESS 100
#define FILE_NAME "contacts.dat"

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactList;

// Function declarations
void initializeContactList(ContactList *list);
void addContact(ContactList *list);
void displayAllContacts(ContactList *list);
void searchContact(ContactList *list);
void deleteContact(ContactList *list);
void saveContactsToFile(ContactList *list);
void loadContactsFromFile(ContactList *list);

#endif