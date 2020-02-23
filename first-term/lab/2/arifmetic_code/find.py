import random
import os

def gen():
	s = ""
	scnt = 3
	cnt = [] * scnt
	for i in range(scnt):
		cnt[i] = random.randint(1, 5)
	while (True):
		x = random.randint(1, scnt)
		
f = open("input.txt", "r")

a = f.read()

print(a)