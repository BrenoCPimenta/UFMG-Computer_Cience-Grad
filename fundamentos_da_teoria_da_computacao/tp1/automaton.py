from state import State

class Automaton():
    def __init__(self, all_states, values, initial_states, final_states, transitions):
        self.states = []
        self.initial_states = initial_states

        #Creating States
        for state_id in all_states:
            this_state = State(state_id)
            if state_id in final_states:
                this_state.setFinal()
            for transition in transitions:
                if transition[0] ==  state_id:
                    this_state.setTransition(
                        value=transition[1],
                        next_state=transition[2])
            self.states.append(this_state)


    def _getState(self, identity):
        for state in self.states:
            if state.hasThisID(identity):
                return state
        return False

    def _findValidPath(self, this_state=None, past_states=None):
        #Intial state:
        if this_state == None:
            for initial_state in self.initial_states:
                transitions = self._getState(initial_state).getTransitions()
                for transition in transitions:
                    next_state = transition[1]
                    initial_past_state = [initial_state]
                    states_solution = self._findValidPath(
                                        next_state, 
                                        past_states = initial_past_state)
                    if states_solution != False:
                        return states_solution
            return False
        
        #Final state:
        if self._getState(this_state).isFinal():
            past_states.append(this_state)
            return past_states

        #Repited State:
        if this_state in past_states:
            return False

        #Inner States:
        transitions = self._getState(this_state).getTransitions()
        for transition in transitions:
            #Set next state
            next_state = transition[1]
            #Set next "past states"
            next_past_states = past_states.copy()
            next_past_states.append(this_state)
            
            states_solution = self._findValidPath(
                                next_state, 
                                past_states = next_past_states)
            if states_solution != False:
                return states_solution
        return False



    def getRegEx(self):
        reg_ex = ""
        valid_path = self._findValidPath()

        for i, state in enumerate(valid_path):
            this_state = self._getState(state)
            loop_values = this_state.getLoops()
            if len(loop_values) != 0:
                reg_ex += "("
                for j, loop_value in enumerate(loop_values):
                    if j != 0:
                        reg_ex += '+'
                    reg_ex += loop_value
                reg_ex += ")*"

            if this_state.isFinal():
                return reg_ex

            transition_values = this_state.getValueFor(valid_path[i+1])
            if len(transition_values) == 1:
                reg_ex += transition_values[0]
            elif len(transition_values) > 1:
                reg_ex += '('
                for j, transition_value in enumerate(transition_values):
                    if j != 0:
                        reg_ex += '+'
                    reg_ex += transition_value
                reg_ex += ')'

        return reg_ex