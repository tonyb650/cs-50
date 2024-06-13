from cs50 import get_int

height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")
for level in range(height):
    print(" "*(height-level) + "#"*(level+1) + "  " + "#"*(level+1))
# print (f"Hello, {answer}")
