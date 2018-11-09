from bs4 import BeautifulSoup
import requests as req
import datetime
import re

class SchoolMenu:
    places = {'학생회관': 1, '기숙사': 3, '자하연': 4, '동원관': 6}

    def price(self, sign):
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

    def samsisekki(self, menu):
        morning = menu[2].text.strip()
        lunch = menu[4].text.strip()
        dinner = menu[6].text.strip()

        if morning == '':
            morning = '아침\n운영 안함\n'
        else:
            mornings = morning.split('\n')[0].split('/')
            morning = '아침\n'
            for m in mornings:
                p = self.price(m[0])
                name = re.sub('[(#*)]', '', m[1:])
                t = p + ' - ' + name + '\n'
                morning += t

        if lunch == '':
            lunch = '\n점심\n운영 안함\n'
        else:
            lunchs = lunch.split('\n')[0].split('/')
            lunch = '\n점심\n'
            for l in lunchs:
                p = self.price(l[0])
                name = re.sub('[(#*)]', '', l[1:])
                t = p + ' - ' + name + '\n'
                lunch += t

        if dinner == '':
            dinner = '\n저녁\n운영 안함\n'
        else:
            dinners = dinner.split('\n')[0].split('/')
            dinner = '\n저녁\n'
            for d in dinners:
                p = self.price(d[0])
                name = re.sub('[(#*)]', '', d[1:])
                t = p + ' - ' + name + '\n'
                dinner += t

        return [morning, lunch, dinner]

    def get_menu(self, place):
        menu_url = 'http://www.snuco.com/html/restaurant/restaurant_menu1.asp?date='
        today = datetime.datetime.today().strftime('%Y-%m-%d')
        # tomorrow = (datetime.datetime.today() + datetime.timedelta(days=1)).strftime('%Y-%m-%d')
        url = menu_url + today

        r = req.get(url)
        r.encoding = 'euc-kr'
        soup = BeautifulSoup(r.text, 'html.parser')

        menu_table = soup.select('div#Content table tr')
        menu_target = menu_table[self.places[place]].select('td')
        # student_center = menu_table[1].select('td')
        # dormitory = menu_table[3].select('td')
        # jahayeon = menu_table[4].select('td')
        # dongwon = menu_table[6].select('td')
        menu_list = self.samsisekki(menu_target)

        result = place + '\n\n' + menu_list[0] + menu_list[1] + menu_list[2]
        return result


if __name__ == '__main__':
    sm = SchoolMenu()
    print(sm.get_menu('학생회관'))
