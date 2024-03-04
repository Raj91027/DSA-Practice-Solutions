def isPrime(num):
    i=2
    while i*i<=num:
        if(num%i==0):
            return False
        i+=1
    return True


n = int(input())
primes = []
for i in range(2, n):
    if isPrime(i):
        print(i, end=' ')
    


# num = int(input())
# print(isPrime(num))
    