#include<stdio.h>
#include<windows.h>
int menu();
void loading();
void deposit();
void withdraw();
struct details
{
	char name[20];
	char city[10];
	char state[20];
	int Pin;
	long long int number;
	int no;
	int money;
};
struct details d[2];
int amt,o;
int main()
{
	int x;
	d[0].no=0;
	char pass[10],password[10]="MyCap2001";
	printf("Enter The Password: ");
	scanf("%s",pass);
	if(strcmp(pass,password)==0)
	{
		loading();
		menu();
	}
	else
	{
		printf("Wrong Password!!\n\n");
		printf("Press 1 to try again and 0 to exit: ");
		scanf("%d",&x);
		if(x==1)
		{
			loading();
			main();
		}
		else if(x==0)
		{
			return 0;
		}
		else
		{
			printf("Invalid Input....EXITING\n");
			return 0;
		}
	}
}
void loading()
{
	int i;
	for(i=0;i<=2;i++)
	{
		printf(".");
		Sleep(1000);	
	}
	system("cls");
}

void create_acc()
{
	
				printf("Enter Name: ");
	            fseek(stdin,0,SEEK_END);
	            fgets(d[0].name,20,stdin);
	            printf("Enter City: ");
				fseek(stdin,0,SEEK_END);
				fgets(d[0].city,10,stdin);
				printf("Enter State: ");
				fseek(stdin,0,SEEK_END);
				fgets(d[0].state,20,stdin);
				printf("Enter PIN code: ");
				scanf("%d",&d[0].Pin);
				printf("Enter Phone Number: ");
				scanf("%lli",&d[0].number);
				printf("Enter Account Number(Dont Forget This): ");
				scanf("%d",&d[0].no);
			    d[0].money=0;
				printf("ACCOUNT CREATED");
				loading();
				menu();
}
		
void deposit()
{
	printf("Enter Your 3 digit Account Number: ");
	scanf("%d",&o);
	loading();
		if(o==d[0].no)
		{
			printf("Account Found!!\n\n");
		    printf("How Much Money Would You Like To Deposit(Rs)?\n");
	        scanf("%d",&amt);
        	d[0].money=d[0].money+amt;
        	printf("MONEY ADDED");
        	loading();
        	menu();
		}
		else
		{
			printf("Account Number Not Found!! Try Again\n\n");
			deposit();
		}
}


void withdraw()
{
	printf("Enter Your 3 digit Account Number: ");
	scanf("%d",&o);
	loading();
		if(o==d[0].no)
		{
			printf("Account Found!!\n\n");
		    printf("How Much Money Would You Like To Withdraw(Rs)?\n");
	        scanf("%d",&amt);
	        if(amt<=d[0].money)
	        {
        	   d[0].money=d[0].money-amt;
           	   printf("MONEY WITHDRAWN");
        	   loading();
        	   menu();
            }
            else
            {
                printf("SORRY YOU DON'T HAVE THAT MUCH MONEY\nTry Again\n");
                loading();
                withdraw();		
			}
		}
		else
		{
			printf("Account Number Not Found!! Try Again\n\n");
			withdraw();
		}
}

void display()
{
	int i,j;
	printf("Enter Your 3 digit account number: ");
	scanf("%d",&i);
	loading();
	if(i==d[0].no)
	{
		printf("Account Found\n\n");
		printf("Here Are All Your Details: \n\n");
		printf("NAME: %s\n",d[0].name);
		printf("STATE: %s\n",d[0].state);
		printf("CITY: %s\n",d[0].city);
		printf("PIN CODE: %d\n",d[0].Pin);
		printf("PHONE NUMBER: %lli\n",d[0].number);
		printf("ACCOUNT NUMBER: %d\n",d[0].no);
		printf("BALANCE: %d\n",d[0].money);
		printf("Press To go back to menu... ");
		getch();
//		if(j)
		system("cls");
		menu();
	}
	else
	{
		printf("Account Not Found\n");
		loading();
		menu();
	}
}
	
int menu()
{
	int i;
	printf("What Do You Want To Do?\n\n");
	printf("Press 1: CREATE NEW ACCOUNT\n");
	printf("Press 2: DIPOSIT MONEY\n");
	printf("Press 3: WITHDRAW MONEY\n");
	printf("Press 4: VIEW ACCOUNT\n");
	printf("Press 5: LOGOUT\n");
	printf("Press 6: EXIT\n");
	scanf("%d",&i);
	if(i!=1 && d[0].no==0 && i!=6)
	{
		printf("You Must Create An Account First!!");
		loading();
		menu();
	}
	else if(i==6)
	{
		return 0;
	}
	else
	{
	switch(i)
	{
		case 1:
			loading();
			create_acc();
			break;
			
		case 2:
			loading();
			deposit();
			break;
			
		case 3:
			loading();
			withdraw();
			break;
			
		case 4:
			loading();
			display();
			break;
			
			
		case 5:
			printf("LOGGING OUT");
			loading();
			main();
			break;
			
			
		default:
			printf("Invalid Input...TRY AGAIN");
			loading();
			menu();
	}
}
	
}
