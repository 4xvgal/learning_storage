import turtle
t = turtle.Turtle()
t.speed(0)
def n_polygon(n, lenght):
    for i in range(n):
        t.forward(lenght)
        t.left(360//n)

positions = int(-400)

for i in range(2,10+1):
    n_polygon(i, 35)
    t.penup()
    t.goto(positions,0)
    t.pendown()
    positions = positions + 100


turtle.exitonclick()