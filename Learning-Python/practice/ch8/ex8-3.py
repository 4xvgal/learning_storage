##ex8-3.py

print("사전 프로그램 시작.. 종료는 q를 입력")
dictionary = {}

while True:
    st = input('$ ') ## st 에 입력받기
    command = st[0]     ## '<' '>' 명령어 구분을 위해 command 에 첫문자를 저장한다.
    if command == '<':  ## 입력 명령문
        st = st[1:]        ## 첫문자 '<' '>' 를 제외한 문자열을 저장
        inputStr = st.split(':')    ##  split 함수로 : 기준으로 두 문자열로 분리해 딕셔너리로 저장
        if len(inputStr) < 2 :
            print('입력 오류가 발생했습니다.')
        else:
            dictionary[inputStr[0].strip()] = inputStr[1].strip()

    elif command == '>':    ##검색 명령문
        st = st[1:] ## 첫문자를 제외한 문자열을 저장한다.
        inputStr = st.strip()   ##검색할 단어 문자열의 공백을 제거한다.
        if inputStr in dictionary:      ## 만약 인풋이 딕셔너리에 있으면
            print(dictionary[inputStr])     ## 해당단어 뜻 출력
        else :
            print('{}가 사전에 없습니다. '.format(inputStr)) ## 없으면 키값출력
    elif command == 'p':    ##모든 단어 출력문
        print(dictionary.items())
    elif command == 'q': ## q가 입력되면 종료
        break
    else :
        print('입력 오류가 발생했습니다.')
print ("사전 프로그램을 종료합니다.")
    
