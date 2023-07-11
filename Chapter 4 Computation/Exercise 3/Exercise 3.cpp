/*3. Read a sequence of double values into a vector.Think of each value as
the distance between two cities along a given route.Compute and print
the total distance(the sum of all distances).Find and print the smallest
and greatest distance between two neighboring cities.Find and print the
mean distance between two neighboring cities.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    vector<double> distanceVec;
	double total = 0;
	double smallest = 0;
	double greatest = 0;
	double mean = 0;

	for (double route; cin >> route; )
	{
		distanceVec.push_back(route);
		total += route;

		if (route < smallest)
			smallest = route;
		else if (route > greatest)
			greatest = route;
	}

	//calculate the mean distance:
	mean = total / distanceVec.size();

	cout << "Shortest route:\t" << smallest << '\n';
	cout << "Longest route:\t" << greatest << '\n';
	cout << "Average distance:\t" << mean << '\n';

}

