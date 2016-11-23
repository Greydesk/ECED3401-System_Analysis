// This header includes the bakery and supplier classes and their methods

/**********************************************************************************************************************/
/*************************************************** BAKERY CLASS *****************************************************/
/**********************************************************************************************************************/
#include <iostream>
<<<<<<< HEAD
=======
#include <fstream>
#include "customer.h"
>>>>>>> branch 'master' of https://github.com/Greydesk/ECED3401-System_Analysis.git
#include "food.h"
#include "customer.h"
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
		tallySheet _tally;
		
	public:
		bakery(float cakePrice, float croiPrice, list<customer>* cMaster, list<foodItem>* fMaster);
		float cakePrice(); // Getter: Selling price of a cake
		float croiPrice(); // Getter: Selling price of a croissant
		float cashFlow();  // Getter: Cumulative Cash Flow
		
		// Operation functions
		void request(int foodItemType); // process customer request, 
		void order();
		
		void orderKits(int nCakes, int nCrois); // Removes funds, adds items to foodMaster

<<<<<<< HEAD
		void writeRpt_daily(ostream &out);    // 
		void writeRpt_customer(ostream &out, const &list<foodItem> _cMaster);
		void writeRpt_food(ostream &out, const &list<foodItem> _fMaster);
};
=======
		void writeRpt_daily(ofstream &out);    // daily report
		void writeRpt_customer(ofstream &out, const &list<fooditem> _customerMaster);
		void writeRpt_food(ofstream &out, const &list<fooditem> _foodMaster);
}
>>>>>>> branch 'master' of https://github.com/Greydesk/ECED3401-System_Analysis.git

bakery::bakery(float cakePrice, float croissantPrice, list<customer>* cMaster, list<foodItem>* fMaster)
{
	_cakePrice      = cakePrice;
	_croiPrice = croissantPrice;
	_cashFlow       = 0.0;
	_cMaster        = cMaster;
	_fMaster        = fMaster;
}

float bakery::cakePrice()  // Getter: Cake Price
{
	return _cakePrice;
}

float bakery::croiPrice() // Getter: Croissant Price
{
	return _croiPrice;
}

float bakery::cashFlow() // Getter: Cumulative Cash Flow
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
