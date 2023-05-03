#include "DynamicArray.h"
#include <stddef.h>

const size_t DynamicArray::DEFAULTCAPACITY = 10;

//Constructors
//Default
DynamicArray::DynamicArray() : capacity(DEFAULTCAPACITY), numOfItems(0) { data = new float[capacity]; }

//Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& other) {
	data = NULL;
	*this = other;
}

//Destructor
DynamicArray::~DynamicArray() {
	if (data) {
		delete[] data;
	}
}

//Deep Copy Overload
const DynamicArray& DynamicArray::operator = (const DynamicArray& rhs) {
	//make sure not to self assign
	if (this != &rhs) {
		//delete current data and set to null
		if (data) {
			delete[] data;
			data = NULL;
		}
		//copy static values
		capacity = rhs.capacity;
		numOfItems = rhs.numOfItems;
		//copy dynaics values
		if (numOfItems <= capacity) {
			data = new float[capacity];
			for (size_t i = 0; i < numOfItems; i++) {
				data[i] = rhs.data[i];
			}
		}
	}
	//return
	return *this;
}

//Subscript operator (lvalue)
float& DynamicArray::operator [] (size_t index) {
	return data[index];
}

//Subscript operator (rvalue)
const float& DynamicArray::operator [] (size_t index) const {
	return data[index];
}

//Class Memeber Functions
/*Get size of array
* @Return, returns size of array
*/
size_t DynamicArray::size() const {
	return numOfItems;
}

/*Check if array is empty
* @Return true if empty, false if not
*/
bool DynamicArray::empty() const {
	return !size();
}

/*Inceases array size when needed
* doubles array size when out of space
*/
void DynamicArray::resize() {
	capacity *= 2;
	float* newData = new float[capacity];
	for (size_t i = 0; i < size(); i++) {
		newData[i] = data[i];
	}
		delete[] data;
		data = newData;
	
}

/*Adds a new value to end of array
*  @Param, unsigned int value to add to end of array
*/
void DynamicArray::pushBack(float value) {
	if (size() == capacity) {
		resize();
	}
	data[numOfItems++] = value;
}

//Remove last item from array
void DynamicArray::popBack() {
	data[size() - 1] = NULL;
	numOfItems--;
}