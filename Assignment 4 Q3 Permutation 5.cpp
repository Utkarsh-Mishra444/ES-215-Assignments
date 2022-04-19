
#include <iostream>
#include<bits/stdc++.h>
#include <math.h>
using namespace std::chrono;
using namespace std;
// kij order
int main()
{   
     //  this is to run the code 3 times and automatically get geometric mean
    int Nvals[3];
    Nvals[0] = 128;
    Nvals[1] = 256;
    Nvals[2] = 512;
    float duration2[3] = {0};
    for (int X = 0; X < 3; X++)
    {
        float duration3 = 0;
    for(int Y = 0; Y<3 ; Y++)  //  this is to run the code 3 times and automatically get geometric mean
    {
    int sum = 0;
    int N = Nvals[X];
    int Matrix[N][N];
    int Product[N][N];
    //filling the matrix with numbers
    for(int i = 0 ; i <N ; i++){
        for(int j = 0 ; j <N ; j++){
            Matrix[i][j] = 598; // arbitary number
            Product[i][j]= 0;
        }
    }
    auto start1 = high_resolution_clock::now();
    for (int k = 0; k < N; k++){ // output matrix index
        for(int i = 0 ; i <N ; i++){    //input matrix indices.
            for(int j = 0 ; j <N ; j++){
                sum += (Matrix[i][k]*Matrix[k][j]);
                //printf("%d \n" , sum);
        }
        //printf("%d \n" , sum);
        Product[k][i] = sum;
        // printf("%d x \n" , Product[i][j]);
        // printf("%d y \n" , i);
        sum = 0;
        
    }
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1= duration_cast<microseconds>(stop1 - start1).count();
    printf("Duration of meat portion in microseconds for N = %d and sample number %d is %ld \n" , Nvals[X],Y+1,duration1);
    duration2[Y] = duration1;
}
duration3 = cbrt((duration2[0]*duration2[1]*duration2[2]));
printf("Duration of meat portion in microseconds for N = %d and geometric mean of samples is %f \n" , Nvals[X],duration3);
}
return 0;
}
