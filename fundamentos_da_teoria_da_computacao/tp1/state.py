class State():
    def __init__(self, identity):
        self.identity = identity 
        self.final = False
        self.init = False
        self.transitions = []
        self.loop_values = []

    def setFinal(self):
        self.final = True
        
    def isFinal(self):
        return self.final
        
    def hasThisID(self, test_idenity):
        if test_idenity == self.identity:
            return True
        else:
            return False

    def setTransition(self, value, next_state):
        self.transitions.append((value, next_state))
        if next_state == self.identity:
            self.loop_values.append(value)

    def getTransitions(self):
        return self.transitions
    
    def getValueFor(self, next_state):
        values = []
        for transition in self.transitions:
            if transition[1] == next_state:
                values.append(transition[0])
        return values

    def getLoops(self):
        return self.loop_values