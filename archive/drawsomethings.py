import turtle
t = turtle.Turtle()

def draw6circle():
    for count in range(6):
     t.circle(100)
     t.left(360/6)

def drawTriangle():
   for i in range(3):
      t.forward(100)
      t.left(360/3)

def drawSqaure():
   for i in range(4):
      t.forward(100)
      t.left(360/4)

t.penup()
t.goto(-200,0)
t.pendown()
draw6circle()

t.penup()
t.goto(0,0)
t.pendown()

drawTriangle()

t.penup()
t.goto(200,0)
t.pendown()

drawSqaure()

turtle.done()

