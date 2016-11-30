// This header includes the bakery and supplier classes and their methods

/******************************************************************************/
/******************************* BAKERY CLASS *********************************/
/******************************************************************************/

#include <iostream>
#include <fstream>

#include "Freezer.h"
#include "Oven.h"
#include "RoomTempStorage.h"
#include "Fridge.h"
#include "Supplier.h"
#include "TallySheet.h"

#define MAX_ITEMS 
/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class bakery {
	private:
		// Atributes
		int    _current_cakes;      // Number of cakes in posession + awaiting delivery
		int    _current_croissants; // Number of croissants in posession + awaiting delivery
		int    _pending;
		// Containers
		deque<Customer>   _customer_master; // Master deque of customers
		deque<foodItem>   _food_master; // Master deque of food items
		queue<Customer*>  _customer_lineup; // Customers waiting at a given time
		// Equipment
		Equipment _fridge;
		Equipment _freezer;
		Equipment _rtStore; // Room Temperature Storage
		Equipment _oven1;
		Equipment _oven2;
		
		// Record keepers
		tallySheet _tally; // Tally sheet for daily reports
		
	public:
		// Ctor
		bakery(float cake_price, float croissant_price) //Ctor
		// Mutators
		void cake_price(float cake_price);           // Setter: Selling price ($) of cakes 
		void croissant_price(float croissant_price); // Setter: Selling price ($) of croissants
		void net_cash_flow(double net_cash_flow);    // Setter: Net cash flow ($)	
		void Deposit(double amnt);                   // Add amnt to net cash flow
		void Deduct(double amnt);                    // Subtract amnt from net cash flow
		// Operational functions
		void processReq(int time, int foodItemType);      // process customer request, 
		void orderKits(int time, int nCakes, int nCrois); // Removes funds, adds items to foodMaster
		void receiveKit(int time);                        // Adds raw food item (kit) to appropriate locations
		void sellOne(int time);                           // Sell a particular item
		void sellItems(int time);                         // Sell all possible items
		// Descriptive functions

		// Read functions 
		
		// Write functions
		void writeRpt_daily(ostream &out); 
		void writeRpt_customer(ostream &out);
		void writeRpt_food(ostream &out);
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

bakery::bakery(float cake_price, float croissant_price, net_cash_flow)
: _cmaster(), _fmaster(), _customer_lineup(), tallySheet(),
  _fridge(1, 15, -1, -1, ), _freezer(2), _rtStore(3, -1, -1, ), _oven1(4, 2, 60, 50), _oven2(5, 5, 50, 40);
{

//Equipment(int id, int slots, int croiRawLT, int cakeRawLT, int croiProcT, int cakeProcT, int croiReadyLT, int cakeReadyLT): _items()

}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

float bakery::cake_price() // Getter: Cake Price
{
	return _cake_price;
}

float bakery::croissant_price() // Getter: Croissant Price
{
	return _croissant_price;
}

float bakery::net_cash_flow() // Getter: Cumulative Cash Flow
{
	return _net_cash_flow;
}


/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

void cake_price(float cake_price)      // Setter: Selling price ($) of cakes
{
	_cake_price = cake_price;
}

void croissant_price(float croissant_price)      // Setter: Selling price ($) of croissants
{
	_croissant_price = croissant_price;
}

void net_cash_flow(double net_cash_flow) // Setter: Net cash flow ($)
{
	_net_cash_flow = net_cash_flow;
}

void Deposit(double amnt) // Add amnt to net cash flow
{
	_net_cash_flow += amnt;
}

void Deduct(double amnt)  // Subtract amnt from net cash flow
{
	_net_cash_flow -= amnt;
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
