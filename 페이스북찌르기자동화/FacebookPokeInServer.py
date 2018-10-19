from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time
import datetime

chrome_options = webdriver.ChromeOptions()
prefs = {"profile.default_content_setting_values.notifications": 2}
chrome_options.add_experimental_option("prefs", prefs)
chrome_options.add_argument("--headless")
chrome_options.add_argument("--no-sandbox")
chrome_options.add_argument("--disable-dev-shm-usage")
chrome_options.add_argument("--disable-gpu")
chrome_options.add_argument("--disable-extensions")

# service_log_path = "{}/chromedriver.log".format("/home/ubuntu")
# service_args = ['--verbose']

# 요청 URL
URL = 'https://www.facebook.com/login'

# webdriver
driver = webdriver.Chrome(chrome_options=chrome_options, executable_path='...???...')
driver.implicitly_wait(5)
driver.get(URL)
driver.implicitly_wait(10)

driver.find_element_by_id('email').send_keys('ID~~~~')
driver.find_element_by_id('pass').send_keys('PASSWORD~~~~')

driver.find_element_by_id('loginbutton').click()
driver.implicitly_wait(10)

# 찌르기 페이지로
driver.get('https://www.facebook.com/pokes/?notif_id=1539875742764253&notif_t=poke')
driver.implicitly_wait(10)
soup = BeautifulSoup(driver.page_source, 'html.parser')
PokeContainer = soup.select('div._4-u2._xct._4-u8')[0].select('div._xco') # 찌르기 리스트
# print(PokeContainer)
poke = False
for container in PokeContainer:
    containerID = container.attrs['id']
    testText = 'div#' + containerID + ' ' + 'div._6a > a._42ft._4jy0._4jy3._4jy1.selected._51sy'
    # testText = soup.select_one('div#' + containerID + ' ' + 'div._6a > a._42ft._4jy0._4jy3._4jy1.selected._51sy').text
    driver.find_element_by_css_selector(testText).click()
    poke = True
    driver.implicitly_wait(3)

# 로그 만들기
now = datetime.datetime.now()
nowDate = now.strftime('%Y-%m-%d %H:%M:%S')
if poke:
    print(nowDate, 'Poke')
else:
    print(nowDate, 'No Poke')
time.sleep(2)
driver.quit()
