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

float calc(item foodList[], item drinksList[], ordered itemsCode[], int i)
{
	float total = 0;
	
	for(int j = 0; j < i; j++){
        if(itemsCode[j].code >= 0 && itemsCode[j].code < 1000){
            total = total + foodList[itemsCode[j].code].price * itemsCode[j].qty;
        }
        else if(itemsCode[j].code >= 1000){
            total = total + drinksList[itemsCode[j].code-1000].price * itemsCode[j].qty;
        }
		else if(itemsCode[j].code == -1)
    	    break;
    }
	return total;
}


float get_discount(float total)
{
	char voucher;
	int option;
	float percentage = 0, discount = 0;

	printf("\nDo you have voucher? [Y/N]: ");
	scanf(" %c", &voucher);
		
	if(voucher == 'Y' || voucher == 'y')
	{
		do{
		printf("\n10%% (Enter 1)	20%% (Enter 2)	Quit (Enter 3): ");
		scanf("%d", &option);

		switch(option){
			case 1 :
				percentage = 0.10;
				break;

			case 2 :
				percentage = 0.20;
				break;

			case 3 :
				break;
				
			default :
				printf("Invalid number. Please enter again.");
		}
		}while(option >= 4);
	}
	discount = total * percentage;
	return discount;
}
