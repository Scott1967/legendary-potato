import sys
import cs50

sys.argv

n = len(sys.argv)
if not n == 2:
    print("Usage: python caesar.py key")
    exit(1)

key = int(sys.argv[1])

plainText = cs50.get_string("plaintext: ")
print("ciphertext:", end=" ")
for c in plainText:
    if c.isalpha():
        if c.isupper():
            d = ((ord(c) - 65 + key) % 26 + 65)
            ctext = chr(d)
            print(ctext, end="")

        if c.islower():
            d = ((ord(c) - 97 + key) % 26 + 97)
            ctext = chr(d)
            print(ctext, end="")
    else:
        print(c, end="")
print()


