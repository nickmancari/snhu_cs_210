#ifndef CALCULATESAVINGS_H_
#define CALCULATESAVINGS_H_

class calculateSavings {
	public:
		calculateSavings(double investment, double monthly, double interest, int years);
		virtual ~calculateSavings();
		void resultWithoutMonthlyDeposit();
		void resultWithMonthlyDeposit();

	private:
		double startingDeposit;
		double monthDeposit;
		double rate;
		int investmentYears;

};
#endif
