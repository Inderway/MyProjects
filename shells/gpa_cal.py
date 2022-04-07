# Mar 23, 2022
# for calculating the gpa
# -*- coding=utf8 -*-
import numpy as np

def getCourseGPA(grade):
    if 96<=grade<=100:
        return 4.8
    if 93<=grade<=95:
        return 4.5
    if 90<=grade<=92:
        return 4.0
    if 86<=grade<=89:
        return 3.8
    if 83<=grade<=85:
        return 3.5
    if 80<=grade<=82:
        return 3.0
    if 76<=grade<=79:
        return 2.8
    if 73<=grade<=75:
        return 2.5
    if 70<=grade<=72:
        return 2.0
    if 66<=grade<=69:
        return 1.8
    if 63<=grade<=65:
        return 1.5
    if 60<=grade<=62:
        return 1.0

def calGPA():
    grades=[[1,87],[4.5,82],[3,88],
    [2,73],[1,83],[2,82],
    [3,88],[2,80],[0.5,81],
    [2,88],[5,86],[3,80],
    [2,89],[3,83],[1,87],
    [2,77],[0.5,90],[2,88],
    [2,80],[4,85],[4,92],
    [3,86],[1,87],[3,81],
    [2,84],[0.5,93],[1,87],
    [2.5,78],[2.5,87],[2,71],
    [3,77],[4,76],[2,89],
    [3,83],[0.5,88],[2,92],
    [4,76],[4,94],[3,85],
    [2,93],[0.5,96],[0.5,85],
    [4,83],[3,84],[3,87],
    [0.5,86],[6.5,94],[0.5,85],
    [8,87],
    ]
    grades=np.array(grades)
    credit=np.sum(grades,axis=0)[0]
    numerator=0
    for course in grades:
        numerator+=course[0]*getCourseGPA(course[1])
    print("GPA:%f"%(numerator/credit))
    print("Average:%f"%np.mean(grades,axis=0)[1])
    



if __name__=="__main__":
    calGPA()