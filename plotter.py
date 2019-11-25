import re
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

bible = open("tuningLog", "r")
regex = re.compile(r'P:[\s\d\.\,]{1,}I:[\s\d\.\,]{1,}D:[\s\d\.\,]{1,}')
PArray=[]
IArray=[]
DArray=[]
for line in bible:
    four_letter_words = regex.findall(line)
    for word in four_letter_words:
        print(word)
        array_in=re.split('P: |, I: |, D:|\n',word)
        if array_in is not None and len(array_in)>=4:
            PArray.append(float(array_in[1]))
            IArray.append(float(array_in[2]))
            DArray.append(float(array_in[3]))

fig, axs = plt.subplots(3)
fig.suptitle('PID Twiddle')
axs[0].plot(PArray,"-.")
axs[1].plot(IArray)
axs[2].plot(DArray)

[ax.grid() for ax in axs]
axs[0].set_title('Kp')
axs[1].set_title('Ki')
axs[2].set_title('Kd')

fig.savefig("twiddle.png")
plt.show()

