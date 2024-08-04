
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>




   /// Update & Insert Function
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);

     /// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

    ///Delete 
void deletefood(int serial);

 ///START Structure Here

struct Node
{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};

   ///Global Type

typedef struct Node node ;

node *head, *list;

int main()
{
	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	char bur[] ="Burger";
	char piz[] ="pizza";
	char hot[] ="hot cake";
	char cof[] ="coffee";
	char ice[] ="ice-cream";
	char sand[] ="sandwich";
	char gri[] ="grill";
	char nun[] ="nun-bread";
	char cold[] ="cold drinks";
	

	head = NULL;
	insertfirst(1,bur ,23,100);
	insertend(2,piz,13,120);
	insertend(3,hot,8,150);
	insertend(4,cof,46,20);
	insertend(5,ice,46,50);
	insertend(6,sand,34,70);
	insertend(7,gri,7,200);
	insertend(8,nun,121,40);
	insertend(9,cold,73,25);

	mainmenu:

	main_menu();

	int main_menu_choice;

 fflush(stdin); 
 scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1)
		{

			foodlist:

			
			printf("=> 0. Main Menu ");
			foodlist();


		}

		else if( main_menu_choice == 2)
		{

			adminpanelchoice:

			int admin_panel_choice;

			     
			printf("1. Main Menu\n\n\t"); 
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");


			fflush(stdin);  
			scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==123321)
			{



				node *temp;

				temp = list;

				adminchoice:

				 printf("You are on Admin Pannel\n\n");
				
				printf(" 1. Total Cash Today \n\n");
				printf(" 2. View Card Pay \n\n");
				printf(" 3. Add Food \n\n");
				printf(" 4. Delete Food \n\n");			
				printf(" 5. Instant Food List \n\n");
				printf(" 6. Main Menu \n\n");
				printf("Enter Your From 1-6: ");
			

				int adminchoice;



				fflush(stdin);   scanf("%d",&adminchoice);

				if(adminchoice==1){

				   printf("Todays Total Cash : %0.2f  \n",totalmoney);

		

					goto adminchoice;
				}
				else if(adminchoice==2)
				{

					if(c!=0)
					{

		

						printf(" ____________________________\n");
						printf("|   Card NO.   |   Money $   |\n");
						printf("------------------------------\n");

						for(int z=1; z<=c;z++){

							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);
							printf("------------------------------\n");
				

						}
					
					}

					if(c==0){

				
					printf("No Card History\n");}
				
					goto adminchoice;
				}

				else if(adminchoice==3){

					foodadd:
				

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


				      printf(" \nEnter Food Name :  ");

					fflush(stdin);    
					 scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);

				
					printf(" \nEnter Food Quantity :  ");

					scanf("%d",&fquantity); fflush(stdin);

                        foodserial:
				  printf(" \nEnter Food Serial :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                     printf("\n Food Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                       goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

				 printf("\n Enter Food Price :  ");fflush(stdin);

					scanf("%f",&fprice);



					 printf("Submiting your data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}


					insertend(fdata,ffoodname,fquantity,fprice);

				     printf("Adding Food  Successfull....\n");

					

					goto adminchoice;

				}
				else if(adminchoice==4){

				
					printf("Enter Serial No of the Food To Delete : ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
					 printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}


					goto adminchoice;
				}

				else if(adminchoice==5)
				{

					
					    foodlist(); 
						

					  printf("1. <-- back  \n\n");



					fflush(stdin);   scanf("%d",&any);

					goto adminchoice;

				}

				

                        
		
				
				else if(adminchoice==6)
				{

					goto mainmenu;
				}

				else{
			
				printf("Please Select From List :  ");
					goto adminchoice;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
		  
			printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
		
		 printf("Thank You For Using Our System \n\n\n\n\n\n\n");
		

			exit(1);

		}

	}
	else{
		
		 printf("Please Enter Correct Choice"); 
		goto mainmenu;
	}


	int get_food_choice;



	fflush(stdin);
	printf("\nPlace Your Order: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
		  
			printf("\nPlease Choice From List: "); 
			
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:

		printf("Enter Food Quantity : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity);



		if(fcquantity==0){
			 
			 printf("Quantity Can not be Zero "); 
			 
			
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			
			 printf("Out of Stock ! "); 

			goto foodlist;
		}

	 
		printf("Choice food %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);
		printf("1. Confirm to buy this \n\n");
		printf("2. Food List \n\n");
		printf("Press 1 to confirm and 2 to back to list :");

		confirm:
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 )
		{

			
			printf(" 1. Cash ");
			
            printf(" 2. Credit\Debit\n");
            printf("Select Method Of payment 1-2: ");
			payment:
			int payment;

			fflush(stdin);  scanf("%d",&payment);

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				  
				printf("===>THANK YOU<===");
				  
				printf("Food Ordered Successfully ...");
			 
			 printf("1. Wanna Buy Another Delicious ? ");
				
				 printf("2. Main Menu \n");
				 
				 printf("Select: ");
				psmenu:
				int ps_menu;

				fflush(stdin);  scanf("%d",&ps_menu);

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{printf("Please Choice from list : "); goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){

				int card_number[100];

				c++;

				
				printf("Enter Your Card No : ");

				fflush(stdin);   scanf("%d",&card_number[c]);



				cardno[c] = card_number[c];

				int pin;

				 
				 printf("Enter Your Card Pin [we never save your pin]  : ");

				fflush(stdin);     
				scanf("%d",&pin);

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				 
				 printf("Payment Success...");
				   
				 printf("1. Wanna Buy Another Delicious ? ");
				 
				 printf("2. Main Menu \n");
				  
				 printf("select: ");
				psmenu2:
				int ps_menu2;

				scanf("%d",&ps_menu2);

				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{printf("Please Choice from list : "); goto psmenu2;}

			}

			else{

				  
				 printf("Enter Choice from List : ");

				goto payment;


			}


		}    ///END Confirm Y/y



		else if(confirm == 2){

			goto foodlist;

		}

		else{
			   
			 printf("Enter choice from List : ");

			goto confirm;


		}  


	}  


	else{

		 
		 printf("Please Choice From List "); 

		goto foodlist;

	}  
}


void main_menu()
{

 printf("===> 1. Food List\n"); 

 printf("===> 2. Admin Panel\n");

 printf("===> 3. Exit\n"); 
	
}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

	//    free(temp);
}

void deletefood(int serial)
{

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial)
	{

		while(temp->next->data != serial)
		{
			temp = temp->next;
		}

		if(temp->next->data == serial)
		{

			temp->next = temp->next->next;
		
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
			for(int cs=0;cs<4;cs++)
			{
			printf(" .");

			printf("\n\n\n\n\t\t\tDeleted Successfylly \n");

		    }
	    }
		else
		{
			printf("\n\n\n\n\t\t\tFood Item Not Found\n"); 
		}

		head = temp ;
	}

 
	else
	{

		temp = temp->next;
		
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
		for(int cs=0;cs<4;cs++)
		{ 
		printf(" .");

		printf("\n\n\n\n\t\t\tDeleted Successfully \n"); 

		head = temp ;

		list=head;
	
	    }
}
}


void updatefood(int udata, int uquantity)
{



	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}
}





void foodlist()
{

	

	printf("\n\t\t"); 
	printf("______________________________________________________ ");
	printf("\n\t\t"); 
	printf("|  Food No.  |   Food Name   |  Price  |   In Stock   |");
	printf("\n\t\t"); 
	printf("-------------------------------------------------------");

	node *temp;

	temp = list;

	while(temp != NULL){

		


		printf("\n\t\t"); 
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		
		printf("\n\t\t"); 
		printf("-------------------------------------------------------");


		temp = temp->next ;

		

	}



}


void order_view(int order, int quantity, int or_no)
{





	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){



		printf("\n\t\t"); 
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);
	
		printf("\n\t\t"); 
		printf("-------------------------------------------------------");

	

	}



}





