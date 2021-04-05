def readInputFile(file_name):
    data = {}
    data['transitions'] = []
    with open(file_name) as f:
        cnt = 0
        for line in f:
            if cnt == 0:
                data['all_states'] = line.strip('\n').split(',')
            elif cnt == 1:
                data['values'] = line.strip('\n').split(',')
            elif cnt == 2:
                data['initial_states'] = line.strip('\n').split(',')
            elif cnt == 3:
                data['final_states'] = line.strip('\n').split(',')
            else:
                data['transitions'].append(line.strip('\n').split(','))
            cnt +=1
    return data