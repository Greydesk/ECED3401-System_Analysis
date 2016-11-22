#include <stdio.h>
#include <random>

const double prob_return_for_item       = 0.50; // probability customer returns as soon as item is completed
const double prob_return_before_leaving = 0.25; // probability customer returns before leaving mall

static default_random_engine generator1(rd1());
static default_random_engine generator2(rd1());

/*
const double buy_croissant_chance = 0.5;   // probability of buying croissant
const int    simulation_duration  = 16*60; // in minutes

// to have a seed for each random generator engine
random_device rd1;
random_device rd2;
random_device rd3;

// random engines
static default_random_engine generator1(rd1());
static default_random_engine generator2(rd1());
static default_random_engine generator3(rd1());

// output file
ofstream os_customers("customers.txt");

int main(int argc, char** argv)
{	
    // random distributions
    static poisson_distribution<int>        poissonDistro(average_customer_rate);
    static exponential_distribution<double> exponentialDistro(1/average_spend_time);
    static bernoulli_distribution           bernolliDistro(buy_croissant_chance);
	
    //total number of generated customers
    int count = 0;
	
    //array to keep the number of customers comming in every minute (by poisson distribution)
    int arrivals[simulation_duration];
	
    //generating arrivals
    for(int i = 1; i <= simulation_duration; i++) {
        arrivals[i] = poissonDistro(generator1);
        count      += arrivals[i];
    }
	
    //writing total number of customers
    os_customers << count << endl;
	
    //writing each customer entry
    for(int i = 1; i <= simulation_duration; i++) {
        for (int j = 1; j <= arrivals[i]; j++) {
            // wrinting arrival time
            os_customers << i << " ";
            // writing spend time (exponential distribution)
            os_customers << (int) exponentialDistro(generator2) << " ";
            // writing type of desired food
            os_customers << (int) bernolliDistro(generator3)    << endl;
        }
    }
}
*/
class customer {
	private:
		int _id;        // Unique ID number, sequentially designated
		int _foodID;    // Unique ID number of food item recieved, -1 if NAN
		int _craving;   // Food type customer craves: 0 = cake, 1 = croissant
		int _arrivalT;  // minutes since store opening that customer arrived
		int _loiterT;   // minutes customer intends on staying in mall
		int _returnT;   // Time when customer returns to bakery, -1 if N
		int _purchaseT; // minutes since store opening that purchase occurs, -1 if NAN
		
	public:
		customer(int id, int foodID = -1, int craving, int arrivalT, ); // Ctor
		int  id();        // Getter: ID
		int  foodID();    // Getter: food ID
		int  craving();   // Getter: craving
		int  arrivalT();  // Getter: arrival time
		int  loiterT();   // Getter: loiter time
		int  returnT();   // Getter: return time
		int  purchaseT(); // Getter: purchase time
		
		void foodID(int f_id);   // Setter: food ID
		void purchaseT(int p_t); // Setter: purchase time
		
		void write(ostream &out);     // Write function for debugging
		void writeRpt(ostream &out); // Special write function for customer rpt
};

customer::customer(int id, int craving, int arrivalTime, int loiterTime){
	int _id           = id;
	int _foodID       = -1;
	int _craving      = craving;
	int _arrivalTime  = arrivalT;
	int _loiterT   = loiterT;
	int _returnT   = -1;
	int _purchaseT = -1;
	
	
}

int customer::id(){
	return _id;
}

int customer::foodID(){
	return _foodID;
}

int customer::craving(){
	return _craving;
}

int customer::arrivalT(){
	return _arrivalT;
}

int customer::loiterT(){
	return _loiterT;
}

int customer::purchaseT(){
	return _purchaseT;
}

void customer::foodID(int f_id){
	_foodID = f_id;
}

void customer::purchaseT(int p_t){
	_purchaseT = p_t;
}

void customer::write(ostream &out){
	out << "Customer" << endl;
	out << "\tCustomer ID:         " << _id                     << endl;
	out << "\tArrival Time:        " << _arrivalT  << " min" << endl;
	out << "\tSpend T:          "    << _loiterT   << " min" << endl;
	out << "\tRequested Food Type: " << _craving                << endl;
	out << "\tFood ID:             " << _foodID                 << endl;
	out << "\tPurchase Time:       " << _purchaseT << " min" << endl;
}

void customer::write_rpt(ostream &out){
	out << _id      << " " << _arrivalT  << " " << _loiterT << " "
	    << _craving << " " << _foodID    << " " << _purchaseT << endl;
}
