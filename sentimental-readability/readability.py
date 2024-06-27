from cs50 import get_string

text = get_string("Text: ")
letters = 0
words = 0
sentences = 0
for char in text:
    if(char == " "):
        words = words +1
    if(char == "." or char == "!" or char == "?"):
        sentences = sentences +1
    if()

grade = 0

print(f"Grade, {grade}")
