#pragma once
#include<string>
#include<iostream>
using namespace std;

class AccountsRecords {
	string firstName, lastName;
	double balance;
	int recordNo, accID;

public:
	AccountsRecords() : firstName(""), lastName(""), balance(0), recordNo(0), accID(0) {
	}

	AccountsRecords(string fN, string lN, double b, int rN, int aID) : firstName(fN), lastName(lN), balance(b), recordNo(rN), accID(aID) {
	}

	void setFirstName(string fN) {
		firstName = fN;
	}

	void setLastName(string lN) {
		lastName = lN;
	}

	void setBalance(const double& b) {
		balance = b;
	}

	void setRecordNo(const int& rN) {
		recordNo = rN;
	}

	void setAccountID(const int& aID) {
		accID = aID;
	}

	string getFirstName() const {
		return firstName;
	}

	string getLastName() const {
		return lastName;
	}

	double getBalance() const {
		return balance;
	}

	int getRecordNo() const {
		return recordNo;
	}

	int getAccountID() const {
		return accID;
	}

	void Display() {
		cout << "Record Number: " << recordNo << endl;
		cout << "Account ID: " << accID << endl;
		cout << "First Name: " << firstName << endl;
		cout << "Last Name: " << lastName << endl;
		cout << "Balance: " << balance << endl << endl;
	}

	AccountsRecords operator=(const AccountsRecords& rhs) {
		accID = rhs.accID;
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		balance = rhs.balance;
		recordNo = rhs.recordNo;

		return *this;
	}

	bool operator<(const AccountsRecords& rhs) const {
		if (this->accID < rhs.accID) {
			return true;
		}
		return false;
	}

	bool operator>(const AccountsRecords& rhs) const {
		if (this->accID > rhs.accID) {
			return true;
		}
		return false;
	}

	bool operator==(const AccountsRecords& rhs) const {
		if (this->accID == rhs.accID) {
			return true;
		}
		return false;
	}
};

ostream& operator<<(ostream& output, AccountsRecords& rhs) {
	rhs.Display();
	return output;
}