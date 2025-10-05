#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];

} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
    FILE*fptr_contact;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int findContactIndex(AddressBook *addressBook,char []);
void saveAndExit ( AddressBook*addressBook ) ;

#endif
