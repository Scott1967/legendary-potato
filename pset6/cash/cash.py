from cs50 import get_float

while True:
    n = get_float("Change Due: ")
    if n > 0:
        break

dollars = round(n * 100)
quarters = 25
dimes = 10
nickels = 5
pennies = 1

coins = 0
qcount = 0
dcount = 0
ncount = 0
pcount = 0

while (dollars >= quarters):
    dollars = dollars - 25
    qcount += 1
    coins += 1

while (dollars >= dimes):
    dollars = dollars - 10
    dcount += 1
    coins += 1

while (dollars >= nickels):
    dollars = dollars - 5
    ncount += 1
    coins += 1

while (dollars >= pennies):
    dollars = dollars - 1
    pcount += 1
    coins += 1

print("Total coins used: ", end="")
print(coins)
print()
print("Type of coins used:")
print("Quarters: ", end="")
print(qcount)
print("Dimes: ", end="")
print(dcount)
print("Nickels: ", end="")
print(ncount)
print("Pennies: ", end="")
print(pcount)
print()