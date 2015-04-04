"this are the import"
import os
import tornado.httpserver
import tornado.ioloop
import os.path
import tornado.options
import tornado.web

from tornado.options import define, options
define("port", default=8888, help="run on the given port", type=int)


class CLASSNAME(object):
    "this is the function"
    def __init__(self, size, name, filetype):
        if size > 1024 * 1024:
            self.size = "%0.2f mb" % (size / (1024.0 * 1024))
        elif size > 1024:
            self.size = "%0.2f kb" % (size / 1024.0)
        else:
            self.size = "%d b" % size
        self.name = name
        self.filetype = filetype

class MainHandler(tornado.web.RequestHandler):
    "this is the mainhandler"
    def get(self):
        rootdir = os.path.join(os.path.dirname(__file__), "static/songs")
        filenames = os.listdir(rootdir)

        playlist = self.get_argument('playlist', 'None')
        if playlist is not 'None':
            listnames = open(os.path.join(rootdir, playlist))
            filenames = listnames.read().splitlines()

        allfile = []
        for filename in filenames:
            # L.append(os.path.getsize(os.path.join(parent, filename)))
            allfile.append(
                CLASSNAME(
                    os.path.getsize(
                        os.path.join(rootdir, filename)
                        ), filename, os.path.splitext(filename)[1][1:]
                    )
                )

            #sorted(L.items(), lambda x, y: cmp(x[1], y[1]))
            #sorted(L,key = element)
            allfile.sort(key=lambda x: x.size)

        self.render("music.html", title="Music Viewer", files=allfile)

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
