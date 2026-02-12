public class Solution {

    private static final String[] Dial = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();

        if (digits == null || digits.length() == 0) {
            return result;
        }

        dfs(digits, 0, new StringBuilder(), result);
        return result;
    }

    private void dfs(String digits, int index, 
                           StringBuilder current, 
                           List<String> result) {

        
        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }

        String letters = Dial[digits.charAt(index) - '0'];

        for (char letter : letters.toCharArray()) {
            current.append(letter);              
            dfs(digits, index + 1, current, result); 
            current.deleteCharAt(current.length() - 1);    
        }
    }
}