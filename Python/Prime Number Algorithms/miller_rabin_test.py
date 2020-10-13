# a is any number between 1 and n-1 

# n is the original number whose primal is to be tested

# m is the value obtained from n-1 = 2^k.m

n = input("Enter n : ")

m = input("Enter m : ")

a = input("Enter a : ")

k = input("Enter k : ")

x = (a**m)% n

if(x == 1 or x == (n-1)):
    print("Prime")
    exit()

for i in range(k - 1):
    x = x**2 % n
    if(x == 1):
        print("Composite")
        break
    if(x == (n-1)):
        print("Prime")
        break