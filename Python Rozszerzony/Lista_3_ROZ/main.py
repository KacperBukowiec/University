import random

#print("s")


def pierwiastek(n):
    sum = 0
    i = 0
    while sum <= n:
        i += 1
        sum += 2 * i - 1
        # print(sum)
        # print(i)

    return i - 1


print(pierwiastek(8))


def uprosc_zdanie(tekst, dl_slowa, liczba_slow):
    tekst = tekst.split(" ")
    cut_tekst = []
    for wyraz in tekst:
        if len(wyraz) <= dl_slowa:
            cut_tekst.append(wyraz)
    if liczba_slow < len(cut_tekst):
        ile_usunac = len(cut_tekst) - liczba_slow
        for i in range(ile_usunac):
            cut_tekst.remove(random.choice(cut_tekst))
    return " ".join(cut_tekst)


t = "sdfds dsfsadf asdfasdfasdf sadfasdf dsfs f f sdf sadf sadf sdf asdf sddg e g rgeg"
print(uprosc_zdanie(t, 4, 5))


def kompresja(tekst):
    poprzedni_znak = ""
    counter = 1
    out = ""
    for znak in tekst:
        if znak == poprzedni_znak:
            counter+=1
        else:
            if counter > 1:
                out += str(counter) + poprzedni_znak
                counter = 1
            else:
                out += poprzedni_znak
        poprzedni_znak = znak
    if counter > 1:
        out += str(counter) + tekst[len(tekst)-1]
    else:
        out += tekst[len(tekst)-1]

    return out


t = "aaaatgherdghdgnhsssdddefwww"
print(kompresja(t))

def dekompresja(tekst):
    cyfry = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
    out = ""
    liczba = ""
    for znak in tekst:
        if znak in cyfry:
            liczba += znak
        else:
            if liczba != "":
                out += znak * int(liczba)
                liczba = ""
            else:
                out += znak
    return out
print(dekompresja(kompresja(t)))
























