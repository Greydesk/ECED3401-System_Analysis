// This header includes the bakery and supplier classes and their methods

/******************************************************************************/
/******************************* BAKERY CLASS *********************************/
/******************************************************************************/

#include <iostream>
#include <fstream>

#include "customer.h"
#include "equipment.h"
#include "foodItem.h"
#include "supplier.h"
#include "tallySheet.h"

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class bakery {
	friend class equipment;
	friend class supplier;
	private:
		// Atributes
		float  _cakePrice;   // Selling price ($) of cakes 
		float  _croiPrice;   // Selling price ($) of croissants
		double _netCashFlow; // Net cash flow ($) for the day
		int    _pending;
		// Containers
		list<customer>   _cMaster; // Master list of customers
		list<foodItem>   _fMaster; // Master list of food items
		queue<customer*> _cLineup; // Customers waiting at a given time
		// Equipment
		equipment _fridge;
		equipment _freezer;
		equipment _rtStore; // Room Temperature Storage
		equipment _oven1;
		equipment _oven2;
		
		// Record keepers
		tallySheet _tally; // Tally sheet for daily reports
		
	public:
		bakery(float cakePrice, float croiPrice, double netCashFlow = 0.0) //Ctor
		
		// Getters
		float cakePrice();   // Getter: Selling price of a cake
		float croiPrice();   // Getter: Selling price of a croissant
		float netcashFlow(); // Getter: Cumulative Cash Flow
		
		// Setters
		void cakePrice(float cakePrice);      // Setter: Selling price ($) of cakes 
		void croiPrice(float croiPrice);      // Setter: Selling price ($) of croissants
		void netCashFlow(double netCashFlow); // Setter: Net cash flow ($)	
		void Deposit(double amnt); // Add amnt to net cash flow
		void Deduct(double amnt);  // Subtract amnt from net cash flow
		
		// Descriptive functions

		// Operation functions
		void processReq(int foodItemType, int time); // process customer request, 
		void orderKits(int nCakes, int nCrois, int time); // Removes funds, adds items to foodMaster
		void receiveKits(int time);
		void sellOne(int time); // Sell a particular item
		void sellItems(int time); // Sell all possible items
		// Read functions 
		
		// Write functions
		void writeRpt_daily(ostream &out); 
		void writeRpt_customer(ostream &out);
		void writeRpt_food(ostream &out);
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

bakery::bakery(float cakePrice, float croiPrice, netCashFlow)
: _cmaster(), _fmaster(), _cLineup(), tallySheet(),
  _fridge(1, 15, -1, -1, ), _freezer(2), _rtStore(3, -1, -1, ), _oven1(4, 2, 60, 50), _oven2(5, 5, 50, 40);
{
//equipment(int id, int slots, int croiRawLT, int cakeRawLT, int croiProcT, int cakeProcT, int croiReadyLT, int cakeReadyLT): _items()
	_cakePrice    = cakePrice;
	_croiPrice    = croiPrice;
	_netCashFlow  = netCashFlow;
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

float bakery::cakePrice() // Getter: Cake Price
{
	return _cakePrice;
}

float bakery::croiPrice() // Getter: Croissant Price
{
	return _croiPrice;
}

float bakery::netCashFlow() // Getter: Cumulative Cash Flow
{
	return _netCashFlow;
}


/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

	void cakePrice(float cakePrice)      // Setter: Selling price ($) of cakes
	{
		_cakePrice = cakePrice;
	}
	
	void croiPrice(float croiPrice)      // Setter: Selling price ($) of croissants
	{
		_croiPrice = croiPrice;
	}
	
	void netCashFlow(double netCashFlow) // Setter: Net cash flow ($)
	{
		_netCashFlow = netCashFlow;
	}
	
	void Deposit(double amnt) // Add amnt to net cash flow
	{
		_netCashFlow += amnt;
	}
	
	void Deduct(double amnt)  // Subtract amnt from net cash flow
	{
		_netCashFlow -= amnt;
	}
	
/******************************************************************************/
/*************************** OPERATION FUNCTIONS ******************************/
/******************************************************************************/



/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/
void bakery::writeRpt_daily(ostream &out)
{
	_tally.writeRpt(out);
}

void report_customer(ostream &out)
{
	
}

void report_food(ostream &out)
{
	
}
