import numpy as np
import matplotlib.pyplot

'''
class Board(object):
    def __init__(self, size):
        self.state = np.random.randint(2, size=size)
        print(type(self.state))
        self.engine = Engine(self)

    def animate(self):
        matplotlib.pyplot.title("Gra w rzyć(ie)")
        im = matplotlib.pyplot.imshow(self.state)
        while True:
            im.set_data(self.state)
            self.engine.applyRules()
            matplotlib.pyplot.pause(0.01)


class Engine(object):
    def __init__(self, board):
        self.state = board.state

    def countNeighbors(self):
        state = self.state
        n = (state[0:-2, 0:-2] + state[0:-2, 1:-1] + state[0:-2, 2:] +
             state[1:-1, 0:-2] + state[1:-1, 2:] + state[2:, 0:-2] +
             state[2:, 1:-1] + state[2:, 2:])
        print(n)

        print(state)
        return n

    def applyRules(self):
        n = self.countNeighbors()
        state = self.state
        birth = (n == 3) & (state[1:-1, 1:-1] == 0)
        survive = ((n == 2) | (n == 3)) & (state[1:-1, 1:-1] == 1)
        state[...] = 0
        state[1:-1, 1:-1][birth | survive] = 1
        return state

board = Board((10, 10))
board.animate()
'''


state = np.random.randint(2, size=(100, 100))
matplotlib.pyplot.title("Gra w rzyć(ie)")
im = matplotlib.pyplot.imshow(state)
while True:
    im.set_data(state)
    n = (state[0:-2, 0:-2] + state[0:-2, 1:-1] + state[0:-2, 2:] +
         state[1:-1, 0:-2] + state[1:-1, 2:] + state[2:, 0:-2] +
         state[2:, 1:-1] + state[2:, 2:])
    state = state
    birth = (n == 3) & (state[1:-1, 1:-1] == 0)
    survive = ((n == 2) | (n == 3)) & (state[1:-1, 1:-1] == 1)
    state[...] = 0
    state[1:-1, 1:-1][birth | survive] = 1
    matplotlib.pyplot.pause(0.01)
