/******************************************************************************/
/**************************** TALLY SHEET CLASS *******************************/
/******************************************************************************/

/*
	Notes:
		- 
*/

#include <iostream>

using namespace std;
/******************************************************************************/
/***************************** CLASS STRUCTURE ********************************/
/******************************************************************************/

class TallySheet{
	private:
		unsigned int _cakes_ordered;        // Number of cakes ordered
		unsigned int _croissants_ordered;   // Number of croissants ordered
		unsigned int _cakes_delivered;      // Number of cakes delivered
		unsigned int _croissants_delivered; // Number of croissants delivered
		unsigned int _cakes_produced;       // Number of cakes produced
		unsigned int _croissants_produced;  // Number of croissants produced
		unsigned int _cakes_sold;           // Number of cakes sold
		unsigned int _croissants_sold;      // Number of croissants sold
		unsigned int _cakes_discarded;      // Number of cakes discarded
		unsigned int _croissants_discarded; // Number of croissants discarded
		unsigned int _cakes_missed;         // Number of cakes missed
		unsigned int _croissants_missed;    // Number of croissants missed

	private:
		// Ctor
		TallySheet(); // tallysheet Ctor
		// Operational Functions
		void Ordered(int food_type);   // Increment appropriate order     tally
		void Delivered(int food_type); // Increment appropriate delivery  tally
		void Produced(int food_type);  // Increment appropriate produced  tally
		void Sold(int food_type);      // Increment appropriate sold      tally
		void Discarded(int food_type); // Increment appropriate discarded tally
		void Missed(int food_type);    // Increment appropriate missed    tally
		// Misc
		void Reset(void); // Reset all tally counters
		//Writer Functions
		void WriteReport(ostream &out); // write Daily report to out
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

TallySheet::TallySheet() // tallysheet Ctor
{
	_cakes_ordered        = 0;
	_croissants_ordered   = 0;
	_cakes_delivered      = 0;
	_croissants_delivered = 0;
	_cakes_produced       = 0;
	_croissants_produced  = 0;
	_cakes_sold           = 0;
	_croissants_sold      = 0;
	_cakes_discarded      = 0;
	_croissants_discarded = 0;
	_cakes_missed         = 0;
	_croissants_missed    = 0;
}

/******************************************************************************/
/************************** OPERATIONAL FUNCTIONS *****************************/
/******************************************************************************/

void TallySheet::Ordered(int food_type) // Increment appropriate order tally
{
	(food_type == 0) ? _cakes_ordered++ : _croissants_ordered++;
}

void TallySheet::Delivered(int food_type) // Increment appropriate delivery tally
{
	(food_type == 0) ? _cakes_delivered++ : _croissants_delivered++;
}

void TallySheet::Produced(int food_type) // Increment appropriate produced tally
{
	(food_type == 0) ? _cakes_produced++ : _croissants_produced++;
}

void TallySheet::Sold(int food_type) // Increment appropriate sold wtally
{
	(food_type == 0) ? _cakes_sold++ : _croissants_sold++;
}

void TallySheet::Discarded(int food_type) // Increment appropriate discarded tally
{
	(food_type == 0) ? _cakes_discarded++ : _croissants_discarded++;
}

void TallySheet::Missed(int food_type) // Increment appropriate missed tally
{
	(food_type == 0) ? _cakes_missed++ : _croissants_missed++;
}

void TallySheet::Reset(void) // Reset all tally counters
{
	_cakes_ordered        = 0;
	_croissants_ordered   = 0;
	_cakes_delivered      = 0;
	_croissants_delivered = 0;
	_cakes_produced       = 0;
	_croissants_produced  = 0;
	_cakes_sold           = 0;
	_croissants_sold      = 0;
	_cakes_discarded      = 0;
	_croissants_discarded = 0;
	_cakes_missed         = 0;
	_croissants_missed    = 0;
}

/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/

void TallySheet::WriteReport(ostream &out) // write Daily report to out
{
	out << "Ordered raw kits: "   << (_cakes_ordered + _croissants_ordered)     << endl;
	out << "\t#cake "             << _cakes_ordered                             << endl;
	out << "\t#croissant "        << _croissants_ordered                        << endl;
	out << endl;

	out << "Delivered raw kits: " << (_cakes_delivered + _croissants_delivered) << endl;
	out << "\t#cake "             << _cakes_delivered                           << endl;
	out << "\t#croissant "        << _croissants_delivered                      << endl;
	out << endl;

	out << "Produced: "           << (_cakes_produced + _croissants_produced)   << endl;
	out << "\t#cake "             << _cakes_produced                            << endl;
	out << "\t#croissant "        << _croissants_produced                       << endl;
	out << endl;
	
	out << "Sold: "               << (_cakes_sold + _croissants_sold)           << endl;
	out << "\t#cake "             << _cakes_sold                                << endl;
	out << "\t#croissant "        << _croissants_sold                           << endl;
	out << endl;
	
	out << "Discarded: "          << (_cakes_discarded + _croissants_discarded) << endl;
	out << "\t#cake "             << _cakes_discarded                           << endl;
	out << "\t#croissant "        << _croissants_ordered                        << endl;
	out << endl;
	
	out << "Missed Requests: "    << (_cakes_missed + _croissants_missed)        << endl;
	out << "\t#cake "             << _cakes_ordered                              << endl;
	out << "\t#croissant "        << _croissants_ordered                         << endl;
	out << endl;
}
