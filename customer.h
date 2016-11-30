/******************************************************************************/
/****************************** CUSTOMER CLASS ********************************/
/******************************************************************************/


/*
	Notes:
		- All time attributes are in terms of minutes since store opening
*/


#include <stdio.h>
#include <random>
#include <bits/random.h>

#include "FoodItem.h"

const double PROB_RETURN_FOR_ITEM       = 0.50; // probability customer returns as soon as item is completed
const double PROB_RETURN_WHILE_LEAVING  = 0.50; // probability customer returns before leaving mall GIVEN not returning as soon as item is completed
random_device rd1;
random_device rd2;
static default_random_engine generator1(rd1());
static default_random_engine generator2(rd2());

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/
 
class Customer {
	private:
		const int _customer_id;   // Unique ID number, sequentially designated
		int _food_id;             // Unique ID number of food item recieved, -1 if NAN
		int _craving;             // Food type customer craves: 0 = cake, 1 = croissant
		int _arrival_time;        // Time that customer arrived
		int _loiter_time;         // Minutes customer intends on staying in mall
		int _return_time;         // Time when customer returns to bakery, -1 if NAN
		int _purchase_time;       // Time that purchase occurs, -1 if NAN
		
	public:
		// Ctor
		Customer(int customer_id, int craving, int arrival_time, int loiter_time);
		// Accessors
		int customer_id();   // Getter: ID
		int food_id();       // Getter: food ID
		int craving();       // Getter: craving
		int arrival_time();  // Getter: arrival time
		int loiter_time();   // Getter: loiter time
		int return_time();   // Getter: loiter_timeime
		int purchase_time(); // Getter: purchase time
		// Mutators
		void food_id(int food_id);                // Setter: food ID
		int  return_time(int food_prep_end_time); // Setter: return time (-1 if no return)
		void purchase_time(int purchase_time);    // Setter: purchase time
		// Write Functions
		void Write(ostream &out);       // Write function for debugging
		void WriteReport(ostream &out); // Special write function for customer rpt
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

Customer::Customer(int customer_id, int craving, int arrival_time, int loiter_time)
: _customer_id(customer_id)
{
	_food_id       = -1;
	_craving       = craving;
	_arrival_time  = arrival_time;
	_loiter_time   = loiter_time;
	_return_time   = -1;
	_purchase_time = -1;
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

int Customer::customer_id()
{
	return _customer_id;
}

int Customer::food_id()
{
	return _food_id;
}

int Customer::craving()
{
	return _craving;
}

int Customer::arrival_time()
{
	return _arrival_time;
}

int Customer::loiter_time()
{
	return _loiter_time;
}

int Customer::return_time()
{
	return _return_time;
}

int Customer::purchase_time()
{
	return _purchase_time;
}

/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

void Customer::food_id(int food_id)
{
	_food_id = food_id;
}

int Customer::return_time(int food_prep_end_time)
{
	// only care if it may be done in time, default return_time value already appropriate
	if((_arrival_time + _loiter_time) <= food_prep_end_time){ // Will be done in time
		static bernoulli_distribution bernDist1(PROB_RETURN_FOR_ITEM);
   		static bernoulli_distribution bernDist2(PROB_RETURN_WHILE_LEAVING);
   	
   		if(bernDist1(generator1)){
		    _return_time = food_prep_end_time;         // Will return when item is ready
		} else if(bernDist2(generator2)) {
			_return_time = _arrival_time + _loiter_time; // Will return while leaving
		}
		// default return_time value appropriate otherwise
	}
	return _return_time; // return when customer has decided to return or -1
}

void Customer::purchase_time(int purchase_time)
{
	_purchase_time = purchase_time;
}

/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/

void Customer::Write(ostream &out)
{
	out << "Customer" << endl;
	out << "\tCustomer ID:         " << _customer_id             << endl;
	out << "\tArrival Time:        " << _arrival_time  << " min" << endl;
	out << "\tSpend T:             " << _loiter_time   << " min" << endl;
	out << "\tRequested Food Type: " << _craving                 << endl;
	out << "\tFood ID:             " << _food_id                 << endl;
	out << "\tPurchase Time:       " << _purchase_time << " min" << endl;
	out << endl;
}

void Customer::WriteReport(ostream &out)
{
	out << _customer_id << " " << _arrival_time << " " << _loiter_time << " " << _craving << " " << _food_id << " " << _purchase_time << endl;
}