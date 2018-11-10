#pragma once 
#ifndef Order
#include<iostream>
#include<string>

using namespace std;

struct orders
{
public:
	int orderid;
	string clotheid;
	int quantity;
	double orderprice;
	string name;
	string address;
	string number;
	int delivery;
	orders* NEXT;
	orders*PREV;
}*HEAD,*TAIL;


class Orders
{
public:
	Orders()
	{
		HEAD = NULL;
		TAIL = NULL;
	}

	void insertorderatbeginning(int orderid, string clotheid, int quantity, double price, string name, string add, string number, int delivery)
	{


		orders* neworder = new orders;
		neworder->orderid = orderid;
		neworder->clotheid = clotheid;
		neworder->quantity = quantity;
		neworder->orderprice = price;
		neworder->name = name;
		neworder->address = add;
		neworder->number = number;
		neworder->delivery = delivery;
		neworder->NEXT = NULL;
		neworder->PREV = NULL;

		if (HEAD == NULL)
		{
			HEAD = TAIL = neworder;
		}
		else
		{
			neworder->NEXT = HEAD;
			HEAD = neworder;
			neworder->NEXT->PREV = neworder;
		}
	}

	void insertorderatend(int orderid, string clotheid, int quantity, double price, string name, string add, string number, int delivery)
	{


		orders* neworder = new orders;
		neworder->orderid = orderid;
		neworder->clotheid = clotheid;
		neworder->quantity = quantity;
		neworder->orderprice = price;
		neworder->name = name;
		neworder->address = add;
		neworder->number = number;
		neworder->delivery = delivery;
		neworder->NEXT = NULL;
		neworder->PREV = NULL;

		if (HEAD == NULL)
			HEAD = TAIL = neworder;
		else
		{
			TAIL->NEXT = neworder;
			neworder->PREV = TAIL;
			TAIL = neworder;
		}
	}

	void insertordersorted(string clotheid, int quantity, double price, string name, string add, string number, int delivery)
	{
		orders* previous = NULL;
		int random = rand();
		int orderid = random;
		orders* neworder = new orders;
		neworder->orderid = orderid;
		neworder->clotheid = clotheid;
		neworder->quantity = quantity;
		neworder->orderprice = price;
		neworder->name = name;
		neworder->address = add;
		neworder->number = number;
		neworder->delivery = delivery;
		neworder->NEXT = NULL;
		neworder->PREV = NULL;

		if (HEAD == NULL)
		{
			HEAD = TAIL = neworder;
		}
		else if (price<HEAD->orderprice)
		{
			insertorderatbeginning(orderid, clotheid, quantity, price, name, add, number, delivery);

		}
		else
		{

			orders* temp = HEAD;
			while (temp != NULL)
			{
				if (price > temp->orderprice)
				{
					previous = temp;
				}
				else
					break;
				temp = temp->NEXT;
			}
			if (temp == NULL)
			{
				insertorderatend(orderid, clotheid, quantity, price, name, add, number, delivery);
			}
			else
			{
				neworder->NEXT = previous->NEXT;
				previous->NEXT->PREV = neworder;
				previous->NEXT = neworder;
				neworder->PREV = previous;
			}
		}
	}

	void viewwholeorders()
	{
		orders* temp = HEAD;
		int i = 1;


		while (temp != NULL)
		{
			if (temp->delivery == 1)
			{
				cout << i << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
				cout << " Buyer name : " << temp->name << "  Address : " << temp->address << " Contact Number  : " << temp->number;
				cout << endl;
				i++;
			}
			temp = temp->NEXT;
		}
		cout << endl;
		orders* current = HEAD;
		while (current != NULL)
		{
			if (current->delivery == 0)
			{
				cout << i << " . " << current->orderid << "  " << current->clotheid << " Quantity : " << current->quantity << "  Price : " << current->orderprice << endl;
				cout << endl;

				i++;
			}
			current = current->NEXT;
		}

	}

	void deleteatbeginning()
	{
		orders* temp = HEAD;
		HEAD->NEXT->PREV = NULL;
		HEAD = HEAD->NEXT;
		cout << " Order to be deleted : ";
		if (temp->delivery == 1)
		{
			cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
			cout << " Buyer name : " << temp->name << "  Address : " << temp->address << " Contact Number  : " << temp->number;
			cout << endl;
		}
		else if (temp->delivery == 0)
		{
			cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
			cout << endl;
		}
		delete temp;

	}

	void deleteatend()
	{
		orders* temp = TAIL;
		TAIL->PREV->NEXT = NULL;
		TAIL = TAIL->PREV;
		cout << " Order to be deleted : ";
		if (temp->delivery == 1)
		{
			cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
			cout << " Buyer name : " << temp->name << "  Address : " << temp->address << " Contact Number  : " << temp->number;
			cout << endl;
		}
		else if (temp->delivery == 0)
		{
			cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
			cout << endl;
		}

		delete temp;
	}

	void deleteorder(int id)
	{
		int option;
		orders* previous = NULL;
		orders* temp = HEAD;
		while (temp->orderid != id)
		{
			previous = temp;
			temp = temp->NEXT;

			if (temp == NULL)
				break;
		}
		if (temp != NULL && temp->orderid == id)
		{
			if (temp == TAIL && temp == HEAD) // If only 1 order in the list
			{
				cout << " Order to be deleted : ";
				if (temp->delivery == 1)
				{
					cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
					cout << " Buyer name : " << temp->name << "  Address : " << temp->address << " Contact Number  : " << temp->number;
					cout << endl;
				}
				else if (temp->delivery == 0)
				{
					cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
					cout << endl;
				}
				delete temp;
				HEAD = TAIL = NULL;
			}
			else if (temp == TAIL)		// order to be deleted is at the end
			{
				deleteatend();
			}
			else if (temp == HEAD) // order to be deleted is at the starting
			{
				deleteatbeginning();
			}
			else
			{
				previous->NEXT = previous->NEXT->NEXT;
				temp->NEXT->PREV = previous;
				cout << endl << "Order to be deleted ";
				if (temp->delivery == 1)
				{
					cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
					cout << " Buyer name : " << temp->name << "  Address : " << temp->address << " Contact Number  : " << temp->number;
					cout << endl;
				}
				else if (temp->delivery == 0)
				{
					cout << endl << "1" << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
					cout << endl;
				}
				delete temp;
			}

		}
		else
		{
			cout << " No order avaialable with the ID : " << id << " . Thus no order will be deleted" << endl << endl;
		}
	}

	void viewordersonebyone()
	{
		orders* temp = HEAD;
		int i = 1, option;
		string name, address, phone;

		while (temp != NULL)
		{
			if (temp->delivery == 1)
			{
				cout << i << " . " << temp->orderid << "  " << temp->clotheid << " Quantity : " << temp->quantity << "  Price : " << temp->orderprice << endl;
				cout << " Buyer name : " << temp->name << "  Address : " << temp->address << " Contact Number  : " << temp->number;
				cout << endl;

				if (i == 1)
				{
					cout << "1.Next order" << endl;
					cout << "2. Modify Order " << endl;
					cout << "3. Delete Order " << endl;
					cout << "4. Go back to mainmenu " << endl;
					cin >> option;
					cout << endl;
					switch (option)
					{
					case 1:
						temp = temp->NEXT;
						i++;
						break;
					case 2:
						system("CLS");
						cout << endl << "--------- Modify Delivery Details ----------" << endl;
						cout << endl << "Enter the name : ";
						getline(cin, name);
						getline(cin, name);
						cout << endl << "Enter the address : ";
						getline(cin, address);
						cout << endl << "Enter the phone number : ";
						getline(cin, phone);
						temp->name = name;
						temp->address = address;
						temp->number = phone;
						cout << endl << "Modified Succefully";
						cout << endl;
						return;
					case 3:
						deleteorder(temp->orderid);
						cout << endl;
						return;
					case 4:
						return;

					}
				}
				else
				{
					cout << "1.Next order" << endl;
					cout << "2. Modify Order " << endl;
					cout << "3. Delete Order " << endl;
					cout << "4. Previous order" << endl;
					cout << "5. Go back to mainmenu " << endl;
					cin >> option;
					cout << endl;

					switch (option)
					{
					case 1:
						temp = temp->NEXT;
						i++;
						break;
					case 2:
						system("CLS");
						cout << endl << "--------- Modify Delivery Details ----------" << endl;
						cout << endl << "Enter the name : ";
						getline(cin, name);
						cout << endl << "Enter the address : ";
						getline(cin, address);
						cout << endl << "Enter the phone number : ";
						getline(cin, phone);

						temp->name = name;
						temp->address = address;
						temp->number = phone;

						cout << endl << "Modified Succefully";

						cout << endl;
						return;
					case 3:
						deleteorder(temp->orderid);
						cout << endl;
						return;
					case 4:
						temp = temp->PREV;
						i--;
						break;
					case 5:
						return;

					}
				}
			}
			else
				temp = temp->NEXT;

		}
		cout << endl;
		orders* current = HEAD;
		while (current != NULL)
		{
			if (current->delivery == 0)
			{
				cout << i << " . " << current->orderid << "  " << current->clotheid << " Quantity : " << current->quantity << "  Price : " << current->orderprice << endl;
				cout << endl;


				if (i == 1 && current == HEAD)
				{
					cout << "1.Next order" << endl;
					cout << "2. Delete order" << endl;
					cout << "3. Go back to mainmenu " << endl;
					cin >> option;
					cout << endl;

					switch (option)
					{
					case 1:
						current = current->NEXT;
						i++;
						break;
					case 2:
						deleteorder(current->orderid);
						cout << endl;
						return;
					case 3:
						return;

					}
				}
				else
				{
					cout << "1.Next order" << endl;
					cout << "2. Delete order" << endl;
					cout << "3. Previous order" << endl;
					cout << "4. Go back to mainmenu " << endl;
					cin >> option;
					cout << endl;

					switch (option)
					{
					case 1:
						current = current->NEXT;
						i++;
						break;
					case 2:
						deleteorder(current->orderid);
						cout << endl;
						return;
					case 3:
						current = current->PREV;
						i--;
						break;
					case 4:
						return;
					}
				}
			}
			else
				current = current->NEXT;

		}
	}

};


















#endif // !Order
