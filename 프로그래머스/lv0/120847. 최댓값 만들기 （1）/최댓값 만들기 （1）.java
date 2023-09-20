class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        int size=numbers.length;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==j)continue;
                int temp=numbers[i]*numbers[j];
                answer=answer>temp?answer:temp;
            }
        }
        return answer;
    }
}