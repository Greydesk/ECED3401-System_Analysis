/******************************************************************************/
/****************************** CUSTOMER CLASS ********************************/
/******************************************************************************/


/*
	Notes: All time attributes are in terms of minutes since store opening
*/


#include <stdio.h>
#include <random>
#include <bits/random.h>

#include "foodItem.h"

const double PROB_RETURN_FOR_ITEM       = 0.50; // probability customer returns as soon as item is completed
const double PROB_RETURN_WHILE_LEAVING  = 0.50; // probability customer returns before leaving mall GIVEN not returning as soon as item is completed
random_device rd1;
random_device rd2;
static default_random_engine generator1(rd1());
static default_random_engine generator2(rd2());

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/
 
class customer {
	private:
		int _id;        // Unique ID number, sequentially designated
		int _foodID;    // Unique ID number of food item recieved, -1 if NAN
		int _craving;   // Food type customer craves: 0 = cake, 1 = croissant
		int _arrivalT;  // Time that customer arrived
		int _loiterT;   // Minutes customer intends on staying in mall
		int _returnT;   // Time when customer returns to bakery, -1 if NAN
		int _purchaseT; // Time that purchase occurs, -1 if NAN
		
	public:
		// Ctor
		customer(int id, int craving, int arrivalT, int loiterT);
		// Getters
		int id();        // Getter: ID
		int foodID();    // Getter: food ID
		int craving();   // Getter: craving
		int arrivalT();  // Getter: arrival time
		int loiterT();   // Getter: loiter time
		int returnT();   // Getter: loiterTime
		int purchaseT(); // Getter: purchase time
		// Setters
		void foodID(int foodID);        // Setter: food ID
		int  returnT(int foodPrepEndT); // Setter: return time (-1 if no return)
		void purchaseT(int purchaseT);  // Setter: purchase time
		// Operational functions
		void purchase(int time, foodItem *item);
		// Write Functions
		void write(ostream &out);    // Write function for debugging
		void writeRpt(ostream &out); // Special write function for customer rpt
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

customer::customer(int id, int craving, int arrivalT, int loiterT){
	_id        = id;
	_foodID    = -1;
	_craving   = craving;
	_arrivalT  = arrivalT;
	_loiterT   = loiterT;
	_returnT   = -1;
	_purchaseT = -1;
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

int customer::id()
{
	return _id;
}

int customer::foodID()
{
	return _foodID;
}

int customer::craving()
{
	return _craving;
}

int customer::arrivalT()
{
	return _arrivalT;
}

int customer::loiterT()
{
	return _loiterT;
}

int customer::returnT()
{
	return _returnT;
}

int customer::purchaseT()
{
	return _purchaseT;
}

/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

void customer::foodID(int foodID)
{
	_foodID = foodID;
}

int customer::returnT(int foodPrepEndT)
{
	// only care if it may be done in time, default returnT value already appropriate
	if((_arrivalT + _loiterT) <= foodPrepEndT){ // Will be done in time
		static bernoulli_distribution bernDist1(PROB_RETURN_FOR_ITEM);
   		static bernoulli_distribution bernDist2(PROB_RETURN_WHILE_LEAVING);
   	
   		if(bernDist1(generator1)){
		    _returnT = foodPrepEndT;         // Will return when item is ready
		} else if(bernDist2(generator2)){
			_returnT = _arrivalT + _loiterT; // Will return while leaving
		}
		// default returnT value appropriate otherwise
	}
	return _returnT; // return when customer has decided to return or -1
}

void customer::purchaseT(int purchaseT)
{
	_purchaseT = purchaseT;
}

/******************************************************************************/
/************************** OPERATIONAL FUNCTIONS *****************************/
/******************************************************************************/

void customer::purchase(int time, foodItem *item)
{
	item.relinquishT(time);
	item.cID(_id);
	_purchaseT = time;
}

/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/

void customer::write(ostream &out)
{
	out << "Customer" << endl;
	out << "\tCustomer ID:         " << _id                  << endl;
	out << "\tArrival Time:        " << _arrivalT  << " min" << endl;
	out << "\tSpend T:             " << _loiterT   << " min" << endl;
	out << "\tRequested Food Type: " << _craving             << endl;
	out << "\tFood ID:             " << _foodID              << endl;
	out << "\tPurchase Time:       " << _purchaseT << " min" << endl << endl;
}

void customer::writeRpt(ostream &out)
{
	out << _id      << " " << _arrivalT << " " << _loiterT   << " "
	    << _craving << " " << _foodID   << " " << _purchaseT << endl;
}
