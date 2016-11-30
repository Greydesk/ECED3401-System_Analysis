/*
 * File:    bakery.cpp
 * Authors: Christian Muise and Rod Naugler
 * Created on November 21, 2016
 */

/* PREPROCESSOR DIRECTIVES */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <deque>
#include <list>

using namespace std;

#include "bakery.h"
#include "customer.h"
#include "equipment.h"
#include "foodItem.h"
#include "supplier.h"
#include "tallySheet.h"

#define CLOSING_TIME 16*60

// Include all necessary standard headers...
// ... and custom headers
// Define Constants as required

/* CLASS DECLARATION */
// Don't actually; declare classes and define their functions in files to be included above

int main(void)
{
  // Initialize variables
  list<Customer> custMaster;
  list<FoodItem> foodMaster;
  list<Customer*> mall; // Store loiterers that may will return
  
  bakery();
  
  
  // Read Input files
  
  // Open-up shop

  // Iterate minute-by-minute through day
  for(int time = 1; time<=CLOSING_TIME; time++){
  	// Trash expiried food
  	
  	// End prep time on cooled items
	
	// Form queue from returning customers in mall...
	
	// ... and then newly arriving customers
	
	// If there are customers queued, sell possible items
	 
	// Transfer baked items into storage locations
	
	// Sell all possible newly ready items
	
	// Begin baking raw items
	
	// Receive and store orders
	
	// Begin baking all possible newly arrived items
	
	// If queued customers remain, transfer them to mall if they will return...
	
	// ... otherwise dismiss them outright.
	
	// 
	
	// IF AN ORDER COULD ARRIVE IN TIME TO BE PROCESSED AND SOLD
	
		// Order items if the number of items on order is less than the empty storage slots plus 
 	
	}
  		
	// Trash remaining stock; Use CLOSING_TIME as necessary
		
    // Write reports
  
  	// close i/o files
}









