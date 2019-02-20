# trash ass build script xd
import os
import time

try:
    os.remove('a.exe')
except:
    pass

includes = []
includes.append("include")

sources = []
sources.append("src")

link = []


flags = "-std=c++11 -Wall -Wfatal-errors -g"

compiler = "g++"

output = "a.exe"

include_str = ""
for directory in includes:
    include_str += f"-I\"{directory}/\" "

sources_str = ""
for src in sources:
    for _file in os.listdir(src):
        if (not os.path.isdir(f"{src}/{_file} ")):
            sources_str += f"{src}/{_file} "

link_str = ""
for l in link:
    sources_str += f"-l{l} "

cmd = f"{compiler} {flags} {include_str} -o {output} main.cpp {sources_str}"
print(cmd)
t1 = time.time()
os.system(cmd)
t2 = time.time()

print("Operation time Elapsed:", f'{t2 - t1:.2f}', "seconds")
