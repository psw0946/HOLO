from bs4 import BeautifulSoup
import requests as req
import simplejson as json

class Movie:

    def get_top10(self):
        response = "네이버 영화 예매 순위 TOP10\n"

        r = req.get('https://movie.naver.com/movie/sdb/rank/rreserve.nhn')
        soup = BeautifulSoup(r.text, 'html.parser')

        names = soup.select('div.tit4 > a')

        for i, name in enumerate(names, 1):
            movie_name = name.text
            movie_link = 'https://movie.naver.com' + name.get('href')
            nr = req.get(movie_link)
            nsoup = BeautifulSoup(nr.text, 'html.parser')
            score = nsoup.select_one('a#actualPointPersentBasic > div.star_score > span.st_off > span.st_on').text
            res = str(i) + "위: " + movie_name + " / " + score + "\n"
            # print(str(i) + "위: " + movie_name + " / " + score)
            response += res

        return response
