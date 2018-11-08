from bs4 import BeautifulSoup
import requests as req
import datetime
import re

def price(sign):
    if sign == 'ⓐ':
        return '1000원'
    elif sign == 'ⓑ':
        return '2000원'
    elif sign == 'ⓒ':
        return '2500원'
    elif sign == 'ⓓ':
        return '3000원'
    elif sign == 'ⓔ':
        return '3500원'
    elif sign == 'ⓕ':
        return '4000원'

def samsisekki(menu):
    morning = menu[2].text
    lunch = menu[4].text
    dinner = menu[6].text

    if morning == '':
        morning = '운영 안함\n'
    else:
        mornings = morning.split('\n')[0].split('/')
        morning = '아침\n'
        for m in mornings:
            p = price(m[0])
            name = re.sub('[(#)]', '', m[1:])
            t = p + ' - ' + name + '\n'
            morning += t

    if lunch == '':
        lunch = '\n운영 안함\n'
    else:
        lunchs = lunch.split('\n')[0].split('/')
        lunch = '\n점심\n'
        for l in lunchs:
            p = price(l[0])
            name = re.sub('[(#)]', '', l[1:])
            t = p + ' - ' + name + '\n'
            lunch += t

    if dinner == '':
        dinner = '\n운영 안함\n'
    else:
        dinners = dinner.split('\n')[0].split('/')
        dinner = '\n저녁\n'
        for d in dinners:
            p = price(d[0])
            name = re.sub('[(#)]', '', d[1:])
            t = p + ' - ' + name + '\n'
            dinner += t

    return [morning, lunch, dinner]


menu_url = 'http://www.snuco.com/html/restaurant/restaurant_menu1.asp?date='
today = datetime.datetime.today().strftime('%Y-%m-%d')
tomorrow = (datetime.datetime.today() + datetime.timedelta(days=1)).strftime('%Y-%m-%d')
url = menu_url + today

r = req.get(url)
r.encoding = 'euc-kr'
soup = BeautifulSoup(r.text, 'html.parser')

menu_table = soup.select('div#Content table tr')

student_center = menu_table[1].select('td')
student_center_menu = samsisekki(student_center)
print(student_center_menu[0], student_center_menu[1])

'''
morning = student_center[2].text
mornings = morning.split('/')
pr = ''
for m in mornings:
    p = price(m[0])
    name = re.sub('[(#)]', '', m[1:])
    t = p + ' - ' + name + '\n'
    pr += t
print(pr)
lunch = student_center[4].text.split('\n')[0]
dinner = student_center[6].text
'''
