public Map<String, Boolean> wordMultiple(String[] strings) {
  Map<String, Boolean> map = new HashMap();
  for (String i : strings) {
    if (map.containsKey(i) && !map.get(i)) 
      map.put(i, true);
    else if (!map.containsKey(i))
      map.put(i, false);
  }
  return map;
}
