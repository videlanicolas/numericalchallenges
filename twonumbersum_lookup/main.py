#!/usr/bin/python3
import sys, json, time, itertools

def main(numbers, target_sum):
	print("Loaded a list containing {} numbers.".format(len(numbers)))
	print("Trying an algorithm in O(N^2) ... ")
	start_time = time.time()
	if any([a+b == target_sum for a,b in itertools.combinations(numbers,2)]):
		print("The sum exists!")
	else:
		print("The sum does not exists!")
	print("Finished! it took {} seconds.".format(time.time() - start_time))
	print("####################################")
	print("Trying an algorithm in O(N log(N)) ... ")
	start_time = time.time()
	hashset = set()
	for num in numbers:
		if num in hashset:
			print("The sum exists!")
			break
		else:
			hashset = set(list(hashset) + [target_sum - num])
	else:
		print("The sum does not exists!")
	print("Finished! it took {} seconds.".format(time.time() - start_time))

if __name__ == "__main__":
	if len(sys.argv) != 3:
		print("Please give a file containing a list of numbers in this format: [1,4,-3,0, ... ], also give the sum that you are looking for.")
		sys.exit()
	else:
		main(json.loads(open(sys.argv[1]).read()), int(sys.argv[2]))