#!/usr/bin/python3
import sys

def is_power_of_2(number):
	return False if number&(number-1) else True

def main(number):
	print("It's {}a power of 2!".format("" if is_power_of_2(number) else "not "))

if __name__ == "__main__":
	main(int(sys.argv[1]))