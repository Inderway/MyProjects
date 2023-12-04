# for computing the grades considering grades of experiments and reports
# Oct 20, 2023
# grades of reports are 60, 75, 85, 100

def _map(c:str):
    # A: first lesson; B: second lesson; C: after lesson; D: unfinished
    if c=='A':
        return 3
    elif c=='B':
        return 2
    elif c=='C':
        return 1
    return 0

def _report_map(c:str):
    if c=='A':
        return 100
    elif c=='B':
        return 85
    elif c=='C':
        return 75
    return 0



with open('grade_input.txt', 'r') as ipt, \
    open('grade_output.txt','w') as opt, \
    open('grade_report.txt', 'r') as rpt:
        grades=ipt.readlines()
        num=len(grades[0])-1
        rpt_grades=rpt.readlines()
        for i, grd in enumerate(grades):
            if num==3:
                sum=_map(grd[0])+_map(grd[1])+_map(grd[2])
                if sum==0:
                    opt.write(str(int(50*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum>0 and sum<3:
                    opt.write(str(int(60*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum>=3 and sum<5:
                    opt.write(str(int(75*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum>=5 and sum<7:
                    opt.write(str(int(85*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum>=7 and sum<=8:
                    opt.write(str(int(95*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==9:
                    opt.write(str(int(100*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
            elif num==2:
                sum=_map(grd[0])+_map(grd[1])
                # 0-6
                if sum==0:
                    opt.write(str(int(50*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum>0 and sum<3:
                    opt.write(str(int(60*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==3:
                    opt.write(str(int(75*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==4:
                    opt.write(str(int(85*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==5:
                    opt.write(str(int(95*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==6:
                    opt.write(str(int(100*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
            elif num==1:
                sum=_map(grd[0])
                # 0-3
                if sum==0:
                    opt.write(str(int(50*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==1:
                    opt.write(str(int(60*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==2:
                    opt.write(str(int(85*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')
                elif sum==3:
                    opt.write(str(int(100*0.8+_report_map(rpt_grades[i][0])*0.2))+'\n')



