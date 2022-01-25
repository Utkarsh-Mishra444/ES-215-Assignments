#include <iostream>
#include<bits/stdc++.h>
using namespace std::chrono;
__int128 max64 = 18446744073709551615;
__int128 max64T =10000000000000000000;
__int128 stor[105];
__int128 stor1[105];

__int128 fibhelp(int n, __int128 t1, __int128 t2){
    if(n == 1)
    return t1;
    if(n == 2)
    return t2;
    else
    return fibhelp(n-1 , t2, t1 + t2);
}
__int128 fib(int n){
    return fibhelp(n,0,1);
}
__int128 fibmemoize(int n){
    __int128 x = 0;
    if(n == 0)
    return 0;
    if(n == 1)
    return 1;
    else if(stor[n] != 0)
    return stor[n];
    x = fibmemoize(n-1) + fibmemoize(n-2) ;
    stor[n] = x;
    return x;
}
int bigprint( __int128 num){ // defining a function to print 128 bit numbers
    if(num > max64){
        __int128 front = num / 10000000000000000000ull;
        __int128 back = num % 10000000000000000000ull;
        //printf("%llu \n" , num);
        printf("%llu" , front);
        printf("%llu \n" , back);   
    }
    
}
void bigprint( __int128* num){ // defining a function to print 128 bit numbers
    if(*num > max64){
        __int128 front = *num / 10000000000000000000ull;
        __int128 back = *num % 10000000000000000000ull;
        //printf("%llu \n" , num);
        printf("%llu" , front);
        printf("%llu \n" , back); 
        return;
    }
    
}
int main() {
    // Using Recursion
    printf("Using Recursion \n");
    auto start1 = high_resolution_clock::now();
    for(int i = 1 ; i<= 101 ; i++){
    __int128 k = fib(i); // Using Recursion
    if(k > max64)
    bigprint(k);
    else
    printf("%llu\n" , k);
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1= duration_cast<microseconds>(stop1 - start1).count();
    printf("Duration in microseconds is %d \n" , duration1);
    printf("Using loops \n");
    auto start2 = high_resolution_clock::now();
    __int128 a = 0;
    __int128 b = 1;
    __int128 c;
    printf("%llu\n" , a);
    printf("%llu\n" , b);
    for(int i = 1 ; i<= 99; i++){
    c = a + b;
    if(c > max64)
    bigprint(c);
    else
    printf("%llu\n" , c);
    a = b;
    b = c;
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2= duration_cast<microseconds>(stop2 - start2).count();
    printf("Duration in microseconds is %d \n" , duration2);
    printf("Using Recursion and memoization \n");
    auto start3 = high_resolution_clock::now();
    for(int i = 0 ; i<= 100 ; i++){
    __int128 k = fibmemoize(i); // Using Recursion
    //printf("%llu X \n" , stor[i]);
    if(k > max64)
    bigprint(k);
    else
    printf("%llu\n" , k);
    }
    auto stop3 = high_resolution_clock::now();
    auto duration3= duration_cast<microseconds>(stop3 - start3).count();
    printf("Duration in microseconds is %d \n" , duration3);
    printf("using loop with memoization \n");
    auto start4 = high_resolution_clock::now();
    stor1[0] = 0;
    stor1[1] = 1;
    printf("%llu \n" , stor1[0]);
    for(int i = 1 ; i<= 100; i++){
        if(stor1[i] == 0){
            stor1[i] = stor1[i-1] + stor1[i-2];
            if(stor1[i] > max64)
            bigprint(stor1[i]);
            else
            printf("%llu \n" , stor1[i]);
        }
        else{
        if(stor1[i] > max64)
        bigprint(stor1[i]);
        else
        printf("%llu \n" , stor1[i]);
        }
    }
    auto stop4 = high_resolution_clock::now();
    auto duration4= duration_cast<microseconds>(stop4 - start4).count();
    printf("Duration in microseconds is %d \n" , duration4);
    //std::cout<<"Hello";
    return 0;
}