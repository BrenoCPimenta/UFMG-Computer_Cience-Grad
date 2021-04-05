def readData():
    """
    Reads and separate examples
    from file examples.txt 
    """
    data = {}
    with open("examples.txt",'r') as file: 
        for line in file:
            try:
                example_number, values = line.split(':')
                data.update({example_number : values.replace('\n', '')})
            except:
                pass
    return data

def treatData(raw_data):
    """
    Gets the R<M,w>
    than separates FinalStates/Transitions/Word
    and create simple list structure for each one of then.
    """
    #Separate FinalStates/Transitions/Word
    final_states_raw = raw_data[: raw_data.find("00")]
    raw_data_without_finals = raw_data[raw_data.find("00") + 2 :]
    word_raw = raw_data_without_finals[raw_data_without_finals.find("000") + 3 :]
    transitions_raw = raw_data_without_finals[: raw_data_without_finals.find("000")]

    #Separate inner final states:
    final_states = final_states_raw.split('0')
    #Separate inner letters in word:
    word = word_raw.split('0')
    #Separate inner transitions
    transitions = {}
    joined_transitions = transitions_raw.split('00')
    for single_joined_transition in joined_transitions:
        this_transition = single_joined_transition.split('0')
        this_state = this_transition[0]
        if this_state in transitions:
            transitions[this_state].append(this_transition)
        else:
            transitions.update({this_state : [this_transition]})

    return final_states, transitions, word


class State():
    """
    Keeps the transitions for each state.
    Represents part of the Tape 1 of the problem.

    DATA REPRESENTATION:
        Input transitions are: δ(0,a) = [1,a,D]
        represented as [0,a,1,a,D].

        And keeps values as:
            this_state = 0
            transitions {a : [1,a,D], ...}
    """
    def __init__(self, transitions):
        self.this_state = transitions[0][0]
        self.transitions = {}
        for transition in transitions:
            self.transitions.update({transition[1] : transition[2:]})

    def getTransition(self, read_value):
        """
        Returns transition values for
        the read input in this state.
        """
        try:
            return self.transitions[read_value]
        except:
            #In case there isn't this transition for this state
            return False

def executeCycles(raw_data):
    """
    Turing Machine execution.
    Separate data in the next tapes:
        - Tape1 = State/Transition
        - Tape2 = Word
        - Tape3 = CurrentState
    Returns if the word is accepted or not.
    """
    initial_state = "1" #Defined in the problem:
    #Separate data:
    final_states, transitions, tape2_word = treatData(raw_data)
    #Create and initialize tape 1 with states/transitions:
    tape1_state_transitions = {}
    for state in transitions:
        tape1_state_transitions.update({ state : State(transitions[state])})
    #Walk throught states:
    tape3_current_state_index = initial_state
    for letter in tape2_word:
        current_state = tape1_state_transitions[tape3_current_state_index]
        this_transition = current_state.getTransition(letter)
        if this_transition:
            tape3_current_state_index = this_transition[0] #set next state
        else:
            break # There isn't a valid transition, therefore stop the machine
    #Answer:
    if tape3_current_state_index in final_states:
        return True #Word ACCEPTED by the turing machine.
    else:
        return False #Word REJECTED by the turing machine

def main():
    """
    Execute exemple by example
    and creates result file.
    """
    data = readData()
    results = ""
    for example_number in data:
        if executeCycles(data[example_number]):
            results +=  example_number + ":  Word ACCEPTED by the turing machine.\n"
        else:
            results +=  example_number + ":  Word REJECTED by the turing machine.\n"
    print(results, file=open("results.txt", 'w'))

if __name__ == "__main__":
   main()
