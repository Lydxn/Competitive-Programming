public List<Integer> square(List<Integer> nums) {
  nums.replaceAll(i -> i * i);
  return nums;
}
