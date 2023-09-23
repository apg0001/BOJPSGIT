class Solution {
    public int solution(String[] s1, String[] s2) {
        int answer = 0;
        int size1 = s1.length;
        int size2 = s2.length;
        
        for(int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++)
                if(s1[i].compareTo(s2[j]) == 0)
                    answer++;
        }
        return answer;
    }
}