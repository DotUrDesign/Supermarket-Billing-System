#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;  
		float price;
		float dis;  // discount
		string pname;
		

		// Member functions 
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:				
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t          Supermarket Main Menu       \n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice; 
	
	/*
		administrator - click on 1
		buyer - click on 2
		want to exit - click on 3
	*/

	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email   \n";
			cin>>email;
			cout<<"\t\t\t Password       \n";
			cin>>password;
			
			/* If the input email and password matched the "if" condition, that means it is the administrator who logged in.  */
			if(email=="pratyush12@gmail.com" && password=="Pratyush")
			{
				administrator();  // administrator function is called.
			}
			else
			{
				cout<<"Invalid email/password";
			}
			break;
	
	
	case 2:
		{
			buyer();
		}
	
	case 3:
		{
			exit(0);
		}
		
		default :
		{
			cout<< "Please select from the given options";
		}
}
goto m;		// goto is a jump statement which jumps to the given label i.e., "m";
}

void shopping:: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		add();    // Add the product
    		break;
    		
    	case 2:
    		edit();   // Modify the product
    		break;
    		
    	case 3:
    		rem();   // Delete the product
    		break;
    		
    	case 4:
    		menu();  // Back to main menu
    		break;
    		
    	default :
    		cout<<"Invalid choice!";
    		
	}
	goto m;
}

void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :
			
			cout<<"invalid choice";
			
	}
	
	goto m;
	
	
}

void shopping ::add()
{
	m:
	fstream data;			
	
	/* In C++, fstream is a data type that represents the file stream and has the capabilities of both ofstream and ifstream, which means it can create files, write information to files, and read information from files. It is part of the fstream header file, which must be included in any program that uses files. */

	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product ";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on product";
	cin>>dis;
	
	/* Now we have to open a file, as this add option is being used by the administrator so we have to store these product details inside a particular file so that we can display to the user that we have these products in our supermarket. */
	data.open("database.txt",ios::in);
	/* data - name of the object
	   ios::in - open the file in reading mode
	   ios::out - open the file in writing mode
	 */


	// if this file doesn't exist
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		/*
		ios::app - append mode
		ios::out - open the file in writing mode
		*/
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();   // close the file
	}
	else
	{
		// if the file exists, read it.
		// here we are initialising the index of the file.
		data>>c>>n>>p>>d;
		
		/* "eof - end of file"
		Here, we are iterating through the file till we have reached the end of file, and is the code matches with the pcode, we are incrementing the token which we have initially initialised as 0.
		*/
		while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();  // close the file.
		
		
	
	/*
	If there is any dupicacy, then it will again go back to the menu.
	If the product code entered by the administrator already exists then he have to enter another product code because if the administrator enters the same duplicate code, then it go back to the menu.
	*/
	if(token==1)
	 goto m;
	else{
		/*
		If the administrator enters an unique code, then he have to print the product details. 
		*/
		data.open("database.txt", ios::app|ios::out); // file is opened in append mode and writing mode.
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
}
	cout<<"\n\n\t\t Record inserted !";
}

void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{
		
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			/* pkey is the code that is entered by the administrator which he wants to edit, if that matches... */
			if(pkey==pcode)
			{
				// Details of the edited file...

				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;  // Edit all the occurences of the previous file to data1.
			}
			// if it the pkey does not matches with the pcode...
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		// close both the objects...
		data.close();
		data1.close();
		
		// rename the database file to database1 file, so to rename it, first we have to remove the database file...
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
	
	
	
}

/* Remove function... */
void shopping::rem()
{
	
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;  // Read from the file...

		/* We are iterating over all the items of the data file. In the first iteration, the pkey entered by the administrator will match the pcode and the msg will be displayed and in the second iteration, the else block will be executed. So, as a result, in the else block, all the products will be displayed except the one we want to remove. */
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|___________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;

	// Iterating over the list of data items and printing every item...

	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

// Receipt function in which all the customer functions will take place...
void shopping::receipt() 
	{
		system("cls");		// Not
		fstream data;
		
		/*
		arrc - array of codes
		arrq - array of quantity  
		*/
		int arrc[100],arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();                                   
			list();
			cout<<"\n____________________________\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|____________________________|\n";

			do
			{
				m:
				cout<<"\n\n Product Code : ";
				cin>>arrc[c];
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					// If the current product code matches with the previous product code stored in the array, then there is a duplicacy else just increment  the value of "c".
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
						goto m;
					}
				}
				c++;             
				cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;	
			}
			
			while(choice == 'y');
			system("cls");		// Not
			
			cout<<"\n\n\t\t\t__________RECEIPT______________\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
			
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>pcode>>pname>>price>>dis;  
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total;
		}
	}
int main()
{
	shopping s;
	s.menu();  // we have to call the first function of the shopping class.
}

