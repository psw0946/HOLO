from selenium import webdriver
from selenium.webdriver.chrome.options import Options # CLI 환경에서 하기 위함
import time

# chrome_options = Options()
# chrome_options.add_argument("--headless") # CLI

# driver = webdriver.Chrome(chrome_options=chrome_options, executable_path='C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
driver = webdriver.Chrome('C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
driver.set_window_size(1920, 1280) # 사이즈 지정 가능
driver.implicitly_wait(5) # 드라이버 불러오고 나서 암묵적으로 5초간 쉬어줌. (로딩이 빠르게 되면 그냥 넘어감)

driver.get('https://www.inflearn.com/wp-login.php?redirect_to=https%3A%2F%2Fwww.inflearn.com%2F')
time.sleep(7)
driver.implicitly_wait(3)

driver.find_element_by_name('log').send_keys('id') # name=log 인 곳에 id 라고 입력
driver.implicitly_wait(1)
driver.find_element_by_name('pwd').send_keys('pw')
driver.implicitly_wait(1)
driver.find_element_by_xpath('//*[@id="wp-submit"]').click() # xpath는 크롬 개발자 도구에서 복사하면 됨

driver.quit()
