from cs50 import get_float

change = -1
while (change < 0):
    change = get_float("Change: ")

coins = 0
while (change > 0):
    if(change >= .25):
        change = change - .25
    elif (change >= .10):
        change = change - .10
    elif (change >= .05):
        change = change - .05
    else:
        change = change - .01
    coins = coins + 1
print (coins)
