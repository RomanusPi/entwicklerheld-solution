#include "Fizzbuzz.hpp"

string Fizzbuzz::fizzbuzz(int number){
    if (number % 3 == 0  ) 
    {
      if (number % 5 == 0  ) 
        {
            return "fizzbuzz";
        }
        else return "fizz";
     
    }
    else  if (number % 5 == 0  ) 
            {
                return "buzz";
            }
    return std::to_string(number);
}
