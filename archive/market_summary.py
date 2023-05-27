snp = bool(input("s&p500 지수가 상승했다면 1 하락했다면 0 : "))
dow = bool(input("다우존스 지수가 상승했다면 1 하락했다면 0 : "))
nsdq100 = bool(input("나스닥 100지수가  상승했다면 1 하락했다면 0 : ")) 
snp_point = float(input("s&p 500 은 몇 포인트의 변동이 있었습니까 : "))
dow_point = float(input("다우존스 지수는 몊 포인트의 변동이 있었습니까 : "))
nsdq100_point = float(input("나스닥 100 지수는 몊 포인트의 변동이 있었습니까 :"))
print("====================================")
print("오늘의 미국 주식시장 마감 상황을 알려드리겠습니다")
print("====================================")
if snp == True :
    print("S&P 500은 상승 마감하였으며", snp_point, "만큼 상승했습니다")
elif snp == False :
    print("S&P 500은 하락 마감하였으며", snp_point, "만큼 하락하였습니다")
if dow == True:
    print("다우존스 지수는 상승 마감하였으며", dow_point, "만큼 상승했습니다")
elif dow == False :
    print("다우존스 지수는 하락 마감하였으며", dow_point, "만큼 하락하였습니다")
if nsdq100 == True :
    print("나스닥 100 지수는 상승 마감하였으며", nsdq100_point, "만큼 상승했습니다")
elif nsdq100 == False :
    print("나스닥 100 지수는 하락 마감하였으며", nsdq100_point, "만큼 하락하였습니다")

    