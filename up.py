import random
import os

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

# def file_read():
#     with open("player.txt", "r", encoding="utf-8") as f:
#         a=0
#         for line in f:
#             a+=1
#             print(line.strip())
#             return a

def file_read():
    with open("player.txt", "r", encoding="utf-8") as f:
        for line in f:
            print(line)

def file_write(name, sc):
    with open("player.txt", "a", encoding="utf-8") as f:
        f.write(f"{name} {sc}") #롸이트 sc뒤에 \n만 뻈는데 이번에는 아예 줄바꿈이 없어




def game(): #난이도 선택 후 플레이

    print("업다운 게임!")
    sc=0

    name = input("플레이어 이름: ").strip()

    while True: #플레이루프
        
        while True: #난이도선택
            b=input("난이도를 선택하세요(1~3): ").strip()
            a=int(b)
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


        #플레이 어템트를 스코어로 넘겨 계산
        att=play(maxnum,maxatt)
        nowsc=score(a,att,maxatt)
        
        sc+=nowsc
        print(f"점수:{nowsc}점, 누적{sc}") #이번점수를 누적시켜 출력

        if nowsc==0:
            break   #이번판 실패시 기회 없음
        
        while True:
            con=input("계속하시겠습니까?(Y or N): ")
            match con:
                case "N"|"n":
                    file_write(name,sc)
                    file_read()
                    return

                case "Y"|"y":
                    break #YN루프종료후 플레이루프
                case _:
                    print("다시입력")
                    continue #YN루프 반복

    file_write(name,sc)
    file_read()

    


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
    #os.remove("player.txt")

    

    


if __name__=="__main__":
    main()
