# -*- coding: utf-8 -*-

from __future__ import (absolute_import, division, print_function, unicode_literals)

from bothub_client.bot import BaseBot
from bothub_client.decorators import channel
from bothub_client.messages import Message
from .melon import Melon
from .movie import Movie
from .schoolmenu import SchoolMenu

class Bot(BaseBot):
    errorMsg = '오류남ㅋ'
    """Represent a Bot logic which interacts with a user.

    BaseBot superclass have methods belows:

    * Send message
      * self.send_message(message, chat_id=None, channel=None)
    * Data Storage
      * self.set_project_data(data)
      * self.get_project_data()
      * self.set_user_data(data, user_id=None, channel=None)
      * self.get_user_data(user_id=None, channel=None)
    * Channel Handler
      from bothub_client.decorators import channel
      @channel('<channel_name>')
      def channel_handler(self, event, context):
        # Handle a specific channel message
    * Command Handler
      from bothub_client.decorators import command
      @command('<command_name>')
      def command_handler(self, event, context, args):
          # Handle a command('/<command_name>')
    * Intent Handler
      from bothub_client.decorators import intent
      @intent('<intent_id>')
      def intent_result_handler(self, event, context, answers):
          # Handle a intent result
          # answers is a dict and contains intent's input data
            {
              "<intent slot id>" : <entered slot value>
              ...
            }
    """
    def handle_message(self, event, context):
        message = event.get('content')

        if message == '음악순위':
            self.get_melon_chart(event, 1, 10)
        elif message == '11~50위':
            self.get_melon_chart(event, 11, 50)
        elif message == '51~100위':
            self.get_melon_chart(event, 51, 100)
        elif message == '영화순위':
            self.get_movie_chart(event)
        elif message == '학식':
            self.get_menu_request(event)
        elif message == '학생회관':
            self.get_menu(event, '학생회관')
        elif message == '동원관':
            self.get_menu(event, '동원관')
        elif message == '자하연':
            self.get_menu(event, '자하연')
        elif message == '기숙사':
            self.get_menu(event, '기숙사')
        else:
            self.default_handler(event, context)

    def get_menu(self, event, place):
        school_menu = SchoolMenu()
        try:
            res = school_menu.get_menu(place)
            message = Message(event).set_text(res)
        except:
            message = Message(event).set_text(self.errorMsg)
        self.send_message(message)

    def get_menu_request(self, event):
        res = "장소를 선택해주세요."
        message = Message(event).set_text(res).add_quick_reply('학생회관').add_quick_reply('기숙사').add_quick_reply(
            '자하연').add_quick_reply('동원관')
        self.send_message(message)

    def get_melon_chart(self, event, start, end):
        melon = Melon()
        try:
            melonChart = melon.get_topN(start, end)
            if end == 10:
                resMessage = "11~50위"
                message = Message(event).set_text(melonChart).add_quick_reply(resMessage)
            elif end == 50:
                resMessage = "51~100위"
                message = Message(event).set_text(melonChart).add_quick_reply(resMessage)
            else:
                message = Message(event).set_text(melonChart)
        except:
            message = Message(event).set_text(self.errorMsg)
        self.send_message(message)

    def get_movie_chart(self, event):
        movie = Movie()
        try:
            movieChart = movie.get_top10()
            message = Message(event).set_text(movieChart)
        except:
            message = Message(event).set_text(self.errorMsg)
        self.send_message(message)

    @channel()
    def default_handler(self, event, context):
        """Handle a message received

        event is a dict and contains trigger info.

        {
           "trigger": "webhook",
           "channel": "<name>",
           "sender": {
              "id": "<chat_id>",
              "name": "<nickname>"
           },
           "content": "<message content>",
           "raw_data": <unmodified data itself webhook received>
        }
        """
        self.send_message('Echo: {}'.format(event['content']))
