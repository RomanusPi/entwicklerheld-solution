#include "ClimbingStairs.hpp"

int fib(int n){

    if (n < 2) return 1;
    return fib(n-1)+fib(n-2); 
} 
int ClimbingStairs::climbingStairs(int numberOfStairs){
   
    if (numberOfStairs <= 0)  return 0;
    
    return fib(numberOfStairs);

}
