import turtle 

t= turtle.Turtle()
t.speed(0)
t.width(3)
n = int(1)
going = int(100)
while n> 0:
   n = int(input("각도를 입력하시오 :", ))
   if n < 0:
        break
   length = 10
   while length < 300:
         t.forward(length)
         t.right(n)
         length +=5
   t.penup()
   going = going + 200
   t.goto(going,0)
   t.pendown()
