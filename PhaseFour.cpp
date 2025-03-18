/* Programmers: 
* Date: 
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Accounts.h"
using namespace std;

int main() {
	
	//vector of customers- could initialize or leave blank
	vector<Customer> customers;
	vector<shared_ptr<Account>> accounts
	{
		make_shared<CheckingsAccount>()
	};
	string fname; string lname;

	//menu for users
	cout << "Please enter the letter representing your choice." << endl;
	cout << "\tA) Add a customer \n\tB) Remove a customer";
	cout << "\n\tC) Add an account \n\tD) Delete an account";
	cout << "\n\tE) View accounts \n\tF) View customers" << endl;
	cout << "\tEnter Q to quit" << endl;

	char choice; //user choice
	
	do{
		cout << "Enter choice here: ";
		cin >> choice;
		switch (toupper(choice)) {
		case 'A': //user chose to add a customer
		{
			cout << "To add a customer, please enter a first and last name: ";
			cin >> fname >> lname; //get customer name
			Customer newCust(fname, lname); //creat customer object and initialize with name
			customers.push_back(newCust); //add customer to vector
			cout << fname << " " << lname << " has been added as a new customer." << endl; //display message to user saying process was sucessful
			break; 
		}
		case 'B': //user chose to remove a customer
		{
			cout << "Enter first and last name of the customer you wish to remove: ";
			cin >> fname >> lname; 
			Customer removeCust(fname, lname);
			auto it = find(customers.begin(), customers.end(), removeCust); //look for customer object with removeCust's initialization
			if (it != customers.end()) { //if value is not at the last location after the last value
				customers.erase(it); //get rid of object
				cout << fname << " " << lname << " has been removed." << endl; //display sucess
			}
			else {
				cout << fname << " " << lname << " was not found." << endl; //otherwise tell user the customer was not in the system
			}
		}
		case 'C': // user chose to add an account
		{
			int accNum;
			double balance, interest;
			char accType;
			string fname, lname;

			cout << "Enter first and last name of thje account holder: ";
			cin >> fname >> lname;

			// Check if customer exists
			Customer accountHolder(fname, lname);
			auto custIt = find(customers.begin(), customers.end(), accountHolder);

			if (custIt == customers.end()) {
				cout << "Customer not found. Please add them first.\n";
				break;
			}

			// Ask for account details
			cout << "Select  account type:\n";
			cout << "\tC) Checking\n\tS) Savings\n\tM) Money Market\n\tD) CD Account\n";
			cout << "Enter choice: ";
			cin >> accType;
			accType = toupper(accType);

			cout << "Enter Account Number: ";
			cin >> accNum;
			cout << "Enter Initial Balance: ";
			cin >> balance;
			cout << "Enter Interest Rate: ";
			cin >> interest;

			// Create the selected account
			Account* newAccount = nullptr;
			switch (accType) {
			case 'C':
				newAccount = new CheckingsAccount(accNum, balance, interest);
				break;
			case 'S':
				newAccount = new SavingsAccount(accNum, balance, interest);
				break;
			case 'M':
				newAccount = new MoneyMarketAccount(accNum, balance, interest);
				break;
			case 'D':
				newAccount = new CDAccount(accNum, balance, interest);
				break;
			default:
				cout << "Invalid account type selected. Try again.\n";
				break;
			}

			if (newAccount) {
				accounts.push_back(newAccount);  // Store account in vector
				cout << "Account successfully added for " << fname << " " << lname << ".\n";
			}
			break;
		}
		}
	} while (choice != 'Q' && choice != 'q');


	return 0;
}