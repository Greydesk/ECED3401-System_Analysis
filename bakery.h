// This header includes the bakery and supplier classes and their methods

/**********************************************************************************************************************/
/*************************************************** BAKERY CLASS *****************************************************/
/**********************************************************************************************************************/
#include <iostream>
#include <fstream>
#include "customer.h"
#include "food.h"
#include "equipment.h"
#include "tallysheet.h"
#include "supplier.h"

class bakery {
	private:
		float _cakePrice; // Selling price ($) of cakes 
		float _croiPrice; // Selling price ($) of croissants
		float _cashFlow;  // Cumulative cash flow ($) for the day
		// Pointers to master lists
		list<customer>* _cMaster;
		list<foodItem>* _fMaster;
		// Equipment
		
		// Other
		tallysheet _tally;
		
	public:
		bakery(float cakePrice, float croiPrice, list<customer>* cMaster, list<foodItem>* fMaster);
		float cakePrice(); // Getter: Selling price of a cake
		float croiPrice(); // Getter: Selling price of a croissant
		float cashFlow();  // Getter: Cumulative Cash Flow
		
		// Operation functions
		void request(int foodItemType); // process customer request, 
		void order();
		
		void orderKits(int nCakes, int nCrois); // Removes funds, adds items to foodMaster

		void writeRpt_daily(ofstream &out);    // daily report
		void writeRpt_customer(ofstream &out, const &list<fooditem> _customerMaster);
		void writeRpt_food(ofstream &out, const &list<fooditem> _foodMaster);
}

bakery(float cakePrice, float croissantPrice, list<customer>* cMaster, list<foodItem>* fMaster)
{
	_cakePrice      = cakePrice;
	_croissantPrice = croissantPrice;
	_cashFlow       = 0.0;
	_cMaster        = cMaster;
	_fMaster        = fMaster;
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

void report_daily(ofstream &out)
{
	_tally.writeRpt(out);
}

void report_customer(ofstream &out)
{
	
}
void report_food(ofstream &out)
{
	
}
