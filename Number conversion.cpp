#include "NumberConversionCpp.hpp"
#include <bits/stdc++.h>
std::string toBin(uint32_t decimalNumber)
{
	std::string convertedNumber;
	if(decimalNumber == 0) return "0";
	while (decimalNumber)
	{
		convertedNumber = convertedNumber + std::to_string(decimalNumber % 2);
		decimalNumber /= 2;
	}
	
	reverse(convertedNumber.begin(), convertedNumber.end());
	return convertedNumber;
}

std::string toHex(uint32_t decimalNumber)
{
	std::string convertedNumber;	
	if(decimalNumber == 0) return "0";
	while (decimalNumber)
	{
		
		switch (decimalNumber % 16)
		{
		case 10:
			convertedNumber += "A";
			break;
		case 11:
			convertedNumber += "B";
			break;
		case 12:
			convertedNumber += "C";
			break;
		case 13:
			convertedNumber += "D";
			break;
		case 14:
			convertedNumber += "E";
			break;
		case 15:
			convertedNumber += "F";
			break;
	
		default:
			convertedNumber = convertedNumber + std::to_string(decimalNumber % 16);
			break;
		} 
		decimalNumber /= 16;
	}
	
	reverse(convertedNumber.begin(), convertedNumber.end());
	return convertedNumber;
	
}

std::string toBase(uint32_t decimalNumber, uint32_t base)
{

	std::string convertedNumber;	
	if(decimalNumber == 0) return "0";
	while (decimalNumber)
	{
	
		if ((decimalNumber % base ) > 9) convertedNumber += static_cast<char> (decimalNumber % base + 55); 
		else convertedNumber = convertedNumber + std::to_string(decimalNumber % base);
		
		decimalNumber /= base;
	}
	
	reverse(convertedNumber.begin(), convertedNumber.end());
	return convertedNumber;
	
	
}
