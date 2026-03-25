class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
    {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);

        comb(candidates, 0, candidates.length, target, new ArrayList<>(), res);

        return res;
    }

    void comb(int[] candidates, int ind, int n, int target, List<Integer> list, List<List<Integer>> res)
    {
        if(target == 0)
        {
            res.add(new ArrayList<>(list));
            return;
        }

        for(int i = ind; i < n && candidates[i] <= target; i++)
        {
            list.add(candidates[i]);
                
            comb(candidates, i, n, target - candidates[i], list, res);

            list.removeLast();
        }
    }
}