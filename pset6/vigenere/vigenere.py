import sys
import cs50

sys.argv

if len(sys.argv) < 2 or len(sys.argv) > 2:
    print("Usage: python vigenere.py argument")
    print("One word argument only")
    exit(1)

for c in sys.argv[1]:
    if c.isalpha():
        continue
    else:
        print("Usage: python vigenere.py key")
        print("Key must be letters only")
        exit(1)

while True:
    plainText = cs50.get_string("plaintext: ")
    if plainText:
        break

print("ciphertext:", end=' ')

length = len(sys.argv[1])
keyArg = sys.argv[1]
i = 0
for c in plainText:
    p = ord(c)
    key = keyArg[i]
    k = ord(key)
    if key.islower():
        k = k - 97
    if key.isupper():
        k = k - 65
    if c.isalpha():
        if c.islower():
            p = ((p + k - 97) % 26 + 97)
            c = chr(p)
            print(c, end='')
            i += 1
        if c.isupper():
            p = ((p + k - 65) % 26 + 65)
            c = chr(p)
            print(c, end='')
            i += 1
    if not c.isalpha():
        print(c, end='')
        i = i

    if i == length:
        i = 0
print()

