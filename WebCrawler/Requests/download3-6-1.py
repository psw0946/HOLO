from selenium import webdriver

driver = webdriver.PhantomJS('C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/phantomjs/phantomjs')

driver.implicitly_wait(5) # 드라이버 불러오고 나서 암묵적으로 5초간 쉬어줌. (로딩이 빠르게 되면 그냥 넘어감)

driver.get('https://google.com')
driver.save_screenshot("C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/screenshot/website1.png")

driver.implicitly_wait(5)

driver.get('https://www.daum.net')
driver.save_screenshot("C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/screenshot/website2.png")

driver.quit()

print('스크린샷 완료')
