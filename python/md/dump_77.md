 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

memcpy
```info
#include <string.h> // C++ 에서는 <cstring>

void * memcpy ( void * destination, const void * source, size_t num );

```

메모리의 일부분을 복사한다.
memcpy 함수의 인자인 source 가 가리키는 곳 부터 num 바이트 만큼을 destination 이 가리키는 곳에 복사한다.
이 때, destination 과 source 의 타입은 모두 위 함수와 무관하다. 왜냐하면 이 함수는 단순히 이진 데이터를 복사하는 것이기 때문이다. 또한, 이 함수는 source 의 널 종료 문자(null terminating character) 을 검사하지 않는다. 언제나 정확히 num 바이트 만큼을 복사한다.
오버플로우 문제를 방지하기 위해 destination 과 source 가 가리키는 배열의 크기는 반드시 num 바이트 이상이여야 하며, 서로 겹치면 안된다. (만일 두 메모리 블록이 겹쳐져 있다면 memmove 함수를 이용하는 것이 현명하다)

### 인자

destination

데이터가 복사될 곳의 주소로, void* 형으로 형변환 되어서 전달된다.

source

복사할 데이터들이 위치한 주소로 역시 void* 형으로 형변환 되어서 전달된다.

num

복사할 데이터의 바이트 수 이다.

### 리턴값

destination 이 리턴된다.

### 실행 예제

```cpp
/*

첫번째 memcpy 함수는 str2 에 str1 의 문자열 길이 + 1 (끝의 널 문자 때문에 1 을 더해줌) 만큼을 str2 에 복사해 넣는다.
두번째 memcpy 함수는 str3 에 "copy successful\0" 을 복사해 넣는다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/memcpy/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>
int main ()
{
    char str1[]="Sample string";
    char str2[40];
    char str3[40];

    memcpy (str2,str1,strlen(str1)+1);
    memcpy (str3,"copy successful",16);
    printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
    return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F110F06254BD40CE9845AFA)

### 연관된 함수

* memmove  :  메모리의 블록을 옮긴다.

* memchr  :  메모리의 특정한 블록에 문자를 쓴다.

* memcmp  :  두 메모리 블록을 비교한다.

* memset  :  메모리 블록을 채운다.
* strncpy  :  문자열에서 특정한 개수의 문자를 복사한다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strcat 함수(0)2010.05.21C 언어 레퍼런스 - strncpy 함수(5)2010.05.09C 언어 레퍼런스 - strcpy 함수(8)2010.05.02C 언어 레퍼런스 - memmove 함수(7)2010.04.25C 언어 레퍼런스 - memcpy 함수(11)2010.04.24C 언어 레퍼런스 - string.h (cstring) 헤더파일(2)2010.04.24
