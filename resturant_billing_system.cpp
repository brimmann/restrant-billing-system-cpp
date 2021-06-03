#include <iostream>
#include <string>
#define SIZE 8
#define MAX_SEL 20
using namespace std;
struct food
{
	string name;
	float price;
};

void InitMenu(food []);
void ShowMenu(food []);
void PrintBill(food [], const int &);

int main()
{
	food menu[SIZE];
	food selectedItems[MAX_SEL];
	int option, track = 0;
	InitMenu(menu);
	ShowMenu(menu);
	while(true)
	{
		cout << "Select item: ";
		int qnt;
		cin >> option;
		if(option == 0)
			break;
		selectedItems[track].name = menu[option-1].name;
		cout << "Quantity: "; cin >> qnt;
		selectedItems[track].price = qnt * menu[option-1].price;
		track++;
	}
	PrintBill(selectedItems, track);
	return 0;
}

void InitMenu(food arr[])
{
	arr[0].name = "Plain Egg";
	arr[0].price = 1.45;
	arr[1].name = "Bacon and Egg";
	arr[1].price = 2.45;
	arr[2].name = "Muffin";
	arr[2].price = 0.99;
	arr[3].name = "French Toast";
	arr[3].price = 1.99;
	arr[4].name = "Fruit Basket";
	arr[4].price = 2.49;
	arr[5].name = "Cereal";
	arr[5].price = 0.69;
	arr[6].name = "Coffbee";
	arr[6].price = 0.50;
	arr[7].name = "Tea";
	arr[7].price = 0.75;
}

void ShowMenu(food arr[])
{
	char spaceArr[40]; 
	int spaceSize;
	cout << "Welcome to Happy resturant!" << endl;
	cout << "No  Name                       Price" << endl;
	for(int i = 0; i < SIZE; i++)
	{
		cout << i+1 << ":  " << arr[i].name;
		spaceSize = 27-arr[i].name.length();
		for(int i = 0; i < 40; i++) {spaceArr[i] = '\0';}
		for(int i = 0; i < spaceSize; i++){spaceArr[i] = ' ';}
		cout << spaceArr << "$" << arr[i].price << endl;
	}
	cout << "Enter 0 to exit" << endl;
	
}

void PrintBill(food arr[], const int &n)
{
	char spaceArr[40]; 
	int spaceSize;
	float total = 0;
	cout << "Name                    Price" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << arr[i].name;
		spaceSize = 24-arr[i].name.length();
		for(int i = 0; i < 40; i++) {spaceArr[i] = '\0';}
		for(int i = 0; i < spaceSize; i++){spaceArr[i] = ' ';}
		cout << spaceArr << "$" << arr[i].price << endl;
		total += arr[i].price;
	}
	total += total * 5.0/100.0;
	cout << "Total + Tax: " << "$" << total;
}



