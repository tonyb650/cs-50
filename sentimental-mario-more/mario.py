height = 0
while height < 1 or height > 8:
    height = int(input("Height: "))
for level in range(height):
    print(" "*(height-level) + "#"*level)
# print (f"Hello, {answer}")
