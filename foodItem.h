// Create food class and functions

/******************************************************************************/
/***************************** FOOD ITEM CLASS ********************************/
/******************************************************************************/

/*
	Notes:
		- Much information can be inferred form the variable values
			- ((customer_id is set)^(time + prepStart)) --> ()
			- () --> ()
*/

#include <iostream>

using namespace std;

#define HOLD_TIME 15
/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class FoodItem{
	private:
		int _food_id;         // Sequential, unique ID indicating 
		int _food_type;       // Type of food item: 0 = cake, 1 = croissant
		int _order_time;      // Time when item (kit) was ordered, -1 if NAN
		int _delivery_time;   // Time when item (kit) was delivered, -1 if NAN
		int _prep_start_time; // Time when prep began, -1 if NAN
		int _prep_end_time;   // Time when prep ended, -1 if NAN
		int _relinquish_time; // Time when item was either sold/discarded, -1 if NAN
		int _status;          // -1 = default, 0 = discarded, 1 = sold
		int _customer_id;     // ID of customer who holds claim over item , -1 by default/discarded

	public:
		// Ctors
		FoodItem(int food_id, int food_type); // For initial stock
		FoodItem(int food_id, int food_type, int order_time, int _delivery_time); // For ordered stock w/o customer req
		FoodItem(int food_id, int food_type, int order_time, int _delivery_time, int customer_id); // For ordered stock w/ customer req
		// Getters
		int food_id();         // Getter: ID     of food item
		int food_type();       // Getter: Type   of food item
		int order_time();      // Getter: Time   of kit order
		int delivery_time();   // Getter: Time   of kit delivery
		int prep_start_time(); // Getter: Time   of food prep start
		int prep_end_time();   // Getter: Time   of food prep end
		int relinquish_time(); // Getter: Time   of food item relinquishing
		int status();          // Getter: Status of food item
		int customer_id();     // Getter: ID     of customer holding claim over item
		// Setters
		void order_time(int order_time);           // Setter: Time   of kit order
		void delivery_time(int delivery_time);     // Setter: Time   of kit delivery
		void prep_start_time(int prep_start_time); // Setter: Time   of food prep start
		void prep_end_time(int prep_end_time);     // Setter: Time   of food prep end
		void relinquish_time(int relinquish_time); // Setter: Time   of food item relinquishing
		void status(int status);                   // Setter: Status of food item
		void customer_id(int customer_id);         // Setter: ID     of customer holding claim over item
		// Descriptive Functions
		int  IsReserved(void); // returns customer ID if reserved, -1 otherwise
		// Write Functions
		void Write(ostream &out);       // General write method
		void WriteReport(ostream &out); // Specialized write method for food report
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

FoodItem::FoodItem(int food_id, int food_type) // For initial stock
{
	_food_id         = food_id;
	_food_type       = food_type;
	_order_time      = -1;
	_delivery_time   = -1;
	_prep_start_time = -1;
	_prep_end_time   = -1;
	_relinquish_time = -1;
	_status          = -1;
	_customer_id     = -1;
}

FoodItem::FoodItem(int food_id, int food_type, int order_time, int delivery_time) // For ordered stock w/o customer req
{
	_food_id         = food_id;
	_food_type       = food_type;
	_order_time      = order_time;
	_delivery_time   = delivery_time;
	_prep_start_time = -1;
	_prep_end_time   = -1;
	_relinquish_time = -1;
	_status          = -1;
	_customer_id     = -1;
}

FoodItem::FoodItem(int food_id, int food_type, int order_time, int delivery_time, int customer_id) // For ordered stock w customer req
{
	_food_id         = food_id;
	_food_type       = food_type;
	_order_time      = order_time;
	_delivery_time   = delivery_time;
	_prep_start_time = -1;
	_prep_end_time   = -1;
	_relinquish_time = -1;
	_status          = -1;
	_customer_id     = customer_id;
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

int FoodItem::food_id()
{
	return _food_id;
}

int FoodItem::food_type()
{
	return _food_type;
}

int FoodItem::order_time()
{
	return _order_time;
}

int FoodItem::delivery_time()
{
	return _delivery_time;
}

int FoodItem::prep_start_time()
{
	return _prep_start_time;
}

int FoodItem::prep_end_time()
{
	return _prep_start_time;
}

int FoodItem::relinquish_time()
{
	return _relinquish_time;
}

int FoodItem::status()
{
	return _status;
}

int FoodItem::customer_id()
{
	return _customer_id;
}

/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

void FoodItem::order_time(int order_time)
{
	_order_time = order_time;
}

void FoodItem::delivery_time(int delivery_time)
{
	_delivery_time = delivery_time;
}

void FoodItem::prep_start_time(int prep_start_time)
{
	_prep_start_time = prep_start_time;
}

void FoodItem::prep_end_time(int prep_end_time)
{
	_prep_end_time = prep_end_time;
}

void FoodItem::relinquish_time(int relinquish_time)
{
	_relinquish_time = relinquish_time;
}

void FoodItem::status(int status)
{
	_status = status;
}

void FoodItem::customer_id(int customer_id)
{
	_customer_id = customer_id;
}

/******************************************************************************/
/**************************** WRITE FUNCTIONS *********************************/
/******************************************************************************/

void FoodItem::Write(ostream &out)
{
	out << "Food Item" << endl;
	out << "\tFood ID:                " << _food_id                   << endl;
	out << "\tFood Type:              " << _food_type                 << endl;
	out << "\tOrder Kit Time:         " << _order_time      << " min" << endl;
	out << "\tDelivered Kit Time:     " << _delivery_time   << " min" << endl;
	out << "\tStart Preparation Time: " << _prep_start_time << " min" << endl;
	out << "\tEnd Preparation Time:   " << _prep_end_time   << " min" << endl;
	out << "\tSold/Discarded Time:    " << _relinquish_time << " min" << endl;
	out << "\tSold/Discarded:         " << _status          << " min" << endl;
	out << "\tCustomer ID Bought :    " << _customer_id               << endl;
}

void FoodItem::WriteReport(ostream &out)
{
	out << _food_id         << " " << _food_type       << " " << _order_time    << " "
	    << _delivery_time   << " " << _prep_start_time << " " << _prep_end_time << " "
	    << _relinquish_time << " " << _status          << " " << endl;
}
