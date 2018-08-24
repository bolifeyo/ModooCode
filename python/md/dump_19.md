 itguru Top itguru Top

이번 강의에서는

* 주석에 대한 확실한 이해
![신나는 씹어먹는 C 언어!](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F114BFB114ABB3A4E151E40)

  사실, 2 - 1 강에서도 다룬 내용이지만 댓글을 통해 질문이 들어 왔기에 정확히 주석이란 놈이 무엇인지 알아 보도록 하겠습니다.

  우리가 프로그래밍을 하다 보면 소스 코드가 상당히 길어 지게 됩니다. 우리가 앞서 한 Hello, World! 출력 예제는 소스 코드가 겨우 몇 줄에 불과하였으나 실제로 어떤 프로그램을 만들다 보면 소스 코드의 길이가 수천 줄에서 수만 줄 가까히 됩니다.믿기지 않으신다면 우리가 지금 사용하는 Windows XP 의 소스 코드가 몇 줄 정도 될 지 추측해 보세요. 한, 십만줄? 50만 줄? 아닙니다. 정확한 자료는 아니지만 대략 4000만 줄 이상 된다고 합니다.

  이런 크기로 프로그램을 작성하다 보면 이 소스 코드가 무엇을 뜻하고 또 무슨 일을 하는지 등의 정보를 소스 코드 내에 나타내야 할 필요성이 있게 됩니다. 즉, 컴파일러가 완전히 무시하고 오직 인간의 편의를 위해서만 존재하는 것이 바로 '주석' 입니다.

  사실 많은 사람들이 주석의 유용함을 간과하는 경우가 많습니다. 하지만 주석은 자신의 편의를 위해서도지만 남이 자신이 쓴 소스코드를 보고 쉽게 이해할 수 있도록 도와주는 역할을 합니다. 게다가 한 주석이 없는 프로그램을 만들고 1 달 쯤 뒤에 작업하려고 하면 도대체 이게 무엇을 하는 소스코드인지 알 수 없는 경우가 종종, 아니 자주 발생하게 됩니다. 따라서 우리는 타의든, 자의든 간에 무조건 소스코드에 중요한 부분은 주석을 넣도록 해야 합니다.

  C 언어에서 주석은 두 가지 방법으로 넣을 수 있습니다.

```info
/* 주석이 들어가는 부분 */

// 주석이 들어가는 부분
```

  일단 전자의 경우 /* 와 */ 로 묶인 내부의 모든 내용들이 주석으로 처리 됩니다. 즉,

```cpp
/*

이 부분은 내가 아무리 생쇼를 해도 컴파일러가 무시
ㅁㄴㅇ러ㅏㅁ니ㅓㄹ먼리;ㅏㄴㅁ어림나러 무시
ㅁ아ㅓㄹ민럼ㄴㄹ ㅁㄴㅇ럼니러
ㅁㄴ라미너럼나러ㅣㅁ너라ㅣㅓㅇ
printf("Hello, World"); <- 이 것도 당연히 무시
*/
```

 와 같이 난리를 쳐도 /* 와 */ 로 묶인 부분은 무시됩니다. 아래 예제를 보면 이해가 더욱 잘 될 것입니다.

```cpp
#include <stdio.h>
int main()
{
    /*
    printf("Hello, World!\n");
    printf("Hi, Human \n");
    */
    printf("Hi, Computer \n");

    return 0;
}
```

위와 같은 소스코드를 컴파일 하였을 때,

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F18062C104ABB38E6420A43)

와 같이 Hi, Computer 을 출력하는 부분만 남을 것을 볼 수 있습니다. 이는 앞서 말했듯이 /* 와 */ 로 묶인 부분이 전부다 주석으로 처리되어서 컴파일러가 철저하게 무시하였기 때문 입니다.

반면의 // 형태의 주석의 경우 // 가 쳐진 줄 만이 주석으로 처리가 됩니다. 즉,

```cpp
// 이부분은 내가 아무리 생쇼를 해도 무시한다
printf("Hello, World!");
```

로 하면 아래 printf 부분 잘 실행됩니다. 하지만 위 주석은 역시 무시됩니다
아래 예제를 보면 확실히 알 수 있습니다.

```cpp
#include <stdio.h>
int main()
{
    //printf("Hello, World!\n");
    printf("Hi, Human \n");
    printf("Hi, Computer \n");

    return 0;
}
```

  성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F1646CE134ABB39E2743606)

  와 같이 주석으로 감싸진 부분을 제외하고는 나머지 부분이 잘 출력되었음을 알 수 있다.




```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는 <<씹어먹는 C 언어 - <2 - 2. 주석(Comment)에 대한 이해>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요

다음 강좌 보러가기

```
공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C' 카테고리의 다른 글씹어먹는 C 언어 - <11 - 2. C 언어의 아파트2 (고차원의 배열)>(65)2009.10.29씹어먹는 C 언어 - <2 - 3. 수를 표현하는 방법(기수법)>(165)2009.10.12씹어먹는 C 언어 - <2 - 2. 주석(Comment)에 대한 이해>(102)2009.09.24씹어 먹는 C 언어 - <10. 연예인 캐스팅(?) (C 언어에서의 형 변환)>(181)2009.08.15씹어먹는 C 언어 - <9. 만약에... 2탄 (switch 문)>(87)2009.08.15씹어 먹는 C 언어 - <8. 우분투 리눅스에서 C 프로그래밍 하기>(43)2009.08.06
