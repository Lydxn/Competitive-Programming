public int countClumps(int[] nums) {
  int counter = 0;
  for (int i = 0; i < nums.length - 1; i++) {
    int temp = nums[i];
    if (temp == nums[i + 1]) {
      for (int n = 0; i < nums.length - i; n++) {
        if (nums[n] == temp) {
          int next = nums[n + 1]; 
          if (next == temp) 
            i++;
          else 
            break;
        }
      }
      counter++;
    }
  }
  return counter;
}
