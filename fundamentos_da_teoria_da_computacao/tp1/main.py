from file_handler import readInputFile
from automaton import Automaton
import json
import sys

try:
    data = {}
    try:
        data = readInputFile(sys.argv[1])
    except:
        print("Há um erro na passagem de parâmetros, verifique o nome do arquivo.")
    AF = Automaton( 
            all_states=data['all_states'],
            values=data['values'],
            initial_states=data['initial_states'],
            final_states=data['final_states'],
            transitions=data['transitions'] )

    reg_ex = AF.getRegEx()
    print(reg_ex)
except:
    print("Por favor tente novamente.")



        