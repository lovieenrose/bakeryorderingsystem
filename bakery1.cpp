#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std;

void login();
void registration();
void forgot();
void displayMenu(); // Pass the cart as a reference
void admin();
void checkout();
void addItemInCart(string item , int price);
int getIndexOfItem(string item);
void main_page();

vector<string> cart;
vector<int> cartItemCount;
vector<int> item_price;


vector <string> menu_list;
vector <int> initial_price;
void initial_menu();



int main() {
	initial_menu();
	main_page();
    return 0;
}

void main_page(){
	    int c;
    system("cls");
    cout << "\t\t\t_____________________________________________________________________\n\n\n";
    cout << setw(82) <<"Welcome to Bakery & Delights' Login Page\n\n";
    cout << "\t\t\t_____________________________________________________________________\n\n\n";
    cout << "\t\t\t----------------------------------------------------\n";
    cout << "\t\t               | Press 1 to LOGIN                     |" << endl;
    cout << "\t\t               | Press 2 to REGISTER                  |" << endl;
    cout << "\t\t               | Press 3 if you forgot your PASSWORD  |" << endl;
    cout << "\t\t               | Press 4 to EXIT                      |" << endl;
    cout << "\t\t\t----------------------------------------------------\n";

    cout << "\n\t\t\t  Please enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c) {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout << "\t\t\t Thank you! \n\n";
            break;

        default:
            system("cls"); // Use system("cls") for Windows
            cout << "\t\t\t Please select from the options given above \n"
                 << endl;
                 main_page();
    }
}

void initial_menu(){

	menu_list.push_back("Croissant");
	menu_list.push_back("Muffin");
	menu_list.push_back("Baguette");
	menu_list.push_back("Cupcake");
	
	initial_price.push_back(50);
	initial_price.push_back(35);
	initial_price.push_back(65);
	initial_price.push_back(20);
}



void login() {
    int count = 0;
    string userID, password, id, pass;
    system("cls");

    cout << "\t\t\tPlease enter the Username and Password\n";

    cout << "\t\t\tUSERNAME: ";
    cin >> userID;
    cout << "\t\t\tPASSWORD: ";
    cin >> password;
    
    
    if ( userID == "admin" && password == "adminonly123") {
        cout << "This is the admin access";  
            admin();
    }
    else{
    	    ifstream input("records.txt");

    while (input >> id >> pass) {
        if (id == userID && pass == password) {
            count = 1;
            system("cls");
            break;  // Exit the loop once credentials are found
        }
    }
    input.close();

    if (count == 1) {
        cout << userID << "\n Your LOGIN is successful \n Thanks for logging in \n";
        displayMenu();  // Display the menu after successful login
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password\n";
        main_page();
    }
	}
        


}


void registration()
{
    string ruserID, rpassword;
    system("cls");

    cout << "\t\t\t Enter the username: ";
    cin >> ruserID;

    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;

    ofstream fi("records.txt", ios::app);
    fi << ruserID << ' ' << rpassword << endl;
    fi.close();

    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
   main_page();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries. \n\n";
    cout << "\t\t\tPress 1 to search your ID by username " << endl;
    cout << "\t\t\tPress 2 to go back to the main menu \n\n" << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserID, sId, spass;
        cout << "\n\t\t\t Enter the username which you remembered: ";
        cin >> suserID;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserID)
            {
                count = 1;
                break; // exit the loop once the ID is found
            }
        }

        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your password is: " << spass << endl;
            main();
        }
        else
        {
            cout << "\n\t Sorry, your account is not found! \n";
            main();
        }
        break;
    }
    case 2:
        main();
        break;
    default:
        cout << "\t\t\t Wrong choice! Please try again" << endl;
        forgot();
    }
}


void displayMenu() {
    int m;
    int price_of_Croissant = 50;
    int price_of_Muffin = 35;
    int price_of_Baguette = 65;
    int price_of_Cupcake = 20;
    
    system("cls"); 
    cout << "\t\t\t_____________________________________________________________________\n\n\n";
    cout << "\t\t\t                 Welcome to Bakery & Delights' Food Menu             \n\n\n";
    cout << "\t\t\t_____________________________________________________________________\n\n\n";
    cout << "\t\t\t--------------------------------------\n";
    
    for (size_t i = 0; i < menu_list.size(); ++i) {
     cout << "\t\t               | ["<<(i+1)<<"]"<< menu_list[i]<<" - PHP "<<initial_price[i]<<"                    |" << endl;
    }
//    
//   
//    cout << "\t\t               | [2] Muffin    - PHP "<<price_of_Muffin<<"                     |" << endl;
//    cout << "\t\t               | [3] Baguette  - PHP "<<price_of_Baguette<<"                   |" << endl;
//    cout << "\t\t               | [4] Cupcake   - PHP "<<price_of_Cupcake<<"                    |" << endl;
    cout << "\t\t\t--------------------------------------\n";

    // Get user input

    // Process user input
    while (1) {
//        // Add the selected item to the cart
//        switch (m) {
//            case 1:
//                addItemInCart("Croissant" , price_of_Croissant);
//                break;
//            case 2:
//                 addItemInCart("Muffin" , price_of_Muffin);
//                break;
//            case 3:
//                 addItemInCart("Baguette" , price_of_Baguette);
//                break;
//            case 4:
//                 addItemInCart("Cupcake" , price_of_Cupcake);
//                break;
//            default:
//                cout << "Invalid choice. Please enter a valid number." << endl;
//                break;
//        }

        // Ask if the user wants to add more items
        cout << "Item added to cart. Do you want to add more? (Enter 0 to Checkout): ";
        cin >> m;
        if(m == 0){
        	break;
		}else{
			addItemInCart(menu_list[m - 1] , initial_price[m - 1]);
		}
        
        
    }
    
    cout<<"Now out of loop";
    
    checkout();
}


void admin()
{
	system("cls");
	string new_item_name;
	int new_item_price;
	int update_item_number;
	char user_choice;
	int delete_item;
	cout << "\n Welcome to Admin Access Page: Add/Edit, Delete items!";
	
	for (size_t i = 0; i < menu_list.size(); ++i) {
     cout << "\n\t\t               | ["<<(i+1)<<"] "<< menu_list[i]<<" - PHP "<<initial_price[i]<<"          |" << endl;
     
    }
    
    cout<<"\n Enter A for add item, E for update item, D for delete item , B to go back to main menu : ";
    cin>>user_choice;
    
    switch(user_choice){
    	case 'A':
    		cout<<"Enter the item u want to add: ";
    		cin>>new_item_name;
    		cout<<"Enter the price for "<<new_item_name <<": ";
    		cin>>new_item_price;
    		
    		menu_list.push_back(new_item_name);
    		initial_price.push_back(new_item_price);
    		
    		cout<<"\nNew item is added successfully !";
    		
    		Sleep(2000);
    		admin();
    		
    	break;
    	
    	case 'E':
    		cout<<"\nEnter the number of item u want to update: ";
    		cin>>update_item_number;
    		
    		cout<<"\nThe choosed item for update is: | "<<menu_list[update_item_number - 1] <<" |";
    		cout<<"\n Enter new name for item '"<<menu_list[update_item_number - 1] <<"' :";
    		cin>>new_item_name;
    		cout<<"\n Enter new price for item '"<<initial_price[update_item_number - 1]<<"' :";
    		cin>>new_item_price;
    		
    		menu_list[update_item_number - 1] = new_item_name;
    		initial_price[update_item_number - 1] = new_item_price;
    		
    		cout<<"\nItem is Updated successfully !";
    		Sleep(2000);
    		admin();
    		
		break;
		
		case 'D':
			cout<<"\n Enter the number of item u want to delete: ";
			cin>>delete_item;
			
			menu_list.erase((menu_list.begin() + (delete_item - 1)) );
			initial_price.erase((initial_price.begin() + (delete_item - 1)) );
			
			cout<<"\nItem is Deleted successfully !";
			Sleep(2000);
    		admin();
		break;
		
		case 'B':
			main_page();
			
	}
    
	
}



void addItemInCart(string item , int price){
	
	cout<<"\n\n"<<item << " " <<price<<endl;
	bool found = false;

    // Iterate through the vector using a for loop
    for (size_t i = 0; i < cart.size(); ++i) {
        if (cart[i] == item) {
            found = true;
            break; // No need to continue searching once found
        }
    }

    if (found) {
    	int index = getIndexOfItem(item);
    	cartItemCount[index] += 1;
    	item_price[index] += price;
      
    } else {
        cart.push_back(item);
        cartItemCount.push_back(1);
        item_price.push_back(price);
    }
		
}


int getIndexOfItem(string item){



    // Iterate through the vector using a for loop
    for (size_t i = 0; i < cart.size(); ++i) {
        if (cart[i] == item) {
        	return i;
        }
    }
    
    return -1;
	
}



void checkout(){
	
	int total_bill = 0;
	 cout << "\n\nYour total bill : "<<endl;
	 
    for (size_t i = 0; i < cart.size(); ++i) {
        cout <<endl<< (i + 1) <<" "<< cart[i]  <<"\t\t" <<cartItemCount[i]<< " piece/s     " <<item_price[i]<<endl;
        total_bill += item_price[i];
    }
    
    cout<<"\n -------------------------------------------------------------------\n";
    cout<<"\n Your order has been placed."<<endl;
    cout<<"\n Your total bill will be:	PHP "<<total_bill<<endl;
    cout<<"\n Thank you for ordering at Bakery & Delights!"<<endl;
}



