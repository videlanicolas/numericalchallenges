#!/usr/bin/python3
from random import randint
from collections import Counter
from statistics import stdev

def rand5():
	return randint(1,5)

def rand7():
	return (sum([rand5() for _ in range(7)])%7) + 1

if __name__ == "__main__":
	N = 100000
	print("Standard deviation for rand5(): {}".format(stdev([v/N for k,v in Counter([rand5() for x in range(N)]).items()])))
	print("Standard deviation for rand7(): {}".format(stdev([v/N for k,v in Counter([rand7() for x in range(N)]).items()])))