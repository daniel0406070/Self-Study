//최진혁 2024.04.14 실습과제
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define DAY_IN_MONTH 30

enum Fruit {Apple, Watermalon, Grape, Strowberry, None = -1};
char* fruitName[] = {"사과", "수박", "포도", "딸기"};
enum SeasonStart {Spring=3, Summer=6, Fall=9, Winter=12};

int* checkWhichFruitByMonth(int month){ //계졀에 따라 과일을 반환 반환값 봄,여름:{수박, 딸기}, 가을,겨울:{사과, 포도}
    int* fruits = (int*)malloc(sizeof(int)*2);

    if(Spring <= month && month < Fall){
        fruits[0] = Watermalon;
        fruits[1] = Strowberry;
    }else{
        fruits[0] = Apple;
        fruits[1] = Grape;
    }

    return fruits;
}

int* checkWhichFruitByDay(int day){ //일의 끝자리에 따라 과일을 반환 반환값 1,5:{사과, 딸기}, 3,7:{수박, 포도} 나머지는 없음
    int* fruits = (int*)malloc(sizeof(int)*2);
    int dayendwith = day%10;
    if(dayendwith == 1 || dayendwith == 5){
        fruits[0] = Apple;
        fruits[1] = Strowberry;
    }
    else if(dayendwith == 3 || dayendwith == 7){
        fruits[0] = Watermalon;
        fruits[1] = Grape;
    }
    else{
        fruits[0] = None;
        fruits[1] = None;
    }

    return fruits;
}

int whichIsOverlapped(int* fruits1, int* fruits2){ //두 배열의 교집합을 반환, 없으면 None 반환
    if(fruits1[0] == fruits2[0]){
        return fruits1[0];
    }else if(fruits1[0] == fruits2[1]){
        return fruits1[0];
    }else if(fruits1[1] == fruits2[0]){
        return fruits1[1];
    }else if(fruits1[1] == fruits2[1]){
        return fruits1[1];
    }else{
        return None;
    }
}

int checkWhichFruit(int month, int day){ // 월, 일에 따라 반환받은 과일에서 교집합을 반환 
    int* fruitsbymonth = checkWhichFruitByMonth(month);
    int* fruitsbyday = checkWhichFruitByDay(day);

    return whichIsOverlapped(fruitsbymonth, fruitsbyday);
}

int getHowManyFruit(int fruit, int user_count){
    switch (fruit){
        case Apple:
            return user_count; //사과는 1명당 1개로 판매
        case Watermalon:
            return user_count/10 + (user_count%10?1:0); //수박은 10명 단위로 판매 나머지는 1개로 판매
        case Grape:
            return user_count/2 + (user_count%2?1:0); //포도는 2명 단위로 판매 나머지는 1개로 판매
        case Strowberry:
            return user_count*5; //딸기는  1명당 2개로 판매
        default:
            return 0; //None 처리
    }
}

int main(){
    int input_month;
    int input_user_count;
    scanf("%d %d", &input_month, &input_user_count);

    for(int i=1; i<= DAY_IN_MONTH; i++){
        printf("%d월 %d일 : ", input_month, i);
        int todayFruit = checkWhichFruit(input_month, i);
        if(todayFruit == None) //교집합이 없을 경우
            printf("-");
        else 
            printf("%s %d개", fruitName[todayFruit], getHowManyFruit(todayFruit, input_user_count)); //과일이 있을 경우
        printf("\n");
    }

}