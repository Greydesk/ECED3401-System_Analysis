#include <random>
#include "food.h"

const double prob_fast_Delivery = 0.50;       // probability delivery arrives in minimum time
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
		int    _deliveryDlyT; // Maximum time (in minutes) for a delivery to be delayed
		list<foodItem*> _pending; // List of food items yet to be delivered
		// Pointers to master lists
		list<customer>* _cMaster;
		list<foodItem>* _fMaster;
		// Probability entitiy
		static bernoulli_distribution _bernDist;
		
	public:
		supplier(float priceCakeKit, float priceCroiKit, int deliveryMinT, int deliveryMaxT, double probOntime); // Supplier Ctor
		void receiveOrder(int time, int ncakes, int ncrois); // process order received at time time
		void checkOrders();
}

supplier::supplier(float priceCakeKit, float priceCroiKit, int deliveryMinT, int deliveryMaxT, double probOntime)
{
	_priceCakeKit = priceCakeKit;
	_priceCroiKit = priceCroiKit;
	_deliveryMinT = deliveryMinT;
	_deliveryDlyT = deliveryDlylT;
	_bernDist(buy_croissant_chance);
}

void supplier::processOrder(int time, int ncakes, int ncrois;)
{
	int deliveryT = time + ((int) bernolliDistro(generator))*_deliveryDlyT; // Time delivery will arrive
	int newID = 0;
	
	for(int ck = 0; ck < ncakes; ck++){
		newID = _foodmaster.size() + 1;
		_foodMaster.emplace_back(newID, 0, time, deliveryT, );
		_pending.emplace_front(&_foodmaster.back());
	}

	for(int cr = 0; ck < ncrois; cr++){
		newID = _foodmaster.size() + 1;
		_foodMaster.emplace_back(newID, 1, time, deliveryT);
		_pending.emplace_front(&_foodmaster.back());
	}
}


