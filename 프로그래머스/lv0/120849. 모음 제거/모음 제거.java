class Solution {
    public String solution(String my_string) {
        String answer = "";
        for(int i=0;i<my_string.length();i++){
            char s = my_string.charAt(i);
            if(s!='a'&&s!='e'&&s!='i'&&s!='o'&&s!='u'){
                answer=answer+s;
            }
        }
        return answer;
    }
}