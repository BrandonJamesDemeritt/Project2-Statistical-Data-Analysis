#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {

public:

	//Constructors
	//Default
	DynamicArray();

	//Copy Constructor
	DynamicArray(const DynamicArray&);

	//Destructor
	~DynamicArray();


	//Class Memeber Functions

	//Get size
	size_t size() const;

	//Check if empty
	bool empty() const;

	//Add unsigned int to end of array
	void pushBack(float);

	//Remove last item from array
	void popBack();


	//Operator Overloads

	//Deep Copy Overload
	const DynamicArray& operator = (const DynamicArray&);

	//Subscript operator (lvalue)
	float& operator [] (size_t);

	//Subscript operator (rvalue)
	const float& operator [] (size_t) const;


private:

	//Data Fields
	static const size_t DEFAULTCAPACITY;
	size_t capacity;
	size_t numOfItems;
	float* data;


	//Class Member Functions

	//increase size of array when needed
	void resize();

};
#endif
