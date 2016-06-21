from math import sqrt

physics_score = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history_score = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]

n = len(physics_score)
x_mean = sum(physics_score) / n
y_mean = sum(history_score) / n
xy = sum([x * y for (x, y) in zip(physics_score, history_score)])
x_square = sum([x ** 2 for x in physics_score])

num = (xy - n * x_mean * y_mean)
denom = x_square - n * x_mean ** 2
beta = num / denom

print(beta)
