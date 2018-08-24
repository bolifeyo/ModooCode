 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios::operator!
```info
bool operator ! ( ) const;
```


스트림 객체의 오류 상태 플래그를 확인한다.
만일 스트림의 오류 상태 플래그인 failbit 와 badbit 중 어느 하나라도 설정되어 있다면 true 를 리턴하고 아니면 false 를 리턴한다.

이 연산자는fail() 함수의 동일한 작업을 한다.

 인자

없다


 리턴값

failbit 나 badbit 어느 하나라도 설정되어 있다면 true 를 리턴한다.
아니면 false

 템플릿 멤버 정의

```cpp
( basic_ios<charT,traits> )
bool operator ! () const;
```


 실행 예제

```cpp
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios/operatornot/
에서 가져왔습니다.

*/
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream is;
    is.open ("test.txt");
    if (!is)
        cerr << "Error opening 'test.txt'\n";
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1265704E4EA3679D21067B)






 연관된 함수



* ios::fail  :  failbit 이나 badbit 이 설정되어 있는지 확인한다.
* ios::good :  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios::rdstate 함수(0)2012.03.25C++ 레퍼런스 - ios::operator void*(0)2012.01.01C++ 레퍼런스 - ios::operator!(2)2011.10.23C++ 레퍼런스 - ios::eof 함수(0)2011.10.23C++ 레퍼런스 - ios::bad 함수(0)2011.10.23C++ 레퍼런스 - ios::fail 함수(0)2011.10.23
