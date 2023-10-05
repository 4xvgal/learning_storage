import turtle

t =turtle.Turtle()
t.speed(0)
t.penup()
t.goto(-200,100)
t.write(str("학번: 20203103\n이름 : 임정민"),font= ('consolas',16, 'bold'))
t.goto(0,0)
t.pendown()
def drawBar(height):
    t.begin_fill()
    if height < 100:
        t.fillcolor("blue")
    elif height <300:
        t.fillcolor("yellow")
    elif height >300:
        t.fillcolor("red")
    t.left(90)
    t.forward(height)
    t.write(str(height),font= ('consolas',16, 'bold'))
    t.right(90)
    t.forward(40)
    t.right(90)
    t.forward(height)
    t.left(90)
    t.end_fill()

data = [120,56,309,220,156,23,98]
t.color("black")
for d in data:
    drawBar(d)
turtle.exitonclick()