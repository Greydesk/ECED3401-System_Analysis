/******************************************************************************/
/****************************** SUPPLIER CLASS ********************************/
/******************************************************************************/

/*
	Notes:
		- 
*/

#include <random>
#include "customer.h"

using namespace std;

const int MIN_DELIVERY_TIME = 1*60; // At least an hour...
const int MAX_DELIVERY_TIME = 2*60; // ... Maybe two

const double PROB_FAST_DELIVERY = 0.50;       // probability delivery arrives in minimum time
random_device rd;                             // Seed for  random generator engine
static default_random_engine generator(rd()); // random engine

/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class supplier{
	private:
		float  _priceCakeKit; // Price of a cake kit
		float  _priceCroiKit; // Price of a croissant kit
		int    _deliveryMinT; // minimum time (in minutes) for a delivery to arrive
		int    _deliveryMaxT; // Maximum time (in minutes) for a delivery to be delayed
		list<FoodItem*> _pending; // List of food items yet to be delivered
		// Pointers to master lists
		list<Customer>* _cMaster;
		list<FoodItem>* _fMaster;
		// Probability entitiy
		static bernoulli_distribution _bernDist;
		
	public:
		supplier(float priceCakeKit, float priceCroiKit, list<Customer>* cMaster, list<Customer>* fMaster); // Supplier Ctor
		void receiveOrder(int time, int ncakes, int ncrois); // process order received at time time
		void presentOrders(int time, Equipment fridge, Equipment freezer);
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

supplier::supplier(float priceCakeKit, float priceCroiKit, list<Customer>* cMaster, list<Customer>* fMaster): _pending()
{
	_priceCakeKit = priceCakeKit;
	_priceCroiKit = priceCroiKit;
	_deliveryMinT = MIN_DELIVERY_TIME;
	_deliveryMaxT = MAX_DELIVERY_TIME;
	_cMaster      = cMaster;
	_fMaster      = fMaster;
	_bernDist(PROB_FAST_DELIVERY);
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

void supplier::receiveOrder(int time, int ncakes, int ncrois)
{
	int deliveryT = time + ((_bernDist(generator)) ? _deliveryMinT : _deliveryMaxT); // Time delivery will arrive
	int newID = 0;
	
	for(int ck = 0; ck < ncakes; ck++){
		_fMaster->push_back(FoodItem(_fMaster->size() + 1, 0, time, deliveryT));
		_pending.push_front(_fMaster->back());
	}

	for(int cr = 0; cr < ncrois; cr++){
		newID = _fMaster->size() + 1;
		_fMaster->push_back(FoodItem(newID, 1, time, deliveryT));
		_pending->push_front(_fMaster->back());
	}
}

void supplier::presentOrders(int time, Equipment fridge, Equipment freezer){
	deque<FoodItem>::iterator itr;
	for (itr =_pending.begin(); itr != _pending.end(); ++itr){
		if(itr->delivery_time() == time) fridge.add();
	}

	std::cout << ' ' << *itr++;
}

/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/
