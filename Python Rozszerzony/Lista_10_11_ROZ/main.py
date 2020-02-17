from sqlalchemy import *
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker, relationship
import tkinter as tk
from tkinter import ttk

'''
engine = create_engine('sqlite:///census.sqlite')
#connection = engine.connect()
metadata = MetaData()
#census = Table('census',metadata,autoload=True,autoload_with=engine)
census = Table('census', metadata, autoload=True, autoload_with=engine)
print(engine.table_names())
print(repr(census))
'''
#print(sqlalchemy.__version__)
engine = create_engine('sqlite:///films.db', echo = True)
Base = declarative_base()

#class Book(Base):
#    __tablename__ = 'books'
#    id = Column(Integer, primary_key=True)
#    title = Column(String)
#    author = Column(String)
#    year = Column(Integer)
#    borrowed_by = relationship("Borrow")
#
#class Friend(Base):
#    __tablename__ = 'friends'
#    id = Column(Integer, primary_key=True)
#    name = Column(String)
#    email = Column(String)
#    borrowed_book = relationship("Borrow")#

#class Borrow(Base):
#    __tablename__ = 'borrowed'
#    friend_id = Column(Integer, ForeignKey("friends.id"))
#    book_id = Column(Integer, ForeignKey("books.id"), unique=True)


class Film(Base):
    __tablename__ = 'films'
    id = Column(Integer, primary_key=True)
    title = Column(String)
    year = Column(Integer)
    director = Column(String)
    operator = Column(String)




Base.metadata.create_all(bind=engine)
Session = sessionmaker(bind=engine)
session = Session()

command = "ad"
if command=="delete":
    obj = session.query(Film).filter_by(id=2).one()
    session.delete(obj)
#elif command== "add":
#    add_film(10,"y",3,"d","o")

#edit
#ob = session.query(Film).filter_by(id=6).one()
#ob.id+=1
session.commit()








session.close()
class App():
    def __init__(self):

        self.scores = tk.Tk()

        self.idd = tk.StringVar()
        self.title = tk.StringVar()
        self.year = tk.StringVar()
        self.director = tk.StringVar()
        self.operator = tk.StringVar()

        #self.record = Film()
        #self.record.id = tk.StringVar()
        label = tk.Label(self.scores, text="Films", font=("Arial", 30)).grid(row=0, columnspan=3)
        # create Treeview with 3 columns
        cols = ('Id', 'Title', 'Year', 'Director', 'Operator')
        self.listBox = ttk.Treeview(self.scores, columns=cols, show='headings')
        # set column headings
        for col in cols:
            self.listBox.heading(col, text=col)
        self.listBox.grid(row=1, column=0, columnspan=2)

        self.show()
        showScores = tk.Button(self.scores, text="Show scores", width=15, command=self.show).grid(row=4, column=0)
        addScores = tk.Button(self.scores, text="add", width=15, command=self.open_new_movie_window).grid(row=4, column=3)

        closeButton = tk.Button(self.scores, text="Close", width=15, command=exit).grid(row=4, column=1)

        self.listBox.bind("<<TreeviewSelect>>", self.open_edit_movie_window)

        self.scores.mainloop()


    def show(self):
        self.listBox.delete(*self.listBox.get_children())
        # tempList = [['Jim', '0.33'], ['Dave', '0.67'], ['James', '0.67'], ['Eden', '0.5']]
        # tempList.sort(key=lambda e: e[1], reverse=True)
        films = session.query(Film).all()
        for b in films:
            self.listBox.insert("", "end", values=(b.id, b.title, b.year, b.director, b.operator))
            # print(b.id)
        # for i, (name, score) in enumerate(tempList, start=1):
        #    listBox.insert("", "end", values=(i, name, score))
        #    print(listBox)

    def add_movie(self):
        print(self.idd.get())
        #session.add(self.record)
        self.add_film(self.idd.get(),self.title.get(),self.year.get(),self.director.get(),self.operator.get())
        #session.commit()
        self.show()
        print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!2")

    def open_new_movie_window(self):
        t = tk.Toplevel(self.scores)
        t.title("Add new movie")
        content = ttk.Frame(t)
        id_lbl = ttk.Label(content, text="Id")
        title_lbl = ttk.Label(content, text="Title")
        year_lbl = ttk.Label(content, text="Year of production")
        director_lbl = ttk.Label(content, text="Director")
        operator_lbl = ttk.Label(content, text="Operator")
        ida = ttk.Entry(content, textvariable=self.idd)
        title = ttk.Entry(content, textvariable=self.title)
        year = ttk.Entry(content, textvariable=self.year)
        director = ttk.Entry(content, textvariable=self.director)
        operator = ttk.Entry(content, textvariable=self.operator)
        submit_btn = ttk.Button(content, command=self.add_movie, text="Submit")
        cancel_btn = ttk.Button(content, command=t.destroy, text="Cancel")

        content.grid(column=0, row=0, padx=5, pady=5)
        id_lbl.grid(column=0, row=5, padx=5, pady=5)
        ida.grid(column=1, row=5, padx=5, pady=5)
        title_lbl.grid(column=0, row=0, padx=5, pady=5)
        title.grid(column=1, row=0, padx=5, pady=5)
        year_lbl.grid(column=0, row=1, padx=5, pady=5)
        year.grid(column=1, row=1, padx=5, pady=5)
        director_lbl.grid(column=0, row=2, padx=5, pady=5)
        director.grid(column=1, row=2, padx=5, pady=5)
        operator_lbl.grid(column=0, row=3, padx=5, pady=5)
        operator.grid(column=1, row=3, padx=5, pady=5)
        submit_btn.grid(column=0, row=4, padx=5, pady=5)
        cancel_btn.grid(column=1, row=4, padx=5, pady=5)

    def add_film(self,id, title, year, director, operator):
        film = Film()
        film.id = id
        film.title = title
        film.director = director
        film.year = year
        film.operator = operator
        session.add(film)
        session.commit()
        #show()
        print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1")

    def open_edit_movie_window(self, *args):
        t = tk.Toplevel(self.scores)
        t.title("Edit movie")

        content = ttk.Frame(t)
        id_lbl = ttk.Label(content, text="Id")
        title_lbl = ttk.Label(content, text="Title")
        year_lbl = ttk.Label(content, text="Year of production")
        director_lbl = ttk.Label(content, text="Director")
        operator_lbl = ttk.Label(content, text="Operator")

        id = ttk.Entry(content, textvariable=self.idd)
        title = ttk.Entry(content, textvariable=self.title)
        year = ttk.Entry(content, textvariable=self.year)
        director = ttk.Entry(content, textvariable=self.director)
        operator = ttk.Entry(content, textvariable=self.operator)
        item = self.listBox.selection()
        vals = self.listBox.item(item)['values']
        self.idd.set(vals[0])
        self.title.set(vals[1])
        self.year.set(vals[2])
        self.director.set(vals[3])
        self.operator.set(vals[4])

        submit_btn = ttk.Button(content, command=lambda:[self.edit_movie(),t.destroy()], text="Submit")
        cancel_btn = ttk.Button(content, command=t.destroy, text="Cancel")

        content.grid(column=0, row=0, padx=5, pady=5)
        id_lbl.grid(column=0,row=5, padx=5, pady=5)
        id.grid(column=1, row=5, padx=5, pady=5)
        title_lbl.grid(column=0, row=0, padx=5, pady=5)
        title.grid(column=1, row=0, padx=5, pady=5)
        year_lbl.grid(column=0, row=1, padx=5, pady=5)
        year.grid(column=1, row=1, padx=5, pady=5)
        director_lbl.grid(column=0, row=2, padx=5, pady=5)
        director.grid(column=1, row=2, padx=5, pady=5)
        operator_lbl.grid(column=0, row=3, padx=5, pady=5)
        operator.grid(column=1, row=3, padx=5, pady=5)

        submit_btn.grid(column=0, row=4, padx=5, pady=5)
        cancel_btn.grid(column=1, row=4, padx=5, pady=5)

    def clear_vars(self):

        self.idd.set("")
        self.title.set("")
        self.year.set("")
        self.director.set("")
        self.operator.set("")

    def edit_movie(self):
        #movie = get_movie_by_id(self.tree.item(self.tree.selection())['text'])
        #movie = session.query(Film).filter_by(self.listBox.item(self.listBox.selection())['text']).first()

        movie = session.query(Film).filter_by(id=int(self.idd.get())).one()

        movie.title = self.title.get()
        movie.year = self.year.get()
        movie.director = self.director.get()
        movie.operator = self.operator.get()
        #self.update_tv(self.listBox.selection(), movie)
        self.listBox.item(self.listBox.selection(), text=movie.id, values=(self.idd.get(), movie.title, movie.year, movie.director, movie.operator))
        self.clear_vars()
        session.commit()


if __name__ == '__main__':
    app = App()