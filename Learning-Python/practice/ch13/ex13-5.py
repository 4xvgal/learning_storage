import cv2
#mac
path1 = "image/green_back.png"
path2 = "image/iceberg.png"
#windows
# path1 = "image\green_back.png"
# path2 = "image\iceberg.png"

global img1,img2
img1 = cv2.imread(path1)
img2 = cv2.imread(path2)

def on_change_weight(x):
    weight = x /100
    img_merged = cv2.addWeighted(img1, 1-weight, img2, weight, 0)
    cv2.imshow('Display',img_merged)

cv2.namedWindow('Display')
#조절할값의 이름, 부착할 창 이름, 최솟값, 최댓값, 변경시 호출될 함수
cv2.createTrackbar('weight','Display',0,100,on_change_weight)


img1 = cv2.resize(img1,(300,400))
img2 = cv2.resize(img2,(300,400))

#show and wait for any key to close


cv2.waitKey(0)




