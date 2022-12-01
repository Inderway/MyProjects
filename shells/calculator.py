# to calculate the income and expense
# created by wei
# Dec 1, 2022

flag=1
while flag==1:
    str=input("Input: ")
    sum=0.0
    print("---------")
    for e in str.split():
        print(e)
        sum+=float(e)
    print("---------\nResult: %.2f"%sum)
    f=input("Again? (y/n):")
    flag=1 if f=='y' else 0
