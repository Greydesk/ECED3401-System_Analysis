#include <random>
#include "food.h"
#include "customer.h"
#include "equipment.h"


const int MIN_DELIVERY_TIME = 1*60; // At least an hour...
const int MAX_DELIVERY_TIME = 2*60; // ... Maybe two

const double PROB_FAST_DELIVERY = 0.50;       // probability delivery arrives in minimum time
random_device rd;                             // Seed for  random generator engine
static default_random_engine generator(rd()); // random engine

/************************************************************************************************************************/
/*************************************************** SUPPLIER CLASS *****************************************************/
/************************************************************************************************************************/
class supplier{
	private:
		float  _priceCakeKit; // Price of a cake kit
		float  _priceCroiKit; // Price of a croissant kit
		int    _deliveryMinT; // minimum time (in minutes) for a delivery to arrive
		int    _deliveryMaxT; // Maximum time (in minutes) for a delivery to be delayed
		list<foodItem*> _pending; // List of food items yet to be delivered
		// Pointers to master lists
		list<customer>* _cMaster;
		list<foodItem>* _fMaster;
		// Probability entitiy
		static bernoulli_distribution _bernDist;
		
	public:
		supplier(float priceCakeKit, float priceCroiKit, list<customer>* cMaster, list<customer>* fMaster); // Supplier Ctor
		void receiveOrder(int time, int ncakes, int ncrois); // process order received at time time
		void presentOrders(int time,  );
}

supplier::supplier(float priceCakeKit, float priceCroiKit, list<customer>* cMaster, list<customer>* fMaster)
{
	_priceCakeKit = priceCakeKit;
	_priceCroiKit = priceCroiKit;
	_deliveryMinT = MIN_DELIVERY_TIME;
	_deliverymaxT = MAX_DELIVERY_TIME;
	_cMaster      = cMaster;
	_fMaster      = fMaster;
	_bernDist(PROB_FAST_DELIVERY);
}

void supplier::receiveOrder(int time, int ncakes, int ncrois)
{
	int deliveryT = time + ((_bernDist(generator)) ? _deliveryMinT : _deliveryMaxT); // Time delivery will arrive
	int newID = 0;
	
	for(int ck = 0; ck < ncakes; ck++){
		_fMaster.emplace_back(_fMaster->size() + 1, 0, time, deliveryT);
		_pending.emplace_front(_fMaster->back());
	}

	for(int cr = 0; ck < ncrois; cr++){
		newID = _foodmaster.size() + 1;
		_fMaster.emplace_back(newID, 1, time, deliveryT);
		_pending.emplace_front(_fmaster->back());
	}
}

void supplier::presentOrders(int time, equipment fridge, equipment freezer){
	deque<foodItem*>::iterator = _pending.begin();
	while (itr != _pending.end()){
		if(*itr->deliveryTime() == time) fridge.add()
	}
    std::cout << ' ' << *it++;
}
