public int commonTwo(String[] a, String[] b) {
  List<String> aList = Arrays.asList(a);
  List<String> bList = Arrays.asList(b);
  HashSet<String> aSet = new HashSet<String>(aList);
  aSet.retainAll(bList);
  return aSet.size();
}
