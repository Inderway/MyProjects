# for plotting
# Nov 23, 2023

import matplotlib.pyplot as plt

#折线图
x = ['100K','200K','300K','400K']#点的横坐标
scenarios=['Gu-En', 'Ja-En', 'Lt-En']
k1 = [[4.5,0.5,0.6,0.5],[6.8,2.3,1.2,1.0],[16.6,9.6,1.9,1.8]]#线1的纵坐标
k2 = [[5.4,0.7,0.7,0.8], [6.3,2.7,1.8,1.5],[16.1,10.4,2.6,5.9]]#线2的纵坐标
k3=  [[6.8,0.6,0.6,0.4],[6.5,0.5,0.6,0.4],[17.1,9.7,1.7,6.1]]
k4=  [[11.3,0.6,0.6,0.5],[5.2,1.0,1.1,0.1],[9.8,1.3,1.1,1.1]]
k5=  [[7.4,0.5,0.6,0.7],[6.8,3.2,0.8,0.7],[17.3,10.4,2.9,5.4]]
k6=  [[6.1,0.7,0.3,0.9],[7.5,5.7,4.9,4.7],[12.2,6.2,2.2,4.5]]
for i, scene in enumerate(scenarios):
    plt.title(scene)
    plt.plot(x,k1[i],'o-',color = 'b',label="De")
    plt.plot(x,k2[i],'v-',color = 'g',label="Es")
    plt.plot(x,k3[i],'^-',color = 'r',label="Fi")
    plt.plot(x,k4[i],'p-',color = 'c',label="Hi")
    plt.plot(x,k5[i],'s-',color = 'm',label="Ru")#s-:方形实线, s表示点类型，-表示实线
    plt.plot(x,k6[i],'D-',color = 'y',label="Zh")
    plt.xlabel("updates")#横坐标名字
    plt.ylabel("BLEU")#纵坐标名字
    plt.legend(loc = "best")#图例
    plt.savefig(f'fig_{scene}.png')
    plt.clf()#清除


