 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

fputs
```info
﻿<stdio.h> // C++ 에서는 <cstdio>﻿﻿﻿

int fputs ( const char * str, FILE * stream );
```

스트림에 문자열을 쓴다.

str 이 가리키는 문자열을 stream 에 씁니다.
fputs 는 str 이 가리키는 문자열을 NULL 문자 ('\0') 에 도달할 때 까지 스트림에 복사합니다. 마지막 NULL 문자는 스트림에 복사되지 않습니다.

### 인자

str

스트림에 쓰여질 널 문자로 끝나는 문자들의 배열.

stream

문자열을 쓸 스트림의 FILE 객체를 가리키는 포인터

### 리턴값

쓰기를 성공한다면 음이 아닌 수가 리턴된다.
오류가 발생한다면 EOF 를 리턴한다.

### 실행 예제

```cpp
/* 화면에 str 의 내용을 출력한다. */
#include <stdio.h>
int main ()
{
    char str[] = "string to print \n";

    fputs(str, stdout);

    return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F18309F0C4B6811F13F2A5C)

화면(stdout) 에 str 의 내용인 string to print \n 이 출력된 것을 볼 수 있다.

```cpp
/*

mylog.txt 에 (없으면 파일을 생성한다) 사용자로 부터 입력받은 문자열을 추가한다.
(기존의 파일 내용은 삭제되지 않고 끝에 덧붙인다)
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fputs/
에서 가져왔습니다.

*/

#include <stdio.h>
int main ()
{
    FILE * pFile;
    char sentence [256];

    printf("mylog.txt 에 추가할 문자열을 입력하세요: ");
    fgets (sentence,255,stdin);
    pFile = fopen ("mylog.txt","a");
    fputs (sentence,pFile);
    fclose (pFile);
    return 0;
}
```

실행 화면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F1931E40B4B68116928BD26)

파일의 모습

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F171D710B4B6811A4481109)


### 연관된 함수


* puts   : stdout 에 문자열을 쓴다.
* fgets  : 스트림에서 문자열을 받아온다.
* fputc  : 스트림에 한 문자를 쓴다.
* fprintf : 특정한 형식으로 스트림에 쓴다.
* fwrite : 스트림에 데이터 블록을 쓴다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - scanf 함수(2)2010.02.03C 언어 레퍼런스 - getc 함수(0)2010.02.02C 언어 레퍼런스 - fputs 함수(0)2010.02.02C 언어 레퍼런스 -  fputc 함수(0)2010.01.29C 언어 레퍼런스 - fgets 함수(1)2010.01.28C 언어 레퍼런스 - fgetc 함수(1)2010.01.28
