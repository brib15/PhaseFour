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
		case 'C': // user chose to add an account
		{
			int accNum;
			double balance;
			char accType;
			string fname, lname;

			cout << "Enter first and last name of the account holder: ";
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
			/*cout << "Enter Interest Rate: ";
			cin >> interest;*/

			// Create the selected account
			Account* newAccount = nullptr;
			switch (accType) {
			case 'C':
				newAccount = new CheckingsAccount(accountHolder, accNum, balance, checkInt);
				break;
			case 'S':
				newAccount = new SavingsAccount(accountHolder, accNum, balance, savInt);
				break;
			case 'M':
				newAccount = new MoneyMarketAccount(accountHolder, accNum, balance, mmInt);
				break;
			case 'D':
			{
				cout << "What length of term would you like to choose? " << endl;
				cout << "\tA) Three months for a 2.5% interest rate \n\tB) Six months for a 3% interest rate \n\tC) One year for a 5% interest rate" << endl;
				char term;
				cin >> term;
				if (toupper(term) == 'A') {
					newAccount = new CDAccount(accountHolder, accNum, balance, threeMonthCD);
				}
				if (toupper(term) == 'B') {
					newAccount = new CDAccount(accountHolder, accNum, balance, sixMonthCD);
				}
				if (toupper(term) == 'C') {
					newAccount = new CDAccount(accountHolder, accNum, balance, oneYrCD);
				}
				else {
					cout << "That was not a valid choice. Please try again." << endl;
				}
				break;
			}
			default:
				cout << "Invalid account type selected. Try again.\n";
				break;
			}

			if (newAccount) {
				accounts.push_back(shared_ptr<Account>(newAccount));  // Store account in vector
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