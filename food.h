// Create food class hierarchy and functions
class fooditem{
	private:
		int _id;          // Sequential, unique ID indicating 
		int _fType;       // Type of food item: 0 = cake, 1 = croissant
		int _orderT;      // Time when item (kit) was ordered, -1 if NAN
		int _delivT;      // Time when item (kit) was delivered, -1 if NAN
		int _prepStrT;    // Time when prep began, -1 if NAN
		int _prepEndT;    // Time when prep ended, -1 if NAN
		int _relinquishT; // Time when item was either sold/discarded, -1 if NAN
		int _status;      // -1 = default, 0 = discarded, 1 = sold, 2 = on-hold
		int _cID;         // ID of customer who holds claim over item , -1 by default/discarded

	public:
		fooditem(int id, int fType, int orderT = -1, int delivT = -1, int prepStrT = -1, int prepEndT = -1, int relinquishT = -1, int status  = -1, int cID = -1);
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
}

fooditem(int id, int fType, int orderT, int delivT, int prepStrT, int prepEndT, int relinquishT, int status, int cID){
	int _id          = id;
	int _fType       = fType;
	int _orderT      = orderT;
	int _delivT      = delivT;
	int _prepStrT    = prepStrT;
	int _prepEndT    = prepEndT;
	int _relinquishT = relinquishT;
	int _status      = status;
	int _cID         = cID;
}

int id(){
	return _id;
}

int fType(){
	return _fType;
}

int orderT(){
	return _orderT;
}

int delivT(){
	return _delivT;
}

int prepStrT(){
	return _prepStrT;
}

int prepEndT(){
	return _prepStrT;
}

int relinquishT(){
	return _relinquishT;
}

int status(){
	return _status;
}

void orderT(int orderT){
	_orderT = orderT;
}

void delivT(int delivT){
	_delivT = delivT;
}

void prepStrT(int prepStrT){
	_prepStrT = prepStrT;
}

void prepEndT(int prepEndT){
	_prepEndT = prepEndT;
}

void relinquishT(int relinquishT){
	_relinquishT = relinquishT;
}

void status(int status) {
	_status = status;
}

void write(ostream &out){
	out << "Food Item" << endl;
	out << "\tFood ID:                " << _id                    << endl;
	out << "\tFood Type:              " << _fType                 << endl;
	out << "\tOrder Kit Time:         " << _orderT      << " min" << endl;
	out << "\tDelivered Kit Time:     " << _delivT      << " min" << endl;
	out << "\tStart Preparation Time: " << _prepStrT    << " min" << endl;
	out << "\tEnd Preparation Time:   " << _prepEndT    << " min" << endl;
	out << "\tSold/Discarded Time:    " << _relinquishT << " min" << endl;
	out << "\tSold/Discarded:         " << ((_relinquish==2) ? -1 : _relinquishT) << " min" << endl; // Status 2 not
	out << "\tCustomer ID Bought :    " << _cID                   << endl;
}

void write_Rpt(ostream &out){
	out << _id          << " " << _fType    << " " << _orderT   << " "
	    << _delivT      << " " << _prepStrT << " " << _prepEndT << " "
	    << _relinquishT << " " << ((_relinquish==2) ? -1 : _relinquishT) << " "
	    << endl;
}
