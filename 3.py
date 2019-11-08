start = 97
end = 122

def encrypt(plain_text, shift):
	cipher_text = ""
	for char in plain_text:
		pt_char_ascii = ord(char)
		cipher_text += chr(start+ ( ((pt_char_ascii-start) +shift) %26) )
			
	return cipher_text

plain_text = input("Enter plain text: ")
shift = int(input("Enter Shift amount :"))
cipher_text = encrypt(plain_text, shift)
print(cipher_text)