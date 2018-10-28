from bs4 import BeautifulSoup
import requests as req
import simplejson as json

class Movie:

    def get_top10(self):
        response = "네이버 영화 예매율 순위 TOP10\n"

        r = req.get('https://movie.naver.com/movie/sdb/rank/rreserve.nhn')
        soup = BeautifulSoup(r.text, 'html.parser')

        rankingTable = soup.select('table.list_ranking > tbody > tr')[1:-1]

        for i, rank in enumerate(rankingTable, 1):
            title = rank.select_one('div.tit4').text.strip()
            reserve = rank.select_one('td.reserve_per.ar').text.strip()
            res = str(i) + "위: " + title + " / " + reserve + "\n"
            response += res

        response += "\n국내 박스오피스 랭킹 TOP10\n"

        r = req.get('https://movie.naver.com/movie/sdb/rank/rboxoffice.nhn')
        soup = BeautifulSoup(r.text, 'html.parser')

        names = soup.select('div.tit1 > a')

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