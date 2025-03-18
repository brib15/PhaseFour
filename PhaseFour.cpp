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

	vector<Customer> customers;
	string fname; string lname;

	cout << "Please enter the letter representing your choice." << endl;
	cout << "\tA) Add a customer \n\tB) Remove a customer";
	cout << "\n\tC) Add an account \n\tD) Delete an account";
	cout << "\n\tE) View accounts \n\tF) View customers" << endl;
	cout << "Enter Q to quit" << endl;

	char choice;
	
	do{
		cout << "Enter choice here: ";
		cin >> choice;
		switch (toupper(choice)) {
		case 'A':
		{
			cout << "To add a customer, please enter a first and last name: ";
			cin >> fname >> lname;
			Customer newCust(fname, lname);
			customers.push_back(newCust);
			cout << fname << " " << lname << " has been added as a new customer." << endl;
			break;
		}
		case 'B':
		{
			cout << "Enter first and last name of the customer you wish to remove: ";
			cin >> fname >> lname;
			Customer removeCust(fname, lname);
			//for (int count = 0; count < customers.size()&&)
			/*for (auto it = customers.begin(); it != customers.end();) {
				if (*it == removeCust)
			}*/
			
			//customers.erase(find(customers.begin(), customers.end(), removeCust));
			auto it = find(customers.begin(), customers.end(), removeCust);
			if (it != customers.end()) {
				customers.erase(it);
				cout << fname << " " << lname << " has been removed." << endl;
			}
			else {
				cout << fname << " " << lname << " was not found." << endl;
			}
		}
		}
	} while (choice != 'Q' && choice != 'q');


	return 0;
}