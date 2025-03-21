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

	fstream bankFile;
	bankFile.open("PhaseFourBank.dat", ios::out | ios::binary);
	if (!bankFile) {
		cout << "Error opening file." << endl;
		return 0;
	}

	double checkInt = 0.0002; //checkings account monthly interest rate
	double savInt = 0.0105; //savings account monthly interest rate
	double threeMonthCD = 0.0025;//CD account interest rate for three months
	double sixMonthCD = 0.03; //CD account interest rate for six months
	double oneYrCD = 0.05; //CD account interest rate for one year
	double mmInt = 0.0125; //money market account monthly interest rate

	//vector of customers- could initialize or leave blank
	vector<Customer> customers;
	vector<shared_ptr<Account>> accounts;

	string fname; string lname;

	//menu for users
	cout << "Please enter the letter representing your choice." << endl;
	cout << "\tA) Add a customer \n\tB) Remove a customer" << endl;
	cout << "\tC) Add an account \n\tD) Delete an account" << endl;
	cout << "\tE) View accounts \n\tF) View customers" << endl;
	cout << "\tEnter Q to quit" << endl;

	char choice; //user choice

	do {
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
			break;
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
			cout << "\tA) Checking\n\tB) Savings\n\tC) Money Market\n\tD) CD Account\n";
			cout << "Enter choice: ";
			cin >> accType;
			accType = toupper(accType);

			cout << "Enter Initial Balance: ";
			cin >> balance;

			shared_ptr<Account> newAccount = nullptr;

			// Create the selected account with auto-incremented accNum
			switch (accType) {
			case 'A':
				newAccount = make_shared<CheckingsAccount>(*custIt, balance, checkInt);
				break;
			case 'B':
				newAccount = make_shared<SavingsAccount>(*custIt, balance, savInt);
				break;
			case 'C':
				newAccount = make_shared<MoneyMarketAccount>(*custIt, balance, mmInt);
				break;
			case 'D': {
				char term;
				cout << "Choose CD Term:\n";
				cout << "\tA) Three months - 2.5%\n\tB) Six months - 3%\n\tC) One year - 5%\n";
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
				int showAccNum = newAccount->getAccNum();
				cout << "Account " << showAccNum << " successfully added for " << fname << " " << lname << ".\n";
			}
			break;
		}
		case 'D': // user choose to delete an account
		{
			cout << "Enter the number of the account you wish to delete: ";
			int deleteAccount;
			cin >> deleteAccount;
			//find account to delete
			auto dAccIt = find_if(accounts.begin(), accounts.end(), [&](const shared_ptr<Account>& delAcc) {
				return delAcc->getAccNum() == deleteAccount;
				});
			if (dAccIt == accounts.end()) { //check its a valid account number
				cout << "Account does not exist." << endl;
			}
			else {
				accounts.erase(dAccIt); //delete
				cout << "Account " << deleteAccount << " has been deleted." << endl;
			}
			break;
		}
		case 'E': //user chose to view accounts
		{
			cout << "Accounts sorted by balance: " << endl;
			sort(accounts.begin(), accounts.end(), [](const shared_ptr<Account>& accBal1, const shared_ptr<Account>& accBal2) {
				return accBal1->getBalance() < accBal2->getBalance();
				});
			for (auto& element : accounts)
				cout << "Account " << element->getAccNum() << " balance: $" << element->getBalance() << endl;
			break;
		}
		case 'F': //user chose to view customers
		{
			cout << "Customers sorted by last name: " << endl;
			sort(customers.begin(), customers.end(), [](const Customer& cust1, const Customer& cust2) {
				return cust1.getLName() < cust2.getLName();
				});
			for (const auto& element : customers)
				cout << element.getLName() << endl;
			break;
		}
		case 'Q': 
		{
			cout << "Exiting program" << endl;
			break;
		}
		default:
			cout << "Invalid choice, please try again." << endl;
		}
	} while (choice != 'Q' && choice != 'q');

	size_t custSize = customers.size();
	bankFile.write((char*)&custSize, sizeof(custSize));

	for (auto& cust : customers) {
		size_t fnSize = cust.getFName().size();
		size_t lnSize = cust.getLName().size();

		bankFile.write((char*)&fnSize, sizeof(fnSize));
		bankFile.write(cust.getFName().c_str(), fnSize);
		bankFile.write((char*)&lnSize, sizeof(lnSize));
		bankFile.write(cust.getLName().c_str(), lnSize);
	}


	size_t accSize = accounts.size();
	bankFile.write((char*)&accSize, sizeof(accSize));

	for (auto& acc : accounts) {
		//get account information- number, balance, owner, interest
		int aNum = acc->getAccNum();
		double accBal = acc->getBalance();
		double aInt = acc->getInterest();
		Customer aC = acc->getCustomer();
		string custFN = aC.getFName();
		string custLN = aC.getLName();

		//write account info to file
		bankFile.write((char*)&aNum, sizeof(aNum)); //acount number
		bankFile.write((char*)&accBal, sizeof(accBal)); //account balance
		bankFile.write((char*)&aInt, sizeof(aInt)); //account interest
		size_t sizeCustFN = custFN.size(); //size of customer's first name
		size_t sizeCustLN = custLN.size(); //size of customer's last name

		//write customer's first name to file
		bankFile.write((char*)&sizeCustFN, sizeof(sizeCustFN));
		bankFile.write(custFN.c_str(), sizeCustFN);
		//write customer's last name to file
		bankFile.write((char*)&sizeCustLN, sizeof(sizeCustLN));
		bankFile.write(custLN.c_str(), sizeCustLN);
	}

	bankFile.close();

	return 0;
}