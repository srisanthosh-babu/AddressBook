/*
Name : SRISANTHOSH B
Date: 26 June , 2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
void listContacts ( AddressBook *addressBook ) {
	printf ( "\n" ) ;       
	for ( int i = 0 ; i < addressBook -> contactCount ; i++ ) {
	        printf ( "%d.\t" , i + 1 ) ;
       		printf ("%s\t" , addressBook -> contacts [ i ] . name ) ;
	        printf ( "%s\t", addressBook -> contacts [ i ] . phone ) ;
		printf ( "%s\t", addressBook -> contacts [ i ] . email ) ;
		printf ( "\n" ) ;
       }
       printf ( "\n" ) ;    
}

void initialize ( AddressBook *addressBook ) {
   populateAddressBook ( addressBook ) ;
}

void saveAndExit ( AddressBook *addressBook ) {
	addressBook -> fptr_contact = fopen ( "contacts.txt" , "w" ) ;
	for(int i=0;i<addressBook->contactCount;i++){
		fprintf ( addressBook -> fptr_contact , "%s,%s,%s\n",addressBook -> contacts [ i ] . name ,  addressBook -> contacts [ i ] . phone , addressBook -> contacts [ i ] . email ) ;
	}
	fclose( addressBook -> fptr_contact ) ;
	printf("\nFiles saved successfully\n");
        return;	
}


void createContact ( AddressBook *addressBook ) {
	printf ( "\nEnter name : " ) ;
	scanf ( " %[^\n]" , addressBook -> contacts [ addressBook -> contactCount ] . name ) ;
	for ( int i = 0 , j = 0 ; addressBook -> contacts [ addressBook ->contactCount ] . name [ i ] != '\0' ; i++ ) {
		if ( isalpha ( addressBook -> contacts [ addressBook -> contactCount ] .name [ i ] ) == 0 && addressBook -> contacts [ addressBook -> contactCount ] . name [ i ] != ' ' ) {
		       printf ( "\nEnter Valid Name...!\n" ) ;
		       return;
		}
	}		
	printf ( "Enter Phone Number : " ) ;
	scanf ( " %[0-9]" , addressBook -> contacts [ addressBook -> contactCount ] . phone ) ;
	if ( strlen ( addressBook -> contacts [ addressBook -> contactCount ] . phone ) != 10 ) {
		printf ( "\nEnter Valid Phone Number..!\n" ) ;
		return ;
	}
	if ( findContactIndex ( addressBook , addressBook -> contacts [ addressBook -> contactCount ] . phone ) != -1 ) {
		printf ( "\nContact Already exists...!\n" ) ;
		return ;
	}
	printf ( "Enter E-mail Id : " ) ;
	scanf ( " %[^\n]" , addressBook -> contacts [ addressBook -> contactCount ] . email ) ;
	if ( strstr ( addressBook -> contacts [ addressBook -> contactCount ] . email , "@gmail.com" ) == NULL ) {
		printf ( "\nEnter a valid E-mail address..!\n" ) ;
		return ;
	}
	for ( int i = 0 ; i < addressBook -> contactCount - 1 ; i++ ) {
	       if ( strcmp ( addressBook -> contacts [ addressBook -> contactCount ] . email , addressBook -> contacts [ i ] . email ) == 0 ) {
		       printf ( "\nE-mail Already exists\n" ) ;
		       return;
	       }
	}	       
	addressBook -> contactCount++ ;
	printf ( "\nContact Created Successfully\n" ) ;
}

void searchContact ( AddressBook *addressBook ){
	printf ( "\n1.Search By name\n2.Search By Phone Number\n3.Search By E-mail Id\nEnter your choice : " ) ;
	int choice ;
	scanf( "%d" , & choice ) ;
	switch ( choice ) {
		case 1:
			printf ( "\nEnter the name to search : " ) ;
			char name [ 50 ] ;
			scanf ( " %[^\n]" , name ) ;
			int flag1 = 0 ;
			for ( int i = 0 ; i < addressBook -> contactCount ; i++ ) {
	    			if ( strcmp ( addressBook -> contacts [ i ] . name , name ) == 0 ) {
		    			printf ( "%d.\t" , i + 1 ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . name ) ;
		    			printf ( "%s\t" , addressBook -> contacts [ i ] . phone ) ;
		    			printf ( "%s\t" , addressBook -> contacts [ i ] . email ) ;
		    			printf ( "\n" ) ;
					flag1++ ;
	    			}
			}
			if ( ! flag1 ) {
				printf ( "\nContact Not found in the List\n" ) ;
			}
			break ;
		case 2:
			char phone [ 10 ] ;
			printf ( "\nEnter the Phone number to search : " ) ;
			scanf ( " %[^\n]" , phone ) ;
			int flag2 = 0 ;
			for ( int i = 0 ; i < addressBook -> contactCount ; i++ ) {
				if ( strcmp ( addressBook -> contacts [ i ] . phone , phone ) == 0 ) {
					printf ( "%d.\t" , i + 1 ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . name ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . phone ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . email ) ;
					printf ( "\n" ) ;
					flag2++ ;
				}
			}
			if ( ! flag2 ) { 
				printf ( "\nContact not found in the List\n" ) ;
			}
			break ;
		case 3:
			char email [ 30 ] ;
			printf ( "\nEnter the E-mail Id to search : " ) ;
			scanf ( " %[^\n]" , email ) ;
			int flag3 = 0 ;
			for ( int i = 0 ; i < addressBook -> contactCount ; i++ ) {
				if ( strcmp ( addressBook -> contacts [ i ] . email , email ) == 0 ) {
					printf ( "%d.\t" , i + 1 ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . name ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . phone ) ;
					printf ( "%s\t" , addressBook -> contacts [ i ] . email ) ;
					printf ( "\n" ) ;
					flag3++ ;
				}
			}
			if ( ! flag3 ) {
				printf ( "\nContact not found in the List\n" ) ;
			}
			break ;
		default :
			printf ( "\nInvalid Choice\n" ) ;
	}
}

void editContact ( AddressBook *addressBook ) {
	char phone [ 10 ] ;
	printf ( "\nEnter the Phone Number to edit : " ) ;
	scanf ( " %[^\n]", phone ) ;
	int ind = findContactIndex ( addressBook , phone ) ;
	if ( ind == -1 ) {
		printf ( "\nNo contact found\n" ) ;
		return ; 
	}
	else{
		printf ( "\n%s\t%s\t%s\n" , addressBook -> contacts [ ind ] . name , addressBook -> contacts [ ind ] . phone , addressBook -> contacts [ ind ] . email ) ; 
		printf ( "\nEnter new name : " ) ;
		scanf ( " %[^\n]" , addressBook -> contacts [ ind ] . name ) ;
		printf ( "Enter new phone number : " ) ;
		scanf ( " %[^\n]" , addressBook -> contacts [ ind ] . phone ) ;
		printf ( "Enter new E-mail Id : " ) ;
		scanf ( " %[^\n]" , addressBook -> contacts [ ind ] . email ) ;
		printf ( "\nContact Updated Successfully\n" ) ;
		return ;
	}    
}

void deleteContact ( AddressBook *addressBook ) {
	char phone [ 10 ] ;
	printf ( "\nEnter the Phone number to delete : " ) ;
	scanf ( " %[0-9]",phone ) ;
	if ( strlen ( phone ) == 10 ) {
		int ind = findContactIndex ( addressBook , phone ) ;
		if ( ind == -1 ) { 
			printf ( "\nNo Contact Found Try with another one\n" );
			return ;
		}
		else {
			printf ( "\n%s\t%s\t%s\n" , addressBook -> contacts [ ind ] . name , addressBook -> contacts [ ind ] . phone , addressBook -> contacts [ ind ] . email ) ;
			for ( int i = ind ; i < addressBook -> contactCount ; i++ ) {
				strcpy ( addressBook -> contacts [ i ] . name , addressBook -> contacts [ i + 1 ] . name ) ;
				strcpy ( addressBook -> contacts [ i ] . phone , addressBook -> contacts [ i + 1 ] . phone ) ;
				strcpy ( addressBook -> contacts [ i ] .email , addressBook -> contacts [ i + 1 ] . email ) ;
			}
			addressBook -> contactCount-- ;
			printf ( "\nContact deleted successfully\n" ) ;
			return ;
		}
	}
	else { 
		printf ( "\nEnter a Valid Contact to Search\n" ) ;
		return ;
	}
}

int findContactIndex ( AddressBook* addressBook , char phone [ ] ) {
	for ( int i = 0 ; i < addressBook -> contactCount ; i++ ) {
		if ( strcmp ( addressBook -> contacts [ i ] . phone , phone ) == 0 ) {
			return i ;
		}
	}
	return -1 ;
}
