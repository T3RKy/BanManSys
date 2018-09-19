#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

int i,j;
int main_exit;
void menu();
void new_acc();
void edit();
void checkacc();
void list();
void transact();
void erase();
void close();

struct date{
    int month,day,year;
    };
struct acc_inf{
		int acc_no,age;
		char acc_type[10];
		char name[60];
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

float cinterest(float t,float amount,int rate, int NCI)
{
	float CI;
	CI=abs(amount*(1-pow(1+(rate/NCI),NCI*t)));
	return (CI);
}

void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


void menu(void)
{   int choice;
    system("cls");
    system("color B");
    printf("\n\n\t\t BANK MGMT SYSTEM");
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
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
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
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhaar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("This Account is already in Use");
            delay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    
	printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    
	printf("\nEnter the name:");
    scanf("%s",add.name);
    
	printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    
	printf("\nEnter Your Age:");
    scanf("%d",&add.age);
    
	printf("\nEnter Your Address:");
    scanf("%s",add.address);
    
    printf("\nEnter Your UIDAI:");
    scanf("%s",add.aadhaar);
    
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    
    printf("\nType of Account:\n\t#Savings\n\t#Current\n\t#Fixed1(1 year)\n\t#Fixed2(2 years)\n\t#Fixed3(3 years)\n\n\tEnter Your Choice:");
    scanf("%s",add.acc_type);

    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhaar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

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
	return 0;
}

void checkacc()
{
	return 0;
}

void list()
{
	return 0;
}

void transact()
{
	return 0;
}

void erase()
{
	return 0;
}

void close()
{
    printf("\n\n\n\n PATIENCE! WORK IN PROGRESS");
}

int main()
{
	return 0;
}
