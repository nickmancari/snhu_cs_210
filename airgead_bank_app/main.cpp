#include <iostream>
#include "calculateSavings.h"

using namespace std;

void inputPrompt() {

	double investment;
	double monthly;
	double interest;
	int years;
	
	cout << "**************************************************************" << endl;
	cout << "************************ Data Input **************************" << endl;
	cout << "Initial Investment Amout: ";
	cin >> investment;

	cout << "Monthly Deposit: ";
	cin >> monthly;

	cout << "Annual Interest: ";
	cin >> interest;

	cout << "Number of Years: ";
	cin >> years;

	system("read -p 'Press Enter to continue. . .' var");

	calculateSavings savingsData = calculateSavings(investment, monthly, interest, years);
	
	savingsData.resultWithoutMonthlyDeposit();
	
	if(monthly > 0) {
		savingsData.resultWithMonthlyDeposit();
	}

	
}

int main() {

	inputPrompt();
	
	return 0;
}
