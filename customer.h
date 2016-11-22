class customer {
	friend class bakery;
	private:
		int _id;           // Unique ID number, sequentially designated
		int _foodID;       // Unique ID number of food item recieved, -1 if NAN
		int _craving;      // Food type customer craves: 0 = cake, 1 = croissant
		int _arrivalTime;  // minutes since store opening that customer arrived
		int _loiterTime;   // minutes customer intends on staying in mall
		int _purchaseTime; // minutes since store opening that purchase occurs
		                   // -1 if NAN
	public:
		customer(int id, int foodID = -1, int craving, int arrivalTime, int loiterTime, int purchaseTime = -1); // Ctor
		int  id();                    // Getter: ID
		int  foodID();                // Getter: food ID
		int  craving();               // Getter: craving
		int  arrivalTime();           // Getter: arrival time
		int  loiterTime();            // Getter: loiter time
		int  purchaseTime();          // Getter: purchase time
		void foodID(int f_id);        // Setter: food ID
		void purchaseTime(int p_t);   // Setter: purchase time
		void write(ostream &out);     // Write function for debugging
		void write_rpt(ostream &out); // Special write function for customer rpt
};

customer::customer(int id, int foodID, int craving, int arrivalTime, int loiterTime, int purchaseTime){
	int _id           = id;
	int _foodID       = foodID;
	int _craving      = craving;
	int _arrivalTime  = arrivalTime;
	int _loiterTime   = loiterTime;
	int _purchaseTime = purchaseTime;
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

int customer::arrivalTime(){
	return _arrivalTime;
}

int customer::loiterTime(){
	return _loiterTime;
}

int customer::purchaseTime(){
	return _purchaseTime;
}

void customer::foodID(int f_id){
	_foodID = f_id;
}

void customer::purchaseTime(int p_t){
	_purchaseTime = p_t;
}

void customer::write(ostream &out){
	out << "Customer" << endl;
	out << "\tCustomer ID:         " << _id                     << endl;
	out << "\tArrival Time:        " << _arrivalTime  << " min" << endl;
	out << "\tSpend Time:          " << _loiterTime   << " min" << endl;
	out << "\tRequested Food Type: " << _craving                << endl;
	out << "\tFood ID:             " << _foodID                 << endl;
	out << "\tPurchase Time:       " << _purchaseTime << " min" << endl;
}

void customer::write_rpt(ostream &out){
	out << _id      << " " << _arrivalTime  << " " << _loiterTime << " "
	    << _craving << " " << _foodID       << " " << _purchaseTime << endl;
}
/*It will have to :
be accessible to the bakery
be able to be called through the process() method
determine if an item moves from display/fridge to sales. */
