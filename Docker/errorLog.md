# 2018-11-01
apt-get update 명령 수행 시 저장소 서버를 제대로 찾아가지 못하고  
0%에서 계속해서 오류를 생성.  
-> **DNS 서버를 제대로 참조하지 못해서 생기는 문제.**  
[링크](https://stackoverflow.com/questions/34296230/how-to-change-default-docker-machines-dns-settings)에서 해결책 참조.
>도커의 DNS 옵션에 직접 google dns 서버를 추가. (기존값은 NULL)

<br/>

도커 재시작 시 IP가 바뀌어버려서 어떤 명령도 실행되지 않음.
[링크](https://stackoverflow.com/questions/34641003/error-checking-tls-connection-error-checking-and-or-regenerating-the-certs)의 jaycode 님께서 작성해주신 해결책 참조.
> 시작 -> 네트워크 상태 확인 -> 어댑터 옵션 변경 -> VirtualBox Host-only 이더넷 모두 사용 안함으로 변경 -> 도커 재시작