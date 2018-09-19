#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

int i,j;
int main_exit;
void menu();

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
    else (main_exit==0)
            close();
}
