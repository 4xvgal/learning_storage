import matplotlib.pyplot as plt
import matplotlib.image as mpimg
path = "/Users/mac/Documents/codes/python3.8/test1/image/mandrill.png"

print("13-1 20203103 임정민")
img= mpimg.imread(path)
print(img)

image_plot = plt.imshow(img)
plt.show()



