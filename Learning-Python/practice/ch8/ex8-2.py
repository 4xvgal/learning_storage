##ex 8-2.py

items = {"커피음료": 7, "펜": 3, "종이컵":2, "우유": 1,}

#name = input("물건의 이름을 입력하시오:")
#print('재고 :', items[name])

w = 0
while w!= 1:
    m = int(input("메뉴를 선택하세요 1) 재고조회, 2) 입고, 3)출고, 4) 종료: "))
    if m == 1 :
        n = input("[재고조회] 물건의 이름을 입력하시오 : ")
        print('재고:', items[n])
    elif m == 2:
        n , count = input("[입고] 물건의 이름과 수량을 입력하시오 : ").split()
        items[n] = items[n] + int(count)
        print('재고:', items[n])
    elif m == 3:
        n , count = input("[출고] 물건의 이름과 수량을 입력하시오 : ").split()
        items[n] = items[n] - int(count)
        print('재고:', items[n])
    elif m== 4:
        w = 1