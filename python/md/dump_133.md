 itguru Top itguru Top

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F205D883D4D4D02442A6149)

  안녕하세요. 원래 제가 기억하기로 tistat 이라는 프로그램이 있었는데, 이 좋은 프로그램을 만드신 분의 사이트가 사라지는 바람에 결국 제가 직접 만들어야 했습니다 ㅎㅎ. C++ 연습도 해볼 겸 프로그램을 재미 삼아 만들어보았는데요, 이게 생각보다 복잡하여서 여러가지 걸림돌이 많더라고요. 일단 XML 파일을 읽어들여야 하기 때문에 좋은 XML parser 인 tinyxml 을 이용하였고, 또다른 문제로 이 파일이 UTF-8 형식으로 되어 있어서 이를 제대로 인코딩하는데에도 많은 애를 먹었습니다. 그래고 일단 만들어 놓으니 뿌듯하네요.

 기존의 tistat 에서 지원하는 기능들의 거의 대부분의 기능은 구현하였습니다. 필요 없는 것들은 몇 개 뺐는데 (예를 들어 제가 거의 관심을 안가지는 트랙백 ㅋ), 지원하는 기능은

월별 글 수
시간대별 글 수
전체 댓글 수
월별 댓글 수
시간별 댓글 수
댓글 많이 달린 글 100개
댓글 단 사람 (이름으로 추정) 전체 목록
댓글 단 사람 (이름 및 ip 를 고려해서 추정) 전체 목록
월별 방문객 수
가장 많이 방문한 날

 들을 지원합니다. 그런데 무엇보다도 제가 가장 잘 만들었다고(?) 생각하는 기능은 댓글 단 사람의 이름과 ip 를 고려해서 추정하는 것인데, 동일한 사람이라도 여러가지 사용자 명으로 댓글을 남기는 사람들이 있고 또 동일한 사용자 명이라도 다른 ip 지역대에서 접속하는 사람들이 있는데 이것을 모두 고려하여서 '동일한 인물인지 정확하게 구분하여' 댓글 단 개수를 추정하는 것을 넣었습니다.

  이는 특히 제 블로그에 많은 도움이 되는데, 제 블로그의 형식상 tistory 보다는 외부 검색엔진에서 유입되는 사람들이 훨씬 많기 때문에 ID 를 기입하지 않고 댓글을 다는 사람이 무척이나 많습니다. 또한 매번 댓글을 달 때 마다 사용자 명을 바꾸는 사람들도 태반이지요. 따라서 어느 사람이 누구누구 인지 구분하기 위해 위와 같은 루틴을 넣었습니다.

  또한 부가적으로

전체 댓글 수
전체 포스트 수
댓글 수가 1 개 이상인 포스트 수
포스트 당 댓글 수
댓글 수가 0 인 포스트를 제외한 포스트 당 댓글 수
댓글 작성자 평균 댓글 작성 수
방문자 당 댓글 수 비율

  를 모두 알 수 있도록 추가하였습니다. 그리고 확실히 C++ 이 다른 인터프리팅 언어 보다는 훨씬 가볍고 빠르네요. 크기도 200kb 정도 밖에 안되고, xml 파일 분석도 금방 금방 합니다.

  아래는 그 파일 입니다. tistory_statistics.exe 를 누르시면 다운 받으실 수 있습니다.

 tistory_stastics.exe
  사용하는 방법은, 프로그림이 위치한 곳에 분석을 원하는 파일을 놔둔 후, 프로그램을 실행 시킨 뒤 파일 이름을 쓰고 데이터를 가져오기 원하는 시간 범위를 써주시면 됩니다. 아래 그림을 보시면 이해가 쉽습니다

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F135CCC434D4D01220FC847)

위 그림처럼 같은 위치에 원하는 xml 파일을 둔 뒤,

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F15420A434D4D012230D529)

위와 같이 파일 이름을 입력하고, 원하는 데이터 범위 yyyymmdd 형식으로 넣으시면 됩니다. 예를 들어서 2009 년 1 월 1 일 부터 2011 년 2 월 5 일 까지의 데이터 범위를 얻고 싶다면 20090101 을 쓰고 엔터를 누른 뒤 20110205 를 쓰고 다시 한 번 엔터를 누르면 됩니다. 그렇다면 아래 그림 처럼 out.txt 와 csv_out.csv 파일이 만들어져 있을 것입니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F1357713E4D4D019D113A85)

csv_out.csv 는 csv 형식 파일로 엑셀에서 바로 열어보실 수 있고, out.txt 는 텍스트 파일로 csv_out.csv 와 내용은 동일합니다.

그럼 모두 잘 쓰세요~~ 버그 같은거나 추가하기 원하는 기능은 댓글로 달아주세요.






공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'My Program' 카테고리의 다른 글티스토리용 통계 프로그램 (댓글, 포스트, 방문자 등등) - tistory_stat (v.0.1)(9)2011.02.05
