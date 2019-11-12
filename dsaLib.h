/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;



class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
    ~L1List();

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);// give the reference to the element i-th in the list
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx) ;// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
    int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
    }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
    // todo: your code goes here


	L1Item<T> *pNew, *pPre;
	pNew = new L1Item<T>();
	pNew->data = a;
	if (pNew == NULL)
		return -1;
	if (_pHead == NULL) {
		_pHead = pNew;
		pNew->pNext = NULL;
	}
	else {
		// Find the position of pPre
		pPre = this->_pHead;
		for (int i = 0; i < _size - 1; i++)
			pPre = pPre->pNext;
		// Insert new node
		pNew->pNext = pPre->pNext;
		pPre->pNext = pNew;
	}
	_size++;
	return 0;

}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
	L1Item<T> *pNew = new L1Item<T>;
	pNew->data = a;
	if (pNew == NULL) return -1;
	pNew->pNext = this->_pHead;
	this->_pHead = pNew;
	this->_size++;
	return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
	if (this->_pHead == NULL) return -1;
	L1List<T> *pLoc = this->_pHead;
	this->_pHead = pLoc->pNext;
	pLoc->pNext = NULL;
	delete pLoc;
	this->_size--;
	return 0;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
	if (this->_pHead == NULL) return -1;
	if (this->_size == 1) {
		removeHead();
		return 0;
	}
	L1List<T>* pTemp1 = this->_pHead;
	L1List<T>* pTemp = this->_pHead;
	while (pTemp->pNext != NULL)
	{
		pTemp1 = pTemp;
		pTemp = pTemp->pNext;
	}
	pTemp->pNext = NULL;
	delete pTemp;
	this->_size--;
	return 0;
}
//Implement function find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
template <class T>
bool L1List<T>::find(T& a, int& idx) {


	L1List<T> *pTemp = _pHead; 
		
		for (int i = 0; i < _size - 1; i++)
		{
			if (pTemp -> data == a)
			{
				idx = i; 
				return 1; 
				break; 
			}
			else
			{
				pTemp = pTemp->pNext; 
			}
		}
		if (pTemp == NULL) {
			idx = -1; 
			return 0; 
		}
		
		
}
	
	



// Implement function insert an element into the list at location i. Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insert(int i, T& a) {
	if (i > _size) return -1;
	if (i == 1)
	{
		insertHead(a);
		return 0;
	}
	L1Item<T> * pWalker = _pHead;
	for (int j = 1; j<i ; j++)
	{
		pWalker = pWalker->pNext;
	}
	L1Item<T> *pNew = new L1Item<T>(a);
	pNew->pNext = pWalker->pNext;
	pWalker->pNext = pNew;
	_size++;
	return 0;
	
}
// remove an element at position i in the list. Return 0 if success, -1 otherwise.
template <class T>
int L1List<T>::remove(int i) {
	if (i<1 || i > _size)
	{
		return -1;
	}
	L1Item<T> * pPre = new L1Item<T>;
	L1Item<T> * tmp;
	tmp = _pHead;
	if(i == 1)
	{
		
		delete tmp;
		_size--;
		return 0;

	}
	else
	{
		for (int j = 1; j < i ; j++)
		{
			pPre = tmp;
			tmp = tmp->pNext;
		}
		pPre->pNext = tmp->pNext;
		delete tmp;
		_size--;
		return 0;
	}
	/*if(i < 1 || i> _size)
		return -1;
	L1Item <T> ∗ dltPtr, ∗ pPre;
	if( i == 1)
	{
		dltPtr = _pHead;
		_pHead = _pHead->pNext;
	} else{
		pPre =  _pHead;
		for( int j =1 , j<i-1; j++) pPre = pPre−>pNext;
		dltPtr = pPre−>pNext;
		pPre−> pNext = dltPtr −> pNext;
	}
	delete dltPtr;
	_size−−;
	return 0;*/
	
	
}
template <class T>
//HAM ADD DUNG DUNG SUA NHA TA YEU DAU================================================
T& L1List<T>::at(int i) {
	L1Item<T> *pTemp = _pHead; 
	if (i == 1) return pTemp->data;
	else
	{
		int j = 1; 
		do {
			pTemp = pTemp->pNext; 
			j++; 
		} while (j != i);
	}
	return pTemp->data; 
	
}
#endif //DSA191_A1_DSALIB_H
