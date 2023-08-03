#pragma once
#ifndef LR3_4_LIST_H
#define LR3_4_LIST_H

#include <iostream>

#include "Exception.h"

template<class KeyT, class DataT>
class [[maybe_unused]] List {
public:
	[[maybe_unused]] DataT data_;
	[[maybe_unused]] KeyT key_;
	List* next;

	//Constructor 
	[[maybe_unused]] explicit List(KeyT, DataT);

	//Append 
	[[maybe_unused]] static void Append(List**, KeyT, DataT);

	//Get Data
	[[maybe_unused]] static DataT& GetData(List**);

	//Get Key
	[[maybe_unused]] static KeyT& GetKey(List**);

	//Size
	[[maybe_unused]] static size_t Size(List*);

	//Delete
	[[maybe_unused]] static void Delete(List**, KeyT);

	//Destructor
	[[maybe_unused]] static void Destruct(List**);

	//operator overloading = 
	[[maybe_unused]] List& operator=(const DataT&);

	//operator overloading << 
	friend std::ostream& operator<<(std::ostream& cout, List& obj) {
		std::cout << obj.data_;
		return cout;
	}

	//Destructor default 
	~List() = default;
};

#define ok1 template <class KeyT, class DataT> [[maybe_unused]]

//Constructor
ok1 inline List<KeyT, DataT>::List(KeyT key, DataT data) : key_(key), data_(data), next(nullptr) {}

//Append
ok1 void List<KeyT, DataT>::Append(List** head, KeyT key, DataT data) {
	List* newList = new List(key, data);
	if (*head == nullptr) {
		*head = newList;
		return;
	}
	List* tempList = *head;
	while (tempList->next != nullptr) {
		tempList = tempList->next;
	}
	tempList->next = newList;
}

//Get Data
ok1 DataT& List<KeyT, DataT>::GetData(List** obj) {
	if (*obj == nullptr || (*obj)->data_ == NULL) {
		throw Exception("Invalid access");
	}
	else {
		return (*obj)->data_;
	}
}

//Get Key
ok1 KeyT& List<KeyT, DataT>::GetKey(List** obj) {
	if (obj == nullptr || (*obj)->data_ == NULL) {
		throw Exception("Invalid access");
	}
	else {
		return (*obj)->key_;
	}
}

//Size
ok1 size_t List<KeyT, DataT>::Size(List* head) {
	size_t res(0);
	List* temp_node = head;
	while (temp_node != nullptr) {
		res++;
		temp_node = temp_node->next;
	}
	return res;
}

//Delete
ok1 void List<KeyT, DataT>::Delete(List** head, KeyT key) {
	if (*head == nullptr) {
		throw Exception("There is no data, connected with the given key");
	}
	if ((*head)->next == nullptr && (*head)->key_ == key) {
		(*head)->data_ = NULL;
		return;
	}
	List* temp = *head;
	List* prev = nullptr;
	if (temp->key_ == key) {
		while (temp->next != nullptr) {
			temp->data_ = (temp->next)->data_;
			temp->key_ = (temp->next)->key_;
			temp = temp->next;
		}
		temp = nullptr;
		return;
	}
	while (temp != nullptr && temp->key_ != key) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == nullptr) {
		return;
	}
	prev->next = temp->next;
	delete temp;
}

//Destructor
ok1 void List<KeyT, DataT>::Destruct(List** head) {
	List* temp_node = *head;
	List* next_node;
	while (temp_node != nullptr) {
		next_node = temp_node->next;
		delete temp_node;
		temp_node = next_node;
	}
	*head = nullptr;
}

//operator overloading =
ok1 List<KeyT, DataT>& List<KeyT, DataT>::operator=(const DataT& data) {
	data_ = data;
	return *this;
}

#endif //LR3_4_LIST_H
