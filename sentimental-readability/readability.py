from cs50 import get_string

text = get_string("Text: ")
letters = 0
words = 1
sentences = 0
for char in text:
    if(char == " "):
        words = words + 1
    if(char == "." or char == "!" or char == "?"):
        sentences = sentences + 1
    if((ord(char) >= 65 and ord(char) <=90) or (ord(char) >= 97 and ord(char) <=122)):
        letters = letters + 1

grade = round(0.0588 * (letters/words/100) - 0.296 * (sentences/words/100) - 15.8)

print(f"Grade, {grade}")
