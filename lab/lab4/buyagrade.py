"'"
import os
import tornado.httpserver
import tornado.ioloop
import os.path
import string
import tornado.options
import tornado.web

from tornado.options import define, options
define("port", default=8888, help="run on the given port", type=int)

class MainHandler(tornado.web.RequestHandler):
    "'"
    def get(self):
        self.render("buyagrade.html")

class ContentHandler(tornado.web.RequestHandler):
    """docstring for ClassName"""
    def post(self):

        name = self.get_argument("name", '')
        section = self.get_argument("section", '')
        creditcard = self.get_argument("creditcard", '')
        credittype = self.get_argument("credittype", '')

        content = []
        content.append(name)
        content.append(section)
        content.append(creditcard)
        content.append(credittype)

        tag = 1
        if name == '' or section == '' or creditcard == '' or credittype == '':
            tag = 0
            self.render("no.html", change = "You didn't fill out the form completely.")

        if (len(creditcard) == 19):
            if creditcard[4] != '-' or creditcard[9] != '-' or creditcard[14] != '-':
                tag = 0
                self.render("no.html", change = "You didn't provide a valid card number.")

        if (len(creditcard) != 19 and creditcard.count('-') != 0):
            tag = 0
            self.render("no.html", change = "You didn't provide a valid card number.")

        newcard = creditcard.replace('-', '')
        if (len(newcard) != 16):
            tag = 0
            self.render("no.html", change = "You didn't provide a valid card number.")

        if (credittype == 'visa' and newcard[0] != '4'):
            tag = 0
            self.render("no.html", change = "You didn't provide a valid card number.")
        if (credittype == 'mastercard' and newcard[0] != '5'):
            tag = 0
            self.render("no.html", change = "You didn't provide a valid card number.")

        for i in range(0, 16):
            if (
                newcard[i] != '0' and newcard[i] != '1' and 
                newcard[i] != '2' and newcard[i] != '3' and 
                newcard[i] != '4' and newcard[i] != '5' and 
                newcard[i] != '6' and newcard[i] != '7' and 
                newcard[i] != '8' and newcard[i] != '9'
                ):
                tag = 0
                self.render("no.html", change = "You didn't provide a valid card number.")

        if (tag == 1):
            all = 0
            for i in range(0, 16):
                if i % 2 == 1:
                    all += int(newcard[i])
                else:
                    number = 2 * int(newcard[i])
                    if  number >= 10:
                        temp1 = number / 10
                        temp2 = number % 10
                        all += temp1 + temp2
                    else:
                        all += number
            if all % 10 == 0:
                store = open("suckers.txt", 'a')
                store.write(name + ';' + section + ';' + creditcard + ';' + credittype + '\n')
                store.close()

                openfile = open("suckers.txt", 'r')
                readfile = openfile.read().splitlines()
                openfile.close()
                self.render("yes.html", content = content, readfile = readfile)         
            else:
                self.render("no.html", change = "You didn't provide a valid card number.")



APPLICATION = tornado.web.Application(
    handlers= [
        (r'/', MainHandler),
        (r'/next',ContentHandler),
    ],
    static_path=os.path.join(os.path.dirname(__file__), "static"),
    debug=True
    )

if __name__ == "__main__":
    tornado.options.parse_command_line()
    HTTP_SEVER = tornado.httpserver.HTTPServer(APPLICATION)
    HTTP_SEVER.listen(options.port)
    tornado.ioloop.IOLoop.instance().start()
