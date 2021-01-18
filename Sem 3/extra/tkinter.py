from tkinter import *
from tkinter.ttk import *


class Application(Frame):
    def __init__(self , master = None):
        super.__init__(master)
        self.master = master

root = Tk()

app = Application(master=root)

app.mainloop()