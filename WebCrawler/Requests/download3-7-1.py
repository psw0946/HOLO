from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import time

class NcafeWriteAtt:
    # 초기화 실행(webdriver 설정)
    def __init__(self):
        chrome_options = Options() # 어차피 한 번만 쓰기 때문에 굳이 self를 붙여서 리소스를 낭비할 건 없다!
        chrome_options.add_argument("--headless") # CLI (User-agent)
        self.driver = webdriver.Chrome(chrome_options=chrome_options, executable_path='C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
        self.driver.implicitly_wait(5)

    # 네이버 카페 로그인 && 출석 체크
    def writeAttendCheck(self):
        self.driver.get('https://www.naver.com')
        self.driver.find_element_by_xpath('//*[@id="account"]/div/a/i').click()
        self.driver.find_element_by_name('id').send_keys('xxmxm')
        self.driver.find_element_by_name('pw').send_keys('sdsad')
        # 로그인은 캡챠 문자로 인해 실패하였습니다..!
        self.driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()
        self.driver.implicitly_wait(30)
        self.driver.get('https://cafe.naver.com/unityhub?iframe_url=/AttendanceView.nhn%3Fsearch.clubid=26377973%26search.menuid=128')
        self.driver.implicitly_wait(30)
        self.driver.switch_to.frame('cafe_main') # iframe으로 되어 있기 때문
        self.driver.find_element_by_id('cmtinput').send_keys('출석합니당')
        self.driver.find_element_by_xpath('//*[@id="main-area"]/div[6]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/a/img')
        time.sleep(3) # 글 쓰는 시간 고려

    # 소멸자
    def __del__(self):
        # self.driver.close() 현재 실행 포커스된 영역을 종료
        self.driver.quit() # Selenium 전체 프로그램 종료
        print("Removed driver Object")

if __name__ == '__main__':
    # 객체 생성
    a = NcafeWriteAtt()
    # 시작 시간
    start_time = time.time()
    # 프로그램 측정
    a.writeAttendCheck()
    # 종료 시간
    print("---Total %s seconds ---" % (time.time() - start_time))
    # 객체 소멸
    del a