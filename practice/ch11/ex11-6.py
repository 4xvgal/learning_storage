#ex11-6.py
import matplotlib.pyplot as plt
fig, ax = plt.subplots(1, 4, figsize=(10, 3))
plt.title("Graph, 20203103, Lim Jeongmin")
x = [x for x in range(7, 13)]
y = [456, 492, 578, 599, 670, 854]

ax[0].bar(x, y)
ax[1].plot(x, y)
ax[2].scatter(x, y, marker='^')
ax[3].barh(x, y)

plt.show()
