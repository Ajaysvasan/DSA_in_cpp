d = {}
nums = [1, 1, 2, 2, 3, 3, 3, 4]


def Value(nums):
    for num in nums:
        if num in d.keys():
            d[num] += 1
        else:
            d[num] = 1
    print(d)
    print(d.items())
    for key, values in d.items():
        if values == 1:
            return key


print(Value(nums))


sum = nums[0]

for i in range(1, len(nums)):
    sum = sum ^ nums[i]
print(sum)

nums = [10, 5, 2, 7, 1, 9]

d = {}
k = 15
sum = 0
maxLen = 0
for i in range(len(nums)):
    sum += nums[i]
    if sum == k:
        maxLen = max(maxLen, i + 1)
    rem = sum - k
    if rem in d.keys():
        length = i - d[rem]
        maxLen = max(maxLen, length)
    d[sum] = i
print(maxLen)

colors = [0, 1, 1, 2, 1, 0, 2]

low, mid, high = (0, 0, len(colors) - 1)

while mid <= high:
    if colors[mid] == 0:
        colors[mid], colors[low] = colors[low], colors[mid]
        low += 1
        mid += 1
    elif colors[mid] == 1:
        mid += 1
    else:
        colors[mid], colors[high] = colors[high], colors[mid]
        high -= 1
print(colors)


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


print(is_prime(5))
