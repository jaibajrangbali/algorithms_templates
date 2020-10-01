import numpy as np

ROLL_NO = "2018101033"
np.set_printoptions(precision=3, suppress=True)
# x = round(1 - ((int(ROLL_NO[-3:])%40 + 1) / 100), 3)
x = 0.6
y = int(ROLL_NO[-2:])%3

pds = [[0.9, 0.85], [0.8, 0.95], [0.85, 0.9]]

Prr, Pgg = pds[y]
Pgr, Prg = [round(1-Prr, 3), round(1-Pgg, 3)]
Pll, Plr, Prl, Prr = [x, round(1-x, 3), round(1-x, 3), x]

NUM_OF_STATES = 5
b = np.array([1/3, 1/3, 0, 0, 1/3])
col = np.array(["red", "red", "green", "green", "red"])

def T(new_state, old_state, action):
    if(new_state == 0 and old_state == 0):
        if(action == "left"):
            return Pll
        else:
            return Plr

    if(new_state == NUM_OF_STATES-1 and old_state == NUM_OF_STATES-1):
        if(action == "left"):
            return Prl
        else:
            return Prr

    if(new_state - old_state == 1):
        if(action == "left"):
            return Prl
        else:
            return Prr

    if(new_state - old_state == -1):
        if(action == "left"):
            return Pll
        else:
            return Plr
    
    return 0

def O(observation, new_state, action):
    if(observation == "red" and col[new_state] == "red"):
        return Prr
    if(observation == "green" and col[new_state] == "red"):
        return Pgr
    if(observation == "red" and col[new_state] == "green"):
        return Prg
    if(observation == "green" and col[new_state] == "green"):
        return Pgg

def Prob(observation, action, b):
    summ = 0
    for old_state in range(NUM_OF_STATES):
        for new_state in range(NUM_OF_STATES):
            res = O(observation, new_state, action)*T(new_state, old_state, action)*b[old_state]
            summ += res
    return summ

def cormat(new_state, Oval, Ts, bs, num):
    brac = ""
    for e,i in enumerate(Ts):
        brac += str(i)+"×"+str(round(bs[e], 3))
        if(e != len(Ts) - 1):
            brac += " + "
    res = "Numerator(Belief[S"+str(new_state+1)+"]) = "+str(Oval)+"×"+"("+brac+") = "+str(round(num, 3))
    return res

def cormatdeno(nums, deno):
    brac = ""
    for e,i in enumerate(nums):
        brac += str(round(i, 3))
        if(e != len(nums) - 1):
            brac += " + "
    res = "Denominator = ("+brac+") = "+str(round(deno, 3))
    return res

def cormat2(new_state, num, deno, final):
    res = "Belief[S"+str(new_state+1)+"] = "+str(round(num, 3))+"/"+str(round(deno, 3))+" = "+str(round(final, 3))
    return res

def calculate_beliefs(action, observation):
    new_b = np.zeros((NUM_OF_STATES))
    probval = Prob(observation, action, b)
    print()
    for new_state in range(NUM_OF_STATES):
        Ts = [T(new_state, old_state, action) for old_state in range(NUM_OF_STATES)]
        bs = [b[old_state] for old_state in range(NUM_OF_STATES)]
        tolls = [Ts[old_state]*b[old_state] for old_state in range(NUM_OF_STATES)]
        Oval = O(observation, new_state, action)
        num = Oval*sum(tolls)
        new_b[new_state] = num
        print(cormat(new_state, Oval, Ts, bs, num))
        # deno = probval
        # new_b[new_state] = num/deno
    deno = sum(new_b)
    print()
    print(cormatdeno(new_b, deno))
    print()
    for new_state in range(NUM_OF_STATES):
        final_b = new_b[new_state]/deno
        print(cormat2(new_state, new_b[new_state], deno, final_b))
        new_b[new_state] = final_b
    print()
    return new_b

events = [("right", "red"), ("left", "green"), ("left", "green")]

outfile = ROLL_NO+".txt"
outstr = ''
outstr += ROLL_NO + '\n'
outstr += str(x) + ' ' + str(y) + '\n'


print("Initially, beliefs are:")
print(repr(b)[7:-2])
for i, event in enumerate(events):
    print()
    print("## Action-Observation Pair", i+1, "##")
    action, observation = event
    b = calculate_beliefs(action, observation)
    print("So, beliefs after taking action "+action+" and observing color "+observation+" are:")
    print(repr(b)[7:-2])
    c = list(b)
    for i in range(len(c)):
        c[i] = round(c[i], 3)
    outstr += ' '.join(map(str, list(c))) + '\n'

with open(outfile, 'w') as f:
    f.write(outstr)
    f.close()