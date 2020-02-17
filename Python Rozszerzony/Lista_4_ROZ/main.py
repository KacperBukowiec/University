import itertools
import timeit
from time import sleep, time


def isPrime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return  True

def pierwsza_05(n):
    out = []
    for i in range(2, n):
        is_prime = True
        for l in out:
            if not i % l:
                is_prime = False
        if is_prime:
            out.append(i)
    return out


#print(pierwsza_05(20))


def pierwsza(n):
    return [x for x in range(2, n) if all(x % d != 0 for d in range(2, x))]


#print(pierwsza(20))


def pierwsza_2(n):
    return list(filter(lambda x: all(x % d != 0 for d in range(2, x)), list(range(2, n))))


#print(pierwsza_2(20))


# [d for d ]
# (x % d == 0 for d in range(1, x)

def doskonala_05(n):
    out=[]
    for i in range(2,n):
        sum=0
        for d in range(1,i):
            if not i%d:
                sum+= d
        if sum == i:
            out.append(i)
    return out

def doskonala(n):
    return [x for x in range(3, n) if sum([d for d in range(1, x // 2 + 1) if x % d == 0]) == x]

def doskonala_2(n):
    return list(filter(lambda x: sum([d for d in range(1, x // 2 + 1) if x % d == 0]) == x, list(range(2, n))))




def primes_iterator(n):

    i = itertools.count(2)
    while(True):
        p = next(i)
        #if p >= n:

        if isPrime(p):
            yield p

def times(n):
    start = time()
    pierwsza_05(n)
    end = time()
    print("imperatywna")
    print(end - start)

    start = time()
    pierwsza(n)
    end = time()
    print("składana")
    print(end - start)

    start = time()
    pierwsza_2(n)
    end = time()
    print("funkcyjna")
    print(end - start)

    iterat = primes_iterator(n)
    help = len(pierwsza_05(n))
    start = time()
    for _ in range(help):
        next(iterat)
    end = time()
    print("iteracyjna")
    print(end - start)

print("#######")
times(10)
print("#######")
times(100)
print("#######")
times(10000)

