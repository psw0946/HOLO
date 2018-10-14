# 2018-10-14

**Bothub**은 오류를 탐지하기 어렵다.  
`Telegram`에 명령을 입력하면 반응이 그냥 없을 뿐.  
가상환경에만 패키지를 설치하고 **Bothub** 서버에 따로 패키지를 설치하지 않아 반응이 나오지 않았다.
> 가상환경과 함께 Bothub 서버에도 파이썬 패키지 설치하기  

<br/>

`message = Message(event).set_text(melonChart).add_quick_reply(resMessage)`  
메세지를 구성하는 부분이다.  
**resMessage**가 없는 상태로 `message`를 구성했더니 오류도 아예 뜨지 않고 반응 자체도 나오지 않았다.
> add_quick_reply에 넣을 값이 빈 string이라면 결과값이 아예 나오지 않는다.