#리스트
population = ["Seoul", 9765, "Busan", 3441, "Incheon", 2954]

print('서울 인구:', population[1])
print('인천 인구:', population[-1])

cities = population[0::2] ## 0 번 인덱스 부터 2스텝 건너뛰어 저장
print('도시 리스트:', cities)
pops = population[1::2] ## 1번 인덱스부터 2스텝 건너뛰어 저장
print('인구의 합:', sum(pops))