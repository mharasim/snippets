#include <cstdint>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

template<class Value> void PrintBits(Value value) 
{
	std::string result("");
	size_t bytes = sizeof(value);
	uint8_t* pblock8 = reinterpret_cast<uint8_t*>(&value);
	for (size_t byte = 0; byte < bytes; ++byte) {
		std::string byte_str("");
		for (int bit = 7; bit >= 0; --bit) {
			size_t bit_value = (*pblock8 >> bit) & 1;
			if (bit_value == 1) 
				byte_str = byte_str + std::string("1");
			else
				byte_str = byte_str + std::string("0");
		}
		pblock8 = pblock8 + 1;
		result = byte_str + result;
	}
	std::cout << result;
}

template<class Value> Value LittleToBig(Value value) 
{
	size_t bytesize = sizeof(value);
	Value output = 0;
	uint8_t* pblock8 = reinterpret_cast<uint8_t*>(&value);
	uint8_t* outblk8 = reinterpret_cast<uint8_t*>(&output);
	for (size_t byte = 0; byte < bytesize; ++byte) {
		*(outblk8 + bytesize - 1 - byte) = *(pblock8 + byte);
	}
	return output;
}

void PrintBitsStr(const std::string& value) 
{
	try {
		if (value.find('.') != std::string::npos)
			PrintBits<double>(std::stod(value));
		else
			PrintBits<int>(std::stoi(value));
	} catch (...) {
		std::cout << "ERROR";
	}
}

bool IsSet(size_t bit, int32_t number)
{
	int32_t setmask = 1 << bit;
	if ((number & setmask) == setmask) 
		return true;
	return false;
}

void Set(size_t bit, int32_t& number)
{
	int32_t setmask = 1 << bit;
	number = number | setmask;
}

void Unset(size_t bit, int32_t& number)
{
	int32_t setmask = 1 << bit;
	number = number & ~setmask;
}

int32_t PrevEqualCnt(int32_t number)
{
	if (number == 0) 
		return 0;
	if (number == ~0)
		return number;
	
	size_t bit = 0;
	while (IsSet(bit, number)) 
		bit = bit + 1;
	while (!IsSet(bit, number))
		bit = bit + 1;
	Unset(bit, number);
	Set(bit - 1, number);

	return number;
}

int32_t NextEqualCnt(int32_t number)
{
	if (number == 0) 
		return 0;
	if (number == ~0)
		return number;
	
	size_t bit = 0;
	while (!IsSet(bit, number)) 
		bit = bit + 1;
	while (IsSet(bit, number))
		bit = bit + 1;
	Set(bit, number);
	Unset(bit - 1, number);

	return number;
}

int Reverse(int size)
{
	size_t rsize = 0;
	while (size != 0) {
		rsize = rsize << 1;
		rsize = rsize | (size & 1);
		size = size >> 1;
	}
	return rsize;
}

/*
void PrintBitsStr2(const std::string& value)
{
	int int_part = std::stoi(value.substr(0, value.find('.')));
	double dec_part = std::stod(value.substr(value.find('.'), std::string::npos));

	std::string int_str("");
	while (int_part > 0) {
		int bit_val = int_part % 2;
		int_part = int_part >> 1;
		int_str = std::to_string(bit_val) + int_str;
	}
	
	dec_part = dec_part * std::pow(10,32);
	int rest = std::ceil(dec_part % 1);
	if (rest > 0) std::cout << "ERROR"; return;

	
	std::string dec_str("");
	while (dec_part > 0) {
		int bit_val = dec_part % 2;
		dec_part = dec_part >> 1;
		dec_str = std::to_string(bit_val) + dec_str;
	}

	std::ostringstream str_buff;
	while (dec_part > 0) {
		if (dec_part == 1) {
			str_buff << dec_part;
			break;
		}

		double bit_value = dec_part << 1; // << 1 => 0.101 -> 1.01
		if (bit_value >= 1)	{ // 1.01
			str_buff << "1";
			dec_part = bit_value - 1;
		} else {	//0.101
			str_buff << "0";
			dec_part = bit_value;
		}
	}
	std::cout << int_str << "." << dec_str;
}
*/

void Copy(int32_t from, size_t i, size_t j, int32_t& to)
{
	for (size_t n = 0; n < 32; ++n) {
		if ((n >= i) && (n <=j)) {
			int32_t setmask = 1 << n;
			if ((setmask & from) == setmask) { // nth bit in from is 1
				to = to | setmask; // set nth bit in to
			} else { // nth bit in from is 0
				int32_t unsetmask = ~setmask;
				to = to & unsetmask; // unset nth bit in to
			}
		}
	}
}

int main(int argc, char** argv) 
{
	int8_t int8 = 1;
	int16_t int16 = 2;
	int32_t int32 = 10;
	double dbl = 27.24;

	PrintBits<int8_t>(int8); std::cout << std::endl;
	PrintBits<int16_t>(int16); std::cout << std::endl;
	PrintBits<int32_t>(int32); std::cout << std::endl;
	PrintBits<double>(dbl); std::cout << std::endl;

	std::cout << "Ex 2: " << std::endl;
	PrintBitsStr("3.75"); std::cout << std::endl;
	PrintBitsStr("10"); std::cout << std::endl;
	PrintBitsStr("xniosdkj"); std::cout << std::endl;

	int32_t from = 14563;
	int32_t to = 45652;
	PrintBits<int32_t>(from); std::cout << std::endl;
	PrintBits<int32_t>(to); std::cout << std::endl;
	Copy(from, 3, 9, to);
	PrintBits<int32_t>(to); std::cout << std::endl;

	PrintBits<int32_t>(from); std::cout << std::endl;
	PrintBits<int32_t>(NextEqualCnt(from)); std::cout << std::endl;
	PrintBits<int32_t>(PrevEqualCnt(from)); std::cout << std::endl;

	int t = 26;
	std::cout << "Reverse: " << std::endl;
	PrintBits<int>(t); std::cout << std::endl;
	PrintBits<int>(Reverse(t)); std::cout << std::endl;
}
