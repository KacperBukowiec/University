ZMIENNE = []

class Formula:

    def oblicz(self, zmienne):
        pass

    def __str__(self):
        pass


class Zmienna(Formula):
    def __init__(self, nazwa):
        self.znak = nazwa
        if not (nazwa in ZMIENNE):
            ZMIENNE.append(nazwa)

    def __str__(self):
        return 'Zmienna("' + self.znak + '")'

    def oblicz(self, zmienne):
        return zmienne.get(self.znak)


class Nott(Formula):
    def __init__(self ,srodek):
        self.srodek =srodek

    def oblicz(self, zmienne):
        return not self.srodek.oblicz(zmienne)

    def __str__(self):
        return "Not(" + str(self.srodek) + ")"

class True_Class(Formula):
    def __str__(self):
        return "True()"

    def oblicz(self, zmienne):
        return True


class False_Class(Formula):
    def __str__(self):
        return "False()"

    def oblicz(self, zmienne):
        return False


class Dual(Formula):
    def __init__(self, lewy, prawy):
        self.lewy = lewy
        self.prawy = prawy


class Impl(Dual):
    def __init__(self, lewy, prawy):
        super().__init__(lewy, prawy)

    def __str__(self):
        return "Impl(" + str(self.lewy) + ", " + str(self.prawy) + ")"

    def oblicz(self, zmienne):
        return not (self.lewy.oblicz(zmienne) and not self.prawy.oblicz(zmienne))


class And(Dual):
    def __init__(self, lewy, prawy):
        super().__init__(lewy, prawy)

    def __str__(self):
        return "And(" + str(self.lewy) + ", " + str(self.prawy) + ")"

    def oblicz(self, zmienne):
        return self.lewy.oblicz(zmienne) and self.prawy.oblicz(zmienne)


class Or(Dual):
    def __init__(self, lewy, prawy):
        super().__init__(lewy, prawy)

    def __str__(self):
        return "Or(" + str(self.lewy) + ", " + str(self.prawy) + ")"

    def oblicz(self, zmienne):
        return self.lewy.oblicz(zmienne) or self.prawy.oblicz(zmienne)


# ef aktualizuj_zmienne(formula):


def is_tautology(formula):
    wartosci = {}
    for zmienna in ZMIENNE:
        wartosci[zmienna] = False

    # for i in range(len(ZMIENNE)):
    #    wartosciowania = list("{0:b}".format(i))

    for n in range(2 ** len(ZMIENNE)):
        wartosciowania = list("{0:b}".format(n))

        if len(wartosciowania) < len(ZMIENNE):
            wyrownane = ['0'] * (len(ZMIENNE) - len(wartosciowania))
            wyrownane.extend(wartosciowania)
            wartosciowania = wyrownane

        for j in range(len(ZMIENNE)):
            var = False
            if wartosciowania[j] == "1":
                var = True
            wartosci[ZMIENNE[j]] = var
        # print(dict)
        # print(wartosciowania)
        if not formula.oblicz(wartosci):
            return False
    return True


test = And(Or(Zmienna("y"), Zmienna("x")),True_Class())

print(is_tautology(test))
print(test.oblicz({"x": False, "y": True}))
print(test)

ZMIENNE = []



test2 = Impl(And(Impl(Nott(Zmienna("a")) ,Zmienna("b")) ,Impl(Nott(Zmienna("a")) ,Nott(Zmienna("b")))) ,Zmienna("a"))

# print(ZMIENNE)

print(is_tautology(test2))
