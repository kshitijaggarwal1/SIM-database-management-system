#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>


long long int stack_i[1000],top_i=-1,count=1;

COORD coord={0,0};
void gotoxy(int x,int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{

    int milli_seconds = 15* number_of_seconds;

        clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}
void drawbox(int x1, int y1, int x2, int y2, int d)
{
    gotoxy(x1,y1);
    printf("+");
    delay(d);
    gotoxy(x2,y2);
    printf("+");
    delay(d);
    int i;
    for(i=1;i<x2-x1;i++)
    {   gotoxy(x1+i,y1);
        printf("-");
        printf("\a");
        delay(d);
        gotoxy(x2-i,y2);
        printf("-");
        delay(d);
    }
    gotoxy(x1,y2);
    printf("+");
    gotoxy(x2,y1);
    printf("+");
    
    int j;
    for(j=1;j<y2-y1;j++)
        {
            gotoxy(x2,y1+j);
            printf("|");
            delay(d);
            gotoxy(x1,y2-j);
            printf("|");
            delay(d);
        }
}

void credits()
{
    gotoxy(50,6);
    printf("PRESENTED TO YOU BY:-");
    delay(100);
    gotoxy(54,8);
    
	printf("* KSHITIJ AGGARWAL 18103134");
    delay(100);
    gotoxy(54,9);
    
    system("color 0C");
    delay(30);
    system("color 0A");
    delay(30);

}


struct node
{
    int age;
    long long int serial;
    long long int contact;
    long long int ID;

	char name[30];
	char address[100];
    char status[2];
    char sim_type[15];
    char activationdate[11];

    struct node *next;
};

struct node *head=NULL,*temp2=NULL;
int user_login()
{
	int t;
    char password[10]="ENTER1234",ch[10];

	start1:
    	printf("\n \tEnter Password  : ");
    	scanf("%s",ch);

   		if(strcmp(ch,password)==0)
		{
			printf("\n\tACCESS GRANTED!\n");

			start2:
				printf("\tPress 1 to continue...: ");
				scanf("%d",&t);

				if(t==1)
				{
					system("CLS");
					return 1;
				}

				else
				{
					printf("\tYou didn't pressed the correct key. Take another try!\n");
					goto start2;
				}
		}

    	else
  		{
    		printf("\nPASSWORD INCORRECT! ACCESS DENIED...\n");
    		printf("To take Another try press 0: ");
    		scanf("%d",&t);

    		if(t==0)
    		goto start1;
    		else
    		return 0;
		}
}


int check_no(long long int mob)
{
	int flag;
	long long int m;
	if(m<1000000000 && m>9999999999)
	{
		printf("Entered contact number is not 10 digit..");
		flag=0;
	}
	else
	{
		flag=1;
	}

	return flag;
}


long long int ten_digit()
{
   static long long int r,sell=6000000000;
   r=sell++;
   return r;
}


void add_customer()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    FILE *f;
    printf("\n\n.....................ADD NEW DETAILS...................\n\n");
    printf("Enter Information for the new Customer:- \n");

    printf("\nEnter name: ");
    scanf("%s",temp->name);

    printf("\nEnter age: ");
    scanf("%d",&temp->age);

    printf("\nEnter address: ");
    scanf("%s",temp->address);

    printf("\nEnter your Personal ID number: ");
    scanf("%lld",&temp->ID);


	temp->contact=ten_digit();
    temp->serial=count;
    count++;
    printf("Contact Number Allocated : %lld",temp->contact);

    printf("\nEnter SIM Type: \n1. P-Personal\n2. C-Coorporate\n3. V-VIP \n");
    scanf("%s",temp->sim_type);
    strcpy(temp->status,"A");

    f=fopen("projectfile.txt","a");
    fprintf(f,"%s\t %d\t %s\t %lld\t %lld\t %s\t %s\t\n",temp->name,temp->age,temp->address,temp->ID,temp->contact,temp->status,temp->sim_type);
    fclose(f);

    if(head==NULL)
    {
    	head=temp;
    	temp2=temp;
    }

    else
    {
        temp2->next=temp;
        temp2=temp;
    }

    printf("\n\nOPERATION SUCCESSFULLY DONE!\n ");
}


void delete_customer()
{
	long long int mobile;
	int check;
	start:
	printf("\n\n.....................DELETE DETAILS...................\n\n");
	printf("\nEnter the mobile number of the customer:");
	scanf("%lld",&mobile);


	struct node *temp=NULL,*temp1=NULL;

	temp=head;
	while(temp->contact!=mobile)
	{
		if(temp==NULL)
		{
			printf("Contact information not found! \n");
			goto end;
		}
		temp1=temp;
		temp=temp->next;
	}

	temp1->next=temp->next;
	free(temp);

	printf("\nThe data for the provided customer is deleted!\n");
	end:
		printf("\n\nOPERATION SUCCESSFULLY DONE! ");
}


void update_customer()
{
    struct node *temp;
    long long int mob;
    temp=head;


    printf("Enter the contact number whose details are to be updated : ");
    scanf("%lld",&mob);
    while(temp!=NULL)
    {
    	if(temp->contact==mob)
    		break;
		temp=temp->next;
	}
    FILE *f;

    int choice;
    int age1;
    char name1[40];
    char addre[50];
    printf("\n\n.....................UPDATE DETAILS...................\n\n");
	printf("\nWhat do you want to update?\nPress 1 to update Name\nPress 2 to update Age\nPress 3 to Update Address.\nPress 4 to update all\n");

	printf("Enter your choice: ");
    scanf("%d",&choice);

	switch(choice)
    {
    	case 1:
        	printf("\nEnter name : ");
        	scanf("%s",name1);
        	strcpy(temp->name,name1);
        	break;

		case 2:
        	printf("\nEnter AGE : ");
        	scanf("%d",&age1);
           	temp->age=age1;
	        break;

		case 3:
        	printf("\nEnter Updated Address : ");
        	scanf("%s",addre);
	        strcpy(temp->address,addre);
    	    break;

	    case 4:
    	    printf("\nEnter name : ");
        	scanf("%s",name1);
        	strcpy(temp->name,name1);
     	   	printf("\nEnter AGE : ");
        	scanf("%d",&age1);
      		temp->age=age1;
        	printf("\nEnter new address : ");
        	scanf("%s",addre);
        	strcpy(temp->address,addre);
        	break;

        default:
        	break;
    }

    if(temp->next==NULL)
    	printf("User data not found!\n");

    printf("\n\nOPERATION SUCCESSFULLY DONE! ");
}


void search_customer()
{
    struct node *temp;
    temp=head;

    long long int mob;

    printf("\n\n.....................SEARCH DETAILS...................\n\n");
    printf("\nEnter the contact number to be searched: ");
    scanf("%lld",&mob);

    while(temp!=NULL)
    {
        if(temp->contact==mob)
        {
            printf("\nYou are looking for : ");
            printf("\nNAME : %s",temp->name);
            printf("\nAGE : %d",temp->age);
            printf("\nADDRESS : %s",temp->address);
            printf("\nTYPE : %s",temp->sim_type);
            printf("\nSTATUS: %s",temp->status);
            break;
        }

	    temp=temp->next;
    }

    if(temp==NULL)
		printf("\nThe contact number doesn't exist in the system database!\n");
	else
    	printf("\n\nOPERATION SUCCESSFULLY DONE! ");
}


void push_i(long long int c)
{
	top_i++;
	stack_i[top_i]=c;
}


void pop_i()
{
	if(top_i==-1)
	printf("No recent call logs!\n");

	else
	{
		printf("Recent Call logs are:\n");

		while(top_i!=-1)
		{
			printf("%lld\n",stack_i[top_i]);
			top_i--;
		}
	}
}


void add_call_logs()
{
 	long long int c,i,n;
 	int check;

 	printf("Enter the number of call logs that you want to enter: ");
 	scanf("%lld",&n);
 	while(n--)
 	{
 		scanf("%lld",&c);
 		push_i(c);

	}

	printf("Calls logs added sucessfully! \n");

    printf("\n\nOPERATION SUCCESSFULLY DONE! ");
}


void show_call_logs()
{
	pop_i();

    printf("\n\nOPERATION SUCCESSFULLY DONE! ");
}

void lost_sim()
{
    struct node *temp;
    long long int num;
    int check;
	temp=head;

    printf("Enter the contact number lost : ");
    scanf("%lld",&num);

    while(temp!=NULL)
    {
    	if(temp->contact==num)
    	{
    		strcpy(temp->status,"B");
    		break;
		}
		temp=temp->next;
	}

	printf("\n\nNumber BLOCKED!");

	printf("\n\nOPERATION SUCCESSFULLY DONE! ");
}






int main()
{
	drawbox(1,1,195,50,1);
	credits();
	delay(50);

	int t;

	printf("\n\n\n\n\n\tWELCOME TO OUR DATABASE. PLEASE LOGIN TO ENTER! \n");
	t=user_login();

	if(t==1)
	{
		int choice;


		choice=0;

			printf("\tAvailable choices are : \n\n");
			printf("\t1. Add Customer\n");
			printf("\t2. Update Customer information\n");
			printf("\t3. Search Customer\n");
			printf("\t4. Delete Customer\n");
			printf("\t5. Add log calls\n");
			printf("\t6. Show recent call logs\n");
			printf("\t7. Enter lost SIM Information\n");
			printf("\t8. Exit\n");

		while(choice!=8)
		{



			printf("\n\n\nEnter action number from the above mentioned list to be performed: ");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
				{
					add_customer();
					break;
				}

				case 2:
				{
					update_customer();
					break;
				}

				case 3:
				{
					search_customer();
					break;
				}
				case 4:
				{
					delete_customer();
					break;
				}

				case 5:
				{
					add_call_logs();
					break;
				}

				case 6:
				{
					show_call_logs();
					break;
				}


				case 7:
				{
					lost_sim();
					break;
				}

				default:
				break;
			}

		}

		if(choice==8)
		printf("\n\n\tThank you for using database. See You Soon!\n\n");
		return 0;
	}

	else
	printf("Thank you for using database. See you soon!\n\n");
}
