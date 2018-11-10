
#include<iostream>
//#include "Clothe.h"
#include<cstdlib>
//#include "Order.h"

using namespace std;


struct clothes {				//Doubly Linked list created to store details of clothes

public:
	string itemid;
	string type;
	string description;
	int quantity;
	string colour;
	string size;
	double price;
	clothes* next;
	clothes* prev;

} *head, *tail;				// Two pointers to locate the starting and ending of the list

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
}*HEAD, *TAIL;


class Orders
{
	Orders()
{
	

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
		try {
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
		catch (exception_ptr) { cout << endl << "List is empty " << endl; }
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
class Clothes
{
public:

	Clothes()			//Constructer to set the list to NULL
	{

	}

	Orders o;

	void deleteAll()
	{
		clothes* temp = head;

		while (temp != NULL)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	void insertclothesatend(string id, string Type, string Description, int Q, string color, string S, double P)
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


	void insertclothesatbeginning(string id, string Type, string Description, int Q, string color, string S, double P)
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


	void insertclothessorted(string id, string Type, string Description, int Q, string color, string S, double P)
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
		else if (P < head->price)			//Since clothes are arranged from lowest to highest 
		{
			insertclothesatbeginning(id, Type, Description, Q, color, S, P);

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
				previous->next->prev = newclothe;
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
		bool value = false;			//To find if product found or not

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
				cout << " Press 1. To check out this product   2. Continue with search " << endl;
				cin >> option;
				if (option == 1)
				{
					system("CLS");
					leftquantity = checkout(temp->itemid, temp->quantity, temp->size, temp->price);
					temp->quantity -= leftquantity; // Update quantity in the list after checkout
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
					o.insertordersorted(id, orderquantity, orderprice, " ", " ", " ", delivery);
				}
				double received;
				cout << " Amount Received : ";
				cin >> received;
				cout << endl << " Balance : " << received - orderprice;
				return orderquantity;
			}
			return 0;

		}
		catch (exception) {}
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
					leftquantity = checkout(temp->itemid, temp->quantity, temp->size, temp->price);
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
					cout << endl << endl << "Proceeding to check out .....";
					system("CLS");
					leftquantity = checkout(temp->itemid, temp->quantity, temp->size, temp->price);
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
int main()
{

	Clothes c;
	Orders o;

	HEAD = NULL;
	TAIL = NULL;

	head = NULL;
	tail = NULL;

	clothes values[5];

	values[0].itemid = 8401;
	values[0].itemtype = "Jeans";
	values[0].itemdescription = "Short Jeans";
	values[0].itemcolour = "Blue";
	values[0].itemquantity = 7;
	values[0].itemsize = "L";
	values[0].itemprice = 79.9;

	values[1].itemid = 2442;
	values[1].itemtype = "Shirts";
	values[1].itemdescription = "Long Sleeve T Shirt";
	values[1].itemcolour = "Red";
	values[1].itemquantity = 4;
	values[1].itemsize = "XL";
	values[1].itemprice = 37.9;

	values[2].itemid = 2109;
	values[2].itemtype = "Shirts";
	values[2].itemdescription = "Mickey Mouse T Shirt";
	values[2].itemcolour = "Blacl";
	values[2].itemquantity = 11;
	values[2].itemsize = "XL";
	values[2].itemprice = 39.9;

	values[3].itemid = 6232;
	values[3].itemtype = "Shorts";
	values[3].itemdescription = "Mickey Mouse Shorts";
	values[3].itemcolour = "Cocklat";
	values[3].itemquantity = 9;
	values[3].itemsize = "XS";
	values[3].itemprice = 59.9;

	values[4].itemid = 3019;
	values[4].itemtype = "Skirts";
	values[4].itemdescription = "Bubble Skirt";
	values[4].itemcolour = "Yellow";
	values[4].itemquantity = 2;
	values[4].itemsize = "F";
	values[4].itemprice = 29.99;

	values[5].itemid = 1015;
	values[5].itemtype = "Slacks";
	values[5].itemdescription = "Skinny Slacks";
	values[5].itemcolour = "Black";
	values[5].itemquantity = 3;
	values[5].itemsize = "S";
	values[5].itemprice = 45.9;

	for (int i = 0; i < 6; i++)
	{
		c.insertclothessorted(values[i].itemid, values[i].itemtype, values[i].itemdescription, values[i].itemquantity, values[i].itemcolour, values[i].itemprice, values[i].itemsize);
	}
	

	/*

	c.insertclothessorted(8401, "Jeans", "Short Jeans", 7, "Blue", "L", 79.9);
	c.insertclothessorted(2109, "Shirts", "Mickey Mouse T Shirt", 11, "Black", "XL", 39.9);
	c.insertclothessorted(2442, "Shirts", "Long Sleeve T Shirt", 4, "Red", "XL", 37.9);
	c.insertclothessorted(6232, "Shorts", "Mickey Mouse Shorts", 9, "Coklat", "XS", 59.9);
	c.insertclothessorted(3019, "Skirts", "Bubble Skirt", 2, "Yellow", "F", 29.99);
	c.insertclothessorted(1015, "Slacks", "SKinny Slacks", 3, "Black", "S", 45.9);

	*/


	mainmenu();

	return(0);

}

	void mainmenu()
	{
		int ID;
		int temp;
		int option;
		cout << endl<<"--------------------------------------------------" << endl;
		cout << "Menu : \n -------------------------------------------------- \n";
		cout <<endl<< "1.Place an Order" << endl;
		cout << "2. View Orders" << endl;
		cout << "3. Insert clothes (Admin)"<<endl;
		cout << "0. Exit " << endl;
		cout << endl;
		cout << "Enter your option : ";
		cin >> temp;

		if (temp == 1)

		{
			
			cout << endl<< "1. View the list of clothes (Complete list of clothes)" << endl;
			cout << "2. Search for a particular type of clothe" << endl;
			cout << "3. View the list of clothes (One by one)" << endl;
			cout << "0. Exit"<<endl;
			cout << "Enter your option : ";
			cin >> option;
			cout << endl;
			string value;
			switch (option)
			{
			case 1:
				c.viewwholeclothes();
				mainmenu();
				break;
			case 2:

				cout << endl << "Enter the product type you want to search ";
				getline(cin, value);
				getline(cin, value);
				c.searchitem(value);
				mainmenu();
				break;
			case 3:
				c.viewclothesonebyone();
				mainmenu();
				break;
			case 0:
				exit(0);
			}
		}

		else if (temp == 2)
		{
			
			cout << endl<< "1. View All Orders" << endl;
			cout << "2. View Orders (One by one)" << endl;
			cout << "3. Delete order" << endl;
			cout << "0.Exit" << endl;
			cout << "Enter your option : ";
			cin >> option;
			cout << endl;
			switch (option)
			{
			case 1:
				o.viewwholeorders();
				mainmenu();
				break;
			case 2:
				o.viewordersonebyone();
				mainmenu();
				break;
			case 3:
				cout << endl << "Enter the Order Id to be deleted  : ";
				cin >> ID;
				o.deleteorder(ID);
				mainmenu();
				break;
			}
		}

		else if (temp == 3)
		{
			insertclothes();
			
		}

		else if (temp == 0)
		{
			cout << "System Exitting";
			exit(0);
		}

	}

	void insertclothes()
	{
		string itemid, type, description, colour,size;
		int quantity, price;

		cout <<endl<< " Enter the cloth id : "<<endl;
		getline(cin, itemid);
		getline(cin, itemid);
		cout << " Enter the cloth type (Jeans,Shirt,Short,Skirt,Slack) :"<<endl;
		getline(cin,type);
		cout << " Enter the Description : " << endl;
		getline(cin, description);
		cout << " Enter the quantity :" << endl;
		cin >> quantity;
		cout << "Enter the colour  : " << endl;
		getline(cin, colour);
		getline(cin, colour);
		cout << "Enter the size :" << endl;
		getline(cin, size);
		cout << "Enter the price :" << endl;
		cin >> price;

		c.insertclothessorted(itemid, type, description, quantity, colour, size, price);
		
		cout << "Clothes succesfully added";
		
		mainmenu();
		

	}



