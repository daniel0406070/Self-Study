import sys
import os

path = "/home/daniel/code_space/binary_search_merge_submissions/"
print(path)

if(not os.path.isdir(path+"test_case")):
    os.system("mkdir "+path+"test_case")

file_list = os.listdir(path)
student_list = {}
mantest_list = {}

# c, cpp 파일 제출자 이름을 student_list에 추가 
# 그 외 파일은 mantest_list에 추가
def ap(list, idx, file):
    if(idx not in list.keys()):
        list[idx] = []

    list[idx].append(file)

for file in file_list:
    if file.endswith(".cpp"):
        ap(student_list,file[:3],file)
    elif file.endswith(".c"):
        ap(student_list,file[:3],file)
    elif file == "codetester.py":
        pass
    elif file == "mantest":
        pass
    elif file == "test_case":
        pass
    else:
        ap(mantest_list,file[:3],file)

for student in mantest_list.keys():
    if student in student_list.keys():
        mantest_list[student].extend(student_list[student])
        del student_list[student]

if(not os.path.isdir(path+"mantest")):
    os.system("mkdir "+path+"mantest")

for student,files in mantest_list.items():
    for file in files:
        if(not os.path.isdir(path+file)):
            os.system("mv "+path+file+" "+path+"mantest/"+file)
        else:
            os.system("mv "+path+file+"/* "+path+"mantest/"+file)
            os.system("rm -rf "+path+file)

#직접 테스트할 사람들 목록을 파일로 저장
with open(path+"mantest/mantest.txt",'w') as f:
    mantest_keys = mantest_list.keys()
    mantest_keys = sorted(mantest_keys)
    for student in mantest_keys:
        f.write(student+'\n')


#학생들의 코드를 컴파일하고 테스트 케이스를 돌림
for student,files in student_list.items():
    if(student == "김은서"):
        pass

    for file in files:
        filename=file.split(".")[0].split("_")[-1].replace("(",'').replace(")",'').replace(" ",'')


        os.system("touch "+path+"test_case/"+student+'_'+ filename +".txt")

        os.system("g++ -o \""+path+file.split(".")[0]+"\" \""+path+file+"\"")            
        os.system("\""+path+file.split(".")[0]+"\""+" > "+path+"test_case/"+student+'_'+ filename +".txt")
    



