# 2018-10-19
### AWS 올리기 전
Selenium으로 Chrome을 실행시킬 때 `알람 팝업`으로 인해 **클릭 함수 실행 시 오류 발생**
> chrome_options = webdriver.ChromeOptions()  
prefs = {"profile.default_content_setting_values.notifications": 2}  
chrome_options.add_experimental_option("prefs", prefs)

다음과 같은 코드를 넣으니 `알람 팝업`이 뜨지 않음.
<br/>
<br/>
### AWS 올린 후
chromedriver 설치로 엄청난 시간을 소모. 알고보니 webdriver만 설치하고
**정작 chrome 설치를 하지 않았던 것.** 
>  chrome_options.add_argument("--headless")  
chrome_options.add_argument("--no-sandbox")  
chrome_options.add_argument("--disable-dev-shm-usage")  
chrome_options.add_argument("--disable-gpu")  
chrome_options.add_argument("--disable-extensions")

chrome option만 가지고 삽질만 한 결과, 많은 옵션만 추가하며 시간을 버림....
검색해본 결과 AWS, Jenkins, Heroku 등에서 실행하려면 위의 것들 중 몇가지 헤더는 필수적으로 넣어야 오류가 안나는듯.

이후 `crontab` 적용하여 30분마다 실행시키도록 함.
> crontab -e
> */30 * * * * sudo python3 Poke.py >> Poke.log

`~~ >> Poke.log에서 '>'를 한 개만 넣으면 이어써지지 않고 덮어 쓰인다`<br/>
`우분투에 chrome 설치하기` : <a>http://snowdeer.github.io/linux/2018/02/02/ubuntu-16p04-install-chrome/</a>
