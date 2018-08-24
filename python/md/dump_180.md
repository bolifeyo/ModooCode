 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios::clear

```info
void clear ( iostate state = goodbit );
```


오류 상태 플래그를 설정한다.
오류 상태 플래그를 새로운 값으로 설정한다. 참고로 이와 유사한 동작을 하는ios::setstate 의 경우, 이전의 오류 상태 플래그를 보존하면서 설정하지만, ios::clear 의 경우 이전의 오류 상태 플래그 값을 보존하지 않는다.

만일 인자를 넣어주지 않는다면 (혹은 인자로 goodbit 을 전달하면) 모든 오류 상태 플래그는 초기화된다.

현재의 오류 상태 플래그는ios::rdstate 함수로 얻을 수 있다.

 인자


state

새롭게 바꿀 ios_base::iostate 타입의 객체로 아래의 오류 상태 멤버 상수들의 조합 (비트 OR 연산) 으로 구성된다.




플래그 값
의미
eofbit
스트림으로부터 추출 작업(extracting operation)을 수행 중 End – Of –  File에 도달하는 경우
failbit
마지막 입력 작업이 자체의 내부 오류 때문에 실패하였을  경우
badbit
스트림 버퍼의 입출력 작업이 실패하여 발생한 오류
goodbit
오류가 없다.

만일 인자로 아무 것도 전달하지 않는다면 디폴트 인자로 goodbit 가 전달된다.


 리턴값


없음

 실행 예제

```cpp
/*

test.txt 를 in 형식으로 open 하였으므로 읽기만 가능한다. 따라서 쓰기를 하면 오류가 발생하므로 myfile.fail() 이 true 가
되고 입출력 작업은 중지되지만 오류 상태 플래그를 초기화함으로써 나중에 getline 을 수행할 수 있게 된다.

이 예제는
http://www.cplusplus.com/reference/iostream/ios/clear/
에서 가져왔습니다.

*/
#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    char buffer [80];
    fstream myfile;

    myfile.open ("test.txt",fstream::in);

    myfile << "test";
    if (myfile.fail())
    {
        cout << "Error writing to test.txt\n";
        myfile.clear();
    }

    myfile.getline (buffer,80);
    cout << buffer << " successfully read from file.\n";

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F182B374B4F6E75AF1F5F53)


 템플릿 멤버 정의


```cpp
( basic_ios<charT,traits> )

void clear ( iostate state = goodbit );
```


 연관된 함수


* ios::fail  :  failbit 이나 badbit 이 설정되어 있는지 확인한다.

* ios::bad  :  badbit 이 설정되어 있는지 확인한다.

* ios::good :  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.
* ios::eof  :  eofbit 이 설정되어 있는지 확인한다.

* ios::rdstate  :  오류 상태 플래그를 얻는다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios::rdbuf 함수(0)2012.03.25C++ 레퍼런스 - ios::fill 함수(0)2012.03.25C++ 레퍼런스 - ios::clear(0)2012.03.25C++ 레퍼런스 - ios::setstate 함수(0)2012.03.25C++ 레퍼런스 - ios::rdstate 함수(0)2012.03.25C++ 레퍼런스 - ios::operator void*(0)2012.01.01
