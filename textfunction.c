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

int itemCount(FILE *file){
	int line = 1;
	char c;
	fseek(file, 0, SEEK_SET);
	do{
		c = fgetc(file);
		if (c == '\n'){
			line ++;
		}
	}while (c != EOF);
	return line;
}


void add(FILE *file, int count, const char *item){
	char buffer[50];
	float price;
	while(getchar() != '\n');
	printf("Enter %s name: ", item);
	gets(buffer);
	printf("Enter selling price: ");
	scanf("%f", &price);
	while (getchar() != '\n');
			
	fprintf(file, "%d,%s,%.2f\n", count, buffer, price);

	return;
}


void read(FILE * file, item items[]){
	int read, records, i = 0;
	fseek(file, 0, SEEK_SET);

	do{
		read = fscanf(file, "%d,%49[^,],%f\n", &items[i].count, items[i].name, &items[i].price);
		items[i].sold = 0;
		if (read == 3){
			i++;
		}
	}while(!feof(file));

	return;
}

void display(item menu[], int counter){
	for(int i = 0; i < counter - 1; i++){
			printf("%d, %-30s: RM%.2f\n", i+1, menu[i].name, menu[i].price);
		}
}
