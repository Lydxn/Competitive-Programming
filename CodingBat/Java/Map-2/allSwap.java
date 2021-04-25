public String[] allSwap(String[] strings) {
  Map<String, Integer> map = new HashMap();
  for (int i = 0; i < strings.length; i++) {
    String key = strings[i].substring(0, 1);
    if (map.containsKey(key)) {
      String temp = strings[map.get(key)];
      strings[map.get(key)] = strings[i];
      strings[i] = temp;
      map.remove(key);
    } else 
      map.put(key, i);
  }
  return strings;
}
