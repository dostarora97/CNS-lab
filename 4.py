start = ord('a')

def encrypt(plain_text, shift_key) :
    cipher_text= ""
    key_len = len(shift_key)
    for i, pt_char in enumerate(plain_text) :
        pt_char_ascii = ord(pt_char)
        shift_char = shift_key[i%key_len]
        shift = ord(shift_char)
        cipher_text += chr(start+( ((pt_char_ascii-start) +shift) %26))
    return cipher_text

def decrypt(cipher_text, shift_key) :
    plain_text= ""
    key_len = len(shift_key)
    for i, ct_char in enumerate(cipher_text) :
        ct_char_ascii = ord(ct_char)
        shift_char = shift_key[i%key_len]
        shift = ord(shift_char)
        plain_text += chr(start+( ((ct_char_ascii-start) -shift) %26))
    return plain_text

plain_text = input("Enter plain text : ")
shift_key = input("Enter shift key : ")
cipher_text = encrypt(plain_text, shift_key)
print("Cipher Text : ", cipher_text)
decrypt_cipher_text = decrypt(cipher_text, shift_key)
print("Plain Text : ", decrypt_cipher_text)