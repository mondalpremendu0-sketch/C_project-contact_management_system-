#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct Contacts{
  char name[50];
  char phone[15];
  char email[50];
};


void addContact()
{
    FILE *fp;
    struct Contacts c;

    fp = fopen("contacts.dat", "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf(" %[^\n]", c.name);

    printf("Enter Phone Number: ");
    scanf("%s", c.phone);

    printf("Enter Email: ");
    scanf("%s", c.email);

    fwrite(&c, sizeof(struct Contacts), 1, fp);

    fclose(fp);

    printf("\nContact Added Successfully!\n");
}
void viewContacts()
{
    FILE *fp;
    struct Contact c;

    fp = fopen("contacts.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo contacts found!\n");
        return;
    }

    printf("\n===============================================\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("===============================================\n");

    while (fread(&c, sizeof(struct Contact), 1, fp))
    {
        printf("%-20s %-15s %-30s\n", c.name, c.phone, c.email);
    }

    printf("===============================================\n");

    fclose(fp);
}
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