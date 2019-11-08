import random
import math

def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('Error: Modular inverse does not exist')
    else:
        return x % m

def generate_keypair(p, q):
    n = p * q
    phi = (p-1) * (q-1)
    e = random.randrange(1, phi)
    g = math.gcd(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g = math.gcd(e, phi)
    d = modinv(e, phi)
    return ((e, n), (d, n))

def encrypt(public_key, plain_text):
    key, n = public_key
    cipher_text = [(ord(char) ** key) % n for char in plain_text]
    return cipher_text

def decrypt(private_key, cipher_text):
    key, n = private_key
    plain_text = [chr((char ** key) % n) for char in cipher_text]
    return ''.join(plain_text)
    
p = int(input("Enter a Prime Number: "))
q = int(input("Enter another Prime Number: "))
public, private = generate_keypair(p, q)
print ("Public key : ", public)
print ("Private key : ", private)
plain_text = input("Enter plain text : ")
cipher_text = encrypt(public, plain_text)
cipher_text_decrypt= decrypt(private, cipher_text)
print ("Cipher Text : ", cipher_text)
print ("Decrypted Cipher Text : ", cipher_text_decrypt)
