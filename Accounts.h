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
	int accNum = 0000;
	double bal; 
	double interest;
public:
	virtual void setCustomer(Customer u) = 0;
	virtual void setAccNum(int accn) = 0;
	virtual void setBalance(double b) = 0;
	virtual void setInterest(double i) = 0;

	virtual Customer getCustomer() const = 0;
	virtual int getAccNum() const = 0;
	virtual double getBalance() const = 0;
	virtual double getInterest() const = 0;

	virtual void addAccount(Customer name) = 0;

	//might not need all, but added in case. Can remove later if unnecessary
	//will need to fill in derived classes
	virtual void deposit(double dep) = 0;
	virtual void withdraw(double wd) = 0;
	virtual void transfer(double tran) = 0;
	virtual void transaction(double tAct) = 0;
};

class CheckingsAccount : public Account {
private:

public:
	CheckingsAccount() { //default constructor- initialize to default values
		setAccNum(0);
		setBalance(0.00);
		setInterest(0.00);
	}
	CheckingsAccount(Customer user, int accNum, double bal, double interest) {
		setCustomer(user);
		setAccNum(accNum);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
		setAccNum(accNum + 1);
	}
	void deleteAccount() {

	}
	virtual void setCustomer(Customer u) { //link to customer
		user = u;
	}
	virtual void setAccNum(int acn) override {
		accNum = acn;
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
	virtual void deposit(double dep) {

	}
	virtual void withdraw(double wd) {

	}
	virtual void transfer(double tran) {

	}
	virtual void transaction(double tAct) {

	}
};

//uncomment and fill in other classes as we go, work on one at a time as needed

class SavingsAccount : public Account {
private:

public:
	SavingsAccount() { //default constructor- initialize to default values
		setAccNum(0);
		setBalance(0.00);
		setInterest(0.00);
	}
	SavingsAccount(Customer user, int accNum, double bal, double interest) {
		setCustomer(user);
		setAccNum(accNum);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
		setAccNum(accNum + 1);
	}
	void deleteAccount() {

	}
	virtual void setCustomer(Customer u) { 
		user = u;
	}
	virtual void setAccNum(int acn) override {
		accNum = acn;
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
	virtual void deposit(double dep) {

	}
	virtual void withdraw(double wd) {

	}
	virtual void transfer(double tran) {

	}
	virtual void transaction(double tAct) {

	}
};

class MoneyMarketAccount : public Account {
private:

public:
	MoneyMarketAccount() { //default constructor- initialize to default values
		setAccNum(0);
		setBalance(0.00);
		setInterest(0.00);
	}
	MoneyMarketAccount(Customer user, int accNum, double bal, double interest) {
		setCustomer(user);
		setAccNum(accNum);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
		setAccNum(accNum + 1);
	}
	void deleteAccount() {

	}
	virtual void setCustomer(Customer u) {
		user = u;
	}
	virtual void setAccNum(int acn) override {
		accNum = acn;
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
	virtual void deposit(double dep) {

	}
	virtual void withdraw(double wd) {

	}
	virtual void transfer(double tran) {

	}
	virtual void transaction(double tAct) {

	}
};

class CDAccount : public Account {
private:

public:
	CDAccount() { //default constructor- initialize to default values
		setAccNum(0);
		setBalance(0.00);
		setInterest(0.00);
	}
	CDAccount(Customer user, int accNum, double bal, double interest) {
		setCustomer(user);
		setAccNum(accNum);
		setBalance(bal);
		setInterest(interest);
	}
	virtual void addAccount(Customer name) {
		setCustomer(name);
		setAccNum(accNum + 1);
	}
	void deleteAccount() {

	}
	virtual void setCustomer(Customer u) {
		user = u;
	}
	virtual void setAccNum(int acn) override {
		accNum = acn;
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
	virtual void deposit(double dep) {

	}
	virtual void withdraw(double wd) {

	}
	virtual void transfer(double tran) {

	}
	virtual void transaction(double tAct) {

	}
};

#endif