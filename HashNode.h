#pragma once
#include<iostream>
#include<string>
using namespace std;

//template for generic type 
template<typename K, typename V>
//Hashnode class 
class HashNode
{
private:
	V value;
	K key;
public:
	HashNode();
	HashNode(K key, V value);
	~HashNode();
	void setKey(K key2);
	K getKey();
	void setValue(V value2);
	V getValue();
};

//default constructor
template<typename K, typename V>
HashNode<K,V>::HashNode()
{
	this->value = "";
	this->key = "";
}

//default destructor
template<typename K, typename V>
HashNode<K, V>::~HashNode()
{
	delete key;
	delete value;
}

//constructor with parameters
template<typename K, typename V>
HashNode<K, V>::HashNode(K key2, V value2)
{
	this->value = value2;
	this->key = key2;
}

//A function to set the key 
//@param key2 - the birthday 
template<typename K, typename V>
void HashNode<K, V>::setKey(K key2)
{
	key = key2;
}

//a function that returns the key
template<typename K, typename V>
K HashNode<K, V>::getKey() 
{
	return key; 
}

//A function to set the Value
//@param value2 - the name 
template<typename K, typename V>
void HashNode<K, V>::setValue(V value2) 
{
	value = value2; 
}

//A function to return the value 
template<typename K, typename V>
V  HashNode<K, V>::getValue() 
{
	return value; 
}