#pragma once
#ifndef Clothe
#include<iostream>
#include<string>
#include <cstdlib>
#include"Order.h"

using namespace std;

struct clothes {

public:
	string itemid;
	string type;
	string description;
	int quantity;
	string colour;
	string size;
	int price;
	clothes* next;
	clothes* prev;

} *head,*tail;

class Clothes
{
public:
	
	 Clothes()
	{
		 head = NULL;
		 tail = NULL;
		 
	}

	 Orders o;
	

	void insertclothesatend(string id, string Type, string Description, int Q, string color, string S, int P)
	{
		clothes* newclothe = new clothes;
		newclothe->itemid = id;
		newclothe->type = Type;
		newclothe->description = Description;
		newclothe->quantity = Q;
		newclothe->colour = color;
		newclothe->size = S;
		newclothe->price = P;
		newclothe->next = NULL;
		newclothe->prev = NULL;

		if (head == NULL)
		{
			head = tail = newclothe;

		}
		else
		{
			tail->next = newclothe;
			newclothe->prev = tail;
			tail = newclothe;
		}

	}


	void insertclothesatbeginning(string id, string Type, string Description, int Q, string color, string S, int P)
	{
		clothes* newclothe = new clothes;
		newclothe->itemid = id;
		newclothe->type = Type;
		newclothe->description = Description;
		newclothe->quantity = Q;
		newclothe->colour = color;
		newclothe->size = S;
		newclothe->price = P;
		newclothe->next = NULL;
		newclothe->prev = NULL;

		if (head == NULL)
		{
			head = tail = newclothe;

		}
		else
		{
			newclothe->next = head;
			head = newclothe;
			newclothe->next->prev = newclothe;
		}

	}
	
	
	void insertclothessorted(string id, string Type, string Description, int Q, string color, string S, int P)
	{
		clothes* previous = NULL;
		clothes* newclothe = new clothes;
		newclothe->itemid = id;
		newclothe->type = Type;
		newclothe->description = Description;
		newclothe->quantity = Q;
		newclothe->colour = color;
		newclothe->size = S;
		newclothe->price = P;
		newclothe->next = NULL;
		newclothe->prev = NULL;
		if (head == NULL)
		{
			head = tail = newclothe;
		}
		else if (P < head->price)
		{
			insertclothesatbeginning( id,  Type,  Description,  Q,  color,  S,  P);

		}
		else
		{
			
			clothes* temp = head;
			while (temp != NULL)
			{
				if (P > temp->price)
				{
					previous = temp;
				}
				else
					break;
				temp = temp->next;
			}
			if (temp == NULL)
			{
				insertclothesatend(id, Type, Description, Q, color, S, P);
			}
			else
			{
				newclothe->next = previous->next;
				previous->next->prev= newclothe;
				previous->next = newclothe;
				newclothe->prev = previous;
			}
		}

	}

	void viewwholeclothes()
	{
		clothes* temp = head;
		int i = 1;
		
		while (temp != NULL)
		{
			cout << i << ". " << temp->itemid << " : " << temp->type << " - " << temp->description << " Colour : " << temp->colour;
			cout << "  Quantity : " << temp->quantity << " Size : " << temp->size << " Price : " << temp->price;
			cout << endl;
			temp = temp->next;
			i++;
		}
		cout << endl;


	}
	
	void searchitem(string Type)
	{
		clothes* temp = head;
		int i = 1; int option, leftquantity;
		bool value = false;
		
			while (temp != NULL)
			{
				if (!(temp->type.find(Type)))
				{

					if (i == 1)

					{
						cout << "Products found as per search are : \n" << endl;
					}

					cout << i << ". " << temp->itemid << " : " << temp->type << " - " << temp->description << " Colour : " << temp->colour;
					cout << "  Quantity : " << temp->quantity << " Size : " << temp->size << " Price : " << temp->price;
					cout << endl;
					i++;
					value = true;

					cout << " Press 1. To check out this product   2. Continue with search "<<endl;
					cin >> option;
					if (option == 1)
					{
						system("CLS");
						leftquantity = checkout(temp->itemid, temp->quantity, temp->size, temp->price);
						temp->quantity -= leftquantity;
						cout << endl;
						return;

					}
					else
						temp = temp->next;
				}
				temp = temp->next;
			}
			if (value == false)
			{
				cout << "\n No product are available of type " << Type << " in the system" << endl;
			}
		
	}

	int checkout(string id, int quantity, string size, int price)
	{
		try {
			string name, address; string no;
			int orderquantity = 0;
			orders* temp = HEAD;

			cout << "Enter the Quantity you want to buy" << endl;
			cin >> orderquantity;
			if (orderquantity > quantity)
			
				cout << "Please choose available quantity" << endl;
				
			else
			{
				
				int delivery;
				double orderprice = price*orderquantity;
				int Option;
				cout << " Require Delivery " << endl;
				cout << "1.Yes   2. No" << endl;
				cin >> Option;
				if (Option == 1)
				{
					delivery = 1;
					cout << "Enter buyer's name  :";
					getline(cin, name);
					getline(cin, name);
					cout << endl << "Enter Address  :";
					getline(cin, address);
					cout << endl << "Enter Contact Number  :";
					cin >> no;

					cout << endl << "Order price : " << orderprice << endl;
					cout << "Delivery charge : 50" << endl;
					orderprice += 50;
					cout << "Total charge :" << orderprice << endl;
					o.insertordersorted(id, orderquantity, orderprice, name, address, no, delivery);
				}

				else if (Option == 2)
				{
					delivery = 0;
					cout << endl << "Order price " << orderprice;
					o.insertordersorted(id, orderquantity, orderprice, " "," "," ", delivery);
				}
				double received;
				cout << " Amount Received : ";
				cin >> received;
				cout << endl << " Balance : " << received - orderprice;
				return orderquantity;
			}
			return 0;
			
		}catch(exception ){}
	}

	void viewclothesonebyone()
	{
		clothes* temp = head;
		int i = 1, option;

		while (temp != NULL)
		{
			cout << i << ". " << temp->itemid << " : " << temp->type << " - " << temp->description << " Colour : " << temp->colour;
			cout << "  Quantity : " << temp->quantity << " Size : " << temp->size << " Price : " << temp->price;
			cout << endl;
			int leftquantity;
			if (i == 1)
			{
				cout << "1.Next product" << endl;
				cout << "2. Check out " << endl;
				cout << "3. Go back to mainmenu " << endl;
				cin >> option;
				cout << endl;

				switch (option)
				{
				case 1:
					temp = temp->next;
					i++;
					break;
				case 2:
					system("CLS");
					leftquantity=checkout(temp->itemid,temp->quantity,temp->size,temp->price);
					temp->quantity -= leftquantity;
					cout << endl;
					return;
				case 3: 
					return;

				}
			}

			else
			{
				cout << "1.Next product" << endl;
				cout << "2. Check out " << endl;
				cout << "3. Previous product" << endl;
				cout << "4. Go back to mainmenu " << endl;
				cin >> option;
				cout << endl;

				switch (option)
				{
				case 1:
					temp = temp->next;
					i++;
					break;
				case 2:
					system("CLS");
					cout << endl<<endl<<"Proceeding to check out .....";
					system("CLS");
					leftquantity=checkout(temp->itemid, temp->quantity, temp->size, temp->price);
					temp->quantity -= leftquantity;
					cout << endl;
					return;
				case 3:
					temp = temp->prev;
					i--;
					break;
				case 4: 
					return;

				}
			}
		}
	}

};











#endif // !Header
