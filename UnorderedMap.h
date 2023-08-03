#pragma once
#ifndef LR3_4_UNORDEREDMAP_H
#define LR3_4_UNORDEREDMAP_H

#include <iostream>
#include <stdio.h>
#include <iterator>
#include <cstddef>

#include "List.h"
#include "Hash.h"

template<class KeyType, class DataType, class Hash = HashFC<KeyType>>
class [[maybe_unused]] UnorderedMap {
private:
	double loadFactor_;
	double maxLoadFactor_ = 0.75;
	size_t buckets_amount_;
	size_t elements_amount_{};
	List<KeyType, DataType>** table_;

	//rehashing 
	[[maybe_unused]] void Rehashing();

public:
	//Iterator
	template<class IterDataType, class IterKeyType>
	class [[maybe_unused]] UnorderedMapIterator {
	protected:
		List<KeyType, DataType>** m_ptr;
	public:
		using UnorderedMapIterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = List<KeyType, DataType>;
		using pointer = List<KeyType, DataType>*;
		using reference = List<KeyType, DataType>&;

		//constructor default
		[[maybe_unused]] explicit UnorderedMapIterator() = default;

		//constructor pointer
		[[maybe_unused]] UnorderedMapIterator(List<KeyType, DataType>** ptr) : m_ptr(ptr) {}

		//constructor reference
		[[maybe_unused]] UnorderedMapIterator(List<KeyType, DataType>& ptr_ref) { m_ptr = ptr_ref; }

		//constructor copy
		[[maybe_unused]] UnorderedMapIterator(const UnorderedMapIterator<DataType, KeyType>& obj) { m_ptr = obj.m_ptr; }

		//operator overloading *
		[[maybe_unused]] DataType& operator*()const { return List<KeyType, DataType>::GetData(m_ptr); }

		//operator overloading ->
		[[maybe_unused]] List<KeyType, DataType>* operator->() { return m_ptr; }

		//operator overloading ++ prefix
		[[maybe_unused]] UnorderedMapIterator& operator++() { m_ptr++; return *this; }

		//operator overloading ++ postfix
		[[maybe_unused]] UnorderedMapIterator operator++(int) { UnorderedMapIterator temp = *this; ++(*this); return temp; }

		//operator overloading -- prefix
		[[maybe_unused]] UnorderedMapIterator& operator--() { m_ptr--; return *this; }

		//operator overloading -- postfix
		[[maybe_unused]] UnorderedMapIterator operator--(int) { UnorderedMapIterator temp = *this; --(*this); return temp; }

		//operator overloading ==
		[[maybe_unused]] bool operator==(const UnorderedMapIterator& obj) { return *this == obj; }

		//operator overloading !=
		[[maybe_unused]] bool operator!=(const UnorderedMapIterator& obj) { return m_ptr != obj.m_ptr; }

		//operator bool()
		[[maybe_unused]] operator bool()const {
			if (m_ptr) return true;
			return false;
		}

		//operator overloading = iterator
		[[maybe_unused]] UnorderedMapIterator& operator=(const UnorderedMapIterator& obj) { m_ptr = obj.m_ptr; return *this; }

		//operator overloading = pointer
		[[maybe_unused]] UnorderedMapIterator& operator=(pointer ptr) { m_ptr = ptr; return *this; }

		//operator overloading += 
		[[maybe_unused]] UnorderedMapIterator& operator+=(const std::ptrdiff_t& movement) { m_ptr += movement; return *this; }

		//operator overloading -= 
		[[maybe_unused]] UnorderedMapIterator& operator-=(const std::ptrdiff_t& movement) { m_ptr -= movement; return *this; }

		//first
		[[maybe_unused]] DataType& first() { return List<KeyType, DataType>::GetData(m_ptr); }

		//second
		[[maybe_unused]] KeyType& second() { return List<KeyType, DataType>::GetKey(m_ptr); }

		[[maybe_unused]] static size_t interval(UnorderedMapIterator obj1, UnorderedMapIterator obj2) {
			size_t count = 0;
			for (auto iter = obj1; iter != obj2; ++iter) count++;
			return count;
		}

		//destructor 
		~UnorderedMapIterator() { m_ptr = nullptr; }
	};

	using iterator = UnorderedMap<KeyType, DataType, Hash>::UnorderedMapIterator<DataType, KeyType>;

	//constructor default 
	[[maybe_unused]] explicit UnorderedMap();

	//constructor segments (buckets) 
	[[maybe_unused]] explicit UnorderedMap(size_t);

	//constructor interval
	[[maybe_unused]] explicit UnorderedMap(iterator obj1, iterator obj2);

	//constructor std::initializer_list 
	[[maybe_unused]] UnorderedMap(std::initializer_list<std::pair<KeyType, DataType>>);

	//constructor copy 
	[[maybe_unused]] UnorderedMap(const UnorderedMap<KeyType, DataType, Hash>&);

	//constructor move 
	[[maybe_unused]] UnorderedMap(UnorderedMap<KeyType, DataType, Hash>&&) noexcept;

	//destructor custom 
	~UnorderedMap();

	//operator overloading = copy 
	[[maybe_unused]] UnorderedMap& operator=(const UnorderedMap<KeyType, DataType, Hash>&);

	//operator overloading = move 
	[[maybe_unused]] UnorderedMap& operator=(UnorderedMap<KeyType, DataType, Hash>&&) noexcept;

	//operator overloading [] 
	[[maybe_unused]] List<KeyType, DataType>& operator[](KeyType key) {
		Hash obj;
		List<KeyType, DataType>* currHead = table_[obj(key) % buckets_amount_];
		List<KeyType, DataType>* Head = table_[obj(key) % buckets_amount_];
		while (currHead != nullptr && currHead->key_ != key) {
			currHead = currHead->next;
		}
		if (currHead == nullptr) {
			elements_amount_++;
			while (LoadFactor() > MaxLoadFactor()) {
				Rehashing();
			}
			List<KeyType, DataType>::Append(&Head, key, NULL);
			if (table_[obj(key) % buckets_amount_] == nullptr) table_[obj(key) % buckets_amount_] = Head;
			currHead = Head;
			while (currHead != nullptr && currHead->key_ != key) {
				currHead = currHead->next;
			}
			return *currHead;
		}
		return *currHead;
	}

	//getMaxLoadFactor 
	[[maybe_unused]] double MaxLoadFactor();

	//getLoadFactor 
	[[maybe_unused]] double LoadFactor();

	//change MaxLoadFactor 
	[[maybe_unused]] void MaxLoadFactor(double);

	//at 
	[[maybe_unused]] DataType at(KeyType);

	//insert 
	[[maybe_unused]] void Insert(std::pair<KeyType, DataType>);

	//insert move
	[[maybe_unused]] void Insert_move(std::pair<KeyType, DataType>&&) noexcept;

	//erase by key 
	[[maybe_unused]] void Erase(KeyType);

	//erase by Iterator
	[[maybe_unused]] void Erase(iterator);

	//reserve 
	[[maybe_unused]] void Reserve(size_t);

	//empty 
	[[maybe_unused]] bool Empty();

	//size elements_amount 
	[[maybe_unused]] size_t Size();

	//depth buckets_amount 
	[[maybe_unused]] size_t Depth();

	//clear 
	[[maybe_unused]] void Clear();

	//begin
	[[maybe_unused]] UnorderedMapIterator<DataType, KeyType> begin() { return iterator(&table_[0]); }

	//end
	[[maybe_unused]] UnorderedMapIterator<DataType, KeyType> end() { return iterator(&table_[buckets_amount_ - 1]); }
};

#define ok2 template <class KeyType, class DataType, class Hash> [[maybe_unused]]

//constructor default
template <class KeyType, class DataType, class Hash>
[[maybe_unused]] UnorderedMap<KeyType, DataType, Hash>::UnorderedMap() : buckets_amount_(8), loadFactor_(0.), elements_amount_(0) {
	table_ = new List<KeyType, DataType> *[buckets_amount_];
	for (size_t i(0); i < buckets_amount_; ++i) {
		table_[i] = nullptr;
	}
}

//constructor segments
template <class KeyType, class DataType, class Hash>
[[maybe_unused]] UnorderedMap<KeyType, DataType, Hash>::UnorderedMap(size_t buckets) : buckets_amount_(buckets), loadFactor_(0.),
elements_amount_(0) {
	table_ = new List<KeyType, DataType> *[buckets_amount_];
	for (size_t i(0); i < buckets_amount_; ++i) {
		table_[i] = nullptr;
	}
}

//constructor interval
template <class KeyType, class DataType, class Hash>
[[maybe_unused]] UnorderedMap<KeyType, DataType, Hash>::UnorderedMap(iterator obj1, iterator obj2) : buckets_amount_(iterator::interval(obj1, obj2)), loadFactor_(0.),
elements_amount_(0) {
	table_ = new List<KeyType, DataType> *[buckets_amount_];
	for (size_t i(0); i < buckets_amount_; ++i) {
		table_[i] = nullptr;
	}
}

//constructor std::initializer_list
template <class KeyType, class DataType, class Hash>
[[maybe_unused]] UnorderedMap<KeyType, DataType, Hash>::UnorderedMap(std::initializer_list<std::pair<KeyType, DataType>> args) :
	buckets_amount_(args.size()), elements_amount_(0) {
	table_ = new List<KeyType, DataType> *[buckets_amount_];
	for (size_t i(0); i < buckets_amount_; ++i) {
		table_[i] = nullptr;
	}
	for (auto i : args) {
		Insert(std::make_pair(i.first, i.second));
	}
	loadFactor_ = LoadFactor();
}

//constructor copy
ok2 UnorderedMap<KeyType, DataType, Hash>::UnorderedMap(const UnorderedMap<KeyType, DataType, Hash>& source_obj) {
	loadFactor_ = source_obj.loadFactor_;
	buckets_amount_ = source_obj.buckets_amount_;
	elements_amount_ = source_obj.elements_amount_;
	delete[] table_;
	table_ = new List<KeyType, DataType> *[source_obj.buckets_amount_];
	for (size_t i(0); i < source_obj.buckets_amount_; ++i) {
		table_[i] = source_obj.table_[i];
	}
}

//constructor move
ok2 UnorderedMap<KeyType, DataType, Hash>::UnorderedMap(UnorderedMap<KeyType, DataType, Hash>&& source_obj) noexcept {
	loadFactor_ = std::move(source_obj.loadFactor_);
	buckets_amount_ = std::move(source_obj.buckets_amount_);
	elements_amount_ = std::move(source_obj.elements_amount_);
	delete[] table_;
	table_ = new List<KeyType, DataType> *[source_obj.buckets_amount_];
	for (size_t i(0); i < source_obj.buckets_amount_; ++i) {
		table_[i] = std::move(source_obj.table_[i]);
	}
	delete[]source_obj.table_;
	source_obj.table_ = nullptr;
}

//destructor 
template <class KeyType, class DataType, class Hash>
[[maybe_unused]] UnorderedMap<KeyType, DataType, Hash>::~UnorderedMap() {
	delete[] table_;
}

//operator overloading = copy
ok2 UnorderedMap<KeyType, DataType, Hash>&
UnorderedMap<KeyType, DataType, Hash>::operator=(const UnorderedMap<KeyType, DataType, Hash>& source_obj) {
	if (this == &source_obj) {
		return *this;
	}
	loadFactor_ = source_obj.loadFactor_;
	buckets_amount_ = source_obj.buckets_amount_;
	elements_amount_ = source_obj.elements_amount_;
	delete[] table_;
	table_ = new List<KeyType, DataType> *[source_obj.buckets_amount_];
	for (size_t i(0); i < source_obj.buckets_amount_; ++i) {
		table_[i] = source_obj.table_[i];
	}
	return *this;
}

//operator overloading = move
ok2 UnorderedMap<KeyType, DataType, Hash>&
UnorderedMap<KeyType, DataType, Hash>::operator=(UnorderedMap<KeyType, DataType, Hash>&& source_obj) noexcept {
	if (this == &source_obj) {
		return *this;
	}
	loadFactor_ = std::move(source_obj.loadFactor_);
	buckets_amount_ = std::move(source_obj.buckets_amount_);
	elements_amount_ = std::move(source_obj.elements_amount_);
	delete[] table_;
	table_ = new List<KeyType, DataType> *[source_obj.buckets_amount_];
	for (size_t i(0); i < source_obj.buckets_amount_; ++i) {
		table_[i] = source_obj.table_[i];
	}
	delete[]source_obj.table_;
	source_obj.table_ = nullptr;
	return *this;
}

//getLoadFactor
ok2 double UnorderedMap<KeyType, DataType, Hash>::LoadFactor() {
	return (static_cast<double> (elements_amount_) / static_cast<double>(buckets_amount_));
}

//rehashing
ok2 void UnorderedMap<KeyType, DataType, Hash>::Rehashing() {
	elements_amount_ = 1;
	size_t old_buckets_amount = buckets_amount_;
	buckets_amount_ = old_buckets_amount * 2;
	List<KeyType, DataType>** temp = table_;
	table_ = new List<KeyType, DataType> *[buckets_amount_];
	for (size_t i(0); i < buckets_amount_; ++i) {
		table_[i] = nullptr;
	}
	for (size_t i(0); i < old_buckets_amount; ++i) {
		List<KeyType, DataType>* currHead = temp[i];
		while (currHead != nullptr) {
			Insert(std::make_pair(currHead->key_, currHead->data_));
			currHead = currHead->next;
		}
	}
	loadFactor_ = LoadFactor();
	delete[] temp;
}

//insert
ok2 void UnorderedMap<KeyType, DataType, Hash>::Insert(std::pair<KeyType, DataType> par) {
	elements_amount_++;
	while (LoadFactor() > MaxLoadFactor()) {
		Rehashing();
	}
	Hash obj;
	size_t bucket_index = obj(par.first) % buckets_amount_;
	if (table_[bucket_index] == nullptr) {
		List<KeyType, DataType>* head(nullptr);
		List<KeyType, DataType>::Append(&head, par.first, par.second);
		table_[bucket_index] = head;
	}
	else {
		List<KeyType, DataType>::Append(&(table_[bucket_index]), par.first, par.second);
	}
	loadFactor_ = LoadFactor();
}

//insert move
ok2 void UnorderedMap<KeyType, DataType, Hash>::Insert_move(std::pair<KeyType, DataType>&& par) noexcept {
	KeyType p_f = std::move(par.first);
	DataType p_s = std::move(par.second);
	elements_amount_++;
	while (LoadFactor() > MaxLoadFactor()) {
		Rehashing();
	}
	Hash obj;
	size_t bucket_index = obj(p_f) % buckets_amount_;
	if (table_[bucket_index] == nullptr) {
		List<KeyType, DataType>* head(nullptr);
		List<KeyType, DataType>::Append(&head, p_f, p_s);
		table_[bucket_index] = head;
	}
	else {
		List<KeyType, DataType>::Append(&(table_[bucket_index]), p_f, p_s);
	}
	loadFactor_ = LoadFactor();
}

//getMaxLoadFactor 
ok2 double UnorderedMap<KeyType, DataType, Hash>::MaxLoadFactor() {
	return maxLoadFactor_;
}

//change MaxLoadFactor
ok2 void UnorderedMap<KeyType, DataType, Hash>::MaxLoadFactor(double val) {
	maxLoadFactor_ = val;
}

//at
ok2 DataType UnorderedMap<KeyType, DataType, Hash>::at(KeyType key) {
	Hash obj;
	List<KeyType, DataType>* currHead = table_[obj(key) % buckets_amount_];
	while (currHead->key_ != key && currHead != nullptr) {
		currHead = currHead->next;
	}
	if (currHead == nullptr) {
		throw Exception("There is no such key\n");
	}
	return currHead->data_;
}

//erase by key
ok2 void UnorderedMap<KeyType, DataType, Hash>::Erase(KeyType key) {
	Hash obj;
	List<KeyType, DataType>* currHead = table_[obj(key) % buckets_amount_];
	List<KeyType, DataType>::Delete(&currHead, key);
}

//erase by Iterator
ok2 void UnorderedMap<KeyType, DataType, Hash>::Erase(iterator iter) {
	Hash obj;
	List<KeyType, DataType>* currHead = table_[obj(iter.second()) % buckets_amount_];
	List<KeyType, DataType>::Delete(&currHead, iter.second());
}

//reserve
ok2 void UnorderedMap<KeyType, DataType, Hash>::Reserve(size_t num) {
	elements_amount_ = 0;
	size_t old_buckets_amount = buckets_amount_;
	buckets_amount_ = old_buckets_amount + num;
	List<KeyType, DataType>** temp = table_;
	table_ = new List<KeyType, DataType> *[buckets_amount_];
	for (size_t i(0); i < buckets_amount_; ++i) {
		table_[i] = nullptr;
	}
	for (size_t i(0); i < old_buckets_amount; ++i) {
		List<KeyType, DataType>* currHead = temp[i];
		while (currHead != nullptr) {
			Insert(std::make_pair(currHead->key_, currHead->data_));
			currHead = currHead->next;
		}
	}
	loadFactor_ = LoadFactor();
	delete[] temp;
}

//empty
ok2 bool UnorderedMap<KeyType, DataType, Hash>::Empty() {
	bool flag = true;
	for (size_t i(0); i < buckets_amount_; ++i) {
		if (table_[i] != nullptr) {
			flag = false;
		}
	}
	return flag;
}

//size elements_amount
ok2 size_t UnorderedMap<KeyType, DataType, Hash>::Size() {
	return elements_amount_;
}

//depth buckets_amount
ok2 size_t UnorderedMap<KeyType, DataType, Hash>::Depth() {
	return buckets_amount_;
}

//clear
ok2 void UnorderedMap<KeyType, DataType, Hash>::Clear() {
	for (size_t i(0); i < buckets_amount_; ++i) {
		if (table_[i] != nullptr) {
			List<KeyType, DataType>* currHead = table_[i];
			List<KeyType, DataType>::Destruct(&currHead);
			table_[i] = nullptr;
		}
	}
}

#endif //LR3_4_UNORDEREDMAP_H
