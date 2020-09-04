#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Functions.h"
using namespace std;

int main() 
{

		auto start = std::chrono::high_resolution_clock::now();
	
		readQuestion();
		
		auto finish = std::chrono::high_resolution_clock::now();

	//	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
	//	cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << " microseconds" << endl;
		cout << "Run time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " milliseconds." << endl << endl;
		
		system("pause");
	
}
