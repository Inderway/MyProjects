# to calculate the income and expense
# created by wei
# Dec 1, 2022

flag=1
while flag==1:
    str=input("Input: ")
    sum=0.0
    print("---------")
    for i, e in enumerate(str.split()):
        print("%d: %s"%(i+1,e))
        sum+=float(e)

    # compute mean
    # sum=sum/len(str.split())  
    print("---------\nResult: %.4f"%sum)
    f=input("Again? (y/n):")
    flag=1 if f=='y' else 0
