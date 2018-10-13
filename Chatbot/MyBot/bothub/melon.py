import requests as req
import simplejson as json
from bs4 import BeautifulSoup

class Melon:

    def get_top100(self):
        chart_url = 'https://www.melon.com/chart/index.htm#params%5Bidx%5D=1'
        header = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; Trident/7.0; rv:11.0) like Gecko'}
        r = req.get(chart_url, headers=header)
        soup = BeautifulSoup(r.text, 'html.parser')
        titles = soup.select('#lst50 div.ellipsis.rank01 a') + soup.select('#lst100 div.ellipsis.rank01 a')
        artists = soup.select('#lst50 div.ellipsis.rank02 a') + soup.select('#lst100 div.ellipsis.rank02 a')
        response = ""
        for i in range(100):
            res = (str(i+1) + "위: " + titles[i].text + " sung by " + artists[i].text + "\n")
            response += res
        return response

    def get_top10(self):
        chart_url = 'https://www.melon.com/chart/index.htm#params%5Bidx%5D=1'
        header = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; Trident/7.0; rv:11.0) like Gecko'}
        r = req.get(chart_url, headers=header)
        soup = BeautifulSoup(r.text, 'html.parser')
        titles = soup.select('#lst50 div.ellipsis.rank01 a') + soup.select('#lst100 div.ellipsis.rank01 a')
        artists = soup.select('#lst50 div.ellipsis.rank02 a') + soup.select('#lst100 div.ellipsis.rank02 a')
        response = ""
        for i in range(10):
            res = (str(i + 1) + "위: " + titles[i].text + " sung by " + artists[i].text + "\n")
            response += res
        return response

