import cv2

path = "/Users/mac/Documents/codes/python3.8/test1/image/mandrill.png"
img = cv2.imread(path, 1)


startPos = (0,20)
finishPos = (200,200)
color = (0,0,255)
thick = int(5)
#cv2.line(img,(0,0), (200,200), (0,0,255),5)

# draw line and arrow
cv2.line(img, startPos,finishPos,color,thick) #직선의 시작점과 끝점, 색상, 두께를 지정함
cv2.arrowedLine(img, (0,200),(200,20),(0,0,255),5) #화살표의 시작점, 끝점, 색상, 두께 지정

#draw rectangle 
cv2.rectangle(img,(0,200),(200,20),(0,0,0),5) # 사각형의 좌표, 색상을 지정

#draw text
cv2.putText(img,"Hello!!!",(30,240), fontFace = 2, fontScale = 1, color = (0,0,0))
cv2.putText(img,"20203103 LimJeongMin",(30,20), fontFace = 2, fontScale = 1, color = (0,0,0))

#show and wait for any key to close
cv2.imshow('lined',img)
cv2.waitKey(0)
cv2.destroyAllWindows()