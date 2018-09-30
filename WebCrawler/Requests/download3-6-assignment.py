from selenium import webdriver
import time

driver = webdriver.Chrome('C:/Users/PSW/Desktop/HOLO/WebCrawler/Requests/webdriver/chrome/chromedriver')
driver.set_window_size(1920, 1280) # 사이즈 지정 가능
driver.implicitly_wait(5) # 드라이버 불러오고 나서 암묵적으로 5초간 쉬어줌. (로딩이 빠르게 되면 그냥 넘어감)

driver.get('http://www.encar.com/index.do#')
driver.implicitly_wait(2)

driver.find_element_by_xpath('//*[@id="manufact"]/a').click()
driver.implicitly_wait(1)
driver.find_element_by_xpath('//*[@id="manufactListText"]/ul[2]/li[1]/a').click()
driver.implicitly_wait(1)
driver.find_element_by_xpath('//*[@id="seriesItemList"]/li[5]/a').click()
driver.implicitly_wait(1)
driver.find_element_by_xpath('//*[@id="mdlItemList"]/li[2]/a').click()
driver.implicitly_wait(1)
driver.find_element_by_xpath('//*[@id="indexSch1"]/div[1]/a').click()
driver.implicitly_wait(1)
driver.find_element_by_xpath('//*[@id="sr_photo"]/li/a/span[1]').click()
driver.implicitly_wait(1)
time.sleep(2)

driver.quit()
