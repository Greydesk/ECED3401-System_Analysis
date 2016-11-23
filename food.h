// Create food class and functions
#include <iostream>

class foodItem{
	private:
		int _id;          // Sequential, unique ID indicating 
		int _fType;       // Type of food item: 0 = cake, 1 = croissant
		int _orderT;      // Time when item (kit) was ordered, -1 if NAN
		int _delivT;      // Time when item (kit) was delivered, -1 if NAN
		int _prepStrT;    // Time when prep began, -1 if NAN
		int _prepEndT;    // Time when prep ended, -1 if NAN
		int _relinquishT; // Time when item was either sold/discarded, -1 if NAN
		int _status;      // -1 = default, 0 = discarded, 1 = sold
		int _cID;         // ID of customer who holds claim over item , -1 by default/discarded

	public:
		foodItem(int id, int fType);
		foodItem(int id, int fType, int orderT, int cID);
		int id();          // Getter: ID     of food item
		int fType();       // Getter: Type   of food item
		int orderT();      // Getter: Time   of kit order
		int delivT();      // Getter: Time   of kit delivery
		int prepStrT();    // Getter: Time   of food prep start
		int prepEndT();    // Getter: Time   of food prep end
		int relinquishT(); // Getter: Time   of food item relinquishing
		int status();      // Getter: Status of food item
		int cID();         // Getter: ID     of customer holding claim over item
		void orderT(int orderT);           // Setter: Time   of kit order
		void delivT(int delivT);           // Setter: Time   of kit delivery
		void prepStrT(int prepStrT);       // Setter: Time   of food prep start
		void prepEndT(int prepEndT);       // Setter: Time   of food prep end
		void relinquishT(int relinquishT); // Setter: Time   of food item relinquishing
		void status(int status);           // Setter: Status of food item
		void cID(int buyid);               // Setter: ID     of customer holding claim over item
		void write(ostream &out);     // General write method
		void write_Rpt(ostream &out); // Specialized write method for food report
};

foodItem::foodItem(int id, int fType) // Ctor for initial stock
{
	_id          = id;
	_fType       = -1;
	_orderT      = -1;
	_delivT      = -1;
	_prepStrT    = -1;
	_prepEndT    = -1;
	_relinquishT = -1;
	_status      = -1;
	_cID         = -1;
}

foodItem::foodItem(int id, int fType, int orderT, int cID) // Ctor for ordered stock w/o customer req
{
	_id          = id;
	_fType       = fType;
	_orderT      = orderT;
	_delivT      = -1;
	_prepStrT    = -1;
	_prepEndT    = -1;
	_relinquishT = -1;
	_status      = -1;
	_cID         = cID;
}
/*
foodItem::foodItem(int id, int fType, int orderT, int _delivT, int cID) // Ctor for ordered stock w/o customer req
{
	_id          = id;
	_fType       = -1;
	_orderT      = orderT;
	_delivT      = delivT;
	_prepStrT    = -1;
	_prepEndT    = -1;
	_relinquishT = -1;
	_status      = -1;
	_cID         = cID;
}
*/
int foodItem::id()
{
	return _id;
}

int foodItem::fType()
{
	return _fType;
}

int foodItem::orderT(){
	return _orderT;
}

int foodItem::delivT()
{
	return _delivT;
}

int foodItem::prepStrT()
{
	return _prepStrT;
}

int foodItem::prepEndT()
{
	return _prepStrT;
}

int foodItem::relinquishT()
{
	return _relinquishT;
}

int foodItem::status()
{
	return _status;
}

int foodItem::cID()
{
	return _cID;
}

void foodItem::orderT(int orderT)
{
	_orderT = orderT;
}

void foodItem::delivT(int delivT)
{
	_delivT = delivT;
}

void foodItem::prepStrT(int prepStrT)
{
	_prepStrT = prepStrT;
}

void foodItem::prepEndT(int prepEndT)
{
	_prepEndT = prepEndT;
}

void foodItem::relinquishT(int relinquishT)
{
	_relinquishT = relinquishT;
}

void foodItem::status(int status)
{
	_status = status;
}

void foodItem::write(ostream &out)
{
	out << "Food Item" << endl;
	out << "\tFood ID:                " << _id                    << endl;
	out << "\tFood Type:              " << _fType                 << endl;
	out << "\tOrder Kit Time:         " << _orderT      << " min" << endl;
	out << "\tDelivered Kit Time:     " << _delivT      << " min" << endl;
	out << "\tStart Preparation Time: " << _prepStrT    << " min" << endl;
	out << "\tEnd Preparation Time:   " << _prepEndT    << " min" << endl;
	out << "\tSold/Discarded Time:    " << _relinquishT << " min" << endl;
	out << "\tSold/Discarded:         " << ((_relinquish == 2) ? -1 : _relinquishT) << " min" << endl; // Status 2 not
	out << "\tCustomer ID Bought :    " << _cID                   << endl;
}

void foodItem::write_Rpt(ostream &out)
{
	out << _id          << " " << _fType    << " " << _orderT   << " "
	    << _delivT      << " " << _prepStrT << " " << _prepEndT << " "
	    << _relinquishT << " " << ((_relinquish==2) ? -1 : _relinquishT) << " "
	    << endl;
}
