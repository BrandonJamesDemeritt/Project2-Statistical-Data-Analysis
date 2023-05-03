#include "DynamicArray.h"
#include <fstream>
#include <iostream>
#include <stddef.h>
#include <cmath>
#include <iomanip>

using namespace std;

//function declarations
float findSum(DynamicArray);
float average(DynamicArray);
float deviation(DynamicArray);
float correlation(DynamicArray, DynamicArray);
float lineSlope(DynamicArray, DynamicArray);
float lineIntersection(DynamicArray, DynamicArray);

int main() {

	//needed variables
	float x;
	float y;
	DynamicArray xArray;
	DynamicArray yArray;
	
	//open input file
	ifstream fin("data.txt");

	//test input file
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//Create output file
	ofstream fout("results.txt");

	//read in number pairs from file and assign each to array
	while (fin >> x >> y) {
		xArray.pushBack(x);
		yArray.pushBack(y);
	}

	//Output information
	//Output how many pairs processed
	fout << "Number of x-y pairs read: " << setprecision(4) << fixed << xArray.size() << endl << endl;
	//Output the average of X and Y
	fout << "Algebraic average of x: " << average(xArray) << endl;
	fout << "Algebraic average of y: " << average(yArray) << endl;
	//Output the deviation of x and y
	fout << "Standard deviation of x: " << deviation(xArray) << endl;
	fout << "Standard deviation of y: " << deviation(yArray) << endl << endl;
	//Output the correlation coefficient
	fout << "Correlation coefficient " << correlation(xArray, yArray) << endl << endl;
	//output the best fit line function, slop, and intercept
	fout << "Linear fitting function: " << endl << endl << "y = " << lineSlope(xArray, yArray) << "x + " << lineIntersection(xArray, yArray) << endl << endl;
	fout << "Slope: " << lineSlope(xArray, yArray) << endl;
	fout << "Intercept: " << lineIntersection(xArray, yArray) << endl;

	//Close files and exit
	fin.close();
	fout.close();
	return 0;
}

/*Find the sum of an array of items (Sigma xi)
* @Param DynamicArray to find the sum of
* @Return: float of the sum
*/
float findSum(DynamicArray array) {
	float sum = 0;
	for (size_t i = 0; i < array.size(); i++) {
		sum += array[i];
	}
	return sum;
}

/*Find squared sum.  Finds the total of Sigma (xi - xAverage)^2
* @Param:  DynamicArray to find the sum with
* @Return: float 
*/
float squaredSum(DynamicArray array) {
	float total = 0;
	for (size_t i = 0; i < array.size(); i++) {
		total += (array[i] - average(array)) * (array[i] - average(array));
	}
	return total;
}

/*Find the average of an array (Sum of each item / total number of items)
* @Param: DynamicArray to find the average of
* @Return: float of the average
*/
float average(DynamicArray array) {
	float avg = 0;
	avg = findSum(array) / array.size();
	return avg;
}

/*Find the standard deviation of an array
* @Param DynamicArray to find the deviation of
* @Return float of the deviation
*/
float deviation(DynamicArray array) {
	float deviation = 0;
	deviation = sqrt(squaredSum(array) / array.size());
	return deviation;
}

/*Find the Correlation coefficient of the two arrays
* @Param, two DynamicArrays to find the correlation of (one X points, one Y points)
* @Return float of the correlation
*/
float correlation(DynamicArray x, DynamicArray y) {
	float ntotal = 0;
	float dtotal = 0;
	for (size_t i = 0; i < x.size(); i++) {
		ntotal += (x[i] - average(x)) * (y[i] - average(y));
	}
	dtotal += sqrt(squaredSum(x)) * sqrt(squaredSum(y));
	return ntotal / dtotal;
}

/*Find the slope of the best fit line
* @Param, two DynamicArrays, one of x points, one of y points
* @Return, float of the slope.
*/
float lineSlope(DynamicArray x, DynamicArray y) {
	float xy = 0;
	float x2 = 0;
	for (size_t i = 0; i < x.size(); i++) {
		xy += x[i] * y[i];
	}
	for (size_t i = 0; i < x.size(); i++) {
		x2 += x[i] * x[i];
	}
	return (x.size() * (xy) - findSum(x) * findSum(y)) / (x.size() * x2 - (findSum(x) * findSum(x)));
}

/*Find the Intercept of the best fit line
* @Param, two Dynamic Arrays, one of x Points, one of y Points
* @Return, float of the intercept
*/
float lineIntersection(DynamicArray x, DynamicArray y) {
	return (findSum(y) - lineSlope(x, y) * findSum(x)) / x.size();
}