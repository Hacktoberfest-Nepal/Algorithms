import math


def sieve_of_eratosthenes(user_num):

    gen_num = []
    for index in range(2, user_num + 1):
        gen_num.append(index)

    i = 2
    while (i <= int(math.sqrt(user_num))):
        if i in gen_num:
            for j in range(i*2, user_num+1, i):
                if j in gen_num:
                    gen_num.remove(j)
        i = i+1

    return gen_num


if __name__ == '__main__':
    user_input = int(
        input("Enter the number to print all prime numbers less than that:\t"))

    prime_numbers = sieve_of_eratosthenes(user_input)

    print(prime_numbers)
