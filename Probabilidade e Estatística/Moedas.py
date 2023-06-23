import random as rd
import matplotlib.pyplot as plt

def playMoeda(n):
    cara = 0
    for i in range (n):
        moeda = rd.randint(0,1)
        if moeda == 0: cara+=1
        
    return cara/n
    
def main():
    jogadas=int(input('Digite o número de Jogadas: '))
    x = []
    y =[]
    for i in range (1,jogadas): x.append(i)
    
    for i in x: y.append(playMoeda(i))

    plt.plot(x,y)
    plt.show()
    

if __name__=="__main__":
    main()
    
