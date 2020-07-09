#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int i=0;
struct hospitalregi
   {
    char hospitalname[50];
    char patientname[50];
    char age[3];
    char pmail[20];
    char address[50];
    char email[20];
    char phone[12];
    char code[5];
    char password[12];
    char sex[4];
    char specialnumber[15];

    };
registe ()

    {
        FILE *log;
        log=fopen("hospitallogin.txt","w");
        struct hospitalregi l;
        printf("Enter Hospital name: ");
        scanf("%s",l.hospitalname);
        printf("Enter address name: ");
        scanf("%s",l.address);
        printf("Enter Email: ");
        scanf("%s",l.email);
        printf("Enter phone: ");
        scanf("%s",l.phone);
        printf("Enter password: ");
        scanf("%s",l.password);
        printf("Enter Hospital code: ");
        scanf("%s",l.specialnumber);

        fwrite(&l,sizeof(l),1,log);
        fclose(log);
        printf("\n\nYour Username is EmailID\n");
        printf("Now login with EmailID and password\n");
        printf("\nPress any key to continue.......");
        getch();
        system("CLS");
        login();
}

login()
{
    char email[200],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct hospitalregi l;
    wrong_trial:
    printf("UserID: ");
    scanf("%s",&email);
    printf("password: ");
    while(1)
        {
            password[i]=getch();
            if(password[i]=='\r'){
                password[i]='\0';
            break;
        }
        putch('*');
        i++;
        }



    while (fread(&l,sizeof(l),1,log))
    {
        if(strcmp(email,l.email)==0 && strcmp(password,l.password)==0)
            {
            printf("\nSuccesful Login\n");

        }
        else{
            printf("\nPlease Enter correct User id and password\n\n");
            goto wrong_trial;
        }

    }

}
    fclose(log);

void patient_registration()
{
   FILE *log;
        log=fopen("patientlogin.txt","w");
        struct hospitalregi l;
        printf("Enter Patient Name: ");
        scanf("%s",l.patientname);
        printf("Enter Age: ");
        scanf("%s",l.age);
        printf("Enter Email: ");
        scanf("%s",l.pmail);
        printf("Enter phone: ");
        scanf("%s",l.phone);
        printf("Enter password: ");
        scanf("%s",l.password);

        fwrite(&l,sizeof(l),1,log);
        fclose(log);
        printf("\n\nYour Username is EmailID\n");
        printf("Now login with EmailID and password\n");
        printf("\nPress any key to continue.......");
        getch();
        system("CLS");
        patient_login();
}

void patient_login()
{
    char pmail[200],password[20];
    FILE *log;
    log=fopen("patientlogin.txt","r");
    struct hospitalregi l;
    wrong_trial:
    printf("Email: ");
    scanf("%s",&pmail);
    printf("password: ");
    while(1)
        {
            password[i]=getch();
            if(password[i]=='\r'){
                password[i]='\0';
            break;
        }
        putch('*');
        i++;
        }



    while (fread(&l,sizeof(l),1,log))
    {
        if(strcmp(pmail,l.pmail)==0 && strcmp(password,l.password)==0)
            {
            printf("\nSuccesful Login\n");

        }
        else{
            printf("\nPlease Enter correct Email id and password\n\n");
            goto wrong_trial;
        }

    }

}
    fclose(log);

int main()
{

    int choice;

    while(1)
    {

    printf("Enter the corresponding system: \n");
    printf("\t\t\t[1]  Register as Hospital \n");
    printf("\t\t\t[2]  Register as patient \n");
    printf("\t\t\t[3]  Login as Hospital \n");
    printf("\t\t\t[4]  Login as patient \n");
    printf("\t\tSelection: \t\t  ");
    scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    registe();
                    break;
                case 2:
                    patient_registration();
                    break;
                case 3:
                    login();
                    break;
                case 4:
                    patient_login();
                    break;
                 case 10:
                    exit(1);
                default:
                    printf("Wrong choice try again\n");
                }

       }

}


