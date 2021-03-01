#pragma once

#include<iostream>
#include<string>
#include"HashNode.h"

using namespace std;

//template for generic type 
template<typename K, typename V>
class HashMap
{
private:
	double size;
	HashNode<K, V> **arr;
	int capacity;
	int collisionsCount;
	double maxLoadFactor;

public:
	HashMap();
	~HashMap();
	bool isPrime(int n);
	int nextPrime(int n);
	void insertNode(K key, V value);
	V find(K key);
	int computeHash(string d);
	int getCollisions();
	double sizeofMap();
	void display();
	int capacityFunction();

};

//default constructor
template <typename K,typename V>
HashMap<K, V>::HashMap()
{
	//Initial capacity of hash array 
	capacity = 13;
	size = 0;
	maxLoadFactor = .75;
	arr = new HashNode<K, V>*[capacity];
	collisionsCount = 0;
	//Initialise all elements of array as nullpte 
	for (int i = 0; i < capacity; i++)
		arr[i] = nullptr;
}

//default destructor
template <typename K, typename V>
HashMap <K, V>::~HashMap()
	{
		delete[]arr;
	}

// This implements hash function to find index for a key 
template <typename K, typename V>
int HashMap <K, V>::computeHash(string d)
{
	int sum = 0; // sum of all the digits in date
	int s = d.length(); // length of date string
	for (int i = 0; i < s; i++) //traversing date string
	{
		if (d[i] != '-') //if the char is not a hyphen, add it to sum
		{
			sum += (d[i] - 48); //ascii, numbers start from 48
		}
	}
	string inter = to_string(sum); //string of intermediate sum

	int size2 = inter.length(); //length of inter
	if (size2 == 1)
		return sum;
	int num = 0;
	if (size2 > 1)
	{
		num = 0; // this is our hash KEY

		while (size2 > 1)
		{
			num = 0;
			//cout << size2 << endl;
			for (int t = 0; t < size2; t++)
			{
				num += (inter[t] - 48);
			}
			inter = to_string(num);
			size2 = inter.length();
			//cout << size2 << endl;

		}
	}
	return num;
}


/*
* Returns whether n is prime or not
*/
template <typename K, typename V>
bool HashMap <K, V>::isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;
	if (n == 1 || n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

/*
 * Finding next prime size of the table
 * @param n - current size of the array
 */

template <typename K, typename V>
int HashMap <K, V>::nextPrime(int n)
{
	if (n <= 0)
		n == 3;
	if (n % 2 == 0)
		n++;
	for (; !isPrime(n); n += 2);
	return n;
}
	//Function to add key value pair 

/*
	A function to insert the name and birthday
	@param key - a string of the birthday
	@param value - a string name
	if Load factor is greater than max load factor the capacity is increased to the next prime number
	if the value at the hashIndex is a nullptr insert the value
	while there is no empty space go through quadratic probing to find a new spot to insert the value
*/
template <typename K, typename V>
void HashMap <K, V>::insertNode(K key, V value)
{
	// if loadfactor is greater than or equal to 75% then increase the capacity by double 
	if ((size / capacity) >= maxLoadFactor)
	{
		int newCapacity = nextPrime(capacity+1);
		HashNode<K, V>**newTable = new HashNode<K, V>*[newCapacity];
		for (int i = 0; i < capacity; i++)
		{
			newTable[i] = arr[i];
		}
		for (int i = capacity; i < newCapacity; i++)
		{
			newTable[i] = nullptr;
		}
		arr = newTable;
		capacity = newCapacity;
	}
	HashNode<K, V> *temp = new HashNode<K, V>(key, value);
	int hashed = computeHash(key);
	// Apply hash function to find index for given key 
	int hashIndex = hashed % capacity;
	int NUM = 1;
	//find next free space  
	while (arr[hashIndex] != nullptr)
	{
		hashIndex += (NUM * NUM);
		hashIndex = hashIndex % capacity;
		NUM++;
		collisionsCount++;
	}

	//if new node to be inserted increase the current size 
	if (arr[hashIndex] == NULL)size++;
	arr[hashIndex] = temp;

	return;
}

//Function to search the value for a given key 
// @param key - the birthday of the person
template <typename K, typename V>
V HashMap <K, V>::find(K key) {
	bool found = false;
	size_t hashIndex = computeHash(key);
	hashIndex = hashIndex % capacity;
	int NUM = 1;
	while (!found && arr[hashIndex] != nullptr)
	{
		found = arr[hashIndex]->getKey() == key;
		if (!found) 
		{
			hashIndex += NUM * NUM;
			hashIndex = hashIndex % capacity;
			NUM++;
		}
	}
	if (found) {
		return arr[hashIndex]->getValue();
	}
	else
		return "an Invalid Data";
}


//Return current size of the hash table
template <typename K, typename V>
double HashMap <K, V>::sizeofMap()
{
	return size;
}

//A sunction that displays the hash table keys and their respective values 
template <typename K, typename V>
void HashMap <K, V>::display()
{
	for (int i = 0; i < capacity; i++)
	{
		if (arr[i] != nullptr)
			cout << "Key = " << arr[i]->getKey() << " Value = " << arr[i]->getValue() << endl;
	}
	cout << endl;
}



// A function to return the capacity (size) of the hashtable
template <typename K, typename V>
int HashMap <K, V>::capacityFunction()
{
	return capacity;
}

//A function to count the number of collisions
template <typename K, typename V>
int HashMap <K, V>::getCollisions()
{
	return collisionsCount++;
}
