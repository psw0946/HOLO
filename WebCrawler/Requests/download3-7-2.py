from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time

class NcafeMemberExr:
    # 초기화 실행(webdriver 설정)
    def __init__(self):
        chrome_options = Options() # 어차피 한 번만 쓰기 때문에 굳이 self를 붙여서 리소스를 낭비할 건 없다!
        chrome_options.add_argument("--headless") # CLI (User-agent)
        self.driver = webdriver.Chrome(chrome_options=chrome_options, executable_path='C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
        self.driver.implicitly_wait(5)

    # 네이버 카페 회원 1페이지 정보 리스트 추출
    def getMemberList(self):
        self.driver.get('https://www.naver.com')
        self.driver.find_element_by_xpath('//*[@id="account"]/div/a/i').click()
        self.driver.find_element_by_name('id').send_keys('xxmxm')
        self.driver.find_element_by_name('pw').send_keys('sdsad')
        self.driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()
        # 로그인은 캡챠 문자로 인해 실패하였습니다..!
        self.driver.get('http://cafe.naver.com/CafeMemberView.nhn?m=view&clubid=19756449')
        self.driver.implicitly_wait(30)
        self.driver.switch_to.frame('cafe_main') # iframe으로 되어 있기 때문
        self.driver.implicitly_wait(30)
        self.driver.switch_to.frame('innerframe') # frame이 중첩되어 있음!
        soup = BeautifulSoup(self.driver.page_source, 'html.parser')
        return soup.select('div.mem_wrap > div.mem_list div.ellipsis.m-tcol-c')

    # 네이버 회원 리스트 출력 및 저장
    def printMemberList(self, list):
        f = open("C:/memberList.txt", "wt")
        for i in list:
            f.write(i.string.strip() + "\n") # 공백 있으면 제거하라고 .strip()
            print(i.string.strip())
        f.close()

    # 소멸자
    def __del__(self):
        # self.driver.close() 현재 실행 포커스된 영역을 종료
        self.driver.quit() # Selenium 전체 프로그램 종료
        print("Removed driver Object")

if __name__ == '__main__':
    # 객체 생성
    a = NcafeMemberExr()
    # 시작 시간
    start_time = time.time()
    # 프로그램 측정
    a.printMemberList(a.getMemberList())
    # 종료 시간
    print("---Total %s seconds ---" % (time.time() - start_time))
    # 객체 소멸
    del a