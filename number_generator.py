# Written by Gokul Manohar (CHN18CS045)
# Roll No. CS18D26

# This python file is for generating 'average_case.txt' and 'worst_case.txt' number files
# Input the value of n to specify the number of elements to be generated into the file

import random
import time


def num_generation(limit, mode, filename):
    arrayOfNumbers = list()
    for i in range(limit):
        arrayOfNumbers.append(random.randint(0, limit))
    if mode == "ASC":
        arrayOfNumbers.sort(reverse=False)
    if mode == "DSC":
        arrayOfNumbers.sort(reverse=True)
    t1 = time.time()
    arrayOfNumbers = tuple(arrayOfNumbers)
    # print(arrayOfNumbers)
    with open(file=str(filename), mode="w+", encoding="utf-8") as numbers_file:
        for i in range(limit-1):
            numbers_file.write(str(arrayOfNumbers[i])+"\n")  # "\n" important!
        numbers_file.write(str(arrayOfNumbers[limit-1]))
    t2 = time.time()
    print("\n" + filename + " generated successfully")
    print("Time taken = ", t2 - t1)


if __name__ == "__main__":
    n = int(input("\nn = "))

    # choice = int(
    #     input("1: No Sort\n2: Ascending Order Sort\n3: Descending Order Sort\nChoice: "))
    # if choice == 1:
    #     num_generation(n, "NoSort", "average_case.txt")
    # elif choice == 2:
    #     num_generation(n, "ASC", "worst_case.txt")
    # elif choice == 3:
    #     num_generation(n, "DSC", "worst_case.txt")
    # else:
    #     print("Wrong input")

    num_generation(n, "NoSort", "average_case.txt")
    num_generation(n, "DSC", "worst_case.txt")
