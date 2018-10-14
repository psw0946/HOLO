import requests as req
import simplejson as json
from bs4 import BeautifulSoup

class Melon:

    def get_topN(self, start, end):
        chart_url = 'https://www.melon.com/chart/index.htm#params%5Bidx%5D=1'
        header = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; Trident/7.0; rv:11.0) like Gecko'}
        r = req.get(chart_url, headers=header)
        soup = BeautifulSoup(r.text, 'html.parser')
        self.titles = soup.select('#lst50 div.ellipsis.rank01 a') + soup.select('#lst100 div.ellipsis.rank01 a')
        self.artists = soup.select('#lst50 div.ellipsis.rank02 > span') + soup.select('#lst100 div.ellipsis.rank02 > span')
        response = "실시간 멜론 차트 TOP" + str(start) + "~" + str(end) + "\n"
        for i in range(start - 1, end):
            artist = []
            for j in self.artists[i].select('a'):
                artist.append(j.text)
            singers = ", ".join(artist)
            res = (str(i + 1) + "위: " + self.titles[i].text + " sung by " + singers + "\n")
            response += res
        return response

