import random

def get_rand_prime(start, end):
    primes = []
    for num in range(start, end+1):
        for i in range(2, num):
            if(num%i == 0):
                primes.append(num)
    rand_prime = random.choice(primes)
    return rand_prime

def get_private_key(root, secret, prime):
    return pow(root, secret) % prime

def get_secret(key, secret, prime):
    return pow(key, secret) % prime

SHARED_PRIME = 23
SHARED_ROOT = 5

alice_secret = get_rand_prime(1,100)
bob_secret = get_rand_prime(100,200)

alice_key = get_private_key(SHARED_ROOT, SHARED_PRIME, alice_secret)
bob_key = get_private_key(SHARED_ROOT, SHARED_PRIME, bob_secret)

alice_shared_secret = get_secret(bob_key, SHARED_PRIME, alice_secret)
bob_shared_secret = get_secret(alice_key, SHARED_PRIME, bob_secret)

if alice_shared_secret == bob_shared_secret:
    print("Shared secret : ", alice_shared_secret)
else:
    print("Oops Went Wrong")