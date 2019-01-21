import cs50

while True:
    # get size of pyramid from the user
    n = cs50.get_int("Number please between 0 - 23: ")
    if n >= 0 and n <= 23:
        break

for x in range(n):
    # outerLoop
    for s in range(n):
        # innerLoop
        if s + x < n - 1:
            # spaces
            print(" ", end="")
        else:
            # bricks
            print("#", end="")

    # separation
    print("  ", end="")

    # second half of pyramid
    for j in range(x + 1):
        if j <= x:
            print("#", end="")
    print()
