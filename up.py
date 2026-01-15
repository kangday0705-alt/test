import random

#play, game, score, main

def play(maxnum, maxatt): #정답 생성후 입력비교, 시도 횟수 리턴
    
    ans = random.randint(1, maxnum)
    att=0

    print(f"범위:1~{maxnum}, {maxatt}번 까지 시도")


    while True: #입력받아 업다운 출력, 실패시none 성공시att 리턴
        
        s = input("입력: ").strip()
        x = int(s)

        if x<1 or x>maxnum:
            print("범위 확인!")
            continue

        att+=1
        if x==ans:
            print (f"정답! {att}번 시도.")
            return att
        elif att>=maxatt:
            print(f"최대시도횟수 초과. 정답:{ans}")
            return None
        elif x < ans:
            print("up")
        elif x > ans:
            print("down")



def game(): #난이도 선택 후 플레이

    print("업다운 게임!")
    sc=0
    
    while True: #난이도선택
        a=int(input("난이도를 선택하세요(1~3): ").strip())
        
        match a:
            case 1:
                maxnum=50
                maxatt=10
                break
            case 2:
                maxnum=50
                maxatt=5
                break
            case 3:
                maxnum=100
                maxatt=5
                break
            case _:
                print("다시입력")


    while True: #플레이루프
        
        #플레이 어템트를 스코어로 넘겨 계산
        nowsc=score(a,play(maxnum,maxatt),maxatt)
        
        sc+=nowsc
        print(f"점수:{nowsc}점, 누적{sc}") #이번점수를 누적시켜 출력

        if nowsc==0:
            break   #이번판 실패시 기회 없음

        con=input("계속하시겠습니까?(Y or N): ")
        match con:
            case "N"|"n":
                break
            case "Y"|"y":
                continue
            case _:
                print("다시입력")

def score(lev, att, maxatt):

    if att is None:
        sc=0
    else:   
        base=100*lev
        n=(base/maxatt)*(att-1)
        sc=base-n
    return sc

def main():
    game()

if __name__=="__main__":
    main()