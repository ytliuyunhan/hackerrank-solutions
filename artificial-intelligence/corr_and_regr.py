from math import sqrt

physics_score = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history_score = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]

sum_x = sum(physics_score)
sum_y = sum(history_score)
sum_xy = sum([x * y for (x, y) in zip(physics_score, history_score)])
sum_x_square = sum([x ** 2 for x in physics_score])
sum_y_square = sum([x ** 2 for x in history_score])
n = len(physics_score)

num = (n * sum_xy - sum_x * sum_y)
denom = sqrt((n * sum_x_square - sum_x ** 2) * (n * sum_y_square - sum_y ** 2))
r = num / denom

print(r)
