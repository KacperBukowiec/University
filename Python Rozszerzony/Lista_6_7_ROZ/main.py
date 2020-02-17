import threading
import time
import urllib.request
import difflib

total_distance = 0
lock = threading.Lock()

class runner(threading.Thread):
    def __init__(self, start_number, adress):
        self.number = start_number
        self.url = adress
        threading.Thread.__init__(self)

    def run(self):

        try:
            response = urllib.request.urlopen(self.url)
        except:
            return
        #response = urllib.request.urlopen(self.url)
        content = response.readlines()
        for b in range(len(content)):
            content[b]=str(content[b])
        while True:
            # update
            try:
                new_content = urllib.request.urlopen(self.url).readlines()
            except:
                return
            for a in range(len(new_content)):
                new_content[a] = str(new_content[a])
            if new_content != content:

                diff = difflib.Differ().compare(content, new_content)
                changes = [l for l in diff if l.startswith('+ ') or l.startswith('- ')]
                lock.acquire()
                print("nastąpiłą zmiana w " + self.url)
                for c in changes:
                    print(c)
                lock.release()
                content = new_content


            print("thread: {0}".format(self.number))
            time.sleep(10)


list_of_url = ["https://usosweb.uni.wroc.pl/kontroler.php?_action=news/default","https://usosweb.uni.wroc.pl/kontroler.php?_action=news/default","sdfsdfs"]
numer=0
lisa = []
for i in list_of_url:
    lisa.append(runner(numer,i))
    numer +=1

for i in lisa:
    i.start()

for i in lisa:
    i.join()
# r2 = runner(2, "http://www.google.de")

#    r1.start()
# r2.start()

#    r1.join()
# r2.join()

#print("kuniec , dystans {0}".format(total_distance))