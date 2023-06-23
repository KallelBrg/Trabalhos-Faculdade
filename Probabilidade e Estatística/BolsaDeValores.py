import random as rd
import matplotlib.pyplot as plt

def bagOfValue(n,start):
    for i in range (n):
        lucky = rd.randint(0,1)
        if lucky == 0: start+=1
        else: start-=1
        
    return start
    
def main():
    invest = int(input('Digite o número de Investimentos: '))
    wallet = int(input('Digite o valor que você irá começar: '))
    x = []
    y = []
    for i in range (1,invest): x.append(i)
    
    for i in x: y.append(bagOfValue(i,wallet))

    plt.plot(x,y)
    plt.show()
    

if __name__=="__main__":
    main()
