 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

strncpy
```info
#include <string.h> // C++ 에서는 <cstring>

char * strncpy ( char * destination, const char * source, size_t num );

```

문자열에서 일부 문자들 만을 복사한다.
source 에서 destination 으로 source 의 처음 num 개의 문자들 만을 복사(NULL 도 포함해서) 한다. num 보다 source 의 문자 수가 더 적다면은 모자란 부분은 0 으로 생각되어서 destination 에 복사가 된다. 다시 말해 source 가 "abc" 인다, num 이 5 라면 destination 에는 "abc\0\0" 가 들어가게 된다.

strncpy 함수는 복사시 destination 끝에 반드시 NULL 문자를 붙이는 것이 아니므로 사용에 주의를 해야 한다.

### 인자

destination

destination 배열을 가리키는 포인터로 문자열이 복사될 곳이다.

source

복사 될 C 문자열이다.

num

source 에서 복사 할 문자의 개수 이다.

### 리턴값

destination 을 리턴한다.

### 실행 예제

```cpp
/*

str2 에  str1 의 첫 5 문자, 즉 "To be" 를 복사해 넣는다. 이 때, str2 에는 자동으로 끝에 NULL 문자가 붙는 것이 아니므로 인위적으로 넣어주어야 한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strncpy/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[]= "To be or not to be";
    char str2[6];
    strncpy (str2,str1,5);
    str2[5]='\0';
    puts (str2);
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F135F511C4BF5F68C075CFF)

### 함수 구현 예

```cpp
/*

다음 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져온 것입니다.

*/
char *strncpy(char *dest, const char *source, size_t count)
{
    char *start = dest;

    while (count && (*dest++ = *source++)) count--;
    if (count) while (--count) *dest++ = '\0';
    return start;
}

```


### 연관된 함수


* strcpy : 문자열을 복사한다.

* memcpy  :  메모리 블록을 복사한다.
* memmove :  메모리 블록을 옮긴다.

* memchr  :  메모리 블록에 문자를 위치시킨다.

* memcmp  :  두 개의 메모리 블록을 비교한다.

* memset  :  메모리 블록을 채운다.
공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strncat 함수(0)2010.05.23C 언어 레퍼런스 - strcat 함수(0)2010.05.21C 언어 레퍼런스 - strncpy 함수(5)2010.05.09C 언어 레퍼런스 - strcpy 함수(8)2010.05.02C 언어 레퍼런스 - memmove 함수(7)2010.04.25C 언어 레퍼런스 - memcpy 함수(11)2010.04.24
