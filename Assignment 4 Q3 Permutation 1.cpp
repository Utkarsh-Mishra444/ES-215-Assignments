#include <iostream>
#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
// ijk order
int main()
{   int Nvals[3];
    Nvals[0] = 128;
    Nvals[1] = 256;
    Nvals[2] = 512;
    for (int X = 0; X < 3; X++)
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
    for(int i = 0 ; i <N ; i++){ // output matrix index
        for(int j = 0 ; j <N ; j++){    //input matrix indices.
            for (int k = 0; k < N; k++){
                sum += (Matrix[i][k]*Matrix[k][j]);
                //printf("%d \n" , sum);
        }
        //printf("%d \n" , sum);
        Product[i][j] = sum;
        // printf("%d x \n" , Product[i][j]);
        // printf("%d y \n" , i);
        sum = 0;
        
    }
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1= duration_cast<microseconds>(stop1 - start1).count();
    printf("Duration of meat portion in microseconds for N = %d is %d \n" , Nvals[X],duration1);

}
return 0;
}
