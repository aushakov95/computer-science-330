/***********************************************************************
K Zemoudeh
4/7/08
String.cpp

Implementation of constructors and member functions defined in String.h.
************************************************************************/

#include <cassert>

#include "String.h"

// default constructor
String::String()
{
	size = 0;
	buffer = 0;
}

// constructor from char string to String
// find the size of p first, allocate space for it, assign p to buffer
String::String(const char * p)
{
	int p_size = 0;
	for (const char *q = p; *q; q++)
		p_size++;
	buffer = new char[p_size];

	for (int i = 0; i < p_size; i++)
		buffer[i] = p[i];

	size = p_size;
}

// copy constructor
String::String(const String & source)
{
	size = source.size;
	buffer = new char[size];
	for (int i = 0; i < size; i++)
		buffer[i] = source.buffer[i];
}

String::~String()
{
	delete [] buffer;
}

int String::length()
{
	return size;
}

// array index operator
char & String::operator[](const int i)
{
	assert(i < size);
	return buffer[i];
}

String String::operator+=(const String & source)
{
	int temp_size = size + source.size;
	char * temp;
	temp = new char[temp_size];
	int i;
	for (i = 0; i < size; i++)
		temp[i] = buffer[i];
	for (int j = 0; j < source.size; j++, i++)
		temp[i] = source.buffer[j];
	delete [] buffer;
	size = temp_size;
	buffer = temp;
	return *this;
}

// assignment operator
// similar to char string constructor, delete the old buffer,
// create a new buffer and size based on source
String String::operator=(const String & source)
{
	delete [] buffer;
	size = source.size;
	buffer = new char[size];

	int i;
	for (i = 0; i < size; i++)
		buffer[i] = source.buffer[i];

	return *this;
}

bool operator==(const String & left, const String & right)
{
	int i, j;
	for (i = 0, j = 0; i < left.size and j < right.size; i++, j++)
		if (left.buffer[i] != right.buffer[j])
			return false;
	if (i == left.size and j == right.size)
		return true;
	return false;
}

bool operator<=(const String & left, const String & right)
{
	int i, j;
	for (i = 0, j = 0; i < left.size and j < right.size; i++, j++)
		if (left.buffer[i] != right.buffer[j])
			if (left.buffer[i] <= right.buffer[j])
				return true;
			else{
                 return false;
            }
	if (i == left.size)
		return true;
	return false;
}

bool operator<(const String & left, const String & right)
{
	if (left <= right and !(left == right))
		return true;
	return false;
}

ostream & operator<<(ostream & out, const String & s)
{
	for (int i = 0; i < s.size; i++)
		out << s.buffer[i];
	return out;
}
