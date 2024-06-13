height = 0
while height < 1 or height > 8:
    height = int(input("Height: "))
for level in range(height):
    print(" "*(height-level) + "#"*(level+1) + "  " + "#"*(level+1) + " "*(height-level))
# print (f"Hello, {answer}")
