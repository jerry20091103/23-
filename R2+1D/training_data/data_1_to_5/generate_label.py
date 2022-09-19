# setting folder
folder = 49
# setting preserve frame
clas = 3
start = 11
end = 35

print("target folder:", folder)
print("start frames:", start)
print("end frame:", end-1)
print("class:", clas)

filePath = './' + str(folder) + '/label.txt'
fout = open(filePath, "w")
for i in range(50):
    if (i >= start and i < end):
        print(clas, file=fout)
    else:
        print("0", file=fout)
fout.close()