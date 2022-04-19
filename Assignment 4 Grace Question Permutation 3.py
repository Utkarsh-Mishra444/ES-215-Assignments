import time
import math
list = [128,256,512]
for N in list:
    t = [0,0,0]
    for X in range(3): # 3 iterations then cube root
        Matrix = [[598]*N]*N;
        Product = [[0]*N]*N;
        s = 0;
        start = time.time();
        for j in range(N):
            for k in range(N):
                for i in range(N):
                    s += Matrix[i][k]*Matrix[k][j]
                Product[i][j] = s
                s = 0
        end = time.time();
        t[X] = end - start
        print(f"meat portion time of the program for N = {N} and sample number = {X+1} is {t[X]}")
    T = (t[0]*t[1]*t[2])**(1.0/3.0)
    print(f"meat portion time (geometric mean of 3 samples) of the program for N = {N} is {T}")
