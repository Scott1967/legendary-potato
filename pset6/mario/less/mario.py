from cs50 import get_int

while True:
    # get size of pyramid from the user
    n = get_int("Number please between 0 - 23: ")
    if n >= 0 and n <= 23:
        break

for i in range(n):
# c outerLoop start

    for j in range(n + 1):
        # c innerLoop

        if i + j < n - 1:
            # algorithm for pyramid shape
            print(" ", end="")
        else:
            print("#", end="")

# c outerLoop end
    print()
