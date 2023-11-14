# to calculate the income and expense
# created by wei
# Dec 1, 2022


while 1:
    str=input("Input(quit 'e'): ")
    sum=0.0
    print("---------")
    if str=='e':
        break
    for i, e in enumerate(str.split()):
        print("%d: %s"%(i+1,e))
        sum+=float(e)

    # compute mean
    # sum=sum/len(str.split())  
    print("---------\nResult: %.4f"%sum)
 