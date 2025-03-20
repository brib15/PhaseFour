/* Programmers: Briana Benningfield and Alexis Lua
* Date: 
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Accounts.h"
using namespace std;

int main() {
	
	double checkInt = 0.0002; //checkings account monthly interest rate
	double savInt = 0.0105; //savings account monthly interest rate
	double threeMonthCD = 0.0025;//CD account interest rate for three months
	double sixMonthCD = 0.03; //CD account interest rate for six months
	double oneYrCD = 0.05; //CD account interest rate for one year
	double mmInt = 0.0125; //money market account monthly interest rate

	//vector of customers- could initialize or leave blank
	vector<Customer> customers;
	vector<shared_ptr<Account>> accounts
	{
		make_shared<CheckingsAccount>(),
		make_shared<SavingsAccount>(),
		make_shared<MoneyMarketAccount>(),
		make_shared<CDAccount>()
	};
	string fname; string lname;

	//menu for users
	cout << "Please enter the letter representing your choice." << endl;
	cout << "\tA) Add a customer \n\tB) Remove a customer";
	cout << "\n\tC) Add an account \n\tD) Delete an account";
	cout << "\n\tE) View accounts \n\tF) View customers" << endl;
	cout << "\tG) Manage accounts \n\tEnter Q to quit" << endl;

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
		case 'C': // User choose to add an account
		{
			double balance;
			char accType;
			string fname, lname;

			cout << "Enter first and last name of the account holder: ";
			cin >> fname >> lname;

			// Find customer safely
			auto custIt = find_if(customers.begin(), customers.end(), [&](const Customer& c) {
				return c.getFName() == fname && c.getLName() == lname;
				});

			if (custIt == customers.end()) {
				cout << "Customer not found. Please add them first.\n";
				break;
			}

			// Ask for account details
			cout << "Select account type:\n";
			cout << "C) Checking\nS) Savings\nM) Money Market\nD) CD Account\n";
			cout << "Enter choice: ";
			cin >> accType;
			accType = toupper(accType);

			cout << "Enter Initial Balance: ";
			cin >> balance;

			shared_ptr<Account> newAccount = nullptr;

			// Create the selected account with auto-incremented accNum
			switch (accType) {
			case 'C':
				newAccount = make_shared<CheckingsAccount>(*custIt, balance, checkInt);
				break;
			case 'S':
				newAccount = make_shared<SavingsAccount>(*custIt, balance, savInt);
				break;
			case 'M':
				newAccount = make_shared<MoneyMarketAccount>(*custIt, balance, mmInt);
				break;
			case 'D': {
				char term;
				cout << "Choose CD Term:\n";
				cout << "A) Three months - 2.5%\nB) Six months - 3%\nC) One year - 5%\n";
				cin >> term;
				term = toupper(term);

				switch (term) {
				case 'A': newAccount = make_shared<CDAccount>(*custIt, balance, threeMonthCD); break;
				case 'B': newAccount = make_shared<CDAccount>(*custIt, balance, sixMonthCD); break;
				case 'C': newAccount = make_shared<CDAccount>(*custIt, balance, oneYrCD); break;
				default:
					cout << "Invalid choice. Please try again.\n";
					break;
				}
				break;
			}
			default:
				cout << "Invalid account type selected. Try again.\n";
				break;
			}

			if (newAccount) {
				accounts.push_back(newAccount); // Store in vector using `shared_ptr`
				cout << "Account successfully added for " << fname << " " << lname << ".\n";
			}
			break;
		}
		case 'D': // user choose to delete an account
		{
			int accNum;
			cout << "Enter Account number to delete: ";
			cin >> accNum;

			cout << "Enter the number of the account you wish to delete: ";
			cin >> accNum;
			//shared_ptr <Account> deleteAcc;
			//auto it = find(accounts.begin(), accounts.end(), deleteAcc); //look for account object with deleteAcc's initialization
			//if (it != accounts.end()) { //if value is not at the last location after the last value
			//	accounts.erase(it); //get rid of object
			//	cout << "Account " << accNum << " has been removed." << endl; //display sucess
			//}
			//else {
			//	cout << accNum << " was not found." << endl; //otherwise tell user the account was not in the system
			//}

			shared_ptr<Account>deleteAccount;
			deleteAccount->getAccNum();
			auto it = find(accounts.begin(), accounts.end(), deleteAccount);

			//deleteAccount(accounts, accNum);
			break;
		}
		case 'E': //user chose to view accounts
		{
			cout << "Accounts sorted by balance: " << endl;
			
		}
		}		
	} while (choice != 'Q' && choice != 'q');


	return 0;
}