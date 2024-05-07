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
#include<time.h>
#include<string.h>

void receipt(item food[], item drink[], ordered orders[], int foodCount, float subtotal, float discount, float total)
{
	time_t current_time=time(NULL);
	struct tm*tm=localtime(&current_time);

	printf("----------------------------------------------------------------\n");
	printf("\t\tNo plans All vibes Restaurant\n");
	printf("----------------------------------------------------------------\n");
	printf("\t\tMultimedia University (MMU)\n");
	printf("\tOnly beautiful human are allowed in this restaurant\n");
	printf("\t\t%s\n",asctime(tm));

	printf("----------------------------------------------------------------\n");
	printf("ITEM				QUANTITY	PRICE(RM)\n\n");
	for(int i = 0; i<foodCount; ++i)
	{
		if(orders[i].code>=1000)
			printf("%-30s\t    %d\t\t%.2f\n",drink[orders[i].code-1000].name,orders[i].qty,drink[orders[i].code-1000].price*orders[i].qty);
		else
			printf("%-30s\t    %d\t\t%.2f\n",food[orders[i].code].name,orders[i].qty,food[orders[i].code].price*orders[i].qty);
	}
	printf("\n\n");
	printf("\t\t\t\tSubtotal: \tRM %.2f\n",subtotal);
	printf("\t\t\t\tDiscount: \tRM %.2f\n",discount);
	printf("\t\t\t\tTotal   : \tRM %.2f\n\n",total);
	printf("THANKS FOR VISITING!\n\n");

	return;



}

void receiptTXT(item food[], item drink[], ordered orders[], int foodCount, float subtotal, float discount, float total)
{
	FILE *file=fopen("receipt.txt","w");
	time_t current_time=time(NULL);
	struct tm*tm=localtime(&current_time);

	fprintf(file, "----------------------------------------------------------------\n");
	fprintf(file, "\t\tNo plans All vibes Restaurant\n");
	fprintf(file, "----------------------------------------------------------------\n");
	fprintf(file, "\t\tMultimedia University (MMU)\n");
	fprintf(file, "\tOnly beautiful human are allowed in this restaurant\n");
	fprintf(file, "\t\t%s\n",asctime(tm));

	fprintf(file, "----------------------------------------------------------------\n");
	fprintf(file, "ITEM						QUANTITY	PRICE(RM)\n\n");
	for(int i = 0; i<foodCount; ++i)
	{
		if(orders[i].code>=1000)
			fprintf(file, "%-30s\t    %d\t\t%.2f\n",drink[orders[i].code-1000].name,orders[i].qty,drink[orders[i].code-1000].price*orders[i].qty);
		else
			fprintf(file, "%-30s\t    %d\t\t%.2f\n",food[orders[i].code].name,orders[i].qty,food[orders[i].code].price*orders[i].qty);
	}
	fprintf(file, "\n\n");
	fprintf(file, "\t\t\t\t\t\tSubtotal: \tRM %.2f\n",subtotal);
	fprintf(file, "\t\t\t\t\t\tDiscount: \tRM %.2f\n",discount);
	fprintf(file, "\t\t\t\t\t\tTotal   : \tRM %.2f\n\n",total);
	fprintf(file, "THANKS FOR VISITING!\n\n");

	fclose(file);
	return;



}


void report(item foodList[], int foodCount, int drinksCount, item drinksList[], float total){
	
	int x;
	
	
	FILE *fptr = fopen("report.txt", "w");
	fprintf(fptr,"Food \n");
	for(x = 0; x < foodCount - 1; x++)
	{
	fprintf(fptr, "%d. %s \n Quantity Sold: %d  \n\n", foodList[x].count, foodList[x].name, foodList[x].sold);
	}

	fprintf(fptr,"-----------------------------------------------------\n\n Drinks \n");

	for(x = 0; x < drinksCount - 1; x++)
	{
	fprintf(fptr, "%d. %s \n Quantity Sold: %d  \n\n", drinksList[x].count, drinksList[x].name, drinksList[x].sold);
	}

	fprintf(fptr, "-----------------------------------------------------\n\nTotal Revenue: %.2f \n", total);

	fclose(fptr);
}