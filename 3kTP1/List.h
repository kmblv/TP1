#pragma once
#include <iostream>
using namespace std;

template<class T>
class List
{
private:
	class Node
	{
	public:
		Node* next_ptr;
		Node* prev_ptr;
		T data;
	};

	size_t _size = 0;
	Node* first = nullptr;
	Node* last = nullptr;

public:
	List();
	List(const List<T>& other);
	~List();
	bool empty();

	size_t size();

	void push_back(T new_data);
	T pop_front();
	T pop(size_t i);

	List<T>& operator= (const List<T>& other);

	T& operator[] (size_t const& i);

	template<class U>
	friend std::ostream& operator<< (std::ostream& out, const List<U>& other);

	template<class U>
	friend std::istream& operator>> (std::istream& in, List<U>& V);
};

//---------------------------------------------------

template<class T>
inline List<T>::List() {}

template<class T>
inline List<T>::List(const List<T>& other)
{
	this->_size = 0;
	List::Node* temp = other.first;
	for (size_t i = 0; i < other._size; i++)
	{
		this->push_back(temp->data);
		temp = temp->next_ptr;
	}
}

template<class T>
inline List<T>::~List()
{
	if (!empty())
		while (!(empty()))
			pop_front();
}

template<class T>
inline bool List<T>::empty() { return !first; }

template<class T>
inline size_t List<T>::size()
{
	return _size;
}

template<class T>
inline void List<T>::push_back(T new_data)
{
	if (empty())
	{
		first = last = new Node;
		last->data = new_data;
		last->next_ptr = nullptr;
		last->prev_ptr = nullptr;
	}
	else
	{
		Node* temp = new Node;
		temp->prev_ptr = last;
		temp->next_ptr = nullptr;
		last->next_ptr = temp;
		temp->data = new_data;
		last = temp;
	}
	++_size;
}

template<class T>
inline T List<T>::pop_front()
{
	if (empty()) throw - 1;
	else if (last == first)
	{
		T temp_data = first->data;
		delete first;
		first = last = nullptr;
		--_size;
		return temp_data;
	}
	else
	{
		Node* temp = first->next_ptr;
		T temp_data = first->data;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
		--_size;
		return temp_data;
	}
}

template<class T>
inline T List<T>::pop(size_t i_i)
{
	if (empty() || i_i >= _size || i_i < 0) throw - 1;
	else if (last == first)
	{
		T temp_data = first->data;
		delete first;
		first = last = nullptr;
		--_size;
		return temp_data;
	}
	else if (i_i == 0)
	{
		Node* temp = first->next_ptr;
		T temp_data = first->data;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
		--_size;
		return temp_data;
	}
	else if (i_i == _size - 1)
	{
		Node* temp = last->prev_ptr;
		T temp_data = last->data;
		delete last;
		temp->next_ptr = nullptr;
		last = temp;
		--_size;
		return temp_data;
	}
	else
	{
		Node* temp = first;
		for (size_t i = 0; temp != nullptr && i < i_i; ++i)
			temp = temp->next_ptr;
		temp->next_ptr->prev_ptr = temp->prev_ptr;
		temp->prev_ptr->next_ptr = temp->next_ptr;
		T temp_data = temp->data;
		delete temp;
		--_size;
		return temp_data;
	}
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& other)
{
	while (!(this->empty()))
		this->pop_front();
	this->_size = other._size;
	List::Node* temp = other.first;
	for (size_t i = 0; i < this->_size; i++)
	{
		this->push_back(temp->data);
		temp = temp->next_ptr;
	}
	return *this;
}

template<class T>
inline T& List<T>::operator[](size_t const& i)
{
	if (empty() || i >= _size || i < 0) throw - 1;
	List::Node* temp = i < _size / 2 ? first : last;
	if (i < _size / 2)
		for (size_t _i = 0; _i < i; ++_i)
			temp = temp->next_ptr;
	else
		for (size_t _i = _size - 1; _i > i; --_i)
			temp = temp->prev_ptr;
	return temp->data;
}

template<class U>
inline std::ostream& operator<<(std::ostream& out, const List<U>& other)
{
	List<U> A(other);
	while (!(A.empty()))
		out << A.pop_front() << " ";
	return out;
}

template<class U>
istream& operator>>(istream& in, List<U>& V)
{
	U a;
	cout << " size__ " << V._size << " ";
	for (size_t i = 0; i < V._size; i++) {
		in >> a;
		V.push_back(a);
	}
	return in;
}



//#include"List.inl"