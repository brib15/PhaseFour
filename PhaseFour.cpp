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
		case 'C': //user chose to add an account
		{
			cout << "Enter your name: "; //get name of customer so it can be linked to their account
			cin >> fname >> lname;
			//loop through vector and validate that customer does not already exist?
			Customer chCust(fname, lname); 
			customers.push_back(chCust); //add customer 
			cout << "Enter your choice for the type of account you would like to create. " << endl;
			cout << "\tA) Checkings account \n\tB) Savings account \n\tC) Money Market account \n\tD) Certificate of Deposit account" << endl;
			char accChoice;
			cin >> accChoice;
			switch (toupper(accChoice))
			{
			case 'A': //user chose to add a checkings account
			{
				auto chAcc = accounts.at(0);
				chAcc->addAccount(chCust);
				cout << "A new checkings account for " << fname << " " << lname << " has been created." << endl;
			}
			}
		}
		}
	} while (choice != 'Q' && choice != 'q');


	return 0;
}