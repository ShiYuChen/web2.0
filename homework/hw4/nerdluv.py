"'"
import os
import os.path
import string
import re

import tornado.web
import tornado.httpserver
import tornado.ioloop
import tornado.options

from tornado.options import define, options
define("port", default=8888, help="run on the given port", type=int)

p = re.compile(r'^[1-9]{1}[0-9]{1}|[0]{1}[1-9]{1}$')

class person(object):
    """docstring for person"""
    def __init__(self, name, gender, age, personality, os, seeking, minage, maxage, rating):
        super(person, self).__init__()
        self.name = name
        self.gender = gender
        self.age = age
        self.personality = personality
        self.os = os
        self.seeking = seeking
        self.minage = minage
        self.maxage = maxage
        self.rating = rating


class BaseHandler(tornado.web.RequestHandler):
    def get_current_user(self):
        return self.get_secure_cookie("name")

class MessageHandler(tornado.web.RequestHandler):
    """docstring for MessageHandler"""
    def get(self, input):
        self.write(input)


class MainHandler(BaseHandler):
    "'"
    def get(self):
        if not self.current_user:
            self.redirect("/login")
            return
        name = tornado.escape.xhtml_escape(self.current_user)
        gender = ''
        age = ''
        personality = ''
        os = ''
        seeking = ''
        minage = ''
        maxage = ''
        with open("singles.txt", "r+") as content:
            users = content.read().splitlines()
            for user in users:
                user = user.split(',')
                if user[0] == name:
                    gender = user[1]
                    age = user[2]
                    personality = user[3]
                    os = user[4]
                    seeking = user[5]
                    minage = user[6]
                    maxage = user[7]

            persons = []
            for user in users:
                count = 0
                user = user.split(',')
                if (user[1] in seeking and user[0] != name):
                    if (user[2] >= minage and user[2] <= maxage):
                        count += 1
                    for i in user[3]:
                        if (i in personality):
                            count += 1
                    if (user[4] == os):
                        count += 2
                if (count >= 3):
                    persons.append(person(user[0],user[1],user[2],user[3],user[4],user[5],user[6],user[7], count))
        self.render("results.html", persons = persons, user = name)

class LoginHandler(BaseHandler):
    """docstring for ClassName"""
    def get(self):
        self.render('index.html')

    def post(self):
        name = self.get_argument("name",'')
        gender = self.get_argument("gender",'')
        age = self.get_argument("age",'')
        personality = self.get_argument("personality",'')
        os = self.get_argument("os",'')
        seeking = self.get_argument("seeking1",'') + self.get_argument("seeking2",'')
        minage = self.get_argument("minage",'')
        maxage = self.get_argument("maxage",'')

        tag = 1
        if (name == '') or (gender == '') or (age == '') or (personality == '') or (os == '') or (seeking == '') or (minage == '') or (maxage == ''):
            tag = 0
            self.render("error.html", errormessage = "you have blank(s) empty!")
        if (not(p.match(age)) or not(p.match(minage)) or not(p.match(maxage)) or ((int(age) <= 0) or (int(age) > 99)) or ((int(minage) <= 0) or (int(minage) > 99)) or ((int(maxage) <= 0) or (int(maxage) > 99)) or (int(maxage) < int(minage))):
            tag = 0
            self.render("error.html", errormessage = "the type of age is error!")
        if (((personality[0] != 'I') and (personality[0] != 'E')) or ((personality[1] != 'N') and (personality[1] != 'S')) or ((personality[2] != 'F') and (personality[2] != 'T')) or ((personality[3] != 'J') and (personality[3] != 'P'))):
            tag = 0
            self.render("error.html", errormessage = "the type of personality is error!")

        if (tag == 1):
            self.set_secure_cookie("name", name)
            with open("singles.txt", "a") as content:
                content.write(name + ',' + gender + ',' + age + ',' + personality + ',' + os + ',' + seeking + ',' + minage + ',' + maxage + '\n')
            self.redirect('/')

if __name__ == "__main__":
    tornado.options.parse_command_line()
    APPLICATION = tornado.web.Application(
    handlers= [
        (r'/', MainHandler),
        (r'/login',LoginHandler),
        (r'/u/(\w+.*\w+,\w,\d+,\w+,\w+,\w,\d+,\d+)',MessageHandler),
    ],
    static_path=os.path.join(os.path.dirname(__file__), "static"),
    template_path=os.path.join(os.path.dirname(__file__), "template"),
    debug=True,
    cookie_secret="610ETzKXQAGaYdkL5gEmGeJJFuYh7EQnp2XdTP1o/Vo=",
    )
    HTTP_SEVER = tornado.httpserver.HTTPServer(APPLICATION)
    HTTP_SEVER.listen(options.port)
    tornado.ioloop.IOLoop.instance().start()
