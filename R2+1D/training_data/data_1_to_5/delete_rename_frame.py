import os

# setting folder
folder = 49
# setting preserve frame
start = 55
end = 105

print("target folder:", folder)
print("preserve frames:", start, "~", end-1)
print("totally", end-start, "frames")

frame_list = os.listdir('./' + str(folder))
n = len(frame_list)


# remove redundant frames
print("remove", 0, "to", start-1)
for i in range(0, start):
    cmd = 'rm \"./{}/{}.jpg\"'.format(folder, i)
    os.system(cmd)
print("remove", end, "to", n-1)
for i in range(end, n):
    cmd = 'rm \"./{}/{}.jpg\"'.format(folder, i)
    os.system(cmd)

# rename remaining frames
print("rename", start, "to", end-1)
frame_list = os.listdir('./' + str(folder))
n = len(frame_list)
for i in range(n):
    frame_list[i] = int(frame_list[i].removesuffix('.jpg'))

frame_list.sort()

for i in range(n):
    cmd = 'mv ./' + str(folder) + '/' + str(frame_list[i]) + '.jpg ./' + str(folder) + '/' + str(i) + '.jpg'
    os.system(cmd)