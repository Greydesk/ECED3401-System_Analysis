// This header includes the bakery and supplier classes and their methods

/******************************************************************************/
/******************************* BAKERY CLASS *********************************/
/******************************************************************************/

#include <iostream>
#include <fstream>

#include "foodItem.h"
#include "freezer.h"
#include "oven.h"
#include "RoomTempStorage.h"
#include "fridge.h"
#include "supplier.h"
#include "tallySheet.h"

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
		float _net_cash_flow;
		float _cake_price;
		float _croissant_price;
		// Containers
		deque<Customer>   _customer_master; // Master deque of customers
		deque<FoodItem>   _food_master; // Master deque of food items
		queue<Customer*>  _customer_lineup; // Customers waiting at a given time
		// Equipment
		Equipment _fridge;
		Equipment _freezer;
		Equipment _rtStore; // Room Temperature Storage
		Equipment _oven1;
		Equipment _oven2;
		
		// Record keepers
		TallySheet _tally; // Tally sheet for daily reports
		
	public:
		// Ctor
		bakery(float cake_price, float croissant_price); //Ctor
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
		float cake_price();           // Getter: Selling price ($) of cakes
		float croissant_price();      // Getter: Selling price ($) of croissants
		float net_cash_flow();       // Getter: Net cash flow ($)
		
		// Write functions
		void writeRpt_daily(ostream &out); 
		void writeRpt_customer(ostream &out);
		void writeRpt_food(ostream &out);
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

bakery::bakery(float cake_price, float croissant_price) :_customer_master(), _food_master(), _customer_lineup(), _tally(), _fridge(1, 15, -1, -1), _freezer(2), _rtStore(3, -1, -1), _oven1(4, 2, 60, 50), _oven2(5, 5, 50, 40)
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

void bakery::cake_price(float cake_price)      // Setter: Selling price ($) of cakes
{
	_cake_price = cake_price;
}

void bakery::croissant_price(float croissant_price)      // Setter: Selling price ($) of croissants
{
	_croissant_price = croissant_price;
}

void bakery::net_cash_flow(double net_cash_flow) // Setter: Net cash flow ($)
{
	_net_cash_flow = net_cash_flow;
}

void bakery::Deposit(double amnt) // Add amnt to net cash flow
{
	_net_cash_flow += amnt;
}

void bakery::Deduct(double amnt)  // Subtract amnt from net cash flow
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
	_tally.WriteReport(out);
}

void report_customer(ostream &out)
{
	
}

void report_food(ostream &out)
{
	
}
