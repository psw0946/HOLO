from selenium import webdriver
from selenium.webdriver.chrome.options import Options # CLI 환경에서 하기 위함
import time

chrome_options = Options()
chrome_options.add_argument("--headless") # CLI

driver = webdriver.Chrome(chrome_options=chrome_options, executable_path='C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
# driver = webdriver.Chrome('C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
# driver.set_window_size(1920, 1280) # 사이즈 지정 가능
# driver.implicitly_wait(5) # 드라이버 불러오고 나서 암묵적으로 5초간 쉬어줌. (로딩이 빠르게 되면 그냥 넘어감)

driver.get('https://google.com')
# time.sleep(5) # 5초간 대기
driver.save_screenshot("C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/screenshot/website1.png")

# driver.implicitly_wait(5)

driver.get('https://www.daum.net')
# time.sleep(5)
driver.save_screenshot("C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/screenshot/website2.png")

driver.quit()

print('스크린샷 완료')
