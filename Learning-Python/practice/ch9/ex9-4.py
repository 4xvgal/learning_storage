print('\n9-4  20102000 홍길동 \n')
import wikipedia
from wordcloud import WordCloud, STOPWORDS
import matplotlib.pyplot as plt

wiki = wikipedia.page('Python')
text = wiki.content

wordcloud = WordCloud(width = 400, height = 300, stopwords = STOPWORDS).generate(text)

plt.figure(figsize=(40, 30))
plt.imshow(wordcloud)
plt.show()
