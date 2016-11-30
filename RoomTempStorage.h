 // Includes equipment class hierarchy and functions

/******************************************************************************/
/****************************** RoomTempStorage CLASS *******************************/
/******************************************************************************/

#include <deque>
#include "FoodItem.h"

/*
	Notes:
		- default values for time variables indicate they are irrelevant within
		  the particular equipment instance (eg. freezer wouldn't need 
		  processing times, raw cake lifetime, etc.)
*/

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class RoomTempStorage: public Equipment {
	friend class Bakery;
	private:
		// Attributes
		//const int _equipment_id; // Unique ID number, sequentially designated
		//const int _slots;        // How many item slots the equipment has
		const int _croissant_shelf_life;
		
		// Containers
		// queue<foodItem*> _cake_queue; // Queue of all cakes in this piece of equipment
		// queue<foodItem*> _croissant_queue; // Queue of all cakes in this piece of equipment
		// Destinations
		// queue
		// Master Lists
		const deque<foodItem>* _food_master_ptr;     // pointer to food master deque
		const deque<customer>* _customer_master_ptr; // pointer to customer master deque
		
	public:
		// Ctor
		Equipment(int equipment_id, int slots, list<foodItem>* food_master_ptr, list<customer>* customer_master_ptr);
		// Accessors
		int equipment_id(); // Getter: ID
		int slots();        // Getter: Slots
		// int num_cakes();      // The number of croissants being held
		// int num_croissants(); // The number of cakes being held
		// Operational functions
		// void Add(int time, fooditem* new_food_item);     // Adds a food item
		// foodItem* Remove(int time, int food_item_id);                // Removes a food item
		// void Discard(int time, fooditem* old_food_item); // Discards a food item
		// void DiscardAll(void);                 // Discards all food items
		// Deque functions
		//bool full();  // Returns true if deque is full
		//bool empty(); // Returns true if the deque is empty
		//Writing Functions
		void Write(ostream &out); // Write function for debugging
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

Equipment::Equipment(int equipment_id, int slots, list<foodItem>* food_master_ptr, list<customer>* customer_master_ptr)
: equipment_id_(equipment_id), slots_(slots), items_(), food_master_ptr_(food_master_ptr), customer_master_ptr_(customer_master_ptr)
{
	// No more initializations needed
}

/******************************************************************************/
/******************************** ACCESSORS ***********************************/
/******************************************************************************/

int Equipment::equipment_id() // Getter: equipment ID
{
	return _equipment_id;
}

int Equipment::slots() // Getter: number of slots
{
	return _slots;
}

/*int equipment::num_cakes() // The number of croissants
{
	return _num_cakes;
}

int equipment::num_croissants() // The number of cakes
{
	return _num_croissants;
}*/

/******************************************************************************/
/************************** OPERATIONAL FUNCTIONS *****************************/
/******************************************************************************/

/*void Add(int time, FoodItem* new_food_item) // Adds a food item
{
	if(this->full()){ // Must make room
		(_items.back()->food_type() == 0) ? _num_cakes-- : _num_croissants--;
		_items.pop_back();
	}
	(new_food_item.food_type() == 0) ? _num_cakes++ : _num_croissants++;
	_items.push_front(new_food_item);
}

FoodItem* Remove(int desired_item_id) // Removes a food item
{
	FoodItem* food_item_ptr = NULL;
	
	deque<FoodItem>::iterator f;
	for(f = _items.begin(); f != _items.end(); f++){	
		if (f->food_item_id() == dsired_item_id){
			food_item_ptr = _items[f];
			_items.erase(f);
			break;
		}
	}
	
	return food_item_ptr;
}

void Discard(fooditem* old_food_item) // Discards a food item
{
	
}

void DiscardAll(int time) // Discards all food items
{
	deque<FoodItem>::iterator f;
	for(f = _items.begin(); f != _items.end(); f++){	
		f->food_item_id() == dsired_item_id){
			food_item_ptr = _items[f];
			_items.erase(f);
			break;
		}
	}
}

/******************************************************************************/
/************************** DESCRIPTIVE FUNCTIONS *****************************/
/******************************************************************************/

/*bool equipment::empty() // Retrurns true if items_ is empty
{
	return _items.empty();
}*/

/* bool equipment::full() // Retrurns true if items_ is full
{
	return (_items.size() == slots_);
}*/

/******************************************************************************/
/*************************** WRITING FUNCTIONS ********************************/
/******************************************************************************/

/*void equipment::Write(ostream &out)
{
	out << "Equipment" << endl;
	out << "\tID:             " << _equipment_id << endl;
	out << "\tSlots:          " << _slot_        << endl;
	out << "\tItems in deque: " << _items.size() << endl;
	if (_items.empty()){
		out << "\tEmpty" << endl;
	} else {
		deque<foodItem>::iterator f;
		for(f = _items.begin(); f != _items.end(); f++){
			out << "\t" << f->id() << endl;
		}
	}
}*/
