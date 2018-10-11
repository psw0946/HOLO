import telegram

my_token = '634196435:AAFZWvFjC5-wh1Cbh_rFqlqnyu7zIjwYvwA'
bot = telegram.Bot(token=my_token)

updates = bot.getUpdates() # 업데이트 내역 받아오기

for u in updates:
    print(u.message)

chat_id = bot.getUpdates()[-1].message.chat.id # 가장 최근에 온 메세지의 chat id를 가져옵니다

bot.sendMessage(chat_id = chat_id, text="저는 봇입니다.")