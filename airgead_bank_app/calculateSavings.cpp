#include <iomanip>
#include <iostream>
#include "calculateSavings.h"

using namespace std;

calculateSavings::~calculateSavings(){
}

calculateSavings::calculateSavings(double investment, double monthly, double interest, int years) {

	this->startingDeposit = investment;
	this->monthDeposit = monthly;
	this->rate = interest;
	this->investmentYears = years;
}

void calculateSavings::resultWithoutMonthlyDeposit() {
	cout << "  Balance and Interest without Additional Monthly Deposits" << endl;
	cout << "====================================================================" << endl;

	cout << setw(10) << "Year"
	<< setw(20) << "Year End Balance"
	<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------" << endl;

	int thisYear = 1;
	double endYearBalance = this->startingDeposit;

	while (thisYear <= this->investmentYears){
		double interestEarned = endYearBalance * this->rate / 100;
		endYearBalance += interestEarned;
		cout << right << setw(10) << thisYear << fixed << setprecision(2) << setw(20)
		<< endYearBalance << setw(35) << interestEarned << endl;
		
		thisYear++;
	}
}

void calculateSavings::resultWithMonthlyDeposit() {
        cout << "  Balance and Interest with Additional Monthly Deposits" << endl;
        cout << "====================================================================" << endl;
	
        cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
        cout << "--------------------------------------------------------------------" << endl;

	int thisYear = 1;
	double endYearBalance = this->startingDeposit;

	while(thisYear <= this->investmentYears){
		int month = 1;
		double interestEarned = 0.0;
		double endMonthlyBalance = endYearBalance;
		
		while(month <= 12) {
			endMonthlyBalance += this->monthDeposit;
			double monthInterest = endMonthlyBalance * this->rate / (100*12);
			interestEarned += monthInterest;
			endMonthlyBalance += monthInterest;
			month++;
		}
		
		endYearBalance = endMonthlyBalance;

		cout << right << setw(10) << thisYear << fixed << setprecision(2) << setw(20) << endYearBalance << setw(35) << interestEarned << endl;
		thisYear++;
	}
}
