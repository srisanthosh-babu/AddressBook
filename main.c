#include <stdio.h>
#include <string.h>
#include "contact.h"
int main () {
	int choice ;
	AddressBook contact ;
	initialize ( & contact ) ;
	do {
		printf ( "\nAddressBook Menu\n" ) ;
		printf ( "1.Create Contact\n" ) ;
		printf ( "2.Edit Contact\n" ) ;
		printf ( "3.Search Contact\n" ) ;
		printf ( "4.Delete Contact\n" ) ;
		printf ( "5.List all contacts\n" ) ;
		printf ( "6.Save contacts\n" ) ;
		printf ( "7.Exit\n" ) ;
		printf ( "Enter you choice: " ) ;
		scanf ( "%d" , & choice ) ;
		switch ( choice ) {
			case 1 :
				printf ( "\nCreate contact selected\n" ) ;
				createContact ( & contact ) ;
				break ;
			case 2 :
				printf ( "\nEdit contact selected\n" ) ;
				editContact ( & contact ) ;
				break ;
			case 3 :
				printf ( "\nSearch contact selected\n" ) ;
				searchContact ( & contact ) ;		
				break ;
			case 4 :
				printf ( "\nDelete contact selected\n" ) ;
				deleteContact ( & contact ) ;
				break ;
			case 5 :
				printf ( "\nList all contact selected\n" ) ;
				listContacts ( & contact ) ;				
				break ;
			case 6 :
				printf ( "\nSave contact to file\n" ) ;
				saveAndExit ( & contact );
				break ;
			case 7 :
				printf ( "\nExit selected\n" ) ;
				break ;
			default : 
				printf ( "\nInvalid input\n" ) ;
		}
	} while ( choice != 7 ) ;

	return 0 ;
	
}


