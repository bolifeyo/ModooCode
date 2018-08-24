 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

strchr

```info
#include <string.h> // C++ 에서는 <cstring>

const char * strchr ( const char * str, int character );
      char * strchr (       char * str, int character );

```

문자열에서 특정한 문자가 가장 먼저 나타나는 곳의 위치를 찾는다.
이 때, 그 위치를 가리키는 포인터를 리턴한다. 이 때 마지막 NULL 문자도 C 문자열의 일부로 간주하기 때문에 이 함수는 문자열의 맨 끝 부분을 가리키는 포인터를 얻기 위해 사용할 수 도 있다.

이 때, C 의 경우 함수 오버로딩을 할 수 없으므로 아래와 같은 하나의 원형만 존재한다.

```info
char * strchr ( const char *, int );
```


참고로 맨 위에 나타난 원형은 C++ 에서만 유효하다.

### 인자

str

C 형식 문자열

character

검색할 문자로, int 형태로 형변환 되어서 전달되지만 함수 내부적으로는 다시 char 형태로 처리된다.

### 리턴값

str 에서 검색한 문자가 가장 먼저 나타나는 곳을 가리키는 포인터를 리턴한다. 만일 문자가 없다면 NULL 포인터를 리턴하게 된다.

### 실행 예제

```cpp
/*

str 에서 's' 라는 문자를 계속 찾는다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strchr/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] = "This is a sample string";
    char * pch;
    printf ("Looking for the 's' character in \"%s\"...\n",str);

    pch=strchr(str,'s');

    while (pch!=NULL)
    {
        printf ("found at %d\n",pch-str+1);
        pch=strchr(pch+1,'s');
    }

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F177446244C558BD59B51A7)



### 연관된 함수

* strrchr  :  문자열에서 특정한 문자를 검색하되, 가장 마지막으로 나타나는 위치를 구한다.
* memchr :  메모리 블록에서 특정한 문자를 검색한다.
* strpbrk  :  문자열에서 다른 문자열에 포함된 문자들 중 일치하는 문자를 검색한다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strpbrk 함수(0)2010.08.02C 언어 레퍼런스 - strcspn 함수(4)2010.08.02C 언어 레퍼런스 - strchr 함수(0)2010.08.02C 언어 레퍼런스 - memchr 함수(0)2010.08.01C 언어 레퍼런스 - strxfrm 함수(0)2010.08.01C 언어 레퍼런스 - strncmp 함수(0)2010.08.01
