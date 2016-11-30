// Includes equipment class hierarchy and functions

/******************************************************************************/
/****************************** EQUIPMENT CLASS *******************************/
/******************************************************************************/

#include <deque>

#include "customer.h"

#define CAKE_SHELF_LIFE 6*60 // How long a cake will be sellable after completion
#define CROISSANT_SHELF_LIFE 6*60 // How long a croissant will be sellable after completion
/*
	Notes:
		- default values for time variables indicate they are irrelevant within
		  the particular equipment instance (eg. freezer wouldn't need 
		  processing times, raw cake lifetime, etc.)
*/

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class Equipment {
	friend class Bakery;
	private:
		// Attributes
		const int _equipment_id; // Unique ID number, sequentially designated
		const int _slots;        // How many item slots this piece of equipment has
		
	public:
		// Ctor
		Equipment(int equipment_id, int slots);
		// Accessors
		int equipment_id(); // Getter: ID
		int slots();        // Getter: Slots
		// Operation Functions
		
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

Equipment::Equipment(int equipment_id, int slots)
: _equipment_id(equipment_id), _slots(slots)
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
