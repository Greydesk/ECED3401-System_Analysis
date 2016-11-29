// Includes equipment class hierarchy and functions

/******************************************************************************/
/****************************** EQUIPMENT CLASS *******************************/
/******************************************************************************/

#include <deque>
#include "foodItem.h"

/*
	Notes:
		- default values for time variables indicate they are irrelevant within
		  the particular equipment instance (eg. freezer wouldn't need 
		  processing times, raw cake lifetime, etc.)
*/

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class equipment {
	friend class bakery;
	private:
		int _id;                 // Unique ID number, sequentially designated
		int _slots;              // How many process slots the equipment has
		deque<foodItem*>  _items; // All of the items in this piece of equipment
		deque<foodItem*>* _output_location;
		list<foodItem>*   _food_master;
		list<customer>*   _customer_master;
		
		
	public:
		equipment(int id, int slots=0, int croiRawLT=-1, int cakeRawLT=-1, int croiProcT=-1, int cakeProcTime=-1, int croiReadyLT=-1, int cakeReadyLT=-1); // Ctor
		// Getters
		int id();          // Getter: ID
		int slots();       // Getter: Slots
		int croiRawLT();   // Getter: raw lifetime of a croissant
		int cakeRawLT();   // Getter: raw lifetime of a cake
		int croiProcT();   // Getter: processing time of a croissant
		int cakeProcT();   // Getter: processing time of a cake
		int croiReadyLT(); // Getter: Shelf life of a ready croissant
		int cakeReadyLT(); // Getter: Shelf life of a ready cake
		// Operational functions
		void store(foodItem* newItem); // Adds an item and begins processing
		foodItem* remove(foodItem* oldItem); // Removes one item
		void trashOne(int ID); // Discards one specific item
		void trashAll(void);   // Discards all items for end-of-day cleanup
		// Deque functions
		bool full();                  // Returns true if deque is full
		bool empty();                 // Returns true if the deque is empty
		//Writing Functions
		void write(ostream &out);     // Write function for debugging
		void write_rpt(ostream &out); // Special write function for customer rpt
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

equipment::equipment(int id, int slots, int croiRawLT, int cakeRawLT, int croiProcT, int cakeProcT, int croiReadyLT, int cakeReadyLT): _items()
{
	_id           = id;
	_slots        = slots;
	_croiRawLT    = croiRawLT;
	_cakeRawLT    = cakeRawLT;
	_croiProcT    = croiProcT;
	_cakeProcT    = cakeProcT;
	_croiReadyLT  = croiReadyLT;
	_cakeReadyLT  = cakeReadyLT;
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

int equipment::id()
{
	return _id;
}

int equipment::slots()
{
	return _slots;
}

int equipment::croiRawLT()
{
	return _croiRawLT;
}

int equipment::cakeRawLT()
{
	return _cakeRawLT;
}

int equipment::croiProcT()
{
	return _croiProcT;
}

int equipment::cakeProcT()
{
	return _cakeProcT;
}

int equipment::croiReadyLT()
{
	return _croiReadyLT;
}

int equipment::cakeReadyLT()
{
	return _cakeReadyLT;
}

/******************************************************************************/
/************************** OPERATIONAL FUNCTIONS *****************************/
/******************************************************************************/



/******************************************************************************/
/************************** DESCRIPTIVE FUNCTIONS *****************************/
/******************************************************************************/

bool equipment::empty()
{
	return _items.empty();
}

bool equipment::full()
{
	return (_items.size() == _slots);
}

/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/

void equipment::write(ostream &out)
{
	out << "Equipment" << endl;
	out << "\tID:                         " << _id           << endl;
	out << "\tSlots:                      " << _slots        << endl;
	out << "\tRaw Croissant Lifetime:     " << _croiRawLT    << endl;
	out << "\tRaw Cake Lifetime:          " << _cakeRawLT    << endl;
	out << "\tCroissant Process Time:     " << _croiProcT    << endl;
	out << "\tCake Process Time:          " << _cakeProcT    << endl;
	out << "\tReady Croissant Shelf Life: " << _croiReadyLT  << endl;
	out << "\tReady Cake Shelf Life:      " << _cakeReadyLT  << endl;
	out << "\tItems in deque:             " << _items.size() << endl;
	if (_items.empty()){
		out << "\tEmpty" << endl;
	} else {
		deque<foodItem>::iterator f;
		for(f = _items.begin(); f != _items.end(); f++){
			out << "\t" << f->id() << endl;
		}
	}
}
