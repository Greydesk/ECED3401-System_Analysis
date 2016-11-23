// This header includes the bakery and supplier classes and their methods

/**********************************************************************************************************************/
/****************************************************BAKERY CLASS******************************************************/
/**********************************************************************************************************************/
#include <iostream>
#include "customer.h"
#include "food.h"
#include "equipment.h"
#include "tallysheet.h"

class bakery {
	friend class supplier;
	private:
		float _cakePrice; // Selling price ($) of cakes 
		float _croiPrice; // Selling price ($) of croissants
		float _cashFlow;  // Cumulative cash flow ($)for the day
		// Master lists
		list<customer> _custMaster;
		list<foodItem> _foodMaster;
		// Equipment 
		
		// Other
		tallySheet _tally;
		
	public:
		bakery(float cakePrice, float croissantPrice);
		float cakePrice();   // Getter: Selling price of a cake
		float croiPrice();   // Getter: Selling price of a croissant
		float cashFlow(); // Getter: Cumulative Cash Flow
		
		void request(int foodItemType); // Adds funds and modifies fItem
		void orderKits(int nCakes, int nCrois ); // Removes funds, adds items to foodMaster

		void writeRpt_daily(ostream &out);    // 
		void writeRpt_customer(ostream &out, const &list<foodItem> _customerMaster);
		void writeRpt_food(ostream &out, const &list<foodItem> _foodMaster);
};

bakery::bakery(float cakePrice, float croissantPrice)
{
	_cakePrice      = cakePrice;
	_croiPrice = croissantPrice;
	_cashFlow    = 0.0;
}

float bakery::cakePrice()  // Getter: Cake Price
{
	return _cakePrice
}

float bakery::croiPrice() // Getter: Croissant Price
{
	return _croiPrice;
}

float cashFlow() // Getter: Cumulative Cash Flow
{
	return _cashFlow;
}

void deposit() // Add deposit ammount to cumulative cash flow
{
	
}

void withdraw(float wthAmt); // Subtract deposit ammount from cumulative cash flow

void report_daily(ostream &out);
void report_customer(ostream &out);
void report_food(ostream &out);
