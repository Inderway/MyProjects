# for plotting
# Nov 23, 2023

import matplotlib.pyplot as plt

#折线图
x = ['100K','200K','300K','400K']#点的横坐标
scenarios=['low','exlow']
k1 = [[11.0, 10.9, 10.5,10.4],[6.7,5.5,4.6,4.8]]#线1的纵坐标
k2 = [[11.4, 10.6, 8.6, 10.5],[5.3,3.0,0.3,1.1]]#线2的纵坐标
k3=[[10.8, 11.0, 10.7, 10.2],[4.8,3.0,1.1,0.1]]
k4=[[10.9,10.8,10.7,10.6],[5.2,3.2,1.4,1.4]]
k5=[[10.8,10.7,11.1,10.8],[5.5,3.3,0.3,1.0]]
k6=[[11.0,10.4,10.4,10.0],[4.3,1.3,1.0,0.7]]
for i, ele in enumerate(scenarios):
    if i==0:
        plt.title("Low-Resource")
    else:
        plt.title("Extremely Low-Resource")
    plt.plot(x,k1[i],'o-',color = 'b',label="Zh")
    plt.plot(x,k2[i],'v-',color = 'g',label="De")
    plt.plot(x,k3[i],'^-',color = 'r',label="Fi")
    plt.plot(x,k4[i],'p-',color = 'c',label="Es")
    plt.plot(x,k5[i],'s-',color = 'm',label="Ru")#s-:方形实线, s表示点类型，-表示实线
    plt.plot(x,k6[i],'D-',color = 'y',label="Hi")
    plt.xlabel("updates")#横坐标名字
    plt.ylabel("BLEU")#纵坐标名字
    plt.legend(loc = "best")#图例
    plt.savefig(f'fig_{ele}.png')
    plt.clf()#清除


