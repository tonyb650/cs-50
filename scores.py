from cs50 import get_int

scores = []

for i in range(3):
    score = get_int("Score: ")
    scores = scores + [score]
    # scores.append(score)

print(scores)
average = sum(scores) / len(scores)
print(f"average= {average}")
