  
alonzo = {"age": 10, "height": 42, "weight": 175, "instrument": "fiddle" }
turing = {"age": 41, "height": 70, "weight": 160, "instrument": "theremin"}
bertha = {"age": 32, "height": 97, "weight": 587, "instrument": "cello"}
tinkerB = {"age":100, "height": 4, "weight": 0.5, "instrument": "cello"}
banditos = {"Alonzo": alonzo, "Turing": turing, "Bertha": bertha, "TinkerB": tinkerB}

def instrument(instrument):
    ans = {}
    for key,value in banditos.items():
        if value['instrument'] == instrument:
            ans.update({key:value})

    return ans

if __name__ == '__main__':
    x = input('Enter the instrument ')
    print(instrument(x))