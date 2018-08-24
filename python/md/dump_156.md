 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios_base::unsetf


```cpp
void unsetf ( fmtflags mask );
```


특정 서식 플래그를 끈다(clear)
인자로 전달되는 mask 에 켜져 있는 서식 플래그가 꺼지게 된다.

인자를 가지는 조작자인 resetiosflags 역시 동일한 작업을 수행한다.

 인자


mask

  어떤 서식 플래그를 끌지 나타내는 비트마스크. 이 비트마스크는 fmtflags 타입의 상수들의 조합(OR 연산) 으로 나타낼 수 있다. 아래 실행 예제를 참고하여라.

 리턴값

없다

 실행 예제

```cpp
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/unsetf/
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main ()
{
    cout.setf ( ios::hex, ios::basefield );       // hex 를 설정한다.
    cout.setf ( ios::showbase );                  // showbase 를 설정
    cout << 100 << endl;
    cout.unsetf( ios::showbase );               // showbase 를 끝다.
    cout << 100 << endl;
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F12714A584E4DE70D317643)


 연관된 것들


* ios_base::flags  :  서식 플래그를 설정하거나 얻는다.
* ios_base::setf  :  특정 서식 플래그를 설정한다.
* ios_base::fmtflags  :  스트림 서식 플래그의 타입
* resetiosflags :  서식 플래그를 끈다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios_base::register_callback 함수(0)2011.08.20C++ 레퍼런스 - ios_base::precision 함수(0)2011.08.19C++ 레퍼런스 - ios_base::usetf 함수(0)2011.08.19C++ 레퍼런스 - ios_base::setf 함수(0)2011.08.19C++ 레퍼런스 - ios_base::fmtflags 타입(0)2011.08.19C++ 레퍼런스 - ios_base::flags 함수(0)2011.08.19
