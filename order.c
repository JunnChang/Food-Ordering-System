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
int orderFood(ordered itemsCode[], item menu[], int y, int count){
	char cont;
	do{
    printf("Please Enter Food Code: ");
    scanf(" %d", &itemsCode[y].code);
	itemsCode[y].code -= 1;

	if (itemsCode[y].code > (count - 2)){
		printf("Invalid Code\n");
		cont = 'Y';
		continue;
	}
    printf("Quantity: ");
    scanf("%d", &itemsCode[y].qty);
	while(getchar() != '\n');
	if ((itemsCode[y].qty + menu[itemsCode[y].code].sold) > 100){
		printf("Sold out!\n");
		cont = 'Y';
		continue;
	}
	else if(itemsCode[y].qty <= 0){
		printf("Please enter a valid quantity\n");
		cont = 'Y';
		continue;
	}
	
	menu[itemsCode[y].code].sold += itemsCode[y].qty;
    y++;

	printf("Continue?(Y/N): ");
	scanf(" %c", &cont);
	while(getchar() != '\n');
	}while (cont == 'Y' || cont ==  'y');
	
	return y;
}

int orderDrink(ordered itemsCode[], item menu[], int y, int count){
	char cont;
	do{
    printf("Please Enter Drinks Code: ");
    scanf(" %d", &itemsCode[y].code);
	itemsCode[y].code += 999;

	if ((itemsCode[y].code - 1000) > (count - 2)){
		printf("Invalid Code\n");
		itemsCode[y].code = -1;
		cont = 'Y';
		continue;
	}
    printf("Quantity: ");
    scanf("%d", &itemsCode[y].qty);
	while(getchar() != '\n');
	if ((itemsCode[y].qty + menu[itemsCode[y].code - 1000].sold) > 100){
		printf("Sold out!\n");
		itemsCode[y].code = -1;
		itemsCode[y].qty = 0;
		cont = 'Y';
		continue;
	}
	else if(itemsCode[y].qty <= 0){
		printf("Please enter a valid quantity\n");
		cont = 'Y';
		continue;
	}
	
	menu[itemsCode[y].code - 1000].sold += itemsCode[y].qty;
    y++;

	printf("Continue?(Y/N): ");
	scanf(" %c", &cont);
	while(getchar() != '\n');
	}while (cont == 'Y' || cont == 'y');
	
	return y;
}