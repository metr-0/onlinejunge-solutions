from sys import stdin

def main():
    nums = []
    for line in stdin:
        inp = list(map(int, line.split()))
        if inp[-1] != -999999:
            nums.extend(inp)
            continue
        nums.extend(inp[:-1])

        max_ = -999999999999
        for i in range(len(nums)):
            prod = 1
            for j in range(i, len(nums)):
                prod *= nums[j]
                if prod > max_:
                    max_ = prod
        print(max_)
        nums = []


main()
