public Map<String, Integer> wordCount(String[] strings) {
  Map<String, Integer> map = new HashMap();
  for (String i : strings) {
    if (map.containsKey(i))
      map.put(i, map.get(i) + 1);
    else
      map.put(i, 1);
  }
  return map;
}
