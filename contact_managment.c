#include <stdio.h>
#include <strung.h>
#include <stdlib.h>

 struct Contacts{
  char name[50];
  char phNumber[15];
  char email[50];
};


void addContact(){
  FILE* fp;
  struct Contacts c;
  fp = fopen("data.txt","ab");
  
  printf("Name: \n");
  fgets(c.name,sizeof(c.name),stdin);
  
  printf("Phone Number: \n");
  fgets(c.phNumber,sizeof(c.phNumber),stdin);
  
  printf("Email: \n");
  fgets(c.email,sizeof(c.email),stdin);
  
  if(fp == NULL){
    printf("Error opening File\n");
    return 1;
  }
  
  fwrite(&c, sizeof(struct Contacts), 1, fp);
  fclose(fp);
  
  printf("Contacts Added successfully!!\n")
  
}
void viewContacts(){}
void searchContact(){}
void updateContact(){}
void deleteContact(){}


int main()
{
    int choice;

    while (1)
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                viewContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                updateContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}