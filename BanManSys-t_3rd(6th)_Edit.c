#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

int i,j;
int main_exit;
void menu();//works
void new_acc();//works
void edit();
void check_acc();//works
void list();
void transact();
void erase();
void close();//works

struct date{
    int month,day,year;
    };
struct acc_inf{
		int acc_no,age;
		char acc_type[10];
		char name[60];
		char sname[60];
		char address[60];
		char aadhaar[12];
		double phone;
		float amt;
		struct date dob;
		struct date deposit;
		struct date withdraw;
		}add,upd,check,rem,transac;

float sinterest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}

/*float cinterest(float t,float amount,int rate, int NCI)
{
	float CI;
	CI=abs(amount*(1-pow(1+(rate/NCI),NCI*t)));
	return (CI);
}*/

void delay(int j)
{   int i,k;
    for(i=1;i<j;i++)
         k=i;
}


void menu(void)
{   int choice;
    system("cls");
    system("color A");
    printf("\n\n\t\tBANK MGMT SYSTEM");
    printf("\n\n\n\t\t\xB1\xB1\xB1 MAIN MENU \xB1\xB1\xB1");
    printf("\n\n\t\t1. Create New Account\n\t\t2. Update Info of Existing Account\n\t\t3. Check the Details of Existing Account(s)\n\t\t4. View Customer List\n\t\t5. Transactions\n\t\t6. Remove Existing Account(s)\n\t\t7. Exit\n\n\n\t\t Enter Your Choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:check_acc();
        break;
        case 4:list();
        break;
        case 5:transact();
        break;
        case 6:erase();
        break;
        case 7:close();
        break;

    }

}

void new_acc()

{
    int choice;
    FILE *ptr;

	ptr=fopen("details.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\t\t\tFILL INFORMATION");
    
    printf("\nEnter your account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,&add.name,&add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("This Account is already in Use");
            delay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    
	/*printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);*/
	getchar();
	
	printf("\nEnter the name (Constrict at exactly two words):");
    //scanf("%[^\n]%*c",&add.name);
	scanf("%s%s",&add.name,&add.sname);
    
	printf("\nEnter the date of birth(MM DD YYYY):");
    scanf("%d%d%d",&add.dob.month,&add.dob.day,&add.dob.year);
    
	printf("\nEnter Your Age:");
    scanf("%d",&add.age);
    getchar();
    
	printf("\nEnter Your Address:");
   // scanf("%[^\n]%*c",&add.address);
    gets(add.address);

    printf("\nEnter Your UIDAI:");
    scanf("%s",&add.aadhaar);
    
    printf("\nEnter the phone number: ");
    scanf("%f",&add.phone);
    
    printf("\nEnter the amount to deposit:Rupee(s) ");
    scanf("%f",&add.amt);
    
    printf("\nType of Account:\n\t#Savings\n\t#Current\n\t#Fixed1(1 year)\n\t#Fixed2(2 years)\n\t#Fixed3(3 years)\n\n\tEnter Your Choice:");
    scanf("%s",&add.acc_type);

    fprintf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.dob.month,add.dob.day,add.dob.year);

    fclose(ptr);
    printf("\nAccount has been created");
    
	add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if (main_exit==0)
            close();
    else
    {
    	printf("\nInvalid!\a");
        goto add_invalid;
    }
}


void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("details.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("details.dat");
    rename("new.dat","details.dat");

	if(test!=1)
        {   
			system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                if(main_exit==1)
                    menu();
                else if(main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void check_acc()
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float interest;
    ptr=fopen("details.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,&add.name,&add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s %s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhaar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rupees %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees%.2f as interest on %d/%d/%d",sinterest,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",sinterest,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",sinterest,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d of every month",sinterest,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s%s",&check.name,&check.sname);
        while (fscanf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0&&(strcmpi(add.sname,check.sname)==0))
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s %s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhaar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rupees%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",sinterest,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",sinterest,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",sinterest,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        interest=sinterest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d of every month",sinterest,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            check_acc_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    check_acc();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto check_acc_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}

void list()
{
    FILE *view;
    view=fopen("details.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s %s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.sname,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    list_invalid:
     printf("\n\nEnter 1 for Main Menu and 0 to Exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto list_invalid;
        }
}

void transact()
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("details.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transac.acc_no);
    while (fscanf(old,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transac.acc_no)
            {   test=1;
            	printf("type of acc :%s",add.acc_type);
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    delay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rupees ");
                    scanf("%f",&transac.amt);
                    add.amt+=transac.amt;
                    fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else if(choice==2)
                {
                    printf("Enter the amount you want to withdraw:Rupees ");
                    scanf("%f",&transac.amt);
                    add.amt-=transac.amt;
                    fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }
                else
                	break;

            }
            else
            {
               fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("details.dat");
   rename("new.dat","details.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}

void erase()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("details.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter The Account No. of The Customer You want to Delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.sname,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.sname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        
        else
        {test++;
            printf("\nRecord Deleted\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("details.dat");
    rename("new.dat","details.dat");
    if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 1 to Retry,2 to Return to Main Menu and 0 to Exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            erase();
        else if(main_exit==2)
            menu();
        else if (main_exit==0)
            close();
        else
        {printf("\nInvalid!\a");
            goto erase_invalid;}
    }
    else
    {
        printf("\nEnter 1 for Main Menu and 0 to Exit:");
        scanf("%d",&main_exit);
        system("cls");
        if(main_exit==1)
        	menu();
        else
            close();
    }
}

void close()
{
    printf("\n\n\n\n PATIENCE! WORK IN PROGRESS");
}

int main()
{
    char pass[10],password[10]="HELP";
    int i=0;
    printf("\n\n\t\tEnter the password to login (Authorised Personnel Only):");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            delay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password 0.o\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    delay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
