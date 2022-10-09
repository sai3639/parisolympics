#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"
#include <fstream>
using std::string;

using std::cin;
using std::cout;
using std::endl;

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data( double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
  

  for (unsigned int i = 0; i < SIZE;  ++i){
	cin >> timeArray[i];
    cin >> countryArray[i];
  	cin >> numberArray[i];
  	cin >> lastnameArray[i];
	
  }



  bool tru;	
  
  for (unsigned int i = 0; i < SIZE; ++i ){
	if (timeArray[i] > 0){
		tru = true;
	
	}
	else{
		tru = false;
		return tru;
	}
	
  }
  
  for (unsigned int i = 0; i < SIZE; ++i){

	int countLet = 0;
	for (unsigned int letter = 0; countryArray[i][letter]; letter ++){
		if ((isupper(countryArray[i][letter]))){
			tru = true;
			
		}
		else{
			tru = false;
			
			return tru;
		}
		countLet += 1;
		
	}

	if (countLet != 3){
		tru = false;
		return false;
	
	
  }

 
  }
	
	for (unsigned int i = 0; i < SIZE; ++i){

		if (numberArray[i] <= 99){
			tru = true;
		}
		else{
			tru = false;
			return tru;
		}
		
  	}
	for (unsigned int i = 0; i < SIZE; ++i){
		int letcount = 0;
		for (int letter = 0; lastnameArray[i][letter]; ++letter){
			if (isalpha(lastnameArray[i][letter])){
				tru = true;
			}
			else{
				tru = false;
				return tru;
			}
			letcount += 1;
			
		}
		if ((1 < letcount) && (tru == true)){
			tru = true;
		}
		else{
			tru = false;
			return tru;
		}
	
	
	}
	

	

  // Update function to return the correct boolean values based on the parameters
  return tru; // set so it will compile
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  unsigned int i;
  for (i = 0; i < SIZE; ++i){
	ary[i] = {};
  }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	 unsigned int i;
  	 for (i = 0; i < SIZE; ++i){
		ary[i] = {};
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	 unsigned int i;
  	 for (i = 0; i < SIZE; ++i){
		ary[i] = "N/A";
  }
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	//parallel array is a structure that contains multiple arrays 
	//each are the same size and the elemnts are related to each other 
	//int max = 0;
	//int rankArray[SIZE];
	//int count = 0;
	//compare two numbers next to each other in array
	for (unsigned int i = 0; i < SIZE; ++i){
		//int t = 0;
		int rank = 1;
		for (unsigned int j = 0; j < SIZE; ++j){
			if(timeArray[j] < timeArray[i]){
				rank += 1;
			}
		}
		rankArray[i] = rank;
	}
	
	//for (unsigned int i = 0; i < SIZE; ++i){
	//	cout << rankArray[i] << endl;
	//}
	
	return;
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{
	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
				
			}
			
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
			
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}