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
	Customer(string fname, string lname) { //constructor
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
	//fix later
	bool operator==(Customer name) const {
		return fn == name.fn && ln == name.ln;
	}
};

class Account {
protected:
	int accNum;
	double bal; 
	double interest;
public:
	virtual void setAccNum(int accn) = 0;
	virtual void setBalance(double b) = 0;
	virtual void setInterest(double i) = 0;

	virtual int getAccNum() const = 0;
	virtual double getBalance() const = 0;
	virtual double getInterest() const = 0;

	//destructor?

	//Account() { //default constructor- initialize to default values
	//	setAccNum(0);
	//	setBalance(0.00);
	//	setInterest(0.00);
	//}
	//Account(int an, double b, double i) { //constructor
	//	setAccNum(accNum);
	//	setBalance(bal);
	//	setInterest(interest);
	//}
	//virtual int setAccNum(int acn) {
	//	return accNum;
	//}
	//virtual double setBalance(double b) {
	//	return bal;
	//}
	//virtual double setInterest(double i) {
	//	return interest;
	//}
};

class CheckingsAccount : public Account {
private:

public:
	CheckingsAccount() { //default constructor- initialize to default values
		setAccNum(0);
		setBalance(0.00);
		setInterest(0.00);
	}
	CheckingsAccount(int accNum, double bal, double interest) {
		setAccNum(accNum);
		setBalance(bal);
		setInterest(interest);
	}
	/*void addAccount() {

	}
	void deleteAccount() {

	}*/
	virtual void setAccNum(int acn) override {
		accNum = acn;
	}
	virtual void setBalance(double b) override {
		bal = b;
	}
	virtual void setInterest(double i) override {
		interest = i;
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

//class SavingsAccount : public Account {
//private:
//
//public:
//	SavingsAccount() { //default constructor- initialize to default values
//		setAccNum(0);
//		setBalance(0.00);
//		setInterest(0.00);
//	}
//	SavingsAccount() {
//		setAccNum(accNum);
//		setBalance(bal);
//		setInterest(interest);
//	}
//	virtual void setAccNum(int acn) {
//		return accNum;
//	}
//	virtual double setBalance(double b) {
//		return bal;
//	}
//	virtual double setInterest(double i) {
//		return interest;
//	}
//};

//class MoneyMarketAccount : public Account {
//private:
//
//public:
//	MoneyMarketAccount() { //default constructor- initialize to default values
//		setAccNum(0);
//		setBalance(0.00);
//		setInterest(0.00);
//	}
//	MoneyMarketAccount() {
//		setAccNum(accNum);
//		setBalance(bal);
//		setInterest(interest);
//	}
//	virtual int setAccNum(int acn) {
//		return accNum;
//	}
//	virtual double setBalance(double b) {
//		return bal;
//	}
//	virtual double setInterest(double i) {
//		return interest;
//	}
//};

//class CDAccount : public Account {
//private:
//
//public:
//	CDAccount() { //default constructor- initialize to default values
//		setAccNum(0);
//		setBalance(0.00);
//		setInterest(0.00);
//	}
//	CDAccount() {
//		setAccNum(accNum);
//		setBalance(bal);
//		setInterest(interest);
//	}
//	virtual int setAccNum(int acn) {
//		return accNum;
//	}
//	virtual double setBalance(double b) {
//		return bal;
//	}
//	virtual double setInterest(double i) {
//		return interest;
//	}
//};

#endif