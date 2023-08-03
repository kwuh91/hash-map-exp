#pragma once
#ifndef LR3_4_HASH_H
#define LR3_4_HASH_H

#include <string>
#include <type_traits>
#include <cmath>
#include <cstddef>

#include "Exception.h"

//maybe struct
template<class KeyType>
class HashFC {
public:
	template<class KeyType>
	[[maybe_unused]] size_t operator()(KeyType key) const;

	//hash function for string 
	template<>
	[[maybe_unused]] size_t operator() < std::string > (std::string key) const {
		size_t res = 0;
		const int p = 53;
		for (size_t i = 0; i < key.length(); ++i) {
			res += static_cast<size_t>(key[i]) * static_cast<size_t>(pow(p, i));
		}
		return res;
	}

	//hash function for int 
	template<>
	[[maybe_unused]] size_t operator() < int > (int key) const {
		unsigned int x = static_cast<unsigned int>(key);
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = (x >> 16) ^ x;
		return x;
	}

	//hash function for uint32_t 
	template<>
	[[maybe_unused]] size_t operator() < uint32_t > (uint32_t key) const {
		unsigned int x = static_cast<unsigned int>(key);
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = (x >> 16) ^ x;
		return x;
	}

	//hash function for char 
	template<>
	[[maybe_unused]] size_t operator() < char > (char key) const {
		unsigned char x = static_cast<unsigned char>(key);
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = (x >> 16) ^ x;
		return x;
	}

	//hash function for bool? 
	template<>
	[[maybe_unused]] size_t operator() < bool > (bool key) const {
		return key;
	}
};

#endif //LR3_4_HASH_H
