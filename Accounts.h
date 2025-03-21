#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <string>
using namespace std;

class Customer {
private:
	string fn;
	string ln;
public:
	Customer() { //default constructor- initialize to default values
		setFName("");
		setLName("");
	}
	Customer(string fname, string lname) { //constructor- initialize to entered values
		setFName(fname);
		setLName(lname);
	}
	void setFName(string fname) {
		fn = fname;
	}
	void setLName(string lname) {
		ln = lname;
	}
	string getFName() const {
		return fn;
	}
	string getLName() const {
		return ln;
	}
	//fix later? Apparently needed in order to compare objects
	bool operator==(Customer name) const {
		return fn == name.fn && ln == name.ln;
	}
};

class Account { //abstract class, pure virtual
protected:
	Customer user;
	static int nextAccountNumber; // Static variable to track the account numbers
	int accNum; // Auto-incrementing account number
	double bal; 
	double interest;
public:
	Account() : bal(0.0), interest(0.0) {
		accNum = nextAccountNumber++; // Assign and increment account number
	}

	virtual void setCustomer(Customer u) = 0;
	virtual void setBalance(double b) = 0;
	virtual void setInterest(double i) = 0;

	virtual Customer getCustomer() const = 0;
	virtual int getAccNum() const {return accNum; } // Gets the account number
	virtual double getBalance() const = 0;
	virtual double getInterest() const = 0;

	virtual void addAccount(Customer name) = 0;
};
// Static variable initialized outside of the class
int Account::nextAccountNumber = 1000; // Starting accout number (the number can be changed if we want to)

class CheckingsAccount : public Account {
public:
	CheckingsAccount() : Account() { //default constructor- initialize to default values
		
		setBalance(0.00);
		setInterest(0.00);
	}
	CheckingsAccount(Customer user, double bal, double interest) : Account() {
		setCustomer(user);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
	}
	virtual void setCustomer(Customer u) { //link to customer
		user = u;
	}
	virtual void setBalance(double b) override {
		bal = b;
	}
	virtual void setInterest(double i) override {
		interest = i;
	}
	virtual Customer getCustomer() const override {
		return user;
	}
	virtual int getAccNum() const override {
		return accNum;
	}
	virtual double getBalance() const override {
		return bal;
	}
	virtual double getInterest() const override {
		return interest;
	}
};

class SavingsAccount : public Account {
public:
	SavingsAccount() : Account() { //default constructor- initialize to default values
		
		setBalance(0.00);
		setInterest(0.00);
	}
	SavingsAccount(Customer user, double bal, double interest) : Account() {
		setCustomer(user);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
	}
	virtual void setCustomer(Customer u) { 
		user = u;
	}
	virtual void setBalance(double b) override {
		bal = b;
	}
	virtual void setInterest(double i) override {
		interest = i;
	}
	virtual Customer getCustomer() const override {
		return user;
	}
	virtual int getAccNum() const override {
		return accNum;
	}
	virtual double getBalance() const override {
		return bal;
	}
	virtual double getInterest() const override {
		return interest;
	}
};

class MoneyMarketAccount : public Account {
public:
	MoneyMarketAccount() : Account() { //default constructor- initialize to default values
		accNum = nextAccountNumber++;
		setBalance(0.00);
		setInterest(0.00);
	}
	MoneyMarketAccount(Customer user, double bal, double interest) : Account() {
		setCustomer(user);
		
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
	}
	virtual void setCustomer(Customer u) {
		user = u;
	}
	virtual void setBalance(double b) override {
		bal = b;
	}
	virtual void setInterest(double i) override {
		interest = i;
	}
	virtual Customer getCustomer() const override {
		return user;
	}
	virtual int getAccNum() const override {
		return accNum;
	}
	virtual double getBalance() const override {
		return bal;
	}
	virtual double getInterest() const override {
		return interest;
	}
};

class CDAccount : public Account {
public:
	CDAccount() : Account() { //default constructor- initialize to default values
		accNum = nextAccountNumber++;
		setBalance(0.00);
		setInterest(0.00);
	}
	CDAccount(Customer user, double bal, double interest) : Account() {
		setCustomer(user);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
	}
	virtual void setCustomer(Customer u) {
		user = u;
	}
	virtual void setBalance(double b) override {
		bal = b;
	}
	virtual void setInterest(double i) override {
		interest = i;
	}
	virtual Customer getCustomer() const override {
		return user;
	}
	virtual int getAccNum() const override {
		return accNum;
	}
	virtual double getBalance() const override {
		return bal;
	}
	virtual double getInterest() const override {
		return interest;
	}
};

#endif