class Solution {
    public int minArray(int[] numbers) {
        int i=0, j=numbers.length-1;
        int m;
        while(i<j) {
            m = (i+j)/2;
            if(numbers[m]<numbers[j]) j = m;
            else if(numbers[m]==numbers[j]) j--;
            else i++;
        }
        return numbers[i];
    }
}