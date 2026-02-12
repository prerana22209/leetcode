class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        count = Counter(nums)
        for i, ival in count.items():
            if ival > 1:
                if (-2 * i) in count:
                    ans.add(tuple(sorted([i, i, (-2* i)])))
            for j, jval in count.items():
                if j == i: continue
                if -2 * j == i:
                    if jval > 1:
                        ans.add(tuple(sorted([i, j, j])))
                elif -(i + j) != i and  -(i + j) in count:
                    ans.add(tuple(sorted([i, j, -(i + j)])))
        if count[0] < 3 and (0,0,0) in ans:
            ans.remove((0,0,0))
        return [[a, b, c] for a, b, c in ans]