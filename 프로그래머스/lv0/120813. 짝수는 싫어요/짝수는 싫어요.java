class Solution {
    public int[] solution(int n) {
        int size = (n + 1) / 2;
        int[] answer = new int[size];
        for(int i = 0; i < size; i++)
            answer[i] = i * 2 + 1;
        return answer;
    }
}