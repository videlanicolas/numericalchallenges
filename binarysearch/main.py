#!/usr/bin/python3
import sys, time, json

def main(filename, number):
	numbers = json.loads(open(filename).read())
	start_time = time.time()
	print("Linear lookup, O(N)")
	steps = 0
	for n in numbers:
		steps += 1
		if n == number:
			print("{} is in the list!".format(number))
			break
	else:
		print("{} is not in the list!".format(number))
	print("Finished! it took {0} seconds and {1} steps to complete.".format(time.time() - start_time,steps))
	start_time = time.time()
	print("Binary search, O(log N)")
	steps = 0
	guess_list = numbers
	while len(guess_list):
		if not guess_list[0] < number < guess_list[-1]:
			guess_list = []
			continue
		steps += 1
		if number == guess_list[int(len(guess_list)/2)]:
			print("{} is in the list!".format(number))
			break
		else:
			if guess_list[int(len(guess_list) / 2)] < number:
				guess_list = guess_list[int(len(guess_list) / 2):]
			else:
				guess_list = guess_list[:int(len(guess_list) / 2)]
	else:
		print("{} is not in the list!".format(number))
	print("Finished! it took {0} seconds and {1} steps to complete.".format(time.time() - start_time,steps))

if __name__ == "__main__":
	if len(sys.argv) != 3:
		print("Please give a file containing an ordered list and the number you are looking for.")
		sys.exit(-1)
	else:
		main(sys.argv[1],int(sys.argv[2]))