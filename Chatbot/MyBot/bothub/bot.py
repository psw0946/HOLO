# -*- coding: utf-8 -*-

from __future__ import (absolute_import, division, print_function, unicode_literals)

from bothub_client.bot import BaseBot
from bothub_client.decorators import channel
from bothub_client.messages import Message
from .melon import Melon

class Bot(BaseBot):
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
        else:
            self.default_handler(event, context)


    def get_melon_chart(self, event, start, end):
        melon = Melon()
        melonChart = melon.get_topN(start, end)
        if end == 10:
            resMessage = "11~50위"
            message = Message(event).set_text(melonChart).add_quick_reply(resMessage)
        elif end == 50:
            resMessage = "51~100위"
            message = Message(event).set_text(melonChart).add_quick_reply(resMessage)
        else:
            message = Message(event).set_text(melonChart)
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
