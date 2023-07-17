// Try This Page 156.cpp : Look it up. Check some information sources to pick good values for the
//min_temp(the “minimum temperature”) and max_temp(the “maximum
//temperature”) constants for our program.Those values will determine the
//limits of usefulness of our program.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	double sum = 0;
	double high_temp = -128.60; // initialize to impossibly low
	double low_temp = 134; // initialize to “impossibly high”
	int no_of_temps = 0;
	for (double temp; cin >> temp; ) { // read temp
		++no_of_temps; // count temperatures
		sum += temp; // compute sum
		if (temp > high_temp) high_temp = temp; // find high
		if (temp < low_temp) low_temp = temp; // find low
	}
	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum / no_of_temps << '\n';
}

