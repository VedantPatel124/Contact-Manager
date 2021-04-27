#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char name[20];
    char address[50];
    char phone[10];
    struct list *next;
} ADDRESS;

void add_to_list(void);       /* Add a name to our address book */
void delete_from_list(void);  /* Delete a name from our address book */
void search_name(void);        /* Print an entry in the address book */
void display_names(void);        /* List all the names in the address book */
void free_list(void);         /* Free all the linked list */

ADDRESS *head=NULL;      /* Head of our linked list of addresses-global variable*/

int main()
{
    int c;
    do
    {
        printf("\n1.Add \n2.Delete \n3.Search \n4.List \n5.Quit");
        printf("\nEnter your Choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: add_to_list();
                    break;
            case 2: delete_from_list();
                    break;
            case 3: search_name();
                    break;
            case 4: display_names();
                    break;
            case 5: free_list();
                    return (0);
           default: printf("\nINVALID CHOICE");
        }
    }
    while(c<5);
}

/* Add a new name to our address book */
void add_to_list(void)
{
    ADDRESS *new_name;
    new_name=malloc(sizeof(ADDRESS));
    if(new_name==NULL)
    {
        printf("\nOut of Memory");
        exit;
    }
    printf("\nEnter the new Name: ");    /* Get input for the new item */
    scanf("%s",&new_name->name);
    printf("Enter the Address: ");
    scanf("%s",&new_name->address);
    printf("Enter the Contact no: ");
    scanf("%s",&new_name->phone);
    new_name->next=head;                /* Chain the new item into the list */
    head=new_name;
}

/* Remove a name from the address book */
void delete_from_list(void)
{
    ADDRESS *del;                    /* Pointer to find name to delete */
    ADDRESS *prev;                   /* Pointer to name BEFORE this name */
    char del_name[20];                   /* Name to delete */
    printf("\nEnter the Name to be Delete: ");
    scanf("%s",&del_name);
    if(head==NULL)
    {
        printf("\nThere is no records in the Address Book");
        return;
    }

    /* If the first name is the correct one then move the head of list onto the next head of list */
    if(strcmp(head->name,del_name)==0)
    {
        del=head;
        head=head->next;
        free(del);
        return;
    }

    /* Otherwise loop round the list looking for the name */
    prev=head;
    while(prev->next!=NULL)
    {
        /* We have found the name so delete it */
        if(strcmp(prev->next->name,del_name)==0)
        {
            del=prev->next;
            prev->next=del->next;
            free(del);
            return;
        }
        prev=prev->next;
    }
    printf("\nName not found");
}

/* Print a name from the list */
void search_name(void)
{
    char name[20];                      /* Name to look for */
    ADDRESS *search;                /* Pointer to search list for name */
    printf("\nEnter the Name to be Search: ");
    scanf("%s",&name);
    search=head;
    while(search!=NULL)
    {
        if(strcmp(search->name,name)==0)
        {
            printf("Address: %s\n",search->address);
            printf("Contact no: %s\n",search->phone);
            return;
        }
        search=search->next;    /* Move to next item */
    }
    printf("\nNo such name in the Address Book");
}

/* List all names in the book */
void display_names(void)
{
    ADDRESS *temp;                   /* Traverses list */
    printf("\nAll Names in the Address Book:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->name);
        temp=temp->next;
    }
}

/* Free memory for list */
void free_list(void)
{
    ADDRESS *del;      /* Pointer to part to delete */
    while(head!=NULL)
    {
       del=head;       /* Store the head of list */
       head=head->next;    /* Move on to the next bit */
       free(del);      /* Free the memort for the bit we just left */
    }
}
