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
        movie = self.get_argument('movie', 'tmnt')
        if movie is not 'tmnt':
            movie = movie;

        rootdir = os.path.join(os.path.dirname(__file__), "static")
        filedir = os.path.join(rootdir, movie)
        infocontent = open(os.path.join(filedir, "info.txt"))
        inforead = infocontent.read().splitlines()
        digit = string.atoi(inforead[2])

        gencontent = open(os.path.join(filedir, "generaloverview.txt"))
        genread = gencontent.read().splitlines()
        title = []
        text = []
        for gen in genread:
            temp = gen.split(':')
            title.append(temp[0])
            text.append(temp[1])
        length1 = len(title)

        filenames = os.listdir(filedir)
        files = []
        for filename in filenames:
            if filename[0:6] == "review":
                revcontent = open(os.path.join(filedir, filename))
                files.append(revcontent.read().splitlines())
        length2 = len(files)

        self.render("movie.html", movie = movie, inforead = inforead, digit = digit, title = title, text = text, length1 = length1, files = files, length2 = length2)

APPLICATION = tornado.web.Application(
    handlers=[(r'/', MainHandler)],
    static_path=os.path.join(os.path.dirname(__file__), "static"),
    debug=True
    )

if __name__ == "__main__":
    tornado.options.parse_command_line()
    HTTP_SEVER = tornado.httpserver.HTTPServer(APPLICATION)
    HTTP_SEVER.listen(options.port)
    tornado.ioloop.IOLoop.instance().start()
