# trash ass build script xd
import os
import time

COMPILER = "g++"
EXECUTABLE = "a.exe"

INCLUDES = []
SOURCES = []
LINK = []
FLAGS = []

INCLUDES.append("include")

SOURCES.append("src")

FLAGS.append("-std=c++11")
FLAGS.append("-Wall")
FLAGS.append("-Wextra")
FLAGS.append("-g")

# for some reason clang wont compile unless in c++17 mode and with these flags
if COMPILER == "clang++":
    FLAGS.append("-std=c++17")
    FLAGS.append("-Xclang -flto-visibility-public-std")

flag_str = ""
for f in FLAGS:
    flag_str += f + " "

include_str = ""
for directory in INCLUDES:
    include_str += f"-I\"{directory}/\" "

sources_str = ""
for src in SOURCES:
    for _file in os.listdir(src):
        if (not os.path.isdir(os.path.join(src, _file))):
            sources_str += f"{src}/{_file} "

link_str = ""
for l in LINK:
    link_str += f"-l{l} "

try:
    os.remove(EXECUTABLE)
except:
    pass

cmd = f"{COMPILER} {flag_str} {include_str} -o {EXECUTABLE} main.cpp {sources_str} {link_str}"
print(cmd)
t1 = time.time()
os.system(cmd)
t2 = time.time()

print("Operation time Elapsed:", f'{t2 - t1:.2f}', "seconds")