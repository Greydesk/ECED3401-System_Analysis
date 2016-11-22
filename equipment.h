// Includes equipment class hierarchy and functions
class equipment {
	friend class bakery;
	private:
		int _id;						// Unique ID number, sequentially designated

	public:
		equipment(int id); 				// Ctor
		int  id();						// Getter: ID
		void write(ostream &out);		// Write function for debugging
		void write_rpt(ostream &out);	// Special write function for customer rpt
};
