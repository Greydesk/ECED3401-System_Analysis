/******************************************************************************/
/****************************** EQUIPMENT CLASS *******************************/
/******************************************************************************/

/*
	Notes:
		- 
*/

#include <deque>
#include <queue>

#include "Equipment.h"

using namespace std;

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class Fridge: public Equipment {
	private:
		// Attributes(none)
		// Containers
		queue<FoodItem*> _raw_cakes;   // Queue of all raw   cakes (cake kits) in the fridge
		deque<FoodItem*> _ready_cakes; // Queue of all ready cakes in the fridge
		
	public:
		// Ctor
		Fridge(int equipment_id, int slots);
		// Operational functions
		void      RemoveHolds(int time);                      // Removes claims customers have over ready cakes if eough time has passed
		void      Store(int time, FoodItem* new_food_item);   // Receives a cake and stores it appropriately
		FoodItem* RemoveRawCake(int time);                    // Removes  a raw cake for baking, 
		FoodItem* RemoveReadyCake(int time, int customer_id); // Removes  a ready cake for sale, NULL if no cakes are currently availible
		void      Discard(int time);                          // Discards cake closest to expiration (firstly unreserved and then reserved
		void      DiscardAll(int time);                           // Discards all cakes for end-of-day protocol
		// Descriptive functions
		int  NumRawCakes(void);  // Returns the total number of cakes
		int  NumReadyCakes(void); // Returns the total number of cakes
		int  NumCakes(void);     // Returns total number of cakes stored in fridge
		bool empty(void);        // Returns true if feidge is empty
		bool full(void);         // Returns true if fridge is full
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

Fridge::Fridge(int equipment_id, int slots)
: Equipment(equipment_id, slots), _raw_cakes(), _ready_cakes()
{
	// No more initializations needed
}

/******************************************************************************/
/************************** OPERATIONAL FUNCTIONS *****************************/
/******************************************************************************/
void Fridge::RemoveHolds(int time)
{
	deque<FoodItem*>::iterator f; 
		
	for(f = _ready_cakes.begin(); f != _ready_cakes.end(); f++){ // iterate through
		if ((*f)->prep_end_time() + HOLD_TIME < time){               // find reserved cakes that have waited long enough...
			(*f)->customer_id(-1);                                   // ... and revoke customer's claim over item.
		}
	}
}

void Fridge::Store(int time, FoodItem* new_food_item) // Receives a cake and store it appropriately
{
	if(this->full()){ // Case where Fridge is full
		this->Discard(time);
	}
	
	if(new_food_item->prep_start_time() == -1){ // Raw Cake has veen received
		_raw_cakes.push(new_food_item);
	} else { // Ready Cake has been received
		_ready_cakes.push_back(new_food_item);
	}
}

void Fridge::Discard(int time) // Discards a cake to make room for new objects closest to expiration (firstly unreserved and then reserved
{
	deque<FoodItem*>::iterator f;
	
	if(!_raw_cakes.empty()){                       // If the fridge contains raw cakes...
		_raw_cakes.front()->relinquish_time(time); // ... set the relinquish time...
		_raw_cakes.front()->customer_id(-1);       // ... and customer ID of oldest raw cake...
		_raw_cakes.pop();                          // ... before removing it from the deque
		return;                                     // exit function
		
	} else if(!_ready_cakes.empty()){             // No raw cakes		
		for(f = _ready_cakes.end(); f != _ready_cakes.begin(); f++){ // iterate through and find optimal match
			if ((*f)->customer_id() == -1){                          // Discard first unreserved cake
				(*f)->relinquish_time(time);                         // ... set the relinquish time...
				(*f)->status(0);                                     // ... set status...
				(*f)->customer_id(-1);                               // ... and customer ID of oldest raw cake.
				_ready_cakes.erase(f);
				return ;                                             // Exit function
			}
		}
		// If you've made it this far, there are no unreserved cakes, so eliminate the oldest reserved cake
		f = _ready_cakes.end();
		(*f)->relinquish_time(time); // ... set the relinquish time...
		(*f)->customer_id(-1);       // ... and customer ID of oldest raw cake...
		(*f)->status(0);             // ... set status...
		_ready_cakes.erase(f);    // Remove from list
	}
}

FoodItem* Fridge::RemoveRawCake(int time) // Removes a raw cake for baking, 
{
	FoodItem* temp_ptr;
	_raw_cakes.front()->prep_start_time(time);
	temp_ptr = _raw_cakes.front();
	_raw_cakes.pop();
	return temp_ptr;
}

FoodItem* Fridge::RemoveReadyCake(int time, int customer_id) // Removes a ready cake for sale, NULL if no cakes are currently availible
{
	FoodItem* temp_ptr;
	
	deque<FoodItem*>::iterator f;
	
	for(f = _ready_cakes.begin(); f != _ready_cakes.end(); f++){ // iterate through and find optimal match
		if((*f)->customer_id() == customer_id){                  // Found a reserved food item!
			(*f)->relinquish_time(time);                         // ... set the relinquish time...
			(*f)->status(1);                                     // ... the status to sold...
			(*f)->customer_id(customer_id);                      // and customer's ID
			temp_ptr = *f;
			_ready_cakes.erase(f);
		}
	}
	
	return temp_ptr;
}

void Fridge::DiscardAll(int time) // Discards all cakes for end-of-day protocol
{
	deque<FoodItem*>::iterator f; 
	
	while(!_raw_cakes.empty()){ // iterate through and find optimal match
		_raw_cakes.front()->relinquish_time(time); // ... set the relinquish time...
		_raw_cakes.front()->status(0);
		_raw_cakes.front()->customer_id(-1); // Found a reserved food item!
		_raw_cakes.pop();
	}
	
	for(f = _ready_cakes.begin(); f != _ready_cakes.end(); f++){ // iterate through and find optimal match
		(*f)->relinquish_time(time); // ... set the relinquish time...
		(*f)->status(0);
		(*f)->customer_id(-1); // ... and customer ID of oldest ready cake...
		_ready_cakes.erase(f);
	}
}

/******************************************************************************/
/************************** DESCRIPTIVE FUNCTIONS *****************************/
/******************************************************************************/

int Fridge::NumRawCakes(void) // Returns the total number of cakes
{
	return _raw_cakes.size();
}

int Fridge::NumReadyCakes(void) // Returns the total number of cakes
{
	return _ready_cakes.size();
}

int Fridge::NumCakes(void) // Returns the total number of cakes
{
	return (this->NumRawCakes() + this->NumReadyCakes());
}

bool Fridge::empty() // Retrurns true if items_ is empty
{
	return (this->NumCakes() == 0);
}

bool Fridge::full() // Retrurns true if items_ is full
{
	return (this->NumCakes() == slots());
}

