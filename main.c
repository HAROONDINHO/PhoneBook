#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;


typedef struct
{
    char lastname[100];
    char firstname[100];
    date DOB;
    char address[100];
    char phonenumber[100];
    char email[100];
} phonebook;

phonebook *contact;
FILE*p;
int count = 0;


void load()
{

    p = fopen("Contacts.txt","r");
    if (p!= NULL)
    {
        while (!feof(p))
        {
            fscanf(p,"%[^,],",contact[count].lastname);
            fscanf(p,"%[^,],",contact[count].firstname);
            fscanf(p,"%d - ",&contact[count].DOB.day);
            fscanf(p,"%d - ",&contact[count].DOB.month);
            fscanf(p,"%d,",&contact[count].DOB.year);
            fscanf(p,"%[^,],",contact[count].address);
            fscanf(p,"%[^,],",contact[count].phonenumber);
            fscanf(p,"%s \n",contact[count].email);
            count ++;
        }
    }

    else
    {
        printf("Error! File Not Found.\n");
        exit(1);

    }

    fclose(p);
}


void Query()
{
    int i;
    p = fopen("Contacts.txt","r");
    int flag = 0;
    char name[100];
    printf("\nEnter The Last Name of the Contact you are looking for: ",name);
    scanf("%s",name);
    for ( i = 0; i<count; i++)
    {
        if (strcasecmp(name,contact[i].lastname) ==  0)
        {
            flag = 1;
            printf("\n\nThe Information of the last name you have searched for as following : \n");
            printf("The First Name is : %s \n",contact[i].firstname);
            printf("The Date of Birth is : %d - %d - %d  \n",contact[i].DOB.day,contact[i].DOB.month,contact[i].DOB.year);
            printf("The Address is : %s  \n",contact[i].address);
            printf("The Phone Number is : %s  \n",contact[i].phonenumber);
            printf("The Email is : %s  \n\n",contact[i].email);
            printf("************************************************************************************************************\n************************************************************************************************************");
        }
    }
    if (flag==0)
        printf("The Number you have searched for is not found \n");
    fclose(p);
}


void Add()
{
    p = fopen("Contacts.txt", "a");
    printf("please fill the following details: ");
    printf("\nLast Name: ");
    scanf("%s",contact[count].lastname);
    printf("\nFirst Name: ");
    scanf("%s",contact[count].firstname);
    printf("\nDate of birth:-\n ");
    printf("Day: ");
    scanf("%d",&contact[count].DOB.day);
    printf("\n Month: ");
    scanf("%d",&contact[count].DOB.month);
    printf("\n Year: ");
    scanf("%d",&contact[count].DOB.year);
    printf("\nAddress: ");
    scanf("%c",contact[count].address);
    scanf("%[^\n]",contact[count].address);
    printf("\nPhone Number: ");
    scanf("%s",contact[count].phonenumber);
    printf("\nE-mail: ");
    scanf("%s",contact[count].email);
    printf("\ncontact added successfully!\n\n");
    count++;

    fclose(p);
}


void Modify()
{
    int j;
    int flag=0;
    char lastname[100];
    printf("Please enter required last name for modification: ");
    scanf("%s",lastname);
    char c;
    for(j=0; j<count; j++)
    {
        p=fopen("Contacts.txt","r");
        if(strcasecmp(lastname,contact[j].lastname)==0)
        {


            flag=1;
            printf("Do you want to modify first name? (Y/N)");
            scanf("%s",&c);
            if(c=='y'||c=='Y')
            {
                printf("New first name: ");
                scanf("%s",contact[j].firstname);
            }
            printf("Do you want to modify last name? (Y/N)");
            scanf("%s",&c);
            if(c=='y'||c=='Y')
            {
                printf("New last name: ");
                scanf("%s",contact[j].lastname);
            }
            printf("Do you want to modify date of birth? (Y/N)");
            scanf("%s",&c);
            if(c=='y'||c=='Y')
            {
                printf("New date of birth: ");
                scanf("%d %d %d",&contact[j].DOB.day,&contact[j].DOB.month,&contact[j].DOB.year);
            }
            printf("Do you want to modify address? (Y/N)");
            scanf("%s",&c);
            if(c=='y'||c=='Y')
            {
                printf("New address: ");
                scanf("%c",contact[j].address);
                scanf("%[^\n]",contact[j].address);

            }
            printf("Do you want to modify email? (Y/N)");
            scanf("%s",&c);
            if(c=='y'||c=='Y')
            {
                printf("New email: ");
                scanf("%s",contact[j].email);

            }
            printf("Do you want to modify phone number? (Y/N)");
            scanf("%s",&c);
            if(c=='y'||c=='Y')
            {
                printf("New phone number: ");
                scanf("%s",contact[j].phonenumber);

            }

        }
    }

    if(flag==0)
    {
        printf("Error!Record not found.\n");

    }


}

void dlt()
{
    int i;
    char lastname[100];
    char firstname[100];
    int flag=0;
    p=fopen("Contacts.txt","r");
    printf("Enter the last name : \n");
    scanf("%s",lastname);
    printf("Enter the first name : \n");
    scanf("%s",firstname);
    for(i=0; i<=count; i++)
    {
        if(strcasecmp(lastname,contact[i].lastname)==0)
        {
            if(strcasecmp(firstname,contact[i].firstname)==0)
            {
                flag=1;
                for( ; i<=count; i++)
                {
                    strcpy(contact[i].lastname,contact[i+1].lastname);
                    strcpy(contact[i].firstname,contact[i+1].firstname);
                    strcpy(contact[i].address,contact[i+1].address);
                    strcpy(contact[i].email,contact[i+1].email);
                    strcpy(contact[i].phonenumber,contact[i+1].phonenumber);
                    contact[i].DOB.day=contact[i+1].DOB.day;
                    contact[i].DOB.month=contact[i+1].DOB.month;
                    contact[i].DOB.year=contact[i+1].DOB.year;
                }
                count--;
            }
        }
        fclose(p);

    }
    if(flag==0)
        printf(" contact isn't found \n");
    else if(flag==1)
        printf("  contact deleted successfully \n");
}

void save()
{
    int i;
    p=fopen("Contacts.txt","w");
    for(i=0; i<count; i++)
    {
        fprintf(p,"%s,%s,%d-%d-%d,%s,%s,%s\n",contact[i].lastname,contact[i].firstname,contact[i].DOB.day,contact[i].DOB.month,contact[i].DOB.year,contact[i].address,contact[i].email,contact[i].phonenumber);
    }
    printf("your changes are saved successfully");
    fclose(p);
}


void sortByLname(){
    int sort=0,k,j;
    phonebook *hold =malloc(sizeof(phonebook));
      for(k=1 ; k<count && !sort ; k++)
        {
            sort=1;
            for(j=0 ; j<count-k ; j++)
            {
                if(strcmpi(contact[j].lastname,contact[j+1].lastname)>0)
                {
                    strcpy(hold->lastname,contact[j].lastname);
                    strcpy(hold->firstname,contact[j].firstname);
                    strcpy(hold->address,contact[j].address);
                    strcpy(hold->email,contact[j].email);
                    strcpy(hold->phonenumber,contact[j].phonenumber);
                    hold->DOB.day=contact[j].DOB.day;
                    hold->DOB.month=contact[j].DOB.month;
                    hold->DOB.year=contact[j].DOB.year;

                    strcpy(contact[j].lastname,contact[j+1].lastname);
                    strcpy(contact[j].firstname,contact[j+1].firstname);
                    strcpy(contact[j].address,contact[j+1].address);
                    strcpy(contact[j].email,contact[j+1].email);
                    strcpy(contact[j].phonenumber,contact[j+1].phonenumber);
                    contact[j].DOB.day=contact[j+1].DOB.day;
                    contact[j].DOB.month=contact[j+1].DOB.month;
                    contact[j].DOB.year=contact[j+1].DOB.year;

                    strcpy(contact[j+1].lastname,hold->lastname);
                    strcpy(contact[j+1].firstname,hold->firstname);
                    strcpy(contact[j+1].address,hold->address);
                    strcpy(contact[j+1].email,hold->email);
                    strcpy(contact[j+1].phonenumber,hold->phonenumber);
                    contact[j+1].DOB.day=hold->DOB.day;
                    contact[j+1].DOB.month=hold->DOB.month;
                    contact[j+1].DOB.year=hold->DOB.year;

                    sort=0;
                }

            }
        }
                printf("##Phone book sorted## \n");
            for (int a=0 ; a<count ; a++)
            {
                printf("%s,",contact[a].lastname);
                printf("%s,",contact[a].firstname);
                printf("%d - ",contact[a].DOB.day);
                printf("%d - ",contact[a].DOB.month);
                printf("%d,",contact[a].DOB.year);
                printf("%s,",contact[a].address);
                printf("%s,",contact[a].phonenumber);
                printf("%s \n",contact[a].email);

    }
    free(hold);
}

void sortByDOB(){
     int sort=0,k,j;
    phonebook *hold =malloc(sizeof(phonebook));
      for(k=1 ; k<count && !sort ; k++)
        {
            sort=1;
            for(j=0 ; j<count-k ; j++)
            {
                if(contact[j].DOB.year>contact[j+1].DOB.year)
                {
                    strcpy(hold->lastname,contact[j].lastname);
                    strcpy(hold->firstname,contact[j].firstname);
                    strcpy(hold->address,contact[j].address);
                    strcpy(hold->email,contact[j].email);
                    strcpy(hold->phonenumber,contact[j].phonenumber);
                    hold->DOB.day=contact[j].DOB.day;
                    hold->DOB.month=contact[j].DOB.month;
                    hold->DOB.year=contact[j].DOB.year;

                    strcpy(contact[j].lastname,contact[j+1].lastname);
                    strcpy(contact[j].firstname,contact[j+1].firstname);
                    strcpy(contact[j].address,contact[j+1].address);
                    strcpy(contact[j].email,contact[j+1].email);
                    strcpy(contact[j].phonenumber,contact[j+1].phonenumber);
                    contact[j].DOB.day=contact[j+1].DOB.day;
                    contact[j].DOB.month=contact[j+1].DOB.month;
                    contact[j].DOB.year=contact[j+1].DOB.year;

                    strcpy(contact[j+1].lastname,hold->lastname);
                    strcpy(contact[j+1].firstname,hold->firstname);
                    strcpy(contact[j+1].address,hold->address);
                    strcpy(contact[j+1].email,hold->email);
                    strcpy(contact[j+1].phonenumber,hold->phonenumber);
                    contact[j+1].DOB.day=hold->DOB.day;
                    contact[j+1].DOB.month=hold->DOB.month;
                    contact[j+1].DOB.year=hold->DOB.year;

                    sort=0;
                }
                else if(contact[j].DOB.year==contact[j+1].DOB.year)
                {
                    if(contact[j].DOB.month>contact[j+1].DOB.month)
                    {
                    strcpy(hold->lastname,contact[j].lastname);
                    strcpy(hold->firstname,contact[j].firstname);
                    strcpy(hold->address,contact[j].address);
                    strcpy(hold->email,contact[j].email);
                    strcpy(hold->phonenumber,contact[j].phonenumber);
                    hold->DOB.day=contact[j].DOB.day;
                    hold->DOB.month=contact[j].DOB.month;
                    hold->DOB.year=contact[j].DOB.year;

                    strcpy(contact[j].lastname,contact[j+1].lastname);
                    strcpy(contact[j].firstname,contact[j+1].firstname);
                    strcpy(contact[j].address,contact[j+1].address);
                    strcpy(contact[j].email,contact[j+1].email);
                    strcpy(contact[j].phonenumber,contact[j+1].phonenumber);
                    contact[j].DOB.day=contact[j+1].DOB.day;
                    contact[j].DOB.month=contact[j+1].DOB.month;
                    contact[j].DOB.year=contact[j+1].DOB.year;

                    strcpy(contact[j+1].lastname,hold->lastname);
                    strcpy(contact[j+1].firstname,hold->firstname);
                    strcpy(contact[j+1].address,hold->address);
                    strcpy(contact[j+1].email,hold->email);
                    strcpy(contact[j+1].phonenumber,hold->phonenumber);
                    contact[j+1].DOB.day=hold->DOB.day;
                    contact[j+1].DOB.month=hold->DOB.month;
                    contact[j+1].DOB.year=hold->DOB.year;

                    sort=0;
                    }
                else if(contact[j].DOB.month==contact[j+1].DOB.month)
                {
                    if(contact[j].DOB.day>contact[j+1].DOB.day)
                    {
                    strcpy(hold->lastname,contact[j].lastname);
                    strcpy(hold->firstname,contact[j].firstname);
                    strcpy(hold->address,contact[j].address);
                    strcpy(hold->email,contact[j].email);
                    strcpy(hold->phonenumber,contact[j].phonenumber);
                    hold->DOB.day=contact[j].DOB.day;
                    hold->DOB.month=contact[j].DOB.month;
                    hold->DOB.year=contact[j].DOB.year;

                    strcpy(contact[j].lastname,contact[j+1].lastname);
                    strcpy(contact[j].firstname,contact[j+1].firstname);
                    strcpy(contact[j].address,contact[j+1].address);
                    strcpy(contact[j].email,contact[j+1].email);
                    strcpy(contact[j].phonenumber,contact[j+1].phonenumber);
                    contact[j].DOB.day=contact[j+1].DOB.day;
                    contact[j].DOB.month=contact[j+1].DOB.month;
                    contact[j].DOB.year=contact[j+1].DOB.year;

                    strcpy(contact[j+1].lastname,hold->lastname);
                    strcpy(contact[j+1].firstname,hold->firstname);
                    strcpy(contact[j+1].address,hold->address);
                    strcpy(contact[j+1].email,hold->email);
                    strcpy(contact[j+1].phonenumber,hold->phonenumber);
                    contact[j+1].DOB.day=hold->DOB.day;
                    contact[j+1].DOB.month=hold->DOB.month;
                    contact[j+1].DOB.year=hold->DOB.year;

                    sort=0;
                    }

                }

            }
        }
    }
    printf("##Phone book sorted## \n");
            for (int a=0 ; a<count ; a++)
            {
                printf("%s,",contact[a].lastname);
                printf("%s,",contact[a].firstname);
                printf("%d - ",contact[a].DOB.day);
                printf("%d - ",contact[a].DOB.month);
                printf("%d,",contact[a].DOB.year);
                printf("%s,",contact[a].address);
                printf("%s,",contact[a].phonenumber);
                printf("%s \n",contact[a].email);
            }
    free(hold);
}

void print(){
    printf("Enter (1) to sort by lastname or (2) to sort by date of birth\n");
    int m;
    scanf("%d",&m);
    if (m==1)
    {
       sortByLname();
    }

    else if(m==2)
    {
        sortByDOB();
    }
    else {
        printf("sorry wrong choice please enter only 1 or 2\n \n");
        print();
    }
}

int main()
{
    int i;
    int choice;
    contact= malloc(sizeof(phonebook)*1000);
    load();

    do
    {
        printf("\n###PHONE BOOK###\n\n");
        printf("please choose a process from below\n");
        printf("\t(1) Add a contact\n");
        printf("\t(2) Search for a contact\n");
        printf("\t(3) Modify a contact\n");
        printf("\t(4) Delete a contact\n");
        printf("\t(5) sort and print the phonebook\n");
        printf("\t(6) Save changes\n");
        printf("\t(7) Quit\n");
        scanf("%d",&i);

        if (i == 1)
        {
            Add();
        }

        if (i == 2)
        {
            Query();
        }

        if (i == 3)
        {
            Modify();
        }

        if (i == 4)
        {
            dlt();
        }
        if (i == 5)
        {
            print();
        }
        if (i==6)
        {
            save();
        }
        if (i == 7)
        {
            printf("All your unsaved changes will be discarded. If sure press (1), To return to phonebook press (0)\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                free(contact);
                break;
                return 0;
            }
        }
        if (i>7 || i<1)
        {
            printf("\n\n--->invalid input<---\n\n");
        }
    }

    while (1);

}
