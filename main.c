/********************************************
Course: DCP5101 Program Design
Assignment: 1
Session: T2215
Group Name: No PLans All Vibes
ID & Name 1: 1221203841, Ng Xhun Yan;
Phone,Email: 011-11758845, edmundngxhunyan@gmail.com;
ID & Name 2: 1221203116, Amanda Bee Jing Ying;
Phone,Email: 018-3528014, amanda1224.jyb@gmail.com;
ID & Name 3: 1221203579, Law Ther Shin;
Phone,Email: 011-20092997, tslaw23@gmail.com;
ID & Name 4: 1221202725, Chang Tek Junn;
Phone,Email: 017-5915322, junnchang345@gmail.com;
********************************************/

#include<stdio.h>
#include<string.h>
#include<time.h>

typedef struct{
	int count;
	char name[50];
	float price;
	int sold;
}item;

typedef struct{
	int code;
	int qty;
}ordered;

#include "textfunction.c"
#include "cal.c"
#include "receipt.c"
#include "order.c"



int main(){
	FILE *food = fopen("food.txt", "a+");
	FILE *drinks = fopen("drinks.txt", "a+");
	int choice = 0, foodCount, drinksCount, orders = 0, todayOrder;
	float total, discount, subTotal, gTotal = 0;
	
	
	if (!food || !drinks){
		printf("Error opening file\n");
		return 1;
	}
	while(choice != 3){
		do{
			printf("Enter 1 for new order, Enter 2 for adding item into list, Enter 3 to end program: ");
			scanf("%d", &choice);
			if (choice != 1 && choice != 2 && choice != 3 ){
				printf("Invalid input, please enter again!\n");
			}
		}while(choice != 1 && choice != 2 && choice != 3);

		if (choice == 3){
			printf("Program ended!");
			return 2;
		}
		if (choice != 2){
			int confirm;
			do{
				printf("\n\nAre you sure not to add item list? You will NOT be able to add food unless program restarted!!\n\n");
				printf("Enter 1 to proceed to order, 2 to add item\n");
				scanf("%d", &confirm);
				if (confirm == 1){
					choice = 1;
				}
				else if(confirm == 2){
					choice = 2;
				}
				else{
					printf("Instruction not valid, please reenter!\n");
				}
			}while(confirm != 1 && confirm != 2);
		}

		if (choice == 1){
			break;
		}

		
		foodCount = itemCount(food);
		drinksCount = itemCount(drinks);
		
		if (choice == 2){
			int append;
			printf("Enter 1 for food, Enter 2 for drink: ");
			scanf("%d", &append);
			if (append == 1){
				add(food, foodCount, "food");
				foodCount ++;
			}
			else if (append == 2){
				add(drinks, drinksCount, "drinks");
				drinksCount ++;
			}
			continue;
		}
	}
	foodCount = itemCount(food);
	drinksCount = itemCount(drinks);
	item foodList[foodCount - 1];
	item drinksList[drinksCount - 1];
	read(food, foodList);
	read(drinks, drinksList);

	char newOrder;
	do{

		printf("Enter 'Y' for NEW ORDER, Enter 'N' to end business for today: ");
		scanf(" %c", &newOrder);
		while (getchar() != '\n');
		if (newOrder == 'n' || newOrder == 'N'){
			break;
		}
		
		ordered order[50];
		orders = 0;
		while (orders != 3){
			int i = 0;
			do {
				printf("Enter 1 to order Food, 2 to order drinks, 3 to end current order : ");
				scanf("%d", &orders);
				if (orders == 1){
					printf("\n\tFood Menu \n\n");
					display(foodList, foodCount);
					i = orderFood(order, foodList, i, foodCount);
					
				}
				else if(orders == 2){
					printf("\n\tDrinks Menu \n\n");
					display(drinksList, drinksCount);
					i = orderDrink(order, drinksList, i, drinksCount);
				}
				else if (orders == 3){
					break;
				}
				else{
					printf("Invalid Instruction!!\n");
				}
			}while (orders != 3);

			todayOrder ++;

			// calculate here thank you :)
			subTotal = calc(foodList, drinksList, order, i);
			discount = get_discount(subTotal);
			total = subTotal - discount;
			gTotal += total;
			receipt(foodList, drinksList, order, i, subTotal, discount, total);
			receiptTXT(foodList, drinksList, order, i, subTotal, discount, total);
		}


	}while(newOrder != 'n' || newOrder != 'N');
	// Generate report here
	//call up function
	report(foodList, foodCount, drinksCount, drinksList, gTotal);
	printf("Report Generated, Have A Good Day!");
	fclose(food);
	fclose(drinks);

	return 0;
}
