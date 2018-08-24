 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

mktime
```info
#include <time.h> // C++ 에서는 <ctime>

time_t mktime ( struct tm * timeptr );

```

tm 구조체를 time_t 형식으로 변환한다.
timeptr 이 가리키는 tm 구조체를 읽어 들여서time_t 형식으로 리턴한다. 이 때, 이 함수가 tm 구조체에서 참조하는 값은 현재 시각과 날짜 뿐이다. 나머지 정보인 tm_wday 와 tm_yday 는 무시한다. 참고로 이 함수는 timeptr 이 가리키는 tm 구조체의 내용을 수정하는데, tm 구조체에 들어있는 시각과 날짜 정보를 가지고 tm_wday 와 tm_yday 를 설정한다. 따라서 이를 통해 역으로 mktime 함수를 호출 하여서 특정한 날짜가 무슨 요일이고, 몇 번째 날인지 추적할 수 도 있다.

### 인자

timeptr

tm 구조체를 가리키는 포인터로 반드시 날짜와 시간에 관한 정보가 들어 있어야 한다.

### 리턴값


현재 timeptr 로 전달된 날짜와 시각에 맞추어서 이에 대한time_t 값이 리턴된다. 오류 발생시에는 -1 이 리턴된다.

### 실행 예제


```cpp
/*

특정한 날짜가 무슨 요일인지 알아온다.
이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/mktime/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

int main ()
{
    time_t rawtime;
    struct tm * timeinfo;
    int year, month ,day;
    char * weekday[] = { "Sunday", "Monday",
        "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};

    /* 사용자로 부터 날짜를 입력 받는다. */
    printf ("Enter year: "); scanf ("%d",&year);
    printf ("Enter month: "); scanf ("%d",&month);
    printf ("Enter day: "); scanf ("%d",&day);

    /* rawtime 에 time 함수로 현재 시간 정보로 세팅한 뒤,
       사용자로 부터 입력받은 데이터로 년/월/일 정보를 수정한다. */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    /* mktime 함수를 호출하면 년/월/일 데이터에 따라
       tm_wday 와 tm_yday 를 설정한다. 이 때 리턴되는 time_t 데이터는 사용하지 않는다.*/
    mktime ( timeinfo );

    printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);

    return 0;
}

```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F2053CC544D1607BD2BED84)



### 연관된 함수

* asctime : tm 구조체를 문자열로 변환한다.

* gmtime  :  time_t 값을 UTC 시간에 따라 tm 구조체로 변환한다.

* localtime :time_t 값을 지역 시간에 따라 tm 구조체로 변환한다.
* time  :  현재 시각을 알아온다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >time.h (ctime)' 카테고리의 다른 글C 언어 레퍼런스 - asctime 함수(0)2010.12.26C 언어 레퍼런스 - time 함수(2)2010.12.26C 언어 레퍼런스 - mktime 함수(0)2010.12.26C 언어 레퍼런스 - time_t 형(1)2010.12.25C 언어 레퍼런스 - difftime 함수(0)2010.12.25C 언어 레퍼런스 - clock 함수(2)2010.12.25
