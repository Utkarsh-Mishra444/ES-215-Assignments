import time
N = 256;
Matrix = [[598]*N]*N;
Product = [[0]*N]*N;
s = 0;
start = time.time();
for i in range(N):
    for j in range(N):
        for k in range(N):
            s += Matrix[i][k]*Matrix[k][j]
        Product[i][j] = s
        s = 0
end = time.time();
for d in Product:
    print(d, "\n")
    
print(f"meat portion of the program is {end - start}")