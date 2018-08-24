 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

struct tm

```info
#include <time.h> // C++ 에서는 <ctime>
struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};
```


시간 구조체이다.
이 구조체는 현재의 날짜와, 시간에 관한 정보를 포함하고 있다. 이 구조체는 9 개의 int 형 멤버들로 구성되어 있는데 각각의 멤버들에 대해 설명을 하자면 아래의 표와 같다.


멤버의미값의 범위
tm_sec현재 시각이 몇 초 인지
0-61*tm_min현재 시각이 몇 분 인지
0-59tm_hour현재 시각이 몇 시 인지
0-23tm_mday지금이 몇 일 인지
1-31tm_mon지금이 몇 월 인지
0-11tm_year지금이 몇 년 인지 (1900 이후)

tm_wday지금이 무슨 요일 인지
0-6tm_yday1 월 1 일 부터 몇 일이 지났는지
0-365tm_isdst서머 타임제를 실시하고 있는지 아닌지


만일 tm_isdst 가 0 보다 크면 서머 타임제를 실시하고 있다는 것이고, 0 이면 실시하고 있지 않다는 의미고, 0 보다 작으면 알 수 없다는 의미가 된다. 참고로 tm_sec 은 보통의 경우 0 부터 59 까지의 값을 가지게 되겠지만 종종 지구 자전 속도의 차이로 인해서 몇 년 마다 한 번 씩 '윤초' 를 도입하여 시간을 보정하는 경우가 있는데 이 때문에 tm_sec 의 값이 60 혹은 61 이 될 수 있다.

   tm_year 의 경우 1900 년 이후의 년 수를 입력하는 것이므로 2000 년의 경우 100 이 들어가게 된다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >time.h (ctime)' 카테고리의 다른 글C 언어 레퍼런스 - mktime 함수(0)2010.12.26C 언어 레퍼런스 - time_t 형(1)2010.12.25C 언어 레퍼런스 - difftime 함수(0)2010.12.25C 언어 레퍼런스 - clock 함수(2)2010.12.25C 언어 레퍼런스 - struct tm ( tm 구조체 )(0)2010.12.25C 언어 레퍼런스 - time.h 헤더파일(0)2010.12.25
