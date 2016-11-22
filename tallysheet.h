#include "bakery.h"

class tallySheet{
	private:
		unsigned int _cakesOrdered;
		unsigned int _croisOrdered;
		unsigned int _cakesDelivered;
		unsigned int _croisDelivered;
		unsigned int _cakesProduced;
		unsigned int _croisProduced;
		unsigned int _cakesSold;
		unsigned int _croisSold;
		unsigned int _cakesDiscarded;
		unsigned int _croisDiscarded;
		unsigned int _cakesMissed;
		unsigned int _croisMissed;

	private:
		tallySheet(); // tallysheet Ctor

		void ordered(int ftype);   // Increment appropriate order tally
		void delivered(int ftype); // Increment appropriate delivery tally
		void produced(int ftype);  // Increment appropriate produced tally
		void sold(int ftype);      // Increment appropriate sold tally
		void discarded(int ftype); // Increment appropriate discarded tally
		void missed(int ftype);    // Increment appropriate missed tally
		
		void writeRpt(ostream &out) // write Daily report to out
}

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

int  tallySheet::ordered(int ftype)   // Increment appropriate order tally
{
	(ftype == 0) ? _cakesOrdered++ : _croisOrdered++;
}

int  tallySheet::delivered(int ftype) // Increment appropriate delivery tally
{
	(ftype == 0) ? _cakesDelivered++ : _croisDelivered++;
}

int  tallySheet::produced(int ftype)  // Increment appropriate produced tally
{
	(ftype == 0) ? _cakesProduced++ : _croisProduced++;
}

int  tallySheet::sold(int ftype)      // Increment appropriate sold tally
{
	(ftype == 0) ? _cakesSold++ : _croisSold++;
}

int  tallySheet::discarded(int ftype) // Increment appropriate discarded tally
{
	(ftype == 0) ? _cakesDiscarded++ : _croisDiscarded++;
}

int  tallySheet::missed(int ftype)    // Increment appropriate missed tally
{
	(ftype == 0) ? _cakesMissed++ : _croisMissed++;
}

void tallySheet::write_Rpt(ostream &out) // write Daily report to out
{
	out << "Ordered raw kits: "   << (_cakesOrdered + _croisOrdered)     << endl;
	out << "\t#cake "             << _cakesOrdered                       << endl;
	out << "\t#croissant "        << _croisOrdered                       << endl << endl;

	out << "Delivered raw kits: " << (_cakesDelivered + _croisDelivered) << endl;
	out << "\t#cake "             << _cakesDelivered                     << endl;
	out << "\t#croissant "        << _croisDelivered                     << endl << endl;

	out << "Produced: "           << (_cakesProduced + _croisProduced)   << endl;
	out << "\t#cake "             << _cakesProduced                      << endl;
	out << "\t#croissant "        << _croisProduced                      << endl << endl;

	out << "Sold: "               << (_cakesSold + _croisSold)           << endl;
	out << "\t#cake "             << _cakesSold                          << endl;
	out << "\t#croissant "        << _croisSold                          << endl << endl;

	out << "Discarded: "          << (_cakesDiscarded + _croisDiscarded) << endl;
	out << "\t#cake "             << _cakesDiscarded                     << endl;
	out << "\t#croissant "        << _croisOrdered                       << endl << endl;

	out << "Missed Requests: "    << (_cakesMissed+_croisMissed)         << endl;
	out << "\t#cake "             << _cakesOrdered                       << endl;
	out << "\t#croissant "        << _croisOrdered                       << endl << endl;
}
