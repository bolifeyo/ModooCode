 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

puts
```info
#include <stdio.h> // C++ 에서는 <cstdio>

int puts ( const char * str );
```


표준 출력에 문자열을 쓴다.
str 이 가리키는 C 문자열을 표준 출력(stdout) 에 쓴 뒤 자동으로 개행 문자('\n') 도 추가로 쓴다.
(즉 문자열에 \n 이 마지막에 없더라도 한 줄 개행이 되어 출력된다)
puts 함수는 str 이 가리키는 주소 부터 널 종료 문자 ('\0') 에 도달할 때 까지 표준 출력에 문자를 복사하지만 마지막 널 문자는 표준 출력에 복사되지 않는다.
fputs(str, stdout) 을 통해 puts 함수와 동일한 작업을 할 수 있지만 fputs 함수의 경우 마지막에 개행 문자를 붙이지 않는다.

### 인자

str

표준 출력에 쓰여질 C 형식 문자열

### 리턴값

성공적으로 쓰였다면 음이 아닌 값이 리턴된다.
오류가 발생하였다면 EOF 를 리턴한다.

### 실행 예제

```cpp
/* 화면에 str 의 내용을 출력한다 */
#include <stdio.h>

int main ()
{
    char str[] = "Hello, World!";
    puts(str);
    return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F116332134B6AB977BD3643)

   주목해 볼 점은 str 에 개행 문자가 없었는데도 불구하고 화면에는 자동적으로 개행되어 나타났다는 점이다. 즉 puts 함수는 자동적으로 마지막에 \n 을 추가해서 스트림에 쓴다는 사실을 알 수 있다.


### 연관된 함수


* fputs  :  문자열을 스트림에 쓴다.
* printf  :  표준 출력(stdout) 에 데이터를 형식에 맞추어 출력한다.
* putchar  :  stdout 에 문자를 쓴다.
* gets  :  stdin 에서 문자열을 받는다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - clearerr 함수(0)2010.02.05C 언어 레퍼런스 - ungetc 함수(0)2010.02.04C 언어 레퍼런스 - puts 함수(0)2010.02.04C 언어 레퍼런스 - putchar 함수(0)2010.02.04C 언어 레퍼런스 - putc 함수(0)2010.02.04C 언어 레퍼런스 - gets 함수(3)2010.02.03
