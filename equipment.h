// Includes equipment class hierarchy and functions
class equipment {
	friend class bakery;
	private:
		int _id;						// Unique ID number, sequentially designated
		deque <foodItem> _items;		// All of the items in this piece of equipment
		int _slots;						//	How many process slots the equipment has
		int _croissantrawtime;			// Raw Croissant Processing Time
		int _croissantcookedtime;		// Cooked Croissant Processing Time
		int _cakerawtime;				// Raw Cake Processing Time
		int _cakecookedtime;			// Cooked Cake Processing Time
		double _random;					//Mu value for randomization
	public:
		equipment(int id, int slots=0, int rcrois=0, int ccrois=0, int rcake=0, int ccake=0, double random=0); 	// Ctor
		int  id();						// Getter: ID
		int slots();					// Getter: Slots
		int rawcroissant();				// Getter: raw croissant process time
		int cookedcroissant();			// Getter: cooked croissant process time
		int rawccake();					// Getter: raw cake process time
		int cookedcake();				// Getter: cooked cake process time
		void write(ostream &out);		// Write function for debugging
		void write_rpt(ostream &out);	// Special write function for customer rpt
};

equipment::equipment(int id, int slots, int rcrois, int ccrois, int rcake, int ccake, double random) {
	_id = id;
	_slots = slots;
	_croissantrawtime = rcrois;
	_croissantcookedtime = ccrois;
	_cakerawtime = rcake;
	_cakecookedtime = ccake;
	_random = random;
}
int equipment::id(){
	return _id;
}
int equipment::slots(){
	return _slots;
}
int equipment::rawcroissant(){
	return _croissantrawtime;
}
int equipment::cookedcroissant(){
	return _croissantcookedtime;
}
int equipment::rawccake(){
	return _cakerawtime;
}
int equipment::cookedcake(){
	return _cakecookedtime;
}
