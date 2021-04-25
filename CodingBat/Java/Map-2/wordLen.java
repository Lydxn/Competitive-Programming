public Map<String, Integer> wordLen(String[] strings) {
  Map<String, Integer> map = new HashMap();
  for (String s : strings) {
    map.put(s, s.length());
  }
  return map;
}
