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

class tallySheet{
	private:
		unsigned int _cakesOrdered;   // Number of cakes ordered
		unsigned int _croisOrdered;   // Number of croissants ordered
		unsigned int _cakesDelivered; // Number of cakes delivered
		unsigned int _croisDelivered; // Number of croissants delivered
		unsigned int _cakesProduced;  // Number of cakes produced
		unsigned int _croisProduced;  // Number of croissants produced
		unsigned int _cakesSold;      // Number of cakes sold
		unsigned int _croisSold;      // Number of croissants sold
		unsigned int _cakesDiscarded; // Number of cakes discarded
		unsigned int _croisDiscarded; // Number of croissants discarded
		unsigned int _cakesMissed;    // Number of cakes missed
		unsigned int _croisMissed;    // Number of croissants missed

	private:
		// Ctor
		tallySheet(); // tallysheet Ctor
		// Operational 
		void ordered(int fType);   // Increment appropriate order     tally
		void delivered(int fType); // Increment appropriate delivery  tally
		void produced(int fType);  // Increment appropriate produced  tally
		void sold(int fType);      // Increment appropriate sold      tally
		void discarded(int fType); // Increment appropriate discarded tally
		void missed(int fType);    // Increment appropriate missed    tally
		
		void reset(void); // Reset all tally counters
		
		void write_Rpt(ostream &out); // write Daily report to out
};

/******************************************************************************/
/********************************** CTOR **************************************/
/******************************************************************************/

tallySheet::tallySheet() // tallysheet Ctor
{
	_cakesOrdered   = 0;
	_croisOrdered   = 0;
	_cakesDelivered = 0;
	_croisDelivered = 0;
	_cakesProduced  = 0;
	_croisProduced  = 0;
	_cakesSold      = 0;
	_croisSold      = 0;
	_cakesDiscarded = 0;
	_croisDiscarded = 0;
	_cakesMissed    = 0;
	_croisMissed    = 0;
}

/******************************************************************************/
/********************************* GETTERS ************************************/
/******************************************************************************/

// None necessary

/******************************************************************************/
/********************************* SETTERS ************************************/
/******************************************************************************/

void tallySheet::ordered(int fType) // Increment appropriate order tally
{
	(fType == 0) ? _cakesOrdered++ : _croisOrdered++;
}

void tallySheet::delivered(int fType) // Increment appropriate delivery tally
{
	(fType == 0) ? _cakesDelivered++ : _croisDelivered++;
}

void tallySheet::produced(int fType) // Increment appropriate produced tally
{
	(fType == 0) ? _cakesProduced++ : _croisProduced++;
}

void tallySheet::sold(int fType) // Increment appropriate sold tally
{
	(fType == 0) ? _cakesSold++ : _croisSold++;
}

void tallySheet::discarded(int fType) // Increment appropriate discarded tally
{
	(fType == 0) ? _cakesDiscarded++ : _croisDiscarded++;
}

void tallySheet::missed(int fType) // Increment appropriate missed tally
{
	(fType == 0) ? _cakesMissed++ : _croisMissed++;
}

void tallySheet::reset(void) // Reset all tally counters
{
	_cakesOrdered   = 0;
	_croisOrdered   = 0;
	_cakesDelivered = 0;
	_croisDelivered = 0;
	_cakesProduced  = 0;
	_croisProduced  = 0;
	_cakesSold      = 0;
	_croisSold      = 0;
	_cakesDiscarded = 0;
	_croisDiscarded = 0;
	_cakesMissed    = 0;
	_croisMissed    = 0;
}

/******************************************************************************/
/********************************* WRITERS ************************************/
/******************************************************************************/

void tallySheet::write_Rpt(ostream &out) // write Daily report to out
{
	out << "Ordered raw kits: "   << (_cakesOrdered + _croisOrdered)    << endl;
	out << "\t#cake "             << _cakesOrdered                      << endl;
	out << "\t#croissant "        << _croisOrdered                      << endl;
	out << endl;

	out << "Delivered raw kits: " << (_cakesDelivered +_croisDelivered) << endl;
	out << "\t#cake "             << _cakesDelivered                    << endl;
	out << "\t#croissant "        << _croisDelivered                    << endl;
	out << endl;

	out << "Produced: "           << (_cakesProduced + _croisProduced)  << endl;
	out << "\t#cake "             << _cakesProduced                     << endl;
	out << "\t#croissant "        << _croisProduced                     << endl;
	out << endl;
	
	out << "Sold: "               << (_cakesSold + _croisSold)          << endl;
	out << "\t#cake "             << _cakesSold                         << endl;
	out << "\t#croissant "        << _croisSold                         << endl;
	out << endl;
	
	out << "Discarded: "          << (_cakesDiscarded +_croisDiscarded) << endl;
	out << "\t#cake "             << _cakesDiscarded                    << endl;
	out << "\t#croissant "        << _croisOrdered                      << endl;
	out << endl;
	
	out << "Missed Requests: "    << (_cakesMissed+_croisMissed)        << endl;
	out << "\t#cake "             << _cakesOrdered                      << endl;
	out << "\t#croissant "        << _croisOrdered                      << endl;
	out << endl;
}
